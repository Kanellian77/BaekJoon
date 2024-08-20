#include <string>
#include <vector>

using namespace std;
int gcd(int a, int b)
{   
    int c;
    while(b!=0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
int solution(vector<int> arr) {
    int answer = arr[0];
    for(int i = 1 ; i< arr.size(); i++)
    {
        answer = answer*arr[i]/gcd(answer, arr[i]);
    }
    return answer;
}