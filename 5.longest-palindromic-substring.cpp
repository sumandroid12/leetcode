/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (26.83%)
 * Total Accepted:    504.9K
 * Total Submissions: 1.9M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * 
 * 
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "cbbd"
 * Output: "bb"
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) { 
        string strev = s;
        reverse(strev.begin(),strev.end());
        return maxSubstring(s,strev); 
    }
    string maxSubstring(string s1,string s2){
        int m=s1.length();
        int n=s2.length();
        int dp[m+1][n+1];
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(s1[i-1]==s2[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=0; 
            }
        }
        int len=-1,send=-1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){ 
                if(dp[i][j]>len){
                    len = dp[i][j]; 
                    send = i; 
                } 
            }
        } 
        return s1.substr(send-len,len);
    }
};

int main(){
    Solution sol;
    string test="cbbd";
    cout << sol.longestPalindrome(test) << endl;
    return 0;
}
