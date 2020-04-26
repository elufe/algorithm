#include <iostream>
#include<string>
#include<fstream>
#include <stack>
#include <queue>

using namespace std;

stack<string> st;	//	��ȣüũ ����
stack<int> cal;		//	��� ����
queue<int> q1;		//	����üũ ť
queue<int> q2;		//	������� ť


struct node {
	string op="";					//	������
	string left="", right="";		//	left ���ڿ�, right ���ڿ�
	int value;						//	���� ���
	node *left_node, *right_node;	//	�ڽ� ��� ������
	node(string op, string left, string right){
		this->op += op;
		this->left += left;
		this->right += right;
		value = 0;
	}
};

int maketree(string total, node** parent) {				//Ʈ�� ���� �Լ� - ���� �߻��� ���� ����
														// total = ��ü string, parent = ������ ��� ������
	int t_size, start_check=0, check = 0, oper_type=0;	// t_size = ��ü string ����
														//	start_check = ��ü ��ȣ ���� üũ ����
														//	check = ���� ������ ���� ����, operator, left, right ���� ����
														//	oper_type = ������ Ÿ�� ���� ���� 1->minus, 2->if
	string op_new = "", left_new = "", right_new = "";	//	��ü string �Ľ��ѵ� ������ string

	t_size = total.size();

	if (total[0] == '(')								//	���۹��ڰ� '('�� ���
		start_check = 1;

	for (int i = 0+start_check; i < t_size-start_check; i++) {	//	��ü string Ž��  ���۹��ڰ� ��ȣ�� ��� �� ��, �� �� ��ȣ �����ϰ�
																//	Ž��

		if (!(											// ���ĺ�, '-'��ȣ, ���ڸ� ������ ���ڰ� ������ ���� ó��
			(total[i] >= 'A' && total[i] <= 'Z') ||		// �Ǽ��� ��� '.'�� ���ԵǾ� �����Ƿ� ���� ���� ����
			(total[i] >= 'a' && total[i] <= 'z') ||
			(total[i] >= '0' && total[i] <= '9') ||
			total[i] == '-' || total[i] == ' ' ||
			total[i] == '(' || total[i] == ')')) {
			check = -3;									// �߸��� �Է�(�Ǽ�, �ٸ� ����) -> ������ȣ -3
			return check;								// ������ȣ �Է�
		}

		if (total[i] == '(') {							// ������ �̿��Ͽ� ��ȣ �˻�
			st.push("(");
		}
		else if (total[i] == ')') {
			if (st.empty()) {							// �߸��� ��ȣ ")"
				check = -2;								// ���� ��ȣ -> -2
				return check;
			}
			st.pop();
		}

		if (total[i] == ' ' && st.empty()) {	// ���鹮�� -> ��ȣ ������ ����ִ� ��� op, left, right ��ȯ
			check++;							// 0 -> operator, 1 -> left, 2 -> right
		}

		else {
			if (check == 0) {		// operator
				op_new += total[i];
			}
			else if (check == 1) {	// left
				left_new += total[i];
			}
			else {					// right
				right_new += total[i];
			}
		}

	}

	if (!st.empty()) {				// �Ľ��� �������� ��ȣ�� ���ÿ� ��ȣ�� �����ִ� ���
		check = -1;					// �߸��� ��ȣ "(", ������ȣ -> -1
		while (!st.empty())
			st.pop();
		return check;
	}

	if (check > 0) {								// �Ľ̰�� operator, left, right�� �������
		if (op_new != "MINUS" && op_new != "IF" &&	// operator�� �˸����� �˻� 
			op_new != "minus" && op_new != "if") {	
			check = -5;								// operator �ڸ��� �ٸ� ���ڰ� ����, ������ȣ -> -5
			return check;
		}
	}
	else if (check == 0) {							// �Ľ̰�� ���ںκ� �ϳ��� �ִ� ���
		if (op_new[1] == '-') {						// '-'�� �������� �������� �˻� - �ι�° ���ڰ� '-'�̸� �ߺ�
			check = -4;								// ������ȣ -> -4
			return check;
		}
	}
	
	*parent = new node(op_new, left_new, right_new);	// ��� ����

	if (check == 0) {									// ������ ���
		(*parent)->value = stoi(op_new);				// �ش� �� value������ ����
		return 1;										// �������� ���� 1����
	}


	check = maketree(left_new, &((*parent)->left_node));	// left ��� ����
	if (check < 0)											// left ��� ���� ���� ���� �˻�
		return check;
	cal.push((*parent)->left_node->value);					// left ��� ����� ���ÿ� ����
	
	check = maketree(right_new, &((*parent)->right_node));	// right ��� ����
	if (check < 0)											// right ��� ���� ���� ���� �˻�
		return check;
	cal.push((*parent)->right_node->value);					// right ��� ����� ���ÿ� ����
	

	if (op_new[0] == 'M'|| op_new[0] == 'm')				// operator Ÿ�� �˻�
		oper_type = 1;										// minus -> 1
	else													
		oper_type = 2;										// if -> 2
	

	if (oper_type == 1) {	// minus
		(*parent)->value = cal.top();	//	right ����� value ���ÿ��� ������ ���� ��� value�� ����
		cal.pop();
		(*parent)->value -= cal.top();	//	left ����� value ���ÿ��� ������ ���� ��� value������ ��
		cal.pop();
		(*parent)->value *= -1;			//	value = right - left  ->  -value = left - right
	}
	else {					// if
		(*parent)->value = cal.top();	//	right ����� value ���ÿ��� ������ ���� ��� value�� ����
		cal.pop();
		if (cal.top() <= 0) {			//	left ����� value �˻�
			(*parent)->value = 0;		//	left ����� value�� 0�����̸� ���� ��� value 0���� ����
		}
		cal.pop();
	}

	return check;						//	�������� Ȯ�� check ���� ����
}

void start() {	// ���ӽ��� ��� �Լ�
	cout << "=============================\n";
	cout << "1. File Load\n";
	cout << "2. Interactive Mode\n";
	cout << "3. Exit\n";
	cout << "=============================\n";
	cout << "�޴��� �����ϼ��� >> ";
}
	
int main() {
	int menu=-1, result=0;	//	menu = �޴����� ����, result = �����˻� ����
	string filename;		//	�Է� string
	node *head = NULL;		//	Ʈ�� head ��� ������
	
	while (1) {				//	���ӽ���
		start();			//	�ʱ� ���
		while (menu < 1 || menu >3) {	//	�޴� ���� -> 1,2,3�� ������ �Է��̸� �ٽ� �Է¹���
			
			cin >> menu;
			
			if (menu == 1) {			//	1�� -> ���ϸ� �Է¹���
				cout << "���ϸ��� �Է��ϼ��� >> ";
				cin >> filename;
			}
			else if (menu == 2) {		//	2�� -> ���� �Է¹���
				cout << "������ �Է��ϼ��� >> \n";
				cout << "-----------------------------\n";
				cin.ignore();			//	���� ���� ����
				getline(cin, filename);
				cout << "-----------------------------\n";
			}
			else if (menu == 3) {	//	3�� ����
				cout << "���α׷��� �����մϴ�.";
			}
			else{					//	�߸��� �޴� ����
				cout << "�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��ϼ��� >> ";
			}
		}

		if (menu == 1) {	//���� �ҷ�����
			ifstream openfile(filename);	//	���� �б�
			string buffer;					//	���� ���� ������ ����
			
			while (!openfile) {				//	������ ���� ��� ���Է� ����
				cout << "������ �������� �ʽ��ϴ�. �ٽ� �Է��ϼ��� >>";
				cin >> filename;
				openfile.open(filename, ios::in);
			}
			cout << "���� ������\n";
			cout << "-----------------------------\n";

			while (openfile.peek() != EOF) {		//	���� ��� �� Ʈ�� ����
				getline(openfile, buffer);			//	1�� ����
				cout << buffer << "\n";				//	1�� ���
				result = maketree(buffer, &head);	//	Ʈ������ �� ����
				
				if (result == -1) {					//	���� �˻�
					q1.push(result);				//	-1 -> "("
				}
				else if (result == -2) {			//	-2 -> ")"
					q1.push(result);
				}
				else if (result == -3) {			//	-3 -> �Ǽ�, �߸��� ����
					q1.push(result);
				}
				else if (result == -4) {			//	-4 -> "-" �ߺ�
					q1.push(result);
				}
				else if (result == -5) {			//	-5 -> ������ ����
					q1.push(result);
				}
				else {								//	1 -> ����
					q1.push(1);
					q2.push(head->value);			//	����� ����
				}
			}
			cout << "-----------------------------\n";
			cout << "�Դϴ�.\n\n";


			while (!q1.empty()) {					//	q1 ť�� ���� �����̸� �ش� ����, 1�̸� ����� ���
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
		else if (menu == 2) {								//	���� �Է�
			result = maketree(filename, &head);
			if (result == -1) {								//	1�� ���ð� �����ϰ� ���� �˻� �� ���� �޼���, ����� ���
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
