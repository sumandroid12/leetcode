/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (28.11%)
 * Total Accepted:    852.4K
 * Total Submissions: 3M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "abcabcbb"
 * Output: 3 
 * Explanation: The answer is "abc", with the length of 3. 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3. 
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 * 
 * 
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int map[256] ={0};
        if(s.empty())
            return 0;
        for(int &i:map)
            i=-1;
        int initmap[256];
        copy(begin(map),end(map),initmap);
        int max=0,max_till_here=0; 
        for(int i=0;i<s.length();i++){
            if(map[s[i]] >= 0){ 
                int repeat = map[s[i]];
                copy(begin(initmap),end(initmap),map);
                int n=repeat;
                while(++n <=i)
                    map[s[n]] = n;
                max_till_here = i-repeat;
            }
            else{ 
                map[s[i]] = i;
                max_till_here++;
            }
            max = max > max_till_here? max:max_till_here;
            
        } 
        return max;
    }
};
