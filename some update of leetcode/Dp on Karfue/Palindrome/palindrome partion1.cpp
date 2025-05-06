#include <bits/stdc++.h>
using namespace std;


vector<vector<string>> ans;
bool palindrome(int l,int r,string s)
{
    while(l<r)
    {
        if(s[l]!=s[r])
        {
            return 0;
        }
        l++;
        r--;
    }

    return 1;
}

void solve(string s,int in,vector<string> v)
{
    if(in==s.size())
    {
        ans.push_back(v);
        return ;
    }

    for(int i=in;i<s.size();i++)
    {
        if(palindrome(in,i,s))
        {
            v.push_back(s.substr(in,i-in+1));
            solve(s,i+1,v);
            v.pop_back();
        }
    }
}

int main() {

    string s;
    cin>>s;
    vector<string> v;
    solve(s,0,v);

    for(auto x:ans)
    {
        for(auto y:x)
        {
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}

/*
dsggsmadamafaffa

*/

