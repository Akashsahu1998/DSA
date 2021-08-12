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

//// 1st Approach
//bool isSumProperty(Node *root){
//    if(root == NULL) return true;
//    if(isSumProperty(root->left) && isSumProperty(root->right)){
//        int sum = 0;
//        if((root->left == NULL) && (root->right == NULL))
//            return true;
//        else{
//            if(root->left != NULL)
//                sum += root->left->key;
//            if(root->right != NULL)
//                sum += root->right->key;
//            if(sum == root->key)
//                return true;
//            else return false;
//        }
//    }
//}

// 2nd Approach
int isSumProperty(Node *root){
    if(root == NULL) return true;
    
    if((root->left == NULL) && (root->right == NULL))
            return true;
        
    int sum = 0;        
    if(root->left != NULL)
        sum += root->left->key;
    if(root->right != NULL)
        sum += root->right->key;
    
    return (sum == root->key && isSumProperty(root->left) && isSumProperty(root->right));
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
    cout << "\n" << isSumProperty(root);
}

// Time Complexity = O(N)
// Space Complexity = O(W), where W is the width of the binary tree
