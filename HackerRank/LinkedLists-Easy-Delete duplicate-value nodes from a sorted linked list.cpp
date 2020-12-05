//LinkedLists-Easy-Delete duplicate-value nodes from a sorted linked list
//https://www.hackerrank.com/challenges/delete-duplicate-value-nodes-from-a-sorted-linked-list/problem

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

SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* temp = head; //Node for traverse
    SinglyLinkedListNode* prev = temp; //Node before current node
    temp = temp->next;
    
    while(temp != NULL){ //When linked lists not finish
        while(temp != NULL && temp->data == prev->data){ //When current node is not null and current data is same as previous
            prev->next = temp->next; //Previous next point to next of current (delete current node)
            temp = temp->next; //Move cuurent to next node
        }
        if(temp == NULL) break; //When current linked lists is end break loop, because there is no temp->next
        temp = temp->next; //Go to next node
        prev = prev->next;
    }
    
    return head;
}

int main(){
    int count, num, test;
    cin >> test;

    for(int j = 0; j < test; j++){
        cin >> count;
        cin >> num;

        SinglyLinkedListNode *head = new SinglyLinkedListNode(num); //Create a head node, must initialize with data

        for(int i = 1; i < count; i++){
            cin >> num;
            head = insertNodeAtTail(head, num); //Insert node
        }

        head = removeDuplicates(head); //Delete duplicate nodes
        printList(head); //Print data
    }
    return 0;
}