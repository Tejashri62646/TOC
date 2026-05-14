#include <iostream>
using namespace std;

class Student {

public:

    int rollNo;
    string name;
    float marks;
};

class HeapSort {

public:

    Student arr[100];
    int n;

    // Input Student Records
    void accept() {

        cout << "Enter Number of Students: ";
        cin >> n;

        for(int i = 0; i < n; i++) {

            cout << "\nEnter Roll No: ";
            cin >> arr[i].rollNo;

            cout << "Enter Name: ";
            cin >> arr[i].name;

            cout << "Enter Marks: ";
            cin >> arr[i].marks;
        }
    }

    // Swap Function
    void swap(Student &a, Student &b) {

        Student temp = a;
        a = b;
        b = temp;
    }

    // Max Heapify
    void maxHeapify(int n, int i) {

        int largest = i;

        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // Left Child
        if(left < n &&
           arr[left].marks > arr[largest].marks)

            largest = left;

        // Right Child
        if(right < n &&
           arr[right].marks > arr[largest].marks)

            largest = right;

        // Swap
        if(largest != i) {

            swap(arr[i], arr[largest]);

            maxHeapify(n, largest);
        }
    }

    // Min Heapify
    void minHeapify(int n, int i) {

        int smallest = i;

        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // Left Child
        if(left < n &&
           arr[left].marks < arr[smallest].marks)

            smallest = left;

        // Right Child
        if(right < n &&
           arr[right].marks < arr[smallest].marks)

            smallest = right;

        // Swap
        if(smallest != i) {

            swap(arr[i], arr[smallest]);

            minHeapify(n, smallest);
        }
    }

    // Ascending Heap Sort
    void ascendingSort() {

        // Build Max Heap
        for(int i = n/2 - 1; i >= 0; i--) {
            maxHeapify(n, i);
        }

        // Heap Sort
        for(int i = n-1; i > 0; i--) {

            swap(arr[0], arr[i]);

            maxHeapify(i, 0);
        }

        cout << "\nAscending Order (Marks):\n";

        display();
    }

    // Descending Heap Sort
    void descendingSort() {

        // Build Min Heap
        for(int i = n/2 - 1; i >= 0; i--) {
            minHeapify(n, i);
        }

        // Heap Sort
        for(int i = n-1; i > 0; i--) {

            swap(arr[0], arr[i]);

            minHeapify(i, 0);
        }

        cout << "\nDescending Order (Marks):\n";

        display();
    }

    // Display Records
    void display() {

        cout << "\n-----------------------------------\n";

        for(int i = 0; i < n; i++) {

            cout << "Roll No: " << arr[i].rollNo
                 << "  Name: " << arr[i].name
                 << "  Marks: " << arr[i].marks << endl;
        }

        cout << "-----------------------------------\n";
    }
};

int main() {

    HeapSort h;

    int choice;

    do {

        cout << "\n===== Student Marks Management =====\n";

        cout << "1. Insert Student Records\n";
        cout << "2. Ascending Heap Sort\n";
        cout << "3. Descending Heap Sort\n";
        cout << "4. Display Records\n";
        cout << "5. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice) {

        case 1:

            h.accept();
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

            cout << "Exiting...\n";
            break;

        default:

            cout << "Invalid Choice\n";
        }

    } while(choice != 5);

    return 0;
}
