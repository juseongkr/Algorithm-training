class Solution {
public:
	int characterReplacement(string s, int k) {
		int dict[257];
		int ans = 0, j = 0, cnt = 0;

		fill(dict, dict+257, 0);
		for (int i=0; i<s.length(); ++i) {
			cnt = max(cnt, ++dict[s[i]]);
			if (i-j+1-cnt > k)
				--dict[s[j++]];
			ans = max(ans, i-j+1);
		}

		return ans;
	}
};
