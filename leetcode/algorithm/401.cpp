class Solution {
public:
	vector<string> ans;
	vector<int> hour = {1, 2, 4, 8};
	vector<int> min = {1, 2, 4, 8, 16, 32};

	void solve(int cur, int h, int m, int cnt) {
		if (cnt == 0) {
			ans.push_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
			return;
		}

		for (int i=cur; i<10; ++i) {
			if (i < 4) {
				h += hour[i];
				if (h < 12) 
					solve(i+1, h, m, cnt-1);
				h -= hour[i];
			} else {
				m += min[i-4];
				if (m < 60)
					solve(i+1, h, m, cnt-1);
				m -= min[i-4];
			}
		}
	}

	vector<string> readBinaryWatch(int num) {
		solve(0, 0, 0, num);
		return ans;
	}
};
