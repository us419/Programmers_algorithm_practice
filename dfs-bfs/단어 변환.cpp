#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

bool isNeighbor(string a, string b)
{
    int count = 0;
    for (int i=0; i<a.size(); i++)
        if (a[i] != b[i])
            count++;
    if (count == 1)
        return true;
    return false;
}

void makeGraph(const vector<string>& words, vector<vector<int>>& graph)
{
    for (int i=0; i<words.size(); i++)
        for (int j=0; j<words.size(); j++)
            if (isNeighbor(words[i], words[j]))
                graph[i][j] = 1;
}

void bfs(const vector<vector<int>>& graph, vector<int>& discovered, vector<int>& distance)
{
    queue<int> q;
    q.push(graph.size()-1);
    discovered[graph.size()-1] = 1;
    while (!q.empty())
    {
        int here = q.front();
        q.pop();
        for (int i=0; i<graph.size(); i++)
            if (graph[here][i] && !discovered[i])
            {
                discovered[i] = 1;
                q.push(i);
                distance[i] = distance[here] + 1;
            }
    }
}

int solution(string begin, string target, vector<string> words) {
    words.push_back(begin);
    int n = words.size();
    vector<vector<int>> graph(n, vector<int>(n,0));
    makeGraph(words, graph);
    vector<int> discovered(n,0);
    vector<int> distance(n,0);

    bfs(graph, discovered, distance);

    int end = -1;
    for (int i=0; i<words.size(); i++)
        if (words[i] == target)
            end = i;

    if (end == -1) 
        return 0;
    return distance[end];
}