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

void bToDLL(Node *root, Node **head) {
    if(root == NULL) return;
    static Node* prev = NULL;
    bToDLL(root->left, head);
    if(prev == NULL) *head = root;
    else{
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    bToDLL(root->right, head);    
}

void printList(Node *node){
    while (node!=NULL){
        cout << node->key << " ";
        node = node->right;
    }
}

int main(){
	Node *root = new Node(10);
	root->left = new Node(5);
	root->right = new Node(20);
	root->right->left = new Node(30);
	root->right->right = new Node(35);	
	
    cout << "Given Tree : ";
    levelOrderTraversal(root);
    
	Node *head = NULL;
	bToDLL(root, &head);
    cout << "After conversion : ";
    printList(head);
}

// Time Complexity = O(N)
// Space Complexity = O(H), where H is the height of the binary tree
