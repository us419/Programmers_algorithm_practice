#include <string>
#include <vector>
#include <utility>
#include <stack>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    stack<pair<int,int>> s;
    pair<int,int> h = make_pair(1, heights[0]);
    answer.push_back(0);
    s.push(h);
    for (int i=1; i<heights.size(); i++)
    {
        while (!s.empty())
        {
            if (s.top().second > heights[i])
            {
                answer.push_back(s.top().first);
                s.push(make_pair(i+1, heights[i]));
                break;
            }
            else
            {
                s.pop();
            }
        }
        if (s.empty())
        {
            answer.push_back(0);
            s.push(make_pair(i+1, heights[i]));
        }
    }
    return answer;
}