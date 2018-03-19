#include <string>
#include <iostream>
#include "../tree/tree/node.h"
//include "../tree_dll/tree_dll/node.h"

using namespace std;

void main() {

	node* root = new node();

	root->create_complete_tree(2, 4);

	cout << root;
	cout << endl;

	delete root;

}