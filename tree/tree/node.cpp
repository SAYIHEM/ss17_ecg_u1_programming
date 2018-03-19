#include "node.h"
#include <iostream>
#include <sstream>
#include <ostream>
#include <stack>
using namespace std;


//Statische Variablen
int node::node_id = 0;

//Konstruktor
node::node(const string& x)
{
	node_id++;

	if (x == "")
	{
		stringstream str_sm;
		str_sm << "node_" << node_id;
		string node_id_str = str_sm.str();

		name = node_id_str;
	}
	else
	{
		name = x;
	}

	next.clear();
}

//Destruktor
node::~node()
{
	cout << "enter ~node() of " << name << endl;

	for (int i = 0; i < get_nr_children(); i++)
	{
		if (!get_child(i)->next.empty())
		{
			get_child(i)->~node();
			next.erase(next.begin() + i);
		}
	}

	for (int i = 0; i < get_nr_children(); i++)
	{
		delete get_child(i);
	}

	next.clear();

	cout << "leave ~node() of " << name << endl;
}

//Get_Name
string node::get_name() const
{
	return name;
}

//Set_Name
void node::set_name(string new_name)
{
	name = new_name;
}

//Get Nr. of Children
int node::get_nr_children() const
{
	int nr_children = next.size();
	return nr_children;
}

//Get child
node* node::get_child(int x) const
{
	return next.at(x);
}

//Get Child
void node::add_child(node * child)
{
	next.push_back(child);
}

//Create complete tree
void node::create_complete_tree(int nr_child_nodes, int tree_depth)
{
	for (int i = 0; i < nr_child_nodes; i++)
	{
		if (tree_depth != 1)
		{
			node* child = new node;
			add_child(child);
			get_child(i)->create_complete_tree(nr_child_nodes, tree_depth - 1);
		}
	}
}

// print tree
void node::print(ostream& str, int depth)
{
	str << name << endl;

	int i;
	depth++;

	string tab = "";
	for (i = 0; i < depth; i++) { tab += "   "; }

	for (i = 0; i < get_nr_children(); i++)
	{
		get_child(i)->print(cout << tab, depth);
	}
}

//overload " << " operator
void operator<<(ostream& os, node* n)
{
	n->print(os, 0);

}
