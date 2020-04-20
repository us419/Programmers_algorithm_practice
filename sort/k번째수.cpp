#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> array2;
    for(vector<int> temp: commands)
    {
        int i = temp[0];
        int j = temp[1];
        int k = temp[2];
        array2 = array;
        sort(array2.begin()+i-1, array2.begin()+j);
        for (int a : array2)
            cout << a << " ";
        cout << endl;
        answer.push_back(array2[i+k-2]);
    }
    return answer;
}