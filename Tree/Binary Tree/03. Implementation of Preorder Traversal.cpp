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
        cout << root->key << " ";
		inorder(root->left);
        inorder(root->right);
    }
}

int main(){
	Node *root = new Node(10);
	root->left = new Node(20);
	root->right = new Node(30);
	root->right->left = new Node(40);
	root->right->right = new Node(50);

    inorder(root);
}

// Time Complexity = O(N)
// Space Complexity = O(H), where H is the height of the binary tree