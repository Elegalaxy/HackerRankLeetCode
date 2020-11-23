//Array-Easy-Left Rotation
//https://www.hackerrank.com/challenges/array-left-rotation/problem

#include <iostream>
#include<vector>
using namespace std;

vector<int> rotateLeft(int d, vector<int> arr) {
    for(int i = 0; i < d; i++){
        arr.push_back(arr[0]); //Push the first element into end
        arr.erase(arr.begin()); //Erase the first element, the second element will become first
    }
    return arr;
}

int main(){
	vector<int> v1;
	int size, count, num;
	cin >> size >> count;
	for(int i = 0; i < size; i++){
		cin >> num;
		v1.push_back(num);
	}
	
	for(auto &i:v1) cout << i << " "; //Loop through the vector
	cout << endl;
	v1 = rotateLeft(count, v1);
	for(auto &i:v1) cout << i << " ";
	cout << endl;
}