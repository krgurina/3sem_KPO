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
		cout << "Неверный ввод: " << endl;
		cout << "unsigned num: ";
		cin >> data.Uint;

	}*/
	

	// создание экземпляра класса сериализация
	Serealizer serealizer(data);
		serealizer.Invoke();	//к экземпляру применяем функцию сериализации

	system("pause");
}