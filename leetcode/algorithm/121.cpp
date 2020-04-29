class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int ans = 0, low = 1e9+7;
		for (const auto p : prices) {
			if (low > p)
				low = min(low, p);
			else if (ans < p - low)
				ans = max(ans, p - low);
		}
		return ans;
	}
};
