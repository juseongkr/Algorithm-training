class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		if (nums.size() == 0)
			return {};

		int x = 0, y = 0, xCnt = 0, yCnt = 0;
		for (const auto num: nums) {
			if (num == x) {
				xCnt++;
			} else if (num == y) {
				yCnt++;
			} else if (xCnt == 0) {
				xCnt = 1;
				x = num;
			} else if (yCnt == 0) {
				yCnt = 1;
				y = num;
			} else {
				xCnt--;
				yCnt--;
			}
		}

		xCnt = 0, yCnt = 0;
		for (const auto num: nums) {
			if (num == x)
				xCnt++;
			else if (num == y)
				yCnt++;
		}

		vector<int> ans;
		if (nums.size() / 3 < xCnt)
			ans.push_back(x);
		if (nums.size() / 3 < yCnt)
			ans.push_back(y);

		return ans;
	}
};
