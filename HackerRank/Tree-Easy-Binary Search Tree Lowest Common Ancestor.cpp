//Tree-Easy-Binary Search Tree Lowest Common Ancestor
//https://www.hackerrank.com/challenges/binary-search-tree-lowest-common-ancestor/problem

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
  
    Node *lca(Node *root, int v1,int v2) {
        if(v1 > v2){ //Make sure v1 is smaller
            int temp = v2;
            v2 = v1;
            v1 = temp;
        }
        
        if(v2 < root->data) return lca(root->left, v1, v2);
        else if(v1 > root->data) return lca(root->right, v1, v2);
        else return root;
    }

}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data); //Building tree
    }
  	
  	int v1, v2; //2 values
  	std::cin >> v1 >> v2;
  
    Node *ans = myTree.lca(root, v1, v2); //LCA function
    
  	std::cout << ans->data;

    return 0;
}