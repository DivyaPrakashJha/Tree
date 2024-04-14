// Inorder Traversal

// Order of Traversal -> Left Node Right

#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;

    Node(int data){
        val = data;
        left = nullptr;
        right = nullptr;
    }
};

// Recursive Inorder Traversal
void inOrderR(Node* node){
    if (node == nullptr) return;

    inOrderR(node->left);
    cout<<node->val<<" ";
    inOrderR(node->right);
}

// Iterative Inorder Traversal
void inOrder(Node* node){
    if (node == nullptr) return;

    stack<Node*>st;
    st.push(node);

    while(!st.empty()){
        
    }
}

int main(){
    // Dummy Tree
    Node* root = new Node(5);
    root->left = new Node(6);
    root->right = new Node(7);
    root->left->left = new Node(8);
    root->left->right = new Node(9);
    root->right->left = new Node(10);
    root->right->right = new Node(11);
    root->right->left->right = new Node(12);

    inOrderR(root);
}