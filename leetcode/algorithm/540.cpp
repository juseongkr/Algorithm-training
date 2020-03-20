class Solution {
public:
	vector<int> vec;
	bool check(int mid) {
		if (mid % 2 == 0) {
			if (mid > 0 && vec[mid] == vec[mid-1])
				return true;
		} else {
			if (mid < vec.size()-1 && vec[mid] == vec[mid+1])
				return true;
		}
		return false;
	}

	int singleNonDuplicate(vector<int>& nums) {
		vec = nums;
		int l = 0, r = nums.size()-1;
		while (l <= r) {
			int mid = (l+r)/2;
			if (check(mid))
				r = mid-1;
			else
				l = mid+1;
		}
		return nums[r];
	}
};
