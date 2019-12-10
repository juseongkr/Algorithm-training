class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.length() != t.length())
			return false;

		int m[26];
		fill(m, m+26, 0);

		for (int i=0; i<s.length(); ++i) {
			m[s[i]-'a']++;
			m[t[i]-'a']--;
		}

		for (int i=0; i<26; ++i)
			if (m[i] != 0)
				return false;
		return true;
	}
};
