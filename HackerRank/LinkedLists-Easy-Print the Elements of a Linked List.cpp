//Easy-LinkedLists-Print the Elements of a Linked List
//https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list/problem
 
#include <iostream>
using namespace std;
 
struct SinglyLinkedListNode {
	int data; //Store data
	SinglyLinkedListNode* next; //Next pointer
	
	SinglyLinkedListNode(int d){ //Constructor for data
		data = d;
	}
};
 
void printLinkedList(SinglyLinkedListNode* head) {
    while(head != NULL){ //When this node is not null
        cout << head->data << endl; //Print data
        head = head->next; //Go to next node
    }
}

int main(){
	int count,data;
	SinglyLinkedListNode *head, *current;
	cin >> count;
	
	cin >> data;
	head = new SinglyLinkedListNode(data); //Head node
	current = head; //Use current node to connect to next node
	for(int i = 1; i < count; i++){
		cin >> data;
		SinglyLinkedListNode *temp = new SinglyLinkedListNode(data); //Create new node
		current->next = temp; //Set next pointer
		current = current->next; //Set current to next node
	}
	
	printLinkedList(head);
	return 0;
}