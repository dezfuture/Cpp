// LEETCODE

/*
A peak element in a 2D grid is an element that is strictly greater than all of its 
adjacent neighbors to the left, right, top, and bottom.

Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, 
find any peak element mat[i][j] and return the length 2 array [i,j].

You may assume that the entire matrix is surrounded by an outer perimeter 
with the value -1 in each cell.

You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.
*/

class Solution
{
public:
    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        int low = 0, high = mat[0].size() - 1;

        while (low <= high)
        {
            int mid = (low + high) >> 1;
            int maxRow = 0;

            for (int i = 0; i < mat.size(); i++)
            {
                maxRow = mat[i][mid] >= mat[maxRow][mid] ? i : maxRow;
            }

            bool lefty = mid - 1 >= low && mat[maxRow][mid - 1] > mat[maxRow][mid];
            bool righty = mid + 1 <= high && mat[maxRow][mid + 1] > mat[maxRow][mid];

            if (!lefty && !righty)
            {
                return vector<int>{maxRow, mid};
            }
            else if (righty)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return vector<int>{-1, -1};
    }
};