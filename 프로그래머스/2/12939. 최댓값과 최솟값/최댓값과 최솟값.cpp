#include <bits/stdc++.h>

using namespace std;

vector<string> split(string s,string splitter){
    vector<string> ret;
    s+=splitter;
    int idx;
    while((idx=s.find(splitter)) != string::npos){
        string tmp = s.substr(0,idx);
        ret.push_back(tmp);
        //cout << tmp << '\n';
        s=s.substr(idx+splitter.size());
    }    
    return ret;
}

string solution(string s) 
{
    vector<string> num = split(s," ");
    int maxi = stoi(num[0]);
    int mini = stoi(num[0]);
    for(auto a : num)
    {
        int buf = stoi(a);
        maxi = buf>maxi ? buf : maxi;
        mini = buf<mini ? buf : mini;
    }
    string answer = to_string(mini)+" "+to_string(maxi);
    return answer;
}