//LinkedLists-Easy-Reverse a linked list
//https://www.hackerrank.com/challenges/reverse-a-linked-list/problem

#include <iostream>
using namespace std;

struct SinglyLinkedListNode { //Node struct
    int data; //Data of node
    SinglyLinkedListNode* next; //Pointer to next node
    SinglyLinkedListNode(int d): data{d} {} //Constructor, put d into data
};

SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) { //Function from previous
    SinglyLinkedListNode* temp = new SinglyLinkedListNode(data); //Create a new node for insert
    if(head == NULL) return temp; //If no head, return new node as head
    SinglyLinkedListNode* tempHead = head; //Create a node for traversal
    
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

SinglyLinkedListNode* reverse(SinglyLinkedListNode* head) {
    if(head == NULL || head->next == NULL) return head;
    SinglyLinkedListNode *temp = reverse(head->next); //Recurse and return new head
    head->next->next = head; //Set the next of new head to current head
    head->next = NULL; //Set the next of last node to null
    return temp;
}

int main(){
    int test,count, num;
    cin >> test;

    for(int j = 0; j < test; j++){
        cin >> count;
        cin >> num;
        SinglyLinkedListNode *head = new SinglyLinkedListNode(num); //Create a head node, must initialize with data

        for(int i = 1; i < count; i++){
            cin >> num;
            head = insertNodeAtTail(head, num); //Insert node
        }

        head = reverse(head); //Reverse
        printList(head); //Print

    }
    return 0;
}