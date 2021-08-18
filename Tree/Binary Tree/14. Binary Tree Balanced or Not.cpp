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

// 2nd Approach
int checkBalancedBinaryTree(Node* root){
    if(root == NULL) return 0;
    int left = checkBalancedBinaryTree(root->left);
    if(left == -1) return -1;
    int right = checkBalancedBinaryTree(root->right);
    if(right == -1) return -1;
    if(abs(left-right) > 1) return -1;
	else return max(left, right)+1;    
}

// 1st Approach
//int checkBalancedBinaryTree(Node* root){
//    if(root == NULL) return 0;
//    int left = checkBalancedBinaryTree(root->left);
//    int right = checkBalancedBinaryTree(root->right);
//    if(left != -1 && right != -1){
//        if(abs(left-right) > 1) return -1;
//        else{
//            return max(left, right) + 1;
//        }
//    }
//    return -1;
//}

bool isBalanced(Node* root) {
    if(checkBalancedBinaryTree(root) == -1) return false;
    else return true;
}

int main(){
	Node *root = new Node(18);
	root->left = new Node(4);		
	root->right = new Node(20);
	root->right->left = new Node(13);
	root->right->right = new Node(70);
//	root->right->right->left = new Node(80);
	
    cout << "Given Tree : ";
    levelOrderTraversal(root);
    cout << "\n" << isBalanced(root);
}

// Time Complexity = O(N)
// Space Complexity = O(H), where H is the height of the binary tree
