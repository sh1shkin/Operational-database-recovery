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
        bool isDragging; // Флаг, указывающий, выполняется ли перетаскивание
        Point^ dragStartPoint; // Начальная точка перетаскивания
        ConnectionWindow^ connectForm;
        OdbcConnection^ db_connect1; // Подключение к DB1
        OdbcConnection^ db_connect2; // Подключение к DB2
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

    private: System::Windows::Forms::Button^ btnClosed;
           String^ nameUser;
    public:
        PartialMainWindow(void)
        {
            InitializeComponent();
        }

        PartialMainWindow(OdbcConnection^ connection, String^ typeStr, String^ dbName, String^ userName, ConnectionWindow^ connectForm, array<String^>^ confBD1)
            : db_connect1(connection), nameDBMS(typeStr), nameDB(dbName), nameUser(userName), db_connect2(nullptr), connectForm(connectForm), confDB1(confBD1)
        {
            queryParams = gcnew array<array<String^>^>(2) {
                gcnew array<String^> { "id2in", "THICKNESS", "WIDTH", "SIS_COIL_STATUS" },
                    gcnew array<String^> { "id2out", "THICKNESS", "WIDTH", "SOS_COIL_STATUS" }
            };
            queryParams1 = gcnew array<array<String^>^>(2) {
                gcnew array<String^> { "sic_id2", "SIC_THICKNESS", "SIC_WIDTH", "SIC_SIS_COIL_STATUS" },
                    gcnew array<String^> { "soc_id2", "SOC_THICKNESS", "SOC_WIDTH", "SOC_SOS_COIL_STATUS" }
            };
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
    private: System::Windows::Forms::Button^ btnDisconnect;
    private: System::Windows::Forms::Panel^ panelID2;
    private: System::Windows::Forms::Label^ lblID2Title;
    private: System::Windows::Forms::Label^ lblID2In;
    private: System::Windows::Forms::TextBox^ txtID2In;
    private: System::Windows::Forms::Label^ lblID2Out;
    private: System::Windows::Forms::TextBox^ txtID2Out;
    private: System::Windows::Forms::Button^ btnGetID;
    private: System::Windows::Forms::Panel^ panelConnectDB2;
    private: System::Windows::Forms::Label^ lblConnectDB2Title;
    private: System::Windows::Forms::Label^ lblConnectDB2Desc;
    private: System::Windows::Forms::Button^ btnConnectDB2;
    private: System::Windows::Forms::Panel^ panelLogs;
    private: System::Windows::Forms::Label^ lblLogsTitle;
    private: System::Windows::Forms::ListBox^ lstLogs;
    private: System::Windows::Forms::Panel^ footerPanel;
    private: System::Windows::Forms::Label^ lblDB1Status;

    private: System::Windows::Forms::PictureBox^ pictureBox1;
    private: System::Windows::Forms::PictureBox^ pictureBox2;
    private: System::Windows::Forms::PictureBox^ pictureBox3;
    private: System::Windows::Forms::Panel^ panel1;
    private: System::Windows::Forms::Panel^ panel2;
    private: System::Windows::Forms::Label^ lblStatusTxt;
    private: System::Windows::Forms::TextBox^ TextBoxPassword; // Поле для ввода пароля
    private: System::Windows::Forms::Label^ lblPassword; // Метка для поля пароля

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
            this->btnDisconnect = (gcnew System::Windows::Forms::Button());
            this->panelID2 = (gcnew System::Windows::Forms::Panel());
            this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
            this->lblID2Title = (gcnew System::Windows::Forms::Label());
            this->lblID2In = (gcnew System::Windows::Forms::Label());
            this->txtID2In = (gcnew System::Windows::Forms::TextBox());
            this->lblID2Out = (gcnew System::Windows::Forms::Label());
            this->txtID2Out = (gcnew System::Windows::Forms::TextBox());
            this->btnGetID = (gcnew System::Windows::Forms::Button());
            this->panel1 = (gcnew System::Windows::Forms::Panel());
            this->panel2 = (gcnew System::Windows::Forms::Panel());
            this->panelConnectDB2 = (gcnew System::Windows::Forms::Panel());
            this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
            this->lblConnectDB2Title = (gcnew System::Windows::Forms::Label());
            this->lblConnectDB2Desc = (gcnew System::Windows::Forms::Label());
            this->btnConnectDB2 = (gcnew System::Windows::Forms::Button());
            this->lblPassword = (gcnew System::Windows::Forms::Label());
            this->TextBoxPassword = (gcnew System::Windows::Forms::TextBox());
            this->panelLogs = (gcnew System::Windows::Forms::Panel());
            this->lblLogsTitle = (gcnew System::Windows::Forms::Label());
            this->lstLogs = (gcnew System::Windows::Forms::ListBox());
            this->footerPanel = (gcnew System::Windows::Forms::Panel());
            this->lblStatusTxt = (gcnew System::Windows::Forms::Label());
            this->lblDB1Status = (gcnew System::Windows::Forms::Label());
            this->btnClosed = (gcnew System::Windows::Forms::Button());
            this->headerPanel->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            this->panelID2->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
            this->panelConnectDB2->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
            this->panelLogs->SuspendLayout();
            this->footerPanel->SuspendLayout();
            this->SuspendLayout();
            // 
            // headerPanel
            // 
            this->headerPanel->BackColor = System::Drawing::Color::White;
            this->headerPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->headerPanel->Controls->Add(this->pictureBox1);
            this->headerPanel->Controls->Add(this->lblTitle);
            this->headerPanel->Controls->Add(this->lblConnectionInfo);
            this->headerPanel->Controls->Add(this->btnDisconnect);
            this->headerPanel->Location = System::Drawing::Point(24, 54);
            this->headerPanel->Name = L"headerPanel";
            this->headerPanel->Size = System::Drawing::Size(860, 80);
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
            this->lblConnectionInfo->Size = System::Drawing::Size(296, 23);
            this->lblConnectionInfo->TabIndex = 2;
            this->lblConnectionInfo->Text = L"БД1: MSSQL: AEIP6L2S\\LEVEL2/NLMK";
            // 
            // btnDisconnect
            // 
            this->btnDisconnect->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->btnDisconnect->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(59)),
                static_cast<System::Int32>(static_cast<System::Byte>(130)), static_cast<System::Int32>(static_cast<System::Byte>(246)));
            this->btnDisconnect->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(239)),
                static_cast<System::Int32>(static_cast<System::Byte>(246)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->btnDisconnect->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnDisconnect->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->btnDisconnect->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(78)),
                static_cast<System::Int32>(static_cast<System::Byte>(216)));
            this->btnDisconnect->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnDisconnect.Image")));
            this->btnDisconnect->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
            this->btnDisconnect->Location = System::Drawing::Point(687, 20);
            this->btnDisconnect->Name = L"btnDisconnect";
            this->btnDisconnect->Size = System::Drawing::Size(150, 40);
            this->btnDisconnect->TabIndex = 3;
            this->btnDisconnect->Text = L"  Отключиться";
            this->btnDisconnect->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
            this->btnDisconnect->UseVisualStyleBackColor = false;
            this->btnDisconnect->Click += gcnew System::EventHandler(this, &PartialMainWindow::btnDisconnect_Click);
            // 
            // panelID2
            // 
            this->panelID2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->panelID2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->panelID2->Controls->Add(this->pictureBox3);
            this->panelID2->Controls->Add(this->lblID2Title);
            this->panelID2->Controls->Add(this->lblID2In);
            this->panelID2->Controls->Add(this->txtID2In);
            this->panelID2->Controls->Add(this->lblID2Out);
            this->panelID2->Controls->Add(this->txtID2Out);
            this->panelID2->Controls->Add(this->btnGetID);
            this->panelID2->Controls->Add(this->panel1);
            this->panelID2->Controls->Add(this->panel2);
            this->panelID2->Location = System::Drawing::Point(23, 140);
            this->panelID2->Name = L"panelID2";
            this->panelID2->Size = System::Drawing::Size(860, 118);
            this->panelID2->TabIndex = 4;
            // 
            // pictureBox3
            // 
            this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
            this->pictureBox3->Location = System::Drawing::Point(20, 11);
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
            this->lblID2Title->Location = System::Drawing::Point(53, 15);
            this->lblID2Title->Name = L"lblID2Title";
            this->lblID2Title->Size = System::Drawing::Size(202, 32);
            this->lblID2Title->TabIndex = 5;
            this->lblID2Title->Text = L"Управление ID2";
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
            this->btnGetID->Text = L"  Получить ID из БД1";
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
            // panelConnectDB2
            // 
            this->panelConnectDB2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(239)), static_cast<System::Int32>(static_cast<System::Byte>(246)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->panelConnectDB2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->panelConnectDB2->Controls->Add(this->pictureBox2);
            this->panelConnectDB2->Controls->Add(this->lblConnectDB2Title);
            this->panelConnectDB2->Controls->Add(this->lblConnectDB2Desc);
            this->panelConnectDB2->Controls->Add(this->btnConnectDB2);
            this->panelConnectDB2->Controls->Add(this->lblPassword);
            this->panelConnectDB2->Controls->Add(this->TextBoxPassword);
            this->panelConnectDB2->Location = System::Drawing::Point(24, 264);
            this->panelConnectDB2->Name = L"panelConnectDB2";
            this->panelConnectDB2->Size = System::Drawing::Size(860, 190);
            this->panelConnectDB2->TabIndex = 29;
            // 
            // pictureBox2
            // 
            this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
            this->pictureBox2->Location = System::Drawing::Point(410, 5);
            this->pictureBox2->Name = L"pictureBox2";
            this->pictureBox2->Size = System::Drawing::Size(36, 36);
            this->pictureBox2->TabIndex = 33;
            this->pictureBox2->TabStop = false;
            // 
            // lblConnectDB2Title
            // 
            this->lblConnectDB2Title->AutoSize = true;
            this->lblConnectDB2Title->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
            this->lblConnectDB2Title->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)),
                static_cast<System::Int32>(static_cast<System::Byte>(58)), static_cast<System::Int32>(static_cast<System::Byte>(138)));
            this->lblConnectDB2Title->Location = System::Drawing::Point(340, 45);
            this->lblConnectDB2Title->Name = L"lblConnectDB2Title";
            this->lblConnectDB2Title->Size = System::Drawing::Size(215, 28);
            this->lblConnectDB2Title->TabIndex = 30;
            this->lblConnectDB2Title->Text = L"Подключение к БД2";
            // 
            // lblConnectDB2Desc
            // 
            this->lblConnectDB2Desc->AutoSize = true;
            this->lblConnectDB2Desc->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->lblConnectDB2Desc->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)),
                static_cast<System::Int32>(static_cast<System::Byte>(78)), static_cast<System::Int32>(static_cast<System::Byte>(216)));
            this->lblConnectDB2Desc->Location = System::Drawing::Point(155, 73);
            this->lblConnectDB2Desc->Name = L"lblConnectDB2Desc";
            this->lblConnectDB2Desc->Size = System::Drawing::Size(724, 20);
            this->lblConnectDB2Desc->TabIndex = 31;
            this->lblConnectDB2Desc->Text = L"Для добавления записей и выполнения операций необходимо подключиться ко второй ба"
                L"зе данных";
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
            this->btnConnectDB2->Location = System::Drawing::Point(326, 145);
            this->btnConnectDB2->Name = L"btnConnectDB2";
            this->btnConnectDB2->Padding = System::Windows::Forms::Padding(3);
            this->btnConnectDB2->Size = System::Drawing::Size(200, 40);
            this->btnConnectDB2->TabIndex = 32;
            this->btnConnectDB2->Text = L"  Подключиться к БД2";
            this->btnConnectDB2->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
            this->btnConnectDB2->UseVisualStyleBackColor = false;
            this->btnConnectDB2->Click += gcnew System::EventHandler(this, &PartialMainWindow::btnConnectDB2_Click);
            // 
            // lblPassword
            // 
            this->lblPassword->AutoSize = true;
            this->lblPassword->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->lblPassword->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(78)),
                static_cast<System::Int32>(static_cast<System::Byte>(216)));
            this->lblPassword->Location = System::Drawing::Point(181, 99);
            this->lblPassword->Name = L"lblPassword";
            this->lblPassword->Size = System::Drawing::Size(93, 27);
            this->lblPassword->TabIndex = 34;
            this->lblPassword->Text = L"Пароль:";
            // 
            // TextBoxPassword
            // 
            this->TextBoxPassword->Location = System::Drawing::Point(260, 102);
            this->TextBoxPassword->Name = L"TextBoxPassword";
            this->TextBoxPassword->PasswordChar = '*';
            this->TextBoxPassword->Size = System::Drawing::Size(365, 22);
            this->TextBoxPassword->TabIndex = 35;
            // 
            // panelLogs
            // 
            this->panelLogs->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->panelLogs->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->panelLogs->Controls->Add(this->lblLogsTitle);
            this->panelLogs->Controls->Add(this->lstLogs);
            this->panelLogs->Location = System::Drawing::Point(23, 460);
            this->panelLogs->Name = L"panelLogs";
            this->panelLogs->Size = System::Drawing::Size(860, 229);
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
            this->lstLogs->HorizontalExtent = 1000;
            this->lstLogs->HorizontalScrollbar = true;
            this->lstLogs->ItemHeight = 18;
            this->lstLogs->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L"11.07.2025 16:19: Подключение к БД1 (MSSQL) успешно установлено" });
            this->lstLogs->Location = System::Drawing::Point(15, 42);
            this->lstLogs->Name = L"lstLogs";
            this->lstLogs->Size = System::Drawing::Size(820, 148);
            this->lstLogs->TabIndex = 36;
            // 
            // footerPanel
            // 
            this->footerPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->footerPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->footerPanel->Controls->Add(this->lblStatusTxt);
            this->footerPanel->Controls->Add(this->lblDB1Status);
            this->footerPanel->Location = System::Drawing::Point(24, 695);
            this->footerPanel->Name = L"footerPanel";
            this->footerPanel->Size = System::Drawing::Size(860, 40);
            this->footerPanel->TabIndex = 37;
            // 
            // lblStatusTxt
            // 
            this->lblStatusTxt->AutoSize = true;
            this->lblStatusTxt->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->lblStatusTxt->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
                static_cast<System::Int32>(static_cast<System::Byte>(175)));
            this->lblStatusTxt->Location = System::Drawing::Point(20, 10);
            this->lblStatusTxt->Name = L"lblStatusTxt";
            this->lblStatusTxt->Size = System::Drawing::Size(55, 20);
            this->lblStatusTxt->TabIndex = 40;
            this->lblStatusTxt->Text = L"Статус:";
            // 
            // lblDB1Status
            // 
            this->lblDB1Status->AutoSize = true;
            this->lblDB1Status->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8));
            this->lblDB1Status->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(22)), static_cast<System::Int32>(static_cast<System::Byte>(163)),
                static_cast<System::Int32>(static_cast<System::Byte>(74)));
            this->lblDB1Status->Location = System::Drawing::Point(66, 10);
            this->lblDB1Status->Name = L"lblDB1Status";
            this->lblDB1Status->Size = System::Drawing::Size(124, 19);
            this->lblDB1Status->TabIndex = 38;
            this->lblDB1Status->Text = L"БД1: Подключено";
            // 
            // btnClosed
            // 
            this->btnClosed->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->btnClosed->FlatAppearance->BorderColor = System::Drawing::Color::White;
            this->btnClosed->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(239)),
                static_cast<System::Int32>(static_cast<System::Byte>(246)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->btnClosed->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnClosed->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->btnClosed->ForeColor = System::Drawing::Color::White;
            this->btnClosed->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnClosed.Image")));
            this->btnClosed->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
            this->btnClosed->Location = System::Drawing::Point(839, 8);
            this->btnClosed->Name = L"btnClosed";
            this->btnClosed->Size = System::Drawing::Size(41, 40);
            this->btnClosed->TabIndex = 5;
            this->btnClosed->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
            this->btnClosed->UseVisualStyleBackColor = false;
            this->btnClosed->Click += gcnew System::EventHandler(this, &PartialMainWindow::btnClosed_Click);
            // 
            // PartialMainWindow
            // 
            this->AutoScroll = true;
            this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->ClientSize = System::Drawing::Size(870, 750);
            this->Controls->Add(this->btnClosed);
            this->Controls->Add(this->headerPanel);
            this->Controls->Add(this->panelID2);
            this->Controls->Add(this->panelConnectDB2);
            this->Controls->Add(this->panelLogs);
            this->Controls->Add(this->footerPanel);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            this->MaximizeBox = false;
            this->Name = L"PartialMainWindow";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &PartialMainWindow::PartialMainWindow_MouseDown);
            this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &PartialMainWindow::PartialMainWindow_MouseMove);
            this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &PartialMainWindow::PartialMainWindow_MouseUp);
            this->headerPanel->ResumeLayout(false);
            this->headerPanel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            this->panelID2->ResumeLayout(false);
            this->panelID2->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
            this->panelConnectDB2->ResumeLayout(false);
            this->panelConnectDB2->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
            this->panelLogs->ResumeLayout(false);
            this->panelLogs->PerformLayout();
            this->footerPanel->ResumeLayout(false);
            this->footerPanel->PerformLayout();
            this->ResumeLayout(false);

        }
#pragma endregion
      
        private:System::Void btnDisconnect_Click(System::Object^, System::EventArgs^);
        private:System::Void btnConnectDB2_Click(System::Object^, System::EventArgs^);
        private:System::Void btnGetID_Click(System::Object^, System::EventArgs^);
        private:System::Void PartialMainWindow_FormClosing(System::Object^, System::Windows::Forms::FormClosingEventArgs^);
        private:System::Void btnClosed_Click(System::Object^, System::EventArgs^);
        private:
            System::Void PartialMainWindow_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
            System::Void PartialMainWindow_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
            System::Void PartialMainWindow_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);


};
}