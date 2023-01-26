#include "AsmGen.h"
#include "stdafx.h"
#include <string>

string Join(string str);

void AsmGen::CreateFile(int Int, unsigned int Uint32) // 4 байта беззнаковое
{
	ofstream file(ASMFILE); // Открытие файла
	string strInt = to_string(Int); // Преобразование в строку
	string strUint32 = to_string(Uint32);	// Преобразование в строку
	strInt = Join(strInt); // Добавление кавычек
	strUint32 = Join(strUint32); // Добавление кавычек

	if (file.is_open()) 
	{
		file ASMHEADER; 

		file << "FILEINT DD " << strInt << endl;
		file << "INTSTR DB \"int:    \", 0" << endl << endl;
		file << "FILEUINT32 DD " << strUint32 << endl;
		file << "UINT32STR DB \"uint32:     \", 0" << endl << endl
			<< ".CODE\n" << endl
			<< "main PROC\n" << endl;

		string footer = "";
		string cTypes = "";
		int startI = 8;
		int countInt = to_string(Int).size();

		for (int i = 0; i < countInt; i++)
		{
			footer += "\n\nmov eax, FILEINT " + cTypes;
			footer += "\n";
			footer += "add eax, 30h\n";
			footer += "mov INTSTR +" + to_string(startI++);
			footer += ", al\n";
			cTypes += " + type FILEINT";
		}

		footer += "invoke MessageBoxA, 0, offset INTSTR, ADDR TEXT_MESSAGE, OK\n";

		string cTypesUint = "";
		startI = 10;

		for (int i = 0; i < to_string(Uint32).size(); i++)
		{
			footer += "\n\nmov eax, FILEUINT32 " + cTypesUint;
			footer += "\n";
			footer += "add eax, 30h\n";
			footer += "mov UINT32STR + " + to_string(startI++);
			footer += ", al\n";
			cTypesUint += " + type FILEUINT32";
		}

		footer += "invoke MessageBoxA, 0, offset UINT32STR, ADDR TEXT_MESSAGE, OK\n";

		footer += "push - 1\n";
		footer += "call ExitProcess\n";
		footer += "main ENDP\n";
		footer += "end main\n";

		file << footer;
	}
	else
	{
		cout << "File not open" << endl;
	}
}

string Join(string str)
{
	string newStr = "";
	for (int i = 0; i < str.size(); i++)
	{
		newStr += str[i];
		if (i + 1 != str.size())
		{
			newStr += ", ";
		}
	}
	return newStr;
}