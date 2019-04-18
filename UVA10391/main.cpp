#include <bits/stdc++.h>

using namespace std;

int main()
{
    set<string> w;
    string s;
    while(cin>>s)
        w.insert(s);
    for(auto x:w)
    {
        for(int i=0; i<x.size()-1; i++)
            if(w.find(x.substr(0,i+1))!=w.end()\
               &&w.find(x.substr(i+1,x.size()-i-1))!=w.end())
            {
                cout<<x<<endl;
                break;
            }

    }
    return 0;
}
