#include "stdafx.h"

using namespace std;

int main() {
	Data data=Data();

	
	cout << endl << "num:"; 

	cin >> data.Int;

	cout << "unsigned num: ";
	cin >> data.Uint;
	
	/*while (data.Uint < 0)
	{
		cout << "�������� ����: " << endl;
		cout << "unsigned num: ";
		cin >> data.Uint;

	}*/
	

	// �������� ���������� ������ ������������
	Serealizer serealizer(data);
		serealizer.Invoke();	//� ���������� ��������� ������� ������������

	system("pause");
}