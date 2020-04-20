#include <string>
#include <vector>

using namespace std;

int count = 0;

void dfs(vector<int>& numbers, int idx, int sum, int target)
{
    if (idx == numbers.size()-1 && (sum + numbers[idx] == target || sum - numbers[idx] == target))
        count++;
    if (idx == numbers.size()-1)
        return;
    dfs(numbers, idx+1, sum + numbers[idx], target);
    dfs(numbers, idx+1, sum - numbers[idx], target);
}

int solution(vector<int> numbers, int target) {
    int sum = 0;
    dfs(numbers, 0, sum, target);
    return count;
}