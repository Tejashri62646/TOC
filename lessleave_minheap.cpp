#include<iostream>
using namespace std;

class MinHeap {

    int heap[100];
    int size;

public:

    MinHeap() {
        size = 0;
    }

    void insert(int value) {

        size++;
        int i = size;

        while(i > 1 && value < heap[i/2]) {
            heap[i] = heap[i/2];
            i = i/2;
        }

        heap[i] = value;
    }

    void firstThree() {

        cout<<"First Three Employees with Less Leaves:\n";

        for(int i=1; i<=3; i++) {
            cout<<heap[i]<<" ";
        }
    }
};

int main() {

    MinHeap h;

    h.insert(10);
    h.insert(2);
    h.insert(5);
    h.insert(1);
    h.insert(7);

    h.firstThree();

    return 0;
}
