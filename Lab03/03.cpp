// Write a program that checks if an expression has balanced parentheses.

#include <iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;
bool checkParenthesis(string input_string){
    stack<char> s;
    for(char ch:input_string){

        // Opening
        if(ch=='(' || ch=='{'|| ch=='['){
            s.push(ch);
        }
        else if (ch==')' || ch=='}' || ch==']'){
            if(s.empty()) {
                return false;
            }
            char top=s.top();

            if (
                (ch==')' && top!='(') ||
                (ch==']' && top!='[') ||
                (ch=='}' && top!='{') 
            )
            {
                return false;
            }
            s.pop();
        }
    }
    bool result=s.empty();
    return result;

}

int main() {
    // Your code here
    string x="{[]}";
    bool output=checkParenthesis(x);
    cout<<output;
    return 0;
}
