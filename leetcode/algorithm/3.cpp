class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		set<char> st;
		int l = 0, r = 0, ans = 0;

		while (l < s.length() && r < s.length()) {
			if (st.count(s[r])) {
				st.erase(s[l]);
				l++;
			} else {
				st.insert(s[r]);
				ans = max(ans, r-l+1);
				r++;
			}
		}
		return ans;
	}
};
