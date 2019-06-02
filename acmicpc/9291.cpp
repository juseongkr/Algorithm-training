#include <iostream>
using namespace std;
#define MAX 9

int board[MAX][MAX], visit[MAX];
const int x[MAX] = {0, 0, 0, 3, 3, 3, 6, 6, 6};
const int y[MAX] = {0, 3, 6, 0, 3, 6, 0, 3, 6};

bool check()
{
	for (int i=0; i<9; ++i) {
		fill(visit, visit+10, 0);
		for (int j=0; j<9; ++j) {
			if (visit[board[i][j]])
				return false;
			visit[board[i][j]] = 1;
		}

		fill(visit, visit+10, 0);
		for (int j=0; j<9; ++j) {
			if (visit[board[j][i]])
				return false;
			visit[board[j][i]] = 1;
		}
	}

	for (int k=0; k<9; ++k) {
		fill(visit, visit+10, 0);
		for (int i=x[k]; i<x[k]+3; ++i) {
			for (int j=y[k]; j<y[k]+3; ++j) {
				if (visit[board[i][j]])
					return false;
				visit[board[i][j]] = 1;
			}
		}
	}
	return true;
}

int main()
{
	int n;

	cin >> n;
	for (int t=0; t<n; ++t) {
		for (int i=0; i<9; ++i)
			for (int j=0; j<9; ++j)
				cin >> board[i][j];

		bool flag = check();
		if (flag)
			cout << "Case " << t+1 << ": CORRECT\n";
		else
			cout << "Case " << t+1 << ": INCORRECT\n";
	}

	return 0;
}
