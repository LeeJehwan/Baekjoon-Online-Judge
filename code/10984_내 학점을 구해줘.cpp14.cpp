#include <iostream>
#include <cstdio>
using namespace std;



void run() {
	int num;
	cin >> num;
	int grade;
	double score;
	double sum_score = 0;
	int sum_grade = 0;
	double gpa;

	for (int i = 0; i < num; i++) {
		cin >> grade >> score;
		sum_score += score*grade;
		sum_grade += grade;
	}
	gpa = sum_score / sum_grade;
	printf("%d %.1f\n", sum_grade, gpa);
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
		run();
}

