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

//int findMax(Node *root){
//	if(root == NULL)
//		return -1;
//	else if(root->left == NULL && root->right == NULL)
//		return root->key;
//	else if(root->left != NULL && root->right != NULL)
//		return max(root->key, max(findMax(root->left), findMax(root->right)));
//	else if(root->left != NULL)
//		return max(root->key, findMax(root->left));
//	else
//		return max(root->key, findMax(root->right));		
//}

int findMax(Node *root){
	if(root == NULL)
		return INT_MIN;
	else 
		return max(root->key, max(findMax(root->left), findMax(root->right)));
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
    
    cout << "\nMaximum : " << findMax(root);       
}

// Time Complexity = O(N)
// Space Complexity = O(W), where W is the width of the binary tree
