#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dp(vector<vector<int>>& cache, vector<vector<int>>& triangle, int a, int b)
{
    int& ret = cache[a][b];
    if (ret != -1)
        return ret;
    if (a == cache.size()-1)
        return ret = triangle[a][b];
    ret = max(dp(cache, triangle, a+1, b), dp(cache, triangle, a+1, b+1)) + triangle[a][b];
    return ret;
}

int solution(vector<vector<int>> triangle) {
    int n = triangle.size();
    vector<vector<int>> cache(n, vector<int>(n,-1));
    int answer = dp(cache, triangle, 0, 0);
    return answer;
}