#ifndef __CONTEXT_TREE
#define __CONTEXT_TREE

namespace drtce
{
	enum i_context { c_loop, c_func, c_block };

	struct ctree_node
	{
		unsigned int _cid;
		std::vector< std::string > dependents;

		ctree_node* parent;
		ctree_node** children;
	};

	class context_tree
	{

		public:

			context_tree();
			~context_tree();

			void add_node( i_context type, std::string context = "<null>" );	

		private:

			ctree_node* m_root;
	};
}
#endif
