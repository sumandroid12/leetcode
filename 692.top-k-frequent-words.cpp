/*
 * @lc app=leetcode id=692 lang=cpp
 *
 * [692] Top K Frequent Words
 *
 * https://leetcode.com/problems/top-k-frequent-words/description/
 *
 * algorithms
 * Medium (44.99%)
 * Total Accepted:    54.6K
 * Total Submissions: 121.4K
 * Testcase Example:  '["i", "love", "leetcode", "i", "love", "coding"]\n2'
 *
 * Given a non-empty list of words, return the k most frequent elements.
 * Your answer should be sorted by frequency from highest to lowest. If two
 * words have the same frequency, then the word with the lower alphabetical
 * order comes first.
 * 
 * Example 1:
 * 
 * Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
 * Output: ["i", "love"]
 * Explanation: "i" and "love" are the two most frequent words.
 * ⁠   Note that "i" comes before "love" due to a lower alphabetical order.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is",
 * "is"], k = 4
 * Output: ["the", "is", "sunny", "day"]
 * Explanation: "the", "is", "sunny" and "day" are the four most frequent
 * words,
 * ⁠   with the number of occurrence being 4, 3, 2 and 1 respectively.
 * 
 * 
 * 
 * Note:
 * 
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Input words contain only lowercase letters.
 * 
 * 
 * 
 * Follow up:
 * 
 * Try to solve it in O(n log k) time and O(n) extra space.
 * 
 * 
 */
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) { 
        vector<string> res;
        unordered_map<string,int> table;
        for(string w:words)
            table[w]++; 
        // for(auto p:table)
        //     cout << p.first << "" << p.second << endl;
        auto cmp = [](pair<string,int> old,pair<string,int> curr) {
                if(old.second == curr.second)
                    return old.first < curr.first;
                return (old.second) > (curr.second);
             };
        priority_queue<pair<string,int>,vector<pair<string,int>>,decltype(cmp)> h(cmp);
        for(auto x:table){
            if(h.size() < k){
                h.push(x);
            }
            else if(h.top().second <= x.second){ 
                if(h.top().second < x.second){
                    h.pop();
                    h.push(x); 
                }
                else if(h.top().first > x.first){ 
                    h.pop();
                    h.push(x); 
                }
            }
        }
        for(int i=0;i<k;i++){
            res.emplace_back(h.top().first);
            h.pop(); 
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

// int main(){
//     Solution sol;
//     vector<string> words{"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
//     // vector<string> words{"i", "love", "leetcode", "i", "love", "coding"};
//     auto res = sol.topKFrequent(words,4);
//     for(auto x:res)
//         cout << x << endl;
// }
