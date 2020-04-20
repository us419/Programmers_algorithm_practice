#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <set>
#include <algorithm>

using namespace std;

bool isPrime(int k)
{
    if (k==0 || k==1)
        return false;
    if (k==2)
        return true;
    int n = sqrt(k);
    for (int i=2; i<=n; i++)
    {
        if (k % i == 0)
            return false;
    }
    return true;
}

int solution(string numbers) {
    sort(numbers.begin(), numbers.end());
    set<int> primes;
    do
    {
        for (int i=0; i<numbers.size(); i++)
        {
            string temp = numbers.substr(i);
            if (isPrime(stoi(temp)))
                primes.insert(stoi(temp));
        }
    } while (next_permutation(numbers.begin(), numbers.end()));
    
    int answer = primes.size();
    return answer;
}