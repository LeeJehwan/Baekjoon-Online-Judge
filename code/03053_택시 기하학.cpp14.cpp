#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

#define PI 3.14159265358979323846
int main() {
	int r;
	cin >> r;

	printf("%.6lf\n", PI*r*r);
	printf("%.6lf\n", 2.0*r*r);

}