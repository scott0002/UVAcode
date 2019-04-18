#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<vector<string> > text;
    string s;
    int word_max[200];
    memset(word_max,0,sizeof(word_max));
    int line_i=0;
    while(getline(cin,s))
    {
        text.push_back(vector<string>());
        stringstream ss(s);
        string tmp;
        int word_i=0;
        while(ss>>tmp)
        {
            text[line_i].push_back(tmp);
            word_max[word_i]=max(word_max[word_i],(int)tmp.size());
            word_i++;
        }
        line_i++;
    }
    int locate=-1;
    for(int i=0; i<text.size(); i++)
    {
        for(int j=0; j<text[i].size(); j++)
        {
            cout<<text[i][j];
            if(j!=text[i].size()-1)
                for(int k=0; k<=(locate+word_max[j]+1-text[i][j].size()); k++)
                    cout<<' ';
        }
        cout<<endl;
    }
    return 0;
}
