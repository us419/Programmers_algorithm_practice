#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> hash_map;
    for (vector<string> i : clothes)
    {
        hash_map[i[1]]++;
    }
    vector<int> arr;
    unordered_map<string, int>::iterator it;
    for(it=hash_map.begin(); it!=hash_map.end(); it++)
    {
        arr.push_back(hash_map[it->first]);
    }
    int answer = 1;
    for (int i : arr)
        answer *= i+1;
    return answer-1;
}