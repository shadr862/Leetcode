#include <bits/stdc++.h>
using namespace std;

int dp[2500][2500];
int solve(int i,int j,string &s1,string &s2)
{
    if(i>=s1.size()|| j>=s2.size())
    {
        return 0;
    }

    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }


    if(s1[i]==s2[j])
    {
        return dp[i][j]=1+solve(i+1,j+1,s1,s2);
    }

    int a=solve(i+1,j,s1,s2);
    int b=solve(i,j+1,s1,s2);

    return dp[i][j]=max(a,b);


}
int main() {
    memset(dp,0,sizeof(dp));
    string s1,s2;
    cin>>s1>>s2;

    for(int i=1;i<=s1.size();i++)
    {
        for(int j=1;j<=s2.size();j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    cout<<dp[s1.size()][s2.size()]<<endl;





    return 0;
}

//loveyou love
