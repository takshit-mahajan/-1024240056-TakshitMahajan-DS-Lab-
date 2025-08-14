#include <iostream>
using namespace std;
#include<vector>
int missingValues(vector<int> &x)
{
    int size=x.size()-1;
    int st=0;
    int end=size;
    int y=x[0];
    while (st<=end)
    {
        int mid=st+((-st+end)/2);
        if(x[mid]-x[0]==mid)
        {
            st=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return st+y;
    

}

int main() {
    // Your code here
    vector<int> arr={1,2,3,4,6,7};
    int result=missingValues(arr);
    cout<<result;
    return 0;
}
