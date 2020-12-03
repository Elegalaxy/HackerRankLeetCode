//LinkedList-Easy-Print in Reverse
//https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list-in-reverse/problem

#include <iostream>
#include <vector>
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


void reversePrint(SinglyLinkedListNode* head) { //Using recursion (better way)
    if(head == NULL) return;
    reversePrint(head->next);
    cout << head->data << endl;
}


/*
void reversePrint(SinglyLinkedListNode* head) { //Using vector
    if(head == NULL) return;
    SinglyLinkedListNode *tempHead = head;
    vector<int> v;
    while(tempHead != NULL){
        v.push_back(tempHead->data);
        tempHead = tempHead->next;   
    }
    
    for(auto &i:v){
        cout << v.back() << endl;
        v.pop_back();
    }
}
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

        reversePrint(head); //Print reversely

    }
    return 0;
}