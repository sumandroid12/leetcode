/*
 * @lc app=leetcode id=867 lang=cpp
 *
 * [867] Transpose Matrix
 *
 * https://leetcode.com/problems/transpose-matrix/description/
 *
 * algorithms
 * Easy (63.67%)
 * Total Accepted:    37.6K
 * Total Submissions: 59.1K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix A, return the transpose of A.
 * 
 * The transpose of a matrix is the matrix flipped over it's main diagonal,
 * switching the row and column indices of the matrix.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,2,3],[4,5,6],[7,8,9]]
 * Output: [[1,4,7],[2,5,8],[3,6,9]]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,2,3],[4,5,6]]
 * Output: [[1,4],[2,5],[3,6]]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 1000
 * 1 <= A[0].length <= 1000
 * 
 * 
 * 
 * 
 */
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int M = A.size();
        int N = A[0].size();
        vector<vector<int>> newMat(N,vector<int>(M)); 
        for(int i=0;i<N;++i){
            for(int j=0;j<M;++j){
                newMat[i][j] = A[j][i];
            }
        }
        return newMat;
    }
};
