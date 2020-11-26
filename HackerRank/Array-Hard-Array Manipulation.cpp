//Array-Hard-Array Manipulation
//https://www.hackerrank.com/challenges/crush/problem

#include <vector>
#include <iostream>
using namespace std;

/*
Instead of recording all the number, I record the changes of the number.
Imagine playing Super Mario, starting point is when u eat a mushroom and grow up, and ending point 
is back to the size before you eat the mushroom.
Instead of keep recording the Mario height throught the whole game, I record the height only when his height has change.
And find the highest changes from all those changes
*/

long arrayManipulation(int n, vector<vector<int>> queries) {
    long int *a = new long int[n+1]();
    long int i,j,p,q,num,max = 0,temp = 0;
    for(i = 0; i < queries.size(); i++){
        p = queries[i][0]; //Get the starting point
        q = queries[i][1]; //Get the ending point
        num = queries[i][2]; //Get the number
        a[p] += num; //Add the number to the starting point
        if((q+1) <= n) a[q+1] -= num; //Minus the number next to the ending point (q+1)
    }
    
    for(j = 1; j <= n; j++){
        temp += a[j];
        if(temp > max) max = temp; //Find the max number
    }
    return max;
}

int main(){
	int i, j, size, query, tempNum;
	vector<vector<int>> vec;
	vector<int> temp;
	
	cin >> size >> query; //Input array size and query size
	for(i = 0; i < query; i++){
		for(j = 0; j < 3;j++){
			cin >> tempNum;
			temp.push_back(tempNum); //Input start, end, and the number to add
		}
		vec.push_back(temp);
		temp.clear();
	}
	
	cout << arrayManipulation(size, vec) << endl;
	
	return 0;
}