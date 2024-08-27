#include<bits/stdc++.h>

using namespace std;

vector<int> solution(int e, vector<int> starts) 
{
    vector<int> answer;
    
    vector<int> dp(5000010);
    for(auto i : dp)
    {
        dp[i] = 0;
    }
    
    dp[1] = 1;
    for(int i = 2 ; i <= 5000000 ; i++)
        for(int j = 1 ; j <= 5000000/i ; j++)
            dp[i*j]++;
    
    
    
    vector<pair<int,int>> result(5000010);
    result[e] = {dp[e], e};
    for(int i = e ; i > 0 ; i--)
    {
        if( result[i+1].first <= dp[i] )
        {
            result[i].first = dp[i];
            result[i].second = i;
        }
        else
        {
            result[i] = result[i+1];
        }
    }
    
    for(auto i : starts)
    {
        answer.push_back(result[i].second);
    }
    
    
    return answer;
}