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
	/// Summary for ventanaInsertarCliente
	/// </summary>
	public ref class ventanaInsertarCliente : public System::Windows::Forms::Form
	{
	public:
		cargarArchivo* progra;
		ventanaInsertarCliente(cargarArchivo* progra)
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
		~ventanaInsertarCliente()
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
			this->button2->Location = System::Drawing::Point(179, 102);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Cancelar";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(62, 103);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Aceptar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ventanaInsertarCliente::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(148, 66);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(167, 20);
			this->textBox2->TabIndex = 9;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(148, 27);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(167, 20);
			this->textBox1->TabIndex = 8;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(16, 73);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(124, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Digite nombre de cliente:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(17, 35);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(121, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Digite cedula de cliente:";
			// 
			// ventanaInsertarCliente
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(331, 152);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"ventanaInsertarCliente";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Agregar Cliente";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		// Obtener texto de textBox and Insertar Producto
		String^ codStrCedula = textBox1->Text;
		String^ codStrNombre = textBox2->Text;



		// Check if the strings are not empty
		if (!String::IsNullOrWhiteSpace(codStrCedula) && !String::IsNullOrWhiteSpace(codStrCedula)) {
			int temp;

			Int32::TryParse(codStrCedula, temp);


			char cStr[50] = { 0 };
			String^ clrString = codStrNombre;
			sprintf_s(cStr, "%s", clrString);
			std::string stlString(cStr);
			//INICIO CODIGO
			if (progra->listaCliente->Search(temp, progra->listaCliente->raiz) == false) {
				progra->listaCliente->InsertarClave(temp, cStr, progra->listaCliente->raiz);
				System::Windows::Forms::DialogResult SelectUSER = MessageBox::Show(
					"Codigo: " + temp + "\nNombre: " + codStrNombre,
					"Cliente agregado.",
					MessageBoxButtons::OK,
					MessageBoxIcon::Information);
				this->Close();
			}
			else {
				System::Windows::Forms::DialogResult SelectUSER = MessageBox::Show(
					"Codigo: " + temp + " ya existe",
					"Error .",
					MessageBoxButtons::OK,
					MessageBoxIcon::Information);
			}			//FIN CODIGO();
		}
		else {
			// Handle empty input in textBox1 or textBox2
			// Display an error message or take appropriate action
		}
		// cerrar ventana
		
	}
};
}
