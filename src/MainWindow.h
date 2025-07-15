#pragma once
#include "PartialMainWindow.h"
#include "ConnectionWindow.h"
namespace src {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Data::Odbc;

    /// <summary>
    /// Сводка для MainWindow
    /// </summary>
    public ref class MainWindow : public System::Windows::Forms::Form
    {
    private: 
        bool isDragging;
        Point^ dragStartPoint;
        PartialMainWindow^ connectForm1;
        ConnectionWindow^ connectForm2;
        OdbcConnection^ db_connect1; // Подключение к DB1
        OdbcConnection^ db_connect2; // Подключение к DB2
        String^ nameDBMS1;
        String^ nameDB1;
        String^ nameUser1;
        String^ nameDBMS2;
        String^ nameDB2;
    private: System::Windows::Forms::Button^ btnClosedMW;

           String^ nameUser2;

    public:
        MainWindow(OdbcConnection^ connection1, OdbcConnection^ connection2, String^ dbms1, String^ dbName1, String^ userName1,
            String^ dbms2, String^ dbName2, String^ userName2, PartialMainWindow^ connectForm1, ConnectionWindow^ connectForm2)
            : db_connect1(connection1), db_connect2(connection2), nameDBMS1(dbms1), nameDB1(dbName1), nameUser1(userName1),
            nameDBMS2(dbms2), nameDB2(dbName2), nameUser2(userName2), connectForm1(connectForm1), connectForm2(connectForm2)
        {
            InitializeComponent();
            lblConnectionInfoDB1->Text = String::Format("БД1: {0}: {1}/{2}", dbms1, dbName1, userName1);
            lblConnectionInfoDB2->Text = String::Format("БД2: {0}: {1}/{2}", dbms2, dbName2, userName2);
            isDragging = false;
            dragStartPoint = gcnew Point(0, 0);
        }
        String^ tableInput;
        String^ tableOutput;
        String^ columnInputId;
        String^ columnOutputId;
    protected:
        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        ~MainWindow()
        {
            if (components) delete components;
            if (db_connect1 != nullptr && db_connect1->State == ConnectionState::Open) db_connect1->Close();
            if (db_connect2 != nullptr && db_connect2->State == ConnectionState::Open) db_connect2->Close();
        }

    private: System::Windows::Forms::Panel^ headerPanel;
    private: System::Windows::Forms::PictureBox^ picDatabaseIcon;
    private: System::Windows::Forms::Label^ lblTitle;
    private: System::Windows::Forms::Label^ lblConnectionInfoDB1;
    private: System::Windows::Forms::Label^ lblConnectionInfoDB2;
    private: System::Windows::Forms::Button^ btnDisconnect;
    private: System::Windows::Forms::Panel^ panelID2;
    private: System::Windows::Forms::PictureBox^ picSettingsIcon;
    private: System::Windows::Forms::Label^ lblID2Title;
    private: System::Windows::Forms::Label^ lblID2In;
    private: System::Windows::Forms::TextBox^ txtID2In;
    private: System::Windows::Forms::Label^ lblID2Out;
    private: System::Windows::Forms::TextBox^ txtID2Out;
    private: System::Windows::Forms::Button^ btnConfirmID;
    private: System::Windows::Forms::Panel^ separator;
    private: System::Windows::Forms::Panel^ panelInputParams;
    private: System::Windows::Forms::Label^ lblInputBadge;
    private: System::Windows::Forms::Label^ lblInputParams;
    private: System::Windows::Forms::Label^ lblThicknessIn;
    private: System::Windows::Forms::TextBox^ txtThicknessIn;
    private: System::Windows::Forms::Label^ lblWidthIn;
    private: System::Windows::Forms::TextBox^ txtWidthIn;
    private: System::Windows::Forms::Label^ lblStatusIn;
    private: System::Windows::Forms::TextBox^ txtStatusIn;
    private: System::Windows::Forms::Panel^ panelOutputParams;
    private: System::Windows::Forms::Label^ lblOutputBadge;
    private: System::Windows::Forms::Label^ lblOutputParams;
    private: System::Windows::Forms::Label^ lblThicknessOut;
    private: System::Windows::Forms::TextBox^ txtThicknessOut;
    private: System::Windows::Forms::Label^ lblWidthOut;
    private: System::Windows::Forms::TextBox^ txtWidthOut;
    private: System::Windows::Forms::Label^ lblStatusOut;
    private: System::Windows::Forms::TextBox^ txtStatusOut;
    private: System::Windows::Forms::Button^ btnAddRecords;
    private: System::Windows::Forms::Panel^ panelResults;
    private: System::Windows::Forms::PictureBox^ picSearchIcon;
    private: System::Windows::Forms::Label^ lblResultsTitle;
    private: System::Windows::Forms::Button^ btnCheckRecords;
    private: System::Windows::Forms::DataGridView^ dgvResults;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ colID;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ colType;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ colThickness;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ colWidth;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ colStatus;
    private: System::Windows::Forms::Panel^ panelLogs;
    private: System::Windows::Forms::Label^ lblLogsTitle;
    private: System::Windows::Forms::ListBox^ lstLogs;
    private: System::Windows::Forms::Panel^ footerPanel;

    private: System::Windows::Forms::Label^ lblDB1Status;

    private: System::Windows::Forms::Label^ lblDB2Status;
    private: System::Windows::Forms::Label^ lblStatusTxt;
    private: System::Windows::Forms::Panel^ panel1;
    private: System::Windows::Forms::Panel^ panel2;

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
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainWindow::typeid));
            this->headerPanel = (gcnew System::Windows::Forms::Panel());
            this->picDatabaseIcon = (gcnew System::Windows::Forms::PictureBox());
            this->lblTitle = (gcnew System::Windows::Forms::Label());
            this->lblConnectionInfoDB1 = (gcnew System::Windows::Forms::Label());
            this->lblConnectionInfoDB2 = (gcnew System::Windows::Forms::Label());
            this->btnDisconnect = (gcnew System::Windows::Forms::Button());
            this->panelID2 = (gcnew System::Windows::Forms::Panel());
            this->btnAddRecords = (gcnew System::Windows::Forms::Button());
            this->picSettingsIcon = (gcnew System::Windows::Forms::PictureBox());
            this->lblID2Title = (gcnew System::Windows::Forms::Label());
            this->lblID2In = (gcnew System::Windows::Forms::Label());
            this->txtID2In = (gcnew System::Windows::Forms::TextBox());
            this->lblID2Out = (gcnew System::Windows::Forms::Label());
            this->txtID2Out = (gcnew System::Windows::Forms::TextBox());
            this->btnConfirmID = (gcnew System::Windows::Forms::Button());
            this->separator = (gcnew System::Windows::Forms::Panel());
            this->panelInputParams = (gcnew System::Windows::Forms::Panel());
            this->lblInputBadge = (gcnew System::Windows::Forms::Label());
            this->lblInputParams = (gcnew System::Windows::Forms::Label());
            this->lblThicknessIn = (gcnew System::Windows::Forms::Label());
            this->txtThicknessIn = (gcnew System::Windows::Forms::TextBox());
            this->lblWidthIn = (gcnew System::Windows::Forms::Label());
            this->txtWidthIn = (gcnew System::Windows::Forms::TextBox());
            this->lblStatusIn = (gcnew System::Windows::Forms::Label());
            this->txtStatusIn = (gcnew System::Windows::Forms::TextBox());
            this->panelOutputParams = (gcnew System::Windows::Forms::Panel());
            this->lblOutputBadge = (gcnew System::Windows::Forms::Label());
            this->lblOutputParams = (gcnew System::Windows::Forms::Label());
            this->lblThicknessOut = (gcnew System::Windows::Forms::Label());
            this->txtThicknessOut = (gcnew System::Windows::Forms::TextBox());
            this->lblWidthOut = (gcnew System::Windows::Forms::Label());
            this->txtWidthOut = (gcnew System::Windows::Forms::TextBox());
            this->lblStatusOut = (gcnew System::Windows::Forms::Label());
            this->txtStatusOut = (gcnew System::Windows::Forms::TextBox());
            this->panel1 = (gcnew System::Windows::Forms::Panel());
            this->panel2 = (gcnew System::Windows::Forms::Panel());
            this->panelResults = (gcnew System::Windows::Forms::Panel());
            this->picSearchIcon = (gcnew System::Windows::Forms::PictureBox());
            this->lblResultsTitle = (gcnew System::Windows::Forms::Label());
            this->btnCheckRecords = (gcnew System::Windows::Forms::Button());
            this->dgvResults = (gcnew System::Windows::Forms::DataGridView());
            this->colID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->colType = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->colThickness = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->colWidth = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->colStatus = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->panelLogs = (gcnew System::Windows::Forms::Panel());
            this->lblLogsTitle = (gcnew System::Windows::Forms::Label());
            this->lstLogs = (gcnew System::Windows::Forms::ListBox());
            this->footerPanel = (gcnew System::Windows::Forms::Panel());
            this->lblStatusTxt = (gcnew System::Windows::Forms::Label());
            this->lblDB1Status = (gcnew System::Windows::Forms::Label());
            this->lblDB2Status = (gcnew System::Windows::Forms::Label());
            this->btnClosedMW = (gcnew System::Windows::Forms::Button());
            this->headerPanel->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picDatabaseIcon))->BeginInit();
            this->panelID2->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picSettingsIcon))->BeginInit();
            this->panelInputParams->SuspendLayout();
            this->panelOutputParams->SuspendLayout();
            this->panelResults->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picSearchIcon))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvResults))->BeginInit();
            this->panelLogs->SuspendLayout();
            this->footerPanel->SuspendLayout();
            this->SuspendLayout();
            // 
            // headerPanel
            // 
            this->headerPanel->BackColor = System::Drawing::Color::White;
            this->headerPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->headerPanel->Controls->Add(this->picDatabaseIcon);
            this->headerPanel->Controls->Add(this->lblTitle);
            this->headerPanel->Controls->Add(this->lblConnectionInfoDB1);
            this->headerPanel->Controls->Add(this->lblConnectionInfoDB2);
            this->headerPanel->Controls->Add(this->btnDisconnect);
            this->headerPanel->Location = System::Drawing::Point(8, 60);
            this->headerPanel->Name = L"headerPanel";
            this->headerPanel->Size = System::Drawing::Size(860, 100);
            this->headerPanel->TabIndex = 0;
            // 
            // picDatabaseIcon
            // 
            this->picDatabaseIcon->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picDatabaseIcon.Image")));
            this->picDatabaseIcon->Location = System::Drawing::Point(20, 30);
            this->picDatabaseIcon->Name = L"picDatabaseIcon";
            this->picDatabaseIcon->Size = System::Drawing::Size(32, 32);
            this->picDatabaseIcon->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->picDatabaseIcon->TabIndex = 1;
            this->picDatabaseIcon->TabStop = false;
            // 
            // lblTitle
            // 
            this->lblTitle->AutoSize = true;
            this->lblTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold));
            this->lblTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(58)),
                static_cast<System::Int32>(static_cast<System::Byte>(138)));
            this->lblTitle->Location = System::Drawing::Point(60, 20);
            this->lblTitle->Name = L"lblTitle";
            this->lblTitle->Size = System::Drawing::Size(282, 25);
            this->lblTitle->TabIndex = 2;
            this->lblTitle->Text = L"Управление ID2 для рулонов";
            // 
            // lblConnectionInfoDB1
            // 
            this->lblConnectionInfoDB1->AutoSize = true;
            this->lblConnectionInfoDB1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8));
            this->lblConnectionInfoDB1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)),
                static_cast<System::Int32>(static_cast<System::Byte>(78)), static_cast<System::Int32>(static_cast<System::Byte>(216)));
            this->lblConnectionInfoDB1->Location = System::Drawing::Point(60, 50);
            this->lblConnectionInfoDB1->Name = L"lblConnectionInfoDB1";
            this->lblConnectionInfoDB1->Size = System::Drawing::Size(191, 13);
            this->lblConnectionInfoDB1->TabIndex = 3;
            this->lblConnectionInfoDB1->Text = L"БД1: MSSQL: AEIP6L2S\\LEVEL2/NLMK";
            // 
            // lblConnectionInfoDB2
            // 
            this->lblConnectionInfoDB2->AutoSize = true;
            this->lblConnectionInfoDB2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8));
            this->lblConnectionInfoDB2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)),
                static_cast<System::Int32>(static_cast<System::Byte>(78)), static_cast<System::Int32>(static_cast<System::Byte>(216)));
            this->lblConnectionInfoDB2->Location = System::Drawing::Point(60, 70);
            this->lblConnectionInfoDB2->Name = L"lblConnectionInfoDB2";
            this->lblConnectionInfoDB2->Size = System::Drawing::Size(149, 13);
            this->lblConnectionInfoDB2->TabIndex = 4;
            this->lblConnectionInfoDB2->Text = L"БД2: ORACLE: SERVER2/DB2";
            // 
            // btnDisconnect
            // 
            this->btnDisconnect->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(78)),
                static_cast<System::Int32>(static_cast<System::Byte>(216)));
            this->btnDisconnect->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)),
                static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(175)));
            this->btnDisconnect->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnDisconnect->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->btnDisconnect->ForeColor = System::Drawing::Color::White;
            this->btnDisconnect->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnDisconnect.Image")));
            this->btnDisconnect->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
            this->btnDisconnect->Location = System::Drawing::Point(690, 30);
            this->btnDisconnect->Name = L"btnDisconnect";
            this->btnDisconnect->Size = System::Drawing::Size(150, 30);
            this->btnDisconnect->TabIndex = 5;
            this->btnDisconnect->Text = L"Отключиться";
            this->btnDisconnect->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
            this->btnDisconnect->UseVisualStyleBackColor = false;
            this->btnDisconnect->Click += gcnew System::EventHandler(this, &MainWindow::btnDisconnect_Click);
            // 
            // panelID2
            // 
            this->panelID2->BackColor = System::Drawing::Color::White;
            this->panelID2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->panelID2->Controls->Add(this->btnAddRecords);
            this->panelID2->Controls->Add(this->picSettingsIcon);
            this->panelID2->Controls->Add(this->lblID2Title);
            this->panelID2->Controls->Add(this->lblID2In);
            this->panelID2->Controls->Add(this->txtID2In);
            this->panelID2->Controls->Add(this->lblID2Out);
            this->panelID2->Controls->Add(this->txtID2Out);
            this->panelID2->Controls->Add(this->btnConfirmID);
            this->panelID2->Controls->Add(this->separator);
            this->panelID2->Controls->Add(this->panelInputParams);
            this->panelID2->Controls->Add(this->panelOutputParams);
            this->panelID2->Controls->Add(this->panel1);
            this->panelID2->Controls->Add(this->panel2);
            this->panelID2->Location = System::Drawing::Point(8, 166);
            this->panelID2->Name = L"panelID2";
            this->panelID2->Size = System::Drawing::Size(860, 280);
            this->panelID2->TabIndex = 6;
            // 
            // btnAddRecords
            // 
            this->btnAddRecords->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(78)),
                static_cast<System::Int32>(static_cast<System::Byte>(216)));
            this->btnAddRecords->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)),
                static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(175)));
            this->btnAddRecords->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnAddRecords->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->btnAddRecords->ForeColor = System::Drawing::Color::White;
            this->btnAddRecords->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAddRecords.Image")));
            this->btnAddRecords->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
            this->btnAddRecords->Location = System::Drawing::Point(305, 235);
            this->btnAddRecords->Name = L"btnAddRecords";
            this->btnAddRecords->Size = System::Drawing::Size(250, 30);
            this->btnAddRecords->TabIndex = 33;
            this->btnAddRecords->Text = L"Добавить записи";
            this->btnAddRecords->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
            this->btnAddRecords->UseVisualStyleBackColor = false;
            // 
            // picSettingsIcon
            // 
            this->picSettingsIcon->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picSettingsIcon.Image")));
            this->picSettingsIcon->Location = System::Drawing::Point(20, 20);
            this->picSettingsIcon->Name = L"picSettingsIcon";
            this->picSettingsIcon->Size = System::Drawing::Size(20, 20);
            this->picSettingsIcon->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->picSettingsIcon->TabIndex = 7;
            this->picSettingsIcon->TabStop = false;
            // 
            // lblID2Title
            // 
            this->lblID2Title->AutoSize = true;
            this->lblID2Title->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
            this->lblID2Title->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(58)),
                static_cast<System::Int32>(static_cast<System::Byte>(138)));
            this->lblID2Title->Location = System::Drawing::Point(50, 20);
            this->lblID2Title->Name = L"lblID2Title";
            this->lblID2Title->Size = System::Drawing::Size(136, 21);
            this->lblID2Title->TabIndex = 8;
            this->lblID2Title->Text = L"Управление ID2";
            // 
            // lblID2In
            // 
            this->lblID2In->AutoSize = true;
            this->lblID2In->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->lblID2In->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(78)),
                static_cast<System::Int32>(static_cast<System::Byte>(216)));
            this->lblID2In->Location = System::Drawing::Point(20, 60);
            this->lblID2In->Name = L"lblID2In";
            this->lblID2In->Size = System::Drawing::Size(52, 15);
            this->lblID2In->TabIndex = 9;
            this->lblID2In->Text = L"ID2 вход";
            // 
            // txtID2In
            // 
            this->txtID2In->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(219)), static_cast<System::Int32>(static_cast<System::Byte>(234)),
                static_cast<System::Int32>(static_cast<System::Byte>(254)));
            this->txtID2In->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->txtID2In->Font = (gcnew System::Drawing::Font(L"Consolas", 10));
            this->txtID2In->Location = System::Drawing::Point(36, 91);
            this->txtID2In->Name = L"txtID2In";
            this->txtID2In->ReadOnly = true;
            this->txtID2In->Size = System::Drawing::Size(233, 16);
            this->txtID2In->TabIndex = 10;
            this->txtID2In->Text = L"127207";
            // 
            // lblID2Out
            // 
            this->lblID2Out->AutoSize = true;
            this->lblID2Out->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->lblID2Out->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(78)),
                static_cast<System::Int32>(static_cast<System::Byte>(216)));
            this->lblID2Out->Location = System::Drawing::Point(290, 60);
            this->lblID2Out->Name = L"lblID2Out";
            this->lblID2Out->Size = System::Drawing::Size(61, 15);
            this->lblID2Out->TabIndex = 11;
            this->lblID2Out->Text = L"ID2 выход";
            // 
            // txtID2Out
            // 
            this->txtID2Out->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(219)), static_cast<System::Int32>(static_cast<System::Byte>(234)),
                static_cast<System::Int32>(static_cast<System::Byte>(254)));
            this->txtID2Out->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->txtID2Out->Font = (gcnew System::Drawing::Font(L"Consolas", 10));
            this->txtID2Out->Location = System::Drawing::Point(307, 90);
            this->txtID2Out->Name = L"txtID2Out";
            this->txtID2Out->ReadOnly = true;
            this->txtID2Out->Size = System::Drawing::Size(233, 16);
            this->txtID2Out->TabIndex = 12;
            this->txtID2Out->Text = L"66188";
            // 
            // btnConfirmID
            // 
            this->btnConfirmID->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(78)),
                static_cast<System::Int32>(static_cast<System::Byte>(216)));
            this->btnConfirmID->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)),
                static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(175)));
            this->btnConfirmID->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnConfirmID->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->btnConfirmID->ForeColor = System::Drawing::Color::White;
            this->btnConfirmID->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnConfirmID.Image")));
            this->btnConfirmID->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
            this->btnConfirmID->Location = System::Drawing::Point(560, 85);
            this->btnConfirmID->Name = L"btnConfirmID";
            this->btnConfirmID->Size = System::Drawing::Size(280, 30);
            this->btnConfirmID->TabIndex = 13;
            this->btnConfirmID->Text = L"Подтвердить ID";
            this->btnConfirmID->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
            this->btnConfirmID->UseVisualStyleBackColor = false;
            // 
            // separator
            // 
            this->separator->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(209)), static_cast<System::Int32>(static_cast<System::Byte>(213)),
                static_cast<System::Int32>(static_cast<System::Byte>(219)));
            this->separator->Location = System::Drawing::Point(20, 125);
            this->separator->Name = L"separator";
            this->separator->Size = System::Drawing::Size(820, 1);
            this->separator->TabIndex = 14;
            // 
            // panelInputParams
            // 
            this->panelInputParams->BackColor = System::Drawing::Color::White;
            this->panelInputParams->Controls->Add(this->lblInputBadge);
            this->panelInputParams->Controls->Add(this->lblInputParams);
            this->panelInputParams->Controls->Add(this->lblThicknessIn);
            this->panelInputParams->Controls->Add(this->txtThicknessIn);
            this->panelInputParams->Controls->Add(this->lblWidthIn);
            this->panelInputParams->Controls->Add(this->txtWidthIn);
            this->panelInputParams->Controls->Add(this->lblStatusIn);
            this->panelInputParams->Controls->Add(this->txtStatusIn);
            this->panelInputParams->Location = System::Drawing::Point(20, 140);
            this->panelInputParams->Name = L"panelInputParams";
            this->panelInputParams->Size = System::Drawing::Size(400, 100);
            this->panelInputParams->TabIndex = 15;
            // 
            // lblInputBadge
            // 
            this->lblInputBadge->AutoSize = true;
            this->lblInputBadge->BackColor = System::Drawing::Color::White;
            this->lblInputBadge->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8));
            this->lblInputBadge->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(78)),
                static_cast<System::Int32>(static_cast<System::Byte>(216)));
            this->lblInputBadge->Location = System::Drawing::Point(10, 10);
            this->lblInputBadge->Name = L"lblInputBadge";
            this->lblInputBadge->Size = System::Drawing::Size(38, 13);
            this->lblInputBadge->TabIndex = 16;
            this->lblInputBadge->Text = L"INPUT";
            // 
            // lblInputParams
            // 
            this->lblInputParams->AutoSize = true;
            this->lblInputParams->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
            this->lblInputParams->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
                static_cast<System::Int32>(static_cast<System::Byte>(175)));
            this->lblInputParams->Location = System::Drawing::Point(48, 9);
            this->lblInputParams->Name = L"lblInputParams";
            this->lblInputParams->Size = System::Drawing::Size(110, 15);
            this->lblInputParams->TabIndex = 17;
            this->lblInputParams->Text = L"Параметры входа";
            // 
            // lblThicknessIn
            // 
            this->lblThicknessIn->AutoSize = true;
            this->lblThicknessIn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8));
            this->lblThicknessIn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(78)),
                static_cast<System::Int32>(static_cast<System::Byte>(216)));
            this->lblThicknessIn->Location = System::Drawing::Point(10, 40);
            this->lblThicknessIn->Name = L"lblThicknessIn";
            this->lblThicknessIn->Size = System::Drawing::Size(55, 13);
            this->lblThicknessIn->TabIndex = 18;
            this->lblThicknessIn->Text = L"Толщина";
            // 
            // txtThicknessIn
            // 
            this->txtThicknessIn->BackColor = System::Drawing::Color::White;
            this->txtThicknessIn->Location = System::Drawing::Point(10, 60);
            this->txtThicknessIn->Name = L"txtThicknessIn";
            this->txtThicknessIn->Size = System::Drawing::Size(120, 20);
            this->txtThicknessIn->TabIndex = 19;
            this->txtThicknessIn->Text = L"300";
            // 
            // lblWidthIn
            // 
            this->lblWidthIn->AutoSize = true;
            this->lblWidthIn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8));
            this->lblWidthIn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(78)),
                static_cast<System::Int32>(static_cast<System::Byte>(216)));
            this->lblWidthIn->Location = System::Drawing::Point(140, 40);
            this->lblWidthIn->Name = L"lblWidthIn";
            this->lblWidthIn->Size = System::Drawing::Size(52, 13);
            this->lblWidthIn->TabIndex = 20;
            this->lblWidthIn->Text = L"Ширина";
            // 
            // txtWidthIn
            // 
            this->txtWidthIn->BackColor = System::Drawing::Color::White;
            this->txtWidthIn->Location = System::Drawing::Point(140, 60);
            this->txtWidthIn->Name = L"txtWidthIn";
            this->txtWidthIn->Size = System::Drawing::Size(120, 20);
            this->txtWidthIn->TabIndex = 21;
            this->txtWidthIn->Text = L"1045";
            // 
            // lblStatusIn
            // 
            this->lblStatusIn->AutoSize = true;
            this->lblStatusIn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8));
            this->lblStatusIn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(78)),
                static_cast<System::Int32>(static_cast<System::Byte>(216)));
            this->lblStatusIn->Location = System::Drawing::Point(270, 40);
            this->lblStatusIn->Name = L"lblStatusIn";
            this->lblStatusIn->Size = System::Drawing::Size(40, 13);
            this->lblStatusIn->TabIndex = 22;
            this->lblStatusIn->Text = L"Статус";
            // 
            // txtStatusIn
            // 
            this->txtStatusIn->BackColor = System::Drawing::Color::White;
            this->txtStatusIn->Location = System::Drawing::Point(270, 60);
            this->txtStatusIn->Name = L"txtStatusIn";
            this->txtStatusIn->Size = System::Drawing::Size(120, 20);
            this->txtStatusIn->TabIndex = 23;
            this->txtStatusIn->Text = L"7";
            // 
            // panelOutputParams
            // 
            this->panelOutputParams->BackColor = System::Drawing::Color::White;
            this->panelOutputParams->Controls->Add(this->lblOutputBadge);
            this->panelOutputParams->Controls->Add(this->lblOutputParams);
            this->panelOutputParams->Controls->Add(this->lblThicknessOut);
            this->panelOutputParams->Controls->Add(this->txtThicknessOut);
            this->panelOutputParams->Controls->Add(this->lblWidthOut);
            this->panelOutputParams->Controls->Add(this->txtWidthOut);
            this->panelOutputParams->Controls->Add(this->lblStatusOut);
            this->panelOutputParams->Controls->Add(this->txtStatusOut);
            this->panelOutputParams->Location = System::Drawing::Point(440, 140);
            this->panelOutputParams->Name = L"panelOutputParams";
            this->panelOutputParams->Size = System::Drawing::Size(400, 100);
            this->panelOutputParams->TabIndex = 24;
            // 
            // lblOutputBadge
            // 
            this->lblOutputBadge->AutoSize = true;
            this->lblOutputBadge->BackColor = System::Drawing::Color::White;
            this->lblOutputBadge->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8));
            this->lblOutputBadge->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
                static_cast<System::Int32>(static_cast<System::Byte>(175)));
            this->lblOutputBadge->Location = System::Drawing::Point(10, 10);
            this->lblOutputBadge->Name = L"lblOutputBadge";
            this->lblOutputBadge->Size = System::Drawing::Size(50, 13);
            this->lblOutputBadge->TabIndex = 25;
            this->lblOutputBadge->Text = L"OUTPUT";
            // 
            // lblOutputParams
            // 
            this->lblOutputParams->AutoSize = true;
            this->lblOutputParams->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
            this->lblOutputParams->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
                static_cast<System::Int32>(static_cast<System::Byte>(175)));
            this->lblOutputParams->Location = System::Drawing::Point(60, 9);
            this->lblOutputParams->Name = L"lblOutputParams";
            this->lblOutputParams->Size = System::Drawing::Size(120, 15);
            this->lblOutputParams->TabIndex = 26;
            this->lblOutputParams->Text = L"Параметры выхода";
            // 
            // lblThicknessOut
            // 
            this->lblThicknessOut->AutoSize = true;
            this->lblThicknessOut->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8));
            this->lblThicknessOut->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(78)),
                static_cast<System::Int32>(static_cast<System::Byte>(216)));
            this->lblThicknessOut->Location = System::Drawing::Point(10, 40);
            this->lblThicknessOut->Name = L"lblThicknessOut";
            this->lblThicknessOut->Size = System::Drawing::Size(55, 13);
            this->lblThicknessOut->TabIndex = 27;
            this->lblThicknessOut->Text = L"Толщина";
            // 
            // txtThicknessOut
            // 
            this->txtThicknessOut->BackColor = System::Drawing::Color::White;
            this->txtThicknessOut->Location = System::Drawing::Point(10, 60);
            this->txtThicknessOut->Name = L"txtThicknessOut";
            this->txtThicknessOut->Size = System::Drawing::Size(120, 20);
            this->txtThicknessOut->TabIndex = 28;
            this->txtThicknessOut->Text = L"300";
            // 
            // lblWidthOut
            // 
            this->lblWidthOut->AutoSize = true;
            this->lblWidthOut->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8));
            this->lblWidthOut->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(78)),
                static_cast<System::Int32>(static_cast<System::Byte>(216)));
            this->lblWidthOut->Location = System::Drawing::Point(140, 40);
            this->lblWidthOut->Name = L"lblWidthOut";
            this->lblWidthOut->Size = System::Drawing::Size(52, 13);
            this->lblWidthOut->TabIndex = 29;
            this->lblWidthOut->Text = L"Ширина";
            // 
            // txtWidthOut
            // 
            this->txtWidthOut->BackColor = System::Drawing::Color::White;
            this->txtWidthOut->Location = System::Drawing::Point(140, 60);
            this->txtWidthOut->Name = L"txtWidthOut";
            this->txtWidthOut->Size = System::Drawing::Size(120, 20);
            this->txtWidthOut->TabIndex = 30;
            this->txtWidthOut->Text = L"1045";
            // 
            // lblStatusOut
            // 
            this->lblStatusOut->AutoSize = true;
            this->lblStatusOut->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8));
            this->lblStatusOut->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(78)),
                static_cast<System::Int32>(static_cast<System::Byte>(216)));
            this->lblStatusOut->Location = System::Drawing::Point(270, 40);
            this->lblStatusOut->Name = L"lblStatusOut";
            this->lblStatusOut->Size = System::Drawing::Size(40, 13);
            this->lblStatusOut->TabIndex = 31;
            this->lblStatusOut->Text = L"Статус";
            // 
            // txtStatusOut
            // 
            this->txtStatusOut->BackColor = System::Drawing::Color::White;
            this->txtStatusOut->Location = System::Drawing::Point(270, 60);
            this->txtStatusOut->Name = L"txtStatusOut";
            this->txtStatusOut->Size = System::Drawing::Size(120, 20);
            this->txtStatusOut->TabIndex = 32;
            this->txtStatusOut->Text = L"1";
            // 
            // panel1
            // 
            this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(219)), static_cast<System::Int32>(static_cast<System::Byte>(234)),
                static_cast<System::Int32>(static_cast<System::Byte>(254)));
            this->panel1->Location = System::Drawing::Point(20, 85);
            this->panel1->Name = L"panel1";
            this->panel1->Size = System::Drawing::Size(249, 30);
            this->panel1->TabIndex = 34;
            // 
            // panel2
            // 
            this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(219)), static_cast<System::Int32>(static_cast<System::Byte>(234)),
                static_cast<System::Int32>(static_cast<System::Byte>(254)));
            this->panel2->Location = System::Drawing::Point(290, 85);
            this->panel2->Name = L"panel2";
            this->panel2->Size = System::Drawing::Size(250, 30);
            this->panel2->TabIndex = 35;
            // 
            // panelResults
            // 
            this->panelResults->BackColor = System::Drawing::Color::White;
            this->panelResults->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->panelResults->Controls->Add(this->picSearchIcon);
            this->panelResults->Controls->Add(this->lblResultsTitle);
            this->panelResults->Controls->Add(this->btnCheckRecords);
            this->panelResults->Controls->Add(this->dgvResults);
            this->panelResults->Location = System::Drawing::Point(8, 452);
            this->panelResults->Name = L"panelResults";
            this->panelResults->Size = System::Drawing::Size(420, 300);
            this->panelResults->TabIndex = 34;
            // 
            // picSearchIcon
            // 
            this->picSearchIcon->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picSearchIcon.Image")));
            this->picSearchIcon->Location = System::Drawing::Point(20, 20);
            this->picSearchIcon->Name = L"picSearchIcon";
            this->picSearchIcon->Size = System::Drawing::Size(20, 20);
            this->picSearchIcon->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->picSearchIcon->TabIndex = 35;
            this->picSearchIcon->TabStop = false;
            // 
            // lblResultsTitle
            // 
            this->lblResultsTitle->AutoSize = true;
            this->lblResultsTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
            this->lblResultsTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(58)),
                static_cast<System::Int32>(static_cast<System::Byte>(138)));
            this->lblResultsTitle->Location = System::Drawing::Point(47, 19);
            this->lblResultsTitle->Name = L"lblResultsTitle";
            this->lblResultsTitle->Size = System::Drawing::Size(180, 21);
            this->lblResultsTitle->TabIndex = 36;
            this->lblResultsTitle->Text = L"Результаты проверки";
            // 
            // btnCheckRecords
            // 
            this->btnCheckRecords->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(78)),
                static_cast<System::Int32>(static_cast<System::Byte>(216)));
            this->btnCheckRecords->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)),
                static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(175)));
            this->btnCheckRecords->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnCheckRecords->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->btnCheckRecords->ForeColor = System::Drawing::Color::White;
            this->btnCheckRecords->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnCheckRecords.Image")));
            this->btnCheckRecords->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
            this->btnCheckRecords->Location = System::Drawing::Point(20, 60);
            this->btnCheckRecords->Name = L"btnCheckRecords";
            this->btnCheckRecords->Size = System::Drawing::Size(380, 30);
            this->btnCheckRecords->TabIndex = 37;
            this->btnCheckRecords->Text = L"Проверить записи";
            this->btnCheckRecords->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
            this->btnCheckRecords->UseVisualStyleBackColor = false;
            // 
            // dgvResults
            // 
            this->dgvResults->AllowUserToAddRows = false;
            this->dgvResults->AllowUserToDeleteRows = false;
            this->dgvResults->BackgroundColor = System::Drawing::Color::White;
            this->dgvResults->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dgvResults->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
                this->colID, this->colType,
                    this->colThickness, this->colWidth, this->colStatus
            });
            this->dgvResults->Location = System::Drawing::Point(20, 100);
            this->dgvResults->Name = L"dgvResults";
            this->dgvResults->ReadOnly = true;
            this->dgvResults->RowHeadersVisible = false;
            this->dgvResults->RowHeadersWidth = 51;
            this->dgvResults->Size = System::Drawing::Size(380, 180);
            this->dgvResults->TabIndex = 38;
            // 
            // colID
            // 
            this->colID->HeaderText = L"ID";
            this->colID->MinimumWidth = 6;
            this->colID->Name = L"colID";
            this->colID->ReadOnly = true;
            this->colID->Width = 80;
            // 
            // colType
            // 
            this->colType->HeaderText = L"Тип";
            this->colType->MinimumWidth = 6;
            this->colType->Name = L"colType";
            this->colType->ReadOnly = true;
            this->colType->Width = 80;
            // 
            // colThickness
            // 
            this->colThickness->HeaderText = L"Толщина";
            this->colThickness->MinimumWidth = 6;
            this->colThickness->Name = L"colThickness";
            this->colThickness->ReadOnly = true;
            this->colThickness->Width = 80;
            // 
            // colWidth
            // 
            this->colWidth->HeaderText = L"Ширина";
            this->colWidth->MinimumWidth = 6;
            this->colWidth->Name = L"colWidth";
            this->colWidth->ReadOnly = true;
            this->colWidth->Width = 80;
            // 
            // colStatus
            // 
            this->colStatus->HeaderText = L"Статус";
            this->colStatus->MinimumWidth = 6;
            this->colStatus->Name = L"colStatus";
            this->colStatus->ReadOnly = true;
            this->colStatus->Width = 80;
            // 
            // panelLogs
            // 
            this->panelLogs->BackColor = System::Drawing::Color::White;
            this->panelLogs->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->panelLogs->Controls->Add(this->lblLogsTitle);
            this->panelLogs->Controls->Add(this->lstLogs);
            this->panelLogs->Location = System::Drawing::Point(438, 452);
            this->panelLogs->Name = L"panelLogs";
            this->panelLogs->Size = System::Drawing::Size(430, 300);
            this->panelLogs->TabIndex = 39;
            // 
            // lblLogsTitle
            // 
            this->lblLogsTitle->AutoSize = true;
            this->lblLogsTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold));
            this->lblLogsTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(58)),
                static_cast<System::Int32>(static_cast<System::Byte>(138)));
            this->lblLogsTitle->Location = System::Drawing::Point(20, 20);
            this->lblLogsTitle->Name = L"lblLogsTitle";
            this->lblLogsTitle->Size = System::Drawing::Size(131, 21);
            this->lblLogsTitle->TabIndex = 40;
            this->lblLogsTitle->Text = L"Логи операций";
            // 
            // lstLogs
            // 
            this->lstLogs->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(239)), static_cast<System::Int32>(static_cast<System::Byte>(246)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->lstLogs->Font = (gcnew System::Drawing::Font(L"Consolas", 9));
            this->lstLogs->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(22)), static_cast<System::Int32>(static_cast<System::Byte>(163)),
                static_cast<System::Int32>(static_cast<System::Byte>(74)));
            this->lstLogs->HorizontalScrollbar = true;
            this->lstLogs->ItemHeight = 14;
            this->lstLogs->Items->AddRange(gcnew cli::array< System::Object^  >(17) {
                L"12.07.2025 09:13: Подключение к БД1 (MSSQL) успешно установлено",
                    L"12.07.2025 09:13: Подключение к БД1 (MSSQL) успешно установлено", L"12.07.2025 09:13: Подключение к БД1 (MSSQL) успешно установлено",
                    L"12.07.2025 09:13: Подключение к БД1 (MSSQL) успешно установлено", L"12.07.2025 09:13: Подключение к БД1 (MSSQL) успешно установлено",
                    L"12.07.2025 09:13: Подключение к БД1 (MSSQL) успешно установлено", L"12.07.2025 09:13: Подключение к БД1 (MSSQL) успешно установлено",
                    L"12.07.2025 09:13: Подключение к БД1 (MSSQL) успешно установлено", L"12.07.2025 09:13: Подключение к БД1 (MSSQL) успешно установлено",
                    L"12.07.2025 09:13: Подключение к БД1 (MSSQL) успешно установлено", L"12.07.2025 09:13: Подключение к БД1 (MSSQL) успешно установлено",
                    L"12.07.2025 09:13: Подключение к БД1 (MSSQL) успешно установлено", L"12.07.2025 09:13: Подключение к БД1 (MSSQL) успешно установлено",
                    L"12.07.2025 09:13: Подключение к БД1 (MSSQL) успешно установлено", L"12.07.2025 09:13: Подключение к БД1 (MSSQL) успешно установлено",
                    L"12.07.2025 09:13: Подключение к БД1 (MSSQL) успешно установлено", L"12.07.2025 09:13: Подключение к БД2 (ORACLE) успешно установлено"
            });
            this->lstLogs->Location = System::Drawing::Point(20, 60);
            this->lstLogs->Name = L"lstLogs";
            this->lstLogs->Size = System::Drawing::Size(390, 214);
            this->lstLogs->TabIndex = 41;
            // 
            // footerPanel
            // 
            this->footerPanel->BackColor = System::Drawing::Color::White;
            this->footerPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->footerPanel->Controls->Add(this->lblStatusTxt);
            this->footerPanel->Controls->Add(this->lblDB1Status);
            this->footerPanel->Controls->Add(this->lblDB2Status);
            this->footerPanel->Location = System::Drawing::Point(8, 758);
            this->footerPanel->Name = L"footerPanel";
            this->footerPanel->Size = System::Drawing::Size(860, 40);
            this->footerPanel->TabIndex = 42;
            // 
            // lblStatusTxt
            // 
            this->lblStatusTxt->AutoSize = true;
            this->lblStatusTxt->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->lblStatusTxt->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
                static_cast<System::Int32>(static_cast<System::Byte>(175)));
            this->lblStatusTxt->Location = System::Drawing::Point(20, 10);
            this->lblStatusTxt->Name = L"lblStatusTxt";
            this->lblStatusTxt->Size = System::Drawing::Size(43, 13);
            this->lblStatusTxt->TabIndex = 47;
            this->lblStatusTxt->Text = L"Статус:";
            // 
            // lblDB1Status
            // 
            this->lblDB1Status->AutoSize = true;
            this->lblDB1Status->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8));
            this->lblDB1Status->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(22)), static_cast<System::Int32>(static_cast<System::Byte>(163)),
                static_cast<System::Int32>(static_cast<System::Byte>(74)));
            this->lblDB1Status->Location = System::Drawing::Point(60, 10);
            this->lblDB1Status->Name = L"lblDB1Status";
            this->lblDB1Status->Size = System::Drawing::Size(179, 13);
            this->lblDB1Status->TabIndex = 44;
            this->lblDB1Status->Text = L"Соединение с БД1: Подключено";
            // 
            // lblDB2Status
            // 
            this->lblDB2Status->AutoSize = true;
            this->lblDB2Status->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8));
            this->lblDB2Status->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(220)), static_cast<System::Int32>(static_cast<System::Byte>(38)),
                static_cast<System::Int32>(static_cast<System::Byte>(38)));
            this->lblDB2Status->Location = System::Drawing::Point(240, 10);
            this->lblDB2Status->Name = L"lblDB2Status";
            this->lblDB2Status->Size = System::Drawing::Size(172, 13);
            this->lblDB2Status->TabIndex = 46;
            this->lblDB2Status->Text = L"Соединение с БД2: Отключено";
            // 
            // btnClosedMW
            // 
            this->btnClosedMW->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->btnClosedMW->FlatAppearance->BorderColor = System::Drawing::Color::White;
            this->btnClosedMW->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(239)),
                static_cast<System::Int32>(static_cast<System::Byte>(246)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->btnClosedMW->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnClosedMW->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->btnClosedMW->ForeColor = System::Drawing::Color::White;
            this->btnClosedMW->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnClosedMW.Image")));
            this->btnClosedMW->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
            this->btnClosedMW->Location = System::Drawing::Point(827, 12);
            this->btnClosedMW->Name = L"btnClosedMW";
            this->btnClosedMW->Size = System::Drawing::Size(41, 40);
            this->btnClosedMW->TabIndex = 43;
            this->btnClosedMW->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
            this->btnClosedMW->UseVisualStyleBackColor = false;
            this->btnClosedMW->Click += gcnew System::EventHandler(this, &MainWindow::btnClosedCW_Click);
            // 
            // MainWindow
            // 
            this->BackColor = System::Drawing::Color::White;
            this->ClientSize = System::Drawing::Size(880, 810);
            this->Controls->Add(this->btnClosedMW);
            this->Controls->Add(this->headerPanel);
            this->Controls->Add(this->panelID2);
            this->Controls->Add(this->panelResults);
            this->Controls->Add(this->panelLogs);
            this->Controls->Add(this->footerPanel);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            this->MaximizeBox = false;
            this->Name = L"MainWindow";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Управление ID2 для рулонов";
            this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWindow::MainWindow_MouseDown);
            this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWindow::MainWindow_MouseMove);
            this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWindow::MainWindow_MouseUp);
            this->headerPanel->ResumeLayout(false);
            this->headerPanel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picDatabaseIcon))->EndInit();
            this->panelID2->ResumeLayout(false);
            this->panelID2->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picSettingsIcon))->EndInit();
            this->panelInputParams->ResumeLayout(false);
            this->panelInputParams->PerformLayout();
            this->panelOutputParams->ResumeLayout(false);
            this->panelOutputParams->PerformLayout();
            this->panelResults->ResumeLayout(false);
            this->panelResults->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picSearchIcon))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvResults))->EndInit();
            this->panelLogs->ResumeLayout(false);
            this->panelLogs->PerformLayout();
            this->footerPanel->ResumeLayout(false);
            this->footerPanel->PerformLayout();
            this->ResumeLayout(false);

        }
#pragma endregion
        private: System::Void btnDisconnect_Click(System::Object^, System::EventArgs^);
        private: System::Void MainWindow_FormClosing(System::Object^, System::Windows::Forms::FormClosingEventArgs^);
        private: System::Void btnClosedCW_Click(System::Object^ sender, System::EventArgs^ e);
        private: System::Void MainWindow_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
        private: System::Void MainWindow_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
        private: System::Void MainWindow_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
};
}