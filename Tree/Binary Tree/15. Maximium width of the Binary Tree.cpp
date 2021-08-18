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

int getMaxWidth(Node* root) {
    if(root == NULL) return 0;
    queue<Node*> q;
    q.push(root);
    int res = 0;
    while(!q.empty()){
       int size = q.size();
	    res = max(res, size);
        for(int itr = 0; itr < size; itr++){
            Node* cur = q.front();
            q.pop();
            
            if(cur->left != NULL) q.push(cur->left);
            if(cur->right != NULL) q.push(cur->right);
        }
	}
    return res;
}

int main(){
	Node *root = new Node(18);
	root->left = new Node(4);		
	root->right = new Node(20);
	root->right->left = new Node(13);
	root->right->right = new Node(70);
	root->right->right->left = new Node(80);
	
    cout << "Given Tree : ";
    levelOrderTraversal(root);
    cout << "\nWidth : " << getMaxWidth(root);
}

// Time Complexity = O(N)
// Space Complexity = O(W), where W is the width of the binary tree
