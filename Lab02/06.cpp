#include <iostream>
using namespace std;

#define MAX 100

void transpose(int A[][3], int B[][3]) {
    int n = A[0][2]; // number of non-zero elements
    B[0][0] = A[0][1];
    B[0][1] = A[0][0];
    B[0][2] = n;

    int k = 1;
    for (int col = 0; col < A[0][1]; col++) {
        for (int i = 1; i <= n; i++) {
            if (A[i][1] == col) {
                B[k][0] = A[i][1];
                B[k][1] = A[i][0];
                B[k][2] = A[i][2];
                k++;
            }
        }
    }
}
void addSparse(int A[][3], int B[][3], int C[][3]) {
    if (A[0][0] != B[0][0] || A[0][1] != B[0][1]) {
        cout << "Addition not possible\n";
        return;
    }
    int i=1, j=1, k=1;
    C[0][0] = A[0][0];
    C[0][1] = A[0][1];

    while (i<=A[0][2] && j<=B[0][2]) {
        if (A[i][0] < B[j][0] || (A[i][0]==B[j][0] && A[i][1]<B[j][1]))
            C[k][0]=A[i][0], C[k][1]=A[i][1], C[k++][2]=A[i++][2];
        else if (B[j][0] < A[i][0] || (B[j][0]==A[i][0] && B[j][1]<A[i][1]))
            C[k][0]=B[j][0], C[k][1]=B[j][1], C[k++][2]=B[j++][2];
        else {
            C[k][0]=A[i][0]; C[k][1]=A[i][1];
            C[k++][2]=A[i++][2]+B[j++][2];
        }
    }
    while (i<=A[0][2]) C[k][0]=A[i][0], C[k][1]=A[i][1], C[k++][2]=A[i++][2];
    while (j<=B[0][2]) C[k][0]=B[j][0], C[k][1]=B[j][1], C[k++][2]=B[j++][2];
    C[0][2] = k-1;
}
void multiplySparse(int A[][3], int B[][3], int C[][3]) {
    if (A[0][1] != B[0][0]) {
        cout << "Multiplication not possible\n";
        return;
    }

    int BT[MAX][3];
    transpose(B, BT);

    int k=1;
    C[0][0] = A[0][0];
    C[0][1] = B[0][1];

    for (int i=1; i<=A[0][2]; ) {
        int row = A[i][0];
        for (int j=1; j<=BT[0][2]; ) {
            int col = BT[j][0];
            int sum = 0;

            int ii=i, jj=j;
            while (ii<=A[0][2] && A[ii][0]==row &&
                   jj<=BT[0][2] && BT[jj][0]==col) {
                if (A[ii][1] < BT[jj][1]) ii++;
                else if (A[ii][1] > BT[jj][1]) jj++;
                else sum += A[ii++][2] * BT[jj++][2];
            }
            if (sum!=0) {
                C[k][0]=row;
                C[k][1]=col;
                C[k][2]=sum;
                k++;
            }
            while (jj<=BT[0][2] && BT[jj][0]==col) jj++;
        }
        while (i<=A[0][2] && A[i][0]==row) i++;
    }
    C[0][2] = k-1;
}
