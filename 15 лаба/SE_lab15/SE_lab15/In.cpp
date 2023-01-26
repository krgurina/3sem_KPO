#include "stdafx.h"

namespace In
{
	IN getin(wchar_t infile[])
	{
		int lines = 0;
		int cols = 0;
		int ignors = 0;
		int iter = 0;
		char* str = new char[MAX_LEN_LINE];
		unsigned char* code = new unsigned char[IN_MAX_LEN_TEXT];
		IN in;
		in.size = 0;
		std::fstream file(infile, std::fstream::in);

		// если невозможео открыть файл
		if (!file.is_open())
		{
			throw ERROR_THROW(110);
		}
		while (!file.eof())
		{
			lines++;
			// считываем данные с файла
			file.getline(str, MAX_LEN_LINE);
			for (int i = 0; i < strlen(str); i++)
			{
				cols++;
				in.size++;
				switch (in.code[int((unsigned char)str[i])]) {
				case(IN::F):
				{
					throw ERROR_THROW_IN(111, lines, cols);
					break;
				}
				case(IN::I):
				{
					ignors++;
					dell_in(str, i);
					break;
				}
				case(IN::T):
				{
					break;
				}
				default:
				{
					str[i] = in.code[int((unsigned char)str[i])];
					break;
				}
				}
			}
			str[strlen(str) + 1] = '\0';
			str[strlen(str)] = '\n';

			for (int i = 0; i < strlen(str); i++)
			{
				code[iter++] = (unsigned char)str[i];
			}

			cols = 0;
		}
		code[iter] = '\0';
		in.ignore = ignors;
		in.lines = lines;
		in.text = code;
		file.close();
		delete[] str;
		return in;
	}

	void dell_in(char* str, int index)
	{
		for (int i = index; i < strlen(str); i++)
		{
			str[i] = str[i + 1];
		}
	}
}