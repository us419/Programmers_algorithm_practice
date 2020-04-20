#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int dp(const vector<int>& left, const vector<int>& right, vector<vector<int>>& cache, int a, int b)
{
    if (b==0)
        return 0;

    int& ret = cache[a][b];
    if (ret != -1)
        return ret;

    if (a==0)
    {
        int sum = 0;
        for (int i=0; i<b; i++)
            sum += right[i];
        return ret = sum;
    }

    if (left[a] > right[b-1])
        ret = dp(left, right, cache, a, b-1) + right[b-1];
    
    else
    {
        ret = max(dp(left, right, cache, a-1, b), dp(left, right, cache, a-1, b-1));
    }

    if (b==right.size()-1)
        if (left[a] > right[b])
            return ret = ret + right[b];
        else
            return ret;
    else
    {
        return ret;
    }
    
}

int solution(vector<int> left, vector<int> right) {
    int n = left.size();
    vector<vector<int>> cache(n, vector<int>(n,-1));
    for (int i=0; i<n; i++)
        dp(left, right, cache, i, n-1);
    for (int i=0; i<n; i++)
        dp(left, right, cache, n-1, i);
    int answer = 0;
    for (int i=0; i<n; i++)
        answer = max(answer, cache[n-1][i]);
    for (int i=0; i<n; i++)
        answer = max(answer, cache[i][n-1]);
    for (vector<int> i : cache)
    {
        for (int j : i)
            cout << j << " "; 
        cout << endl;
    }
    return answer;
}