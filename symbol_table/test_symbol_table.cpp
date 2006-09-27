#include <iostream>
#include "symbol_table.h"

#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

class sttest : public CppUnit::TestFixture
{

	public:

		void setUp()
		{

		}

		void tearDown()
		{

		}

		void testAddOp()
		{

		}

	private:

		drtce::symbol_table table1;
		drtce::symbol_table table2;
};

int main( int argc, char* argv[] )
{
	CppUnit::Test *suite = CppUnit::TestFactoryRegistry::getRegistry().makeTest();

	CppUnit::TextUi::TestRunner runner;

	runner.addTest( suite );

	return( runner.run() ); 
	
}
