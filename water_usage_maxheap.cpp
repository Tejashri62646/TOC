#include<iostream>
using namespace std;

class MaxHeap {
    int heap[100];
    int size;

public:
    MaxHeap() {
        size = 0;
    }

    void insert(int value) {
        size++;
        int i = size;

        while(i > 1 && value > heap[i/2]) {
            heap[i] = heap[i/2];
            i = i/2;
        }

        heap[i] = value;
    }

    void display() {
        cout<<"Heap Elements:\n";
        for(int i=1; i<=size; i++) {
            cout<<heap[i]<<" ";
        }
    }

    void highestUsage() {
        cout<<"\nHighest Water Usage: "<<heap[1];
    }
};

int main() {
    MaxHeap h;

    h.insert(500);
    h.insert(900);
    h.insert(300);
    h.insert(1200);

    h.display();
    h.highestUsage();

    return 0;
}
