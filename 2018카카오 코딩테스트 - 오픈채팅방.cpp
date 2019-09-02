#include <iostream>
#include <string>
#include <vector>
#include <map>


using namespace std;

vector<string> parse(string s, vector<string> v) {
	int size = s.size(), index = 0;
	v.push_back("\0");
	for (int i = 0; i < size; i++) {
		if (s[i] == ' ') {
			index++;
			v.push_back("\0");
		}
		else {
			if (v[index] == "\0")
				v[index] = s[i];
			else
				v[index].push_back(s[i]);
		}
	}
	return v;
}

vector<string> solution(vector<string> record) {
	vector<string> answer;
	int size = record.size();
	vector<string> split;

	map<string, string> m;

	string s = "\0";

	for (int i = 0; i < size; i++) {

		while (!split.empty())
			split.pop_back();

		split = parse(record[i], split);

		if (split[0] == "Enter") {
			m[split[1]] = split[2];
			split.pop_back();
			split.pop_back();
			split.pop_back();
		}
		else if (split[0] == "Leave") {
			split.pop_back();
			split.pop_back();
			continue;

		}
		else {
			m[split[1]] = split[2];
			split.pop_back();
			split.pop_back();
			split.pop_back();
		}

	}
	int index = 0;
	for (int i = 0; i < size; i++) {

		while (!split.empty())
			split.pop_back();

		split = parse(record[i], split);

		if (split[0] == "Enter") {
			answer.push_back("\0");
			s = m.find(split[1])->second + "님이 들어왔습니다.";
			answer[index++] = s;
		}
		else if (split[0] == "Leave") {
			answer.push_back("\0");
			s = m.find(split[1])->second + "님이 나갔습니다.";
			answer[index++] = s;
		}
		while (!split.empty())
			split.pop_back();
	}

	return answer;
}