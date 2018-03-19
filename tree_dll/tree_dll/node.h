#include <string>
#include <vector>
#include <iostream>
#include <ostream>
using namespace std;

#ifdef TREE_EXPORTS  
#define TREE_API __declspec(dllexport)   
#else  
#define TREE_API __declspec(dllimport)   
#endif  

class node
{
private:

	//Variablen
	string name;
	vector<node*> next;
	static int node_id;

	//operator overload
	friend void operator<<(ostream& os, node* n);

public:

	//Consturctor/Destructor
	node(const string& x = "");
	virtual ~node();

	//Methods
	TREE_API string get_name() const;
	TREE_API void set_name(string new_name);
	TREE_API int get_nr_children() const;
	TREE_API node* get_child(int i) const;

	TREE_API void add_child(node * child);
	TREE_API void node::create_complete_tree(int nr_child_nodes, int tree_depth);
	TREE_API void node::print(ostream& str, int depth);

};