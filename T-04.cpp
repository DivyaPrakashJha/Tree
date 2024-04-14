// Preorder Traversal

// Order of Traversal -> Node Left Right

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

// Recursive Preorder Traversal
void preOrderR(Node* node){
    if (node == nullptr) return;

    cout<<node->val<<" ";
    preOrderR(node->left);
    preOrderR(node->right);
}

// Iterative Preoder Traversal
void preOrder(Node* node){
    if (node == nullptr) return;

    stack<Node*>st;
    st.push(node);

    while(!st.empty()){
        Node* x = st.top();
        st.pop();

        cout<<x->val<<' ';
        if (x->right != nullptr) st.push(x->right);
        if (x->left != nullptr) st.push(x->left);
        // We have inserted x->left after x->right as stack is a LIFO DS and we want to firstly explore the left part
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

    preOrderR(root);
    cout<<"\n";
    preOrder(root);
}