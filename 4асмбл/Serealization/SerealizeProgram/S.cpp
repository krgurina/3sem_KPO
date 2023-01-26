#include "stdafx.h"
#define INT "int";
#define UINT "uint";
using namespace std;

void Serealizer::Invoke()
{
	file = ofstream("F:\\лабы\\КПО\\4асмбл\\Serealization\\Debug\\bin1.txt");

	file.clear();

	//запись в файл, как char

	/*file << INT;
	file << sizeof(int);
	file << data.Int;*/

	file.write(reinterpret_cast<char*>(&data.Int1), sizeof(int));

	file.write(reinterpret_cast<char*>(&data.Int), sizeof(int));

	/*file << UINT;
	file << sizeof(unsigned int);
	file << data.Uint;*/
	file.write(reinterpret_cast<char*>(&data.Int2), sizeof(int));

	file.write(reinterpret_cast<char*>(&data.Uint), sizeof(unsigned int));

	file.close();
}
