#include <iostream>
#include<stack>
#include<string>
using namespace std;

stack<char> result;
void reverseString(string name){
    for(int i=0;i<name.length();i++){
        result.push(name[i]);


    }
    while(result.empty()==false){
        cout<<result.top();
        result.pop();
    }
}


int main() {
    // Your code here
    string x="Takshit";
    reverseString(x);
    return 0;
}
