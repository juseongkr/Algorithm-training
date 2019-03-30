#include <iostream>
#include <algorithm>
using namespace std;

int l, c;
char pw[16];

void solve(int p, int x, int y, string s)
{
	if (s.size() == l) {
		if (x >= 1 && y >= 2)
			cout << s << '\n';
		return;
	}

	for (int i=p; i<c; ++i) {
		if (pw[i] == 'a' || pw[i] == 'e' || pw[i] == 'i' ||
		    pw[i] == 'o' || pw[i] == 'u')
			solve(i+1, x+1, y, s+pw[i]);
		else
			solve(i+1, x, y+1, s+pw[i]);
	}
}

int main()
{
	scanf("%d %d", &l, &c);
	for (int i=0; i<c; ++i)
		scanf(" %c", &pw[i]);

	sort(pw, pw + c);

	solve(0, 0, 0, "");

	return 0;
}
