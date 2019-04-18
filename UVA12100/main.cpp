#include <bits/stdc++.h>

using namespace std;

bool check(deque<int> &q)
{
    for(deque<int>::iterator it=q.begin(); it!=q.end(); it++)
    {
        if(*it>q.front())
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        deque<int> q;
        int n,m,time=0;
        cin>>n>>m;
        int len=n;
        for(int i=0; i<n; i++)
        {
            int tmp;
            cin>>tmp;
            q.push_back(tmp);
        }
        while(1)
        {
            if(check(q))
            {
                if(!m)
                {
                    cout<<++time<<endl;
                    break;
                }
                else
                {
                    time++;
                    q.pop_front();
                    m--;
                    len--;
                }
            }
            else if(!check(q))
            {
                if(!m)
                {
                    q.push_back(q.front());
                    q.pop_front();
                    m=len-1;
                }
                else
                {
                    q.push_back(q.front());
                    q.pop_front();
                    m--;
                }
            }
        }
    }
    return 0;
}
