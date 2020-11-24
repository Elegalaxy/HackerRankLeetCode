//Array-Easy-Running Sum of 1d Array
//https://leetcode.com/problems/running-sum-of-1d-array/

#include <iostream>
#include <vector>
using namespace std;

vector<int> runningSum(vector<int>& nums) {
        int current = nums[0]; //Total number for now
        for(int i = 1; i < nums.size(); i++){
            current += nums[i]; //Sum up current number with total number for now 
            nums[i] = current; //Set this number to total number for now
        }
        return nums;
}

int main(){
	vector<int> v1{3,1,2,10,1};
	for(auto &i:v1) cout << i << " "; //Cout original vector
	cout << endl;
	
	v1 = runningSum(v1);
	for(auto &i:v1) cout << i << " "; //Cout new vector
	cout << endl;
	
	return 0;
}