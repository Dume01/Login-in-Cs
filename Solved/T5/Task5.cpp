// C++ program to evaluate truth value
#include <bits/stdc++.h>
using namespace std;

// Class to represent the atoms of parse tree
class ParseTreeNode
{
public:
	char key;
	ParseTreeNode *left = NULL, *right = NULL;
	ParseTreeNode(char x)
	{
		key = x;
	}
};

//function to return truth value of atom
int truth(char s)
{
	int num;
		
	if(s=='0'){num = 0;}
	else{num = 1;}
	
	return num;
}

// function to receive a atmon of the parse tree and recursively evaluate it
int evaluation(ParseTreeNode* root)
{
	// empty tree
	if (!root)
		return 0;

	// leaf i.e, truth value
	if (!root->left && !root->right)
		return truth(root->key);

	// Evaluate left subtree
	int l_val = evaluation(root->left);

	// Evaluate right subtree
	int r_val = evaluation(root->right);

	// Check which operator to apply
	if (root->key=='+')
		return l_val|r_val;

	if (root->key=='*')
		return l_val&r_val;
		
	if(root->key=='~')
	    return !r_val;

	return !(l_val)|(r_val);
}

// function to check the above program
int main()
{
    //User defined parse tree
    ParseTreeNode *root = new ParseTreeNode('>');
    root->left = new ParseTreeNode('*');
    root->left->left = new ParseTreeNode('1');
    root->left->right = new ParseTreeNode('1');
    root->right = new ParseTreeNode('+');
    root->right->left = new ParseTreeNode('~');
    root->right->left->right = new ParseTreeNode('1');
    root->right->right = new ParseTreeNode('>');
    root->right->right->right= new ParseTreeNode('0');
    root->right->right->left= new ParseTreeNode('0');
    cout << "The truth Value of the given parse tree is " <<evaluation(root);

	return 0;
}