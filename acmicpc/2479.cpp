#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
#define MAX 1001

int n, k, u, v;
string b[MAX];
bool visit[MAX];
int pre[MAX];
vector<int> graph[MAX];

bool check(string x, string y)
{
	int cnt = 0;
	for (int i=0; i<k; ++i)
		if (x[i] != y[i])
			cnt++;
	return cnt == 1;
}

int main()
{
	cin >> n >> k;
	for (int i=0; i<n; ++i) {
		cin >> b[i];
		for (int j=0; j<i; ++j) {
			if (check(b[i], b[j])) {
				graph[i+1].push_back(j+1);
				graph[j+1].push_back(i+1);
			}
		}
	}
	cin >> u >> v;

	queue<int> que;
	que.push(u);
	visit[u] = 1;

	bool flag = false;
	while (!que.empty()) {
		int cur = que.front();
		que.pop();

		if (cur == v)
			flag = true;

		for (int i=0; i<graph[cur].size(); ++i) {
			int next = graph[cur][i];

			if (!visit[next]) {
				que.push(next);
				pre[next] = cur;
				visit[next] = 1;
			}
		}
	}

	if (flag) {
		stack<int> st;
		for (int i=v; i!=u; i=pre[i])
			st.push(i);
		st.push(u);
		while (!st.empty()) {
			cout << st.top() << " ";
			st.pop();
		}
	} else {
		cout << "-1\n";
	}

	return 0;
}
