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
	/// Summary for ventanaEliminarCliente
	/// </summary>
	public ref class ventanaEliminarCliente : public System::Windows::Forms::Form
	{
	public:
		cargarArchivo* progra;
		ventanaEliminarCliente(cargarArchivo* progra)
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
		~ventanaEliminarCliente()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button2;
	protected:
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::TextBox^ textBox1;

	private: System::Windows::Forms::Label^ label1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(180, 74);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Cancelar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ventanaEliminarCliente::button2_Click);
			// 
			// button1
			// 
			this->button1->AutoSize = true;
			this->button1->Location = System::Drawing::Point(63, 75);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Eliminar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ventanaEliminarCliente::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(148, 27);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(167, 20);
			this->textBox1->TabIndex = 8;
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
			// ventanaEliminarCliente
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(330, 108);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"ventanaEliminarCliente";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Eliminar Cliente";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		// Obtener texto de textBox and EliminarCliente
		String^ codStrCedula = textBox1->Text;

		// Check if the strings are not empty
		if (!String::IsNullOrWhiteSpace(codStrCedula)) {
			int temp;
			Int32::TryParse(codStrCedula, temp);
			std::string adminInfoStdString = progra->listaCliente->SearchNodo(temp, progra->listaCliente->raiz);
			String^ adminInfo = gcnew String(adminInfoStdString.c_str());

			//INICIO CODIGO
			if (progra->listaCliente->SearchNodo(temp, progra->listaCliente->raiz) != "") {
				progra->listaCliente->Eliminar(temp, progra->listaCliente->raiz);
				this->Close();
				System::Windows::Forms::DialogResult SelectUSER = MessageBox::Show(
					"Cedula: " + temp + "\nNombre: " + adminInfo,
					"Cliente Eliminado",
					MessageBoxButtons::OK,
					MessageBoxIcon::Information);
			}
			else {
				System::Windows::Forms::DialogResult SelectUSER = MessageBox::Show(
					"Cedula: " + temp,
					"Cliente No Encontrado",
					MessageBoxButtons::OK,
					MessageBoxIcon::Warning);
			}
			//FIN CODIGO();
		}
		else {
			// Handle empty input in textBox1 or textBox2
			// Display an error message or take appropriate action
		}
		// cerrar ventana
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
};
}
