#include <string>
#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>

using namespace std;

bool compare(pair<int,int>& a, pair<int,int>& b)
{
    if (a.first > b.first)
        return true;
    if (a.first == b.first)
    {
        if (a.second < b.second)
            return true;
        else
            return false;
    }
    if (a.first < b.first)
        return false;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> hash_map;
    for (int i=0; i<genres.size(); i++)
    {
        if (hash_map.empty())
            hash_map.insert(make_pair(genres[i], plays[i]));
        else
        {
            if (hash_map.count(genres[i]))
                hash_map[genres[i]] += plays[i];
            else
                hash_map.insert(make_pair(genres[i], plays[i]));
        }
    }
    unordered_map<string, int>::iterator it;
    vector<pair<int, string>> counts;
    for (it=hash_map.begin(); it!=hash_map.end(); it++)
        counts.push_back(make_pair(it->second, it->first));
    sort(counts.begin(), counts.end(), greater<pair<int,string>>());
    for (pair<int,string> i : counts)
    {
        vector<pair<int, int>> temp;
        for (int j=0; j<genres.size(); j++)
        {
            if (genres[j] == i.second)
            {
                temp.push_back(make_pair(plays[j], j));
            }
        }
        sort(temp.begin(), temp.end(), compare);
        if (temp.size() == 1)
            answer.push_back(temp[0].second);
        else
        {
            for (int i=0; i<2; i++)
                answer.push_back(temp[i].second);
        }
    }
    return answer;
}