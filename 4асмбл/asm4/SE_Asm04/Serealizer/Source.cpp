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
	
	
	cout << "������� �������� int: ";
	cin.getline(intVal, 50);
	
	cout << "������� �������� unsigned int: ";
	cin.getline(unsignedVal, 30);
	
	Int = atol(intVal + indexNumIn(intVal)); //�������������� ������ � �����

	Unsigned = strtoul(unsignedVal + indexNumIn(unsignedVal), NULL, 10); //�������������� ������ � �����

	cout << Int << " " << Unsigned << endl;

	serealizer.Serialize(Int, Unsigned); //������������
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