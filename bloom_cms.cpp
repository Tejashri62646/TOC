#include<iostream>
using namespace std;

// ======================================================
//                BLOOM FILTER CLASS
// ======================================================

class BloomFilter {

    int size;
    int *arr;

public:

    // Constructor
    BloomFilter(int s) {
        size = s;

        arr = new int[size];

        for(int i = 0; i < size; i++) {
            arr[i] = 0;
        }
    }

    // Destructor
    ~BloomFilter() {
        delete[] arr;
    }

    // Hash Functions
    int hash1(int key) {
        return key % size;
    }

    int hash2(int key) {
        return (key / size) % size;
    }

    int hash3(int key) {
        return ((7 * key) + 3) % size;
    }

    // Insert Element
    void insert(int key) {

        int h1 = hash1(key);
        int h2 = hash2(key);
        int h3 = hash3(key);

        arr[h1] = 1;
        arr[h2] = 1;
        arr[h3] = 1;

        cout << "\nData Inserted Successfully!\n";

        cout << "Hash Positions Set:\n";
        cout << "H1 = " << h1 << endl;
        cout << "H2 = " << h2 << endl;
        cout << "H3 = " << h3 << endl;
    }

    // Search Element
    void search(int key) {

        int h1 = hash1(key);
        int h2 = hash2(key);
        int h3 = hash3(key);

        cout << "\nChecking Positions:\n";
        cout << "H1 = " << h1 << endl;
        cout << "H2 = " << h2 << endl;
        cout << "H3 = " << h3 << endl;

        if(arr[h1] == 1 &&
           arr[h2] == 1 &&
           arr[h3] == 1) {

            cout << "\nData MAY be present "
                 << "(Possible False Positive)\n";
        }
        else {
            cout << "\nData NOT present\n";
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

// ======================================================
//             COUNT MIN SKETCH CLASS
// ======================================================

class CountMinSketch {

    int d, w;
    int **table;

public:

    // Constructor
    CountMinSketch(int rows, int columns) {

        d = rows;
        w = columns;

        table = new int*[d];

        for(int i = 0; i < d; i++) {

            table[i] = new int[w];

            for(int j = 0; j < w; j++) {
                table[i][j] = 0;
            }
        }
    }

    // Destructor
    ~CountMinSketch() {

        for(int i = 0; i < d; i++) {
            delete[] table[i];
        }

        delete[] table;
    }

    // Hash Function
    int hash(int key, int i) {

        return (key + (i * 31)) % w;
    }

    // Insert
    void insert(int key) {

        for(int i = 0; i < d; i++) {

            int idx = hash(key, i);

            table[i][idx]++;
        }

        cout << "\nData Inserted Successfully!\n";
    }

    // Get Frequency
    int getCount(int key) {

        int min = 999;

        for(int i = 0; i < d; i++) {

            int idx = hash(key, i);

            if(table[i][idx] < min) {
                min = table[i][idx];
            }
        }

        return min;
    }

    // Display Table
    void display() {

        cout << "\nCount-Min Sketch Matrix:\n";

        for(int i = 0; i < d; i++) {

            for(int j = 0; j < w; j++) {

                cout << table[i][j] << " ";
            }

            cout << endl;
        }
    }
};

// ======================================================
//                     MAIN FUNCTION
// ======================================================

int main() {

    int choice;

    // Objects
    BloomFilter *bf = new BloomFilter(10);
    CountMinSketch *cms = new CountMinSketch(2, 5);

    do {

        cout << "\n====================================";
        cout << "\n PROBABILISTIC DATA STRUCTURES MENU";
        cout << "\n====================================";

        cout << "\n1. Bloom Filter Insert";
        cout << "\n2. Bloom Filter Search";
        cout << "\n3. Display Bloom Filter";

        cout << "\n4. Count-Min Sketch Insert";
        cout << "\n5. Get Frequency";
        cout << "\n6. Display Count-Min Sketch";

        cout << "\n7. Exit";

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch(choice) {

            // ==================================================
            // BLOOM FILTER INSERT
            // ==================================================

            case 1: {

                int key;

                cout << "\nEnter data to insert: ";
                cin >> key;

                bf->insert(key);

                break;
            }

            // ==================================================
            // BLOOM FILTER SEARCH
            // ==================================================

            case 2: {

                int key;

                cout << "\nEnter data to search: ";
                cin >> key;

                bf->search(key);

                break;
            }

            // ==================================================
            // DISPLAY BLOOM FILTER
            // ==================================================

            case 3:

                bf->display();

                break;

            // ==================================================
            // COUNT MIN SKETCH INSERT
            // ==================================================

            case 4: {

                int key;

                cout << "\nEnter data to insert: ";
                cin >> key;

                cms->insert(key);

                break;
            }

            // ==================================================
            // GET FREQUENCY
            // ==================================================

            case 5: {

                int key;

                cout << "\nEnter element to get frequency: ";
                cin >> key;

                int freq = cms->getCount(key);

                cout << "\nEstimated Frequency of "
                     << key << " = " << freq << endl;

                break;
            }

            // ==================================================
            // DISPLAY CMS
            // ==================================================

            case 6:

                cms->display();

                break;

            // ==================================================
            // EXIT
            // ==================================================

            case 7:

                cout << "\nProgram Ended Successfully...\n";

                break;

            // ==================================================
            // INVALID
            // ==================================================

            default:

                cout << "\nInvalid Choice! Try Again.\n";
        }

    } while(choice != 7);

    // Memory Cleanup
    delete bf;
    delete cms;

    return 0;
}
