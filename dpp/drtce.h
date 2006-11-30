
#include <iostream>
#include <time.h>

#define xstr(s) #s
#define str(s) xstr(s)

//#define drtce_for(a, b, c) std::cout << "line " str(__LINE__) " at " << (clock ()) << ": for (" str(a) "; " str(b) "; " str(c) ") -> " << (c) << std::endl
#define drtce_for(a, b, c) std::cout << str(__LINE__) "\t" << (clock ()) << "\t" << (c) << std::endl
