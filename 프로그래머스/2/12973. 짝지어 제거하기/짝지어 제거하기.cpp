#include <bits/stdc++.h>

using namespace std;

int solution(string s)
{
    stack<char> stac;
    
    for(auto c : s)
    {
        if(stac.empty() || stac.top() != c)
        {
            stac.push(c);
        }
        else
        {
            stac.pop();
        }
    }
    
    if(stac.empty())
        return 1;
    
    return 0;
}