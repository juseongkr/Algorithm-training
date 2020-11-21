class Solution {
public:
	int maxProduct(vector<string>& words) {
		vector<int> dict(words.size()+1, 0);
		for (int i=0; i<words.size(); ++i)
			for (int j=0; j<words[i].length(); ++j)
				dict[i] |= (1 << (words[i][j]-'a'));

		int ans = 0;
		for (int i=0; i<words.size(); ++i)
			for (int j=i+1; j<words.size(); ++j)
				if ((dict[i] & dict[j]) == 0)
					ans = max(ans, (int)(words[i].length() * words[j].length()));

		return ans;
	}
};
