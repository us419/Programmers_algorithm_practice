#include <string>
#include <vector>
#include <utility>

using namespace std;

vector<pair<int,int>> findFactor(int k)
{
    int n = k / 2;
    vector<pair<int,int>> factors;
    for (int i=2; i<n; i++)
    {
        if (k % i == 0)
        {
            int j = k / i;
            factors.push_back(make_pair(j,i));
        }
    }
    return factors;
}

vector<int> solution(int brown, int red) {
    vector<int> answer;
    int sum = brown + red;
    vector<pair<int,int>> factors = findFactor(sum);
    for (pair<int,int> i : factors)
    {
        if ((i.first-2) * (i.second-2) == red)
        {
            answer.push_back(i.first);
            answer.push_back(i.second);
            break;
        }
    }
    return answer;
}