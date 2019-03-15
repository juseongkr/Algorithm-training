#include <iostream>
using namespace std;

int main()
{
	int num;
	int x1, y1, r1, x2, y2, r2;

	cin >> num;
	for (int i=0; i<num; ++i) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		int dis = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
		int a = (r1 - r2) * (r1 - r2);
		int b = (r1 + r2) * (r1 + r2);

		if (dis == 0 && a == 0)
			cout << "-1\n";
		else if (dis == 0)
			cout << "0\n";
		else if (dis == a || dis == b)
			cout << "1\n";
		else if (a < dis && dis < b)
			cout << "2\n";
		else
			cout << "0\n";
	}

	return 0;
}
