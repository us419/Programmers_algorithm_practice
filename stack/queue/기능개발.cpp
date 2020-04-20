#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    queue<int> D_day;
    for (int i=0; i<progresses.size(); i++)
    {
        int temp = ((100-progresses[i]) % speeds[i] == 0) ? (100-progresses[i]) / speeds[i] : (100-progresses[i]) / speeds[i] + 1;
        D_day.push(temp);
    }
    vector<int> answer;
    int pivot,count;
    while (!D_day.empty())
    {
        pivot = D_day.front();
        D_day.pop();
        count = 1;
        while (!D_day.empty() && D_day.front() <= pivot)
        {
            count++;
            D_day.pop();
        }
        answer.push_back(count);
    }

    return answer;
}