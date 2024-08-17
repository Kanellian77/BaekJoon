#include <bits/stdc++.h>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> stac;
    
    for(auto a : s)
    {
        if (a =='(')
        {
            stac.push('(');
        }
        else
        {
            if(!stac.empty())
            {
                stac.pop();
            }
            else
            {   
                return false;
            }
        }
    }
    if(!stac.empty())
        answer = false;
    
    return answer;
}