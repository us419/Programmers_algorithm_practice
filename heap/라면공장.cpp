#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    priority_queue<int, vector<int>> que;
    int i = 0;
    for (int day = 0; day != k; day++) {
        if (dates[i] == day) {
            que.push(supplies[i]);
            i++;
        }
        if (!stock) {
            stock += que.top();
            que.pop();
            answer++;
        }
        stock--;
    }
    return answer;
}
