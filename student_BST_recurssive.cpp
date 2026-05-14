#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int rollNo;
    string name;
    Node* left;
    Node* right;

    Node(int r, string n) {
        rollNo = r;
        name = n;
        left = right = NULL;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = NULL;
    }

    // Insert Node
    Node* insert(Node* root, int rollNo, string name) {
        if (root == NULL) {
            return new Node(rollNo, name);
        }

        if (rollNo < root->rollNo) {
            root->left = insert(root->left, rollNo, name);
        }
        else if (rollNo > root->rollNo) {
            root->right = insert(root->right, rollNo, name);
        }

        return root;
    }

    // Search Node
    void search(Node* root, int key) {
        if (root == NULL) {
            cout << "Student not found\n";
            return;
        }

        if (key == root->rollNo) {
            cout << "Student Found\n";
            cout << "Roll No: " << root->rollNo << endl;
            cout << "Name: " << root->name << endl;
            return;
        }

        if (key < root->rollNo)
            search(root->left, key);
        else
            search(root->right, key);
    }

    // Find Minimum Node
    Node* findMin(Node* root) {
        while (root->left != NULL) {
            root = root->left;
        }
        return root;
    }

    // Delete Node
    Node* deleteNode(Node* root, int key) {
        if (root == NULL)
            return NULL;

        if (key < root->rollNo) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->rollNo) {
            root->right = deleteNode(root->right, key);
        }
        else {

            // No Child
            if (root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }

            // One Child
            else if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            }

            else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            // Two Children
            Node* temp = findMin(root->right);

            root->rollNo = temp->rollNo;
            root->name = temp->name;

            root->right = deleteNode(root->right, temp->rollNo);
        }

        return root;
    }

    // Inorder Traversal
    void inorder(Node* root) {
        if (root != NULL) {
            inorder(root->left);
            cout << root->rollNo << " - " << root->name << endl;
            inorder(root->right);
        }
    }

    // Preorder Traversal
    void preorder(Node* root) {
        if (root != NULL) {
            cout << root->rollNo << " - " << root->name << endl;
            preorder(root->left);
            preorder(root->right);
        }
    }

    // Postorder Traversal
    void postorder(Node* root) {
        if (root != NULL) {
            postorder(root->left);
            postorder(root->right);
            cout << root->rollNo << " - " << root->name << endl;
        }
    }

    // Level Wise Printing
    void levelOrder(Node* root) {
        if (root == NULL)
            return;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            cout << temp->rollNo << " - " << temp->name << endl;

            if (temp->left != NULL)
                q.push(temp->left);

            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
};

int main() {
    BST tree;
    int choice, rollNo;
    string name;

    do {
        cout << "\n===== Student Record Management =====\n";
        cout << "1. Insert Student\n";
        cout << "2. Search Student\n";
        cout << "3. Delete Student\n";
        cout << "4. Inorder Traversal\n";
        cout << "5. Preorder Traversal\n";
        cout << "6. Postorder Traversal\n";
        cout << "7. Level Wise Display\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {

        case 1:
            cout << "Enter Roll No: ";
            cin >> rollNo;

            cout << "Enter Name: ";
            cin >> name;

            tree.root = tree.insert(tree.root, rollNo, name);
            cout << "Student Inserted\n";
            break;

        case 2:
            cout << "Enter Roll No to Search: ";
            cin >> rollNo;

            tree.search(tree.root, rollNo);
            break;

        case 3:
            cout << "Enter Roll No to Delete: ";
            cin >> rollNo;

            tree.root = tree.deleteNode(tree.root, rollNo);
            cout << "Student Deleted\n";
            break;

        case 4:
            cout << "\nInorder Traversal:\n";
            tree.inorder(tree.root);
            break;

        case 5:
            cout << "\nPreorder Traversal:\n";
            tree.preorder(tree.root);
            break;

        case 6:
            cout << "\nPostorder Traversal:\n";
            tree.postorder(tree.root);
            break;

        case 7:
            cout << "\nLevel Wise Display:\n";
            tree.levelOrder(tree.root);
            break;

        case 8:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid Choice\n";
        }

    } while(choice != 8);

    return 0;
}
