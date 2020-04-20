#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string ab;
string ba;

int compare(string& a, string& b)
{
    if (a == b)
        return 1;
    ab.clear();
    ba.clear();
    ab = a+b;
    ba = b+a;
    for (int i=0; i<ab.length(); i++)
    {
        if(ab[i] > ba[i])
            return 1;
        if(ab[i] < ba[i])
            return 0;
    }
    return 0;
}

string solution(vector<int> numbers) {
    string answer = "";
    int sum = 0;
    for (int i : numbers)
        sum += i;
    if (sum == 0)
    {
        answer = "0";
        return answer;
    }
    vector<string> string_numbers(numbers.size());
    for (int i=0; i<numbers.size(); i++)
    {
        string_numbers[i] = to_string(numbers[i]);
    }
    sort(string_numbers.begin(), string_numbers.end(), compare);
    for (string i : string_numbers)
        answer += i;
    return answer;
}