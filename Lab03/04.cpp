// 4. Write a program to convert an Infix expression into a Postfix expression.
#include <iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return -1; 
}

bool isRightAssociative(char op) {
    return (op == '^'); // ^ is right associative
}

string conversionPostFix(string infix){
    stack<char> que;
    string result="";

    // Pushing my start.
    que.push('(');
    infix+=')';

    for(char c:infix){
        if(isalnum(c)){
            result+=c;
        }
        else if(c=='('){
            que.push(c);
        }
        else if (c == ')') {
            while (!que.empty() && que.top() != '(') {
                result += que.top();
                que.pop();
            }
            que.pop(); 
        }
        else {
            while (!que.empty() && 
                  ((precedence(que.top()) > precedence(c)) ||
                   (precedence(que.top()) == precedence(c) && !isRightAssociative(c))) &&
                   que.top() != '(') {
                result += que.top();
                que.pop();
            }
            que.push(c);
        }
    }
    return result;
}

int main() {
    // Your code here
    string x="A+b/C^X";
    string output=conversionPostFix(x);
    cout<<output;
    return 0;
}
