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

int findDiameter(Node* root, int &res){
    if(root == NULL) return 0;
    int lh = findDiameter(root->left, res);
    int rh = findDiameter(root->right, res);
    res = max(res, lh+rh+1);
    return 1 + max(lh, rh);
}

// 1st Approach
// Efficient Solution
int diameterOfBinaryTree(Node* root) {
    int res = INT_MIN;
    findDiameter(root, res);
    return res;
}


int main(){
	Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);		
	root->right->left=new Node(40);
	root->right->left->left=new Node(60);
	root->right->right=new Node(50);
	
    cout << "Given Tree : ";
    levelOrderTraversal(root);
    cout << "\nDiameter : ";
    cout << diameterOfBinaryTree(root);
}

// Time Complexity = O(N)
// Space Complexity = O(H), where H is the height of the binary tree
