//Array-Medium-Subrectangle Queries
//https://leetcode.com/problems/subrectangle-queries/

#include <iostream>
#include <vector>
using namespace std;

class SubrectangleQueries {
private:
    vector<vector<int>> rect;
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        rect = rectangle; //Implement vector
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) { //Update the subRectangle
        for(int i = row1; i <= row2; i++){ //Loop though row
            for(int j = col1; j <= col2; j++){ //Loop through column
                rect[i][j] = newValue; //Change value
            }
        }
    }
    
    int getValue(int row, int col) {
        return rect[row][col]; //Return required value
    }
};

//Main function is unknown