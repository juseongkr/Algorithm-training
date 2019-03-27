#include <iostream>
using namespace std;

int main()
{
	string cmd[51];
	string dict;
	int num;

	cin >> num;
	for (int i=0; i<num; ++i)
		cin >> cmd[i];
	
	dict = cmd[0];
	for (int i=0; i<num-1; ++i) {
		for (int j=0; j<cmd[i].length(); ++j) {
			if (cmd[i][j] != cmd[i+1][j])
				dict[j] = '?';
		}
	}

	cout << dict << '\n';

	return 0;
}
