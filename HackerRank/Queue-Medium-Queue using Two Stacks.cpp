//Queue-Medium-Queue using Two Stacks
//https://www.hackerrank.com/challenges/queue-using-two-stacks/problem

#include <iostream>
#include <vector>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int i,count,temp,choice;
    vector<int> q;
    
    cin >> count;
    for(i = 0; i < count; i++){
        cin >> choice;
        switch(choice){
            case 1:
                cin >> temp;
                q.push_back(temp);
                break;
            case 2:
                q.erase(q.begin());
                break;
            case 3:
                cout << q[0] << endl;
                break;
        }
    }
    
    return 0;
}