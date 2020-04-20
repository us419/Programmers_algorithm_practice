#include <string>
#include <vector>

using namespace std;

int count=0;

void dfs(const vector<vector<int>>& computers, vector<int>& visited, int here)
{
    if (visited[here])
    {
        count++;
        return;
    }
    visited[here] = 1;
    for (int i=0; i<computers.size(); i++)
        if (computers[here][i] && !visited[i])
            dfs(computers, visited, i);
}

int solution(int n, vector<vector<int>> computers) {
    vector<int> visited(n, 0);
    for (int i=0; i<n; i++)
        dfs(computers, visited, i);
    return n - count;
}