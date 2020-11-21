class Solution {
public:
	int mx, far;
	vector<int> visit, path;
	vector<vector<int>> graph;

	void dfs(int cur, int prev, int dep) {
		if (visit[cur])
			return;
		visit[cur] = 1;

		if (mx < dep) {
			mx = dep;
			far = cur;
		}

		path[cur] = prev;
		for (int i=0; i<graph[cur].size(); ++i) {
			int next = graph[cur][i];
			dfs(next, cur, dep+1);
		}
	}

	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
		graph.resize(n+1);
		path.resize(n+1, 0);
		visit.resize(n+1, 0);

		for (const auto vec : edges) {
			int x = vec[0];
			int y = vec[1];
			graph[x].push_back(y);
			graph[y].push_back(x);
		}

		dfs(0, -1, 0);
		fill(visit.begin(), visit.end(), 0);
		mx = 0;
		dfs(far, -1, 0);

		vector<int> vec;
		for (int i=far; i!=-1; i=path[i])
			vec.push_back(i);

		int len = vec.size();
		if (len % 2)
			return {vec[len/2]};

		return {vec[len/2], vec[len/2-1]};
	}
};
