//Array-Medium-Sparse Arrays
//https://www.hackerrank.com/challenges/sparse-arrays/problem

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
    vector<int> total;
    for(int i = 0; i < queries.size(); i++){ //Count how many time the string appeared, count will also return 0
        total.push_back(count(strings.begin(), strings.end(), queries[i])); //Push back the counted number
    }
    return total;
}

int main(){
	int strings_count, queries_count;
	vector<string> strings, queries;

    cin >> strings_count;
    for (int i = 0; i < strings_count; i++) { //Put string into vector
        string strings_item;
        cin >> strings_item;

        strings.push_back(strings_item);
    }

	cin >> queries_count;
    for (int i = 0; i < queries_count; i++) { //Put queries into vector
        string queries_item;
        cin >> queries_item;

        queries.push_back(queries_item);
    }
	
	vector<int> res = matchingStrings(strings, queries); //Call function
	for(auto &i:res) cout << i << endl;
	return 0;
}