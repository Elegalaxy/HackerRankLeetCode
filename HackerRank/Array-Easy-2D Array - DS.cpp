//Array-Easy-2D Array - DS
//https://www.hackerrank.com/challenges/2d-array/problem

#include <iostream>
#include <vector>
using namespace std;

int hourglassSum(vector<vector<int>> arr) {
    int max; //Record the max for now
    for(int i = 1; i < arr.size()-1; i++){ //Loop from the 1, 1(middle part) because we calculate it base on 9x9 area
        for(int j = 1; j < arr[i].size()-1; j++){ //Loop until the last second element
            int count = arr[i-1][j-1] + arr[i-1][j] + arr[i-1][j+1] + arr[i][j] + arr[i+1][j-1] + arr[i+1][j] + arr[i+1][j+1]; 
            //Current count
            if((i == 1 && j == 1) || (count > max)) max = count; //Update the max
        }
    }
    return max;
}

int main(){
	vector<vector<int>> arr(6); //Initialize vector
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j]; //Input value
        }
    }

	/* Test input
	1 1 1 0 0 0
	0 1 0 0 0 0
	1 1 1 0 0 0
	0 0 2 4 4 0
	0 0 0 2 0 0
	0 0 1 2 4 0
	*/

    cout << hourglassSum(arr) << endl; //Print result
	
	return 0;
}