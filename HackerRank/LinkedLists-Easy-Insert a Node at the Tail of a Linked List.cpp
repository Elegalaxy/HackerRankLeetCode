//LinkedLists-Easy-Insert a Node at the Tail of a Linked List
//https://www.hackerrank.com/challenges/insert-a-node-at-the-tail-of-a-linked-list/problem

#include <iostream>
using namespace std;

struct SinglyLinkedListNode { //Node struct
    int data; //Data of node
    SinglyLinkedListNode* next; //Pointer to next node
    SinglyLinkedListNode(int d): data{d} {} //Constructor, put d into data
};

SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    SinglyLinkedListNode* temp = new SinglyLinkedListNode(data); //Create a new node for insert
    SinglyLinkedListNode* tempHead = head; //Create a node for traversal

    if(tempHead == NULL) return temp; //If no head, return new node as head
    
    while(tempHead->next != NULL) tempHead = tempHead->next; //While it is not the last, traverse
    tempHead->next = temp; //Set the next of last node to temp
    return head; //Return head node
}

void printList(SinglyLinkedListNode *head){
    while(head != NULL){ //While node is not null
        cout << head->data << " "; //Print current node data
        head = head->next; //Go to next node
    }
    cout << endl;
}

int main(){
    SinglyLinkedListNode *head = new SinglyLinkedListNode(1); //Create a head node
    SinglyLinkedListNode *temp = head; //Temp node for traverse

    for(int i = 0; i < 3; i++){
        insertNodeAtTail(temp, i); //Insert node
        temp = temp->next; //Go to next node
    }

    printList(head); //Print data
    return 0;
}