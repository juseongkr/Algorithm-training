#include <iostream>
#include <vector>
using namespace std;
#define MAX 100001

int n, m, k, x, y;
int in[MAX], cur[MAX], possible[MAX];
vector<int> graph[MAX];

void cmd(int x, bool flag)
{
	for (int i=0; i<graph[x].size(); ++i) {
		int next = graph[x][i];
		possible[next] = flag ? possible[next]+1 : possible[next]-1;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i=0; i<m; ++i) {
		cin >> x >> y;
		graph[x].push_back(y);
		in[y]++;
	}

	bool flag = true;
	for (int i=0; i<k; ++i) {
		cin >> x >> y;
		if (x == 1) {
			if (possible[y] < in[y]) {
				flag = false;
			} else {
				if (cur[y]++ == 0)
					cmd(y, 1);
			}
		} else {
			if (cur[y] == 0) {
				flag = false;
			} else {
				if (--cur[y] == 0)
					cmd(y, 0);
			}
		}
	}

	if (flag)
		cout << "King-God-Emperor\n";
	else
		cout << "Lier!\n";

	return 0;
}
