#include "stdafx.h"

using namespace std;

//создание файла на ассемблере
void AsmConvenrter::Invoke()
{
	file = ofstream("F:\\лабы\\КПО\\4асмбл\\Serealization\\AssemblerProgramm\\test4.asm");


	file.clear();

	file ASMHEADER;
	file << "FILEUINT	 DD " << '0' + data.Uint - '0' << endl << endl;


	file DATA;
		 file<< "FILEINT	 DD " <<'0' + data.Int - '0' << endl << endl;
		 

	file ASMFOOTER;

	file.close();
}
