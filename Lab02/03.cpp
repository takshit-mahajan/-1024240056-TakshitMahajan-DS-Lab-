#include <iostream>
#include<string>
using namespace std;
string conCatenate(string x,string y)
{
    return x+y;
}
string reverse(string a){
    int length=a.length();
    for(int i=length;i>=0;i--)
    {
        cout<<a[i];
    }

}
string deleteVowels(const string &a)
{
    string result="";
    for(char c:a)
    {
        
        if(!(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')){
            result+=c;

        }
    }
    return result;

}
string sortStringWithoutSort(const string &s) {
    int freq[256] = {0};  // frequency array for all ASCII chars

    // Count frequency of each character
    for (char c : s) {
        freq[(unsigned char)c]++;
    }

    // Rebuild string in alphabetical order
    string result = "";
    for (int i = 0; i < 256; i++) {
        while (freq[i] > 0) {
            result += (char)i;
            freq[i]--;
        }
    }
    return result;
}

string toLowerCase(string s) {
    for (char &c : s) {
        if (c >= 'A' && c <= 'Z') {
            c = c + 32;   // convert to lowercase
        }
    }
    return s;
}

int main() {
    string x="Takshit";
    string y="Mahajan";
    // cout<<x+y;
    string a=conCatenate(x,y);
    cout<<a;
    cout<<endl;
    // Your code here
    reverse(x);
    cout<<endl;
    string result=deleteVowels(x);
    cout<<result;
    
    return 0;
}
