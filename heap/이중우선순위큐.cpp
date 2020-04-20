#include <string>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

void list_insert(list<int>& sorted_list, int data)
{
    if (sorted_list.empty())
    {
        sorted_list.push_back(data);
        return;
    }
    list<int>::iterator it;
    for (it=sorted_list.begin(); it!=sorted_list.end(); it++)
    {
        if (data <= *it)
        {
            sorted_list.insert(it, data);
            return;
        }
    }
    sorted_list.push_back(data);
}

vector<int> solution(vector<string> operations) {
    list<int> sorted_list;
    for (string i : operations)
    {
        if (i[0] == 'I')
            list_insert(sorted_list, stoi(i.substr(2)));
        else
        {
            if (i[2] == '1' && !sorted_list.empty())
                sorted_list.pop_back();
            else if (i[2] == '-' && !sorted_list.empty())
                sorted_list.pop_front();
        }
    }

    vector<int> answer;
    if (sorted_list.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        answer.push_back(sorted_list.back());
        answer.push_back(sorted_list.front());
    }
    return answer;
}