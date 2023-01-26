#include "stdafx.h"
#include "Serealizer.h"

using namespace std;
int indexNumIn(char arr[]);

void main()
{
	setlocale(LC_ALL, "ru");
	Serealizer serealizer;
	char intVal[50];
	short Int;
	char unsignedVal[30];
	unsigned short Unsigned;
	
	
	cout << "Введите значение int: ";
	cin.getline(intVal, 50);
	
	cout << "Введите значение unsigned int: ";
	cin.getline(unsignedVal, 30);
	
	Int = atol(intVal + indexNumIn(intVal)); //преобразование строки в число

	Unsigned = strtoul(unsignedVal + indexNumIn(unsignedVal), NULL, 10); //преобразование строки в число

	cout << Int << " " << Unsigned << endl;

	serealizer.Serialize(Int, Unsigned); //сериализация
}

int indexNumIn(char arr[]) 
{
	int i = 0;
	for (; i < strlen(arr); i++)
	{
		if (
			(arr[i] >= '0' && arr[i] <= '9') ||
			arr[i] == '-' || arr[i] == '+'
			)
		{
			return i;
		}
	}
	return -1;
}