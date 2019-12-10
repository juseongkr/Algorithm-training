class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		vector<pair<long long, long long>> vec;

		for (int i=0; i<nums.size(); ++i)
			vec.push_back({nums[i], i});

		sort(vec.begin(), vec.end());

		for (int i=0; i<vec.size(); ++i) {
			for (int j=i+1; j<vec.size(); ++j) {
				if (vec[i].first + t >= vec[j].first) {
					if (abs(vec[i].second - vec[j].second) <= k)
						return true;
				} else {
					break;
				}
			}
		}
		return false;
	}
};
