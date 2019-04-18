#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    vector<vector<string> > doc;
    map<string,vector<pair<int,int> > > DID;
    cin>>n;
    string line,s;
    for(int i=0; i<n; i++)
    {

        doc.push_back(vector<string>());
        while(getline(cin,line) &&line[0]!='*')
        {
            for(auto c:line)
                if(!isalpha(c))
                    c=' ';
                else
                    c=tolower(c);
            stringstream ss(line);
            while(ss>>s)
            {
                if(DID.find(s)==DID.end())
                    DID[s]=vector<pair<int,int> >();
                DID[s].push_back({i,doc[i].size()});
            }
            doc[i].push_back(line);
        }
    }
    int q;
    cin.ignore();
    cin>>q;
    string s1,s2;
    while(q--)
    {
        getline(cin,line);
        int type=0;//AND=1 OR=2 NOT=3 other=0
        stringstream ss(line);
        while(ss>>s)
        {
            if(s=="AND")
            {
                type=1;
                break;
            }
            if(s=="OR")
            {
                type=2;
                break;
            }
            if(s=="NOT")
            {
                type=3;
                break;
            }
        }
        stringstream ss1(line);
        switch(type)
        {
        case 0:
            vector<pair<int,int> > v=DID[s];
            if(v.empty())
                cout<<"Sorry, I found nothing."<<endl;
            else
                for(auto x:v)
                {
                    cout<<doc[x.first][x.second]<<endl;
                }
            break;
        case 1:
            ss1>>s1>>s>>s2;
            vector<pair<int,int> > v1=DID[s1];
            vector<pair<int,int> > v2=DID[s2];
            if(v1.empty()||v2.empty())
                cout<<"Sorry, I found nothing."<<endl;
            else
                for(auto x1:v1)
                {
                    for(auto x2:v2)
                        if(x1==x2)
                            cout<<doc[x1.first][x1.second]<<endl;
                }
            break;
        case 2:
            ss1>>s1>>s>>s2;
            vector<pair<int,int> > v1=DID[s1];
            vector<pair<int,int> > v2=DID[s2];
            merge(v1.begin(),v1.end(),v2.begin(),v2.end());
            if(v1.empty())
                cout<<"Sorry, I found nothing."<<endl;
            else
                for(auto x:v1)
                {
                    cout<<doc[x.first][x.second]<<endl;
                }
            break;
        case 3:
            vector<pair<int,int> > v=DID[s];
            bool flag=true;
            for(int i=0; i<n; i++)
            {
                for(auto x:v)
                    if(x.first==i)
                    {
                        flag=false;
                        break;
                    }
                if(flag)
                {
                    for(auto x:doc[i])
                        cout<<x<<endl;
                }
            }

            break;
        }
        cout<<"=========="<<endl;
    }
    return 0;
}
