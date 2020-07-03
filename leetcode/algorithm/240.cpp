class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int n = matrix.size();
		if (n == 0)
			return false;
		int m = matrix[0].size();
		if (m == 0)
			return false;

		int l = 0, r = m-1;
		while (l < n && r >= 0) {
			if (matrix[l][r] > target) {
				r--;
			} else if (matrix[l][r] < target) {
				l++;
			} else {
				return true;
			}
		}

		return false;
	}
};
