#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
map<ll,int> w;
void bfs(string s,int dep)
{
    if(s[0]=='[')
    {
        int p=0;
        for(int i=1;i<=s.size()-1; i++)
        {
            if(s[i]=='[') p++;
            if(s[i]==']') p--;
            if(p==0 && s[i]==',')
            {
                //cout<<s.substr(1,i-1)<<endl;
                bfs(s.substr(1,i-1),dep+1);
                //cout<<s.substr(i+1,s.size()-i-2)<<endl;
                bfs(s.substr(i+1,s.size()-i-2),dep+1);
            }
        }
    }
    else
    {
        stringstream ss(s);
        ll n;
        ss>>n;
        w[n<<dep]++;
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        w.clear();
        string s;
        cin>>s;
        bfs(s,0);
        int sum=0;
        int maxn=-1;
        for(auto x:w)
        {
            sum+=x.second;
            maxn=max(maxn,x.second);
        }
        cout<<sum-maxn<<endl;
    }
    return 0;
}
