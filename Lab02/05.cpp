#include <iostream>
using namespace std;

void setDiagonal(int A[], int n, int i, int j, int x) {
    if (i == j) A[i-1] = x;
}

int getDiagonal(int A[], int n, int i, int j) {
    if (i == j) return A[i-1];
    else return 0;
}

void displayDiagonal(int A[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) cout << A[i] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }
}
void setTriDiagonal(int A[], int n, int i, int j, int x) {
    if (i-j == 0) A[i-1] = x;                 // main diagonal
    else if (i-j == 1) A[n + j - 1] = x;      // lower diagonal
    else if (i-j == -1) A[2*n + i - 1] = x;   // upper diagonal
}

int getTriDiagonal(int A[], int n, int i, int j) {
    if (i-j == 0) return A[i-1];
    else if (i-j == 1) return A[n + j - 1];
    else if (i-j == -1) return A[2*n + i - 1];
    else return 0;
}
void setLower(int A[], int n, int i, int j, int x) {
    if (i >= j) A[(i*(i-1))/2 + (j-1)] = x;
}

int getLower(int A[], int n, int i, int j) {
    if (i >= j) return A[(i*(i-1))/2 + (j-1)];
    else return 0;
}
void setUpper(int A[], int n, int i, int j, int x) {
    if (i <= j) A[(i-1)*n - (i-2)*(i-1)/2 + (j-i)] = x;
}

int getUpper(int A[], int n, int i, int j) {
    if (i <= j) return A[(i-1)*n - (i-2)*(i-1)/2 + (j-i)];
    else return 0;
}
void setSymmetric(int A[], int n, int i, int j, int x) {
    if (i >= j) A[(i*(i-1))/2 + (j-1)] = x;
}

int getSymmetric(int A[], int n, int i, int j) {
    if (i >= j) return A[(i*(i-1))/2 + (j-1)];
    else return A[(j*(j-1))/2 + (i-1)];
}
