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

// 1st Approach
//Naive Approach
//Time Complexity = O(N^2), Space Complexity = O(H) where H is the height of the Binary Tree
//Node* buildBinaryTree(vector<int>& preorder, vector<int>& inorder, int is, int ie, int& preIndex) {
//    if(is > ie) return NULL;
//    Node *root = new Node(preorder[preIndex++]);
//    
//    int inIndex;
//    for(int itr = is; itr <= ie; itr++){
//        if(inorder[itr] == root->key){
//            inIndex = itr;
//            break;
//        }
//    }
//    root->left = buildBinaryTree(preorder, inorder, is, inIndex-1, preIndex);
//    root->right = buildBinaryTree(preorder, inorder, inIndex+1, ie, preIndex);
//    return root;
//}
//
//Node* buildTree(vector<int>& preorder, vector<int>& inorder) {
//    int preIndex = 0;
//    return buildBinaryTree(preorder, inorder, 0, inorder.size()-1, preIndex);
//}


// 2nd Approach
//Using Unordered Map Approach
//Time Complexity = O(N), Space Complexity = O(N) where N is the size of the inorder vector
//Node* buildBinaryTree(vector<int>& preorder, vector<int>& inorder, int is, int ie, unordered_map<int, int> ump, int& preIndex) {
//    if(is > ie) return NULL;
//    Node *root = new Node(preorder[preIndex++]);
//    
//    // get the index of the val;
//    int inIndex = ump[root->key];
//    
//    root->left = buildBinaryTree(preorder, inorder, is, inIndex-1, ump, preIndex);
//    root->right = buildBinaryTree(preorder, inorder, inIndex+1, ie, ump, preIndex);
//    return root;
//}
//
//Node* buildTree(vector<int>& preorder, vector<int>& inorder) {
//    int preIndex = 0;
//	unordered_map<int, int> ump;    
//    for(int itr = 0; itr < inorder.size(); itr++){
//        ump[inorder[itr]] = itr;
//    }
//    return buildBinaryTree(preorder, inorder, 0, inorder.size()-1, ump, preIndex);
//}


// 3rd Approach
//Without Map Approach
//Time Complexity = O(N), Space Complexity = O(H) where H is the height of the Binary Tree
Node* buildBinaryTree(vector<int>& preorder, vector<int>& inorder, int& inorderPosition, int& preorderPosition, int stop){
    if(preorderPosition >= preorder.size()) return NULL;
    if(inorder[inorderPosition] == stop){
        inorderPosition++;
        return NULL;
    }
        
    Node *root = new Node(preorder[preorderPosition++]);
    
    root->left = buildBinaryTree(preorder, inorder, inorderPosition, preorderPosition, root->key);
    root->right = buildBinaryTree(preorder, inorder, inorderPosition, preorderPosition, stop);
    return root;
}

Node* buildTree(vector<int>& preorder, vector<int>& inorder) {        
    int inorderPosition = 0;
    int preorderPosition = 0;
    return buildBinaryTree(preorder, inorder, inorderPosition, preorderPosition, INT_MIN);
}


int main(){
	vector<int> inorder = {40, 20, 50, 10, 30, 80, 70, 90};
	vector<int> preorder = {10, 20, 40, 50, 30, 70, 80, 90};
	Node *root = buildTree(preorder, inorder);
		
    cout << "Final Tree : \n";
    levelOrderTraversal(root);    
}

// Time Complexity = O(N)
// Space Complexity = O(W), where W is the width of the binary tree
