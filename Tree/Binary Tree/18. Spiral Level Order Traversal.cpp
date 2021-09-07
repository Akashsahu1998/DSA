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


// 1st Approach
// Naive Solution
// In this solution we are processing item 4 times, enqueue and deque in queue and push and pop in stack
//void findSpiral(Node *root){
//    if(root == NULL) return;
//    queue<Node*> q;
//    stack<int> s;
//    bool reverse = false;
//    q.push(root);
//    
//    while(!q.empty()){
//    	int count = q.size();
//    	
//    	for(int i = 0; i < count; i++){
//    		Node* cur = q.front();
//    		q.pop();
//    		
//    		if(reverse)
//    			s.push(cur->key);
//    		else
//    			cout << cur->key << " ";
//    			
//    		if(cur->right != NULL)
//    			q.push(cur->right);
//    		if(cur->left != NULL)
//    			q.push(cur->left);    			
//		}
//		
//		if(reverse){
//			while(!s.empty()){
//				cout << s.top() << " ";
//				s.pop();
//			}				
//		}
//		reverse = !reverse;
//		cout << "\n";
//	}
//}


// 2nd Approach
// Efficient Solution
// In this solution we are processing item 2 times, push and pop in stack
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
	Node *root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	root->right->left=new Node(6);
	root->right->right=new Node(7);
	
    cout << "Given Tree : ";
    levelOrderTraversal(root);
    cout << "\nSpriral Form : \n";
    findSpiral(root);
}

// Time Complexity = O(N)
// Space Complexity = O(W), where W is the width of the binary tree
