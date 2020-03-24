class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		vector<string> ret;
		if (nums.size() == 0)
			return ret;

		int idx = 0;
		for (int i=1; i<nums.size(); ++i) {
			if (nums[i] != nums[i-1]+1) {
				if (nums[idx] == nums[i-1])
					ret.push_back(to_string(nums[idx]));
				else
					ret.push_back(to_string(nums[idx]) + "->" + to_string(nums[i-1]));
				idx = i;
			}
		}

		if (nums[idx] == nums[nums.size()-1])
			ret.push_back(to_string(nums[idx]));
		else
			ret.push_back(to_string(nums[idx]) + "->" + to_string(nums[nums.size()-1]));

		return ret;
	}
};
