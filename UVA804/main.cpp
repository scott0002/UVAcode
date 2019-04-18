#include <bits/stdc++.h>

using namespace std;
struct transition
{
    map<int,int> input,output;
}tran[101];
int place[101];
int np,nt,nf;
void init()
{
    for(int i=1; i<=np; i++)
    {
        place[i]=0;
    }
    for(int i=1; i<=nt; i++)
    {
        tran[i].input.clear();
        tran[i].output.clear();
    }
}

bool firing()
{
    bool flag=true;
    for(int i=1; i<=nt; i++)
    {
        flag=true;
        for(auto x:tran[i].input)
        {
            if(place[x.first]<x.second)
            {
                flag=false;
                break;
            }
        }
        if(flag)
        {
            for(auto x:tran[i].input)
            {
                place[x.first]-=x.second;
            }
            for(auto x:tran[i].output)
            {
                place[x.first]+=x.second;
            }
                return true;
        }
    }
    return false;
}
bool solve()
{
    bool life=false;
    int cnt=0;
    while(cnt<nf&&firing())
    {
        /*
        for(int i=1; i<=np; i++)
        {
            //if(place[i])
            //{
                printf(" %d (%d)",i,place[i]);
            //}
        }
        cout<<endl;
        //*/
        cnt++;
    }
    if(nf==cnt)
    {
        return true;
    }
    else
    {
        nf=cnt;
        return false;
    }
}
int main()
{
    int cases=0;
    while(cin>>np&&np)
    {
        init();
        for(int i=1; i<=np; i++)
        {
            cin>>place[i];
        }
        cin>>nt;
        for(int i=1; i<=nt; i++)
        {
            int tmp;
            while(cin>>tmp && tmp)
            {
                if(tmp<0)
                {
                    tran[i].input[-tmp]++;
                }
                else
                    tran[i].output[tmp]++;
            }
        }
        cin>>nf;
        printf("Case %d: ",++cases);
        if(solve())
        {
            printf("still live after %d transitions",nf);
            cout<<endl;
        }
        else
        {
            printf("dead after %d transitions",nf);
            cout<<endl;
        }
        cout<<"Places with tokens:";
        for(int i=1; i<=np; i++)
        {
            if(place[i])
            {
                printf(" %d (%d)",i,place[i]);
            }
        }
        cout<<endl;
        cout<<endl;//third line
    }
    return 0;
}
