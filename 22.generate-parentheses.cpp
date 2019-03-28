/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (53.48%)
 * Total Accepted:    308.8K
 * Total Submissions: 577.1K
 * Testcase Example:  '3'
 *
 * 
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * 
 * For example, given n = 3, a solution set is:
 * 
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string st="";
        vector<string> res;
        recGen(res,n,st,0,0); 
        return res;
    }
    void recGen(vector<string> &res,int n,string st,int o,int c){
        if(c > o || n < c || n < o){
            return;
        }
        if(c==n){
            res.emplace_back(st);
            return;
            }
        recGen(res,n,st+'(',o+1,c);
        recGen(res,n,st+')',o,c+1);
    }
};

// int main(){
//     Solution sol;
//     string st = "";
//     auto res = sol.generateParenthesis(3); 
//     for(string st:res){
//         cout << st << endl;
//     }
// }

