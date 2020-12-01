//Queue-Hard-Truck Tour
//https://www.hackerrank.com/challenges/truck-tour/problem

#include <iostream>
#include <vector>
using namespace std;

/*
This question is not ask for the whole loop journey, just from one station to the last station
*/

int truckTour(vector<vector<int>> petrolpumps) {
    long start,current = 0,currentPetrol = 0;
    for(start = 0; start < petrolpumps.size(); start++){
        currentPetrol += petrolpumps[start][0] - petrolpumps[start][1]; //Add petrol and minus distance when reach a station
        if(currentPetrol < 0){ //When the distance is more than petrol
            currentPetrol = 0; //Reset petrol
            if(start+1 != petrolpumps.size()) current = start+1; //Reset the starting point to the next station
            else current = -1; //If no station can give enough petrol return -1
        }
    }
    return current;
}

int main(){
	int count;
	cin >> count;
	vector<int> temp;
	vector<vector<int>> v(count);
	
	for(int i = 0; i < count; i++){
		v[i].resize(2);
		cin >> v[i][0];
		cin >> v[i][1];
	}
		
	cout << truckTour(v) << endl;
	
	return 0;
}