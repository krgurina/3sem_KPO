#include "Serealizer.h"
#include "stdafx.h"

void Serealizer::Serialize(int intVal, unsigned int unsignedVal)
{
	ofstream file(FILENAME, ios::binary);
	if (file.is_open())
	{
		//запись в файл
		file.write(reinterpret_cast<char*>(&intVal), sizeof(int));
		file.write(reinterpret_cast<char*>(&unsignedVal), sizeof(unsigned int)); 
		file.close();
	}
	else
	{
		cout << "File not open" << endl;
	}
}