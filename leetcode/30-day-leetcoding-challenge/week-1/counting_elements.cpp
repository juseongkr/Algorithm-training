class Solution {
public:
	int countElements(vector<int>& arr) {
		map<int, int> mp;
		for (const auto i : arr)
			mp[i]++;

		int ans = 0;
		for (const auto i : mp)
			if (mp.count(i.first+1))
				ans += i.second;
		return ans;
	}
};
