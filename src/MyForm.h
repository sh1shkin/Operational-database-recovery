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
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::TextBox^ TextBoxDataBase;

	private: System::Windows::Forms::Label^ labelDataBase;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Label^ MessageTextConnect;

	private: System::Windows::Forms::Label^ label2;





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
			this->TextBoxDataBase = (gcnew System::Windows::Forms::TextBox());
			this->labelDataBase = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
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
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->MessageTextConnect = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->BackColor = System::Drawing::Color::White;
			this->panel1->Controls->Add(this->TextBoxDataBase);
			this->panel1->Controls->Add(this->labelDataBase);
			this->panel1->Controls->Add(this->pictureBox2);
			this->panel1->Controls->Add(this->TextBoxPassword);
			this->panel1->Controls->Add(this->TextBoxUser);
			this->panel1->Controls->Add(this->TextBoxServer);
			this->panel1->Controls->Add(this->comboBox1);
			this->panel1->Controls->Add(this->ButtonConnect);
			this->panel1->Controls->Add(this->labelPassword);
			this->panel1->Controls->Add(this->labelUser);
			this->panel1->Controls->Add(this->labelServer);
			this->panel1->Controls->Add(this->SUBD);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(24, 87);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(936, 229);
			this->panel1->TabIndex = 0;
			// 
			// TextBoxDataBase
			// 
			this->TextBoxDataBase->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->TextBoxDataBase->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12));
			this->TextBoxDataBase->Location = System::Drawing::Point(591, 101);
			this->TextBoxDataBase->Name = L"TextBoxDataBase";
			this->TextBoxDataBase->Size = System::Drawing::Size(204, 29);
			this->TextBoxDataBase->TabIndex = 15;
			// 
			// labelDataBase
			// 
			this->labelDataBase->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->labelDataBase->AutoSize = true;
			this->labelDataBase->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12));
			this->labelDataBase->Location = System::Drawing::Point(587, 68);
			this->labelDataBase->Name = L"labelDataBase";
			this->labelDataBase->Size = System::Drawing::Size(102, 21);
			this->labelDataBase->TabIndex = 14;
			this->labelDataBase->Text = L"База/Схема";
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(17, 10);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(34, 31);
			this->pictureBox2->TabIndex = 13;
			this->pictureBox2->TabStop = false;
			// 
			// TextBoxPassword
			// 
			this->TextBoxPassword->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->TextBoxPassword->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12));
			this->TextBoxPassword->Location = System::Drawing::Point(360, 181);
			this->TextBoxPassword->Name = L"TextBoxPassword";
			this->TextBoxPassword->Size = System::Drawing::Size(204, 29);
			this->TextBoxPassword->TabIndex = 11;
			// 
			// TextBoxUser
			// 
			this->TextBoxUser->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->TextBoxUser->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12));
			this->TextBoxUser->Location = System::Drawing::Point(127, 181);
			this->TextBoxUser->Name = L"TextBoxUser";
			this->TextBoxUser->Size = System::Drawing::Size(203, 29);
			this->TextBoxUser->TabIndex = 10;
			// 
			// TextBoxServer
			// 
			this->TextBoxServer->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->TextBoxServer->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12));
			this->TextBoxServer->Location = System::Drawing::Point(360, 101);
			this->TextBoxServer->Name = L"TextBoxServer";
			this->TextBoxServer->Size = System::Drawing::Size(204, 29);
			this->TextBoxServer->TabIndex = 9;
			// 
			// comboBox1
			// 
			this->comboBox1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"MS SQL", L"Oracle" });
			this->comboBox1->Location = System::Drawing::Point(132, 101);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(198, 29);
			this->comboBox1->TabIndex = 7;
			// 
			// ButtonConnect
			// 
			this->ButtonConnect->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->ButtonConnect->BackColor = System::Drawing::Color::SkyBlue;
			this->ButtonConnect->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->ButtonConnect->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12));
			this->ButtonConnect->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ButtonConnect->Location = System::Drawing::Point(591, 181);
			this->ButtonConnect->Name = L"ButtonConnect";
			this->ButtonConnect->Size = System::Drawing::Size(204, 32);
			this->ButtonConnect->TabIndex = 6;
			this->ButtonConnect->Text = L"Подключиться";
			this->ButtonConnect->UseVisualStyleBackColor = false;
			this->ButtonConnect->Click += gcnew System::EventHandler(this, &MyForm::connect1_Click);
			// 
			// labelPassword
			// 
			this->labelPassword->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->labelPassword->AutoSize = true;
			this->labelPassword->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelPassword->Location = System::Drawing::Point(356, 146);
			this->labelPassword->Name = L"labelPassword";
			this->labelPassword->Size = System::Drawing::Size(73, 21);
			this->labelPassword->TabIndex = 5;
			this->labelPassword->Text = L"Пароль:";
			// 
			// labelUser
			// 
			this->labelUser->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->labelUser->AutoSize = true;
			this->labelUser->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12));
			this->labelUser->Location = System::Drawing::Point(128, 146);
			this->labelUser->Name = L"labelUser";
			this->labelUser->Size = System::Drawing::Size(124, 21);
			this->labelUser->TabIndex = 4;
			this->labelUser->Text = L"Пользователь:";
			// 
			// labelServer
			// 
			this->labelServer->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->labelServer->AutoSize = true;
			this->labelServer->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12));
			this->labelServer->Location = System::Drawing::Point(356, 68);
			this->labelServer->Name = L"labelServer";
			this->labelServer->Size = System::Drawing::Size(72, 21);
			this->labelServer->TabIndex = 3;
			this->labelServer->Text = L"Сервер:";
			// 
			// SUBD
			// 
			this->SUBD->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->SUBD->AutoSize = true;
			this->SUBD->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->SUBD->Location = System::Drawing::Point(128, 68);
			this->SUBD->Name = L"SUBD";
			this->SUBD->Size = System::Drawing::Size(57, 21);
			this->SUBD->TabIndex = 1;
			this->SUBD->Text = L"СУБД:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold));
			this->label1->Location = System::Drawing::Point(57, 10);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(618, 31);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Подключение к БД1(Для получения данных)";
			// 
			// panel2
			// 
			this->panel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel2->BackColor = System::Drawing::Color::White;
			this->panel2->Controls->Add(this->pictureBox1);
			this->panel2->Controls->Add(this->label3);
			this->panel2->Location = System::Drawing::Point(0, -1);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(984, 69);
			this->panel2->TabIndex = 1;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(29, 13);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(34, 40);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(58, 12);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(404, 31);
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
			this->panel3->Location = System::Drawing::Point(0, 342);
			this->panel3->MaximumSize = System::Drawing::Size(1000, 400);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(984, 70);
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
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(12, 11);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(56, 16);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Статус:";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(249)), static_cast<System::Int32>(static_cast<System::Byte>(250)),
				static_cast<System::Int32>(static_cast<System::Byte>(249)));
			this->ClientSize = System::Drawing::Size(984, 411);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1000, 450);
			this->MinimumSize = System::Drawing::Size(1000, 450);
			this->Name = L"MyForm";
			this->Text = L"Operational-database-recovery";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
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
		MessageTextConnect->Text = L"Выберите используемую СУБД ";
		return;
	}
	if (TypeSUBD == L"MS SQL") {
		String^ connect = "Server=" + TextBoxServer->Text + "LEVEL2; Database = " + TextBoxDataBase->Text + "; User Id =" + TextBoxUser->Text + "; Password = " + TextBoxPassword->Text + ";";
		SqlConnection^ sql_connect = gcnew SqlConnection(connect);
		try {
			sql_connect->Open();
			if (sql_connect->State != ConnectionState::Open) {
				MessageTextConnect->Font = gcnew System::Drawing::Font("Microsoft Sans Serif", 10.25);
				MessageTextConnect->ForeColor = Color::Red;
				MessageTextConnect->Text = L"Ошибка подключения к " + TextBoxDataBase->Text;
				return;
			}
			MessageTextConnect->Font = gcnew System::Drawing::Font("Microsoft Sans Serif", 10.25);
			MessageTextConnect->ForeColor = Color::Green;
			MessageTextConnect->Text = L"Подключено успоешно к " + TextBoxDataBase->Text;
		}
		catch (Exception^ ex) {
			MessageTextConnect->Font = gcnew System::Drawing::Font("Microsoft Sans Serif", 10.25);
			MessageTextConnect->ForeColor = Color::Red;
			MessageTextConnect->Text = L"Ошибка! Проверьте правильность введеных вами полей!";
		}
		finally {
			if (sql_connect->State == ConnectionState::Open) {
				sql_connect->Close();
			}
		}
	}
}

};
}