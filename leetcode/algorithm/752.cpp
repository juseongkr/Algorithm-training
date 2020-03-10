class Solution {
public:
	int openLock(vector<string>& deadends, string target) {
		if (target == "0000")
			return 0;

		unordered_set<string> visit;
		for (const auto i : deadends)
			visit.insert(i);

		if (visit.count("0000"))
			return -1;

		queue<pair<string, int>> que;
		visit.insert("0000");
		que.push({"0000", 0});

		while (!que.empty()) {
			auto [cur, step] = que.front();
			que.pop();

			if (cur == target)
				return step;

			for (int i=0; i<4; ++i) {
				for (int j=-1; j<=1; j+=2) {
					string p = cur;
					p[i] = ((p[i]-'0' + j + 10) % 10)+'0';

					if (!visit.count(p)) {
						visit.insert(p);
						que.push({p, step+1});
					}
				}
			}
		}
		return -1;
	}
};
