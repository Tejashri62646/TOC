#include <iostream>
#include <stack>
using namespace std;

class Node {

public:

    int data;
    Node* left;
    Node* right;
    int height;

    Node(int value) {

        data = value;
        left = right = NULL;
        height = 1;
    }
};

class AVLTree {

public:

    Node* root;

    AVLTree() {

        root = NULL;
    }

    // Get Height
    int getHeight(Node* node) {

        if (node == NULL)
            return 0;

        return node->height;
    }

    // Get Maximum
    int getMax(int a, int b) {

        return (a > b) ? a : b;
    }

    // Get Balance Factor
    int getBalance(Node* node) {

        if (node == NULL)
            return 0;

        return getHeight(node->left)
             - getHeight(node->right);
    }

    // Right Rotation
    Node* rightRotate(Node* y) {

        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = 1 + getMax(getHeight(y->left),
                               getHeight(y->right));

        x->height = 1 + getMax(getHeight(x->left),
                               getHeight(x->right));

        return x;
    }

    // Left Rotation
    Node* leftRotate(Node* x) {

        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = 1 + getMax(getHeight(x->left),
                               getHeight(x->right));

        y->height = 1 + getMax(getHeight(y->left),
                               getHeight(y->right));

        return y;
    }

    // Insert Node
    Node* insert(Node* node, int key) {

        // Normal BST Insert
        if (node == NULL)
            return new Node(key);

        if (key < node->data)
            node->left = insert(node->left, key);

        else if (key > node->data)
            node->right = insert(node->right, key);

        else
            return node;

        // Update Height
        node->height = 1 + getMax(getHeight(node->left),
                                  getHeight(node->right));

        // Get Balance Factor
        int balance = getBalance(node);

        // LL Rotation
        if (balance > 1 &&
            key < node->left->data) {

            cout << "LL Rotation Applied at Node "
                 << node->data << endl;

            return rightRotate(node);
        }

        // RR Rotation
        if (balance < -1 &&
            key > node->right->data) {

            cout << "RR Rotation Applied at Node "
                 << node->data << endl;

            return leftRotate(node);
        }

        // LR Rotation
        if (balance > 1 &&
            key > node->left->data) {

            cout << "LR Rotation Applied at Node "
                 << node->data << endl;

            node->left = leftRotate(node->left);

            return rightRotate(node);
        }

        // RL Rotation
        if (balance < -1 &&
            key < node->right->data) {

            cout << "RL Rotation Applied at Node "
                 << node->data << endl;

            node->right = rightRotate(node->right);

            return leftRotate(node);
        }

        return node;
    }

    // Recursive Inorder
    void inorder(Node* node) {

        if (node != NULL) {

            inorder(node->left);

            cout << node->data << " ";

            inorder(node->right);
        }
    }

    // Recursive Preorder
    void preorder(Node* node) {

        if (node != NULL) {

            cout << node->data << " ";

            preorder(node->left);

            preorder(node->right);
        }
    }

    // Recursive Postorder
    void postorder(Node* node) {

        if (node != NULL) {

            postorder(node->left);

            postorder(node->right);

            cout << node->data << " ";
        }
    }

    // Non Recursive Inorder
    void nonRecursiveInorder(Node* root) {

        stack<Node*> s;
        Node* curr = root;

        while (curr != NULL || !s.empty()) {

            while (curr != NULL) {

                s.push(curr);

                curr = curr->left;
            }

            curr = s.top();
            s.pop();

            cout << curr->data << " ";

            curr = curr->right;
        }
    }

    // Non Recursive Preorder
    void nonRecursivePreorder(Node* root) {

        if (root == NULL)
            return;

        stack<Node*> s;

        s.push(root);

        while (!s.empty()) {

            Node* curr = s.top();
            s.pop();

            cout << curr->data << " ";

            if (curr->right)
                s.push(curr->right);

            if (curr->left)
                s.push(curr->left);
        }
    }

    // Non Recursive Postorder
    void nonRecursivePostorder(Node* root) {

        if (root == NULL)
            return;

        stack<Node*> s1, s2;

        s1.push(root);

        while (!s1.empty()) {

            Node* curr = s1.top();
            s1.pop();

            s2.push(curr);

            if (curr->left)
                s1.push(curr->left);

            if (curr->right)
                s1.push(curr->right);
        }

        while (!s2.empty()) {

            cout << s2.top()->data << " ";

            s2.pop();
        }
    }
};

int main() {

    AVLTree tree;

    int choice, value;

    do {

        cout << "\n===== AVL TREE MENU =====\n";

        cout << "1. Insert Node\n";
        cout << "2. Recursive Inorder\n";
        cout << "3. Recursive Preorder\n";
        cout << "4. Recursive Postorder\n";
        cout << "5. Non Recursive Inorder\n";
        cout << "6. Non Recursive Preorder\n";
        cout << "7. Non Recursive Postorder\n";
        cout << "8. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice) {

        case 1:

            cout << "Enter Value: ";
            cin >> value;

            tree.root = tree.insert(tree.root,
                                    value);

            cout << "Node Inserted\n";

            break;

        case 2:

            cout << "Recursive Inorder: ";

            tree.inorder(tree.root);

            cout << endl;

            break;

        case 3:

            cout << "Recursive Preorder: ";

            tree.preorder(tree.root);

            cout << endl;

            break;

        case 4:

            cout << "Recursive Postorder: ";

            tree.postorder(tree.root);

            cout << endl;

            break;

        case 5:

            cout << "Non Recursive Inorder: ";

            tree.nonRecursiveInorder(tree.root);

            cout << endl;

            break;

        case 6:

            cout << "Non Recursive Preorder: ";

            tree.nonRecursivePreorder(tree.root);

            cout << endl;

            break;

        case 7:

            cout << "Non Recursive Postorder: ";

            tree.nonRecursivePostorder(tree.root);

            cout << endl;

            break;

        case 8:

            cout << "Program Ended\n";

            break;

        default:

            cout << "Invalid Choice\n";
        }

    } while(choice != 8);

    return 0;
}
