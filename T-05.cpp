// Postorder Traversal

// Order of Traversal -> Left Right Node

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

// Recursive Postorder Traversal
void postorderR(Node* node){
    if (node == nullptr) return;

    postorderR(node->left);
    postorderR(node->right);
    cout<<node->val<<" ";
}

// Iterative Postorder Traversal


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

    postorderR(root);
}