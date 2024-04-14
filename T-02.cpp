// Representation

#include<bits/stdc++.h>

using namespace std;

class Node{
    public:    
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

// OR 

struct Node1{
    int data;
    struct Node1* left;
    struct Node1* right;

    Node1(int data){
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

int main(){

    // Using class representation
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(4);
    root->right->left = new Node(6);

    cout<<root->data<<"\n"<<root->left->data<<" "<<root->right->data<<"\n"<<root->right->left->data<<"\n";

    // Using struct representation
    struct Node1* root1 = new Node1(5);
    root1->left = new Node1(3);
    root1->right = new Node1(4);
    root1->right->left = new Node1(6); 

    cout<<root1->data<<"\n"<<root1->left->data<<" "<<root1->right->data<<"\n"<<root1->right->left->data<<"\n";
}