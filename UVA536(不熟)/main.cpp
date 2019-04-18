#include <bits/stdc++.h>

using namespace std;
int rc[30],lc[30],n;
int in_order[30],pre_order[30];

int build(int L1, int R1, int L2, int R2)
{
    if(L1>R1) return -1;
    int root=pre_order[L2];
    int p=L1;
    while(in_order[p]!=root)
        p++;
    int Llen=p-L1;
    lc[root]=build(L1,p-1,L2+1,L2+Llen);
    rc[root]=build(p+1,R1,L2+Llen+1,R2);
    return root;
}
void dfs(int u)
{
    if(u==-1) return;
    dfs(lc[u]);
    dfs(rc[u]);
    cout<<(char)(u+'A');
}
int main()
{
    string s1,s2;
    while(cin>>s1>>s2)
    {
        n=s1.size();
        for(int i=0; i<n; i++)
            pre_order[i]=s1[i]-'A';
        for(int i=0; i<n; i++)
            in_order[i]=s2[i]-'A';
        int root=build(0,n-1,0,n-1);
        dfs(root);
        cout<<endl;
    }
    return 0;
}
