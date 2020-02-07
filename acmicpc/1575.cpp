#include <iostream>
#include <vector>
using namespace std;
#define MAX 101

int k, n, a, b, p, NODE;
vector<int> graph[MAX], must;
int A[MAX], B[MAX*MAX], visit[MAX];

bool dfs(int a)
{
	visit[a] = 1;
	for (int i=0; i<graph[a].size(); ++i) {
		int b = graph[a][i];
		if (B[b] == -1 || (!visit[B[b]] && dfs(B[b]))) {
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}

int main()
{
	cin >> k;
	for (int i=0; i<k; ++i) {
		cin >> p;
		must.push_back(p-1);
	}

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> a >> b;
		for (int j=0; j<b; ++j) {
			cin >> p;
			for (int k=0; k<a; ++k)
				graph[p-1].push_back(NODE+k);
		}
		NODE += a;
	}

	int ret = 0;
	fill(A, A+MAX, -1);
	fill(B, B+MAX*MAX, -1);
	for (int i=0; i<k; ++i) {
		fill(visit, visit+MAX, 0);
		if (dfs(must[i]))
			ret++;
	}

	vector<int> vec;
	for (int i=0; i<MAX; ++i) {
		if (A[i] == -1) {
			fill(visit, visit+MAX, 0);
			if (dfs(i)) {
				ret++;
				vec.push_back(i);
			}
		}
	}

	if (ret >= NODE) {
		cout << vec.size() << '\n';
		for (int i=0; i<vec.size(); ++i)
			cout << vec[i]+1 << " ";
	} else {
		cout << "-1\n";
	}

	return 0;
}
