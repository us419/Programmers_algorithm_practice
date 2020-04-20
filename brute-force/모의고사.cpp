#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
// 1 : 12345
// 2 : 21232425
// 3 : 3311224455

using namespace std;

class one
{
    int i = 0;
    vector<int> pattern = {1,2,3,4,5};
public:
    int getNow()
    {
        return pattern[i];
    }

    int next()
    {   
        i++;
        if (i==5)
            i = 0;
        return pattern[i];
    }
};

class two
{
    int i = 0;
    vector<int> pattern = {2,1,2,3,2,4,2,5};
public:
    int getNow()
    {
        return pattern[i];
    }
    int next()
    {   
        i++;
        if (i==8)
            i = 0;
        return pattern[i];
    }
};

class three
{
    int i = 0;
    vector<int> pattern = {3,3,1,1,2,2,4,4,5,5};
public:
    int getNow()
    {
        return pattern[i];
    }
    int next()
    {   
        i++;
        if (i==10)
            i = 0;
        return pattern[i];
    }
};

int calc(vector<int>& answers, int option)
{
    int sum = 0;
    int n = answers.size();
    if (option == 1)
    {
        one first;
        if (answers[0] == first.getNow())
            sum++;
        for (int i=1; i<n; i++)
        {
            if (answers[i] == first.next())
                sum++;
        }
    }
    if (option == 2)
    {
        two second;
        if (answers[0] == second.getNow())
            sum++;
        for (int i=1; i<n; i++)
        {
            if (answers[i] == second.next())
                sum++;
        }
    }
    if (option == 3)
    {
        three third;
        if (answers[0] == third.getNow())
            sum++;
        for (int i=1; i<n; i++)
        {
            if (answers[i] == third.next())
                sum++;
        }
    }
    return sum;
}

vector<int> solution(vector<int> answers) {
    int first = calc(answers, 1);
    int second = calc(answers, 2);
    int third = calc(answers, 3);
    int max_num = max(max(first, second), third);
    vector<int> answer;
    vector<int> temp = {first, second, third};
    {
        for (int i=0; i<3; i++)
        {
            if(temp[i] == max_num)
                answer.push_back(i+1);
        }
    }
    return answer;
}