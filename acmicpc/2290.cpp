#include <iostream>
using namespace std;

int c[10][10] = {
		{1,1,1,0,1,1,1},
		{0,0,1,0,0,1,0},
		{1,0,1,1,1,0,1},
		{1,0,1,1,0,1,1},
		{0,1,1,1,0,1,0},
		{1,1,0,1,0,1,1},
		{1,1,0,1,1,1,1},
		{1,0,1,0,0,1,0},
		{1,1,1,1,1,1,1},
		{1,1,1,1,0,1,1}};

int main()
{
	string n;
	int s;

	cin >> s >> n;
	int len = n.length();
	for (int i=0; i<5; ++i) {
		if (i == 0 || i == 2 || i == 4) {
			for (int j=0; j<len; ++j) {
				int cur = n[j]-'0';
				if (j != 0)
					cout << ' ';
				cout << ' ';
				if ((i == 0 && c[cur][0]) || \
				    (i == 2 && c[cur][3]) || \
				    (i == 4 && c[cur][6]))
					for (int k=0; k<s; ++k)
						cout << '-';
				else
					for (int k=0; k<s; ++k)
						cout << ' ';
				cout << ' ';
			}
			cout << '\n';
		} else {
			for (int k=0; k<s; ++k) {
				for (int j=0; j<len; ++j) {
					int cur = n[j]-'0';
					if (j != 0)
						cout << ' ';
					if ((i == 1 && c[cur][1]) || \
					    (i == 3 && c[cur][4]))
						cout << '|';
					else
						cout << ' ';
					for (int t=0; t<s; ++t)
						cout << ' ';
					if ((i == 1 && c[cur][2]) || \
					    (i == 3 && c[cur][5]))
						cout << '|';
					else
						cout << ' ';
				}
				cout << '\n';
			}
		}
	}

	return 0;
}
