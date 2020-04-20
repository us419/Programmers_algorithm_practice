#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> budgets, int M) {
    sort(budgets.begin(), budgets.end());
    int sum = 0;
    int n = budgets.size();
    int answer = 0;
    bool isOK = true;
    for (int i=0; i<budgets.size(); i++)
    {
        if (sum + budgets[i] * (n-i) >= M)
        {
            answer = (M-sum) / (n-i);
            isOK = false;
            break;
        }
        sum += budgets[i];
    }
    if (isOK)
        answer = budgets[n-1];
        
    return answer;
}