// Leetcode 54

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int elements = n * m;
        int total = 0;
        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = m - 1;
        vector<int> ans;
        while (left <= right && top <= bottom && total < elements)
        {
            for (int j = left; j <= right && total < elements; j++)
            {
                ans.push_back(matrix[top][j]);
                total++;
            }

            top++;
            for (int i = top; i <= bottom && total < elements; i++)
            {
                ans.push_back(matrix[i][right]);
                total++;
            }
            right--;
            for (int j = right; j >= left && total < elements; j--)
            {
                ans.push_back(matrix[bottom][j]);
                total++;
            }
            bottom--;
            for (int i = bottom; i >= top && total < elements; i--)
            {
                ans.push_back(matrix[i][left]);
                total++;
            }
            left++;
        }
        return ans;
    }
};