#include <string>
#include <vector>
#include <queue>

using namespace std;

void makeGraph(const vector<vector<int>>& edge, vector<vector<int>>& graph)
{
    for (vector<int> i : edge)
    {
        graph[i[0]-1][i[1]-1] = 1;
        graph[i[1]-1][i[0]-1] = 1;
    }
}

void bfs(const vector<vector<int>>& graph, vector<int>& distance, vector<int>& discovered)
{
    queue<int> q;
    q.push(0);
    discovered[0] = 1;
    while(!q.empty())
    {
        int here = q.front();
        q.pop();
        for (int i=0; i<graph.size(); i++)
        {
            if (graph[here][i] && !discovered[i])
            {
                q.push(i);
                discovered[i] = 1;
                distance[i] = distance[here] + 1;
            }
        }
    }
}


int solution(int n, vector<vector<int>> edge) {
    vector<vector<int>> graph(n, vector<int>(n,0));
    makeGraph(edge, graph);
    vector<int> distance(n,0);
    vector<int> discovered(n,0);
    bfs(graph, distance, discovered);
    int max_num = 0;
    for (int i : distance)
        if (i > max_num)
            max_num = i;
    int answer = 0;
    for (int i : distance)
        if (i == max_num)
            answer++;
    return answer;
}