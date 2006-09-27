#include "symbol_table.h"

drtce::symbol_table::symbol_table()
{

}

drtce::symbol_table::~symbol_table()
{

}

const unsigned int drtce::symbol_table::add_operation( drtce::__vsymbol sym, drtce::i_op op )
{
	_symbol_map[ sym.addr ].operations[ op ]++; 
	return( sym.addr );
}
