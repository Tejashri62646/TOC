#include <iostream>
using namespace std;

class Node {
public:

    int bookId;
    string name;
    float price;

    Node *left, *right;

    bool lthread;
    bool rthread;

    Node(int id, string n, float p) {

        bookId = id;
        name = n;
        price = p;

        left = right = NULL;

        lthread = true;
        rthread = true;
    }
};

class TBT {

public:

    Node* root;

    TBT() {
        root = NULL;
    }

    // Insert Node
    void insert(int id, string name, float price) {

        Node* newNode = new Node(id, name, price);

        // First Node
        if(root == NULL) {
            root = newNode;
            return;
        }

        Node* current = root;
        Node* parent = NULL;

        while(current != NULL) {

            if(id == current->bookId) {
                cout << "Duplicate Book ID not allowed\n";
                return;
            }

            parent = current;

            // Move Left
            if(id < current->bookId) {

                if(current->lthread == false)
                    current = current->left;
                else
                    break;
            }

            // Move Right
            else {

                if(current->rthread == false)
                    current = current->right;
                else
                    break;
            }
        }

        // Insert Left
        if(id < parent->bookId) {

            newNode->left = parent->left;
            newNode->right = parent;

            parent->lthread = false;
            parent->left = newNode;
        }

        // Insert Right
        else {

            newNode->left = parent;
            newNode->right = parent->right;

            parent->rthread = false;
            parent->right = newNode;
        }
    }

    // Inorder Successor
    Node* inorderSuccessor(Node* ptr) {

        if(ptr->rthread == true)
            return ptr->right;

        ptr = ptr->right;

        while(ptr->lthread == false)
            ptr = ptr->left;

        return ptr;
    }

    // Recursive Inorder Traversal
	void inorderRecursive(Node* root) {
	
	    if(root == NULL)
	        return;
	
	    // Visit Left Child
	    if(root->lthread == false)
	        inorderRecursive(root->left);
	
	    cout << "Book ID: " << root->bookId
	         << "  Name: " << root->name
	         << "  Price: " << root->price << endl;
	
	    // Visit Right Child
	    if(root->rthread == false)
	        inorderRecursive(root->right);
	}

    // Recursive Preorder Traversal
	void preorderRecursive(Node* root) {
	
	    if(root == NULL)
	        return;
	
	    cout << "Book ID: " << root->bookId
	         << "  Name: " << root->name
	         << "  Price: " << root->price << endl;
	
	    // Visit Left Child
	    if(root->lthread == false)
	        preorderRecursive(root->left);
	
	    // Visit Right Child
	    if(root->rthread == false)
	        preorderRecursive(root->right);
	}
    
    // Recursive Postorder Traversal
	void postorderRecursive(Node* root) {
	
	    if(root == NULL)
	        return;
	
	    // Visit Left Child
	    if(root->lthread == false)
	        postorderRecursive(root->left);
	
	    // Visit Right Child
	    if(root->rthread == false)
	        postorderRecursive(root->right);
	
	    cout << "Book ID: " << root->bookId
	         << "  Name: " << root->name
	         << "  Price: " << root->price << endl;
	}
};

int main() {

    TBT tree;

    int choice, id;
    string name;
    float price;

    do {

        cout << "\n===== Book Record Management =====\n";

        cout << "1. Insert Book\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Preorder Traversal\n";
        cout << "4. Postorder Traversal\n";
		cout << "5. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {

        case 1:

            cout << "Enter Book ID: ";
            cin >> id;

            cout << "Enter Book Name: ";
            cin >> name;

            cout << "Enter Price: ";
            cin >> price;

            tree.insert(id, name, price);

            cout << "Book Inserted Successfully\n";
            break;

       case 2:
	   
	       cout << "\nRecursive Inorder Traversal:\n";
	       tree.inorderRecursive(tree.root);
	       break;
	   
	   case 3:
	   
	       cout << "\nRecursive Preorder Traversal:\n";
	       tree.preorderRecursive(tree.root);
	       break;
	   
	   case 4:
	   
	       cout << "\nRecursive Postorder Traversal:\n";
	       tree.postorderRecursive(tree.root);
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
