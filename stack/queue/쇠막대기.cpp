#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int solution(string arrangement) {
    string new_arr = "";
    for (int i=0; i<arrangement.size()-1; i++)
    {
        if (arrangement[i] == '(' && arrangement[i+1] == ')')
        {
            new_arr += 'r';
            i++;
        }
        else
        {
            new_arr += arrangement[i];
        }
    }

    vector<int> v;
    stack<char> s;
    for (char i : new_arr)
    {
        if (i == 'r')
            v.push_back(s.size());
        else if (s.empty())
            s.push(i);
        else
        {
            if (i == ')')
                s.pop();
            else
            {
                s.push(i);
            }
        }
    }
    int num_bar = 0;
    for (char i : new_arr)
    {
        if (i == '(')
            num_bar++;
    }
    int sum = 0;
    for (int i : v)
        sum += i;
    int answer = sum + num_bar;
    return answer;
}