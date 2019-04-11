#include <iostream>
using namespace std;


double Avg(int arr[], int len) {
	double sum = 0;
	for (int i = 0; i < len; i++)
		sum += (double)arr[i];
	return sum / len;
}


void run() {
	int num, count = 0;
	cin >> num;
	int arr[1000];

	for (int i = 0; i < num; i++)
		cin >> arr[i];
	double avg = Avg(arr, num);
	for (int i = 0; i < num; i++)
		if ((double)arr[i] > avg)
			count++;
	printf("%.3lf%%\n", (double)count / num * 100);

}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		run();
}
