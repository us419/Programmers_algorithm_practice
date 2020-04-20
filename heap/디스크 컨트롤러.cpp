#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
    sort(jobs.begin(), jobs.end(), less<vector<int>>());
    vector<int> processing_times;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> waiting;
    queue<vector<int>> jobs_q;
    for (vector<int> i : jobs)
        jobs_q.push(i);
    int time = 0;
    bool isProcessing = false;
    int remain, start;
    while(processing_times.size() != jobs.size())
    {
        while(!jobs_q.empty() && jobs_q.front()[0] == time)
        {
            waiting.push(make_pair(jobs_q.front()[1], jobs_q.front()[0]));
            jobs_q.pop();
        }
        if (!isProcessing && !waiting.empty())
        {
            remain = waiting.top().first;
            start = waiting.top().second;
            waiting.pop();
            isProcessing = true;
        }
        remain--;
        time++;
        if (remain == 0)
        {
            isProcessing = false;
            processing_times.push_back(time - start);
        }
    }
    int sum = 0;
    for (int i : processing_times)
        sum += i;
    int answer = sum / processing_times.size();
    return answer;
}