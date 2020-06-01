class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> ret;

		sort(nums.begin(), nums.end());
		do {
			vector<int> vec;
			for (const auto i : nums)
				vec.push_back(i);
			ret.push_back(vec);
		} while (next_permutation(nums.begin(), nums.end()));

		return ret;
	}
};
