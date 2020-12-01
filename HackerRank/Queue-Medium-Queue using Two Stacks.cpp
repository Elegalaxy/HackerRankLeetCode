//Queue-Medium-Queue using Two Stacks
//https://www.hackerrank.com/challenges/queue-using-two-stacks/problem

#include <iostream>
#include <stack>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int i,count,temp,choice;
    stack<int> q1,q2;    
    cin >> count;
    
    for(i = 0; i < count; i++){
        cin >> choice; //User choice
        if(choice == 1){ //Push into first stack
            cin >> temp;
            q1.push(temp);
        }
        else{ //When the queue require operation on front of queue
            if(q2.empty()){ //When q2 is empty
                while(!q1.empty()){ //Reverse q1 and put it into q2, then you can access to front of queue
                    q2.push(q1.top());
                    q1.pop();
                }
            }
            
            if(!q2.empty()){ //Remove or print element
                if(choice == 2) q2.pop();
                else cout << q2.top() << endl;
            }
        }
    }
    
    return 0;
}