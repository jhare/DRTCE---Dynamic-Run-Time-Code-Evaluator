
#include <iostream>

#ifndef SMART_ITERATOR_H
#define SMART_ITERATOR_H


class _sint
{
	int i;
	clock_t Start;
	int Ticks;
	const char *Name;

public:
	_sint (int _i, const char *_name) : i (_i), Start (clock ()), Ticks (0), Name (_name)
	{
	}

	void next ()
	{
		++Ticks;
		++i;
	}

	~_sint ()
	{
		std::cout << Name << " avg loop time: " << (clock () - Start) / Ticks << std::endl;
	}

	operator int ()
	{
		return i;
	}
};

#endif
