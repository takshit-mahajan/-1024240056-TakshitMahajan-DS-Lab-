#include <iostream>
using namespace std;

int createArray(int arr[]) {
    int size;
    cout << "Enter number of elements: ";
    cin >> size;
    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    return size;
}

int displayArray(int arr[], int size) {
    if (size == 0) {
        cout << "Array is empty.\n";
        return size;
    }
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return size;
}

int insertElement(int arr[], int size) {
    int pos, value;
    cout << "Enter position (1-based index): ";
    cin >> pos;
    cout << "Enter value: ";
    cin >> value;

    if (pos < 1 || pos > size + 1) {
        cout << "Invalid position.\n";
        return size;
    }

    for (int i = size; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = value;
    size++;
    cout << "Element inserted.\n";
    return size;
}

int deleteElement(int arr[], int size) {
    int pos;
    cout << "Enter position to delete (1-based index): ";
    cin >> pos;

    if (pos < 1 || pos > size) {
        cout << "Invalid position.\n";
        return size;
    }

    for (int i = pos - 1; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    cout << "Element deleted.\n";
    return size;
}

int linearSearch(int arr[], int size) {
    int key;
    cout << "Enter value to search: ";
    cin >> key;

    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            cout << "Element found at position " << i + 1 << ".\n";
            return size;
        }
    }
    cout << "Element not found.\n";
    return size;
}

int main() {
    int arr[100];
    int size = 0;
    int choice;

    while (true) {
        cout << "\n——MENU——\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: size = createArray(arr); break;
            case 2: size = displayArray(arr, size); break;
            case 3: size = insertElement(arr, size); break;
            case 4: size = deleteElement(arr, size); break;
            case 5: size = linearSearch(arr, size); break;
            case 6: cout << "Exiting...\n"; return 0;
            default: cout << "Invalid choice.\n";
        }
    }
}
