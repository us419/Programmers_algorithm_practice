#include <string>
#include <vector>

using namespace std;

int dp(vector<vector<int>>& cache, const vector<vector<int>>& puddles, int m, int n)
{
    if (m==0 || n==0)
        return 0;
    int& ret = cache[n][m];
    if (ret != -1)
        return ret;
    if (m==1 && n==1)
        return ret = 1;
    return ret = (dp(cache, puddles, m-1, n) + dp(cache, puddles, m, n-1)) % 1000000007;
}

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> cache(n+1, vector<int>(m+1, -1));
    for (vector<int> p : puddles)
        cache[p[1]][p[0]] = 0;
    int answer = dp(cache, puddles, m, n);
    return answer;
}