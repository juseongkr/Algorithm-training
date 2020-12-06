class Solution {
public:
	vector<string> ans;
	unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;

	void dfs(string cur) {
		while (!graph[cur].empty()) {
			auto next = graph[cur].top();
			graph[cur].pop();

			dfs(next);
		}

		ans.push_back(cur);
	}

	vector<string> findItinerary(vector<vector<string>>& tickets) {
		for (const auto ticket : tickets) {
			string x = ticket[0];
			string y = ticket[1];
			graph[x].push(y);
		}

		dfs("JFK");

		reverse(ans.begin(), ans.end());

		return ans;
	}
};
