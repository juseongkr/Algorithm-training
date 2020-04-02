class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int ans = 0;
		for (const auto i : nums)
			ans ^= i;
		return ans;
	}
};
