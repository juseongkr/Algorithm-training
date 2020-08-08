class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> words, visit;
		for (int i=0; i<wordList.size(); ++i)
			words.insert(wordList[i]);

		queue<pair<string, int>> que;
		que.push({beginWord, 0});

		while (!que.empty()) {
			auto [cur, dep] = que.front();
			que.pop();

			if (cur == endWord)
				return dep + 1;

			for (int i=0; i<cur.size(); ++i) {
				string t = cur;
				for (int j='a'; j<='z'; ++j) {
					t[i] = j;
					if (!visit.count(t) && words.count(t)) {
						visit.insert(t);
						que.push({t, dep+1});
						words.erase(t);
					}
				}
			}
		}

		return 0;
	}
};
