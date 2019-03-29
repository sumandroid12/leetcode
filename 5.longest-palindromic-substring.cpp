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
        pair<int,int> res;
        if(s.empty() || s.length()==1)
            return s;
        int n=s.length();
        for(int i=0;i<n-1;i++){
            auto o = expand_around(s,i,i);
            auto e = expand_around(s,i,i+1);
            auto curr = o.second > e.second ? o:e; 
            res = curr.second > res.second ? curr:res;
        }
        return s.substr(res.first,res.second);
        
    }
    pair<int,int> expand_around(string &s,int l, int r){
        int n = s.length();
        while(l >=0 && r <n){
            if(s[l]!=s[r])
                break;
            l--;r++; 
        }
        l++;r--;
        if(s[l]==s[r])
            return pair<int,int>(l,r-l+1);
        else
            return pair<int,int>(l,0);
    }
};

// int main(){
//     Solution sol;
//     string s = "a";
//     cout << sol.longestPalindrome(s) << endl;
// }
