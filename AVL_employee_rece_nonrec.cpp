#include <iostream>
#include <stack>
using namespace std;

class Node {

public:

    int empId;
    string name;
    float salary;

    Node* left;
    Node* right;

    int height;

    Node(int id, string n, float sal) {

        empId = id;
        name = n;
        salary = sal;

        left = right = NULL;

        height = 1;
    }
};

class AVL {

public:

    Node* root;

    AVL() {
        root = NULL;
    }

    // Height Function
    int getHeight(Node* node) {

        if(node == NULL)
            return 0;

        return node->height;
    }

    // Maximum Function
    int max(int a, int b) {
        return (a > b) ? a : b;
    }

    // Balance Factor
    int getBalance(Node* node) {

        if(node == NULL)
            return 0;

        return getHeight(node->left)
               - getHeight(node->right);
    }

    // Right Rotation
    Node* rightRotate(Node* y) {

        cout << "Right Rotation Performed\n";

        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(getHeight(y->left),
                        getHeight(y->right)) + 1;

        x->height = max(getHeight(x->left),
                        getHeight(x->right)) + 1;

        return x;
    }

    // Left Rotation
    Node* leftRotate(Node* x) {

        cout << "Left Rotation Performed\n";

        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(getHeight(x->left),
                        getHeight(x->right)) + 1;

        y->height = max(getHeight(y->left),
                        getHeight(y->right)) + 1;

        return y;
    }

    // Insert Node
    Node* insert(Node* node,
                 int id,
                 string name,
                 float salary) {

        // Normal BST Insert
        if(node == NULL)
            return new Node(id, name, salary);

        if(id < node->empId)
            node->left = insert(node->left,
                                id, name, salary);

        else if(id > node->empId)
            node->right = insert(node->right,
                                 id, name, salary);

        else
            return node;

        // Update Height
        node->height = 1 + max(getHeight(node->left),
                               getHeight(node->right));

        // Get Balance Factor
        int balance = getBalance(node);

        // LL Rotation
        if(balance > 1 && id < node->left->empId) {

            cout << "LL Rotation\n";
            return rightRotate(node);
        }

        // RR Rotation
        if(balance < -1 && id > node->right->empId) {

            cout << "RR Rotation\n";
            return leftRotate(node);
        }

        // LR Rotation
        if(balance > 1 && id > node->left->empId) {

            cout << "LR Rotation\n";

            node->left = leftRotate(node->left);

            return rightRotate(node);
        }

        // RL Rotation
        if(balance < -1 && id < node->right->empId) {

            cout << "RL Rotation\n";

            node->right = rightRotate(node->right);

            return leftRotate(node);
        }

        return node;
    }

    // Recursive Inorder
    void inorder(Node* root) {

        if(root != NULL) {

            inorder(root->left);

            cout << "ID: " << root->empId
                 << "  Name: " << root->name
                 << "  Salary: " << root->salary << endl;

            inorder(root->right);
        }
    }

    // Recursive Preorder
    void preorder(Node* root) {

        if(root != NULL) {

            cout << "ID: " << root->empId
                 << "  Name: " << root->name
                 << "  Salary: " << root->salary << endl;

            preorder(root->left);

            preorder(root->right);
        }
    }

    // Recursive Postorder
    void postorder(Node* root) {

        if(root != NULL) {

            postorder(root->left);

            postorder(root->right);

            cout << "ID: " << root->empId
                 << "  Name: " << root->name
                 << "  Salary: " << root->salary << endl;
        }
    }

    // Non Recursive Inorder
    void nonRecInorder(Node* root) {

        stack<Node*> st;
        Node* temp = root;

        while(temp != NULL || !st.empty()) {

            while(temp != NULL) {
                st.push(temp);
                temp = temp->left;
            }

            temp = st.top();
            st.pop();

            cout << "ID: " << temp->empId
                 << "  Name: " << temp->name
                 << "  Salary: " << temp->salary << endl;

            temp = temp->right;
        }
    }

    // Non Recursive Preorder
    void nonRecPreorder(Node* root) {

        if(root == NULL)
            return;

        stack<Node*> st;

        st.push(root);

        while(!st.empty()) {

            Node* temp = st.top();
            st.pop();

            cout << "ID: " << temp->empId
                 << "  Name: " << temp->name
                 << "  Salary: " << temp->salary << endl;

            if(temp->right != NULL)
                st.push(temp->right);

            if(temp->left != NULL)
                st.push(temp->left);
        }
    }

    // Non Recursive Postorder
    void nonRecPostorder(Node* root) {

        if(root == NULL)
            return;

        stack<Node*> st1, st2;

        st1.push(root);

        while(!st1.empty()) {

            Node* temp = st1.top();
            st1.pop();

            st2.push(temp);

            if(temp->left != NULL)
                st1.push(temp->left);

            if(temp->right != NULL)
                st1.push(temp->right);
        }

        while(!st2.empty()) {

            Node* temp = st2.top();
            st2.pop();

            cout << "ID: " << temp->empId
                 << "  Name: " << temp->name
                 << "  Salary: " << temp->salary << endl;
        }
    }
};

int main() {

    AVL tree;

    int choice, id;
    string name;
    float salary;

    do {

        cout << "\n===== Employee Management System =====\n";

        cout << "1. Insert Employee\n";
        cout << "2. Recursive Inorder\n";
        cout << "3. Recursive Preorder\n";
        cout << "4. Recursive Postorder\n";
        cout << "5. Non Recursive Inorder\n";
        cout << "6. Non Recursive Preorder\n";
        cout << "7. Non Recursive Postorder\n";
        cout << "8. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {

        case 1:

            cout << "Enter Employee ID: ";
            cin >> id;

            cout << "Enter Employee Name: ";
            cin >> name;

            cout << "Enter Salary: ";
            cin >> salary;

            tree.root = tree.insert(tree.root,
                                    id, name, salary);

            cout << "Employee Inserted\n";
            break;

        case 2:

            cout << "\nRecursive Inorder:\n";
            tree.inorder(tree.root);
            break;

        case 3:

            cout << "\nRecursive Preorder:\n";
            tree.preorder(tree.root);
            break;

        case 4:

            cout << "\nRecursive Postorder:\n";
            tree.postorder(tree.root);
            break;

        case 5:

            cout << "\nNon Recursive Inorder:\n";
            tree.nonRecInorder(tree.root);
            break;

        case 6:

            cout << "\nNon Recursive Preorder:\n";
            tree.nonRecPreorder(tree.root);
            break;

        case 7:

            cout << "\nNon Recursive Postorder:\n";
            tree.nonRecPostorder(tree.root);
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
