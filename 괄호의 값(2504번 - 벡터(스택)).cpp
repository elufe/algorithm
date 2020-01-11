#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> v;

char input;

int main() {

	int temp=0;

	while (1) {

		input = getchar();

		if (input == '\n' || input == '\0' || input == EOF)
			break;

		if (input == '(' || input == '[') {
			v.push_back(input);
		}
		else if (input == ')') {
			temp = 0;

			while (1) {
				if (v.empty()) {
					cout << 0;
					return 0;
				}

				if (v.back() == '(') {
					v.pop_back();
					if (temp == 0) {
						v.push_back(2);
					}
					else
						v.push_back(temp * 2);
					break;
				}
				else if (v.back() != ')' && v.back() != '[' && v.back() != ']') {
					temp += v.back();
					v.pop_back();
				}
				else {
					cout << 0;
					return 0;
				}
			}
		}
		else if (input == ']') {
			temp = 0;
			
			while (1) {
				if (v.empty()) {
					cout << 0;
					return 0;
				}

				if (v.back() == '[') {
					v.pop_back();
					if (temp == 0) {
						v.push_back(3);
					}
					else
						v.push_back(temp * 3);
					break;
				}
				else if (v.back() != ']' && v.back() != '(' && v.back() != ')') {
					temp += v.back();
					v.pop_back();
				}
				else {
					cout << 0;
					return 0;
				}
			}
		}
		temp = 0;
		while (!v.empty() && (v.back() != '(' && v.back() != ')' && v.back() != '[' && v.back() != ']')) {
			temp += v.back();
			v.pop_back();
		}

		if (temp)
			v.push_back(temp);
	}
	if (v.size() == 1)
		cout << temp;
	else
		cout << 0;
}