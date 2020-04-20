#include <string>
#include <vector>

using namespace std;

long long dp(vector<long long>& cache, int idx)
{
    long long& ret = cache[idx];
    if (ret != -1)
        return ret;
    
    ret = dp(cache, idx-1) + dp(cache,idx-2);
    return ret;
}

long long solution(int N) {
    vector<long long> cache(N,-1);
    cache[0] = 1;
    cache[1] = 1;
    dp(cache, N-1);
    if (N==1)
        return 4;
    long long answer = 4*cache[N-1] + 2*cache[N-2];
    return answer;
}