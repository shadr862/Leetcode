#include <bits/stdc++.h>
using namespace std;

int dp[2500][2500];
int solve(int i,int j,vector<int>& nums)
{
    if(i>=nums.size())
    {
        return 0;
    }

    if(dp[i][j+1]!=-1)
    {
        return dp[i][j+1];
    }
    int ans,ans1;
    if(nums[i]>nums[j]|| j==-1)
    {
        ans=1+solve(i+1,i,nums);
    }

    ans1=0+solve(i+1,j,nums);

    return dp[i][j+1]=max(ans,ans1);


}
int main() {
    //memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    vector<int> v(n),Dp(n,1),cnt(n,1),pre(n,-1);

    for(int i=0;i<n;i++)
    {
       cin>>v[i];
    }
    int ans=0;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(v[i]>v[j] && Dp[i]<Dp[j]+1)
            {
                Dp[i]=Dp[j]+1;
                cnt[i]=cnt[j];
                pre[i]=j;
            }
            else if(Dp[i]==Dp[j]+1)
            {
                cnt[i]+=cnt[j];
            }
        }
        ans=max(ans,Dp[i]);
    }

    int c=0,ind=-1;
    for(int i=0;i<n;i++)
    {
        if(ans==Dp[i])
        {
            ind=i;
            c+=cnt[i];
        }
    }

    while(ind!=-1)
    {
        cout<<v[ind]<<" ";
        ind=pre[ind];
    }
    cout<<endl;

    cout<<"max len: "<<ans<<"  num of way: "<<c<<endl;


    return 0;
}

//1 5 3 2 7 6 9 11
