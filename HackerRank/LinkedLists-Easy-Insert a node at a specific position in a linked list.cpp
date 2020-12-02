//LinkedLists-Easy-Insert a node at a specific position in a linked list
//https://www.hackerrank.com/challenges/insert-a-node-at-a-specific-position-in-a-linked-list/problem

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

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
    SinglyLinkedListNode *temp = new SinglyLinkedListNode(data); //Create new node
    SinglyLinkedListNode *tempHead = head; //Set temp for traversal
    for(int i = 0; i < position-1; i++){ //When this node is not the previous node of desire position
        tempHead = tempHead->next; //Traverse
    }
    temp->next = tempHead->next; //Next of new node point to next of current node
    tempHead->next = temp; //Next of current node is new node
    return head; //Return head node
}

int main(){
    SinglyLinkedListNode *head = new SinglyLinkedListNode(1); //Create a head node
    SinglyLinkedListNode *temp = head; //Temp node for traverse

    head = insertNodeAtPosition(head, 2, 1); //Insert node after head
    head = insertNodeAtPosition(head, 3, 1); //Insert node in between current nodes
    head = insertNodeAtPosition(head, 4, 2); //Insert node at index 2

    printList(head); //Print data
    return 0;
}