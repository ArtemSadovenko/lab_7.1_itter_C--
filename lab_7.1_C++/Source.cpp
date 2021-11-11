#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;
void create(int** a,int col, int row, int l, int h);
void print(int** a, int row, int col);
void sort(int** a, int row, int col);
void change(int** a, int i1, int i2, int col);
int sum(int** a, int row, int col, int& k);

void main() {
	srand((unsigned)time(NULL));

	int row = 7;
	int col = 6;

	int l = -12;
	int h = 23;

	int k = 0;

	int** X = new int* [row];
	for (int i = 0; i < row; i++) 
		X[i] = new int[col];

	create(X, col, row, l, h);

	print(X, row, col);

	sort(X, row, col);

	print(X, row, col);

	int s = sum(X, row, col, k);

	print(X, row, col);

	cout << "sum = " << s << "\t" << "amount = " << k << endl;

}

void create(int** a, int col, int row, int l, int h) {
	for (int i = 0; i < row; i++) 
		for (int j = 0; j < col; j++) 
			a[i][j] = l + rand() % (h - l + 1);
}

void print(int** a, int row, int col ) {
	for (int i = 0; i < row; i++) {
		cout << "|";
		for (int j = 0; j < col; j++) {
			cout << setw(3) << a[i][j] << " ";
		}
		cout << "|" <<  endl;
	}
	cout <<  endl;
}

void sort(int** a, int row, int col) {
	for (int i0 = 0; i0 < row - 1; i0++) 
		for (int i1 = 0; i1 < row - i0 - 1; i1++) 
			if ((a[i1][0] > a[i1 + 1][0]) 
				||
				(a[i1][0] == a[i1 + 1][0] &&
				a[i1][1] > a[i1 + 1][1]) 
				||
				(a[i1][0] == a[i1 + 1][0] &&
				a[i1][1] == a[i1 + 1][1] &&
				a[i1][3] < a[i1 + 1][3])) 
				change(a, i1, i1 + 1, col);
}

void change(int** a, int i1, int i2, int col) {
	int k;
	for (int i = 0; i < col; i++) {
		k = a[i1][i];
		a[i1][i] = a[i2][i];
		a[i2][i] = k;
	}
}

int sum(int** a, int row, int col, int& k) {
	int s = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if ( !(a[i][j] % 2 == 0) 
				||
				!(a[i][j] < 0) ) {
				s += a[i][j];
				k++;
				a[i][j] = 0;
			}
		}
	}
	return s;
}