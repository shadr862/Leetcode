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
        }
    }

}

int main() {

    string s;
    cin>>s;
    longest_palindrome_substring(s);

    int n=s.size();
    vector<int> cuts(n,0);

    for(int i=0;i<n;i++)
    {
        cuts[i]=i;
        for(int j=0;j<=i;j++)
        {
            if(dp[j][i])
            {
                cuts[i]=min(cuts[i],j==0?0:cuts[j-1]+1);
            }
        }
    }

    cout<<"result:"<<cuts[n-1]<<endl;


    return 0;
}

/*
dsggsmadamafaffa

*/

