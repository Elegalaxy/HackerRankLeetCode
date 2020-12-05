//LinkedLists-Easy-Find Merge Point of Two Lists
//https://www.hackerrank.com/challenges/find-the-merge-point-of-two-joined-linked-lists/problem

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

int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    while(head1 != NULL){
        SinglyLinkedListNode* temp = head2; //Reset second head every loop
        while(temp != NULL){ //Traverse through whole second list to check the merge point with first list
            if(head1 == temp) return head1->data;
            temp = temp->next;
        }
        head1 = head1->next; //Move first head to next
    }
    return NULL;
}

int main(){
    int count, num, merge, test;
    cin >> test;

    for(int j = 0; j < test; j++){
        cin >> merge; //Merge point
        cin >> count;
        cin >> num;

        //First list
        SinglyLinkedListNode *head = new SinglyLinkedListNode(num); //Create a head node, must initialize with data

        for(int i = 1; i < count; i++){
            cin >> num;
            head = insertNodeAtTail(head, num); //Insert node
        }

        cin >> count;
        cin >> num;

        //Second list
        SinglyLinkedListNode *head2 = new SinglyLinkedListNode(num); //Create second head node, must initialize with data

        for(int i = 1; i < count; i++){
            cin >> num;
            head = insertNodeAtTail(head2, num); //Insert node
        }

        //Merge point
        SinglyLinkedListNode *temp = head;
        for(int i = 0; i < merge; i++){
            temp = temp->next; //Traverse to merge point in first list
        }

        SinglyLinkedListNode *temp2 = head2;
        while(temp2->next != NULL) temp2 = temp2->next; //Traverse to end node of second list
        temp2->next = temp; //Merge second list with first list

        cout << findMergeNode(head, head2) << endl; //Print the value of merge point
    }

    return 0;
}