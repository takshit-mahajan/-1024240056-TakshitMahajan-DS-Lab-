#include <iostream>
using namespace std;
//  Design the logic to remove the duplicate elements from an Array and after the deletion the array should contain the unique elements
int removeDuplicates(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;)
        {
            if (arr[i]==arr[j])
            {
                for(int k=j;k<n-1;k++)
                {
                    arr[k]=arr[k+1];
                }
                n--;
            }
            else
            {
                j++;
            }
        }
    }
    return n;
}
int main() {
    // Your code here
    int n=4;
    int arr[n]={1,2,3,2};
    int x;

    x=removeDuplicates(arr,n);
    cout<<x;
    return 0;
}
