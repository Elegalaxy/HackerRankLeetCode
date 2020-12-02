//LinkedLists-Easy-Tree: Height of a Binary Tree
//https://www.hackerrank.com/challenges/tree-height-of-a-binary-tree/problem

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

    int height(Node* root) {
        if(root == NULL) return -1; //Return if the root is null
        
        int current = 0; //Record depth of this node
        if(root->left != NULL) current = height(root->left)+1; //When the left of this node is not null current +1 +the height of child node
        
        if(root->right != NULL) current = height(root->right)+1; //When the right of this node is not null current +1 +the height of child node
                
        return current;
    }

}; //End of Solution

/*
Sample Input:
7
3 5 2 1 4 6 7
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
  
	cout << myTree.height(root) << endl;
    return 0;
}