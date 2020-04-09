class Solution {
public:
	string solve(string s) {
		string r;
		for (int i=0; i<s.length(); ++i) {
			if (s[i] == '#' && r.length())
				r.pop_back();
			else if (s[i] != '#')
				r.push_back(s[i]);
		}
		return r;
	}

	bool backspaceCompare(string S, string T) {
		return solve(S) == solve(T);
	}
};
