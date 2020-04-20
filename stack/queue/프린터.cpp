#include <string>
#include <vector>
#include <deque>

using namespace std;

bool isMax(deque<int>& priorities)
{
    int front = priorities.front();
    deque<int>::iterator it;
    for (it=priorities.begin(); it!=priorities.end(); it++)
    {
        if (*it > front)
            return false;
    }
    return true;
}

int solution(vector<int> priorities, int location) {
    deque<int> q;
    for (int i : priorities)
        q.push_back(i);
    int count=0;
    int i=0;
    while (true)
    {
        if (isMax(q))
        {
            q.pop_front();
            count++;
            if (i==location)
                break;
            i++;
        }
        else
        {
            q.push_back(q.front());
            q.pop_front();
            if (i==location)
                location += q.size();
            i++;
        }  
    }    
    int answer = count;
    return answer;
}