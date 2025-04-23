//
//  main.cpp
//  Homework8.1
//
//  Created by Avi Soclof on 4/28/22.
//

#include <iostream>
#include "Vector.hpp"
#include "StackVector.hpp"


int operation(int num1, int num2, char oper)
{
    int res;

    switch (oper)
    {
    case'*':
    {
        return num1 * num2;
        break;
    }
    case '/':
    {
        return num1 / num2;
        break;
    }
    case '+':
    {
        return num1 + num2;
        break;
    }
    {
    case'-':
    {
        return num1 - num2;
        break;
    }
    }
    }
    return 0; 
}

string infixToPostfix(string& str){
    
    string helper;
    StackVector<char> stack;
    
    for (int i = 0; i < str.length(); ++i){
        if (str[i] == '('){
            stack.push(str[i]);
        }
        else if (str[i] == ')'){
            while (stack.top() != '('){
                helper += ' ';
                helper += stack.pop();
            }
            stack.pop();
        }
        else if (str[i] >= '*' && str[i] <= '/')
        {
            //add a space to the string
            str += ' ';
             
            //precedence for multiplication and division
            if (str[i] == '*'||str[i]=='/')
            {
                while (!stack.isEmpty() && (stack.top() == '*' || stack.top() == '/'))
                {
                    helper += stack.pop();
                    helper += ' ';
                }
            }
        
            //check for addition and subtraction chars
            else if (str[i] == '+'||str[i]=='-')
            {
                
                while (!stack.isEmpty() && (stack.top() == '*' || stack.top() == '/' || stack.top() == '+' || stack.top() == '-'))
                {
                    helper += stack.pop();
                    helper += ' ';
                }
            }
            
            //push input into string
            stack.push(str[i]);

        }
    }
    
    //push values from stack into helper
    while (!stack.isEmpty())
    {
        helper += ' ';
        helper += stack.pop();
    }


    return helper;
    
    
}

//function that will calculate the user chosen operation, fucntion takes in a postfixstr as defined by infixtopostfixand returns an int
int calcPostfix(string& str)
{
    int curr_num1, curr_num2;
    StackVector<int> stk;
    
    //for loop iterates through string
    for (int x = 0; x < str.length(); ++x)
    {
        //check if value at index is a digit
        if (str[x] >= '0' && str[x] <= '9')
        {
            //push to the stack
            stk.push(str[x]-'0');

            //while loop will check for digits
            for (++x; x<str.length()&&str[x] >= '0' && str[x] <= '9'; ++x)
            {

                //add to the stack the value*10 + current value
                stk.push((stk.pop() * 10) + (str[x] - '0'));

            }
        }
        //if we encounter an operand than we perform the appropriate math
        else if (str[x] >= '*' && str[x] <= '/')
        {
            //operation by operan
            curr_num1 = stk.pop();
            curr_num2 = (stk.pop());
            stk.push(operation(curr_num2, curr_num1, str[x]));
        }
    }

    //returns the solution
    return stk.top();
}

int main() {

    string exp;
    cout << "enter an infix expression as a string" << endl;
    cin >> exp;
    string postfix = infixToPostfix(exp);
    cout << "in postfix form: " << postfix << endl;
    cout << "calculated value: " << calcPostfix(postfix) << endl;
    return 0;
}

/*
sample output:
Enter an infix expression as a string
(5+3)*((20/10)+(8-6))
in postfix form: 5 3 + 20 10 / 8 6 - + *
calculated value: 32
*/

