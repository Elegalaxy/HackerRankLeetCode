//LinkedLists-Easy-Merge two sorted linked lists
//https://www.hackerrank.com/challenges/merge-two-sorted-linked-lists/problem

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

/*
Sample case:
1
3
1
2
3
2
3
4
*/

SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    if(head1 == NULL && head2 == NULL) return NULL; //Return if both are null
    if(head1 == NULL) return head2; //Return head2 if head1 is null
    if(head2 == NULL) return head1; //Return head1 if head2 is null
    
    SinglyLinkedListNode *nxt;
    
    if(head1->data > head2->data){ //Let first data of head1 always be the smallest one
        SinglyLinkedListNode* tmp = head2; //Exchange if head1 is not smaller than head2
        head2 = head1;
        head1 = tmp;
    }
    
    SinglyLinkedListNode *head = head1; //The new list start from head1 because first data of head1 is smallest
    
    while(head2){ //While head2 is not null
        while(head1->next != NULL && head1->next->data < head2->data){ //While head1 is not the last node and the next node data is smaller than head2 data
            head1 = head1->next; // Traverse until data of next head1 is bigger or equal to head2
        }
        
        SinglyLinkedListNode* nxt = head2->next; //Insert node
        head2->next = head1->next;
        head1->next = head2;
        head2 = nxt; //Keep traverse on second list
    }
    
    return head;

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

        cin >> count;
        cin >> num;
        SinglyLinkedListNode *head2 = new SinglyLinkedListNode(num); //Create a head node, must initialize with data

        for(int i = 1; i < count; i++){
            cin >> num;
            head = insertNodeAtTail(head2, num); //Insert node
        }

        head = mergeLists(head, head2); //Merge
        printList(head); //Print

    }
    return 0;
}