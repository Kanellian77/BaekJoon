#include <bits/stdc++.h>
#include <vector>

using namespace std;
// 1차로 가장많이 재생된 장르를 먼저 찾는것임 장르가 많음 ㅇㅇ
// 맵으로 우선 장르 순위부터 나눔(1빠따) 

bool comp(pair<string,int> a, pair<string,int> b)
{
    return a.second > b.second;
}

bool mlistcomp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    
    //정답
    vector<int> answer;
    // 토탈 장르 플레이수를 통해 정리
    map<string, int> buf;
    // 각 장르별 곡들의 (고유번호, 플레이수)
    map<string, vector<pair<int, int>>> mlist;
    // 전체 곡의 갯수
    int cnt = genres.size();
    
    // 토탈장르 플레이수 + 장르별곡들의 순위를 만들 것
    for(int i = 0 ; i< cnt ; i++)
    {
        buf[genres[i]] += plays[i];
        mlist[genres[i]].push_back({i, plays[i]});
    }
    
    for(auto &p : mlist)
    {
        sort(p.second.begin(), p.second.end(), mlistcomp);
    }
    
    vector<pair<string, int>> total;
    total.assign(buf.begin(), buf.end());
    
    sort(total.begin(), total.end(),comp);
    
    // genre는 결국 장르 총순위대로 결정된 것
    for(auto genre : total)
    {
        string name = genre.first;
        for(int i = 0; i < 2 && i< mlist[name].size() ; i++)
            answer.push_back(mlist[name][i].first);
        
        
    }
    
    
    return answer;
}