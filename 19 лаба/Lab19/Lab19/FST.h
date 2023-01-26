#pragma once
#include "stdafx.h"

namespace FST
{
	struct RELATION		//ребро:символ -> вершина переходов КА
	{
		char symbol;	//символ перехода
		short nnode;	//номер смежной вершины
		RELATION(char c = 0x00, short ns = NULL);
	};

	struct NODE		//вершина графа переходов
	{
		short n_relation;		//количество инцидентных ребер
		RELATION* relations;	//инцедентные рёбра
		NODE();
		NODE(
			short n,			//количество инциндентных рёбер
			RELATION rel, ...	//список рёбер
		);
	};

	struct FST		//недетерминированный конечный автомат
	{
		char* string;		//цепочка(строка, завершается 0х00)
		short position;		//текущая позиция в цепочке
		short nstates;		//количество состояний автомата
		NODE* nodes;		//граф переходов: [0]-начальное состояние, [nstate-1]-конечное
		short* rstates;		//возможные состояния давнной позиции
		FST(
			char* s,		//цепочка(строка, завершается 0х00)
			short ns,		//количество состояний автомата
			NODE n, ...		//список состояний(граф переходов)
		);
	};

	bool execute(	//выполнить распознавание цепочки
		FST& fst	//недетерминированный конечный автомат
	);
};
