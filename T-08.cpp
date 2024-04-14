// Depth and Height of a Tree

// The depth of a node is the number of edges present in path from the root node of a tree to that node.
// The height of a node is the number of edges present in the longest path connecting that node to a leaf node.

// Here, maximum depth of a tree is defined as the number of nodes along the longest path from the root node down to the farthest leaf node.

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

// Using recursion
int maxDepthR(Node* root){
    if (root == nullptr) return 0;

    return 1 + max(maxDepthR(root->left), maxDepthR(root->right));
}

// Using levelOrder traversal
int maxDepth(Node* root){
    if (root == nullptr) return 0;

    int depth = 1;
    queue<Node*>q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty()){
        Node* x = q.front();
        q.pop();

        if (x == nullptr){
            if (!q.empty()){
                depth++;
                q.push(nullptr);
            }
        }
        else{
            if (x->left != nullptr) q.push(x->left);
            if (x->right != nullptr) q.push(x->right);
            
        }
    }

    return depth;
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

    cout<<maxDepthR(root)<<endl;
    cout<<maxDepth(root)<<endl;

}