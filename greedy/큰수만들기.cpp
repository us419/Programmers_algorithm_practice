#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    for (int i=0; i<k; i++)
    {
        bool isSort = true;
        for (int j=0; j<number.size(); j++)
        {
            if (number[j] < number[j+1])
            {
                number = number.substr(0, j) + number.substr(j+1);
                isSort = false;
                break;
            }
        }
        if (isSort)
            number.pop_back();
    }
    return number;
}