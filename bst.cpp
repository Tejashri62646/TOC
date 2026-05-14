#include<iostream>
#include<stack>
#include<queue>

using namespace std;

class node{
	public:
	int data;
	node *left;
	node *right;

	node(int val){
		data = val;
		left = right = NULL;
	}
};

class BST{

	public:

	node *root;

	BST(){
		root = NULL;
	}

	node* insert(node *root,int key);

	void Inorder_R(node *root);
	void Preorder_R(node *root);
	void Postorder_R(node *root);

	void Inorder_NR(node *root);
	void Preorder_NR(node *root);
	void Postorder_NR(node *root);

	void levelorder(node *root);

	bool isleafnode(node *root);

	node* inordersuccessor(node *right);

	node* deletenode(node *root,int key);
};



// INSERT
node* BST::insert(node *root,int key){

	if(root == NULL){
		return new node(key);
	}

	if(key < root->data){
		root->left = insert(root->left,key);
	}

	else if(key > root->data){
		root->right = insert(root->right,key);
	}

	return root;
}



// INORDER RECURSIVE
void BST::Inorder_R(node *root){

	if(root != NULL){

		Inorder_R(root->left);

		cout << root->data << " ";

		Inorder_R(root->right);
	}
}



// PREORDER RECURSIVE
void BST::Preorder_R(node *root){

	if(root != NULL){

		cout << root->data << " ";

		Preorder_R(root->left);

		Preorder_R(root->right);
	}
}



// POSTORDER RECURSIVE
void BST::Postorder_R(node *root){

	if(root != NULL){

		Postorder_R(root->left);

		Postorder_R(root->right);

		cout << root->data << " ";
	}
}



// CHECK LEAF NODE
bool BST::isleafnode(node *root){

	if(root->left == NULL && root->right == NULL){
		return true;
	}

	return false;
}



// INORDER SUCCESSOR
node* BST::inordersuccessor(node *right){

	while(right != NULL && right->left != NULL){
		right = right->left;
	}

	return right;
}



// DELETE NODE
node* BST::deletenode(node *root,int key){

	// TREE EMPTY
	if(root == NULL){
		cout << "Node not found\n";
		return NULL;
	}

	// SEARCH LEFT
	if(key < root->data){

		root->left = deletenode(root->left,key);
	}

	// SEARCH RIGHT
	else if(key > root->data){

		root->right = deletenode(root->right,key);
	}

	// NODE FOUND
	else{

		// LEAF NODE
		if(root->left == NULL && root->right == NULL){

			delete root;

			return NULL;
		}

		// ONLY RIGHT CHILD
		else if(root->left == NULL){

			node *temp = root->right;

			delete root;

			return temp;
		}

		// ONLY LEFT CHILD
		else if(root->right == NULL){

			node *temp = root->left;

			delete root;

			return temp;
		}

		// TWO CHILDREN
		else{

			node *temp = inordersuccessor(root->right);

			root->data = temp->data;

			root->right = deletenode(root->right,temp->data);
		}
	}

	return root;
}



// INORDER NON-RECURSIVE
void BST::Inorder_NR(node *root){

	if(root == NULL){
		cout << "Tree is empty";
		return;
	}

	stack<node*> st;

	node *current = root;

	while(current != NULL || !st.empty()){

		while(current != NULL){

			st.push(current);

			current = current->left;
		}

		current = st.top();

		st.pop();

		cout << current->data << " ";

		current = current->right;
	}
}



// PREORDER NON-RECURSIVE
void BST::Preorder_NR(node *root){

	if(root == NULL){
		cout << "Tree is empty";
		return;
	}

	stack<node*> st;

	st.push(root);

	while(!st.empty()){

		node *current = st.top();

		st.pop();

		cout << current->data << " ";

		if(current->right != NULL){
			st.push(current->right);
		}

		if(current->left != NULL){
			st.push(current->left);
		}
	}
}



// POSTORDER NON-RECURSIVE
void BST::Postorder_NR(node *root){

	if(root == NULL){
		cout << "Tree is empty";
		return;
	}

	stack<node*> st1,st2;

	st1.push(root);

	while(!st1.empty()){

		node *current = st1.top();

		st1.pop();

		st2.push(current);

		if(current->left != NULL){
			st1.push(current->left);
		}

		if(current->right != NULL){
			st1.push(current->right);
		}
	}

	while(!st2.empty()){

		node *current = st2.top();

		st2.pop();

		cout << current->data << " ";
	}
}



// LEVEL ORDER
void BST::levelorder(node *root){

	if(root == NULL){
		cout << "Tree is empty";
		return;
	}

	queue<node*> q;

	q.push(root);

	while(!q.empty()){

		node *current = q.front();

		q.pop();

		cout << current->data << " ";

		if(current->left != NULL){
			q.push(current->left);
		}

		if(current->right != NULL){
			q.push(current->right);
		}
	}
}



// MAIN FUNCTION
int main(){

	BST tree;

	int choice,key;

	do{

		cout << "\n\n===== BST MENU =====";

		cout << "\n1. Insert Node";
		cout << "\n2. Inorder Recursive";
		cout << "\n3. Preorder Recursive";
		cout << "\n4. Postorder Recursive";

		cout << "\n5. Inorder Non-Recursive";
		cout << "\n6. Preorder Non-Recursive";
		cout << "\n7. Postorder Non-Recursive";

		cout << "\n8. Level Order Traversal";

		cout << "\n9. Delete Node";

		cout << "\n10. Exit";

		cout << "\n\nEnter your choice: ";
		cin >> choice;

		switch(choice){

			case 1:

				cout << "Enter value: ";
				cin >> key;

				tree.root = tree.insert(tree.root,key);

				cout << "Node inserted successfully";

				break;


			case 2:

				cout << "Inorder Recursive: ";

				tree.Inorder_R(tree.root);

				break;


			case 3:

				cout << "Preorder Recursive: ";

				tree.Preorder_R(tree.root);

				break;


			case 4:

				cout << "Postorder Recursive: ";

				tree.Postorder_R(tree.root);

				break;


			case 5:

				cout << "Inorder Non-Recursive: ";

				tree.Inorder_NR(tree.root);

				break;


			case 6:

				cout << "Preorder Non-Recursive: ";

				tree.Preorder_NR(tree.root);

				break;


			case 7:

				cout << "Postorder Non-Recursive: ";

				tree.Postorder_NR(tree.root);

				break;


			case 8:

				cout << "Level Order Traversal: ";

				tree.levelorder(tree.root);

				break;


			case 9:

				cout << "Enter node to delete: ";
				cin >> key;

				tree.root = tree.deletenode(tree.root,key);

				cout << "Deletion completed";

				break;


			case 10:

				cout << "Program Ended";

				break;


			default:

				cout << "Invalid Choice";
		}

	}while(choice != 10);

	return 0;
}
