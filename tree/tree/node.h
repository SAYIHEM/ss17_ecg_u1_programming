#include <string>
#include <vector>
#include <iostream>
#include <ostream>
using namespace std;

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
	string get_name() const;
	void set_name(string new_name);
	int get_nr_children() const;
	node* get_child(int i) const;

	void add_child(node * child);
	void node::create_complete_tree(int nr_child_nodes, int tree_depth);
	void node::print(ostream& str, int depth);

};