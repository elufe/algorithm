#include <iostream>
#include<string>
#include<fstream>
#include <stack>
#include <queue>

using namespace std;

stack<string> st;
stack<int> cal;
queue<int> q1;
queue<int> q2;


struct node {
	string op="";
	string left="", right="";
	int value;
	node *left_node, *right_node;
	node(string op, string left, string right){
		this->op += op;
		this->left += left;
		this->right += right;
		value = 0;
	}
};

int maketree(string total, node** parent) {
	
	int t_size, start_check=0, check = 0, oper_type=0;
	string op_new = "", left_new = "", right_new = "";

	t_size = total.size();

	if (total[0] == '(')
		start_check = 1;

	for (int i = 0+start_check; i < t_size-start_check; i++) {	//전체 string 탐색

		if (!(											// 알파벳, '-'기호, 숫자를 제외한 문자가 들어오면 에러 처리
			(total[i] >= 'A' && total[i] <= 'Z') ||		// 실수인 경우 '.'이 포함되어 있으므로 같이 검출 가능
			(total[i] >= 'a' && total[i] <= 'z') ||
			(total[i] >= '0' && total[i] <= '9') ||
			total[i] == '-' || total[i] == ' ' ||
			total[i] == '(' || total[i] == ')')) {
			check = -3;
			return check;
		}

		if (total[i] == '(') {
			st.push("(");
		}
		else if (total[i] == ')') {
			if (st.empty()) {		// 잘못된 괄호 ")"
				check = -2;
				return check;
			}
			st.pop();
		}

		//if (i == t_size - 1 && (!st.empty())) {	// 잘못된 괄호 "(";
		//	check = - 1;
		//	while (!st.empty())
		//		st.pop();
		//	return check;
		//}

		if (total[i] == ' ' && st.empty()) {	// op, left, right 전환
			check++;
		}

		else {
			if (check == 0) {		// operator	검사필요
				op_new += total[i];
			}
			else if (check == 1) {	// left		검사필요
				left_new += total[i];
			}
			else {					// right	검사필요
				right_new += total[i];
			}
		}

	}

	if (!st.empty()) {	// 잘못된 괄호 "(";
		check = -1;
		while (!st.empty())
			st.pop();
		return check;
	}

	if (check > 0) {
		if (op_new != "MINUS" && op_new != "IF" && op_new != "minus" && op_new != "if") {
			check = -5;
			return check;
		}
	}
	else if (check == 0) {
		if (op_new[1] == '-') {
			check = -4;
			return check;
		}
	}
	
	*parent = new node(op_new, left_new, right_new);

	if (check == 0) {	//숫자일 경우
		(*parent)->value = stoi(op_new);
		return 1;
	}


	check = maketree(left_new, &((*parent)->left_node));
	cal.push((*parent)->left_node->value);
	if (check < 0)
		return check;

	check = maketree(right_new, &((*parent)->right_node));
	cal.push((*parent)->right_node->value);
	if (check < 0)
		return check;

	/////////////////////////////////////////////
	if (op_new[0] == 'M')
		oper_type = 1;
	else
		oper_type = 2;
	///////////////////////////////////////////

	if (oper_type == 1) {	// minus
		(*parent)->value = cal.top();
		cal.pop();
		(*parent)->value -= cal.top();
		cal.pop();
		(*parent)->value *= -1;
	}
	else {					// if
		(*parent)->value = cal.top();
		cal.pop();
		if (cal.top() <= 0) {
			(*parent)->value = 0;
		}
		cal.pop();
	}

//	cout << (*parent)->value << "\n";

	return check;
}

void start() {
	cout << "=============================\n";
	cout << "1. File Load\n";
	cout << "2. Interactive Mode\n";
	cout << "3. Exit\n";
	cout << "=============================\n";
	cout << "메뉴를 선택하세요 >> ";
}
	
int main() {
	int menu=-1, result=0;
	string filename;
	node *head = NULL;
	
	while (1) {
		start();
		while (menu < 1 || menu >3) {
			
			cin >> menu;
			
			if (menu == 1) {
				cout << "파일명을 입력하세요 >> ";
				cin >> filename;
			}
			else if (menu == 2) {
				cout << "문장을 입력하세요 >> \n";
				cout << "-----------------------------\n";
				cin.ignore();
				getline(cin, filename);
				cout << "-----------------------------\n";
			}
			else if (menu == 3) {
				cout << "프로그램을 종료합니다.";
			}
			else{
				cout << "잘못 입력하셨습니다. 다시 입력하세요 >> ";
			}
		}

		if (menu == 1) {	//파일 불러오기
			ifstream openfile(filename);
			string buffer;
			
			while (!openfile) {
				cout << "파일이 존재하지 않습니다. 다시 입력하세요 >>";
				cin >> filename;
				openfile.open(filename, ios::in);
			}
			cout << "파일 내용은\n";
			cout << "-----------------------------\n";

			while (openfile.peek() != EOF) {
				getline(openfile, buffer);
				cout << buffer << "\n";
				result = maketree(buffer, &head);
				
				if (result == -1) {		// 문법검사
					q1.push(result);
				}
				else if (result == -2) {
					q1.push(result);
				}
				else {
					q1.push(1);
					q2.push(head->value);
				}
			}
			cout << "-----------------------------\n";
			cout << "입니다.\n\n";


			while (!q1.empty()) {
				if (q1.front() == -1) {
					cout << "\"(\"의 위치가 잘못되었습니다.\n";
				}
				else if (q1.front() == -2) {
					cout << "\")\"의 위치가 잘못되었습니다.\n";
				}
				else if (q1.front() == -3) {
					cout << "입력이 잘못되었습니다.\n";

				}
				else if (q1.front() == -4) {
					cout << "\"-\"기호가 중복되었습니다.\n";

				}
				else if (q1.front() == -5) {
					cout << "undefined\n";

				}
				else{
					cout << "결과 : " << q2.front() << "\n";
					q2.pop();
				}
				q1.pop();
			}
			
		}
		else if (menu == 2) {	//문장 입력
			result = maketree(filename, &head);
			if (result == -1) {		// 문법검사
				cout << "\"(\"의 위치가 잘못되었습니다.\n";
			}
			else if (result == -2) {
				cout << "\")\"의 위치가 잘못되었습니다.\n";
			}
			else if (result == -3) {
				cout << "입력이 잘못되었습니다.\n";
			}
			else if (result == -4) {
				cout << "\"-\"기호가 중복되었습니다.\n";
			}
			else if (result == -5) {
				cout << "undefined\n";
			}
			else {
				cout << "결과 : " << head->value<<"\n";
				cout << "-----------------------------\n";
			}
		}
		else if (menu == 3) {	//종료
			return 0;
		}
		menu = -1;
	}
}


// 각종 예외 확인해보기, 트리 출력