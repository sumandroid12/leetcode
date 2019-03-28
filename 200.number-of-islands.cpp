/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (40.67%)
 * Total Accepted:    318.8K
 * Total Submissions: 783.8K
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of
 * islands. An island is surrounded by water and is formed by connecting
 * adjacent lands horizontally or vertically. You may assume all four edges of
 * the grid are all surrounded by water.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * 11110
 * 11010
 * 11000
 * 00000
 * 
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * 11000
 * 11000
 * 00100
 * 00011
 * 
 * Output: 3
 * 
 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int m,n;
    int numIslands(vector<vector<char>>& grid) { 
        if(grid.size()==0)
            return 0;
        m=grid.size();
        n=grid[0].size();
        vector<vector<int>> isl(m,vector<int>(n,0));
        int numIslands = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1'){
                    numIslands++;
                    call_dfs(grid,i,j);
                }
            }
        }
        return numIslands;
    }
    void call_dfs(vector<vector<char>> &grid,int i,int j){ 
        queue<pair<int,int>> q;
        pair<int,int> root(i,j);
        q.emplace(root);
        while(!q.empty()){
            auto p = q.front();
            grid[p.first][p.second]='2';
            //take left
            if(p.first-1>=0 && grid[p.first-1][p.second] == '1'){
                q.emplace(pair<int,int>(p.first-1,p.second)); 
                grid[p.first-1][p.second]='2';
            }
            //take up
            if(p.second-1>=0 && grid[p.first][p.second-1] == '1'){
                q.emplace(pair<int,int>(p.first,p.second-1)); 
                grid[p.first][p.second-1]='2';
            }
            //take right 
            if(p.first+1<m && grid[p.first+1][p.second] == '1'){
                q.emplace(pair<int,int>(p.first+1,p.second)); 
                grid[p.first+1][p.second]='2';
            }
            //take down
            if(p.second+1<n && grid[p.first][p.second+1] == '1'){
                q.emplace(pair<int,int>(p.first,p.second+1)); 
                grid[p.first][p.second+1]='2';
            }
            q.pop();
        }
    }
};

int main(){
    Solution sol;
    vector<vector<char>> grid{{'1','1','0','0','0'},
    {'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}};
    cout << sol.numIslands(grid) << endl; 
}