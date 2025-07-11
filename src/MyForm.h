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
	protected:
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ Password;

	private: System::Windows::Forms::TextBox^ User;
	private: System::Windows::Forms::TextBox^ DataBase;





	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ MessageTextConnect;

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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->Password = (gcnew System::Windows::Forms::TextBox());
			this->User = (gcnew System::Windows::Forms::TextBox());
			this->DataBase = (gcnew System::Windows::Forms::TextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->MessageTextConnect = (gcnew System::Windows::Forms::TextBox());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->MessageTextConnect);
			this->panel1->Controls->Add(this->Password);
			this->panel1->Controls->Add(this->User);
			this->panel1->Controls->Add(this->DataBase);
			this->panel1->Controls->Add(this->comboBox1);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(699, 429);
			this->panel1->TabIndex = 0;
			// 
			// Password
			// 
			this->Password->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12));
			this->Password->Location = System::Drawing::Point(443, 210);
			this->Password->Name = L"Password";
			this->Password->Size = System::Drawing::Size(178, 29);
			this->Password->TabIndex = 11;
			// 
			// User
			// 
			this->User->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12));
			this->User->Location = System::Drawing::Point(443, 165);
			this->User->Name = L"User";
			this->User->Size = System::Drawing::Size(178, 29);
			this->User->TabIndex = 10;
			// 
			// DataBase
			// 
			this->DataBase->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12));
			this->DataBase->Location = System::Drawing::Point(443, 120);
			this->DataBase->Name = L"DataBase";
			this->DataBase->Size = System::Drawing::Size(178, 29);
			this->DataBase->TabIndex = 9;
			// 
			// comboBox1
			// 
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"MS SQL", L"Oracle" });
			this->comboBox1->Location = System::Drawing::Point(443, 77);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(178, 29);
			this->comboBox1->TabIndex = 7;
			this->comboBox1->Text = L"MS SQL";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12));
			this->button1->Location = System::Drawing::Point(267, 284);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(145, 32);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Подключиться";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(115, 210);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(73, 21);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Пароль:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12));
			this->label5->Location = System::Drawing::Point(115, 168);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(124, 21);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Пользователь:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12));
			this->label4->Location = System::Drawing::Point(115, 120);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(114, 21);
			this->label4->TabIndex = 3;
			this->label4->Text = L"База данных:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(115, 77);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(57, 21);
			this->label2->TabIndex = 1;
			this->label2->Text = L"СУБД:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(260, 10);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(152, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Подключение к БД";
			// 
			// MessageTextConnect
			// 
			this->MessageTextConnect->Location = System::Drawing::Point(188, 346);
			this->MessageTextConnect->Name = L"MessageTextConnect";
			this->MessageTextConnect->Size = System::Drawing::Size(296, 20);
			this->MessageTextConnect->TabIndex = 12;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(723, 453);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm";
			this->Text = L"Operational-database-recovery";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ db = "";
	if (comboBox1->Text == L"MS SQL") {
		db = "AEIP6L2S\\";
	}
	String^ connect = "Server=" + comboBox1->Text + "LEVEL2; Database = " + DataBase->Text + "; User Id =" + User->Text + "; Password = " + Password->Text + ";";
	SqlConnection^ sql_connect = gcnew SqlConnection(connect);
	try {
		sql_connect->Open();
		if (sql_connect->State != ConnectionState::Open){
			MessageTextConnect->Text = L"Ошибка подключения к " + DataBase->Text;
			return;
		}
		MessageTextConnect->Text = L"Подключено успоешно к " + DataBase->Text;
	}
	catch (Exception^ ex) {
		MessageTextConnect->Text = L"Ошибка! Вызвано исключение " + ex->Message;
	}
	finally {
		if (sql_connect->State == ConnectionState::Open) {
			sql_connect->Close();
		}
	}
}
};
}
