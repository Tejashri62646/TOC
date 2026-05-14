#include<iostream>
using namespace std;

class HeapSort {

    int arr[100], n;

public:

    // Input Function
    void input() {

        cout << "\nEnter number of elements: ";
        cin >> n;

        cout << "Enter elements:\n";

        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
    }

    // Display Function
    void display() {

        cout << "\nArray Elements:\n";

        for(int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    // Max Heapify (Ascending)
    void maxHeapify(int i, int size) {

        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if(left < size && arr[left] > arr[largest]) {
            largest = left;
        }

        if(right < size && arr[right] > arr[largest]) {
            largest = right;
        }

        if(largest != i) {

            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;

            maxHeapify(largest, size);
        }
    }

    // Min Heapify (Descending)
    void minHeapify(int i, int size) {

        int smallest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if(left < size && arr[left] < arr[smallest]) {
            smallest = left;
        }

        if(right < size && arr[right] < arr[smallest]) {
            smallest = right;
        }

        if(smallest != i) {

            int temp = arr[i];
            arr[i] = arr[smallest];
            arr[smallest] = temp;

            minHeapify(smallest, size);
        }
    }

    // Ascending Sort
    void ascendingSort() {

        // Build Max Heap
        for(int i = n/2 - 1; i >= 0; i--) {
            maxHeapify(i, n);
        }

        // Heap Sort
        for(int i = n-1; i > 0; i--) {

            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;

            maxHeapify(0, i);
        }

        cout << "\nArray Sorted in Ascending Order\n";
    }

    // Descending Sort
    void descendingSort() {

        // Build Min Heap
        for(int i = n/2 - 1; i >= 0; i--) {
            minHeapify(i, n);
        }

        // Heap Sort
        for(int i = n-1; i > 0; i--) {

            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;

            minHeapify(0, i);
        }

        cout << "\nArray Sorted in Descending Order\n";
    }
};

int main() {

    HeapSort h;

    int choice;

    do {

        cout << "\n========== HEAP SORT MENU ==========\n";
        cout << "1. Enter Elements\n";
        cout << "2. Sort in Ascending Order\n";
        cout << "3. Sort in Descending Order\n";
        cout << "4. Display Elements\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {

            case 1:
                h.input();
                break;

            case 2:
                h.ascendingSort();
                break;

            case 3:
                h.descendingSort();
                break;

            case 4:
                h.display();
                break;

            case 5:
                cout << "\nProgram Exited Successfully\n";
                break;

            default:
                cout << "\nInvalid Choice! Please Try Again.\n";
        }

    } while(choice != 5);

    return 0;
}
