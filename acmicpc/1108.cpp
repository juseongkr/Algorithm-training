#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
using namespace std;
#define MAX 2600

map<string, int> dict;
stack<int> st;
vector<int> graph[MAX], group_graph[MAX];
vector<vector<int>> vec;
long long value[MAX];
int visit[MAX], finish[MAX], order[MAX];
int group[MAX], in[MAX];
int n, m, node, cnt, label;
string to, from, ans;

int scc(int n)
{
	visit[n] = ++cnt;
	st.push(n);

	int ret = visit[n];
	for (int i=0; i<graph[n].size(); ++i) {
		int next = graph[n][i];
		if (!visit[next])
			ret = min(ret, scc(next));
		else if (!finish[next])
			ret = min(ret, visit[next]);
	}

	if (ret == visit[n]) {
		vector<int> temp;
		while (1) {
			int t = st.top();
			st.pop();
			finish[t] = 1;
			group[t] = label;
			temp.push_back(t);
			if (n == t)
				break;
		}
		label++;
		vec.push_back(temp);
	}
	return ret;
}

int to_num(string s)
{
	if (dict.count(s))
		return dict[s];
	else
		dict.insert({s, node});

	return node++;
}

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> to >> m;
		int b = to_num(to);
		for (int j=0; j<m; ++j) {
			cin >> from;
			int a = to_num(from);
			graph[a].push_back(b);
		}
	}
	cin >> ans;

	fill(value, value+node, 1LL);
	for (int i=0; i<node; ++i)
		if (!visit[i])
			scc(i);

	for (int i=0; i<node; ++i) {
		int cur = group[i];
		for (int j=0; j<graph[i].size(); ++j) {
			int next = group[graph[i][j]];
			if (cur != next) {
				group_graph[cur].push_back(next);
				in[next]++;
			}
		}
	}

	queue<int> que;
	for (int i=0; i<label; ++i)
		if (!in[i])
			que.push(i);

	for (int i=0; i<label; ++i) {
		int cur = que.front();
		order[i] = cur;
		que.pop();
		for (int j=0; j<group_graph[cur].size(); ++j) {
			int next = group_graph[cur][j];
			if (--in[next] == 0)
				que.push(next);
		}
	}

	for(int k=0; k<label; k++) {
		for (int i=0; i<vec[order[k]].size(); ++i) {
			int cur = vec[order[k]][i];
			for (int j=0; j<graph[cur].size(); ++j) {
				int next = graph[cur][j];
				if(group[cur] != group[next])
					value[next] += value[cur];
			}
		}
	}

	if (dict.count(ans))
		cout << value[dict[ans]] << '\n';
	else
		cout << "1\n";

	return 0;
}
