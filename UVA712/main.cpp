#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,cnt=0;
    while(cin>>n&&n)
    {
        printf("S-Tree #%d:\n",++cnt);
        string s,tmp;
        for(int i=0; i<n; i++)
            cin>>s;
        cin>>s;
        int q;
        cin>>q;
        for(int i=0; i<q; i++)
        {
            int index=1;
            cin>>tmp;
            for(auto c:tmp)
                if(c=='1')
                    index=index*2+1;
                else
                    index*=2;
            cout<<s[index-(1<<n)];
        }
        cout<<endl;
        cout<<endl;
    }
    return 0;
}
