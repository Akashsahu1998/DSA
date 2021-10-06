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

// Naive Approach
// Time Complexity = O(N), Space Complexity = O(H) where H is the height of the Binary Tree
//int countNodes(Node* root) {
//    if(root == NULL) return 0;
//    else return 1 + countNodes(root->left) + countNodes(root->right);
//}


// Efficient Approach
// Time Complexity = O(Log(n)^2), Space Complexity = O(H) where H is the height of the Binary Tree
int countNodes(Node* root) {
    int leftHeight = 0, rightHeight = 0;
    Node *cur = root;
    while(cur != NULL){
        leftHeight++;
        cur = cur->left;
    }
    cur = root;
    while(cur != NULL){
        rightHeight++;
        cur = cur->right;
    }
    if(leftHeight == rightHeight) return pow(2, leftHeight) - 1;
    return 1 + countNodes(root->left) + countNodes(root->right);
}


// Driver Code
int main(){
	Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);		
	root->left->left=new Node(40);
	root->left->right=new Node(50);
	root->left->left->left=new Node(80);
	root->left->left->right=new Node(90);
	root->left->right->left=new Node(100);
	root->left->right->right=new Node(110);
	root->right->left = new Node(60);
	root->right->right = new Node(70);
	root->right->left->left = new Node(120);
	
    cout << "Given Tree : ";
    levelOrderTraversal(root);
    cout << "Ans :- " << countNodes(root);
}
