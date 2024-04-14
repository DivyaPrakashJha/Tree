// Balanced Binary Tree

// A tree is said to be a balanced binary tree if the height difference of its left and right subtrees is less than or equal to 1

#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};

int findHeight(Node* node){
    if (node == nullptr) return 0;

    int lh = findHeight(node->left);
    int rh = findHeight(node->right);

    if (abs(lh - rh) > 1) return -1;
    if (lh == -1 or rh == -1) return -1;

    return 1 + max(lh, rh);
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

    if (findHeight(root) == -1) cout<<"Not balanced\n";
    else cout<<"Balanced\n";
}