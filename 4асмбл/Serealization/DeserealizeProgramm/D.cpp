#include "stdafx.h"
#include "D.h"

using namespace std;

void Deserializer::Invoke() {

	file = ifstream("F:\\лабы\\КПО\\4асмбл\\Serealization\\Debug\\bin1.txt");

	//file = ifstream("F:\\лабы\\КПО\\4асмбл\\Serealization\\SerializeProgram\\bin1.txt");

	//считывание из файла
	file.read(reinterpret_cast<char*>(&(data->Int1)), sizeof(int));
	file.read(reinterpret_cast<char*>(&(data->Int)), sizeof(int));

	file.read(reinterpret_cast<char*>(&(data->Int2)), sizeof(int));
	file.read(reinterpret_cast<char*>(&(data->Uint)), sizeof(unsigned int));
	


	file.close();
}
