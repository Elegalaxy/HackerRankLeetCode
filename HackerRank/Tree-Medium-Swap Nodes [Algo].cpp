//Tree-Medium-Swap Nodes [Algo]
//https://www.hackerrank.com/challenges/swap-nodes-algo/problem

#include <iostream>
#include <queue>
using namespace std;

struct Node{
    int data, level; //Data and level of node
    Node *left, *right;
    Node(int d, int l): data{d}, level{l}, left{nullptr}, right{nullptr} {} //Initialize
};

void swapNodes(Node *root, int level){
    if(root == nullptr) return; //Return when current node is null
    if(root->level == level){ //When reach require level of node
        Node *temp = root->left; //Change nodes
        root->left = root->right;
        root->right = temp;
        return;
    }
    swapNodes(root->left, level); //Recurse to left and right
    swapNodes(root->right, level);
}

void printInOrder(Node *root){ //Print node in order
    if(root == nullptr) return; //Return if null
    printInOrder(root->left); //Recurse to left
    cout << root->data << " "; //Cout data
    printInOrder(root->right); //Recurse to right
}

int main(){
    int nodesNum, t, level;
    queue<Node*> nodes;

    Node *root = new Node(1, 1); //Root node
    nodes.push(root);
    Node *head;

    cin >> nodesNum; //Total number of nodes
    for(int i = 0; i < nodesNum; i++){
        head = nodes.front(); //Get front node
        nodes.pop();
        if(head != nullptr){ //When it is not null
            int L, R; //Left right node
            cin >> L >> R;
            level = head->level +1; //New level
            if(L != -1) head->left = new Node(L, level); //When this node is not null, set left to new node
            else head->left = nullptr;

            if(R != -1) head->right = new Node(R, level);
            else head->right = nullptr;

            nodes.push(head->left); //Push left and right nodes, just like BFS
            nodes.push(head->right);
        }else{ //When it is null node, we dont use it so i--
            i--;
        }
    }

    cin >> t; //Swap how many times

    for(int i = 0; i < t; i++){
        int k; //Level for swap
        cin >> k;
        for(int j = 1; j*k < level; j++){ //j*k so all the children can be swap when the parent swap
            swapNodes(root, j*k); //Swap node with level
        }
        printInOrder(root); //Print node
        cout << endl;
    }
}