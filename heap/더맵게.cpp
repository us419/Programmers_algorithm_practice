#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> min_heap;
    for (int i : scoville)
        min_heap.push(i);
    int answer = 0;
    while (min_heap.top() < K)
    {
        if (min_heap.size() == 1)
        {
            answer = -1;
            break;
        }
        int smallest = min_heap.top();
        min_heap.pop();
        int second = min_heap.top();
        min_heap.pop();
        int mix = smallest + second * 2;
        min_heap.push(mix);
        answer++;
    }
    return answer;
}