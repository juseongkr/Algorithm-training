#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
#define MAX 2002

tuple<int, int, int> shark[MAX];
vector<int> graph[MAX];
int A[MAX], B[MAX], visit[MAX];
int n, a, b, c, cnt;

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
	 cin >> n;
	 for (int i=0; i<n; ++i) {
		 cin >> a >> b >> c;
		 shark[i] = {a, b, c};
	 }

	 for (int i=0; i<n; ++i) {
		 for (int j=i+1; j<n; ++j) {
			if (get<0>(shark[i]) >= get<0>(shark[j]) &&
			    get<1>(shark[i]) >= get<1>(shark[j]) &&
			    get<2>(shark[i]) >= get<2>(shark[j])) {
				graph[i+1000].push_back(j);
				graph[i].push_back(j);
			}

			else if (get<0>(shark[i]) <= get<0>(shark[j]) &&
			    get<1>(shark[i]) <= get<1>(shark[j]) &&
			    get<2>(shark[i]) <= get<2>(shark[j])) {
				graph[j+1000].push_back(i);
				graph[j].push_back(i);
			}
		 }
	 }

	 fill(A, A+MAX, -1);
	 fill(B, B+MAX, -1);
	 for (int i=0; i<MAX; ++i) {
		 fill(visit, visit+MAX, 0);
		 if (dfs(i))
			 cnt++;
	 }
	 cout << n - cnt << '\n';

	 return 0;
}
