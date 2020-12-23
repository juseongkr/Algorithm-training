class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end());
		vector<vector<int>> ans;
		vector<int> cur = intervals[0];

		for (int i=1; i<intervals.size(); ++i) {
			int x = intervals[i][0];
			int y = intervals[i][1];

			if (x <= cur[1]) {
				cur[1] = max(cur[1], y);
			} else {
				ans.push_back(cur);
				cur = intervals[i];
			}
		}
		ans.push_back(cur);

		return ans;
	}
};
