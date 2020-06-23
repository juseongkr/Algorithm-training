class Solution {
public:
	bool isIsomorphic(string s, string t) {
		int a[128], b[128];
		fill(a, a+128, -1);
		fill(b, b+128, -1);
		for (int i=0; i<s.length(); ++i) {
			if (a[s[i]] != b[t[i]])
				return false;
			a[s[i]] = b[t[i]] = i;
		}
		return true;
	}
};
