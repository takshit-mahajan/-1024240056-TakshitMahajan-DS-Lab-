#include <iostream>
using namespace std;

#define SIZE 5   

int arr[SIZE];
int front = -1, rear = -1;

bool isFull() {
    return (rear == SIZE - 1);
}


bool isEmpty() {
    return (front == -1 || front > rear);
}


void enqueue(int x) {
    if (isFull()) {
        cout << "Queue full. ";
        return;
    }
    if (front == -1) front = 0; 
    arr[++rear] = x;
    cout<<"Inserted.";
}



void dequeue() {
    if (isEmpty()) {
        cout << "Already empty";
        return;
    }
    cout<<"Deleted.";
    front++;
}

void display() {
    if (isEmpty()) {
        cout << "Queue Empty.";
        return;
    }
    cout << "Queue elements: ";
    for (int i = front; i <= rear; i++) {
        cout << arr[i];
    }
    cout << endl;
}


int peek(){
    return arr[rear];
}

int main(){
    enqueue(5);
    enqueue(23);
    dequeue();
    int top_element=peek();
    cout<<top_element;

    return 0;
}

