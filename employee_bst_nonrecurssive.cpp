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

    Node(int id, string n, float sal) {
        empId = id;
        name = n;
        salary = sal;

        left = right = NULL;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = NULL;
    }

    // Insert Employee
    Node* insert(Node* root, int id, string name, float salary) {

        if(root == NULL) {
            return new Node(id, name, salary);
        }

        if(id < root->empId) {
            root->left = insert(root->left, id, name, salary);
        }
        else if(id > root->empId) {
            root->right = insert(root->right, id, name, salary);
        }

        return root;
    }

    // Non Recursive Inorder
    void inorder(Node* root) {

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
    void preorder(Node* root) {

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
    void postorder(Node* root) {

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

    BST tree;

    int choice, id;
    string name;
    float salary;

    do {

        cout << "\n===== Employee Management System =====\n";

        cout << "1. Insert Employee\n";
        cout << "2. Non Recursive Inorder\n";
        cout << "3. Non Recursive Preorder\n";
        cout << "4. Non Recursive Postorder\n";
        cout << "5. Exit\n";

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

            tree.root = tree.insert(tree.root, id, name, salary);

            cout << "Employee Inserted Successfully\n";
            break;

        case 2:

            cout << "\nNon Recursive Inorder Traversal:\n";
            tree.inorder(tree.root);
            break;

        case 3:

            cout << "\nNon Recursive Preorder Traversal:\n";
            tree.preorder(tree.root);
            break;

        case 4:

            cout << "\nNon Recursive Postorder Traversal:\n";
            tree.postorder(tree.root);
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
