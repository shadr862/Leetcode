#include <bits/stdc++.h>
using namespace std;
void LAS(vector<int>& v)
{
    int n=v.size();
    unordered_map<int,unordered_map<int,int>> dp;
    int ans=0;
    for(int i=1;i<n;i++)
    {
        for(int j=i-1;j>=0;j--)
        {
            int diff=v[i]-v[j];
            dp[i][diff]=dp[j].count(diff)?dp[j][diff]+1:2;
            ans=max(dp[i][diff],ans);
        }
    }

    cout<<ans<<endl;
}

void LAS_given_diff(vector<int>& v,int diff)
{
    int n=v.size();
    unordered_map<int,int> dp;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        dp[v[i]]=dp[v[i]-diff]+1;
        ans=max(ans,dp[v[i]]);
    }

    cout<<ans<<endl;
}

int main() {

    int n;
    cin>>n;

    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    LAS(v);
    LAS_given_diff(v,2);



    return 0;
}

/*
7
1 4 3 9 5 6 7

2
1 3

*/

