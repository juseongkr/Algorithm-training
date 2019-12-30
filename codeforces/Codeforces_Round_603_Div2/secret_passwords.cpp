#include <iostream>
#include <vector>
#include <map>
using namespace std;
#define MAX 200001

string s;
int n, ans;
bool visit[MAX];
vector<int> graph[MAX];
map<char, int> st;

void dfs(int u)
{
	visit[u] = 1;
	for (int i=0; i<graph[u].size(); ++i) {
		int next = graph[u][i];
		if (!visit[next])
			dfs(next);
	}
}

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> s;
		for (int j=0; j<s.length(); ++j) {
			if (st.count(s[j])) {
				int k = st[s[j]];
				graph[k].push_back(i);
				graph[i].push_back(k);
			}
			st[s[j]] = i;
		}
	}

	for (int i=0; i<n; ++i) {
		if (!visit[i]) {
			dfs(i);
			ans++;
		}
	}

	cout << ans << '\n';

	return 0;
}
