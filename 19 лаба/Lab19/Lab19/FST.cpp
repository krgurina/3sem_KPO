#include "FST.h"

namespace FST
{
	RELATION::RELATION(char c, short ns)
	{
		this->symbol = c;
		this->nnode = ns;
	}

	NODE::NODE()		//по умолчанию 
	{
		this->n_relation = NULL;
		this->relations = NULL;
	};
	NODE::NODE(short n, RELATION rel, ...)	//с параметрами
	{
		this->n_relation = n;	//количество инцедентных рёбер
		this->relations = new RELATION[n_relation];
		RELATION* wptr = &rel;
		for (int i = 0; i < n; i++)
		{
			relations[i] = wptr[i];
		};
	};

	FST::FST(char* s, short ns, NODE n, ...)
	{
		this->position = -1; //чтобы с 0 начинать в execute
		this->string = s;
		this->nstates = ns;	
		this->rstates = new short[nstates];
		this->nodes = new NODE[nstates];

		rstates = new short[nstates];	//массив возможных состояний автомата на данной позиции
		memset(rstates, 0xff, sizeof(short) * nstates);
		rstates[0] = 0;

		NODE* wptr = &n;
		for (int i = 0; i < ns; i++)
			nodes[i] = wptr[i];
	}

	bool step(FST& fst, short*& rstates)	//один шаг автомата
	{
		bool rc = false;
		std::swap(rstates, fst.rstates);	//смена массивов
		for (short i = 0; i < fst.nstates; i++)
		{
			if (rstates[i] == fst.position)
				for (short j = 0; j < fst.nodes[i].n_relation; j++)
					if (fst.nodes[i].relations[j].symbol == fst.string[fst.position]) {
						fst.rstates[fst.nodes[i].relations[j].nnode] = fst.position + 1;
						rc = true;
					};
		};
		return rc;
	};
	bool execute(FST& fst)		//выполнить распознавание цепочки
	{
		short* rstates = new short[fst.nstates];	//количество значимых символов входной цепочки
		memset(rstates, 0xff, sizeof(short) * fst.nstates);
		short lstring = strlen(fst.string);
		bool rc = true;
		for (short i = 0; i < lstring && rc; i++)
		{
			fst.position++;				//продвинули позицию
			rc = step(fst, rstates);	//один шаг автомата
		};
		delete[] rstates;
		return (rc ? (fst.rstates[fst.nstates - 1] == lstring) : rc);
	};
}