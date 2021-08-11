#include <iostream>


using namespace std;
int main() {
	int n;
	int cnt = 0;
	cin >> n;
	int arr[] = {500, 100, 50, 10, 5, 1};
	n = 1000 - n;
	for (int i = 0; i < 6; i++) {
		while (n > 0) {
			if (n >= arr[i]) {
				n -= arr[i];
				cnt++;
			}
			else break;
		}
		if (n == 0)
			break;
	}
	cout << cnt << endl;

}