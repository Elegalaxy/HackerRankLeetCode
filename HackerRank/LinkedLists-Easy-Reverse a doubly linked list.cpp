//LinkedLists-Easy-Reverse a doubly linked list
//https://www.hackerrank.com/challenges/reverse-a-doubly-linked-list/problem

#include <iostream>
using namespace std;

struct DoublyLinkedListNode { //Node struct
    int data; //Data of node
    DoublyLinkedListNode* next; //Pointer to next node
    DoublyLinkedListNode* prev; //Pointer to previous node
    DoublyLinkedListNode(int d): data{d} {} //Constructor, put d into data
};

void printList(DoublyLinkedListNode *head){
    while(head != NULL){ //While node is not null
        cout << head->data << " "; //Print current node data
        head = head->next; //Go to next node
    }
    cout << endl;
}

DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {
    DoublyLinkedListNode* temp = head; //Create temp for traversal
    DoublyLinkedListNode* newNode = new DoublyLinkedListNode(data); //Create new node

    while(temp != NULL){
        if(data <= temp->data && temp->prev == NULL){ //When new node is smaller or equal than current node and it is first node
            newNode->next = temp; //Next of new node equal current node (head node)
            newNode->prev = NULL; //Previous pointer is null
            temp->prev = newNode; //Previous of current node is new node
            return newNode; //Return new node as head node
        }else if(temp->next == NULL && data >= temp->data){ //When new node has biggest data
            temp->next = newNode; //Next of last node equal to new node
            newNode->next = NULL; //Next of new node equal to null
            newNode->prev = temp; //Previous of new node equal to current node
            return head;
        }
        else if(data <= temp->next->data){ //When new node's data is smaller or equal to current data
            DoublyLinkedListNode* nxt = temp->next; //Set a new pointer point to next of current node
            temp->next = newNode; //Next of current point reset to new node
            newNode->next = nxt; //next of new node is the new pointer we set at first line
            newNode->prev = temp; //Previous of new node is current node
            newNode->next->prev = newNode; //Previous of the "First line node" equal to new node
            return head;
        }
        temp = temp->next; //Traverse until find where current node is smaller or equal than the next of current
    }
    return head;
}

/*
1 <-> 2 <-> 4 <-> 5 <-> NULL
1 <-> 2     4 <-> 5 <-> NULL
      ^     ^
      |     |
      L> 3 <⅃      

*/

DoublyLinkedListNode* reverse(DoublyLinkedListNode* head) {
    DoublyLinkedListNode* temp = head->next; //Start from second node
    
    bool isFirst = true; //Checker
    
    while(temp != NULL){
        
        if(isFirst){ //When it is first node
            head->next = NULL; //Set the next to null (last node)
            isFirst = false;
        }
        
        head->prev = temp; //Previous of head equal to temp (second last node)
        temp = temp->next; //Move to next one in ascending order
        head->prev->next = head; //Set the next of previous to THIS node
        head = head->prev; //Move to previous node (decending order)
    }
    
    /*
    NULL(<- Move to here) <-> 2 <-> 1 <-> NULL    NULL(From here ->) <-> 3 <-> 4 <-> NULL
    */

    return head;
}

int main(){
    int count, num, test;
    cin >> test;

    for(int j = 0; j < test; j++){
        cin >> count;
        cin >> num;

        //First list
        DoublyLinkedListNode *head = new DoublyLinkedListNode(num); //Create a head node, must initialize with data

        for(int i = 1; i < count; i++){
            cin >> num;
            head = sortedInsert(head, num); //Insert node
        }

        head = reverse(head); //Insert node
        printList(head);
    }
    return 0;
}