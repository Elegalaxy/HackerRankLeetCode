//LinkedLists-Easy-Compare two linked lists
//https://www.hackerrank.com/challenges/compare-two-linked-lists/problem

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

bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    if(head1 == NULL && head2 != NULL) return 0; //If either one is null, return false
    if(head2 == NULL && head1 != NULL) return 0;
    
    while(head1 != NULL && head2 != NULL){
        if(head1->data != head2->data) return 0; //If data not the same return false
        head1 = head1->next; //Traverse
        head2 = head2->next;
        if(head1 == NULL && head2 != NULL) return 0; //When one of the list comes to end, return false
        if(head2 == NULL && head1 != NULL) return 0;
    }
    
    return 1; //If all false statement is not true, return true
}

/*
Sample case:
2 //Case
2 //First list
1
2
1 //Second list
1
2 //First list
1
2
2 //Second list
1
2
*/

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

        cin >> count;
        cin >> num;
        SinglyLinkedListNode *head2 = new SinglyLinkedListNode(num); //Create a head node, must initialize with data

        for(int i = 1; i < count; i++){
            cin >> num;
            head = insertNodeAtTail(head2, num); //Insert node
        }

        cout << compare_lists(head, head2) << endl; //Compare and print

    }
    return 0;
}