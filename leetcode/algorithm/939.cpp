class Solution {
public:
	int minAreaRect(vector<vector<int>>& points) {
		int ans = 1e9+7;
		set<pair<int, int>> st;

		for (const auto i : points)
			st.insert({i[0], i[1]});

		for (int i=0; i<points.size(); ++i) {
			for (int j=i+1; j<points.size(); ++j) {
				if (points[i][0] != points[j][0] && points[i][1] != points[j][1]) {

					pair<int, int> x = {points[i][0], points[j][1]};
					pair<int, int> y = {points[j][0], points[i][1]};

					if (st.count(x) && st.count(y)) {
						int area = abs(points[i][0] - points[j][0]) * abs(points[i][1] - points[j][1]);
						ans = min(ans, area);
					}
				}
			}
		}
		return ans == 1e9+7 ? 0 : ans;
	}
};
