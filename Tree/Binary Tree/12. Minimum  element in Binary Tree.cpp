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

void levelOrderTraversal(Node *root){
    if(root == NULL) return;
    queue<Node*> q;
    q.push(root);
    
    while(q.size() != 0){
    	Node *cur = q.front();
    	q.pop();
		cout << cur->key << " ";
		if(cur->left != NULL){
			q.push(cur->left);
		}
		if(cur->right != NULL){
			q.push(cur->right);
		}
	}
}

//int findMin(Node *root){
//    if(root == NULL)
//	    return -1;  
//	else if(root->left == NULL && root->right == NULL)
//		return root->key;
//	else if(root->left != NULL && root->right != NULL)
//		return min(root->key, min(findMin(root->left), findMin(root->right)));
//	else if(root->left != NULL)
//		return min(root->key, findMin(root->left));
//	else
//		return min(root->key, findMin(root->right));
//}

int findMin(Node *root){
	if(root == NULL)
		return INT_MAX;
	else 
		return min(root->key, min(findMin(root->left), findMin(root->right)));
}

int main(){
	Node *root = new Node(10);
	root->left = new Node(20);
	root->left->left = new Node(40);
	root->left->right = new Node(50);
	root->right = new Node(30);
	root->right->right = new Node(70);
	
    cout << "Given Tree : ";
    levelOrderTraversal(root);
    
    cout << "\nMaximum : " << findMin(root);       
}

// Time Complexity = O(N)
// Space Complexity = O(W), where W is the width of the binary tree
