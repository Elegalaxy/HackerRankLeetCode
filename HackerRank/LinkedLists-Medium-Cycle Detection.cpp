//LinkedLists-Medium-Cycle Detection
//https://www.hackerrank.com/challenges/detect-whether-a-linked-list-contains-a-cycle/problem

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

bool has_cycle(SinglyLinkedListNode* head) { //Cycle function
    if(head == NULL) return 0;
        
    SinglyLinkedListNode* slow = head; //Use Tortoise and Hare algorithm (fast and slow iteration)
    SinglyLinkedListNode* fast = head;
    
    while(fast != NULL && fast->next != NULL){ //When fast and his next node is not null
        slow = slow->next; //Slow become next
        fast = fast->next->next; //Fast become next next (faster next)
        if(slow == fast) return 1; //If they met, return 1 (is a cycle)
    }
    
    //This function is better to draw the algorithm process out, you will find the fast went throught the whole list for few time
    //But the fast iteration will meet the slow one eventually if there is a cycle
    //If there is no cycle the fast iteration will break and return 0

    return 0;
}

int main(){
    //No main function for this question, input from the question is complicate
    return 0;
}