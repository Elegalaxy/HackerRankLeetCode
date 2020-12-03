//LinkedLists-Easy-Delete a Node
//https://www.hackerrank.com/challenges/delete-a-node-from-a-linked-list/problem

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

SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) { //Function from previous
    SinglyLinkedListNode* temp = new SinglyLinkedListNode(data); //Create a new node for insert
    if(head == NULL) return temp; //If no head, return new node as head
    SinglyLinkedListNode* tempHead = head; //Create a node for traversal
    
    while(tempHead->next != NULL) tempHead = tempHead->next; //While it is not the last, traverse
    tempHead->next = temp; //Set the next of last node to temp
    return head; //Return head node
}

SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position) {
    if(position == 0) return head->next; //If delete the first node, just return the next one as new head
    SinglyLinkedListNode *tempHead = head; //For traversal
    for(int i = 0; i < position-1; i++){
        tempHead = tempHead->next; //Go to the previous node of position node
    }
    
    tempHead->next = tempHead->next->next; //Set the next of ,previous of position node to the next of position node
    return head; //Return head
}

int main(){
    int count, num;
    cin >> count;
    cin >> num;

    SinglyLinkedListNode *head = new SinglyLinkedListNode(num); //Create a head node, must initialize with data

    for(int i = 1; i < count; i++){
        cin >> num;
        head = insertNodeAtTail(head, num); //Insert node
    }

    cin >> num;
    deleteNode(head, num); //Delete node
    printList(head); //Print data
    return 0;
}