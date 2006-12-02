#ifndef __SYMBOL_TABLE
#define __SYMBOL_TABLE

namespace drtce
{

enum i_type { t_void, t_int, t_unit, t_float, t_double, t_long, t_short, t_char, t_bool };

enum i_op { o_new, o_delete, o_deletep, o_add, o_sub, o_mul, o_div,
	 	o_mod, o_band, o_bor, o_bnot, o_bcomp, o_leq, o_lneq
		o_lnot, o_eq, o_neq, o_gt, o_lt, o_gteq, o_lteq
		o_ref, o_arrow, o_dref, o_umin, o_uplus, o_preinc, o_predec, o_postinc, o_postdec };

struct __vsymbol
{
	unsigned int addr;
	unsigned int context;

	i_type type;
	unsigned int operations[30];
};

class symbol_table
{

	public:
	
		symbol_table();
		~symbol_table();

		const unsigned int add_operation( __vsymbol sym, i_op op );

	private:

	std::map< unsigned int, __vsymbol > _symbol_map;

};

}

#endif
