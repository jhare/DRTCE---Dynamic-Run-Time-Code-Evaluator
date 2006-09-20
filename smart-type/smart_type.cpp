

#include <stdio.h>
#include <stdlib.h>

template <typename T>
class _T
{
	T t;
	
public:

	_T ()
	{
	}

	_T (T _t)
	{
		t = _t;
	}
		
	operator T (void)
	{
		return t;
	}

	void *operator new (size_t _n)
	{
		T *p = (T *) malloc (sizeof (T) * _n);

		return p;
	}

	void operator delete (void *_p)
	{
		free (_p);
	}

	T operator + (T _a)
	{
		return t + _a;
	}

	T operator - (T _a)
	{
		return t - _a;
	}

	T operator * (T _a)
	{
		return t * _a;
	}

	T operator / (T _a)
	{
		return t * _a;
	}

	T operator & (T _a)
	{
		return t & _a;
	}

	T operator | (T _a)
	{
		return t | _a;
	}

	T operator ^ (T _a)
	{
		return t ^ _a;
	}

	bool operator && (T _a)
	{
		return t && _a;
	}

	bool operator || (T _a)
	{
		return t || _a;
	}
};

typedef _T <float> FLOAT;
#define _T smart_type;


int main ()
{
	{
		FLOAT *f = new FLOAT;
		*f = 10.0f;
		printf ("%f\n", (float) *f);
		delete f;
	}

	{
		FLOAT f = 1.0f;
		f = 1.0f * f + 9.0f;
		printf ("%f\n", (float) f);
	}


	return 0;
}
