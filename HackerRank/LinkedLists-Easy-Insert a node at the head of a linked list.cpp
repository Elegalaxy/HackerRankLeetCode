//LinkedLists-Easy-Insert a node at the head of a linked list
//https://www.hackerrank.com/challenges/insert-a-node-at-the-head-of-a-linked-list/problem

#include <iostream>
using namespace std;

struct SinglyLinkedListNode { //Node struct
    int data; //Data of node
    SinglyLinkedListNode* next; //Pointer to next node
    SinglyLinkedListNode(int d): data{d} {} //Constructor, put d into data
};

void printList(SinglyLinkedListNode *head){
    while(head != NULL){ //While node is not null
        cout << head->data << " "; //Print current node data
        head = head->next; //Go to next node
    }
    cout << endl;
}

SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* head, int data) {
    SinglyLinkedListNode *temp = new SinglyLinkedListNode(data); //Create new node
    temp->next = head; //Set the next pointer to current node
    return temp; //Return new node as head node
}

int main(){
    SinglyLinkedListNode *head = new SinglyLinkedListNode(1); //Create a head node
    SinglyLinkedListNode *temp = head; //Temp node for traverse

    for(int i = 0; i < 3; i++){ //Keep insert infront of head node
        head = insertNodeAtHead(head, i); //Insert node and set new head node
    }

    printList(head); //Print data
    return 0;
}