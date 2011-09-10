#pragma once


#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <time.h>
#include <vcclr.h> // Necesario para funcion To_string()


extern System::String^ WhoCalledMe();

cv::Mat frame; // Cada frame capturado // TODO: SÁCAME DE AQUIIIIIIIII

namespace TimeLapser {

	using namespace System;
	using namespace System::Configuration;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Resumen de Form1
	///
	/// ADVERTENCIA: si cambia el nombre de esta clase, deberá cambiar la
	///          propiedad 'Nombre de archivos de recursos' de la herramienta de compilación de recursos administrados
	///          asociada con todos los archivos .resx de los que depende esta clase. De lo contrario,
	///          los diseñadores no podrán interactuar correctamente con los
	///          recursos adaptados asociados con este formulario.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén utilizando.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TrackBar^  trackBar1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;

	private: cv::VideoCapture* webcam;
	private: System::Windows::Forms::Button^  bEmpezar;
	private: System::Windows::Forms::Button^  bDetener;


	private: bool mostrar;
	private: System::String^ Version;
	private: System::Windows::Forms::Button^  bCrearVideo;
	private: System::Windows::Forms::TextBox^  textBoxDestino;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  buttonExaminarDestino;

	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBoxVideoFilename;

	private: System::Windows::Forms::TextBox^  textBoxFileName;
	private: System::Windows::Forms::Button^  buttonAplicar;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  ayudaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  acercaDeTimeLapserToolStripMenuItem;



	protected: 

	private:
		/// <summary>
		/// Variable del diseñador requerida.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido del método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->bEmpezar = (gcnew System::Windows::Forms::Button());
			this->bDetener = (gcnew System::Windows::Forms::Button());
			this->bCrearVideo = (gcnew System::Windows::Forms::Button());
			this->textBoxDestino = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->buttonExaminarDestino = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->buttonAplicar = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBoxVideoFilename = (gcnew System::Windows::Forms::TextBox());
			this->textBoxFileName = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->ayudaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->acercaDeTimeLapserToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// trackBar1
			// 
			this->trackBar1->Cursor = System::Windows::Forms::Cursors::SizeWE;
			this->trackBar1->Location = System::Drawing::Point(12, 231);
			this->trackBar1->Maximum = 120;
			this->trackBar1->Minimum = 1;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(394, 45);
			this->trackBar1->TabIndex = 0;
			this->trackBar1->Value = 1;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &Form1::trackBar1_Scroll);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 212);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(122, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Intervalo entre capturas:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(145, 212);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(13, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"1 s";
			// 
			// bEmpezar
			// 
			this->bEmpezar->Location = System::Drawing::Point(12, 284);
			this->bEmpezar->Name = L"bEmpezar";
			this->bEmpezar->Size = System::Drawing::Size(75, 23);
			this->bEmpezar->TabIndex = 3;
			this->bEmpezar->Text = L"&Empezar";
			this->bEmpezar->UseVisualStyleBackColor = true;
			this->bEmpezar->Click += gcnew System::EventHandler(this, &Form1::bEmpezar_Click);
			// 
			// bDetener
			// 
			this->bDetener->Enabled = false;
			this->bDetener->Location = System::Drawing::Point(108, 284);
			this->bDetener->Name = L"bDetener";
			this->bDetener->Size = System::Drawing::Size(75, 23);
			this->bDetener->TabIndex = 4;
			this->bDetener->Text = L"&Detener";
			this->bDetener->UseVisualStyleBackColor = true;
			this->bDetener->Click += gcnew System::EventHandler(this, &Form1::bDetener_Click);
			// 
			// bCrearVideo
			// 
			this->bCrearVideo->Location = System::Drawing::Point(292, 282);
			this->bCrearVideo->Name = L"bCrearVideo";
			this->bCrearVideo->Size = System::Drawing::Size(75, 23);
			this->bCrearVideo->TabIndex = 5;
			this->bCrearVideo->Text = L"Crear &Vídeo";
			this->bCrearVideo->UseVisualStyleBackColor = true;
			this->bCrearVideo->Click += gcnew System::EventHandler(this, &Form1::bCrearVideo_Click);
			// 
			// textBoxDestino
			// 
			this->textBoxDestino->Location = System::Drawing::Point(96, 22);
			this->textBoxDestino->Name = L"textBoxDestino";
			this->textBoxDestino->Size = System::Drawing::Size(259, 20);
			this->textBoxDestino->TabIndex = 6;
			this->textBoxDestino->TextChanged += gcnew System::EventHandler(this, &Form1::textBox_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 25);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(84, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Carpeta destino:";
			// 
			// buttonExaminarDestino
			// 
			this->buttonExaminarDestino->Location = System::Drawing::Point(361, 20);
			this->buttonExaminarDestino->Name = L"buttonExaminarDestino";
			this->buttonExaminarDestino->Size = System::Drawing::Size(24, 23);
			this->buttonExaminarDestino->TabIndex = 8;
			this->buttonExaminarDestino->Text = L"...";
			this->buttonExaminarDestino->UseVisualStyleBackColor = true;
			this->buttonExaminarDestino->Click += gcnew System::EventHandler(this, &Form1::buttonExaminarDestino_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->buttonAplicar);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->buttonExaminarDestino);
			this->groupBox1->Controls->Add(this->textBoxVideoFilename);
			this->groupBox1->Controls->Add(this->textBoxFileName);
			this->groupBox1->Controls->Add(this->textBoxDestino);
			this->groupBox1->Location = System::Drawing::Point(12, 32);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(394, 165);
			this->groupBox1->TabIndex = 9;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Rutas";
			// 
			// buttonAplicar
			// 
			this->buttonAplicar->Enabled = false;
			this->buttonAplicar->Location = System::Drawing::Point(280, 128);
			this->buttonAplicar->Name = L"buttonAplicar";
			this->buttonAplicar->Size = System::Drawing::Size(75, 23);
			this->buttonAplicar->TabIndex = 9;
			this->buttonAplicar->Text = L"&Aplicar";
			this->buttonAplicar->UseVisualStyleBackColor = true;
			this->buttonAplicar->Click += gcnew System::EventHandler(this, &Form1::buttonAplicar_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(6, 96);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(146, 13);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Nombre de archivo de vídeo:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(6, 61);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(105, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Nombre de archivos:";
			// 
			// textBoxVideoFilename
			// 
			this->textBoxVideoFilename->Location = System::Drawing::Point(158, 93);
			this->textBoxVideoFilename->Name = L"textBoxVideoFilename";
			this->textBoxVideoFilename->Size = System::Drawing::Size(197, 20);
			this->textBoxVideoFilename->TabIndex = 6;
			this->textBoxVideoFilename->TextChanged += gcnew System::EventHandler(this, &Form1::textBox_TextChanged);
			// 
			// textBoxFileName
			// 
			this->textBoxFileName->Location = System::Drawing::Point(117, 58);
			this->textBoxFileName->Name = L"textBoxFileName";
			this->textBoxFileName->Size = System::Drawing::Size(238, 20);
			this->textBoxFileName->TabIndex = 6;
			this->textBoxFileName->TextChanged += gcnew System::EventHandler(this, &Form1::textBox_TextChanged);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->ayudaToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->menuStrip1->Size = System::Drawing::Size(414, 24);
			this->menuStrip1->TabIndex = 10;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ayudaToolStripMenuItem
			// 
			this->ayudaToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->acercaDeTimeLapserToolStripMenuItem});
			this->ayudaToolStripMenuItem->Name = L"ayudaToolStripMenuItem";
			this->ayudaToolStripMenuItem->Padding = System::Windows::Forms::Padding(4, 0, 25, 0);
			this->ayudaToolStripMenuItem->Size = System::Drawing::Size(74, 20);
			this->ayudaToolStripMenuItem->Text = L"Ayuda";
			// 
			// acercaDeTimeLapserToolStripMenuItem
			// 
			this->acercaDeTimeLapserToolStripMenuItem->Name = L"acercaDeTimeLapserToolStripMenuItem";
			this->acercaDeTimeLapserToolStripMenuItem->Size = System::Drawing::Size(218, 22);
			this->acercaDeTimeLapserToolStripMenuItem->Text = L"Acerca de TimeLapser 1.1 b";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(414, 319);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->bCrearVideo);
			this->Controls->Add(this->bDetener);
			this->Controls->Add(this->bEmpezar);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Timelapser 1.1 b";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Form1::Form1_FormClosed);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

/* Para guardar la imagen capturada tenemos que convertir "ruta" en std::string
 * Esto es un requisito de la libreria OpenCV 2.3
 */
bool To_string( String^ source, std::string &target ){
    pin_ptr<const wchar_t> wch = PtrToStringChars( source );
    int len = (( source->Length+1) * 2);
    char *ch = new char[ len ];
    bool result = wcstombs( ch, wch, len ) != -1;
    target = ch;
    delete ch;
    return result;
}


	private: System::Void trackBar1_Scroll(System::Object^  sender, System::EventArgs^  e) {
				 this->label2->Text = System::Convert::ToString(this->trackBar1->Value) + " s";
			 }

	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 this->webcam = new cv::VideoCapture();
				 this->mostrar = false;
				 this->textBoxDestino->Text = ConfigurationSettings::AppSettings["outputDir"]->ToString();
				 this->textBoxFileName->Text = ConfigurationSettings::AppSettings["imageFileName"]->ToString();
				 this->textBoxVideoFilename->Text = ConfigurationSettings::AppSettings["videoFileName"]->ToString();
				 this->buttonAplicar->Enabled = false;
			 }

private: System::Void bEmpezar_Click(System::Object^  sender, System::EventArgs^  e) {
				 //cv::Mat frame; // Cada frame capturado
				 cv::namedWindow("Live", 1); // Ventana que muestra los frames leidos de this->webcam
				 clock_t start, finish; // Variables para calcular el tiempo transcurrido entre capturas
				 double duration;		// IDEM
				 String^ rutabase = ConfigurationSettings::AppSettings["outputDir"]->ToString() + ConfigurationSettings::AppSettings["imageFileName"]->ToString();
				 String^ ruta = rutabase;
				 std::string aux; // Almacena el contenido de "ruta" pero como un std::string
				 unsigned int i = 0;

				 this->bEmpezar->Enabled = false;
				 this->bCrearVideo->Enabled = false;
				 this->bDetener->Enabled = true;
				 this->mostrar = true;
				 try{
					this->webcam->open(0); // Activar webcam
					start = clock();
				 } catch (Exception^ e) {
					Windows::Forms::MessageBox::Show("["+WhoCalledMe()+"]: " + e->Message->ToString());
				 }
				 while(this->mostrar == true){ // Bucle de captura y muestra de frames
					 (*this->webcam) >> frame; // Obtenemos el frame desde this->webcam
					 if (!frame.data)
						 break; // Sino se obtuvo ningun dato, detenemos el bucle
					 finish = clock(); // Obtenemos la hora, para calcular tiempo entre captura y captura
					 duration = (double)(finish - start) / CLOCKS_PER_SEC; // Diferencia entre start y finish
					 cv::imshow("Live", frame); // Mostramos la imagen en la ventana "Live"
					 if (duration >= this->trackBar1->Value){ // Si ha pasado el tiempo especificado, capturamos
						 ruta += System::Convert::ToString(i);
						 ruta += ".jpg";
						 To_string(ruta, aux); // Para guardar la imagen capturada tenemos que convertir "ruta" en std::string
						 cv::imwrite(aux, frame); // Guardamos el frame en la ruta "aux"
						 i++;
						 ruta = rutabase; // Reseteamos el valor de "ruta"
						 start = clock(); // Reiniciamos la cuenta de tiempo
					 }
					 cv::waitKey(1);
				 }
				 this->bEmpezar->Enabled = true;
				 this->bCrearVideo->Enabled = true;
				 this->bDetener->Enabled = false;
		 }

		 /* *************************************************************
		 * TODO: Las dos siguientes funciones hacen lo mismo exactamente
		 ****************************************************************/
private: System::Void bDetener_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->webcam->release();
			 this->mostrar = false;
			 cv::destroyWindow("Live");
		 }

/* Form1_FormClosed
 * Pone a "false" la variable 'mostrar', con lo que se dentiene el bucle de muestra/captura de fotogramas
 * Libera a la webcam
 * Elimina la 'cv::namedWindow' "Live" 
 */
private: System::Void Form1_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
			 this->mostrar = false;
			 this->webcam->release();
			 cv::destroyWindow("Live");
		 }

/* bCrearVideo_Click
 * Ejecuta el proceso ffmpeg para crear el video a partir de las capturas
 */
private: System::Void bCrearVideo_Click(System::Object^  sender, System::EventArgs^  e) {
			 String^ ffmpeg = ConfigurationSettings::AppSettings["ffmpeg"]->ToString();
			 String^ capPath = ConfigurationSettings::AppSettings["outputDir"]->ToString() + ConfigurationSettings::AppSettings["imageFileName"]->ToString();
			 String^ videoPath = ConfigurationSettings::AppSettings["outputDir"]->ToString() + ConfigurationSettings::AppSettings["videoFileName"]->ToString();
			 //String^ parametros = "-f image2 -i " + capPath + "%d.jpg " + videoPath;
			 //String^ parametros = "-f image2 -r 24 -b 1800 -i " + capPath + "%d.jpg -vcodec libx264 " + videoPath;
			 String^ parametros = "-f image2 -i " + capPath + "%d.jpg -r 24 -b 1800 -vcodec copy " + videoPath;
			 try{
				 System::Diagnostics::Process::Start(ffmpeg, parametros);
			 } catch (Exception^ e) {
				 Windows::Forms::MessageBox::Show("["+WhoCalledMe()+"]: " + e->Message->ToString());
			 }
		 }

/* buttonExaminarDestino_Click
 * Crea un 'FolderBrowserDialog' que se abrira por defecto en la ruta "outputDir"
 * Carga la ruta seleccionada en textBoxDestino añadiendole el caracter "\" al final si es necesario
 */
private: System::Void buttonExaminarDestino_Click(System::Object^  sender, System::EventArgs^  e) {
			 FolderBrowserDialog^ folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());

			 folderBrowserDialog1->ShowNewFolderButton = true;
			 folderBrowserDialog1->SelectedPath = ConfigurationSettings::AppSettings["outputDir"]->ToString();
			 folderBrowserDialog1->ShowDialog();
			 this->textBoxDestino->Text = folderBrowserDialog1->SelectedPath;
			 if (!this->textBoxDestino->Text->EndsWith("\\"))
				 this->textBoxDestino->Text += "\\";
			 
		 }

/* buttonAplicar_Click
 * Comprueba que textBoxDestino finalice con el caracter "\"
 * Persiste los cambios tanto en el fichero de configuracion como en aps->Settings
 * Deshabilita buttonAplicar
 */
private: System::Void buttonAplicar_Click(System::Object^  sender, System::EventArgs^  e) {
			 System::Configuration::Configuration^ config = System::Configuration::ConfigurationManager::OpenExeConfiguration(Application::ExecutablePath);
			 System::Configuration::AppSettingsSection^ aps = config->AppSettings;
			 String^ Destino = this->textBoxDestino->Text;

			 if (!this->textBoxDestino->Text->EndsWith("\\"))
				 Destino += "\\";
			 try{
			    // Cambios en el aps->Settings
				aps->Settings["outputDir"]->Value =  Destino;
				aps->Settings["imageFileName"]->Value = this->textBoxFileName->Text;
				aps->Settings["videoFileName"]->Value = this->textBoxVideoFilename->Text;
				// Cambios en el fichero de configuracion
				ConfigurationSettings::AppSettings["outputDir"] = Destino;
				ConfigurationSettings::AppSettings["imageFileName"] = this->textBoxFileName->Text;
				ConfigurationSettings::AppSettings["videoFileName"] = this->textBoxVideoFilename->Text;
				// Persistir los cambios
				aps->SectionInformation->ForceSave = true;
				config->Save(ConfigurationSaveMode::Full);
			 } catch (Exception^ e) {
				 Windows::Forms::MessageBox::Show("["+WhoCalledMe()+"]: " + e->Message->ToString());
			 }
			 this->buttonAplicar->Enabled = false;
		 }

/* textBox_TextChanged
 * Se encarga de habilitar buttonAplicar cuando se cambia el contenido de cualquier textBox del formulario
 */
private: System::Void textBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 this->buttonAplicar->Enabled = true;
		 }
};
}

