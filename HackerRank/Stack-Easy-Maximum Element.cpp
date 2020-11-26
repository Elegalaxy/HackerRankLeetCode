//Stack-Easy-Maximum Element
//https://www.hackerrank.com/challenges/maximum-element/problem

#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int count, choice, num;
    stack<int> stk;
    cin >> count;
	
    for(int i = 0; i < count; i++){ //How many intructions
        cin >> choice; //User choice
        switch(choice){
            case 1:
                cin >> num;
                if(stk.empty() || (num > stk.top())) stk.push(num); //Push element into stack if it is empty or it is bigger than top element
                else stk.push(stk.top()); //Push the maximum again if element is smaller than top

                break;
            case 2:
                stk.pop(); //Remove top element
                break;
            case 3:
                cout << stk.top() << endl; //The top element will always be the Largest number
                break;
            default:
                break;
        }
    }

	return 0;
}