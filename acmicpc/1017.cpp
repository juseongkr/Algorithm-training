#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX_NUM 2002
#define MAX_NODE 51

vector<int> even, odd, ans, graph[MAX_NODE];
bool check[MAX_NUM], prime[MAX_NUM];
int A[MAX_NODE], B[MAX_NODE], visit[MAX_NODE];
int n, t, first;

bool dfs(int a)
{
	if (visit[a])
		return false;
	visit[a] = 1;
	for (int i=0; i<graph[a].size(); ++i) {
		int b = graph[a][i];
		if (B[b] == -1 || dfs(B[b])) {
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}

int main()
{
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> t;
		if (i == 0)
			first = t;
		if (t % 2 != 0)
			odd.push_back(t);
		else
			even.push_back(t);
	}

	if (even.size() != odd.size()) {
		cout << "-1\n";
		return 0;
	}
	
	if (first % 2 == 0)
		swap(odd, even);

	fill(check+2, check+MAX_NUM, true);
	for (int i=2; i<MAX_NUM; ++i) {
		if (check[i])
			prime[i] = true;
		for (int j=i; j<MAX_NUM; j+=i)
			check[j] = false;
	}

	for (int i=0; i<n/2; ++i)
		for (int j=0; j<n/2; ++j)
			if (prime[odd[i]+even[j]])
				graph[i].push_back(j);

	for (int i=0; i<graph[0].size(); ++i) {
		int next = graph[0][i];
		fill(A, A+MAX_NODE, -1);
		fill(B, B+MAX_NODE, -1);
		int cnt = 1;
		A[0] = next;
		B[next] = 0;
		for (int j=1; j<n/2; ++j) {
			fill(visit, visit+MAX_NODE, 0);
			visit[0] = 1;
			if (dfs(j))
				cnt++;
		}
		if (cnt == n/2)
			ans.push_back(even[next]);
	}

	if (!ans.empty()) {
		sort(ans.begin(), ans.end());
		for (int i=0; i<ans.size(); ++i)
			cout << ans[i] << " ";
	} else {
		cout << "-1\n";
	}

	return 0;
}
