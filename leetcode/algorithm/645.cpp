class Solution {
public:
	vector<int> findErrorNums(vector<int>& nums) {
		int no = -1, twice = -1;
		for (const auto v : nums) {
			if (nums[abs(v)-1] < 0)
				twice = abs(v);
			else
				nums[abs(v)-1] *= -1;            
		}

		for (int i=0; i<nums.size(); ++i)
			if (nums[i] > 0)
				no = i+1;

		vector<int> ret{twice, no};
		return ret;
	}
};
