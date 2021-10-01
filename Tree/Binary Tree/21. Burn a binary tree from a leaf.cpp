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

// Line by line
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

// Find time to burn a binary tree
int findTimeToBurnTree(Node *root, int leafNode, int &dist, int &res){
	if(root == NULL) return 0;
	if(root->key == leafNode) {
		dist = 0;
		return 1;
	}
	int leftDist = -1, rightDist = -1;
	int lh = findTimeToBurnTree(root->left, leafNode, leftDist, res);
	int rh = findTimeToBurnTree(root->right, leafNode, rightDist, res);
	if(leftDist != -1){
		dist = leftDist+1;
		res = max(res, dist+rh+1);
	}
	if(rightDist != -1){
		dist = rightDist+1;
		res = max(res, dist+lh);
	}
	return (max(lh, rh)+1);
}

// Driver Code
int main(){
	Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);		
	root->left->left=new Node(40);
	root->left->right=new Node(50);
	root->left->left->left=new Node(60);
	root->left->left->left->left=new Node(70);
	
    cout << "Given Tree : ";
    levelOrderTraversal(root);
    int leafNode = 50, dist = -1, res = 0;
    cout << "\nTime : ";
    findTimeToBurnTree(root, leafNode, dist, res);
    cout << res;
}

// Time Complexity = O(N), Space Complexity = O(H) where H is the height of the Binary Tree
