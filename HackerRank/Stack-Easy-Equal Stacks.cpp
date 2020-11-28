//Stack-Easy-Equal Stacks
//https://www.hackerrank.com/challenges/equal-stacks/problem

#include <iostream>
#include <vector>
using namespace std;

int total(vector<int> v){
    int sum = 0;
    for(auto &i:v) sum += i; //Loop and count the sum of this stack
	
	/* If you really want to use it like a stack you can use this loop
	while(v.back() != NULL){ //When the last value is available
		sum += v.back(); //Add up
		v.pop_back(); //Pop the last element
	}*/
	
    return sum;
}

int equalStacks(vector<int> s1, vector<int> s2, vector<int> s3) {
    int t1 = total(s1); //Get the start total of the stack
    int t2 = total(s2);
    int t3 = total(s3);
    while(t1 != t2 || t2 != t3){ //When every stack is not the same
        if(t1 > t2 && t1 > t3){
            t1 -= s1[0]; //If stack 1 is the largest, subtract from the total
            s1.erase(s1.begin()); //Pop the last element of stack(the vector is reversed so delete first element)
        }else if(t3 > t2){ //If stack 3 is bigger than stack 2
            t3 -= s3[0];
            s3.erase(s3.begin());
        }else{
            t2 -= s2[0];
            s2.erase(s2.begin());
        }
    }
    return t1; //Return the total
	//If we keep update the total by counting it again and again, time complexity is huge
}

int main(){
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	int num, i;
	int count1;
	int count2;
	int count3;
	
	cin >> count1 >> count2 >> count3;
	
	for(i = 0; i < count1; i++){
		cin >> num;
		v1.push_back(num);
	}
	
	for(i = 0; i < count2; i++){
		cin >> num;
		v2.push_back(num);
	}
	
	for(i = 0; i < count3; i++){
		cin >> num;
		v3.push_back(num);
	}
	
	cout << equalStacks(v1,v2,v3) << endl;
}