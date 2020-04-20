#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    sort(reserve.begin(), reserve.end());
    sort(lost.begin(), lost.end());
    for (int i=0; i<reserve.size(); i++)
    {
        for (int j=0; j<lost.size(); j++)
        {
            if (reserve[i] == lost[j])
            {
                reserve[i] = -1;
                lost[j] = -1;
                break;
            }
        }
    }
    for (int i : reserve)
    {
        if (i == -1)
            continue;
        for (int j=0; j<lost.size(); j++)
        {
            if (lost[j] == i-1)
            {
                lost[j] = -1;
                break;
            }
            if (lost[j] == i+1)
            {
                lost[j] = -1;
                break;
            }
        }
    }
    int answer = 0;
    for (int i : lost)
        if (i != -1)
            answer++;
    return n - answer;
}