#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<string> solution(vector<vector<int>> line) 
{
    set<pair<int,int>> cross;
    
    int maxx = INT32_MIN, minx = INT32_MAX;
    int maxy = INT32_MIN, miny = INT32_MAX;
    
    for(int i = 0 ; i < line.size() ; i++ )
    {
        for(int j = i+1 ; j < line.size() ;j++)
        {
            ll head = line[i][0]*line[j][1] - line[i][1]*line[j][0];
            if (head != 0)
            {
                ll x = (1LL*line[i][1]*line[j][2]) - (1LL*line[i][2]*line[j][1]);
                ll y = (1LL*line[i][2]*line[j][0]) - (1LL*line[i][0]*line[j][2]);
                if(x%head == 0 && y%head==0)
                    cross.insert({x/head, y/head});
            }
        }
    }
        
    for(auto dot : cross)
    {
        maxx = max(maxx, dot.first);
        minx = min(minx, dot.first);
        maxy = max(maxy, dot.second);
        miny = min(miny, dot.second);
    }

    ll n = maxy - miny;
    ll m = maxx - minx;
    
    vector<string> answer;
    
    if (cross.size() != 0)
    {
        for(int i = 0; i<= n; i++)
        {
            string buf(m+1,'.');
            answer.push_back(buf);
        }
        for(auto dot : cross)
        answer[-dot.second+maxy][dot.first-minx] = '*';
    }
    
    
    
    return answer;
}