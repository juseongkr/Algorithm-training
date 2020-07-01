class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int n = matrix.size();
		if (n == 0)
			return false;
		int m = matrix[0].size();
		if (m == 0)
			return false;

		int l = 0, r = n-1;
		while (l <= r) {
			int mid = l+(r-l)/2;
			if (matrix[mid][0] <= target && target <= matrix[mid][m-1]) {
				return binary_search(matrix[mid].begin(), matrix[mid].end(), target);
			} else if (matrix[mid][0] > target) {
				r = mid-1;
			} else {
				l = mid+1;
			}
		}

		return false;
	}
};
