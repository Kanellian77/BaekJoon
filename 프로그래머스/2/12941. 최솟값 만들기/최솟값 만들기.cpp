#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int cnt = A.size()-1;
    for(int i = 0 ; i<= A.size(); i++)
    {
        answer += A[i]*B[cnt-i];
    }
        
    
    return answer;
}