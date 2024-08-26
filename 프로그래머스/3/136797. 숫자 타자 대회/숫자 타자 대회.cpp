#include <bits/stdc++.h>
#include <vector>

using namespace std;


int solution(string numbers) 
{
    vector<pair<int,int>> ij = {{3,1},
                                {0,0}, {0,1}, {0,2},
                                {1,0}, {1,1}, {1,2},
                                {2,0}, {2,1}, {2,2}};
    int w[10][10] = {};
    int di,dj;
    
    int*** dp = new int**[11];
    for(int i = 0; i < 11 ; i++)
    {
        dp[i] = new int*[11];
        for(int j = 0; j < 11 ; j++)
        {
            dp[i][j] = new int[100010];
            for(int n = 0; n < 100010 ; n++)
                dp[i][j][n] = 1000000;
            
        }
        
    }

    
    for(int n1 = 0; n1<=9; n1++)
    {
        for(int n2 = 0; n2<=9 ; n2++)
        {
            if(n1==n2)
            {
                w[n1][n2] = w[n2][n1] = 1;
                continue;
            }
            di = abs(ij[n1].first - ij[n2].first);
            dj = abs(ij[n1].second - ij[n2].second);
            
            if(di == 0|| dj == 0)
                w[n1][n2] = w[n2][n1] = max(di, dj)*2;
            else
            {
                int maxij = max(di,dj);
                int minij = min(di,dj);
                w[n1][n2] = w[n1][n2] = minij*3+(maxij-minij)*2;
                
            }
        }
    }
    
    int answer = 1000000000;
    numbers = "0" + numbers;
    
    dp[4][6][0] = 0;
    int bn = -1;
    int endn = numbers.size()-1;
    
    for(int n = 1; n <= endn; n++)
    {
        int obj = numbers[n]-'0';
        for(int leftn = 0 ; leftn <= 9 ; leftn++ )
        {
            for(int rightn = 0 ; rightn <= 9 ; rightn++ )
            {
                if(leftn == rightn || (bn!=-1 && leftn != bn && rightn != bn))
                    continue;
                
                // 오른손이 움직임
                if(obj != leftn)
                {
                    dp[leftn][obj][n] = min(dp[leftn][obj][n], dp[leftn][rightn][n-1] + w[obj][rightn]);
                    if(n==endn)
                        answer = min(answer, dp[leftn][obj][n]);
                }
                
                //왼손이 움직임
                if(obj != rightn)
                {
                    dp[obj][rightn][n] = min(dp[obj][rightn][n], dp[leftn][rightn][n-1] + w[obj][leftn]);
                    if(n==endn)
                        answer = min(answer, dp[obj][rightn][n]);
                }
            }
        }
        bn = obj;
    }
    
    return answer;
}