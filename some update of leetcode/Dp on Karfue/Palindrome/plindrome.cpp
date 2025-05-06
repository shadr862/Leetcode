#include <bits/stdc++.h>
using namespace std;
int dp[2500][2500];
void longest_palindrome_substring(string s)
{
    int n=s.size();
    string ans;
    for(int len=1;len<=n;len++)
    {
        for(int j=0;j<(n-len+1);j++)
        {
            if(len==1)
            {
                dp[j][j]=1;
            }
            else if(len==2)
            {
                dp[j][j+1]=(s[j]==s[j+1])?1:0;
            }
            else if(s[j]==s[j+len-1] && dp[j+1][j+len-2]>0)
            {
                dp[j][j+len-1]=1;
            }

            if(dp[j][j+len-1])
            {
                ans=s.substr(j,len);
            }
        }
    }

    cout<<ans<<endl;

}

int longest_palindrome_subsequence(int i,int j,string &s)
{
    if(i>=j)
    {
        return i==j?1:0;
    }

    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }

    if(s[i]==s[j])
    {
        return dp[i][j]=2+longest_palindrome_subsequence(i+1,j-1,s);
    }

    return dp[i][j]=max(longest_palindrome_subsequence(i+1,j,s),longest_palindrome_subsequence(i,j-1,s));
}
int main() {

    string s;
    cin>>s;

    //longest_palindrome_substring(s);
    memset(dp,-1,sizeof(dp));
    cout<<longest_palindrome_subsequence(0,s.size()-1,s)<<endl;


    return 0;
}

/*
dsggsmadamafaffa

*/

