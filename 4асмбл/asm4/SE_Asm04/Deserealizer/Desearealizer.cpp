#include "Desearealizer.h"
#include "stdafx.h"

void Desearealizer::Deserialize(int* valInt, unsigned int* valUnsigned)
{
	ifstream file(FILENAME, ios::binary);
	if (file.is_open())
	{
		file.read(reinterpret_cast<char*>(valInt), sizeof(int));
		file.read(reinterpret_cast<char*>(valUnsigned), sizeof(unsigned int));
		file.close();
	}
	else
	{
		cout << "File not open" << endl;
	}
}