

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
};

typedef _T <float> FLOAT;


int main ()
{
	FLOAT *f = new FLOAT;

	*f = 10.0f;

	printf ("%f\n", (float) *f);

	delete f;

	return 0;
}
