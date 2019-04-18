#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    string line;
    stack<char> s;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        while(!s.empty()) s.pop();
        bool flag=false;
        getline(cin,line);
        for(auto c:line)
        {
            if(c=='(' || c=='[')
                s.push(c);
            else if(c==')')
            {
                if(s.empty() || s.top()!='(')
                {
                    cout<<"No"<<endl;
                    flag=true;
                    break;
                }
                else
                    s.pop();
            }
            else if(c==']')
            {
                if(s.empty() || s.top()!='[')
                {
                    cout<<"No"<<endl;
                    flag=true;
                    break;
                }
                else
                    s.pop();
            }
        }
        if(!flag)
            if(s.empty())
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
    }
    //system("pause");
    return 0;
}
