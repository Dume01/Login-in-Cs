#include <bits/stdc++.h>
using namespace std;

// Parse stree structure defined by user
struct NodeParseTree  
{ 
  char key; 
  struct NodeParseTree *left; 
  struct NodeParseTree *right; 
  NodeParseTree(char k){
      key=k;
      left=right=NULL;
  }

};

//Stack made for converting the prefix expression to infix expression
struct MyStack{
    string *arr;
    int cap;
    int top;
    MyStack(int c){
        cap=c;
        arr=new string [cap];
        top=-1;
    }

// To push an element in the stack
    
    void push(string x){
        if(top==cap-1){cout<<"Stack is full"<<endl;return;}
        top++;
        arr[top]=x;
    }

// To pop an element from the stack

    string pop(){
        if(top==-1){cout<<"Stack is Empty"<<endl;return NULL;}
        string res=arr[top];
        top--;
        return res;
    }

// To get the top elemenet from the stack
    
    string peek(){
        if(top==-1){cout<<"Stack is Empty"<<endl;return NULL;}
        return arr[top];
    }


    int size(){
        return (top+1);
    }

// To check if the stack is empty or not
    
    bool isEmpty(){
        return top==-1;
    }
};

// Custom function to check if the char considered is a operand or an operator
bool isOperator(char x) {
  switch (x) {
  case '+':
  case '~':
  case '*':
  case '>':
    return true;
  }
  return false;
}
 
// Convert prefix to Infix expression
string preToInfix(string pre_exp) {
  MyStack s(pre_exp.size());
 
  // length of expression
  int length = pre_exp.size();
 
  // reading from right to left
  for (int i = length - 1; i >= 0; i--) {
 
    // check if symbol is operator
    if (isOperator(pre_exp[i])) {
       if(pre_exp[i]=='~')
       { string a=s.peek();
         s.pop();
         string temp="~"+ a;
         s.push(temp);
       }
     else{
      // pop two operands from stack
      string op1 = s.peek();   s.pop();
      string op2 = s.peek();   s.pop();
 
      // concat the operands and operator
      string temp =op1 + pre_exp[i] + op2;
 
      // Push string temp back to stack
      s.push(temp);
    }
    }
 
    // if symbol is an operand
    else {
 
      // push the operand to the stack
      s.push(string(1, pre_exp[i]));
    }
  }
  
  // Stack now contains the Infix expression
  return s.peek();
}

// Static global variable to control the index of the prefix expression
static int preIndex=0;

// function that made the prefix and infix expression into the parse tree
NodeParseTree  *cTree(string in,string pre,int isq,int iee)
{
    if(isq>iee)return NULL;
    char q=pre[preIndex++];
    
    NodeParseTree  *root=new NodeParseTree (q);
    
    int inIndex=isq;
    
    for(int i=isq;i<=iee;i++)
    {
        char a=in[i];
        if(a==root->key)
        {
            inIndex=i;
            break;
        }
    }

//Recursion 
   
    root->left=cTree(in, pre, isq, inIndex-1);

    root->right=cTree(in, pre, inIndex+1, iee);

    return root;
}

// For inorder traversal
void inorder(NodeParseTree *root){
    if(root!=NULL){
        inorder(root->left);
        cout<< root->key <<" ";
        inorder(root->right);    
    }
}  

// Driver Code of the functions
int main() {
  string prefix = "";

  cout<< "Enter the prefix proposition"<< endl;
  // Taking input of the prefix expreesion
  cin >> prefix;

  string infix=preToInfix(prefix);

  cout << infix<<endl;
  //for getting the parse tree
  NodeParseTree *root=cTree(infix, prefix, 0, infix.size()-1);
  // to check if the new parse tree made is valid or not 
  inorder(root);

  return 0;
}