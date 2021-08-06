#include<bits/stdc++.h>
using namespace std;

struct Node{
	int key;
	Node *left;
	Node *right;
	
	Node(int k){
		key = k;
		left = NULL;
		right = NULL;
	}
};

void inorder(Node *root){
    if(root != NULL){
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

int printNodesAtkDistance(Node *root, int k){
    if(root == NULL) return 0;
    else if(k == 0) cout << root->key << " ";
    else{
    	printNodesAtkDistance(root->left, k-1);
    	printNodesAtkDistance(root->right, k-1);
	}    
}

int main(){
	Node *root = new Node(10);
	root->left = new Node(20);
	root->left->left = new Node(40);
	root->left->right = new Node(50);
	root->right = new Node(30);	
	root->right->right = new Node(70);

    cout << "Original Tree : ";
    inorder(root);
    cout << endl;
    cout << "Distance Tree : ";
    printNodesAtkDistance(root, 2);
}

// Time Complexity = O(N)
// Space Complexity = O(H), where H is the height of the binary tree
