#include <bits/stdc++.h>

using namespace std;

struct book
{
    string name,author;
    bool operator<(const book &b)
    {
        if(author!=b.author) return author<b.author;
        else if(name!=b.name) return name<b.name;
        else return false;
    }
};
int main()
{
    string line;
    vector<int> next,pre;
    vector<bool> on;
    map<string,int> index;
    vector<book> books;
    books.push_back(book());
    while(getline(cin,line)&&line[0]!='E')
    {
        book newb;
        next.push_back(int());
        pre.push_back(int());
        on.push_back(bool());
        int rq=0;
        for(int i=1; i<line.size(); i++)
            if(line[i]=='\"')
                rq=i;
        newb.name=line.substr(1,rq-1);
        newb.author=line.substr(rq+5,line.size()-rq-6);
        //cout<<newb.name<<" "<<newb.author<<endl;
        books.push_back(newb);
    }
    sort(books.begin()+1,books.end());
    //for(int i=0; i<books.size(); i++)
        //cout<<i<<" "<< books[i].name<<" "<<books[i].author<<endl;
    for(int i=0; i<books.size(); i++)
    {
        next[i]=i+1;
        pre[i]=i-1;
        on[i]=true;
        index[books[i].name]=i;
        //cout<<books[i].name<<" "<<i<<endl;
    }
    while(getline(cin,line)&&line[0]!='E')
    {
        int lq,first=1;
        string qname;
        if(line[0]=='S')
        {
            for(int i=1;i<on.size(); i++)
                if(on[i])
                {
                    first=i;
                    break;
                }
            int cur=0;
            for(int i=0; i<books.size(); i++)
            {
                if(cur==i)
                {
                    cur=next[i];
                }
                else if(i<cur&&on[i])
                {
                    if(i==first)
                    {
                        printf("Put \"");
                        cout<<books[i].name;
                        printf("\" first");
                        cout<<endl;
                    }
                    else
                    {
                        printf("Put \"");
                        cout<<books[i].name;
                        printf("\" after \"");
                        cout<<books[pre[cur]].name;
                        printf("\"");
                        cout<<endl;
                    }

                    next[i]=cur;
                    pre[i]=pre[cur];
                    next[pre[i]]=i;
                    pre[next[i]]=i;
                }
            }
            cout<<"END"<<endl;
            continue;
        }
        for(int i=0; i<line.size()-1; i++)
            if(line[i]=='\"')
                lq=i;
        qname=line.substr(lq+1,line.size()-2-lq);
        //cout<<qname<<endl;
        int i=index[qname];
        //cout<<"i="<<i<<endl;
        if(line[0]=='B')
        {
            on[i]=false;
            next[pre[i]]=next[i];
            pre[next[i]]=pre[i];
            pre[i]=i;
            next[i]=i;
        }
        else if(line[0]=='R')
        {
            on[i]=true;
        }
    }
    return 0;
}
