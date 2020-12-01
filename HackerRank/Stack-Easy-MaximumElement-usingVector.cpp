//Stack-Easy-Maximum Element
//https://www.hackerrank.com/challenges/maximum-element/problem
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int max = INT8_MIN;					// the minimum integer which is -128
    vector<int> stack;					// using vector
    int N;
    cin >> N;
    for (int i=0; i<N; i++)
    {
        int type;
        cin >> type;
        switch (type)
        {
            case 1:
                int x;
                cin >> x;
                stack.push_back(x);
                if(x>max)
                {
                    max = x;
                }
                break;
            case 2:
                if(stack.at(stack.size()-1) == max)
                {
                    max = INT8_MIN;
                    for(int i=0; i<stack.size()-1; i++)
                    {
                        if(stack.at(i) > max)
                        {
                            max = stack[i];
                        }
                    }
                }
                stack.pop_back();
                
                break;
            case 3:
                cout << max << endl;
                break;
            default:
                break;
        }
    }
    return 0;
}

