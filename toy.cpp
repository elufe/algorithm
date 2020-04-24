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

	for (int i = 0+start_check; i < t_size-start_check; i++) {	//��ü string Ž��

		if (!(											// ���ĺ�, '-'��ȣ, ���ڸ� ������ ���ڰ� ������ ���� ó��
			(total[i] >= 'A' && total[i] <= 'Z') ||		// �Ǽ��� ��� '.'�� ���ԵǾ� �����Ƿ� ���� ���� ����
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
			if (st.empty()) {		// �߸��� ��ȣ ")"
				check = -2;
				return check;
			}
			st.pop();
		}

		//if (i == t_size - 1 && (!st.empty())) {	// �߸��� ��ȣ "(";
		//	check = - 1;
		//	while (!st.empty())
		//		st.pop();
		//	return check;
		//}

		if (total[i] == ' ' && st.empty()) {	// op, left, right ��ȯ
			check++;
		}

		else {
			if (check == 0) {		// operator	�˻��ʿ�
				op_new += total[i];
			}
			else if (check == 1) {	// left		�˻��ʿ�
				left_new += total[i];
			}
			else {					// right	�˻��ʿ�
				right_new += total[i];
			}
		}

	}

	if (!st.empty()) {	// �߸��� ��ȣ "(";
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

	if (check == 0) {	//������ ���
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
	cout << "�޴��� �����ϼ��� >> ";
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
				cout << "���ϸ��� �Է��ϼ��� >> ";
				cin >> filename;
			}
			else if (menu == 2) {
				cout << "������ �Է��ϼ��� >> \n";
				cout << "-----------------------------\n";
				cin.ignore();
				getline(cin, filename);
				cout << "-----------------------------\n";
			}
			else if (menu == 3) {
				cout << "���α׷��� �����մϴ�.";
			}
			else{
				cout << "�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��ϼ��� >> ";
			}
		}

		if (menu == 1) {	//���� �ҷ�����
			ifstream openfile(filename);
			string buffer;
			
			while (!openfile) {
				cout << "������ �������� �ʽ��ϴ�. �ٽ� �Է��ϼ��� >>";
				cin >> filename;
				openfile.open(filename, ios::in);
			}
			cout << "���� ������\n";
			cout << "-----------------------------\n";

			while (openfile.peek() != EOF) {
				getline(openfile, buffer);
				cout << buffer << "\n";
				result = maketree(buffer, &head);
				
				if (result == -1) {		// �����˻�
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
			cout << "�Դϴ�.\n\n";


			while (!q1.empty()) {
				if (q1.front() == -1) {
					cout << "\"(\"�� ��ġ�� �߸��Ǿ����ϴ�.\n";
				}
				else if (q1.front() == -2) {
					cout << "\")\"�� ��ġ�� �߸��Ǿ����ϴ�.\n";
				}
				else if (q1.front() == -3) {
					cout << "�Է��� �߸��Ǿ����ϴ�.\n";

				}
				else if (q1.front() == -4) {
					cout << "\"-\"��ȣ�� �ߺ��Ǿ����ϴ�.\n";

				}
				else if (q1.front() == -5) {
					cout << "undefined\n";

				}
				else{
					cout << "��� : " << q2.front() << "\n";
					q2.pop();
				}
				q1.pop();
			}
			
		}
		else if (menu == 2) {	//���� �Է�
			result = maketree(filename, &head);
			if (result == -1) {		// �����˻�
				cout << "\"(\"�� ��ġ�� �߸��Ǿ����ϴ�.\n";
			}
			else if (result == -2) {
				cout << "\")\"�� ��ġ�� �߸��Ǿ����ϴ�.\n";
			}
			else if (result == -3) {
				cout << "�Է��� �߸��Ǿ����ϴ�.\n";
			}
			else if (result == -4) {
				cout << "\"-\"��ȣ�� �ߺ��Ǿ����ϴ�.\n";
			}
			else if (result == -5) {
				cout << "undefined\n";
			}
			else {
				cout << "��� : " << head->value<<"\n";
				cout << "-----------------------------\n";
			}
		}
		else if (menu == 3) {	//����
			return 0;
		}
		menu = -1;
	}
}


// ���� ���� Ȯ���غ���, Ʈ�� ���