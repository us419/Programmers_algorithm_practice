#include <string>
#include <vector>
#include <set>
#include <string>

using namespace std;

int strike(int a, int b)
{
    int count=0;
    string A = to_string(a);
    string B = to_string(b);
    for (int i=0; i<3; i++)
    {
        if (A[i] == B[i])
            count++;
    }
    return count;
}

int ball(int a, int b)
{
    string A = to_string(a);
    string B = to_string(b);
    int count=0;
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
        {
            if (A[i] == B[j])
                count++;
        }
    return count - strike(a,b);
}
bool isAnswer(int k, vector<vector<int>>& baseball)
{
    string K = to_string(k);
    set<char> s;
    for (int i=0; i<3; i++)
    {
        if (K[i] == '0')
            return false;
        s.insert(K[i]);
    }
    if (s.size() != 3)
        return false;
    for (vector<int> i : baseball)
    {
         if (strike(i[0], k) != i[1] || ball(i[0], k) != i[2])
            return false;
    }
    return true;
}

int solution(vector<vector<int>> baseball) {
    int answer = 0;
    string temp = to_string(answer);
    for (int i=100; i<1000; i++)
    {
        if (isAnswer(i, baseball))
            answer++;
    }
    return answer;
}