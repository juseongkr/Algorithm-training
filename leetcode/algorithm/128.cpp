class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		set<int> st;
		for (int i=0; i<nums.size(); ++i)
			st.insert(nums[i]);

		int ans = 0, next = 0, len = 0;
		for (auto i : st) {
			if (!st.count(i-1)) {
				next = i;
				len = 1;
				while (st.count(next+1)) {
					next++;
					len++;
				}
			}
			ans = max(ans, len);
		}

		return ans;
	}
};
