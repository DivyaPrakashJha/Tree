// Diameter of a binary tree

// It is the length of the longest path between any two nodes in the tree
// It may or may not pass through the root of the tree

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

int diameter = 0;

int findHeight(Node* node){
    if (node == nullptr) return 0;

    int lh = findHeight(node->left);
    int rh = findHeight(node->right);

    // Trying to take the longest path considering the current node as the curve point(LCA)
    diameter = max(diameter, lh+rh); 

    return 1 + max(lh, rh);
}

int main(){

    // Taking array input and converting it to a binary tree

    int n;
    cin>>n;
    vector<string>v(n);
    for(auto &x : v) cin>>x;

    Node* root;
    queue<pair<Node*, int>>q;
    q.push({root, 0});

    while(!q.empty()){
        Node* nd = q.front().first;
        int x = q.front().second;
        q.pop();

        if (2*x + 1 < n){
            if (v[2*x + 1] == "null") nd->left = nullptr;
            else{
                Node* newNode = new Node(stoi(v[2*x+1]));
                nd->left = newNode;
                q.push({nd->left, 2*x+1});
            }
        }
        if (2*x + 2 < n){
            if (v[2*x + 2] == "null") nd->right = nullptr;
            else{
                Node* newNode = new Node(stoi(v[2*x+2]));
                nd->right = newNode;
                q.push({nd->right, 2*x+2});
            }
        }
    }

    findHeight(root);
    cout<<diameter;
}

/* Sample Test Case
14
5 6 7 8 9 10 11 null null null null null 12 null
*/

// Output
// 5