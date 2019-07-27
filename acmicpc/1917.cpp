#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a[6][6];

vector<vector<string>> ans = {
{"0010",
"1111",
"0010"},
{"0100",
"1111",
"1000"},
{"0010",
"1111",
"0100"},
{"0001",
"1111",
"1000"},
{"0001",
"1111",
"0100"},
{"11100",
"00111"},
{"1100",
"0111",
"0010"},
{"1100",
"0111",
"0001"},
{"0010",
"1110",
"0011"},
{"0001",
"1111",
"0001"},
{"1100",
"0110",
"0011"}
};

vector<string> mirror(const vector<string> &v)
{
	vector<string> ret(v.size());
	for (int i=0; i<v.size(); ++i) {
		string t = v[i];
		reverse(t.begin(), t.end());
		ret[i] = t;
	}
	return ret;
}

vector<string> rotate(const vector<string> &v)
{
	vector<string> ret(v[0].size());
	for (int i=0; i<v[0].size(); ++i)
		for (int j=v.size()-1; j>=0; j--)
			ret[i].push_back(v[j][i]);

	return ret;
}

bool check(const vector<string> &v, int y, int x)
{
	for (int i=0; i<v.size(); ++i) {
		for (int j=0; j<v[0].size(); ++j) {
			int ny = y + i;
			int nx = x + j;
			if (ny < 0 || nx < 0 || ny >= 6 || nx >= 6)
				return false;

			if ((v[i][j] == '0' && a[ny][nx] == 1) || (v[i][j] == '1' && a[ny][nx] == 0))
				return false;
		}
	}
	return true;
}

int main()
{
	int t = 3;
	while (t--) {
		for (int i=0; i<6; ++i)
			for (int j=0; j<6; ++j)
				cin >> a[i][j];

		bool flag = false;
		for (const auto &c : ans) {
			vector<string> cube(c);
			for (int a=0; a<2; ++a) {
				for (int b=0; b<4; ++b) {
					for (int i=0; i<6; ++i) {
						for (int j=0; j<6; ++j)
							if (check(cube, i, j))
								flag = true;
					}
					cube = rotate(cube);
				}
				cube = mirror(cube);
			}
		}
		if (flag)
			cout << "yes\n";
		else
			cout << "no\n";
	}

	return 0;
}
