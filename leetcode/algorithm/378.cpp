class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		priority_queue<int> que;

		for (int i=0; i<matrix.size(); ++i) {
			for (int j=0; j<matrix[i].size(); ++j) {
				if (que.size() < k) {
					que.push(matrix[i][j]);
				} else {
					if (matrix[i][j] < que.top()) {
						que.pop();
						que.push(matrix[i][j]);
					}
				}
			}
		}

		return que.top();
	}
};
