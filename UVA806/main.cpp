#include <bits/stdc++.h>

using namespace std;
/*
struct node
{
    int p;//white=0 black=1 gray=2
    node* ch[5];
    // 1 2
    // 3 4
};
*/
int image[100][100],b;
vector<int> seq;
int f_t(int f)
{
    int t=0,pow=1;
    string s;
    stringstream ss;
    ss<<f;
    ss>>s;
    for(auto c:s)
    {
        t+=((int)(c-'0')*pow);
        pow*=5;
    }
    return t;
}
int t_f(int t)
{
    int f=0;
    while(t)
    {
        f*=10;
        f+=(t%5);
        t/=5;
    }
    return f;
}
/*
node* newnode()
{
    node* root=new node;
    *root.p=0;
    for(int i=1; i<=4; i++)
        root->ch[i]=nullptr;
    return root;
}
*/
void tree(int l,int r,int u,int d,long long path)
{
    //node* root=newnode();
    //cout<<path<<endl;
    if(r<l || d<u) return;
    bool all_b=true,all_w=true;
    for(int i=u;i<=d;i++)
    {
        for(int j=l; j<=r ;j++)
            if(image[i][j])
            {
               all_w=false;
            }
            else
            {
                all_b=false;
            }
    }
    if(all_w)
    {
        //root->p=0;
        return;
    }
    else if(all_b)
    {
        //root->p=1;
        seq.push_back(f_t(path));
        b++;
        return ;
    }
    else
    {
        tree(l    , (r+l-1)/2, u    , (d+u-1)/2, path*10+1);
        tree((r+l-1)/2+1, r  , u    , (d+u-1)/2, path*10+2);
        tree(l    , (r+l-1)/2, (d+u-1)/2+1, d  , path*10+3);
        tree((r+l-1)/2+1, r  , (d+u-1)/2+1, d  , path*10+4);
        return;
    }
}
void solve1(int n)//images into root-to-leaf paths
{
    b=0;
    for(int i=1; i<=n; i++)
    {
        string s;
        cin>>s;
        for(int j=1; j<=n; j++)
        {
            image[i][j]=(int)(s[j-1]-'0');
        }
    }
    /*
        for(int i=1; i<=n ;i++)
    {
        for(int j=1; j<=n; j++)
            if(image[i][j])
                cout<<'*';
            else
                cout<<'.';
        cout<<endl;
    }
    //*/
    tree(1,n,1,n,0);
    sort(seq.begin(),seq.end());
    if(b)
    {
        for(int i=0; i<seq.size(); i++)
        {
            if((i-11)%12==0 || i==seq.size()-1)
            {
                cout<<seq[i]<<endl;
            }
            else
                cout<<seq[i]<<' ';
        }
    }
    cout<<"Total number of black nodes = "<<b<<endl;
}

void  solve2(int n)// root-to-leaf paths into images
{
    int in;
    seq.clear();
    while(cin>>in&&in!=-1)
        seq.push_back(in);
    memset(image,0,sizeof(image));
    if(!seq.empty())
    if(seq[0]==0)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
                image[i][j]=1;
        }
    }
    else
    {
        for(auto x:seq)
        {
            int path=t_f(x),l=1,r=n,u=1,d=n;
            string s;
            stringstream ss;
            ss<<path;
            ss>>s;
            //cout<<path<<endl;
            for(auto c:s)
            {
                if(c=='1')
                {
                    r=(r+l-1)/2;
                    d=(d+u-1)/2;
                }
                else if(c=='2')
                {
                    l=(r+l-1)/2+1;
                    d=(d+u-1)/2;
                }
                else if(c=='3')
                {
                    r=(r+l-1)/2;
                    u=(d+u-1)/2+1;
                }
                else if(c=='4')
                {
                    l=(r+l-1)/2+1;
                    u=(d+u-1)/2+1;
                }
            }
            for(int i=u; i<=d; i++)
            {
                for(int j=l; j<=r; j++)
                {
                    image[i][j]=1;
                }
            }
        }
    }
    for(int i=1; i<=n ;i++)
    {
        for(int j=1; j<=n; j++)
            if(image[i][j])
                cout<<'*';
            else
                cout<<'.';
        cout<<endl;
    }
}
int main()
{
    int n,cnt=0;
    while(cin>>n&&n)
    {
        seq.clear();
        if(cnt)
            cout<<endl;
        printf("Image %d\n",++cnt);
        if(n>0)
            solve1(n);
        else
            solve2(-n);

    }
    return 0;
}
