#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;
    int sum = n;
    while(sum != 0)
    {
        if(sum%2==1)
        {
            ans++;
            sum--;
        }
        else
        {
            sum /= 2;
        }
        
    }
        
    
    return ans;
}