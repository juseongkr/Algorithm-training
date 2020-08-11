class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		vector<vector<int>> graph(numCourses);
		vector<int> in(numCourses, 0);
		vector<bool> visit(numCourses, false);
		queue<int> que;

		for (auto i : prerequisites) {
			graph[i[0]].push_back(i[1]);
			in[i[1]]++;
		}

		for (int i=0; i<numCourses; ++i)
			if (!in[i])
				que.push(i);

		while (!que.empty()) {
			int cur = que.front();
			que.pop();

			if (visit[cur])
				continue;
			visit[cur] = 1;

			for (int i=0; i<graph[cur].size(); ++i) {
				int next = graph[cur][i];
				if (--in[next] == 0)
					que.push(next);
			}
		}

		for (int i=0; i<numCourses; ++i)
			if (!visit[i])
				return false;

		return true;
	}
};
