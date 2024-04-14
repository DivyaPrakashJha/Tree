// ZigZag Level Order Traversal

#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val = val;
        left = right = nullptr;
    }
};

void zigzagLevelOrder(Node* root) {
        vector<vector<int>>zzTrav;

        if (root == nullptr) return;

        bool right = 0;

        queue<Node*>q;
        q.push(root);

        while(!q.empty()){
            int sz = q.size();
            vector<int>v(sz);

            for(int i = 0; i < sz; i++){
                Node* x = q.front();
                q.pop();

                if (right) v[sz-1-i] = x->val;
                else v[i] = x->val;

                if (x->left != nullptr) q.push(x->left);
                if (x->right != nullptr) q.push(x->right);
            }

            right = 1 - right;
            zzTrav.push_back(v);
        } 
        
        for(auto vec : zzTrav){
            for(auto it: vec){
                cout<<it<<" ";
            }
            cout<<endl;
        }
    }

int main(){
    // Taking array input and converting it to a binary tree

    int n;
    cin>>n;
    vector<string>v(n);
    for(auto &x : v) cin>>x;

    Node* root;

    queue<pair<Node*, int>>q;
    if (v[0] != "null"){
        root->val = stoi(v[0]);
        q.push({root, 0});
    }
    
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

    zigzagLevelOrder(root);

}