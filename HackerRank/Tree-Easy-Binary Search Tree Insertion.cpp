//Tree-Easy-Binary Search Tree Insertion
//https://www.hackerrank.com/challenges/binary-search-tree-insertion/problem

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
        void preOrder(Node *root) {
            if(root == NULL) return; //Return if this is null
            cout << root->data << " "; //Print data first before recurse;
            preOrder(root->left); //Recurse to left
            preOrder(root->right); //Recurse to right
        }


        Node * insert(Node * root, int data) {
            if(root == NULL){
                root = new Node(data);
                root->left = root->right = NULL;
            }else{
                if(data < root->data) root->left = insert(root->left, data);
                else root->right = insert(root->right, data);
            }
            return root;
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
        root = myTree.insert(root, data); //Print in preOrder
    }
  
	myTree.preOrder(root); //Print in preOrder
    return 0;
}