#include <iostream>
using namespace std;

void sumRows(int rows, int cols, int arr[][5]) {
    for (int i = 0; i < rows; i++) {
        int sum = 0;
        for (int j = 0; j < cols; j++) {
            sum += arr[i][j];
        }
        cout << "Row " << i + 1 << ": " << sum << endl;
    }
}

void sumCols(int rows, int cols, int arr[][5]) {
    for (int j = 0; j < cols; j++) {
        int sum = 0;
        for (int i = 0; i < rows; i++) {
            sum += arr[i][j];
        }
        cout << "Column " << j + 1 << ": " << sum << endl;
    }
}

int main() {
    int rows, cols;
    rows=2,cols=4;
    int arr[5][5]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};

    cout << "\nSum of each row:\n";
    sumRows(rows, cols, arr);

    cout << "\nSum of each column:\n";
    sumCols(rows, cols, arr);

    return 0;
}
