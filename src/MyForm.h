#pragma once

namespace src {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		SqlConnection^ sql_connect;
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ labelUser;
	
	protected:

	private: System::Windows::Forms::Label^ labelServer;
	private: System::Windows::Forms::Label^ SUBD;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ labelPassword;
	private: System::Windows::Forms::TextBox^ TextBoxPassword;
	private: System::Windows::Forms::TextBox^ TextBoxUser;
	private: System::Windows::Forms::TextBox^ TextBoxServer;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Button^ ButtonConnect;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::TextBox^ TextBoxDataBase;
	private: System::Windows::Forms::Label^ labelDataBase;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->CheckConnect = (gcnew System::Windows::Forms::Button());
			this->LabelText = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->TextBoxDataBase = (gcnew System::Windows::Forms::TextBox());
			this->labelDataBase = (gcnew System::Windows::Forms::Label());
			this->TextBoxPassword = (gcnew System::Windows::Forms::TextBox());
			this->TextBoxUser = (gcnew System::Windows::Forms::TextBox());
			this->TextBoxServer = (gcnew System::Windows::Forms::TextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->ButtonConnect = (gcnew System::Windows::Forms::Button());
			this->labelPassword = (gcnew System::Windows::Forms::Label());
			this->labelUser = (gcnew System::Windows::Forms::Label());
			this->labelServer = (gcnew System::Windows::Forms::Label());
			this->SUBD = (gcnew System::Windows::Forms::Label());
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
			this->panel1->Controls->Add(this->TextBoxDataBase);
			this->panel1->Controls->Add(this->labelDataBase);
			this->panel1->Controls->Add(this->TextBoxPassword);
			this->panel1->Controls->Add(this->TextBoxUser);
			this->panel1->Controls->Add(this->TextBoxServer);
			this->panel1->Controls->Add(this->comboBox1);
			this->panel1->Controls->Add(this->ButtonConnect);
			this->panel1->Controls->Add(this->labelPassword);
			this->panel1->Controls->Add(this->labelUser);
			this->panel1->Controls->Add(this->labelServer);
			this->panel1->Controls->Add(this->SUBD);
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
			this->CheckConnect->Text = L"Тестировать соединение";
			this->CheckConnect->UseVisualStyleBackColor = false;
			this->CheckConnect->Click += gcnew System::EventHandler(this, &MyForm::CheckConnect_Click);
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
			this->pictureBox1->Size = System::Drawing::Size(38, 34);
			this->pictureBox1->TabIndex = 17;
			this->pictureBox1->TabStop = false;
			// 
			// TextBoxDataBase
			// 
			this->TextBoxDataBase->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->TextBoxDataBase->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12));
			this->TextBoxDataBase->Location = System::Drawing::Point(34, 145);
			this->TextBoxDataBase->Name = L"TextBoxDataBase";
			this->TextBoxDataBase->Size = System::Drawing::Size(246, 29);
			this->TextBoxDataBase->TabIndex = 15;
			// 
			// labelDataBase
			// 
			this->labelDataBase->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->labelDataBase->AutoSize = true;
			this->labelDataBase->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelDataBase->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(78)),
				static_cast<System::Int32>(static_cast<System::Byte>(216)));
			this->labelDataBase->Location = System::Drawing::Point(30, 123);
			this->labelDataBase->Name = L"labelDataBase";
			this->labelDataBase->Size = System::Drawing::Size(105, 19);
			this->labelDataBase->TabIndex = 14;
			this->labelDataBase->Text = L"База данных*";
			// 
			// TextBoxPassword
			// 
			this->TextBoxPassword->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->TextBoxPassword->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12));
			this->TextBoxPassword->Location = System::Drawing::Point(34, 218);
			this->TextBoxPassword->Name = L"TextBoxPassword";
			this->TextBoxPassword->PasswordChar = '*';
			this->TextBoxPassword->Size = System::Drawing::Size(530, 29);
			this->TextBoxPassword->TabIndex = 11;
			// 
			// TextBoxUser
			// 
			this->TextBoxUser->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->TextBoxUser->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12));
			this->TextBoxUser->Location = System::Drawing::Point(305, 145);
			this->TextBoxUser->Name = L"TextBoxUser";
			this->TextBoxUser->Size = System::Drawing::Size(259, 29);
			this->TextBoxUser->TabIndex = 10;
			// 
			// TextBoxServer
			// 
			this->TextBoxServer->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->TextBoxServer->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12));
			this->TextBoxServer->Location = System::Drawing::Point(305, 79);
			this->TextBoxServer->Name = L"TextBoxServer";
			this->TextBoxServer->Size = System::Drawing::Size(259, 29);
			this->TextBoxServer->TabIndex = 9;
			// 
			// comboBox1
			// 
			this->comboBox1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"MS SQL", L"Oracle" });
			this->comboBox1->Location = System::Drawing::Point(34, 79);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(246, 29);
			this->comboBox1->TabIndex = 7;
			// 
			// ButtonConnect
			// 
			this->ButtonConnect->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->ButtonConnect->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(42)), static_cast<System::Int32>(static_cast<System::Byte>(74)),
				static_cast<System::Int32>(static_cast<System::Byte>(172)));
			this->ButtonConnect->FlatAppearance->BorderColor = System::Drawing::Color::WhiteSmoke;
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
			this->ButtonConnect->Click += gcnew System::EventHandler(this, &MyForm::connect1_Click);
			// 
			// labelPassword
			// 
			this->labelPassword->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->labelPassword->AutoSize = true;
			this->labelPassword->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelPassword->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(78)),
				static_cast<System::Int32>(static_cast<System::Byte>(216)));
			this->labelPassword->Location = System::Drawing::Point(30, 196);
			this->labelPassword->Name = L"labelPassword";
			this->labelPassword->Size = System::Drawing::Size(68, 19);
			this->labelPassword->TabIndex = 5;
			this->labelPassword->Text = L"Пароль*";
			// 
			// labelUser
			// 
			this->labelUser->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->labelUser->AutoSize = true;
			this->labelUser->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelUser->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(78)),
				static_cast<System::Int32>(static_cast<System::Byte>(216)));
			this->labelUser->Location = System::Drawing::Point(301, 123);
			this->labelUser->Name = L"labelUser";
			this->labelUser->Size = System::Drawing::Size(111, 19);
			this->labelUser->TabIndex = 4;
			this->labelUser->Text = L"Пользователь:";
			// 
			// labelServer
			// 
			this->labelServer->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->labelServer->AutoSize = true;
			this->labelServer->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelServer->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(78)),
				static_cast<System::Int32>(static_cast<System::Byte>(216)));
			this->labelServer->Location = System::Drawing::Point(301, 57);
			this->labelServer->Name = L"labelServer";
			this->labelServer->Size = System::Drawing::Size(64, 19);
			this->labelServer->TabIndex = 3;
			this->labelServer->Text = L"Сервер:";
			// 
			// SUBD
			// 
			this->SUBD->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->SUBD->AutoSize = true;
			this->SUBD->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->SUBD->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(78)),
				static_cast<System::Int32>(static_cast<System::Byte>(216)));
			this->SUBD->Location = System::Drawing::Point(30, 57);
			this->SUBD->Name = L"SUBD";
			this->SUBD->Size = System::Drawing::Size(138, 19);
			this->SUBD->TabIndex = 1;
			this->SUBD->Text = L"Тип базы данных*";
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
			this->pictureBox2->Size = System::Drawing::Size(59, 53);
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
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(249)), static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(249)));
			this->ClientSize = System::Drawing::Size(784, 481);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(800, 520);
			this->MinimumSize = System::Drawing::Size(800, 520);
			this->Name = L"MyForm";
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
	
private: System::Void connect1_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ TypeSUBD = comboBox1->Text;
	if (TypeSUBD == L"") {
		MessageTextConnect->Font = gcnew System::Drawing::Font("Microsoft Sans Serif", 10.25);
		MessageTextConnect->ForeColor = Color::Red;
		MessageTextConnect->Text = L"Выберите используемую СУБД";
		return;
	}
	if (TypeSUBD == L"MS SQL") {
		String^ connect = "Server=" + TextBoxServer->Text + "LEVEL2; Database = " + TextBoxDataBase->Text + "; User Id =" + TextBoxUser->Text + "; Password = " + TextBoxPassword->Text + ";";
		if(sql_connect == nullptr || sql_connect->State != ConnectionState::Open)
			SqlConnection^ sql_connect = gcnew SqlConnection(connect);
		try {
			sql_connect->Open();
			if (sql_connect->State != ConnectionState::Open) {
				MessageTextConnect->Font = gcnew System::Drawing::Font("Microsoft Sans Serif", 10.25);
				MessageTextConnect->ForeColor = Color::Red;
				MessageTextConnect->Text = L"Ошибка подключения, " + TextBoxDataBase->Text;
				return;
			}
			MessageTextConnect->Font = gcnew System::Drawing::Font("Microsoft Sans Serif", 10.25);
			MessageTextConnect->ForeColor = Color::Green;
			MessageTextConnect->Text = L"Подключено успоешно, " + TextBoxDataBase->Text;
		}
		catch (Exception^ ex) {
			MessageTextConnect->Font = gcnew System::Drawing::Font("Microsoft Sans Serif", 10.25);
			MessageTextConnect->ForeColor = Color::Red;
			MessageTextConnect->Text = L"Ошибка! Проверьте правильность введеных вами полей";
		}
		finally {
			if (sql_connect->State == ConnectionState::Open) {
				sql_connect->Close();
			}
		}
	}
}

private: System::Void CheckConnect_Click(System::Object^ sender, System::EventArgs^ e) {
	if (sql_connect == nullptr || sql_connect->State != ConnectionState::Open) {
		MessageTextConnect->Font = gcnew System::Drawing::Font("Microsoft Sans Serif", 10.25);
		MessageTextConnect->ForeColor = Color::Red;
		MessageTextConnect->Text = L"Ошибка подключения";
		return;
	}
	MessageTextConnect->Font = gcnew System::Drawing::Font("Microsoft Sans Serif", 10.25);
	MessageTextConnect->ForeColor = Color::Green;
	MessageTextConnect->Text = L"Подключение успешно";
}


};
}