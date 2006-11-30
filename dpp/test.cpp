

#include <iostream>
#include <stdio.h>

int main ()
{
	clock_t t;

	for (int i = 0; i < 10; ++i)
		for (int j = i; j < 10; ++j)
		{
			t = clock ();
			while (clock () == t);
		}
}

