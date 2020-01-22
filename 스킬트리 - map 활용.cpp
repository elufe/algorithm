#include <string>
#include <vector>
#include <map>

using namespace std;

map<char, int> m;

int solution(string skill, vector<string> skill_trees) {
	int answer = skill_trees.size();
	int len = skill.size(), check = 1;
	string temp = "";

	for (int i = 0; i < len; i++) {
		m[skill[i]] = i + 1;
	}

	while (!skill_trees.empty()) {
		len = skill_trees.back().size();
		temp = skill_trees.back();
		skill_trees.pop_back();
		check = 1;

		for (int i = 0; i < len; i++) {
			if (m.count(temp[i])) {
				if (m[temp[i]] == check) {
					check++;
				}
				else {
					answer--;
					break;
				}
			}
		}
	}

	return answer;
}