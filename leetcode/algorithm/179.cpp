class Solution {
public:
	string largestNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end(), [](int x, int y) {
			return to_string(x) + to_string(y) > to_string(y) + to_string(x);
		});

		string ret;
		for (const auto s : nums)
			ret += to_string(s);

		while (ret.length() && ret[0] == '0')
			ret.erase(0);

		return ret.length() == 0 ? "0" : ret;
	}
};
