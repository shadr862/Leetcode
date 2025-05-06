#include <bits/stdc++.h>
using namespace std;

int dp[1000][2500];
int solve(int i,vector<int> &v,int target)
{
    if(i>=v.size()|| target<=0)
    {
        return target==0?1:0;
    }

    if(dp[i][target]!=-1)
    {
        return dp[i][target];
    }


    int ans=0;

    if(target>=v[i])
    {
        ans|=solve(i+1,v,target-v[i]);
    }

    ans|=solve(i+1,v,target);

    return dp[i][target]=ans;


}

void partition1(vector<int>& v,int sum)
{
    memset(dp,-1,sizeof(dp));
    if(solve(0,v,sum))
    {
        cout<<"posssible"<<endl;
        return ;
    }

    cout<<"not possible"<<endl;
}

void partition2(vector<int>& v,int sum)
{
    memset(dp,0,sizeof(dp));
    int n=v.size();

    for(int i=0;i<=n;i++)
    {
        dp[i][0]=1;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(j>=v[i-1])
            {
                dp[i][j]|=dp[i-1][j-v[i-1]];
            }
        }
    }
    if(dp[n][sum])
    {
        cout<<"posssible"<<endl;
        return ;
    }

    cout<<"not possible"<<endl;
}
int main() {

    int n,sum=0;
    cin>>n;

    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        sum+=v[i];
    }
    if(sum%2==1)
    {
        cout<<"not possible"<<endl;
    }
    sum=sum/2;

    partition2(v,sum);







    return 0;
}

/*
7
1 2 3 3 5 7 9

2
1 3

*/

