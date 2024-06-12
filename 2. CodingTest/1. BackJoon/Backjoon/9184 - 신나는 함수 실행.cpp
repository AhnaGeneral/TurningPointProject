#include <iostream>
#include <string>

using namespace std;

int cache[51][51][51];
int w(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;

	int& result = cache[a][b][c];

	if (result != 0) {
		return result;
	}

	if (a > 20 || b > 20 || c > 20)
		return result = w(20, 20, 20);

	if (a < b && b < c)
		return result = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);

	return result = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}
int main() {

	int a, b, c;
	int n = 0;
	while (1) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			return 0;
		n = w(a, b, c);
		cout << "w(" << a << ", " << b << ", " << c << ") = " << n << '\n';
	}

	return 0;
}//end of main