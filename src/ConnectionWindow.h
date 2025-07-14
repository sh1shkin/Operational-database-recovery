#pragma once

namespace src {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;
	using namespace System::Data::Odbc;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class ConnectionWindow : public System::Windows::Forms::Form
	{
	private:
		OdbcConnection^ db_connect;
		String^ nameDBMS;
		String^ Server;
		String^ DataBase;
		String^ User;
	public:
		ConnectionWindow(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
		
		
		/*public: void ClearFields() {
			comboBox1->SelectedIndex = -1;
			comboBox1->Text = "";
			TextBoxDataBase->Text = "";
			TextBoxUser->Text = "";
			TextBoxPassword->Text = "";
			TextBoxServer->Text = "";
			MessageTextConnect->Text = "";
		}*/

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~ConnectionWindow()
		{
			if (components) delete components;
			if (db_connect != nullptr && db_connect->State == ConnectionState::Open)
				db_connect->Close();
		}
	private: System::Windows::Forms::Panel^ panel1;	
	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ labelPassword;
	private: System::Windows::Forms::TextBox^ TextBoxPassword;
	private: System::Windows::Forms::Button^ ButtonConnect;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Label^ MessageTextConnect;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ LabelText;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ CheckConnect;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ConnectionWindow::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->CheckConnect = (gcnew System::Windows::Forms::Button());
			this->LabelText = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->TextBoxPassword = (gcnew System::Windows::Forms::TextBox());
			this->ButtonConnect = (gcnew System::Windows::Forms::Button());
			this->labelPassword = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->MessageTextConnect = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->BackColor = System::Drawing::Color::White;
			this->panel1->Controls->Add(this->CheckConnect);
			this->panel1->Controls->Add(this->LabelText);
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Controls->Add(this->TextBoxPassword);
			this->panel1->Controls->Add(this->ButtonConnect);
			this->panel1->Controls->Add(this->labelPassword);
			this->panel1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->panel1->Location = System::Drawing::Point(96, 87);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(594, 316);
			this->panel1->TabIndex = 0;
			// 
			// CheckConnect
			// 
			this->CheckConnect->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->CheckConnect->BackColor = System::Drawing::Color::White;
			this->CheckConnect->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(90)),
				static_cast<System::Int32>(static_cast<System::Byte>(115)), static_cast<System::Int32>(static_cast<System::Byte>(191)));
			this->CheckConnect->FlatAppearance->BorderSize = 2;
			this->CheckConnect->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->CheckConnect->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->CheckConnect->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(42)), static_cast<System::Int32>(static_cast<System::Byte>(74)),
				static_cast<System::Int32>(static_cast<System::Byte>(172)));
			this->CheckConnect->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"CheckConnect.Image")));
			this->CheckConnect->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->CheckConnect->Location = System::Drawing::Point(34, 261);
			this->CheckConnect->Name = L"CheckConnect";
			this->CheckConnect->Size = System::Drawing::Size(246, 32);
			this->CheckConnect->TabIndex = 20;
			this->CheckConnect->Text = L"Файл кофигурации";
			this->CheckConnect->UseVisualStyleBackColor = false;
			this->CheckConnect->Click += gcnew System::EventHandler(this, &ConnectionWindow::CheckConnect_Click);
			// 
			// LabelText
			// 
			this->LabelText->AutoSize = true;
			this->LabelText->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LabelText->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(78)),
				static_cast<System::Int32>(static_cast<System::Byte>(216)));
			this->LabelText->Location = System::Drawing::Point(118, 15);
			this->LabelText->Name = L"LabelText";
			this->LabelText->Size = System::Drawing::Size(392, 25);
			this->LabelText->TabIndex = 16;
			this->LabelText->Text = L"Настройка подключения к базе данных";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(83, 15);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(36, 39);
			this->pictureBox1->TabIndex = 17;
			this->pictureBox1->TabStop = false;
			// 
			// TextBoxPassword
			// 
			this->TextBoxPassword->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->TextBoxPassword->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12));
			this->TextBoxPassword->Location = System::Drawing::Point(34, 104);
			this->TextBoxPassword->Name = L"TextBoxPassword";
			this->TextBoxPassword->PasswordChar = '*';
			this->TextBoxPassword->Size = System::Drawing::Size(530, 29);
			this->TextBoxPassword->TabIndex = 11;
			// 
			// ButtonConnect
			// 
			this->ButtonConnect->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->ButtonConnect->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(42)), static_cast<System::Int32>(static_cast<System::Byte>(74)),
				static_cast<System::Int32>(static_cast<System::Byte>(172)));
			this->ButtonConnect->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(42)),
				static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(172)));
			this->ButtonConnect->FlatAppearance->BorderSize = 2;
			this->ButtonConnect->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ButtonConnect->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ButtonConnect->ForeColor = System::Drawing::Color::White;
			this->ButtonConnect->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ButtonConnect.Image")));
			this->ButtonConnect->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->ButtonConnect->Location = System::Drawing::Point(305, 261);
			this->ButtonConnect->Name = L"ButtonConnect";
			this->ButtonConnect->Size = System::Drawing::Size(259, 32);
			this->ButtonConnect->TabIndex = 6;
			this->ButtonConnect->Text = L"Подключиться и продолжить";
			this->ButtonConnect->UseVisualStyleBackColor = false;
			this->ButtonConnect->Click += gcnew System::EventHandler(this, &ConnectionWindow::connect1_Click);
			// 
			// labelPassword
			// 
			this->labelPassword->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->labelPassword->AutoSize = true;
			this->labelPassword->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelPassword->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(78)),
				static_cast<System::Int32>(static_cast<System::Byte>(216)));
			this->labelPassword->Location = System::Drawing::Point(30, 82);
			this->labelPassword->Name = L"labelPassword";
			this->labelPassword->Size = System::Drawing::Size(68, 19);
			this->labelPassword->TabIndex = 5;
			this->labelPassword->Text = L"Пароль*";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(78)),
				static_cast<System::Int32>(static_cast<System::Byte>(216)));
			this->label1->Location = System::Drawing::Point(273, 44);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(299, 19);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Подключение к БД1(Для получения данных)";
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(180, 10);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(45, 53);
			this->pictureBox2->TabIndex = 13;
			this->pictureBox2->TabStop = false;
			// 
			// panel2
			// 
			this->panel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel2->BackColor = System::Drawing::Color::White;
			this->panel2->Controls->Add(this->label3);
			this->panel2->Controls->Add(this->label1);
			this->panel2->Controls->Add(this->pictureBox2);
			this->panel2->Location = System::Drawing::Point(0, -1);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(784, 69);
			this->panel2->TabIndex = 1;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(78)),
				static_cast<System::Int32>(static_cast<System::Byte>(216)));
			this->label3->Location = System::Drawing::Point(213, 10);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(431, 36);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Управление ID2 для рулонов";
			// 
			// panel3
			// 
			this->panel3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel3->BackColor = System::Drawing::Color::White;
			this->panel3->Controls->Add(this->MessageTextConnect);
			this->panel3->Controls->Add(this->label2);
			this->panel3->Location = System::Drawing::Point(0, 409);
			this->panel3->MaximumSize = System::Drawing::Size(1000, 400);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(784, 70);
			this->panel3->TabIndex = 2;
			// 
			// MessageTextConnect
			// 
			this->MessageTextConnect->AutoSize = true;
			this->MessageTextConnect->Location = System::Drawing::Point(62, 11);
			this->MessageTextConnect->Name = L"MessageTextConnect";
			this->MessageTextConnect->Size = System::Drawing::Size(0, 13);
			this->MessageTextConnect->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(78)),
				static_cast<System::Int32>(static_cast<System::Byte>(216)));
			this->label2->Location = System::Drawing::Point(12, 11);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(56, 19);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Статус:";
			// 
			// ConnectionWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(249)), static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(249)));
			this->ClientSize = System::Drawing::Size(784, 479);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(800, 518);
			this->MinimumSize = System::Drawing::Size(800, 518);
			this->Name = L"ConnectionWindow";
			this->Text = L"Operational-database-recovery";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		private: System::Void connect1_Click(System::Object^, System::EventArgs^);
		private: System::Void CheckConnect_Click(System::Object^, System::EventArgs^);
		private: System::Void ConnectionWindow_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);

};
}