#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	string start, end;
	int mov, col, row;

	cin >> start >> end;

	row = start[0] - end[0];
	col = start[1] - end[1];
	mov = (max(abs(row), abs(col)));

	cout << mov << '\n';
	
	while (row || col) {
		if (row < 0) {
			row++;
			cout << "R";
		}
		if (row > 0) {
			row--;
			cout << "L";
		}
		if (col < 0) {
			col++;
			cout << "U";
		}
		if (col > 0) {
			col--;
			cout << "D";
		}
		cout << '\n';
	}

	return 0;
}
