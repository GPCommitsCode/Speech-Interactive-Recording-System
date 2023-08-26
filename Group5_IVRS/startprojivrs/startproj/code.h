// sp_ivrs.cpp : Defines the entry point for the console application.
//
#ifndef CODE
#define CODE

//#include "header.h"
#include "stdAfx.h"
#include "startproj1.h"
#include "stdAfx.h"
#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<float.h>
#include <windows.h>
#include<MMSystem.h>
#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<float.h>
#include <windows.h>
#include<MMSystem.h>

#define M 32
#define N 5
#define p 12
#define CLIP 5000
#define FS 320
#define sampleSize 320
#define DELTA 0.0001

 int T=85;
 long double R[13];
 long double alpha1[13][13];
 long double a[13];
 long double c[320];
 long double sample[320];
 long double averageEnergy[100000];
 long double totalFrameOfAmplitudes[100000];
 long double alpha[160+1][N+1];
 long double beta[160+1][N+1];
 long double gamma[160+1][N+1];
 long double delta[160+1][N+1];
 long double zi[160+1][N+1][N+1];
 int xhi[160+1][N+1];
 long double A[N+1][N+1];
 long double B[N+1][M+1];
 long double pi[N+1];
 long double pstar;
 long double transtionsfromstatesi;
 long double transitionsfromstatesitosj; 
 int qstarVal;
 int qstar[160+1];
 int O[160+1];
 long double ref[M+1][13];
 long double distances[5][5];
 long double averageA[N+1][N+1];
 long double averageB[N+1][M+1];
 long double piValue=22.0/7;
 long double tokhuraWeights[] = {1.0, 3.0, 7.0, 13.0, 19.0, 22.0, 25.0, 33.0, 42.0, 50.0, 56.0, 61.0};
 int maxAmplitude=1;
 int normalizedFactor=5000;
 int totalNumberOfSamples=0;
 int frameNumber=0;
 long double dc_shift=0;
 int testCount=-1;
 int numberofFrames=0;
 long double avgenergy=0;
 long double threshold = 1e-30; 
 long double pstar_old=-1;
 long double w[13]={0.0,1.0,3.0,7.0,13.0,19.0,22.0,25.0,33.0,42.0,50.0,56.0,61.0};
 int start_index=0;
 int end_index=0;
 int zcr=0;
 int readUniverse=0;

 FILE *unv=fopen("universe_new_123.csv","w");
 
 //--------------------------------------------
 long double epsilon=0.03;
 long double universeData[50000][12];
//array to store the centroids of every regions
long double centroidBuckets[M][12];
//array to temporarily store the centorids of every region
long double newCentroidBucket[M][12]={0};
//array to store the number of vectors store in each region
int countVectorInBucket[M];
//variable to store the previous distortion of the entire universe
long double previousDistortion=0;
//variable to store the current distorition of the current univers
long double currentDistortion=0;
long double minDistortion=0;
int K=0;
int numberOfVectors=0;

 //--------------------------------------------
//applying durbins algo to get the filter coefficients a.
long double durbinsAlgo(long double r[])
{
	long double e[p+1];
	long double k[p+1];
	//FILE *aout = fopen("aout.txt","w");
	e[0]=r[0];
	k[1]=r[1]/r[0];
	alpha1[1][1]=k[1];
	e[1]=(1-k[1]*k[1])*e[0];
	for(int i=2;i<=p;i++)
	{
		long double bisum=0;
		for(int j=1;j<=i-1;j++)
		{
			bisum+=alpha1[j][i-1]*r[i-j];
		}
		for(int j=1;j<=i-1;j++)
		{
		k[i]=(r[i]-bisum)/e[i-1];
		alpha1[i][i]=k[i];
		alpha1[j][i]=alpha1[j][i-1]-k[i]*alpha1[i-j][i-1];
		if(i==p)
		{
			a[j]=alpha1[j][i];
		}
			e[i]=(1-k[i]*k[i])*e[i-1];
		}
	}
	for(int i=1;i<=p;i++)
	{
		if(i==p)
		    a[i]=alpha1[i][i];
	}
	return 0;
}
//finding auto co-relation coefficients R
void calcAutoCoRelation(long double sample[])
{
//	FILE *rout = fopen("rout.txt","w");
	/*
		Applying window function
	*/
	//printf("\n *** The auto corelation coeff are ***\n");
	for(int i=0;i<sampleSize;i++)
	{
		long double arg=(2.0*22*i)/(7*(sampleSize-1));
		long double window=0.54-0.46*cos(arg);
		sample[i]=sample[i]*window;
	}
	/*
		find autoRelation coefficients
	*/
	for(int i=0;i<=p;i++)
	{
		R[i]=0;
		long double sum=0;
		for(int y=0;y<=sampleSize-1-i;y++)
		{
			long double s=sample[y]*sample[y+i];
			sum+=s;
		}
		R[i]=sum;
		//printf("R[%d]=%Lf\n",i,R[i]);
		//fprintf(rout,"%Lf\t",R[i]);
	}
	return;

}
//finding cepstral coefficient,it will act as a vector to us
long double calcCepstralCoeff(long double a[])
{
//	c[0]=2*log2(R[0]);
	for(int m=1;m<=p;m++)
	{
		c[m]=a[m];
		long double sum=0;
		for(int k=1;k<=m-1;k++)
		{
			sum=sum+(k*1.0/m)*c[k]*a[m-k];
		}
		c[m]+=sum;
		//printf("c[%d]=%Lf\n",m,c[m]);
		//fprintf(fptr,"%Lf\t",c[m]);
		
	}
	return 0;
} 
//applying raised sine window to the cepstral coefficients, the final vector
long double calcRaisedWindow(long double c[])
{
	//printf("\n***The cepstral Coeff after raised sine window are***\n");
	for(int m=1;m<=p;m++)
	{
		long double raisedTimeWindow= (1+(p/2.0)*sin(piValue*m/p));
		c[m]*=raisedTimeWindow;
		
		if(readUniverse && unv!=NULL)
		fprintf(unv,"%Lf,",c[m]);
	}
	if(readUniverse && unv!=NULL)
	fprintf(unv,"\n");
	return 0;
} //should change this   
//calculating the minimum tokuhra distance between the current vector and the codebook of vectors and return the index with minimum tokuhra distance
int calculateTokuhraDistance()
{
	long double min=DBL_MAX;
	int minIndex=0;
	for(int frame=1;frame<=M;frame++)
	{
		long double sum=0;
		for(int i=1;i<13;i++)
		{
			sum=sum+(w[i]*(c[i]-ref[frame][i])*(c[i]-ref[frame][i]));
		}
		if(sum<min)
		{
			minIndex=frame;
			min=sum;
		}
	}
	return minIndex;
}
int calculateStartAndEndIndex()
{
	long double temp=avgenergy/100;
	end_index=frameNumber-1;
	for(int i=0;i<frameNumber;i++)
	{
		if(averageEnergy[i]<temp)
		{
			continue;
			
		}
		start_index=i;
		break;
	}
	int flag=0;
	int iter=0;
	for(int i=start_index;i<frameNumber;i++)
	{
		if(flag==1 && iter<20 && iter<frameNumber)
		{
			if(averageEnergy[i]<temp)
			{
				iter++;
			}
			else
			{
				end_index=i;
				flag=0;
				iter=0;
			}
		}
		else if(flag==1 && iter>=20)
			break;
		else if(averageEnergy[i]<temp)
		{
			end_index=i;
			flag=1;
		}
	}
	return 0;
}
//function to calculate normalized short term energy
long double calcNormalizedShortTermEnergy()
{
	long double sumOfAmplitudes =0;
	long double resultShortTermEnergy;
	int init_index=0;
	
	frameNumber=((totalNumberOfSamples-320)/80)+1;
	for(int j=0;j<frameNumber;j++)
	{
		sumOfAmplitudes=0;
		for(int i=init_index;i<init_index+320;i++)
		{
			long double normalizedsquareOfAmplitude = totalFrameOfAmplitudes[i]* totalFrameOfAmplitudes[i]; //squaring each amplitude
			sumOfAmplitudes += normalizedsquareOfAmplitude; //finding energy of each frame of 320 samples by summing them up
		}
		resultShortTermEnergy = (sumOfAmplitudes)/sampleSize;
		averageEnergy[j]=resultShortTermEnergy;
		avgenergy+=resultShortTermEnergy;
		init_index+=80;
	}
	/*for(int i=totalNumberOfSamples;i>=0;i--)
	{
		printf("%Lf ",totalFrameOfAmplitudes[i]);
	}*/
	avgenergy/=frameNumber;
	printf("average energy = %lf\n",avgenergy);
	calculateStartAndEndIndex();
	return 0;
}
//function which divides the entire amplitudes into frames and generates cepstral coefficients
long double findFramesAndGenerateCepstralCoefficents(long double totalFrameOfAmplitudes[])
{
		//int start_index=0;
		//printf("totalNumberofSamples=%d ",totalNumberOfSamples);
		calculateStartAndEndIndex();
	/*	for(int i=0;i<totalNumberOfSamples;i++)
		{
			if(totalFrameOfAmplitudes[i]<50 && totalFrameOfAmplitudes[i]>-50)
			{
				continue;
			}
			start_index=i;
			break;
		}*/
		//totalNumberOfSamples-=start_index;
		//frameNumber=((totalNumberOfSamples-320)/80)+1;
		frameNumber=end_index-start_index;
		if(frameNumber>160)
		{
			frameNumber=160;
			start_index=end_index-160;
		}
		int start_index1=start_index*80;	

		for(int i=0;i<frameNumber;i++)
		{
			int index=0;
			for(int j=start_index1;j<start_index1+320;j++)
			{
				sample[index]=totalFrameOfAmplitudes[j];
			//	printf("%Lf ",totalFrameOfAmplitudes[j]);
				index++;
			}
			//break;
			start_index1+=80;
			calcAutoCoRelation(sample);
			durbinsAlgo(R);
			calcCepstralCoeff(a);
			calcRaisedWindow(c);
			int value=calculateTokuhraDistance();
			O[i+1]=value;
			//printf("%d ",value);
		}
		return 0;
		
}
/*function to take the input as a file name, and process the file and assign final normalized 
amplitudes to the findFramesAndGenerateCepstralCoefficents() function
to generate cepstral coefficients*/
void processFile(char *filePath)
{
	FILE *fp=fopen(filePath,"r");
	printf("%s\n",filePath);
	if(fp==NULL)
	{
		printf("File not opened\n");
		return;
	}
	int amp=0,avg=0;
	int i=0;
	int n=0;
	int min_amp=INT_MAX;
	int max_amp=INT_MIN;
	
	//calculate average, minimum & maximum amplitude
	while(!feof(fp)){
		fscanf(fp,"%d",&amp);
		avg+=amp;
		min_amp=(amp<min_amp)?amp:min_amp;
		max_amp=(amp>max_amp)?amp:max_amp;
		n++;
		totalNumberOfSamples++;
	}
	avg/=n;
	T=(n-FS)/80 + 1;
	//update minimum & maximum amplitude after DC Shift
	min_amp-=avg;
	max_amp-=avg;
	fseek(fp,0,SEEK_SET);
	while(!feof(fp)){
		fscanf(fp,"%d",&amp);
		if(min_amp==max_amp){
			amp=0;
		}
		else{
			//handle DC Shift
			amp-=avg;
			//normalize the data
			amp=(amp*CLIP)/((max_amp>min_amp)?max_amp:(-1)*min_amp);
			//store normalized data
			totalFrameOfAmplitudes[i++]=amp;
		}
	}
	fclose(fp);
	calcNormalizedShortTermEnergy();
	findFramesAndGenerateCepstralCoefficents(totalFrameOfAmplitudes);
	return;
}
//---------------------------------------------- END OF Generating Cepstral Coeffcients------------------------------------------
//function to read the codebook generated from the training data

//function to load the data into A,B,PI matrices
void generateUniverse()
{
	char datasetName[250];
	FILE *dataset=fopen("data/datasetName.txt","r");
	if(dataset==NULL)
		printf("Filde not found");
	fscanf(dataset,"%s",datasetName);
	//printf("%s ",datasetName);
	for(int digit=1;digit<=3;digit++)
	{
		for(int utterno=1;utterno<=30;utterno++)
		{
			
			totalNumberOfSamples=0;
			frameNumber=0;
			char filePath[100];
			char file[100]="";
			sprintf(filePath,"/224101027_E_%d_%d.txt",digit,utterno);
			strcat(file,datasetName);
			strcat(file,filePath);
			readUniverse=1;
			processFile(file);
			printf("***************************************\n");
			
		}
	}
	readUniverse=0;
	if(unv!=NULL)
	fclose(unv);


}
long double readUniverseFile()
{
	//File initalization in read mode
		FILE *universeFilePointer=fopen("universe_new_123.csv","r");
		//checking if the file is opened or not
		if(universeFilePointer==NULL)
		{
			printf("File Not found");
			return -1;
		}
		//initializing row number
		int row=0;
		//initializing column number
		int column=0;
		//variable to store the current column value
		long double columnValue;
		//condition to check for EOF
		while(!feof(universeFilePointer)) 
		{
			//read the data of one row until all the columns of one row are read
			if(column<12)
			{
					fscanf(universeFilePointer,"%Lf%*c",&columnValue);
					universeData[row][column]=columnValue;
					column++;
					
					
			}
			else
			{
				numberOfVectors++;
				column=0;
				//increase the row size
				row++;
			}
	
		}
		return 0;
}
void calculatingUniversalCentorid()
{
	for(int i=0;i<numberOfVectors;i++)
	{
		for(int j=0;j<12;j++)
		{
			centroidBuckets[K][j]+=universeData[K][j];
		}
	}
	for(int i=0;i<12;i++)
	{
		centroidBuckets[K][i]=centroidBuckets[K][i]/numberOfVectors;
	}
}
long double assignVectorsToBuckets(int currentVectorIndex)
{
	long double sum=0.00000;
	//variable to keep track of in which region/bucket the current vector to store.
	int bucketIndex=0;
	
	for(int i=0;i<12;i++)
	{
		//calculate the tokuhra distance
		long double td=(tokhuraWeights[i]*(centroidBuckets[0][i]-universeData[currentVectorIndex][i])*(centroidBuckets[0][i]-universeData[currentVectorIndex][i]));
		sum=sum+td;
	}
	//intializing the mindistortion of a vector to the first region's/bucket centroid
	minDistortion=sum;
	//Now assign the vector to a region/bucket and calcuate the mindistortion of the current vector and add it to the current distortion of the unvierse
	for(int k=0;k<=K;k++)
	{
		sum=0;
		for(int i=0;i<12;i++)
		{
			long double td=(tokhuraWeights[i]*(centroidBuckets[k][i]-universeData[currentVectorIndex][i])*(centroidBuckets[k][i]-universeData[currentVectorIndex][i]));
			sum=sum+td;
		//	printf("bucket=%d vector=%d sum=%Lf\n",k,currentVectorIndex,sum);
		}
		if(sum<=minDistortion)
		{
			minDistortion=sum;
			bucketIndex=k;
		}
	}
	currentDistortion+=minDistortion;
	//increase the count of the bucket/region in which the vector is added.
	countVectorInBucket[bucketIndex]+=1;
	//add the current vector and the centroid of the region in which it was added and temporarily store it in the new centorid bucket
	for(int i=0;i<12;i++)
	{
		newCentroidBucket[bucketIndex][i]+=universeData[currentVectorIndex][i];
	}
	return 0;
}
long double updateCentroidsOfRegions()
{
	for(int i=0;i<=K;i++)
	{
		for(int j=0;j<12;j++)
		{
			if(countVectorInBucket[i]!=0)
			centroidBuckets[i][j]=newCentroidBucket[i][j]/countVectorInBucket[i];
			newCentroidBucket[i][j]=0;
		}
	}
	return 0;
}
long double kMeansAlgo()
{
	//assign currentDistortion to the previous Distortion
	previousDistortion=currentDistortion;
	//re-intialize the currentDistortion to 0
	currentDistortion=0;
	//loop to assign each vector to a region/bucket
	for(int i=0;i<numberOfVectors;i++)
	{
		assignVectorsToBuckets(i);
		//break;
	}
	//update the centroid of each region
	updateCentroidsOfRegions();
	//Take the average of the current Distortion
	currentDistortion=currentDistortion/numberOfVectors;
	return 0;
}
long double applyLBG()
{
	//temporary array to store the current centroids of the regions
	long double temp[M][12]={0};
	for(int i=0;i<=K;i++)
	{
		for(int j=0;j<12;j++)
		{
			temp[i][j]=centroidBuckets[i][j];
		}	
	}
	for(int i=0;i<=K;i++)
	{
		for(int j=0;j<12;j++)
		{
			for(int k=i;k<i+2;)
			{
				//doubling the size of code book by addding epsilon and subtracting epslion for each vector in the current codebook
				centroidBuckets[i+k][j]=temp[i][j]-epsilon;
				k++;
				centroidBuckets[i+k][j]=temp[i][j]+epsilon;
				k++;
				
			}	
		}
	}

	//doubling the size of the code book..as index started with 0, after doubling plus 1 is added
	K=K*2+1;
	return 0;
}
void generateCodebook()
{
	readUniverseFile();
	//calcuating the universe centorid and intializing the code book with this centroid
	calculatingUniversalCentorid();
	//Until code book size becomes 8 (0..7 here)
	while(K!=M-1)
	{
		//apply LBG algo to double the codebook size
		applyLBG();

		//then apply K means algo on top of the doubled codebook to update the new centroids of each region
		for(int m=0;;m++)
		{
			for(int k=0;k<M;k++)
			{
				countVectorInBucket[k]=0;
			}
			
			kMeansAlgo();
			printf("m=%d,previousDistortion= %Lf,curretnDistortion=%Lf\n",m,previousDistortion,currentDistortion);
			/*for(int i=0;i<=K;i++)
			{
				printf("%d ",countVectorInBucket[i]);
			}*/
			//printf("\n");
			if(fabs(previousDistortion-currentDistortion)<DELTA)
			{
				break;
			}
		}
	}
	FILE *codebook=fopen("codebook_new_123.csv","w");
	printf("Final centroids of every Region after LBG Algo...\n");
	for(int i=0;i<M;i++)
	{
	//	printf("Region %d centroid:",i);
		for(int j=0;j<12;j++)
		{
			fprintf(codebook,"%Lf,",centroidBuckets[i][j]);
		}
		fprintf(codebook,"\n");
	}
	fclose(codebook);
}
long double readCodebook()
{
	FILE *fptr=fopen("codebook_new_123.csv","r");
		//checking if the file is opened or not
	if(fptr==NULL)
	{
		printf("File Not found");
		return -1;
	}
	for(int i=1;i<=M;i++)
	{
		for(int j=1;j<=12;j++)
		{
			fscanf(fptr,"%Lf%*c",&ref[i][j]);
		}
	}

}
long double readDataFromFilesToMatrices()
{
	FILE *aPtr=fopen("HMM_AIJ_FINAL.txt","r");
	FILE *aloaded=fopen("data/aloaded.txt","w");
	FILE *bloaded=fopen("data/bloaded.txt","w");
	if(aPtr==NULL)
	{
		printf("File not found\n");
	}
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			if(aPtr!=NULL)
			fscanf(aPtr,"%Lf",&A[i][j]);
			fprintf(aloaded,"%Lf ",A[i][j]);
		}
		fprintf(aloaded,"\n");
	}
//	fclose(aPtr)
	fclose(aloaded);
	FILE *bPtr=fopen("b.txt","r");
	if(bPtr==NULL)
	{
		printf("File not found\n");
	}
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			if(bPtr!=NULL)
			fscanf(bPtr,"%Lf",&B[i][j]);
				fprintf(bloaded,"%Lf ",B[i][j]);
		
		}
		fprintf(bloaded,"\n");
	}
	fclose(bloaded);
	FILE *piPtr=fopen("pi.txt","r");
	if(piPtr==NULL)
	{
		printf("File not found\n");
	}
	for(int i=1;i<=N;i++)
	{
		if(piPtr!=NULL)
		fscanf(piPtr,"%Lf",&pi[i]);	
	}
	fclose(aPtr);
	fclose(bPtr);
	fclose(piPtr);
	return 0;
}
//function for forward procedure to calculate alpha
long double calculate_alpha()
{
	//intialization step
	for(int i=1;i<=N;i++)
	{
		alpha[1][i]=pi[i]*B[i][O[1]];
	}
	//induction step
	for(int t=1;t<=frameNumber-1;t++)
	{
		
		for(int j=1;j<=N;j++)
		{
			long double sum=0;
			for(int i=1;i<=N;i++)
			{
				sum=sum+(alpha[t][i]*A[i][j]);
			}
			alpha[t+1][j]=sum*B[j][O[t+1]];
		}
	}
	return 0;
} 
//function for backward procedure to calcuate beta
long double calculate_beta()
{
	//intialization
	for(int i=1;i<=N;i++)
	{
		beta[frameNumber][i]=1;
	}
	//induction
	for(int t=frameNumber-1;t>=0;t--)
	{
		for(int i=1;i<=N;i++)
		{
			long double sum=0;
			for(int j=1;j<=N;j++)
			{
				beta[t][i]+=A[i][j]*B[j][O[t+1]]*beta[t+1][j];
			}
		}
	}
	
	return 0;
} 
//function to calucate gamma using alpha and beta generated above
long double calculate_gamma()
{
	for(int t=1;t<=frameNumber;t++)
	{
		long double sum=0;
		for(int i=1;i<=N;i++)
		{
			sum+=alpha[t][i]*beta[t][i];
		}
		for(int i=1;i<=N;i++)
		{
			gamma[t][i]=alpha[t][i]*beta[t][i]/sum;
		}
	}
	return 0;
} 
//function for viterbi algorithm to generate the delta and generate p* and q*
long double calculate_delta()
{
	for(int i=1;i<=N;i++)
	{
		delta[1][i]=pi[i]*B[i][O[1]];
		xhi[1][i]=0;
	}
	for(int t=2;t<=frameNumber;t++)
	{
		
		for(int j=1;j<=N;j++)
		{
			int maxIndex=0;
			long double max=-999;
			long double deltaValue;
			for(int i=1;i<=N;i++)
			{
				deltaValue=delta[t-1][i]*A[i][j];
				if(max<deltaValue)
				{
					max=deltaValue;
					maxIndex=i;
				}
			}
			delta[t][j]=max*B[j][O[t]];
			xhi[t][j]=maxIndex;
		}
	}
	long double max=delta[frameNumber][1];
	int maxIndex=0;
	for(int i=2;i<=N;i++)
	{
			if(max<=delta[frameNumber][i])
			{
				max=delta[frameNumber][i];
				maxIndex=i;
			}
	}
	pstar=max;
	qstarVal=maxIndex;
	qstar[frameNumber]=qstarVal;
	for(int t=frameNumber-1;t>=0;t--)
	{
		qstar[t]=xhi[t+1][qstar[t+1]];
	}
	return 0;
} 
//function to calcuate zeta
long double calculate_zi()
{
	long double numerator;
	long double denominator=0;
	for(int t=1;t<=frameNumber-1;t++)
	{
		denominator=0;
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=N;j++)
			{
				denominator=denominator+alpha[t][i]*A[i][j]*B[j][O[t+1]]*beta[t+1][j];
			}
		}
		for(int i=1;i<=N;i++)  
		{
			for(int j=1;j<=N;j++)
			{
				numerator=alpha[t][i]*A[i][j]*B[j][O[t+1]]*beta[t+1][j];
				zi[t][i][j]=numerator/denominator;
			}
			
		}
	}
	return 0;
} 
//function to update the matrices A,B and PI after reestimation
long double updatetheMatricesForConvergence()
{
	long double num=0;
	long double den=0;
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			den=0;
			num=0;
			for(int t=1;t<=frameNumber-1;t++)
			{
				den=den+gamma[t][i];
				num=num+zi[t][i][j];
			}
		//	printf("den=%.32e,num=%.32e",den,num);
			if(den!=0)
			A[i][j]=num/den;
		}
		
	}
	for(int j=1;j<=N;j++)
	{
		for(int k=1;k<=M;k++)
		{
			den=0;
			num=0;
			for(int t=1;t<=frameNumber;t++)
			{
				den=den+gamma[t][j];
				if(O[t]==k)
				{
					num=num+gamma[t][j];
				}
				
			}
			B[j][k]=num/den;
			if(B[j][k] == 0){ //if the value of bjk is 0 updating to the threshold
				B[j][k]=threshold;
			}
		}	
	}
	return 0;
} 
//function contains data to print output
long double printOutput()
{
	
	printf("A matrix...\n");

	for (int t = 1; t <= N; t++)
	{
		for (int j = 1; j <= N; j++)
		{
			printf("%e ", A[t][j]);
		}
		printf("\n");
	}
	printf("B matrix...\n");

	for (int t = 1; t <= N; t++)
	{
		for (int j = 1; j <= M; j++)
		{
			printf("%e ", B[t][j]);
		}
		printf("\n");
	}
	printf("alpha matrix...\n");

	for (int t = 1; t <= frameNumber; t++)
	{
		for (int j = 1; j <= N; j++)
		{
			printf("%e ", alpha[t][j]);
		}
		printf("\n");
	}

	printf("Beta matrix...\n");

	for (int t = 1; t <= frameNumber; t++)
	{
		for (int j = 1; j <= N; j++)
		{
			printf("%e ", beta[t][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("\n");
	printf("Pstar = %.32e\n",pstar);
	printf("State Sequence:\n");
	for(int t=1;t<=frameNumber;t++)
	{
		printf("%d ",qstar[t]);
	}
	printf("\n");
	printf("\n");
	return 0;
}  
//fucntion which intializes the average models
void intializeModels()
{
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			averageA[i][j]=0;
		}
	}
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			averageB[i][j]=0;
		}
	}
} 
//function to find the average of each digit models
long double findAverageOfTheModels()
{
	for(int digit=1;digit<=3;digit++)
	{
		intializeModels();
		for(int utterno=1;utterno<=25;utterno++)
		{
			char datapathA[100];
			sprintf(datapathA,"A_%d_%d.txt",digit,utterno);
			char datapathB[100];
			sprintf(datapathB,"B_%d_%d.txt",digit,utterno);
			FILE *dA=fopen(datapathA,"r");
			FILE *dB=fopen(datapathB,"r");
			for(int i=1;i<=N;i++)
			{
				for(int j=1;j<=N;j++)
				{
					long double value=0;
					if(dA!=NULL)
						fscanf(dA,"%Lf",&value);

					averageA[i][j]+=value;
				}
				
			}
			if(dA!=NULL)
					fclose(dA);
			for(int i=1;i<=N;i++)
			{
				for(int j=1;j<=M;j++)
				{
					long double value=0;
					if(dB!=NULL)
						fscanf(dB,"%Lf",&value);

					averageB[i][j]+=value;
				}
			}
			if(dB!=NULL)
					fclose(dB);
		}
		char datapathAA[100];
		sprintf(datapathAA,"averageA_%d.txt",digit);
		char datapathBB[100];
		sprintf(datapathBB,"averageB_%d.txt",digit);
		FILE *dAA=fopen(datapathAA,"w");
		FILE *dBB=fopen(datapathBB,"w");
			for(int i=1;i<=N;i++)
			{
				for(int j=1;j<=N;j++)
				{
					long double value=averageA[i][j]/25.0;
					if(dAA!=NULL)
						fprintf(dAA,"%Lf ",value);
					
				}
				if(dAA!=NULL)
					fprintf(dAA,"\n");
			}
			if(dAA!=NULL)
					fclose(dAA);
			for(int i=1;i<=N;i++)
			{
				for(int j=1;j<=M;j++)
				{
					long double value=averageB[i][j]/25.0;
					if(dBB!=NULL)
						fprintf(dBB,"%.5e ",value);
				}
				if(dBB!=NULL)
					fprintf(dBB,"\n");
			}
			if(dBB!=NULL)
					fclose(dBB);
	}

	
	

	return 0;
}  
//function to load the average model of each digit
void loadAverageModels(int digit)
{
	char filePath[100];
	sprintf(filePath,"averageA_%d.txt",digit);
	FILE *fptr=fopen(filePath,"r");
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			if(fptr!=NULL)
			fscanf(fptr,"%Lf",&A[i][j]);
		}
	}
	if(fptr!=NULL)
		fclose(fptr);

	char filePathB[100];
	sprintf(filePathB,"averageB_%d.txt",digit);
	FILE *fptrB=fopen(filePathB,"r");
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			if(fptrB!=NULL)
			fscanf(fptrB,"%Lf",&B[i][j]);
		}
	}
	if(fptrB!=NULL)
		fclose(fptrB);
	FILE *piPtr=fopen("pi.txt","r");
	if(piPtr==NULL)
	{
		printf("File not found\n");
	}
	for(int i=1;i<=N;i++)
	{
		if(piPtr!=NULL)
		fscanf(piPtr,"%Lf",&pi[i]);	
	}
	if(piPtr!=NULL)
		fclose(piPtr);
}  
int predictNumberOneorTwo(char *filePath)
{
	totalNumberOfSamples=0;
	frameNumber=0;
	processFile(filePath);
	long double max=DBL_MIN;
	int maxIndex=1;
	for(int i=1;i<=2;i++)
	{
		loadAverageModels(i);
		calculate_alpha();
		long double sum1=0;
		for(int j=1;j<=N;j++)
		{
			sum1=sum1+alpha[frameNumber][j];
		}
		if(sum1>max)
		{
			max=sum1;
			maxIndex=i;
		}
		//printf("\nP(O/lambda%d) = %.32e",i,sum1);
	}
			printf("\n");
			printf("The predicted Output of live test is %d\n",maxIndex);
			return maxIndex;
}
//function to train the models
void trainTheModel()
{
	generateUniverse();
	generateCodebook();
	char datasetName[250];
	FILE *dataset=fopen("data/datasetName.txt","r");
	if(dataset==NULL)
		printf("Filde not found");
	fscanf(dataset,"%s",datasetName);
	for(int digit=1;digit<=3;digit++)
	{
		for(int utterno=1;utterno<=20;utterno++)
		{
			totalNumberOfSamples=0;
			frameNumber=0;
			char filePath[100];
			char file[100]="";
			sprintf(filePath,"/224101027_E_%d_%d.txt",digit,utterno);
			strcat(file,datasetName);
			strcat(file,filePath);
			processFile(file);
			readDataFromFilesToMatrices();
			calculate_alpha();
			calculate_beta();
		//	printOutput();
			calculate_gamma();
			calculate_delta();
		//	printOutput();
			calculate_zi();
		//	printf("Inital Pstar before restimation %.32e\n",pstar);
			updatetheMatricesForConvergence();
			for(int i=0;i<60;i++)
			{
				calculate_alpha();
				calculate_beta();
				calculate_gamma();
				pstar_old=pstar;
				calculate_delta();
				calculate_zi();
				//printOutput();
				//printf("digit:%d\titertion:%d\tpstar=%.32e\n",digit,i,pstar);
				if(pstar<pstar_old)
						break;
				updatetheMatricesForConvergence();
			}
	//printOutput();
			char datapathA[100];
			sprintf(datapathA,"A_%d_%d.txt",digit,utterno);
			char datapathB[100];
			sprintf(datapathB,"B_%d_%d.txt",digit,utterno);
			FILE *dA=fopen(datapathA,"w");
			FILE *dB=fopen(datapathB,"w");
			for(int i=1;i<=N;i++)
			{
				for(int j=1;j<=N;j++)
				{
					if(dA!=NULL)
					fprintf(dA,"%Lf ",A[i][j]);
					

				}
				if(dA!=NULL)
				fprintf(dA,"\n");
			}
			if(dA!=NULL)
			fclose(dA);
			printf("Updated Matrixes B...\n");
			for(int i=1;i<=N;i++)
			{
				for(int j=1;j<=M;j++)
				{
					if(dB!=NULL)
					fprintf(dB,"%.5e ",B[i][j]);
				}
				if(dB!=NULL)
				fprintf(dB,"\n");
			}
			if(dB!=NULL)
			fclose(dB);
			printf("***************************************\n");		
		}
	}
}
//function to test the model 
long double testingModel()
{
	long double accuracy=0;
	long double totalAccuracysamples=0;
	char datasetName[250];
	FILE *dataset=fopen("data/datasetName.txt","r");
	if(dataset==NULL)
		printf("Filde not found");
	fscanf(dataset,"%s",datasetName);
	for(int digit=1;digit<=3;digit++)
	{
		for(int utterno=21;utterno<=30;utterno++)
		{
			totalNumberOfSamples=0;
			frameNumber=0;
			totalAccuracysamples++;
			char filePath[100];
			char file[100]="";
			sprintf(filePath,"/224101027_E_%d_%d.txt",digit,utterno);
			strcat(file,datasetName);
			strcat(file,filePath);
			processFile(file);
			long double max=DBL_MIN;
			int maxIndex=-1;
			for(int i=1;i<=3;i++)
			{
				loadAverageModels(i);
				calculate_alpha();
				long double sum1=0;
				for(int j=1;j<=N;j++)
				{
					sum1=sum1+alpha[frameNumber][j];
				}
				if(sum1>max)
				{
					max=sum1;
					maxIndex=i;
				}
				printf("\nP(O/lambda%d) = %.32e",i,sum1); 
			}
		//	printf("\n");
			printf("\nOrginal Data: %d Predicted Output: %d\n\n",digit,maxIndex);
			if(digit==maxIndex)
				accuracy++;
			
		}
	}
	printf("The accuracy of Model is %Lf%\n",(accuracy/totalAccuracysamples)*100);	
	accuracy=(accuracy/totalAccuracysamples)*100;
	return accuracy;
}
//function to test the live data given as input.. Note: The time for live recording given is 1 second
int predictNumber(char *filePath)
{
	totalNumberOfSamples=0;
	frameNumber=0;
	processFile(filePath);
	long double max=DBL_MIN;
	int maxIndex=3;
	for(int i=1;i<=3;i++)
	{
		loadAverageModels(i);
		calculate_alpha();
		long double sum1=0;
		for(int j=1;j<=N;j++)
		{
			sum1=sum1+alpha[frameNumber][j];
		}
		if(sum1>max)
		{
			max=sum1;
			maxIndex=i;
		}
		//	printf("\nP(O/lambda%d) = %.32e",i,sum1);
	}
			printf("\n");
			printf("The predicted Output of live test is %d\n",maxIndex);
			return maxIndex;
}
int confirmYesOrNo()
{
	#pragma comment(lib, "Winmm.lib")
	Sleep(2000);
	system("Recording_Module.exe 2 input_file.wav input_file.txt");
	int secondChoice=predictNumberOneorTwo("input_file.txt");
	printf("You confirmed %d\n",secondChoice);
	//int secondChoice=predictNumber("input_file.txt");
	return secondChoice;
} 
void ringtone()
{
	#pragma comment(lib, "Winmm.lib")
	PlaySound("wav/21.1.wav",0,SND_FILENAME);
	PlaySound("wav/hello.wav",0,SND_FILENAME); 
}
int chooseMoviesOrSeries()
{
	#pragma comment(lib, "Winmm.lib")
	int firstChoice=-1;
	int confirmation=-1;
	//return 1;
	printf("Voice out an option\n");
	printf("Tell 1 for Movies\n");
	printf("Tell 2 for Series\n");
	PlaySound("wav/1.1.wav",0,SND_FILENAME);
	PlaySound("wav/2.1.wav",0,SND_FILENAME);
	//PlaySound("sound1.wav",0,SND_FILENAME);
	Sleep(1000);
	system("Recording_Module.exe 2 input_file.wav input_file.txt");
	firstChoice=predictNumberOneorTwo("input_file.txt");
	printf("The choice selected is %d\n",firstChoice);
	if(firstChoice==1)
	{
		printf("Yayyyyyyy! You selected movies\n");
		PlaySound("wav/3.1.wav",0,SND_FILENAME);
		Sleep(500);
	}
	if(firstChoice==2)
	{
		PlaySound("wav/4.1.wav",0,SND_FILENAME);
		printf("Yayyyyyyy! You selected Series\n");
	}
	if(firstChoice!=1 && firstChoice!=2)
	{
		PlaySound("wav/5.1.wav",0,SND_FILENAME);
		printf("Wrong Option selected\n");
		return -1;
	}
	PlaySound("wav/7.1.wav",0,SND_FILENAME);
	PlaySound("wav/8.1.wav",0,SND_FILENAME);
	//PlaySound("yesornoconfirm.wav",0,SND_FILENAME);
	printf("\nPlease confirm the choice by saying Yes or No\n"); 
	confirmation = confirmYesOrNo();
	if(confirmation==1)
	{
		return firstChoice;
	}
	else if(confirmation==2)
	{
		return -1;
	}
	return -1;
}
int chooseMovieOrGeners(char *value)
{
	#pragma comment(lib, "Winmm.lib")
	int secondChoice;
	printf("Voice out an option\n");
	printf("Tell 1 for Drama\n");
	printf("Tell 2 for Horror\n");
	printf("Tell 3 for Action\n");
	PlaySound("wav/drama.wav",0,SND_FILENAME);
	PlaySound("wav/horror.wav",0,SND_FILENAME);
	PlaySound("wav/action.wav",0,SND_FILENAME);
	Sleep(1000);
	system("Recording_Module.exe 2 input_file.wav input_file.txt");
	secondChoice=predictNumber("input_file.txt");
	switch(secondChoice)
	{
		case 1:
			//PlaySound("wav/drama.wav",0,SND_FILENAME);
			printf("yayy! You selected Drama movies\n");
			break;
		case 2:
			//PlaySound("wav/horror.wav",0,SND_FILENAME);
			printf("yayy! You selected Horror movies\n");
			break;
		case 3:
			//PlaySound("wav/action.wav",0,SND_FILENAME);
			printf("yayy! You selected Action movies\n");
			//printf("genre 1 Movie 1\n");
			break;
		default:
			PlaySound("wav/5.1.wav",0,SND_FILENAME);
			printf("Wrong Option selected\n");
			return -1;
	}
	printf("Wahh!!!You selected is genere %d\n",secondChoice);
	if(secondChoice!=1 && secondChoice!=2 && secondChoice!=3 && secondChoice!=4 && secondChoice!=5)
	{
		printf("Wrong Option selected\n");
		return -1;
	}
	PlaySound("wav/7.1.wav",0,SND_FILENAME);
	PlaySound("wav/8.1.wav",0,SND_FILENAME);
	//PlaySound("yesornoconfirm.wav",0,SND_FILENAME);
	printf("Tell 1 for confirmation and Tell 2 for repeating options\n"); 
	int confirmation = confirmYesOrNo();
	if(confirmation==1)
	{
		return secondChoice;
	}
	else if(confirmation==2)
	{
		return -1;
	}
	return 0;
} 
int chooseOneMovie(int genre)
{
	#pragma comment(lib, "Winmm.lib")
	switch(genre)
	{
		case 1:
			printf("AlongForTheRide\n");
			printf("beforewego\n");
			printf("MidnightinParis2011\n");
			PlaySound("wav/movie11.wav",0,SND_FILENAME);
			PlaySound("wav/movie12.wav",0,SND_FILENAME);
			PlaySound("wav/movie13.wav",0,SND_FILENAME);
			break;
		case 2:
			printf("genre 1 Movie 1\n");
			printf("genre 2 Movie 1\n");
			printf("genre 3 Movie 1\n");
			PlaySound("wav/movie21.wav",0,SND_FILENAME);
			PlaySound("wav/movie22.wav",0,SND_FILENAME);
			PlaySound("wav/movie23.wav",0,SND_FILENAME);
			break;
		case 3:
			printf("Dunkirk\n");
			printf("TopGunMaverick2022\n");
			printf("VForVendetta\n");
			PlaySound("wav/movie31.wav",0,SND_FILENAME);
			PlaySound("wav/movie32.wav",0,SND_FILENAME);
			PlaySound("wav/movie33.wav",0,SND_FILENAME);
			break;
		default:
			printf("Wrong Option selected\n");
			break;
	}
	Sleep(2000);
	system("Recording_Module.exe 2 input_file.wav input_file.txt");
	int thirdChoice=predictNumber("input_file.txt");
	if(thirdChoice!=1 && thirdChoice!=2 && thirdChoice!=3 && thirdChoice!=4 && thirdChoice!=5)
	{
		printf("Wrong Option selected\n");
		return -1;
	}
	printf("Wahh!!!You selected is Movie %d\n",thirdChoice);
	Sleep(1000);
	PlaySound("wav/7.1.wav",0,SND_FILENAME);
	PlaySound("wav/8.1.wav",0,SND_FILENAME);
	printf("Tell 1 for confirmation and Tell 2 for repeating options\n");  
	int confirmation = confirmYesOrNo();
	if(confirmation==1)
	{
		return thirdChoice;
	}
	else if(confirmation==0)
	{
		//chooseOneMovie(genre);
		return -1;
	}
}
int chooseOneShow(int genre)
{
	#pragma comment(lib, "Winmm.lib")
	switch(genre)
	{
		case 1:
			printf("GameofThronesS01E01\n");
			printf("KotaFactoryS01E01\n");
			printf("Mirzapur\n");
			PlaySound("wav/show11.wav",0,SND_FILENAME);
			PlaySound("wav/show12.wav",0,SND_FILENAME);
			PlaySound("wav/show13.wav",0,SND_FILENAME);
			break;
		case 2:
			printf("DefendingJacobS1E1\n");
			printf("Sense8S1E1\n");
			printf("TheRainS1E1\n");
			PlaySound("wav/show21.wav",0,SND_FILENAME);
			PlaySound("wav/show22.wav",0,SND_FILENAME);
			PlaySound("wav/show23.wav",0,SND_FILENAME);
			break;
		case 3:
			printf("DaredevilS01E01\n");
			printf("SherlockS01E01\n");
			printf("TheMandalorianS01E01\n");
			PlaySound("wav/show31.wav",0,SND_FILENAME);
			PlaySound("wav/show32.wav",0,SND_FILENAME);
			PlaySound("wav/show33.wav",0,SND_FILENAME);
			break;
		default:
			printf("Wrong Option selected\n");
			break;
	}
	Sleep(2000);
	system("Recording_Module.exe 2 input_file.wav input_file.txt");
	int thirdChoice=predictNumber("input_file.txt");
	printf("Wahh!!!You selected is show %d",thirdChoice);
	PlaySound("wav/7.1.wav",0,SND_FILENAME);
	PlaySound("wav/8.1.wav",0,SND_FILENAME);
	printf("Please confirm the choice by saying Yes or No\n"); 
	int confirmation = confirmYesOrNo();
	if(confirmation==1)
	{
		return thirdChoice;
	}
	else if(confirmation==2)
	{
		//chooseOneMovie(genre);
		return -1;
	}
}
void testLiveModel()
{
	printf("Start\n");
	int firstChoice=chooseMoviesOrSeries();
	while(firstChoice==-1)
	{
		firstChoice=chooseMoviesOrSeries();
	}
	int secondChoice;
	int thirdChoice=-1;
	if(firstChoice==1)
	{
		secondChoice=chooseMovieOrGeners("Movies");	
		while(secondChoice==-1)
			secondChoice=chooseMovieOrGeners("Movies");
		thirdChoice = chooseOneMovie(secondChoice);
		while(thirdChoice==-1)
			thirdChoice = chooseOneMovie(secondChoice);
	}
	else if(firstChoice==2)
	{
		secondChoice=chooseMovieOrGeners("Shows");
		while(secondChoice==-1)
			secondChoice=chooseMovieOrGeners("Shows");
		thirdChoice = chooseOneShow(secondChoice);
		while(thirdChoice==-1)
			thirdChoice = chooseOneShow(secondChoice);

	}
	printf("Happy Binge Watch the movie/series number %d\n",thirdChoice);
	printf("*****************THE END***********************\n");
} 
void liveRecording()
{
	for(int i=0;i<30;i++)
	{
		system("Recording_Module.exe 2 input_file.wav input_file.txt");

	}
}
#endif