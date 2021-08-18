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

void findSpiral(Node *root){
    if(root == NULL) return;
    stack<Node*> stackLeftToRight;
    stack<Node*> stackRightToLeft;
    stackLeftToRight.push(root);
    
    while(!(stackLeftToRight.empty() && stackRightToLeft.empty())){
        while(!stackLeftToRight.empty()){
            Node* cur = stackLeftToRight.top();
            stackLeftToRight.pop();
            cout << cur->key << " ";
            if(cur->right != NULL)
                stackRightToLeft.push(cur->right);
            if(cur->left != NULL) 
                stackRightToLeft.push(cur->left);
        }
        cout << endl;
        while(!stackRightToLeft.empty()){
            Node* cur = stackRightToLeft.top();
            stackRightToLeft.pop();
            cout << cur->key << " ";
            if(cur->left != NULL) 
                stackLeftToRight.push(cur->left);
            if(cur->right != NULL)
                stackLeftToRight.push(cur->right);
        }
        cout << endl;
    } 
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
    cout << "\nSpriral Form : \n";
    findSpiral(root);
}

// Time Complexity = O(N)
// Space Complexity = O(W), where W is the width of the binary tree
