#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int compare(string a, string b)
{
    int aHour = stoi(a.substr(0,2));
    int bHour = stoi(b.substr(0,2));
    int aMinute = stoi(a.substr(3,2));
    int bMinute = stoi(b.substr(3,2));
    if (aHour > bHour)
        return 0;
    if (aHour < bHour)
        return 1;
    if (aMinute > bMinute)
        return 0;
    if (aMinute < bMinute)
        return 1;
    return 0;
}

string string_plus(string a, int t)
{
    int hour = stoi(a.substr(0,2));
    int minute = stoi(a.substr(3,2));
    if (minute + t < 60 && minute + t >9)
    {
        return a.substr(0,3) + to_string(minute+t);
    }
    else if (minute + t <=9 && minute + t >=0 && t != -1)
    {
        return a.substr(0,4) + to_string(minute+t);
    }
    else if (minute == 10 && t == -1)
    {
        return a.substr(0,3) + "09";
    }
    else if (minute + t <=9 && minute + t >=0)
    {
        return a.substr(0,4) + to_string(minute+t);
    }
    else if (minute + t < 0)
    {
        if (hour == 10)
        {
            return "09:59";
        }
        else if (hour > 10)
        {
            return to_string(hour-1) + ":59";
        }
        else
        {
            return "0" + to_string(hour-1) + ":59";
        }
    }
    else
    {
        if (hour + 1 >= 10 && minute + t - 60 > 9)
        {
            return to_string(hour + 1) + ":" + to_string(minute+t-60);
        }
        else if (hour + 1 >= 10 && minute + t - 60 <=9)
        {
            return to_string(hour + 1) + ":0" + to_string(minute+t-60);
        }
        else if (minute + t - 60 > 9)
        {
            return "0" + to_string(hour + 1) + ":" + to_string(minute+t-60);
        }
        else
        {
            return "0" + to_string(hour + 1) + ":0" + to_string(minute+t-60);
        }        
    }
    
}
vector<string> make_bustable(int n, int t)
{
    vector<string> busTable;
    string begin = "09:00";
    busTable.push_back(begin);
    for (int i=0; i<n-1; i++)
    {
        begin = string_plus(begin, t);
        busTable.push_back(begin);
    }
    return busTable;
}

string solution(int n, int t, int m, vector<string> timetable) {
    sort(timetable.begin(), timetable.end(), compare);
    vector<string> busTable = make_bustable(n, t);
    queue<string> q;
    vector<vector<string>> rider(n);
    for (string i : timetable)
        q.push(i);
    for (int i=0; i<busTable.size(); i++)
    {
        for (int j=0; j<m; j++)
        {
            if (!q.empty() && !compare(busTable[i], q.front()))
            {
                rider[i].push_back(q.front());
                q.pop();
            }
        }
    }
    cout << rider[n-1].size() << endl;
    for (string i : busTable)
        cout << i << " ";
    cout << endl;
    if (rider[n-1].size() < m)
        return busTable[n-1];

    if (rider[n-1].size() == m )
    {
        return string_plus(rider[n-1][m-1], -1);
    }
    string answer = "";
    return answer;
}