class NumMatrix {
public:
	vector<vector<int>> psum;
	NumMatrix(vector<vector<int>>& matrix) {
		int n = matrix.size();
		if (n == 0)
			return;
		int m = matrix[0].size();
		psum.resize(n+1);
		for (int i=0; i<n+1; ++i)
			psum[i].resize(m+1, 0);

		for (int i=0; i<n; ++i)
			for (int j=0; j<m; ++j)
				psum[i+1][j+1] = psum[i+1][j] + psum[i][j+1] - psum[i][j] + matrix[i][j];
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		return psum[row2+1][col2+1] + psum[row1][col1] - psum[row1][col2+1] - psum[row2+1][col1];
	}
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
