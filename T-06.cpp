// Level order Traversal

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

void levelOrder(Node* node){
    if (node == nullptr) return;

    queue<Node*>q;
    q.push(node);
    q.push(nullptr);

    while(!q.empty()){
        Node* x = q.front();
        q.pop();

        if (x == nullptr){
            if (!q.empty()){
                q.push(nullptr);
                cout<<endl;
            }
        }
        else{
            cout<<x->val<<' ';
            if (x->left != nullptr) q.push(x->left);
            if (x->right != nullptr) q.push(x->right);
        }

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

    levelOrder(root);
}