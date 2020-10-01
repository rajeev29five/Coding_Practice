// C++ program to find n-th node of 
// Postorder Traversal of Binary Tree 
#include <bits/stdc++.h> 
using namespace std; 
  
// node of tree 
struct Node { 
    int data; 
    Node *left, *right; 
}; 
  
// function to create a new node 
struct Node* createNode(int item) 
{ 
    Node* temp = new Node; 
    temp->data = item; 
    temp->left = NULL; 
    temp->right = NULL; 
  
    return temp; 
} 
  
// function to find the N-th node in the postorder 
// traversal of a given binary tree 
void NthPostordernode(struct Node* root, int N) 
{ 
    static int flag = 0; 
  
    if (root == NULL) 
        return; 
  
    if (flag <= N) { 
  
        // left recursion 
        NthPostordernode(root->left, N); 
  
        // right recursion 
        NthPostordernode(root->right, N); 
  
        flag++; 
  
        // prints the n-th node of preorder traversal 
        if (flag == N) 
            cout << root->data; 
    } 
} 
  
// driver code 
int main() 
{ 
    struct Node* root = createNode(25); 
    root->left = createNode(20); 
    root->right = createNode(30); 
    root->left->left = createNode(18); 
    root->left->right = createNode(22); 
    root->right->left = createNode(24); 
    root->right->right = createNode(32); 
  
    int N = 6; 
  
    // prints n-th node found 
    NthPostordernode(root, N); 
  
    return 0; 
} 
