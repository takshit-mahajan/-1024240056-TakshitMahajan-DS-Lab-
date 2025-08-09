#include <iostream>
using namespace std;

int main() {
    // Your code here
    int i;
    int arr[5]={1};
    for (i=0;i<5;i++)
    {
        cout<<arr[i];
    }
    return 0;
}
// Output is:- 10000    (Because uninitialised values of array are set to be zero in c/c++)
