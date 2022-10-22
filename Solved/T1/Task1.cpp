#include <bits/stdc++.h>
using namespace std;
//stack that is user defined 
struct MyStack{
    char *arr;
    int cap;
    int top;
    MyStack(int c){
        cap=c;
        arr=new char [cap];
        top=-1;
    }
    // to push elements in the stack
    void push(char x){
        if(top==cap-1){cout<<"Stack is full"<<endl;return;}
        top++;
        arr[top]=x;
    }
    // to pop elements off the stack
    int pop(){
        if(top==-1){cout<<"Stack is Empty"<<endl;return INT_MIN;}
        int res=arr[top];
        top--;
        return res;
    }
    // to get the top elements of the stack
    int peek(){
        if(top==-1){cout<<"Stack is Empty"<<endl;return INT_MIN;}
        return arr[top];
    }
    // to return the top elements of the stack 
    int size(){
        return (top+1);
    }
    // to check if the stack is empty or not
    bool isEmpty(){
        return top==-1;
    }
};

//boolean function that returns if the element is an operator or not
bool isItOperator(char c)
{
    return (!isalpha(c) && !isdigit(c));
}

// return the priority of the operators involved
int getPriorityOfoperator(char W)
{
    if (W == '+')
        return 1;
    else if (W == '*')
        return 2;
    else if (W == '~')
        return 3;
    return 0;
}
//Function for returning the converted postfix expression
string infixToPostfix(string infix)
{
    infix = '(' + infix + ')';
    int l = infix.size();
    //stack for storing 
    MyStack char_stack(l);
    string output;
 
    for (int i = 0; i < l; i++) {
 
        // If the scanned character is an operand, add it to output.
        
        if (isalpha(infix[i]) || isdigit(infix[i]))
            output += infix[i];
 
        // If the scanned character is an '(', push it to the stack.
        
        else if (infix[i] == '(')
            char_stack.push('(');
 
        // If the scanned character is an ')', pop and output from the stack until an '(' is encountered.

        else if (infix[i] == ')') {
            while (char_stack.peek() != '(') {
                output += char_stack.peek();
                char_stack.pop();
            }
 
            // Remove '(' from the stack
            char_stack.pop();
        }
 
        //If Operator is found

        else
        {
            if (isItOperator(char_stack.peek()))
            {
                if(infix[i] == '~')
                {
                      while (getPriorityOfoperator(infix[i]) <= getPriorityOfoperator(char_stack.peek()))
                       {
                         output += char_stack.peek();
                         char_stack.pop();
                       }
                     
                }
                else
                {
                    while (getPriorityOfoperator(infix[i]) < getPriorityOfoperator(char_stack.peek()))
                       {
                         output += char_stack.peek();
                         char_stack.pop();
                       }
                     
                }
 
                // Push current Operator on stack
                char_stack.push(infix[i]);
            }
        }
    }
      while(!char_stack.isEmpty()){
          output += char_stack.peek();
        char_stack.pop();
    }
    return output;
}
//Funtion for getting the prefix expression 
string infixToPrefix(string infix)
{
    /* Reverse String
     * Replace ( with ) and vice versa
     * Get Postfix
     * Reverse Postfix  *  */
    int l = infix.size();
 
    // Reverse infix
    reverse(infix.begin(), infix.end());
 
    // Replace ( with ) and vice versa
    for (int i = 0; i < l; i++) {
 
        if (infix[i] == '(') {
            infix[i] = ')';
        }
        else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }
 
    string prefix = infixToPostfix(infix);
 
    // Reverse postfix
    reverse(prefix.begin(), prefix.end());
 
    return prefix;
}
 
// Driver code
int main()
{   cout << "Enter the Infix expression" << endl;
    // Input of the infix expression
    string s;
    cin >> s;
    cout << "Infix: " << s<<" Prefix: "<<infixToPrefix(s) << std::endl;
    return 0;
}