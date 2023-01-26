#pragma once
class Serealizer
{
public:
	void Serialize(int intVal, unsigned int unsignedVal);

private:
	const char* FILENAME = "bin.txt";
};

