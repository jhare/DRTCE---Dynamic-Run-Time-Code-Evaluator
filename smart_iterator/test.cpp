
#include "smart_iterator.h"


int main ()
{
	for (int i = 0; i < 100; ++i)
	{
		while (clock () == clock ());
	}

}
