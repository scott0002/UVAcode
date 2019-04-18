#include <bits/stdc++.h>

using namespace std;

int main()
{
    string line,s;
    set<string> ans;
    while(cin>>line)
    {
        for(int i=0; i<line.size(); i++)
        {
            if(line[i]<='Z'&&line[i]>='A')
                line[i]=tolower(line[i]);
            else if(line[i]>'z' || line[i]<'a')
                line[i]=' ';
        }
        stringstream ss(line);
        while(ss>>s)
            ans.insert(s);
    }
    for(auto x:ans)
            cout<<x<<endl;
    return 0;
}
