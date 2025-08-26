// Given a string, reverse it using STACK. For example “DataStructure” should be output as “erutcurtSataD.”

#include <iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

string reverseString(const string &str) {
    stack<char> s;     
    for(char ch : str) {
        s.push(ch);
    }
    
    string result = "";
    while(!s.empty()) {
        result += s.top();
        s.pop();
    }
    
    return result;
}

int main() {
    // Your code here
    string x="Takshit";
    string output=reverseString(x);
    cout<<output;
    return 0;
}
