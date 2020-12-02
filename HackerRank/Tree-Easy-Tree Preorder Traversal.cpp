//Tree-Easy-Tree: Preorder Traversal
//https://www.hackerrank.com/challenges/tree-preorder-traversal/problem

#include <iostream>
using namespace std;

class Node {
    public:
        int data; //Node data
        Node *left; //Left pointer
        Node *right; //Right pointer
        Node(int d) { //Constructor
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) { //Insert nodes
            if(root == NULL) { //If no root
                return new Node(data); //Return node as root
            } else {
                Node* cur;
                if(data <= root->data) { //If current node data is smaller than root
                    cur = insert(root->left, data); //Assign node to left
                    root->left = cur; //Set left pointer to new node
                } else {
                    cur = insert(root->right, data); //Assign node to right
                    root->right = cur; //Set right pointer to new node
               }

               return root; //Return root
           }
        }

void preOrder(Node *root) {
    if(root == NULL) return; //Return if this is null
    cout << root->data << " "; //Print data first before recurse;
    preOrder(root->left); //Recurse to left
    preOrder(root->right); //Recurse to right
}

}; //End of Solution

/*
Sample input:
6
1 2 5 3 6 4
*/

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t; //Number of nodes

    while(t-- > 0) {
        std::cin >> data; //Input data
        root = myTree.insert(root, data); //Insert new node into tree
    }
  
	myTree.preOrder(root); //Print in preOrder
    return 0;
}
