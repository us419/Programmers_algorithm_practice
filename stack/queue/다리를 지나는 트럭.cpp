#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<pair<int,int>> bridge_q;
    int count = 0;
    int i=0;
    int current_weight = 0;
    do
    {
        count++;
        if (count - bridge_q.front().first == bridge_length)
        {
            current_weight -= bridge_q.front().second;
            bridge_q.pop();
        }
        if (weight >= current_weight + truck_weights[i] && i<truck_weights.size())
        {
            bridge_q.push(make_pair(count, truck_weights[i]));
            current_weight += truck_weights[i];
            i++;
        }
    } while (!bridge_q.empty());
    
    int answer = count;
    return answer;
}