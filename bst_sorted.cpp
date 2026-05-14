#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class BST {
public:

    Node* insert(Node* root, int val) {

        if(root == NULL)
            return new Node(val);

        if(val < root->data)
            root->left = insert(root->left, val);

        else
            root->right = insert(root->right, val);

        return root;
    }

    void inorder(Node* root) {

        if(root != NULL) {
            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);
        }
    }
};

int main() {

    BST b;
    Node* root = NULL;

    int arr[] = {30,20,16,14,10,5};

    for(int i=0; i<6; i++) {
        root = b.insert(root, arr[i]);
    }

    cout<<"Inorder Traversal:\n";
    b.inorder(root);

    return 0;
}
