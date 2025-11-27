#include <iostream>
#include <vector>
using namespace std;


void heapifyMax(vector<int>& a, int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && a[l] > a[largest]) largest = l;
    if (r < n && a[r] > a[largest]) largest = r;

    if (largest != i) {
        swap(a[i], a[largest]);
        heapifyMax(a, n, largest);
    }
}


void heapifyMin(vector<int>& a, int n, int i) {
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && a[l] < a[smallest]) smallest = l;
    if (r < n && a[r] < a[smallest]) smallest = r;

    if (smallest != i) {
        swap(a[i], a[smallest]);
        heapifyMin(a, n, smallest);
    }
}


void heapSortIncreasing(vector<int>& a) {
    int n = a.size();
   
    for (int i = n/2 - 1; i >= 0; --i) heapifyMax(a, n, i);

    
    for (int i = n - 1; i > 0; --i) {
        swap(a[0], a[i]);       
        heapifyMax(a, i, 0);    
    }
}


void heapSortDecreasing(vector<int>& a) {
    int n = a.size();
    
    for (int i = n/2 - 1; i >= 0; --i) heapifyMin(a, n, i);

    
    for (int i = n - 1; i > 0; --i) {
        swap(a[0], a[i]);         
        heapifyMin(a, i, 0);      
    }
    
    reverse(a.begin(), a.end());
}


void printVec(const vector<int>& a) {
    for (int x : a) cout << x << " ";
    cout << "\n";
}


int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    cout << "Original: ";
    printVec(arr);

    // Increasing order
    vector<int> a1 = arr;
    heapSortIncreasing(a1);
    cout << "Heapsort (increasing): ";
    printVec(a1);

    // Decreasing order
    vector<int> a2 = arr;
    heapSortDecreasing(a2);
    cout << "Heapsort (decreasing): ";
    printVec(a2);


    return 0;
}
