//Stack-Medium-Balanced Brackets
//https://www.hackerrank.com/challenges/balanced-brackets/problem

#include <iostream>
#include <stack>
using namespace std;

string isBalanced(string s) {
    stack<char> stk;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{') stk.push(s[i]); //If this is open brackets, push into stack
        else{
            if(stk.empty() || abs(s[i] - stk.top()) > 2) return "NO"; //if there is no close bracket or not the same pair then it is not valid
            else stk.pop(); //If it is same pair of close bracket then pop the last bracket
        }
    }
    if(stk.empty()) return "YES"; //If it is totally empty return YES
    else return "NO"; //If got one element left return NO
}

int main(){
	string s;
	cin >> s;
	cout << isBalanced(s) << endl;
	return 0;
}