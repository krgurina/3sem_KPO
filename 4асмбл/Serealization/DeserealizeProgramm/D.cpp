#include "stdafx.h"
#include "D.h"

using namespace std;

void Deserializer::Invoke() {

	file = ifstream("F:\\����\\���\\4�����\\Serealization\\Debug\\bin1.txt");

	//file = ifstream("F:\\����\\���\\4�����\\Serealization\\SerializeProgram\\bin1.txt");

	//���������� �� �����
	file.read(reinterpret_cast<char*>(&(data->Int1)), sizeof(int));
	file.read(reinterpret_cast<char*>(&(data->Int)), sizeof(int));

	file.read(reinterpret_cast<char*>(&(data->Int2)), sizeof(int));
	file.read(reinterpret_cast<char*>(&(data->Uint)), sizeof(unsigned int));
	


	file.close();
}
