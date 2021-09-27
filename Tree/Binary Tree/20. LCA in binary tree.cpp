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


// 1st Approach Using path
// Time Complexity = O(N), Space Complexity = O(H) where H is the height of the Binary Tree
// In this solution we require three traversal of binary tree (0(N)+0(N)+0(N)) => 3(0(N)) => 0(N).

bool findPath(Node* root, vector<Node*> &path, int node){
    if(root == NULL) return false;
    path.push_back(root);
    if(root->key == node) return true;
    if(findPath(root->left, path, node) || findPath(root->right, path, node)) return true;
    path.pop_back();
    return false;
}

Node* lowestCommonAncestor(Node* root, int p, int q) {
    vector<Node*> path1, path2;
    if(findPath(root, path1, p) == false || findPath(root, path2, q) == false) return NULL;
    int itr = 0;
    for(itr; itr < min(path1.size(), path2.size()); itr++){
        if(path1[itr] != path2[itr]) break;
    }
    return path1[itr-1];
}


int main(){
	Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);		
	root->right->left=new Node(40);
	root->right->left->left=new Node(60);
	root->right->right=new Node(50);
	root->right->right->left=new Node(70);
	root->right->right->right=new Node(80);
	
    cout << "Given Tree : ";
    levelOrderTraversal(root);
    
    cout << "LCA : " << lowestCommonAncestor(root, 60, 70)->key;
}
