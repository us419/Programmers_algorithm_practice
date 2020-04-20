#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int changeChar(char c)
{
    if (c>='A' && c<='N')
        return c - 'A';    
    else
        return abs(c - 'Z' - 1);
}

int countMove(string name)
{
    vector<int> idx;
    for (int i=1; i<name.size(); i++)
    {
        if (name[i] != 'A')
            idx.push_back(i);
    }
    int k = name.length() - idx.front();
    return min(idx.back(), k);
}

int solution(string name) {
    int answer = 0;
    for (char i : name)
        answer += changeChar(i);
    answer += countMove(name);
    return answer;
}