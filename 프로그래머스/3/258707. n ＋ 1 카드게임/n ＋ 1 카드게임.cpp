#include <bits/stdc++.h>
#include <vector>

using namespace std;


int n;

bool NR(set<int> &a, set<int> &b)
{
    for(int i : a)
    {
        int j = (n+1)-i;
        if(b.find(j)!= b.end())
        {
            a.erase(i);
            b.erase(j);
            return true;
        }
    }
    return false;    
}

int solution(int coin, vector<int> cards) 
{
    set<int> draw;
    set<int> hand;
    int round = 1;
    n = cards.size();
    int idx = n/3;
    
    for(int i = 0; i < n/3 ; i++)
    {
        hand.insert(cards[i]);
    }
    
    
    while(idx < n)
    {
        //뽑기
        for(int i = 0 ; i < 2 ; i++)
            draw.insert(cards[idx++]);    
        
        
        // 손에 있을때
        if(hand.size() >= 2 && NR(hand, hand))
        {
            round++;
        }
        // 뽑은카드 1장과 손에있는카드 1장일때
        else if(hand.size() >= 1 && coin>=1 && NR(hand, draw))
        {
            round++;
            coin--;
        }
        // 뽑은카드 2장일때
        else if(coin>=2 && NR(draw, draw))
        {
            round++;
            coin -= 2;
        }
        else
            return round;
        
    }
    
    return round;
}
