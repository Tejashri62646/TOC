#include<iostream>
#include<stack>
using namespace std;

class node{
public:
    int data;
    node *left;
    node *right;

    // 0 = child exists
    // 1 = thread
    int left_thread;
    int right_thread;

    node(int val){
        data = val;
        left = right = NULL;
        left_thread = right_thread = 1;
    }
};

class TBT{
public:
    node *root;

    TBT(){
        root = NULL;
    }

    node* insert(node *root, int key);

    void Inorder_R(node *root);
    void Preorder_R(node *root);
    void Postorder_R(node *root);

    void Inorder_NR(node *root);
    void Preorder_NR(node *root);
    void Postorder_NR(node *root);
};


// INSERT FUNCTION
node* TBT::insert(node *root, int key){

    if(root == NULL){
        node *temp = new node(key);
        return temp;
    }

    // LEFT SIDE
    if(key < root->data){

        if(root->left_thread == 0){
            root->left = insert(root->left, key);
        }

        else{
            node *temp = new node(key);

            temp->left = root->left;
            temp->right = root;

            root->left = temp;
            root->left_thread = 0;
        }
    }

    // RIGHT SIDE
    else if(key > root->data){

        if(root->right_thread == 0){
            root->right = insert(root->right, key);
        }

        else{
            node *temp = new node(key);

            temp->right = root->right;
            temp->left = root;

            root->right = temp;
            root->right_thread = 0;
        }
    }

    return root;
}


// RECURSIVE INORDER
void TBT::Inorder_R(node *root){

    if(root == NULL)
        return;

    if(root->left_thread == 0)
        Inorder_R(root->left);

    cout << root->data << " ";

    if(root->right_thread == 0)
        Inorder_R(root->right);
}


// RECURSIVE PREORDER
void TBT::Preorder_R(node *root){

    if(root == NULL)
        return;

    cout << root->data << " ";

    if(root->left_thread == 0)
        Preorder_R(root->left);

    if(root->right_thread == 0)
        Preorder_R(root->right);
}


// RECURSIVE POSTORDER
void TBT::Postorder_R(node *root){

    if(root == NULL)
        return;

    if(root->left_thread == 0)
        Postorder_R(root->left);

    if(root->right_thread == 0)
        Postorder_R(root->right);

    cout << root->data << " ";
}


// NON-RECURSIVE INORDER
void TBT::Inorder_NR(node *root){

    if(root == NULL){
        cout << "Tree is empty";
        return;
    }

    node *current = root;

    while(current->left_thread == 0){
        current = current->left;
    }

    while(current != NULL){

        cout << current->data << " ";

        if(current->right_thread == 1){
            current = current->right;
        }

        else{
            current = current->right;

            while(current != NULL &&
                  current->left_thread == 0){
                current = current->left;
            }
        }
    }
}


// NON-RECURSIVE PREORDER
void TBT::Preorder_NR(node *root){

    if(root == NULL){
        cout << "Tree is empty";
        return;
    }

    node *current = root;

    while(current != NULL){

        cout << current->data << " ";

        if(current->left_thread == 0){
            current = current->left;
        }

        else{

            while(current != NULL &&
                  current->right_thread == 1){
                current = current->right;
            }

            if(current != NULL)
                current = current->right;
        }
    }
}


// NON-RECURSIVE POSTORDER
void TBT::Postorder_NR(node *root){

    if(root == NULL){
        cout << "Tree is empty";
        return;
    }

    stack<node*> s1, s2;

    s1.push(root);

    while(!s1.empty()){

        node *temp = s1.top();
        s1.pop();

        s2.push(temp);

        // push left child
        if(temp->left_thread == 0){
            s1.push(temp->left);
        }

        // push right child
        if(temp->right_thread == 0){
            s1.push(temp->right);
        }
    }

    // print postorder
    while(!s2.empty()){

        cout << s2.top()->data << " ";
        s2.pop();
    }
}



int main(){

    TBT tree;

    int choice, key;

    do{

        cout << "\n\n===== THREADED BINARY TREE =====";
        cout << "\n1. Insert Node";
        cout << "\n2. Recursive Inorder";
        cout << "\n3. Recursive Preorder";
        cout << "\n4. Recursive Postorder";
        cout << "\n5. Non-Recursive Inorder";
        cout << "\n6. Non-Recursive Preorder";
        cout << "\n7. Non-Recursive Postorder";
        cout << "\n8. Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice){

        case 1:

            cout << "Enter value: ";
            cin >> key;

            tree.root = tree.insert(tree.root, key);

            cout << "Node inserted";
            break;

        case 2:

            cout << "\nRecursive Inorder: ";
            tree.Inorder_R(tree.root);
            break;

        case 3:

            cout << "\nRecursive Preorder: ";
            tree.Preorder_R(tree.root);
            break;

        case 4:

            cout << "\nRecursive Postorder: ";
            tree.Postorder_R(tree.root);
            break;

        case 5:

            cout << "\nNon-Recursive Inorder: ";
            tree.Inorder_NR(tree.root);
            break;

        case 6:

            cout << "\nNon-Recursive Preorder: ";
            tree.Preorder_NR(tree.root);
            break;

        case 7:

            cout << "\nNon-Recursive Postorder: ";
            tree.Postorder_NR(tree.root);
            break;

        case 8:

            cout << "\nProgram Ended";
            break;

        default:

            cout << "\nInvalid Choice";
        }

    }while(choice != 8);

    return 0;
}
