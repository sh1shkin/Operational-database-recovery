#pragma once
#include "ConnectionWindow.h"

namespace src {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Data::Odbc;
    using namespace System::Collections::Generic;
    /// <summary>
    /// Сводка для PartialMainWindow
    /// </summary>
    //ref class ConnectionWindow;
    public ref class PartialMainWindow : public System::Windows::Forms::Form
    {
    private:
        String^ PathConfig1;
        String^ PathConfig2;
        bool isDragging;
        Point^ dragStartPoint;
        ConnectionWindow^ connectForm;
        OdbcConnection^ db_connect1;
        OdbcConnection^ db_connect2;
        array<array<String^>^>^ queryParams;
        array<array<String^>^>^ queryParams1;
        OdbcConnection^ connect;
        String^ nameDBMS;
        String^ nameDB;
        String^ tableInput;
        String^ tableOutput;
        String^ columnInputId;
        String^ columnOutputId;
        array<String^>^ confDB1;
        String^ Server;
        String^ Driver;
        String^ DataIn1;
        String^ DataIn2;
        String^ DataIn3;
        String^ DataOut1;
        String^ DataOut2;
        String^ DataOut3;
        String^ nameDBMS2;
        String^ Server2;
        String^ DataBase2;
        String^ User2;
        String^ Driver2;
        String^ tableInput2;
        String^ tableOutput2;
        String^ columnInputId2;
        String^ columnOutputId2;
        String^ nameUser;

    private: System::Windows::Forms::Button^ btnClosed;
    private: System::Windows::Forms::Button^ button1;


    private: System::Windows::Forms::Label^ labArea2;
    private: System::Windows::Forms::TextBox^ TextBoxPassword;
    private: System::Windows::Forms::Label^ lblPassword;
    private: System::Windows::Forms::Button^ btnConnectDB2;
    private: System::Windows::Forms::Label^ lblConnectDB2Title;
    private: System::Windows::Forms::PictureBox^ pictureBox2;
    private: System::Windows::Forms::Button^ btnConnectDB1;
    private: System::Windows::Forms::Label^ labArea1;
    private: System::Windows::Forms::Button^ btnUpdateconfig1;
    private: System::Windows::Forms::Panel^ panelConnectDB2;
    private: System::Windows::Forms::PictureBox^ pictureBox4;
    private: System::Windows::Forms::Button^ btnUpdateconfig2;





    public:
        PartialMainWindow(void)
        {
            InitializeComponent();
        }

        PartialMainWindow(OdbcConnection^ connection, String^ typeStr, String^ dbName, String^ userName, ConnectionWindow^ connectForm, array<String^>^ confBD1)
            : db_connect1(connection), nameDBMS(typeStr), nameDB(dbName), nameUser(userName), db_connect2(nullptr), connectForm(connectForm), confDB1(confBD1)
        {
            InitializeComponent();
            lblConnectionInfo->Text = String::Format("DB1: {0}: {1}/{2}", typeStr, dbName, userName);
        
            isDragging = false;
            dragStartPoint = gcnew Point(0, 0);
        }

    protected:
        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        ~PartialMainWindow()
        {
            if (components) delete components;
            if (db_connect1 != nullptr && db_connect1->State == ConnectionState::Open) db_connect1->Close();
            if (db_connect2 != nullptr && db_connect2->State == ConnectionState::Open) db_connect2->Close();
        }

    private: System::Windows::Forms::Panel^ headerPanel;
    private: System::Windows::Forms::Label^ lblTitle;
    private: System::Windows::Forms::Label^ lblConnectionInfo;

    private: System::Windows::Forms::Panel^ panelID2;
    private: System::Windows::Forms::Label^ lblID2Title;
    private: System::Windows::Forms::Label^ lblID2In;
    private: System::Windows::Forms::TextBox^ txtID2In;
    private: System::Windows::Forms::Label^ lblID2Out;
    private: System::Windows::Forms::TextBox^ txtID2Out;
    private: System::Windows::Forms::Button^ btnGetID;




    private: System::Windows::Forms::Panel^ panelLogs;
    private: System::Windows::Forms::Label^ lblLogsTitle;
    private: System::Windows::Forms::RichTextBox^ lstLogs;


    private: System::Windows::Forms::PictureBox^ pictureBox1;

    private: System::Windows::Forms::PictureBox^ pictureBox3;
    private: System::Windows::Forms::Panel^ panel1;
    private: System::Windows::Forms::Panel^ panel2;

           // Поле для ввода пароля
           // Метка для поля пароля

    private:
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(PartialMainWindow::typeid));
            this->headerPanel = (gcnew System::Windows::Forms::Panel());
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            this->lblTitle = (gcnew System::Windows::Forms::Label());
            this->lblConnectionInfo = (gcnew System::Windows::Forms::Label());
            this->panelID2 = (gcnew System::Windows::Forms::Panel());
            this->labArea2 = (gcnew System::Windows::Forms::Label());
            this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
            this->lblID2Title = (gcnew System::Windows::Forms::Label());
            this->lblID2In = (gcnew System::Windows::Forms::Label());
            this->txtID2In = (gcnew System::Windows::Forms::TextBox());
            this->lblID2Out = (gcnew System::Windows::Forms::Label());
            this->txtID2Out = (gcnew System::Windows::Forms::TextBox());
            this->btnGetID = (gcnew System::Windows::Forms::Button());
            this->panel1 = (gcnew System::Windows::Forms::Panel());
            this->panel2 = (gcnew System::Windows::Forms::Panel());
            this->panelLogs = (gcnew System::Windows::Forms::Panel());
            this->lblLogsTitle = (gcnew System::Windows::Forms::Label());
            this->lstLogs = (gcnew System::Windows::Forms::RichTextBox());
            this->btnClosed = (gcnew System::Windows::Forms::Button());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->TextBoxPassword = (gcnew System::Windows::Forms::TextBox());
            this->lblPassword = (gcnew System::Windows::Forms::Label());
            this->btnConnectDB2 = (gcnew System::Windows::Forms::Button());
            this->lblConnectDB2Title = (gcnew System::Windows::Forms::Label());
            this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
            this->btnConnectDB1 = (gcnew System::Windows::Forms::Button());
            this->labArea1 = (gcnew System::Windows::Forms::Label());
            this->btnUpdateconfig1 = (gcnew System::Windows::Forms::Button());
            this->panelConnectDB2 = (gcnew System::Windows::Forms::Panel());
            this->btnUpdateconfig2 = (gcnew System::Windows::Forms::Button());
            this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
            this->headerPanel->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            this->panelID2->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
            this->panelLogs->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
            this->panelConnectDB2->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
            this->SuspendLayout();
            // 
            // headerPanel
            // 
            this->headerPanel->BackColor = System::Drawing::Color::White;
            this->headerPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->headerPanel->Controls->Add(this->pictureBox1);
            this->headerPanel->Controls->Add(this->lblTitle);
            this->headerPanel->Controls->Add(this->lblConnectionInfo);
            this->headerPanel->Location = System::Drawing::Point(6, 52);
            this->headerPanel->Name = L"headerPanel";
            this->headerPanel->Size = System::Drawing::Size(852, 80);
            this->headerPanel->TabIndex = 0;
            // 
            // pictureBox1
            // 
            this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
            this->pictureBox1->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.InitialImage")));
            this->pictureBox1->Location = System::Drawing::Point(15, 21);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(36, 36);
            this->pictureBox1->TabIndex = 4;
            this->pictureBox1->TabStop = false;
            // 
            // lblTitle
            // 
            this->lblTitle->AutoSize = true;
            this->lblTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold));
            this->lblTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(58)),
                static_cast<System::Int32>(static_cast<System::Byte>(138)));
            this->lblTitle->Location = System::Drawing::Point(54, 10);
            this->lblTitle->Name = L"lblTitle";
            this->lblTitle->Size = System::Drawing::Size(442, 41);
            this->lblTitle->TabIndex = 1;
            this->lblTitle->Text = L"Управление ID2 для рулонов";
            // 
            // lblConnectionInfo
            // 
            this->lblConnectionInfo->AutoSize = true;
            this->lblConnectionInfo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->lblConnectionInfo->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)),
                static_cast<System::Int32>(static_cast<System::Byte>(78)), static_cast<System::Int32>(static_cast<System::Byte>(216)));
            this->lblConnectionInfo->Location = System::Drawing::Point(58, 46);
            this->lblConnectionInfo->Name = L"lblConnectionInfo";
            this->lblConnectionInfo->Size = System::Drawing::Size(0, 23);
            this->lblConnectionInfo->TabIndex = 2;
            // 
            // panelID2
            // 
            this->panelID2->BackColor = System::Drawing::Color::White;
            this->panelID2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->panelID2->Controls->Add(this->pictureBox3);
            this->panelID2->Controls->Add(this->labArea2);
            this->panelID2->Controls->Add(this->lblID2Title);
            this->panelID2->Controls->Add(this->lblID2In);
            this->panelID2->Controls->Add(this->txtID2In);
            this->panelID2->Controls->Add(this->lblID2Out);
            this->panelID2->Controls->Add(this->txtID2Out);
            this->panelID2->Controls->Add(this->btnGetID);
            this->panelID2->Controls->Add(this->panel1);
            this->panelID2->Controls->Add(this->panel2);
            this->panelID2->Location = System::Drawing::Point(4, 334);
            this->panelID2->Name = L"panelID2";
            this->panelID2->Size = System::Drawing::Size(854, 118);
            this->panelID2->TabIndex = 4;
            // 
            // labArea2
            // 
            this->labArea2->AutoSize = true;
            this->labArea2->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->labArea2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(78)),
                static_cast<System::Int32>(static_cast<System::Byte>(216)));
            this->labArea2->Location = System::Drawing::Point(8, 5);
            this->labArea2->Name = L"labArea2";
            this->labArea2->Size = System::Drawing::Size(36, 40);
            this->labArea2->TabIndex = 38;
            this->labArea2->Text = L"2";
            // 
            // pictureBox3
            // 
            this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
            this->pictureBox3->Location = System::Drawing::Point(41, 7);
            this->pictureBox3->Name = L"pictureBox3";
            this->pictureBox3->Size = System::Drawing::Size(32, 32);
            this->pictureBox3->TabIndex = 21;
            this->pictureBox3->TabStop = false;
            // 
            // lblID2Title
            // 
            this->lblID2Title->AutoSize = true;
            this->lblID2Title->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold));
            this->lblID2Title->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(58)),
                static_cast<System::Int32>(static_cast<System::Byte>(138)));
            this->lblID2Title->Location = System::Drawing::Point(78, 11);
            this->lblID2Title->Name = L"lblID2Title";
            this->lblID2Title->Size = System::Drawing::Size(295, 32);
            this->lblID2Title->TabIndex = 5;
            this->lblID2Title->Text = L"Запрос max id из Oracle";
            // 
            // lblID2In
            // 
            this->lblID2In->AutoSize = true;
            this->lblID2In->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->lblID2In->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(78)),
                static_cast<System::Int32>(static_cast<System::Byte>(216)));
            this->lblID2In->Location = System::Drawing::Point(20, 50);
            this->lblID2In->Name = L"lblID2In";
            this->lblID2In->Size = System::Drawing::Size(68, 20);
            this->lblID2In->TabIndex = 6;
            this->lblID2In->Text = L"ID2 вход";
            // 
            // txtID2In
            // 
            this->txtID2In->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(219)), static_cast<System::Int32>(static_cast<System::Byte>(234)),
                static_cast<System::Int32>(static_cast<System::Byte>(254)));
            this->txtID2In->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->txtID2In->Font = (gcnew System::Drawing::Font(L"Consolas", 12));
            this->txtID2In->Location = System::Drawing::Point(31, 75);
            this->txtID2In->Name = L"txtID2In";
            this->txtID2In->ReadOnly = true;
            this->txtID2In->Size = System::Drawing::Size(235, 24);
            this->txtID2In->TabIndex = 7;
            // 
            // lblID2Out
            // 
            this->lblID2Out->AutoSize = true;
            this->lblID2Out->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->lblID2Out->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(78)),
                static_cast<System::Int32>(static_cast<System::Byte>(216)));
            this->lblID2Out->Location = System::Drawing::Point(290, 50);
            this->lblID2Out->Name = L"lblID2Out";
            this->lblID2Out->Size = System::Drawing::Size(79, 20);
            this->lblID2Out->TabIndex = 8;
            this->lblID2Out->Text = L"ID2 выход";
            // 
            // txtID2Out
            // 
            this->txtID2Out->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(219)), static_cast<System::Int32>(static_cast<System::Byte>(234)),
                static_cast<System::Int32>(static_cast<System::Byte>(254)));
            this->txtID2Out->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->txtID2Out->Font = (gcnew System::Drawing::Font(L"Consolas", 12));
            this->txtID2Out->Location = System::Drawing::Point(303, 75);
            this->txtID2Out->Name = L"txtID2Out";
            this->txtID2Out->ReadOnly = true;
            this->txtID2Out->Size = System::Drawing::Size(233, 24);
            this->txtID2Out->TabIndex = 9;
            // 
            // btnGetID
            // 
            this->btnGetID->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(78)),
                static_cast<System::Int32>(static_cast<System::Byte>(216)));
            this->btnGetID->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)),
                static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(175)));
            this->btnGetID->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnGetID->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->btnGetID->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->btnGetID->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnGetID.Image")));
            this->btnGetID->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
            this->btnGetID->Location = System::Drawing::Point(560, 70);
            this->btnGetID->Name = L"btnGetID";
            this->btnGetID->Size = System::Drawing::Size(280, 30);
            this->btnGetID->TabIndex = 10;
            this->btnGetID->Text = L"  Получить max ID из Oracle";
            this->btnGetID->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
            this->btnGetID->UseVisualStyleBackColor = false;
            this->btnGetID->Click += gcnew System::EventHandler(this, &PartialMainWindow::btnGetID_Click);
            // 
            // panel1
            // 
            this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(219)), static_cast<System::Int32>(static_cast<System::Byte>(234)),
                static_cast<System::Int32>(static_cast<System::Byte>(254)));
            this->panel1->Location = System::Drawing::Point(20, 70);
            this->panel1->Name = L"panel1";
            this->panel1->Size = System::Drawing::Size(250, 30);
            this->panel1->TabIndex = 6;
            // 
            // panel2
            // 
            this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(219)), static_cast<System::Int32>(static_cast<System::Byte>(234)),
                static_cast<System::Int32>(static_cast<System::Byte>(254)));
            this->panel2->Location = System::Drawing::Point(290, 70);
            this->panel2->Name = L"panel2";
            this->panel2->Size = System::Drawing::Size(250, 30);
            this->panel2->TabIndex = 22;
            // 
            // panelLogs
            // 
            this->panelLogs->BackColor = System::Drawing::Color::White;
            this->panelLogs->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->panelLogs->Controls->Add(this->lblLogsTitle);
            this->panelLogs->Controls->Add(this->lstLogs);
            this->panelLogs->Location = System::Drawing::Point(4, 458);
            this->panelLogs->Name = L"panelLogs";
            this->panelLogs->Size = System::Drawing::Size(852, 229);
            this->panelLogs->TabIndex = 33;
            // 
            // lblLogsTitle
            // 
            this->lblLogsTitle->AutoSize = true;
            this->lblLogsTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
            this->lblLogsTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(58)),
                static_cast<System::Int32>(static_cast<System::Byte>(138)));
            this->lblLogsTitle->Location = System::Drawing::Point(16, 9);
            this->lblLogsTitle->Name = L"lblLogsTitle";
            this->lblLogsTitle->Size = System::Drawing::Size(163, 28);
            this->lblLogsTitle->TabIndex = 34;
            this->lblLogsTitle->Text = L"Логи операций";
            // 
            // lstLogs
            // 
            this->lstLogs->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(239)), static_cast<System::Int32>(static_cast<System::Byte>(246)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->lstLogs->Font = (gcnew System::Drawing::Font(L"Consolas", 9));
            this->lstLogs->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(22)), static_cast<System::Int32>(static_cast<System::Byte>(163)),
                static_cast<System::Int32>(static_cast<System::Byte>(74)));
            this->lstLogs->Location = System::Drawing::Point(15, 42);
            this->lstLogs->Name = L"lstLogs";
            this->lstLogs->ReadOnly = true;
            this->lstLogs->Size = System::Drawing::Size(820, 166);
            this->lstLogs->TabIndex = 36;
            this->lstLogs->Text = L"";
            // 
            // btnClosed
            // 
            this->btnClosed->BackColor = System::Drawing::Color::Azure;
            this->btnClosed->FlatAppearance->BorderColor = System::Drawing::Color::White;
            this->btnClosed->FlatAppearance->BorderSize = 0;
            this->btnClosed->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(239)),
                static_cast<System::Int32>(static_cast<System::Byte>(246)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->btnClosed->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnClosed->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->btnClosed->ForeColor = System::Drawing::Color::White;
            this->btnClosed->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnClosed.Image")));
            this->btnClosed->Location = System::Drawing::Point(797, 1);
            this->btnClosed->Name = L"btnClosed";
            this->btnClosed->Size = System::Drawing::Size(60, 45);
            this->btnClosed->TabIndex = 5;
            this->btnClosed->UseVisualStyleBackColor = false;
            this->btnClosed->Click += gcnew System::EventHandler(this, &PartialMainWindow::btnClosed_Click);
            // 
            // button1
            // 
            this->button1->BackColor = System::Drawing::Color::Azure;
            this->button1->FlatAppearance->BorderColor = System::Drawing::Color::White;
            this->button1->FlatAppearance->BorderSize = 0;
            this->button1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(239)),
                static_cast<System::Int32>(static_cast<System::Byte>(246)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
            this->button1->Location = System::Drawing::Point(731, 1);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(60, 45);
            this->button1->TabIndex = 46;
            this->button1->UseVisualStyleBackColor = false;
            this->button1->Click += gcnew System::EventHandler(this, &PartialMainWindow::button1_Click);
            // 
            // TextBoxPassword
            // 
            this->TextBoxPassword->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(219)), static_cast<System::Int32>(static_cast<System::Byte>(234)),
                static_cast<System::Int32>(static_cast<System::Byte>(254)));
            this->TextBoxPassword->Location = System::Drawing::Point(259, 104);
            this->TextBoxPassword->Name = L"TextBoxPassword";
            this->TextBoxPassword->PasswordChar = '*';
            this->TextBoxPassword->Size = System::Drawing::Size(342, 22);
            this->TextBoxPassword->TabIndex = 35;
            // 
            // lblPassword
            // 
            this->lblPassword->AutoSize = true;
            this->lblPassword->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->lblPassword->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(78)),
                static_cast<System::Int32>(static_cast<System::Byte>(216)));
            this->lblPassword->Location = System::Drawing::Point(391, 69);
            this->lblPassword->Name = L"lblPassword";
            this->lblPassword->Size = System::Drawing::Size(93, 27);
            this->lblPassword->TabIndex = 34;
            this->lblPassword->Text = L"Пароль:";
            // 
            // btnConnectDB2
            // 
            this->btnConnectDB2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(78)),
                static_cast<System::Int32>(static_cast<System::Byte>(216)));
            this->btnConnectDB2->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)),
                static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(175)));
            this->btnConnectDB2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnConnectDB2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
            this->btnConnectDB2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->btnConnectDB2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnConnectDB2.Image")));
            this->btnConnectDB2->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
            this->btnConnectDB2->Location = System::Drawing::Point(605, 69);
            this->btnConnectDB2->Name = L"btnConnectDB2";
            this->btnConnectDB2->Padding = System::Windows::Forms::Padding(3);
            this->btnConnectDB2->Size = System::Drawing::Size(230, 40);
            this->btnConnectDB2->TabIndex = 32;
            this->btnConnectDB2->Text = L"  Подключиться к MS SQL";
            this->btnConnectDB2->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
            this->btnConnectDB2->UseVisualStyleBackColor = false;
            this->btnConnectDB2->Click += gcnew System::EventHandler(this, &PartialMainWindow::btnConnectDB2_Click);
            // 
            // lblConnectDB2Title
            // 
            this->lblConnectDB2Title->AutoSize = true;
            this->lblConnectDB2Title->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
            this->lblConnectDB2Title->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)),
                static_cast<System::Int32>(static_cast<System::Byte>(58)), static_cast<System::Int32>(static_cast<System::Byte>(138)));
            this->lblConnectDB2Title->Location = System::Drawing::Point(77, 6);
            this->lblConnectDB2Title->Name = L"lblConnectDB2Title";
            this->lblConnectDB2Title->Size = System::Drawing::Size(203, 28);
            this->lblConnectDB2Title->TabIndex = 30;
            this->lblConnectDB2Title->Text = L"Подключение к БД";
            // 
            // pictureBox2
            // 
            this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
            this->pictureBox2->Location = System::Drawing::Point(35, 5);
            this->pictureBox2->Name = L"pictureBox2";
            this->pictureBox2->Size = System::Drawing::Size(36, 36);
            this->pictureBox2->TabIndex = 33;
            this->pictureBox2->TabStop = false;
            // 
            // btnConnectDB1
            // 
            this->btnConnectDB1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(78)),
                static_cast<System::Int32>(static_cast<System::Byte>(216)));
            this->btnConnectDB1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)),
                static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(175)));
            this->btnConnectDB1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnConnectDB1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
            this->btnConnectDB1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->btnConnectDB1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnConnectDB1.Image")));
            this->btnConnectDB1->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
            this->btnConnectDB1->Location = System::Drawing::Point(23, 69);
            this->btnConnectDB1->Name = L"btnConnectDB1";
            this->btnConnectDB1->Padding = System::Windows::Forms::Padding(3);
            this->btnConnectDB1->Size = System::Drawing::Size(230, 40);
            this->btnConnectDB1->TabIndex = 36;
            this->btnConnectDB1->Text = L"  Подключиться к Oracle";
            this->btnConnectDB1->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
            this->btnConnectDB1->UseVisualStyleBackColor = false;
            this->btnConnectDB1->Click += gcnew System::EventHandler(this, &PartialMainWindow::btnConnectDB1_Click);
            // 
            // labArea1
            // 
            this->labArea1->AutoSize = true;
            this->labArea1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->labArea1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(78)),
                static_cast<System::Int32>(static_cast<System::Byte>(216)));
            this->labArea1->Location = System::Drawing::Point(3, 5);
            this->labArea1->Name = L"labArea1";
            this->labArea1->Size = System::Drawing::Size(36, 40);
            this->labArea1->TabIndex = 37;
            this->labArea1->Text = L"1";
            // 
            // btnUpdateconfig1
            // 
            this->btnUpdateconfig1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(78)),
                static_cast<System::Int32>(static_cast<System::Byte>(216)));
            this->btnUpdateconfig1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)),
                static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(175)));
            this->btnUpdateconfig1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnUpdateconfig1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
            this->btnUpdateconfig1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->btnUpdateconfig1->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
            this->btnUpdateconfig1->Location = System::Drawing::Point(23, 115);
            this->btnUpdateconfig1->Name = L"btnUpdateconfig1";
            this->btnUpdateconfig1->Padding = System::Windows::Forms::Padding(3);
            this->btnUpdateconfig1->Size = System::Drawing::Size(230, 40);
            this->btnUpdateconfig1->TabIndex = 38;
            this->btnUpdateconfig1->Text = L"Изменить путь конф. файл Oracle";
            this->btnUpdateconfig1->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
            this->btnUpdateconfig1->UseVisualStyleBackColor = false;
            this->btnUpdateconfig1->Click += gcnew System::EventHandler(this, &PartialMainWindow::btnUpdateconfig1_Click);
            // 
            // panelConnectDB2
            // 
            this->panelConnectDB2->BackColor = System::Drawing::Color::White;
            this->panelConnectDB2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->panelConnectDB2->Controls->Add(this->btnUpdateconfig2);
            this->panelConnectDB2->Controls->Add(this->btnUpdateconfig1);
            this->panelConnectDB2->Controls->Add(this->labArea1);
            this->panelConnectDB2->Controls->Add(this->btnConnectDB1);
            this->panelConnectDB2->Controls->Add(this->pictureBox2);
            this->panelConnectDB2->Controls->Add(this->lblConnectDB2Title);
            this->panelConnectDB2->Controls->Add(this->btnConnectDB2);
            this->panelConnectDB2->Controls->Add(this->lblPassword);
            this->panelConnectDB2->Controls->Add(this->TextBoxPassword);
            this->panelConnectDB2->Location = System::Drawing::Point(5, 138);
            this->panelConnectDB2->Name = L"panelConnectDB2";
            this->panelConnectDB2->Size = System::Drawing::Size(853, 190);
            this->panelConnectDB2->TabIndex = 29;
            // 
            // btnUpdateconfig2
            // 
            this->btnUpdateconfig2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(78)),
                static_cast<System::Int32>(static_cast<System::Byte>(216)));
            this->btnUpdateconfig2->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)),
                static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(175)));
            this->btnUpdateconfig2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnUpdateconfig2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
            this->btnUpdateconfig2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->btnUpdateconfig2->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
            this->btnUpdateconfig2->Location = System::Drawing::Point(605, 115);
            this->btnUpdateconfig2->Name = L"btnUpdateconfig2";
            this->btnUpdateconfig2->Padding = System::Windows::Forms::Padding(3);
            this->btnUpdateconfig2->Size = System::Drawing::Size(230, 40);
            this->btnUpdateconfig2->TabIndex = 39;
            this->btnUpdateconfig2->Text = L"Изменить путь конф. файл MS SQL";
            this->btnUpdateconfig2->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
            this->btnUpdateconfig2->UseVisualStyleBackColor = false;
            this->btnUpdateconfig2->Click += gcnew System::EventHandler(this, &PartialMainWindow::btnUpdateconfig2_Click);
            // 
            // pictureBox4
            // 
            this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
            this->pictureBox4->Location = System::Drawing::Point(6, 1);
            this->pictureBox4->Name = L"pictureBox4";
            this->pictureBox4->Size = System::Drawing::Size(90, 45);
            this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox4->TabIndex = 47;
            this->pictureBox4->TabStop = false;
            // 
            // PartialMainWindow
            // 
            this->AutoScroll = true;
            this->BackColor = System::Drawing::Color::Azure;
            this->ClientSize = System::Drawing::Size(828, 705);
            this->Controls->Add(this->pictureBox4);
            this->Controls->Add(this->headerPanel);
            this->Controls->Add(this->btnClosed);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->panelLogs);
            this->Controls->Add(this->panelID2);
            this->Controls->Add(this->panelConnectDB2);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            this->MaximizeBox = false;
            this->Name = L"PartialMainWindow";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Load += gcnew System::EventHandler(this, &PartialMainWindow::PartialMainWindow_Load);
            this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &PartialMainWindow::PartialMainWindow_MouseDown);
            this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &PartialMainWindow::PartialMainWindow_MouseMove);
            this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &PartialMainWindow::PartialMainWindow_MouseUp);
            this->headerPanel->ResumeLayout(false);
            this->headerPanel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            this->panelID2->ResumeLayout(false);
            this->panelID2->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
            this->panelLogs->ResumeLayout(false);
            this->panelLogs->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
            this->panelConnectDB2->ResumeLayout(false);
            this->panelConnectDB2->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
            this->ResumeLayout(false);

        }
#pragma endregion
      
        private:System::Void btnDisconnect_Click(System::Object^, System::EventArgs^);
        private:System::Void btnConnectDB2_Click(System::Object^, System::EventArgs^);
        private:System::Void btnGetID_Click(System::Object^, System::EventArgs^);
        private:System::Void PartialMainWindow_FormClosing(System::Object^, System::Windows::Forms::FormClosingEventArgs^);
        private:System::Void btnClosed_Click(System::Object^, System::EventArgs^);
        private:System::Void PartialMainWindow_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
        private:System::Void PartialMainWindow_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
        private:System::Void PartialMainWindow_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
        private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
            this->WindowState = FormWindowState::Minimized;
        }
        private: System::Void btnConnectDB1_Click(System::Object^ sender, System::EventArgs^ e);
        private: System::Void btnUpdateconfig1_Click(System::Object^ sender, System::EventArgs^ e);
        private: System::Void btnUpdateconfig2_Click(System::Object^ sender, System::EventArgs^ e);
        private: System::Void PartialMainWindow_Load(System::Object^ sender, System::EventArgs^ e);

        

        
};
}