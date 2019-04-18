#include <bits/stdc++.h>

using namespace std;

int plate[25][25];
int dis[25][25][25];
int m,n,k;
int dx[]={1,0,0,-1};
int dy[]={0,-1,1,0};
struct pos
{
    int row,col,s;
};

void bfs()
{
    queue<pos> q;
    dis[0][0][0]=0;
    q.push({0,0,0});
    while(!q.empty())
    {
        pos tmp=q.front(); q.pop();
        for(int i=0; i<4; i++)
        {
            int x=tmp.row;
            int y=tmp.col;
            int s=tmp.s;
            int tx=x+dx[i];
            int ty=y+dy[i];
            int ts;
            if(tx>=m || tx<0 || ty>=n ||ty<0) continue;
            if(plate[tx][ty])
                ts=s+1;
            else
                ts=0;
            if(ts>k) continue;
            if(dis[tx][ty][ts]>dis[x][y][s]+1)
            {
                q.push({tx,ty,ts});
                dis[tx][ty][ts]=dis[x][y][s]+1;
            }
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(plate,-1,sizeof(plate));
        memset(dis,0x3f,sizeof(dis));
        cin>>m>>n;
        cin>>k;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>plate[i][j];
            }
        }
        bfs();
        int ans=0x3f3f3f3f;
        for(int i=0;i<=k;i++)
            ans=min(ans,dis[m-1][n-1][i]);
        if(ans==0x3f3f3f3f)
            cout<<-1<<endl;
        else
            cout<<ans<<endl;
        /*
        cout<<endl;
        for(int ii=0; ii<=k;ii++)
        {
            for(int i=0; i<m; i++)
            {
                for(int j=0; j<n; j++)
                {
                    printf("%13d",dis[i][j][ii]);
                }
                cout<<endl;
            }
            cout<<endl;
            cout<<endl;
        }*/
    }
    return 0;
}
