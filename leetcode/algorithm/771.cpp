class Solution {
public:
	int numJewelsInStones(string J, string S) {
		unordered_set<char> jewels;
        
		for (int i=0; i<J.length(); ++i)
			jewels.insert(J[i]);

		int ans = 0;
		for (int i=0; i<S.length(); ++i)
			if (jewels.count(S[i]))
				ans++;

		return ans;
	}
};
