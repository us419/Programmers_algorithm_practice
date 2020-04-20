#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> cache(10001,0);

void preCalc(int h, vector<int>& citations)
{
    if (citations[h-1] >= h)
        cache[h] = 1;
    else
    {
        cache[h] = 0;
    }
}

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), greater<int>());
    for(int h=1; h<=citations.size(); h++)
        preCalc(h, citations);
    for(int h=citations.size(); h>0; h--)
    {
        if (cache[h])
        {
            answer = h;
            break;
        }
    }
    return answer;
}