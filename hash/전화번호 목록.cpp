#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// substr의 경우 substr(idx, npos)에서 npos가 실제 길이를 넘더라도 전부를 반환하고 끝 (에러 안뜸)
bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    for (int i=0; i<phone_book.size(); i++)
    {
        for (int j=i+1; j<phone_book.size(); j++)
        {
            if (phone_book[j].substr(0, phone_book[i].size()) == phone_book[i])
                return false;
        }
    }
    bool answer = true;
    return answer;
}