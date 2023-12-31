#pragma once
#include "cargarArchivo.h"
#include <string>

#include "ventanaPopupRestaurantes2.h"
#include "ventanaPopupMenu.h"
#include "ventanaPopupProductos.h"

namespace Interfaz {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ventanaPopupRestaurantes
	/// </summary>
	public ref class ventanaPopupRestaurantes : public System::Windows::Forms::Form
	{
	public:
		cargarArchivo* progra;
	private: System::Windows::Forms::Button^ button5;
	public:
		bool^ flag;
		ventanaPopupRestaurantes(cargarArchivo* progra, bool^ flag)
		{
			this->flag = flag;
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
		~ventanaPopupRestaurantes()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::Label^ label4;
	protected:
	public: System::Windows::Forms::Button^ button3;
	public: System::Windows::Forms::Label^ label1;
	public: System::Windows::Forms::Button^ button1;
	public: System::Windows::Forms::Label^ label2;
	public: System::Windows::Forms::Button^ button2;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		
		ventanaPopupRestaurantes2^ popupRestaurantes;
		ventanaPopupMenu^ popupMenu;
		ventanaPopupProductos^ popupProductos;


		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ventanaPopupRestaurantes::typeid));
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(22, 121);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(95, 13);
			this->label4->TabIndex = 10;
			this->label4->Text = L"RESTAURANTES";
			this->label4->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// button3
			// 
			this->button3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.BackgroundImage")));
			this->button3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button3->Location = System::Drawing::Point(25, 29);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(85, 85);
			this->button3->TabIndex = 9;
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &ventanaPopupRestaurantes::button3_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(149, 121);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(39, 13);
			this->label1->TabIndex = 12;
			this->label1->Text = L"MENU";
			this->label1->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// button1
			// 
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button1->Location = System::Drawing::Point(125, 29);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(85, 85);
			this->button1->TabIndex = 11;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ventanaPopupRestaurantes::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(236, 121);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(75, 13);
			this->label2->TabIndex = 14;
			this->label2->Text = L"PRODUCTOS";
			this->label2->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// button2
			// 
			this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.BackgroundImage")));
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button2->Location = System::Drawing::Point(226, 29);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(85, 85);
			this->button2->TabIndex = 13;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ventanaPopupRestaurantes::button2_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(135, 162);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 25;
			this->button5->Text = L"Cancelar";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &ventanaPopupRestaurantes::button5_Click);
			// 
			// ventanaPopupRestaurantes
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(344, 197);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button3);
			this->Name = L"ventanaPopupRestaurantes";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Restaurantes";
			this->Load += gcnew System::EventHandler(this, &ventanaPopupRestaurantes::ventanaPopupRestaurantes_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ventanaPopupRestaurantes_Load(System::Object^ sender, System::EventArgs^ e) {
	}


	private: System::Void ventanaPopupRestaurantes2_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
		// Check if ventanaEliminarPais is disposed before accessing it
		if (popupRestaurantes != nullptr && !popupRestaurantes->IsDisposed) {
			// Unsubscribe events
			popupRestaurantes->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaPopupRestaurantes::ventanaPopupRestaurantes2_FormClosed);
			// Show the ventanaPrincipal form when EliminarPais is closed
		}
		this->Show();
	}

	private: System::Void ventanaPopupMenu_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
		// Check if ventanaEliminarPais is disposed before accessing it
		if (popupMenu != nullptr && !popupMenu->IsDisposed) {
			// Unsubscribe events
			popupMenu->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaPopupRestaurantes::ventanaPopupMenu_FormClosed);
			// Show the ventanaPrincipal form when EliminarPais is closed
		}
		this->Show();
	}


	private: System::Void ventanaPopupProductos_FormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
		// Check if ventanaEliminarPais is disposed before accessing it
		if (popupProductos != nullptr && !popupProductos->IsDisposed) {
			// Unsubscribe events
			popupProductos->FormClosed -= gcnew FormClosedEventHandler(this, &ventanaPopupRestaurantes::ventanaPopupProductos_FormClosed);
			// Show the ventanaPrincipal form when EliminarPais is closed
		}
		this->Show();
	}



	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		//Restaurantes
		if(*flag == true){
			popupRestaurantes = gcnew ventanaPopupRestaurantes2(progra, flag);
			popupRestaurantes->FormClosed += gcnew FormClosedEventHandler(this, &ventanaPopupRestaurantes::ventanaPopupRestaurantes2_FormClosed);
			popupRestaurantes->Show();
		}
		else {
			popupRestaurantes = gcnew ventanaPopupRestaurantes2(progra, flag);
			popupRestaurantes->button1->Enabled = false;
			popupRestaurantes->button3->Enabled = false;
			popupRestaurantes->button4->Enabled = false;
			popupRestaurantes->FormClosed += gcnew FormClosedEventHandler(this, &ventanaPopupRestaurantes::ventanaPopupRestaurantes2_FormClosed);
			popupRestaurantes->Show();
		}
		this->Hide();
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		//Menu
		if (*flag == true) {
			popupMenu = gcnew ventanaPopupMenu(progra, flag);
			popupMenu->FormClosed += gcnew FormClosedEventHandler(this, &ventanaPopupRestaurantes::ventanaPopupMenu_FormClosed);
			popupMenu->Show();
		}
		else {
			popupMenu = gcnew ventanaPopupMenu(progra, flag);
			popupMenu->button1->Enabled = false;
			popupMenu->button3->Enabled = false;
			popupMenu->button4->Enabled = false;
			popupMenu->FormClosed += gcnew FormClosedEventHandler(this, &ventanaPopupRestaurantes::ventanaPopupMenu_FormClosed);
			popupMenu->Show();
		}
		this->Hide();

	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		//Productos
		if (*flag == true) {
			popupProductos = gcnew ventanaPopupProductos(progra, flag);
			popupProductos->FormClosed += gcnew FormClosedEventHandler(this, &ventanaPopupRestaurantes::ventanaPopupProductos_FormClosed);
			popupProductos->Show();
		}
		else {
			popupProductos = gcnew ventanaPopupProductos(progra, flag);
			popupProductos->button1->Enabled = false;
			popupProductos->button3->Enabled = false;
			popupProductos->button4->Enabled = false;
			popupProductos->FormClosed += gcnew FormClosedEventHandler(this, &ventanaPopupRestaurantes::ventanaPopupProductos_FormClosed);
			popupProductos->Show();
		}
		this->Hide();
	}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}
