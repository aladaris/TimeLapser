// TimeLapser.cpp: archivo de proyecto principal.

#include "stdafx.h"
#include "Form1.h"

using namespace TimeLapser;

/*
	Devuelve el nombre de la funcion que invoca a esta funcion
*/
System::String^ WhoCalledMe(){
	System::Diagnostics::StackTrace^ st = gcnew System::Diagnostics::StackTrace();
	System::Diagnostics::StackFrame^ sf = st->GetFrame(1);
	System::Reflection::MethodBase^ mb = sf->GetMethod();
	return mb->Name;
}

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Habilitar los efectos visuales de Windows XP antes de crear ningún control
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Crear la ventana principal y ejecutarla
	Application::Run(gcnew Form1());
	return 0;
}
