#include <iostream>
using namespace std;
#define MAX 101
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

char op;
int no, cnt;
int Y, X, N, M, x[MAX], y[MAX], d[MAX];

int main()
{
	cin >> Y >> X >> N >> M;
	for (int i=0; i<N; i++) {
		cin >> y[i] >> x[i] >> op;
		y[i]--;
		x[i]--;

		if (op == 'N')
			d[i] = 0;
		else if (op == 'E')
			d[i] = 1;
		else if (op == 'S')
			d[i] = 2;
		else
			d[i] = 3;
	}

	bool fail = false;
	for (int i=0; i<M; i++) {
		cin >> no >> op >> cnt;
		no--;
		if (fail)
			continue;

		if (op == 'L') {
			d[no] = (d[no] + 3 * cnt) % 4;
		} else if (op == 'R') {
			d[no] = (d[no] + cnt) % 4;
		} else {
			for (int j=0; j<cnt; j++) {
				int nx = x[no] + dx[d[no]];
				int ny = y[no] + dy[d[no]];

				if (nx < 0 || nx >= X || ny < 0 || ny >= Y) {
					cout << "Robot " << no+1 << " crashes into the wall\n";
					fail = true;
					break;
				}

				for (int k=0; k<N; k++) {
					if (i != k && x[k] == nx && y[k] == ny) {
						cout << "Robot " << no+1 << " crashes into robot " << k+1 << '\n';
						fail = true;
						break;
					}
				}

				if (fail)
					break;

				x[no] = nx;
				y[no] = ny;
			}
		}
	}

	if (!fail)
		cout << "OK\n";

	return 0;
}
