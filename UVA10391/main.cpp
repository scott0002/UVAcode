#include <bits/stdc++.h>

using namespace std;

int main()
{
    set<string> s;
    string tmp;
    while(cin>>tmp)
        s.insert(tmp);
    for(set<string>::iterator i=s.begin(); i!=s.end(); i++)
    {
        string s1,s2;
        for(int j=1; j<i->size(); j++)
        {
            s1=i->substr(0,j);
            s2=i->substr(j,i->size()-j);
            //cout<<*i<<endl;
           //cout<<s1<<' '<<s2<<endl;
            if(s.find(s1)!=s.end() && s.find(s2)!=s.end())
            {
                cout<<*i<<endl;
                break;
            }
        }

    }
    return 0;
}
