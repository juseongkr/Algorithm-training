class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		map<int, int> dict;

		for (int i=0; i<nums.size(); ++i) {
			int value = target - nums[i];
			if (dict.count(value))
				return {dict[value], i};
			dict[nums[i]] = i;
		}

		return {-1, -1};
	}
};
