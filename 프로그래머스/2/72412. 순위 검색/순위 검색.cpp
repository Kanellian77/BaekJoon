#include <bits/stdc++.h>

using namespace std;



vector<string> split(string s,string splitter){
    vector<string> ret;
    s+=splitter;
    int idx;
    while((idx=s.find(splitter)) != string::npos){
        string tmp = s.substr(0,idx);
        ret.push_back(tmp);
        s=s.substr(idx+splitter.size());
    }    
    return ret;
}
vector<int> solution(vector<string> info, vector<string> query) 
{
    vector<int> answer;
    
    map<string,string> table;
    table["cpp"] = "1",table["java"] = "2", table["python"] = "3";
    table["backend"] = "1",table["frontend"] = "2";
    table["junior"] = "1",table["senior"] = "2";
    table["chicken"] = "1",table["pizza"] = "2";
    
    // info 정제
    map<string, vector<int>> information;
    for(auto s : info)
    {
        auto buf = split(s, " ");
        string num;
        for(int i = 0; i < 4 ; i++)
        {
            num+=table[buf[i]];
        }
        information[num].push_back(stoi(buf[4]));
    }
    
    // info 소팅
    for(auto& p: information){
        sort(p.second.begin(), p.second.end());
    }
    
    for(auto s : query)
    {
        auto buf = split(s, " ");
        vector<string> sq;
        sq.push_back(buf[0]);
        sq.push_back(buf[2]);
        sq.push_back(buf[4]);
        sq.push_back(buf[6]);
        sq.push_back(buf[7]);
        
        vector<string> checker[4];
        for(int i = 0 ; i < 4; i++)
        {
            if(sq[i] != "-")
            {
                checker[i] = {table[sq[i]]};
            }
            else
            {
                checker[i] = {"1","2"};
                if(i==0) checker[i].push_back("3");
            }
        }
        
        
        int cnt = 0;
        for(auto c1 : checker[0])
        {
            for(auto c2 : checker[1])
            {
                for(auto c3 : checker[2])
                {
                    for(auto c4 : checker[3])
                    {
                        string key = c1+c2+c3+c4;
                        int target = stoi(sq[4]);
                        auto it = lower_bound(information[key].begin(), information[key].end(), target);
                        cnt += information[key].end()-it;
                    }
                }
            }
        }
        answer.push_back(cnt);
    }
    
    return answer;
}