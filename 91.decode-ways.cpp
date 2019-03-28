/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 *
 * https://leetcode.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (21.86%)
 * Total Accepted:    237.7K
 * Total Submissions: 1.1M
 * Testcase Example:  '"12"'
 *
 * A message containing letters from A-Z is being encoded to numbers using the
 * following mapping:
 * 
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 
 * 
 * Given a non-empty string containing only digits, determine the total number
 * of ways to decode it.
 * 
 * Example 1:
 * 
 * 
 * Input: "12"
 * Output: 2
 * Explanation: It could be decoded as "AB" (1 2) or "L" (12).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "226"
 * Output: 3
 * Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2
 * 6).
 * 
 */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDecodings(string st) { 
        int len = st.length();
        int s[len];
        int dp[len + 1];
        dp[0]=1;dp[1]=1; 
        for(int i=0;i<len;i++)
            s[i] = st.at(i)-'0';
        if(len == 0 or st[0] == '0')
            return 0;
        if(len == 1)
            return 1;
        int prev = s[0];
        for(int i=1;i<len;i++){
            if(s[i] == 0 && (s[i-1] > 2 || s[i-1] == 0) ){
                return 0;
            }
            else if(s[i] == 0 && s[i-1] <= 2){
                dp[i+1] = dp[i-1];
            }
            else if(s[i-1] == 1 ||(s[i-1] == 2 && s[i] <= 6)){
                dp[i+1] = dp[i] + dp[i-1];
            }
            else{
                dp[i+1] = dp[i];
            } 
        }
        return dp[len];
    }
};

// int main(){
//     Solution sol;
//     string s = "22012";
//     cout << sol.numDecodings(s);
// }

