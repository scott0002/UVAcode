#include <bits/stdc++.h>

using namespace std;
string standalize(string s)
{
    for(int i=0; i<s.size(); i++)
        s[i]=tolower(s[i]);
    sort(s.begin(),s.end());
    return s;
}

int main()
{
    string line;
    vector<string> in;
    map<string,int> cnt;
    while(cin>>line&&line[0]!='#')
    {
        stringstream ss(line);
        string s;
        while(ss>>s)
        {
            in.push_back(s);
            cnt[standalize(s)]++;
        }
    }
    sort(in.begin(),in.end());
    for(auto x:in)
        if(cnt[standalize(x)]==1)
            cout<<x<<endl;
    return 0;
}
