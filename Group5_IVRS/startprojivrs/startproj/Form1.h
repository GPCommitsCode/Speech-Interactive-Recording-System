#pragma once
#include"stdAfx.h"
#include"startproj1.h"
#include "liveRecording.h"
#include "code.h"
namespace startproj {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	protected: 
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::TextBox^  textBox2;

	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Panel^  movieshowpanel;
	private: System::Windows::Forms::TextBox^  WebSeries;


	private: System::Windows::Forms::TextBox^  Movies;

	private: System::Windows::Forms::TextBox^  movieorshows;

	private: System::Windows::Forms::Panel^  genrepanel;
	private: System::Windows::Forms::TextBox^  gener3;



	private: System::Windows::Forms::TextBox^  gener2;

	private: System::Windows::Forms::TextBox^  gener1;

	private: System::Windows::Forms::TextBox^  genreheader;

	private: System::Windows::Forms::Panel^  movienamepanel;
	private: System::Windows::Forms::TextBox^  moviename3;


	private: System::Windows::Forms::TextBox^  moviename2;

	private: System::Windows::Forms::TextBox^  moviename1;

	private: System::Windows::Forms::TextBox^  movienamesheader;

	private: System::Windows::Forms::Panel^  seriesnamepanel;
	private: System::Windows::Forms::TextBox^  showname3;


	private: System::Windows::Forms::TextBox^  showname2;

	private: System::Windows::Forms::TextBox^  showname1;

	private: System::Windows::Forms::TextBox^  shownamesheader;
	private: System::Windows::Forms::Button^  button1;





	private: System::Windows::Forms::Button^  button5;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->movieshowpanel = (gcnew System::Windows::Forms::Panel());
			this->WebSeries = (gcnew System::Windows::Forms::TextBox());
			this->Movies = (gcnew System::Windows::Forms::TextBox());
			this->movieorshows = (gcnew System::Windows::Forms::TextBox());
			this->genrepanel = (gcnew System::Windows::Forms::Panel());
			this->gener3 = (gcnew System::Windows::Forms::TextBox());
			this->gener2 = (gcnew System::Windows::Forms::TextBox());
			this->gener1 = (gcnew System::Windows::Forms::TextBox());
			this->genreheader = (gcnew System::Windows::Forms::TextBox());
			this->movienamepanel = (gcnew System::Windows::Forms::Panel());
			this->moviename3 = (gcnew System::Windows::Forms::TextBox());
			this->moviename2 = (gcnew System::Windows::Forms::TextBox());
			this->moviename1 = (gcnew System::Windows::Forms::TextBox());
			this->movienamesheader = (gcnew System::Windows::Forms::TextBox());
			this->seriesnamepanel = (gcnew System::Windows::Forms::Panel());
			this->showname3 = (gcnew System::Windows::Forms::TextBox());
			this->showname2 = (gcnew System::Windows::Forms::TextBox());
			this->showname1 = (gcnew System::Windows::Forms::TextBox());
			this->shownamesheader = (gcnew System::Windows::Forms::TextBox());
			this->panel1->SuspendLayout();
			this->movieshowpanel->SuspendLayout();
			this->genrepanel->SuspendLayout();
			this->movienamepanel->SuspendLayout();
			this->seriesnamepanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::Aqua;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox1->ForeColor = System::Drawing::Color::Black;
			this->textBox1->Location = System::Drawing::Point(10, 85);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(237, 43);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.2F, System::Drawing::FontStyle::Bold));
			this->button2->ForeColor = System::Drawing::Color::Snow;
			this->button2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button2.Image")));
			this->button2->Location = System::Drawing::Point(10, 135);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(237, 74);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Testing";
			this->button2->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::Color::Black;
			this->button3->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button3.Image")));
			this->button3->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->button3->Location = System::Drawing::Point(10, 271);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(237, 81);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Start\r\nIVRS";
			this->button3->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button3->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::SpringGreen;
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button4->ForeColor = System::Drawing::Color::Red;
			this->button4->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button4.Image")));
			this->button4->Location = System::Drawing::Point(20, 540);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(227, 69);
			this->button4->TabIndex = 4;
			this->button4->Text = L"Exit";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::PeachPuff;
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(10, 215);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(237, 50);
			this->textBox2->TabIndex = 5;
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &Form1::textBox2_TextChanged);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::OliveDrab;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1->Controls->Add(this->button5);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->button4);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->textBox2);
			this->panel1->Controls->Add(this->button3);
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Location = System::Drawing::Point(2, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(264, 641);
			this->panel1->TabIndex = 7;
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::PaleGreen;
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button5->ForeColor = System::Drawing::Color::Crimson;
			this->button5->Location = System::Drawing::Point(8, 402);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(237, 73);
			this->button5->TabIndex = 7;
			this->button5->Text = L"Live Training";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// button1
			// 
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::Black;
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button1.Image")));
			this->button1->Location = System::Drawing::Point(10, 8);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(237, 71);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Training";
			this->button1->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// movieshowpanel
			// 
			this->movieshowpanel->BackColor = System::Drawing::Color::MediumSeaGreen;
			this->movieshowpanel->Controls->Add(this->WebSeries);
			this->movieshowpanel->Controls->Add(this->Movies);
			this->movieshowpanel->Controls->Add(this->movieorshows);
			this->movieshowpanel->Location = System::Drawing::Point(272, 2);
			this->movieshowpanel->Name = L"movieshowpanel";
			this->movieshowpanel->Size = System::Drawing::Size(380, 328);
			this->movieshowpanel->TabIndex = 8;
			this->movieshowpanel->Visible = false;
			this->movieshowpanel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::movieshowpanel_Paint);
			// 
			// WebSeries
			// 
			this->WebSeries->BackColor = System::Drawing::Color::RosyBrown;
			this->WebSeries->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->WebSeries->Location = System::Drawing::Point(83, 170);
			this->WebSeries->Multiline = true;
			this->WebSeries->Name = L"WebSeries";
			this->WebSeries->Size = System::Drawing::Size(171, 39);
			this->WebSeries->TabIndex = 2;
			this->WebSeries->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->WebSeries->TextChanged += gcnew System::EventHandler(this, &Form1::WebSeries_TextChanged);
			// 
			// Movies
			// 
			this->Movies->BackColor = System::Drawing::Color::RosyBrown;
			this->Movies->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Movies->Location = System::Drawing::Point(83, 102);
			this->Movies->Multiline = true;
			this->Movies->Name = L"Movies";
			this->Movies->Size = System::Drawing::Size(171, 39);
			this->Movies->TabIndex = 1;
			this->Movies->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// movieorshows
			// 
			this->movieorshows->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->movieorshows->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->movieorshows->Location = System::Drawing::Point(38, 32);
			this->movieorshows->Multiline = true;
			this->movieorshows->Name = L"movieorshows";
			this->movieorshows->Size = System::Drawing::Size(267, 37);
			this->movieorshows->TabIndex = 0;
			this->movieorshows->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// genrepanel
			// 
			this->genrepanel->BackColor = System::Drawing::Color::DarkSeaGreen;
			this->genrepanel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->genrepanel->Controls->Add(this->gener3);
			this->genrepanel->Controls->Add(this->gener2);
			this->genrepanel->Controls->Add(this->gener1);
			this->genrepanel->Controls->Add(this->genreheader);
			this->genrepanel->Location = System::Drawing::Point(658, 2);
			this->genrepanel->Name = L"genrepanel";
			this->genrepanel->Size = System::Drawing::Size(409, 328);
			this->genrepanel->TabIndex = 9;
			this->genrepanel->Visible = false;
			// 
			// gener3
			// 
			this->gener3->BackColor = System::Drawing::Color::Khaki;
			this->gener3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->gener3->Location = System::Drawing::Point(101, 240);
			this->gener3->Multiline = true;
			this->gener3->Name = L"gener3";
			this->gener3->Size = System::Drawing::Size(197, 47);
			this->gener3->TabIndex = 3;
			this->gener3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// gener2
			// 
			this->gener2->BackColor = System::Drawing::Color::Khaki;
			this->gener2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->gener2->Location = System::Drawing::Point(101, 177);
			this->gener2->Multiline = true;
			this->gener2->Name = L"gener2";
			this->gener2->Size = System::Drawing::Size(197, 43);
			this->gener2->TabIndex = 2;
			this->gener2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// gener1
			// 
			this->gener1->BackColor = System::Drawing::Color::Khaki;
			this->gener1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->gener1->Location = System::Drawing::Point(101, 113);
			this->gener1->Multiline = true;
			this->gener1->Name = L"gener1";
			this->gener1->Size = System::Drawing::Size(197, 45);
			this->gener1->TabIndex = 1;
			this->gener1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// genreheader
			// 
			this->genreheader->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->genreheader->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->genreheader->Location = System::Drawing::Point(16, 30);
			this->genreheader->Multiline = true;
			this->genreheader->Name = L"genreheader";
			this->genreheader->Size = System::Drawing::Size(343, 37);
			this->genreheader->TabIndex = 0;
			this->genreheader->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// movienamepanel
			// 
			this->movienamepanel->BackColor = System::Drawing::Color::MediumAquamarine;
			this->movienamepanel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->movienamepanel->Controls->Add(this->moviename3);
			this->movienamepanel->Controls->Add(this->moviename2);
			this->movienamepanel->Controls->Add(this->moviename1);
			this->movienamepanel->Controls->Add(this->movienamesheader);
			this->movienamepanel->Location = System::Drawing::Point(272, 336);
			this->movienamepanel->Name = L"movienamepanel";
			this->movienamepanel->Size = System::Drawing::Size(380, 307);
			this->movienamepanel->TabIndex = 10;
			this->movienamepanel->Visible = false;
			// 
			// moviename3
			// 
			this->moviename3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->moviename3->Location = System::Drawing::Point(81, 206);
			this->moviename3->Multiline = true;
			this->moviename3->Name = L"moviename3";
			this->moviename3->Size = System::Drawing::Size(184, 39);
			this->moviename3->TabIndex = 3;
			this->moviename3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// moviename2
			// 
			this->moviename2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->moviename2->Location = System::Drawing::Point(81, 145);
			this->moviename2->Multiline = true;
			this->moviename2->Name = L"moviename2";
			this->moviename2->Size = System::Drawing::Size(184, 38);
			this->moviename2->TabIndex = 2;
			this->moviename2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// moviename1
			// 
			this->moviename1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->moviename1->Location = System::Drawing::Point(81, 86);
			this->moviename1->Multiline = true;
			this->moviename1->Name = L"moviename1";
			this->moviename1->Size = System::Drawing::Size(184, 37);
			this->moviename1->TabIndex = 1;
			this->moviename1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// movienamesheader
			// 
			this->movienamesheader->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->movienamesheader->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->movienamesheader->Location = System::Drawing::Point(36, 8);
			this->movienamesheader->Multiline = true;
			this->movienamesheader->Name = L"movienamesheader";
			this->movienamesheader->Size = System::Drawing::Size(267, 36);
			this->movienamesheader->TabIndex = 0;
			this->movienamesheader->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// seriesnamepanel
			// 
			this->seriesnamepanel->BackColor = System::Drawing::Color::LightSeaGreen;
			this->seriesnamepanel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->seriesnamepanel->Controls->Add(this->showname3);
			this->seriesnamepanel->Controls->Add(this->showname2);
			this->seriesnamepanel->Controls->Add(this->showname1);
			this->seriesnamepanel->Controls->Add(this->shownamesheader);
			this->seriesnamepanel->Location = System::Drawing::Point(658, 336);
			this->seriesnamepanel->Name = L"seriesnamepanel";
			this->seriesnamepanel->Size = System::Drawing::Size(409, 307);
			this->seriesnamepanel->TabIndex = 11;
			this->seriesnamepanel->Visible = false;
			// 
			// showname3
			// 
			this->showname3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->showname3->Location = System::Drawing::Point(101, 206);
			this->showname3->Multiline = true;
			this->showname3->Name = L"showname3";
			this->showname3->Size = System::Drawing::Size(186, 39);
			this->showname3->TabIndex = 3;
			this->showname3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->showname3->TextChanged += gcnew System::EventHandler(this, &Form1::showname3_TextChanged);
			// 
			// showname2
			// 
			this->showname2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->showname2->Location = System::Drawing::Point(101, 145);
			this->showname2->Multiline = true;
			this->showname2->Name = L"showname2";
			this->showname2->Size = System::Drawing::Size(186, 38);
			this->showname2->TabIndex = 2;
			this->showname2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// showname1
			// 
			this->showname1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->showname1->Location = System::Drawing::Point(101, 86);
			this->showname1->Multiline = true;
			this->showname1->Name = L"showname1";
			this->showname1->Size = System::Drawing::Size(186, 38);
			this->showname1->TabIndex = 1;
			this->showname1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// shownamesheader
			// 
			this->shownamesheader->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->shownamesheader->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->shownamesheader->Location = System::Drawing::Point(16, 7);
			this->shownamesheader->Multiline = true;
			this->shownamesheader->Name = L"shownamesheader";
			this->shownamesheader->Size = System::Drawing::Size(343, 39);
			this->shownamesheader->TabIndex = 0;
			this->shownamesheader->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightCyan;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1071, 645);
			this->Controls->Add(this->seriesnamepanel);
			this->Controls->Add(this->movienamepanel);
			this->Controls->Add(this->genrepanel);
			this->Controls->Add(this->movieshowpanel);
			this->Controls->Add(this->panel1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->movieshowpanel->ResumeLayout(false);
			this->movieshowpanel->PerformLayout();
			this->genrepanel->ResumeLayout(false);
			this->genrepanel->PerformLayout();
			this->movienamepanel->ResumeLayout(false);
			this->movienamepanel->PerformLayout();
			this->seriesnamepanel->ResumeLayout(false);
			this->seriesnamepanel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
					
				 textBox2->Text="";
				textBox1->Text="Training in Progress.......";
				readCodebook();
				trainTheModel();
             	findAverageOfTheModels();
				textBox1->Text="Training Completed";
			 }
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
				 Application::Exit();
			 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		//	 textBox1->Text ="";
			 textBox2->Text="Testing in Progress.......";
			 long double accuracy=testingModel();
		     textBox2->Text="Accuracy : "+accuracy.ToString()+"%";	
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			#pragma comment(lib, "Winmm.lib")
			ringtone();
			Sleep(1000);
			movieshowpanel->Visible=true;
			movieshowpanel->Update();
			movieorshows->Text = "Voice out the Option";
			movieorshows->Update();
			Movies->Text="1.MOVIES";
			Movies->Update();
			WebSeries->Text="2.WEB SERIES";
			WebSeries->Update();
			//testLiveModel();
			int firstChoice=chooseMoviesOrSeries();
			while(firstChoice==-1)
			{
				firstChoice=chooseMoviesOrSeries();
			}
			genrepanel->Visible=true;
			genrepanel->Update();
			genreheader->Text =" Voice out the your favouire genre";
			genreheader->Update();
			gener1->Text = "Drama";
			gener1->Update();
			gener2->Text = "Horror";
			gener2->Update();
			gener3->Text = "Action";
			gener3->Update();
			int secondChoice;
			int thirdChoice=-1;
			if(firstChoice==1)
			{
				secondChoice=chooseMovieOrGeners("Movies");	
				while(secondChoice==-1)
					secondChoice=chooseMovieOrGeners("Movies");
				movienamepanel->Visible=true;
				movienamepanel->Update();
				movienamesheader->Text="Choose your favorite movie";
				movienamesheader->Update();
				if(secondChoice==1)
				{
					moviename1->Text="AlongForTheRide";
					moviename1->Update();
					moviename2->Text="beforewego";
					moviename2->Update();
					moviename3->Text="MidnightinParis2011";
					moviename3->Update();
				}
				else if(secondChoice==2)
				{
					moviename1->Text="Anabella";
					moviename1->Update();
					moviename2->Text="Conjuring";
					moviename2->Update();
					moviename3->Text="Nun";
					moviename3->Update();
				}
				else if(secondChoice==3)
				{
					moviename1->Text="Dunkirk";
					moviename1->Update();
					moviename2->Text="TopGunMaverick2022";
					moviename2->Update();
					moviename3->Text="VForVendetta";
					moviename3->Update();
				}
			
				thirdChoice = chooseOneMovie(secondChoice);
				while(thirdChoice==-1)
					thirdChoice = chooseOneMovie(secondChoice);
			    	if(secondChoice==1)
				{
					if(thirdChoice==1)
					{
						char vlcPath[100]="vlc C:\\Users\\JP\\Videos\\Movies\\Drama\\AlongForTheRide.mkv";
						system(vlcPath);
					}
					if(thirdChoice==2)
					{
						char vlcPath[100]="vlc C:\\Users\\JP\\Videos\\Movies\\Drama\\beforewego.mkv";
						system(vlcPath);
					}
					if(thirdChoice==3)
					{
						char vlcPath[100]="vlc C:\\Users\\JP\\Videos\\Movies\\Drama\\MidnightinParis2011.mkv";
						system(vlcPath);
					}
					
				}
				if(secondChoice==2)
				{
					if(thirdChoice==1)
					{
						char vlcPath[100]="vlc C:\\Users\\JP\\Videos\\Movies\\Horror\\Annabelle.mp4";
						system(vlcPath);
					}
					if(thirdChoice==2)
					{
						char vlcPath[100]="vlc C:\\Users\\JP\\Videos\\Movies\\Horror\\Conjuring.mp4";
						system(vlcPath);
					}
					if(thirdChoice==3)
					{
						char vlcPath[100]="vlc C:\\Users\\JP\\Videos\\Movies\\Horror\\NUN.mp4";
						system(vlcPath);
					}
					
				}
				if(secondChoice==3)
				{
					if(thirdChoice==1)
					{
						char vlcPath[100]="vlc C:\\Users\\JP\\Videos\\Movies\\Action\\Dunkirk.mp4";
						system(vlcPath);
					}
					if(thirdChoice==2)
					{
						char vlcPath[100]="vlc C:\\Users\\JP\\Videos\\Movies\\Action\\TopGunMaverick2022.mkv";
						system(vlcPath);
					}
					if(thirdChoice==3)
					{
						char vlcPath[100]="vlc C:\\Users\\JP\\Videos\\Movies\\Action\\VForVendetta.mkv";
						system(vlcPath);
					}
					
				}
			}
			else if(firstChoice==2)
			{
				secondChoice=chooseMovieOrGeners("Shows");
				while(secondChoice==-1)
					secondChoice=chooseMovieOrGeners("Shows");
				seriesnamepanel->Visible=true;
				seriesnamepanel->Update();
				shownamesheader->Text="Choose Your favorite show";
				shownamesheader->Update();
				if(secondChoice==1)
				{
						showname1->Text="GameofThrones";
						showname1->Update();
						showname2->Text="KotaFactory";
						showname2->Update();
						showname3->Text="Mirzapur";
						showname3->Update();
				}
				else if(secondChoice==2)
				{
						showname1->Text="D Jacob";
						showname1->Update();
						showname2->Text="Sense";
						showname2->Update();
						showname3->Text="TheRain";
						showname3->Update();
				}
				else if(secondChoice==3)
				{
						showname1->Text="Daredevil";
						showname1->Update();
						showname2->Text="Sherlock";
						showname2->Update();
						showname3->Text="Mandalorian";
						showname3->Update();
				}
			
				thirdChoice = chooseOneShow(secondChoice);
				while(thirdChoice==-1)
					thirdChoice = chooseOneShow(secondChoice);
				if(secondChoice==1)
				{
					if(thirdChoice==1)
					{
						char vlcPath[100]="vlc C:\\Users\\JP\\Videos\\Shows\\Drama\\GameofThronesS01E01.mkv";
						system(vlcPath);
					}
					if(thirdChoice==2)
					{
						char vlcPath[100]="vlc C:\\Users\\JP\\Videos\\Shows\\Drama\\KotaFactoryS01E01.mkv";
						system(vlcPath);
					}
					if(thirdChoice==3)
					{
						char vlcPath[100]="vlc C:\\Users\\JP\\Videos\\Shows\\Drama\\Mirzapur.mp4";
						system(vlcPath);
					}
					
				}
				if(secondChoice==2)
				{
					if(thirdChoice==1)
					{
						char vlcPath[100]="vlc C:\\Users\\JP\\Videos\\Shows\\Thriller\\DefendingJacobS1E1.mkv";
						system(vlcPath);
					}
					if(thirdChoice==2)
					{
						char vlcPath[100]="vlc C:\\Users\\JP\\Videos\\Shows\\Thriller\\Sense8S1E1.mkv";
						system(vlcPath);
					}
					if(thirdChoice==3)
					{
						char vlcPath[100]="vlc C:\\Users\\JP\\Videos\\Shows\\Thriller\\TheRainS1E1.mkv";
						system(vlcPath);
					}
					
				}
				if(secondChoice==3)
				{
					if(thirdChoice==1)
					{
						char vlcPath[100]="vlc C:\\Users\\JP\\Videos\\Shows\\Action\\DaredevilS01E01.mp4";
						system(vlcPath);
					}
					if(thirdChoice==2)
					{
						char vlcPath[100]="vlc C:\\Users\\JP\\Videos\\Shows\\Action\\SherlockS01E01.mkv";
						system(vlcPath);
					}
					if(thirdChoice==3)
					{
						char vlcPath[100]="vlc C:\\Users\\JP\\Videos\\Shows \\Action\\TheMandalorianS01E01.mkv";
						system(vlcPath);
					}
					
				}

			}
		 }
private: System::Void textBox3_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {

		 }
private: System::Void movieshowpanel_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		 }
private: System::Void WebSeries_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void showname3_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void textBox4_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
//			 liveRecording->Visible=true;
			// liveRecording->Update();
			 this->Hide();
			 liveRecording^ f2=gcnew liveRecording();
			 f2->ShowDialog();

		 }

private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}

