//LinkedLists-Easy-Get Node Value
//https://www.hackerrank.com/challenges/get-the-value-of-the-node-at-a-specific-position-from-the-tail/problem

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

/*
Sample case:
2
1
1
0
3
3
2
1
2
*/

int getNode(SinglyLinkedListNode* head, int positionFromTail) {
    int length = 0;
    SinglyLinkedListNode* tempHead = head;
    while(tempHead != NULL){ //Count the length of this list
        length++;
        tempHead = tempHead->next;
    }
    
    for(int i = 0; i < length-positionFromTail-1; i++){ //Traverse to the node
        head = head->next;
    }
    return head->data; //Return the value
}

int main(){
    int test,count, num,pos;
    cin >> test;

    for(int j = 0; j < test; j++){
        cin >> count;
        cin >> num;
        SinglyLinkedListNode *head = new SinglyLinkedListNode(num); //Create a head node, must initialize with data

        for(int i = 1; i < count; i++){
            cin >> num;
            head = insertNodeAtTail(head, num); //Insert node
        }

        cin >> pos;
        cout << getNode(head, pos) << endl; //Get value
    }
    return 0;
}