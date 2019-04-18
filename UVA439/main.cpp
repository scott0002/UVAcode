#include <bits/stdc++.h>

using namespace std;

int plate[8][8];
int dx[]={2,1,2,1,-1,-1,-2,-2};
int dy[]={1,2,-1,-2,2,-2,1,-1};
struct pos
{
    int row,col;
};
int bfs(pos s,pos t)
{
    memset(plate,-1,sizeof(plate));
    queue<pos> q;
    while(!q.empty()) q.pop();
    plate[s.row][s.col]=0;
    q.push(s);
    while(!q.empty())
    {
        pos tmp=q.front(); q.pop();
        if(tmp.row==t.row && tmp.col==t.col) return plate[tmp.row][tmp.col];
        for(int i=0;i<8; i++)
        {
            if(tmp.row+dx[i]<8&&tmp.row+dx[i]>=0 && tmp.col+dy[i]<8&&tmp.col+dy[i]>=0)
            {
                plate[tmp.row+dx[i]][tmp.col+dy[i]]=plate[tmp.row][tmp.col]+1;
                q.push({tmp.row+dx[i],tmp.col+dy[i]});
            }

        }
    }
}
int main()
{
    char c1,c2;
    int n1,n2;
    while(cin>>c1>>n1>>c2>>n2)
    {
        printf("To get from %c%d to %c%d takes %d knight moves.\n"\
        ,c1,n1,c2,n2,bfs({(c1-'a'),n1-1},{(c2-'a'),n2-1}));
    }
    return 0;
}
