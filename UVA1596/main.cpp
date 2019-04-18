#include <bits/stdc++.h>

using namespace std;

map<char,map<int,int> > arr;

int atoi(string s)
{
    int ans=0;
    for(int i=0; i<s.size(); i++)
    {
        ans=ans*10+(s[i]-'0');
    }
    return ans;
}
int callarr(string s)
{
    if(!isalpha(s[0]))
    {
        return atoi(s);
    }
    if(arr.find(s[0])==arr.end())
        return -1;
    int tmp1=callarr(s.substr(2,s.size()-3));
    if(tmp1<0 || tmp1>=arr[s[0]][-1])
        return -1;
    if(arr[s[0]].find(tmp1)==arr[s[0]].end())
        return -1;
    return arr[s[0]][tmp1];
}
void darr(string s)
{
    int index=atoi(s.substr(2,s.size()-3));
    arr[s[0]]=map<int,int>();
    arr[s[0]][-1]=index;
}
int main()
{
    string s;
    while(cin>>s && s[0]!='.')
    {
        arr.clear();
        int lnum=1;
        bool in=true;

        while(s[0]!='.')
        {

            bool inin=true;
            for(int i=0; i<s.size(); i++)
            {
                if(s[i]=='=')
                {
                    inin=false;
                    if(!isalpha(s[i+1]))
                    {
                        if(in&&arr.find(s[0])==arr.end())
                        {
                            cout<<lnum<<endl;
                            in=false;
                        }
                        int tmp1=callarr(s.substr(2,i-3));
                        if(in&&(tmp1<0 || tmp1>=arr[s[0]][-1]))
                        {
                            cout<<lnum<<endl;
                            in=false;
                        }

                        if(in)
                            arr[s[0]][tmp1]=atoi(s.substr(i+1,s.size()-i-1));
                            //cout<<callarr(s.substr(2,i-3))<<' '<<arr[s[0]][callarr(s.substr(2,i-3))]<<' '<<atoi(s.substr(i+1,s.size()-i-1))<<endl;
                    }
                    else
                    {
                        if(in&&arr.find(s[0])==arr.end())
                        {
                            cout<<lnum<<endl;
                            in=false;
                        }
                        if(in&&arr.find(s[i+1])==arr.end())
                        {
                            cout<<lnum<<endl;
                            in=false;
                        }
                        int tmp2=callarr(s.substr(2,i-3));
                        if(in&&(tmp2<0 || tmp2>=arr[s[0]][-1]))
                        {
                            cout<<lnum<<endl;
                            in=false;
                        }
                        int tmp3=callarr(s.substr(i+3,s.size()-i-4));
                        if(in&&(arr[s[i+1]].find(tmp3)==arr[s[i+1]].end()  || tmp3<0 || tmp3>=arr[s[i+1]][-1]))
                        {
                            cout<<lnum<<endl;
                            in=false;
                        }
                        if(in&&arr[s[i+1]][tmp3]<0)
                        {
                            cout<<lnum<<endl;
                            in=false;
                        }
                        if(in)
                            arr[s[0]][tmp2]=arr[s[i+1]][tmp3];
                            //cout<<callarr(s.substr(2,i-3))<<' '<<arr[s[0]][callarr(s.substr(2,i-3))]<<' '<<arr[s[i+1]][callarr(s.substr(i+3,s.size()-i-4))];
                    }

                }
            }
            if(in&&inin)
                darr(s);
            cin>>s;
            lnum++;
        }
        if(in)
            cout<<0<<endl;
    }
    return 0;
}
