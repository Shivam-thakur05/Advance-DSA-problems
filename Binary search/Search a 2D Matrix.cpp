class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int firstRow = 0;
        int lastRow = row - 1;

        // Binary search to find the correct row
        while (firstRow <= lastRow) {
            int midRow = firstRow + (lastRow - firstRow) / 2;

            // If target is in this row
            if (matrix[midRow][0] <= target && target <= matrix[midRow][col - 1]) {
                // Perform binary search in the found row
                int startCol = 0;
                int endCol = col - 1;

                while (startCol <= endCol) {
                    int midCol = startCol + (endCol - startCol) / 2;
                    if (matrix[midRow][midCol] == target) return true;
                    else if (matrix[midRow][midCol] > target) endCol = midCol - 1;
                    else startCol = midCol + 1;
                }
                // Target not found in the current row
                return false;
            } 
            else if (matrix[midRow][0] > target) lastRow = midRow - 1;
            else firstRow = midRow + 1;
        }

        return false;
    }
};
