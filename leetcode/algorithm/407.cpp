class Solution {
public:
	int N = 0, M = 0, ans = 0;
	const int dx[4] = {1, 0, -1, 0};
	const int dy[4] = {0, 1, 0, -1};
	typedef tuple<int, int, int> tp;
	vector<vector<bool>> visit;
	priority_queue<tp, vector<tp>, greater<tp>> que;

	void dfs(int x, int y, int z, vector<vector<int>> &heightMap) {
		visit[x][y] = 1;
		for (int i=0; i<4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M || visit[nx][ny])
				continue;

			visit[nx][ny] = 1;
			if (heightMap[nx][ny] > z) {
				que.push({heightMap[nx][ny], nx, ny});
			} else {
				dfs(nx, ny, z, heightMap);
				ans += (z - heightMap[nx][ny]);
			}       
		}
	}

	int trapRainWater(vector<vector<int>>& heightMap) {
		visit.resize(N+1, vector<bool>(M+1, 0));
		N = heightMap.size();
		M = heightMap[0].size();

		for (int i=0; i<N; ++i)
			for (int j=0; j<M; ++j)
				if (i == 0 || j == 0 || i == N-1 || j == M-1)
					que.push({heightMap[i][j], i, j});

		while (!que.empty()) {
			auto [z, x, y] = que.top();
			que.pop();
			dfs(x, y, z, heightMap);
		}

		return ans;
	}
};
