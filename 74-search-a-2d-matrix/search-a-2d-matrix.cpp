class Solution {
public:

    // Binary search inside a particular row
    bool searchInRow(vector<vector<int>>& mat, int target, int row) {
        int n = mat[0].size();

        int st = 0;
        int end = n - 1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (target == mat[row][mid]) {
                return true;
            }
            else if (target > mat[row][mid]) {
                st = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>>& mat, int target) {

        int m = mat.size();
        int n = mat[0].size();

        // Binary search on rows
        int startRow = 0;
        int endRow = m - 1;

        while (startRow <= endRow) {

            int midRow = startRow + (endRow - startRow) / 2;

            // Target can exist in this row
            if (target >= mat[midRow][0] &&
                target <= mat[midRow][n - 1]) {

                return searchInRow(mat, target, midRow);
            }

            // Target is greater than the largest element
            // of this row, so go down
            else if (target > mat[midRow][n - 1]) {
                startRow = midRow + 1;
            }

            // Target is smaller than the first element
            // of this row, so go up
            else {
                endRow = midRow - 1;
            }
        }

        return false;
    }
};