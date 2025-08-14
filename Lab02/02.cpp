#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {             
        for (int j = 0; j < n - i - 1; j++) {     
            if (arr[j] > arr[j + 1]) {            
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    for(int val:arr){
        cout<<val<<endl;
        
    }
}
int main(){
    vector<int> x={64,34,25,12,22,11,90};
    bubbleSort(x);


}

