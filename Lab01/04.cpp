#include <iostream>
using namespace std;
void reverseArray(int arr[],int n)
{
    int st=0;
    int end=n-1;
    while(st<end)
    {
        swap(arr[st],arr[end]);
        st++;
        end--;
    }
    cout<<"Reversed Array are:- \n";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i];

    }
    return ;
}

void multiplyMatrices(int a[5][5], int b[5][5], int result[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            result[i][j] = 0;
            for (int k = 0; k < 5; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}
void transposeMatrix(int mat[5][5], int trans[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            trans[j][i] = mat[i][j];
        }
    }
}

int main() {
    // Your code here
    int n=5;
    int arr[n]={1,2,3,4,5};
    reverseArray(arr,n);

    return 0;
}
