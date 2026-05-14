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

    // Non Recursive Inorder Traversal
    void inorder() {

        if(root == NULL) {
            cout << "Tree is Empty\n";
            return;
        }

        Node* current = root;

        // Move to leftmost node
        while(current->lthread == false)
            current = current->left;

        while(current != NULL) {

            cout << "Book ID: " << current->bookId
                 << "  Name: " << current->name
                 << "  Price: " << current->price << endl;

            current = inorderSuccessor(current);
        }
    }

    // Non Recursive Preorder Traversal
    void preorder() {

        if(root == NULL) {
            cout << "Tree is Empty\n";
            return;
        }

        Node* current = root;

        while(current != NULL) {

            cout << "Book ID: " << current->bookId
                 << "  Name: " << current->name
                 << "  Price: " << current->price << endl;

            // Move Left
            if(current->lthread == false) {
                current = current->left;
            }

            // Move Right using threads
            else {

                while(current != NULL && current->rthread == true)
                    current = current->right;

                if(current != NULL)
                    current = current->right;
            }
        }
    }
    
    // Non Recursive Postorder Traversal
	void postorder() {
	
	    if(root == NULL) {
	        cout << "Tree is Empty\n";
	        return;
	    }
	
	    Node* stack1[100];
	    Node* stack2[100];
	
	    int top1 = -1;
	    int top2 = -1;
	
	    stack1[++top1] = root;
	
	    while(top1 != -1) {
	
	        Node* temp = stack1[top1--];
	
	        stack2[++top2] = temp;
	
	        // Push Left Child
	        if(temp->lthread == false)
	            stack1[++top1] = temp->left;
	
	        // Push Right Child
	        if(temp->rthread == false)
	            stack1[++top1] = temp->right;
	    }
	
	    // Print Postorder
	    while(top2 != -1) {
	
	        Node* temp = stack2[top2--];
	
	        cout << "Book ID: " << temp->bookId
	             << "  Name: " << temp->name
	             << "  Price: " << temp->price << endl;
	    }
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

            cout << "\nInorder Traversal:\n";
            tree.inorder();
            break;

        case 3:

            cout << "\nPreorder Traversal:\n";
            tree.preorder();
            break;

       case 4:
	   
	       cout << "\nPostorder Traversal:\n";
	       tree.postorder();
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
