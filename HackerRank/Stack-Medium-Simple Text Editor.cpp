//Stack-Medium-Simple Text Editor
//https://www.hackerrank.com/challenges/simple-text-editor/problem

#include <iostream>
#include <vector>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int count,choice,temp;
    string word,tempStr;
    vector<string> s; //Use stack to record the previous string
    
    cin >> count;
    for(int i = 0; i < count; i++){
        cin >> choice; //User choice
        switch(choice){
            case 1:
                s.push_back(word); //Push back current string
                cin >> tempStr;
                word += tempStr; //Add new string
                break;
            case 2:
                s.push_back(word);
                cin >> temp;
                word.erase(word.length()-temp, temp); //Delete string
                break;
            case 3:
                cin >> temp;
                cout << word[temp-1] << endl; //Print out char
                break;
            case 4:
                word = s.back(); //Undo the string
                s.pop_back();
                break;
        }
    }
    return 0;
}
