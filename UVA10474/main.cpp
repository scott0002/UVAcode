#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,q,cnt=1;
    while(cin>>n>>q&&(n||q))
    {
        printf("CASE# %d:\n",cnt++);
        int marble[n];
        for(int i=0; i<n; i++)
        {
            cin>>marble[i];
        }
        sort(marble,marble+n);
        for(int i=0; i<q; i++)
        {
            int x;
            cin>>x;
            int y=lower_bound(marble,marble+n,x)-marble;
            if(marble[y]==x)
                printf("%d found at %d",x,y+1);
            else
                printf("%d not found",x);
            cout<<endl;
        }
    }
    return 0;
}
