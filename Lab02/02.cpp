#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;

        
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        
        if (!swapped)
            break;
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    bubbleSort(arr, n);

    cout << "Sorted:   ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    cout<<n;
    return 0;
}
