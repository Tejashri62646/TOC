#include <iostream>
using namespace std;

class BloomFilter {

    int size;
    int arr[100];

public:

    BloomFilter(int s) {

        size = s;

        for(int i = 0; i < size; i++) {
            arr[i] = 0;
        }
    }

    // Hash Function 1
    int hash1(string str) {

        int sum = 0;

        for(int i = 0; i < str.length(); i++) {
            sum += str[i];
        }

        return sum % size;
    }

    // Hash Function 2
    int hash2(string str) {

        int sum = 1;

        for(int i = 0; i < str.length(); i++) {
            sum = sum * str[i];
        }

        return sum % size;
    }

    // Insert Username
    void insert(string username) {

        int index1 = hash1(username);
        int index2 = hash2(username);

        arr[index1] = 1;
        arr[index2] = 1;

        cout << "Username Inserted\n";
    }

    // Search Username
    void search(string username) {

        int index1 = hash1(username);
        int index2 = hash2(username);

        if(arr[index1] == 1 &&
           arr[index2] == 1) {

            cout << "Username MAY exist\n";
        }
        else {

            cout << "Username definitely NOT present\n";
        }
    }

    // Display Filter
    void display() {

        cout << "\nBloom Filter Array:\n";

        for(int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main() {

    BloomFilter bf(10);

    int choice;
    string username;

    do {

        cout << "\n===== Username Checking System =====\n";

        cout << "1. Insert Username\n";
        cout << "2. Search Username\n";
        cout << "3. Display Bloom Filter\n";
        cout << "4. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice) {

        case 1:

            cout << "Enter Username: ";
            cin >> username;

            bf.insert(username);
            break;

        case 2:

            cout << "Enter Username to Search: ";
            cin >> username;

            bf.search(username);
            break;

        case 3:

            bf.display();
            break;

        case 4:

            cout << "Exiting...\n";
            break;

        default:

            cout << "Invalid Choice\n";
        }

    } while(choice != 4);

    return 0;
}
