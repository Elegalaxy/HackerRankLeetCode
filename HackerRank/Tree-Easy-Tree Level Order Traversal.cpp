//Tree-Easy-Tree Level Order Traversal
//https://www.hackerrank.com/challenges/tree-level-order-traversal/problem

#include <iostream>
#include <queue>
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

    void levelOrder(Node * root) {
        cout << root->data << " "; //Print root data
        queue<Node*> record; //Queue help us record nodes in ascending order
        
        if(root->left != NULL) record.push(root->left); //Push left node if available
        if(root->right != NULL) record.push(root->right); //Push left node if available
        
        while(!record.empty()){ //When still have nodes
            Node *temp = record.front(); //Get front node
            if(temp->left != NULL) record.push(temp->left); //Push the left and right of current node into queue
            if(temp->right != NULL) record.push(temp->right);
            cout << temp->data << " "; //Print current node data
            record.pop(); //Delete the node we used
        }
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
  
	myTree.levelOrder(root); //Print in preOrder
    return 0;
}