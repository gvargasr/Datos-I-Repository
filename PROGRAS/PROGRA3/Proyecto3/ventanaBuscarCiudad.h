#pragma once
#include "cargarArchivo.h"
#include <string>

namespace Interfaz {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ventanaBuscarCiudad
	/// </summary>
	public ref class ventanaBuscarCiudad : public System::Windows::Forms::Form
	{
	public:
		cargarArchivo* progra;
		ventanaBuscarCiudad(cargarArchivo* progra)
		{
			this->progra = progra;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ventanaBuscarCiudad()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button2;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;

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
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(177, 88);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 17;
			this->button2->Text = L"Cancelar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ventanaBuscarCiudad::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(60, 89);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 16;
			this->button1->Text = L"Buscar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ventanaBuscarCiudad::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(144, 49);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(167, 20);
			this->textBox2->TabIndex = 15;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &ventanaBuscarCiudad::textBox2_TextChanged);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(143, 16);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(167, 20);
			this->textBox1->TabIndex = 14;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &ventanaBuscarCiudad::textBox1_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 56);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(123, 13);
			this->label2->TabIndex = 13;
			this->label2->Text = L"Digite codigo de Ciudad:";
			this->label2->Click += gcnew System::EventHandler(this, &ventanaBuscarCiudad::label2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(110, 13);
			this->label1->TabIndex = 12;
			this->label1->Text = L"Digite codigo de Pais:";
			this->label1->Click += gcnew System::EventHandler(this, &ventanaBuscarCiudad::label1_Click);
			// 
			// ventanaBuscarCiudad
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(331, 126);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"ventanaBuscarCiudad";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Buscar Ciudad";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		// Obtener texto de textBox and BuscarCiudad
		String^ codStrPais = textBox1->Text;
		String^ codStrCiudad = textBox2->Text;

		// Check if the strings are not empty
		if (!String::IsNullOrWhiteSpace(codStrPais) && !String::IsNullOrWhiteSpace(codStrCiudad)) {
			int temp;
			int temp2;
			Int32::TryParse(codStrPais, temp);
			Int32::TryParse(codStrCiudad, temp2);
			NodoBinarioPais* aux = progra->listaPais->BuscarPais(progra->listaPais->raiz, temp);
			if (aux != NULL) {
				NodoBinarioCiudad* aux2 = aux->ArbolCiudad.BuscarCiudad(aux->ArbolCiudad.raiz, temp2);
				if (aux2 != NULL) {
					std::string adminInfoStdString = aux2->ciudad;
					String^ adminInfo = gcnew String(adminInfoStdString.c_str());
					System::Windows::Forms::DialogResult SelectUSER = MessageBox::Show(
						"Codigo: " + temp2 + "\nCiudad: " + adminInfo,
						"Ciudad Encontrada",
						MessageBoxButtons::OK,
						MessageBoxIcon::Information);
					cout << "\n.:Ciudad encontrada:.\nCodigo Pais: " << aux2->ciudad << "\nCodigo Ciudad: " << temp2 << "\nNombre: " << aux2->ciudad << endl;
				}
				else {
					System::Windows::Forms::DialogResult SelectUSER = MessageBox::Show(
						"Codigo: " + temp2,
						"Ciudad No Encontrada",
						MessageBoxButtons::OK,
						MessageBoxIcon::Error);
					cout << "La ciudad " << temp2 << " no se encuentra" << endl;
				}
				this->Close();
			}
			else {
				System::Windows::Forms::DialogResult SelectUSER = MessageBox::Show(
					"Codigo: " + temp2,
					"Ciudad No Encontrada",
					MessageBoxButtons::OK,
					MessageBoxIcon::Error);
				cout << "La ciudad " << temp2 << " no se encuentra" << endl;
				this->Close();
			}
		}
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
