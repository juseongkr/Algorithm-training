#include <iostream>
#include <map>
using namespace std;

int main(int argc, char **argv)
{
	map<string, int> result, temp;
	string name[1001];
	int score[1001];
	int max_val;
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> name[i] >> score[i];
		result[name[i]] += score[i];
	}

	for (int i = 0; i < n; i++) {
		max_val = max(max_val, result[name[i]]);
	}

	for (int i = 0; ; i++) {
		if (!(result[name[i]] < max_val || (temp[name[i]] += score[i]) < max_val)) {
			cout << name[i] << endl;
			break;
		}
	}

	return 0;
}
