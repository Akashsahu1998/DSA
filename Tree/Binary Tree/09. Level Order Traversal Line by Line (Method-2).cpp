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
    
    while(q.empty() == false){
    	int size = q.size();
    	
    	for(int itr = 0; itr < size; itr++){
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
		cout << "\n";
	}
}

int main(){
	Node *root = new Node(10);
	root->left = new Node(20);
	root->left->left = new Node(40);
	root->left->right = new Node(50);
	root->right = new Node(30);
	root->right->right = new Node(60);

    cout << "Level order traversal Tree : \n";
    levelOrderTraversal(root);    
}

// Time Complexity = O(N)
// Space Complexity = O(W), where W is the width of the binary tree
