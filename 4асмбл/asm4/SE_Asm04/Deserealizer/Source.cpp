#include "stdafx.h"
#include "AsmGen.h"

void main()
{
	setlocale(LC_ALL, "ru");
	int intVal;
	unsigned int unsignedVal;

	Desearealizer des;
	des.Deserialize(&intVal, &unsignedVal); // Десериализация

	cout << intVal << " " << unsignedVal << endl;

	AsmGen AG;
	AG.CreateFile(intVal, unsignedVal); // Create asm file
}