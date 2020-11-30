//Stack-Medium-Largest Rectangle
//https://www.hackerrank.com/challenges/largest-rectangle/problem

#include <iostream>
#include <vector>
using namespace std;

long largestRectangle(vector<int> h) {
    int max = 0,current = 0,top,i;
    vector<int> v; //Use to record the starting index
    v.push_back(0); //Start at 0
    for(i = 1; i < h.size(); i++){
        if(h[i] > h[v.back()]) v.push_back(i); //When this height is higher than last one, push back index (start a new rectangle)
        else{
            while(!v.empty() && h[v.back()] > h[i]){ //When this height is lower than last height, start calculate area (end of rectangle)
                top = h[v.back()]; //Get height from previous index
                v.pop_back(); //Pop previous index
                if(v.empty()) current = top*i; //If the stack is empty , calculate the area, height * all block(length)
                else current = top*(i-v.back()-1); //if not, calculate last rectangle area Size = height(last rectangle height) * (currentIndex - 1(length))
                
                if(current > max) max = current; //Replace max if current is bigger
            }
            v.push_back(i); //Push current index into stack (start of current rectangle)
        }
    }
    
    while(!v.empty()){ //When still got rectangle that haven't reach the end
        top = h[v.back()]; //Do the same thing until no more rectangle is not ended
        v.pop_back();
        if(v.empty()) current = top*i;
        else current = top*(i-v.back()-1);
        if(current > max) max = current;
    }

    return max;
}

//Watch this video for a deeper explaination
//https://www.youtube.com/watch?v=VNbkzsnllsU&t=536s

int main(){
	vector<int> v;
	int count,len;
	cin >> count;
	for(int i = 0; i < count; i++){
		cin >> len;
		v.push_back(len);
	}
	
	cout << largestRectangle(v) << endl;
	return 0;
}