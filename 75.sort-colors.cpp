/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 *
 * https://leetcode.com/problems/sort-colors/description/
 *
 * algorithms
 * Medium (41.52%)
 * Total Accepted:    298.2K
 * Total Submissions: 718.1K
 * Testcase Example:  '[2,0,2,1,1,0]'
 *
 * Given an array with n objects colored red, white or blue, sort them in-place
 * so that objects of the same color are adjacent, with the colors in the order
 * red, white and blue.
 * 
 * Here, we will use the integers 0, 1, and 2 to represent the color red,
 * white, and blue respectively.
 * 
 * Note: You are not suppose to use the library's sort function for this
 * problem.
 * 
 * Example:
 * 
 * 
 * Input: [2,0,2,1,1,0]
 * Output: [0,0,1,1,2,2]
 * 
 * Follow up:
 * 
 * 
 * A rather straight forward solution is a two-pass algorithm using counting
 * sort.
 * First, iterate the array counting number of 0's, 1's, and 2's, then
 * overwrite array with total number of 0's, then 1's and followed by 2's.
 * Could you come up with a one-pass algorithm using only constant space?
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) { 
        int r=0,w=0,b=0;
        for(int i=0;i<nums.size();i++){
            switch(nums[i]){
                case 0:
                    if(w){
                    nums[r] = 0; nums[w+r] = 1;
                    if(b){
                        nums[b+w+r] = 2;
                    }
                }
                else if(b){
                    nums[r]=0; nums[b+r]=2;
                }
                else{ nums[r]=0; }
                r++;
                break;
                    
                case 1:
                    if(b){
                    nums[b+r+w]=2; nums[w+r]=1; }
                    else{ nums[w+r]=1; }
                    w++; 
                    break;
                    
                case 2: 
                    nums[b+w+r]=2; b++; break;
            }
        }
    }
};

int main(){
    Solution sol;
    vector<int> col{2,0,2,1,1,0};
    sol.sortColors(col);
    for(auto x:col)
        cout << x << " ";

}
