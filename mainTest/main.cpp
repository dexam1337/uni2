/*
 * main.cpp
 *
 *  Created on: Feb 22, 2017
 *      Author: sebastian
 */

#include <iostream>
using namespace std;

void printPyramid(int n);
void printLine(int limit, int n);
string compressString(string s);

int main() {
	//string s;
	//cin >> s;
	//cout << compressString(s);
	//printPyramid(5);

	return 0;

}

string compressString(string s) {
	string compressed = "";
	char last = '~';
	int count = 0;
	s += '~';

	for (unsigned int i = 0; i < s.length(); i++) {
		if (last != s.at(i)) {
			if (count > 1) {
				compressed += last;
				compressed += to_string(count);
			} else if (count == 1) {
				compressed += last;
			}
			last = s.at(i);
			count = 1;
		} else {
			count++;
		}
	}
	return compressed;
}

void printPyramid(int n) {
	for (int i = 1; i <= n; i++) {
		printLine(i, n);
	}
}

void printLine(int limit, int n) {
	for (int i = 0; i < (n - limit); i++)
		cout << " ";

	for (int i = limit; i > 0; i--)
		cout << i;

	for (int i = 2; i <= limit; i++)
		cout << i;

	cout << endl;
}
