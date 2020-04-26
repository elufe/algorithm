#include <iostream>
#include<string>
#include<fstream>
#include <stack>
#include <queue>

using namespace std;

stack<string> st;	//	괄호체크 스택
stack<int> cal;		//	계산 스택
queue<int> q1;		//	오류체크 큐
queue<int> q2;		//	결과저장 큐


struct node {
	string op="";					//	연산자
	string left="", right="";		//	left 문자열, right 문자열
	int value;						//	연산 결과
	node *left_node, *right_node;	//	자식 노드 포인터
	node(string op, string left, string right){
		this->op += op;
		this->left += left;
		this->right += right;
		value = 0;
	}
};

int maketree(string total, node** parent) {				//트리 생성 함수 - 오류 발생시 음수 리턴
														// total = 전체 string, parent = 생성할 노드 포인터
	int t_size, start_check=0, check = 0, oper_type=0;	// t_size = 전체 string 길이
														//	start_check = 전체 괄호 유무 체크 변수
														//	check = 오류 검출을 위한 변수, operator, left, right 구분 변수
														//	oper_type = 연산자 타입 저장 변수 1->minus, 2->if
	string op_new = "", left_new = "", right_new = "";	//	전체 string 파싱한뒤 저장할 string

	t_size = total.size();

	if (total[0] == '(')								//	시작문자가 '('인 경우
		start_check = 1;

	for (int i = 0+start_check; i < t_size-start_check; i++) {	//	전체 string 탐색  시작문자가 괄호인 경우 맨 앞, 맨 뒤 괄호 제외하고
																//	탐색

		if (!(											// 알파벳, '-'기호, 숫자를 제외한 문자가 들어오면 에러 처리
			(total[i] >= 'A' && total[i] <= 'Z') ||		// 실수인 경우 '.'이 포함되어 있으므로 같이 검출 가능
			(total[i] >= 'a' && total[i] <= 'z') ||
			(total[i] >= '0' && total[i] <= '9') ||
			total[i] == '-' || total[i] == ' ' ||
			total[i] == '(' || total[i] == ')')) {
			check = -3;									// 잘못된 입력(실수, 다른 문자) -> 오류번호 -3
			return check;								// 오류번호 입력
		}

		if (total[i] == '(') {							// 스택을 이용하여 괄호 검사
			st.push("(");
		}
		else if (total[i] == ')') {
			if (st.empty()) {							// 잘못된 괄호 ")"
				check = -2;								// 오류 번호 -> -2
				return check;
			}
			st.pop();
		}

		if (total[i] == ' ' && st.empty()) {	// 공백문자 -> 괄호 스택이 비어있는 경우 op, left, right 전환
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

	if (!st.empty()) {				// 파싱이 끝났을때 괄호의 스택에 괄호가 남아있는 경우
		check = -1;					// 잘못된 괄호 "(", 오류번호 -> -1
		while (!st.empty())
			st.pop();
		return check;
	}

	if (check > 0) {								// 파싱결과 operator, left, right로 나뉜경우
		if (op_new != "MINUS" && op_new != "IF" &&	// operator가 알맞은지 검사 
			op_new != "minus" && op_new != "if") {	
			check = -5;								// operator 자리에 다른 문자가 존재, 오류번호 -> -5
			return check;
		}
	}
	else if (check == 0) {							// 파싱결과 숫자부분 하나만 있는 경우
		if (op_new[1] == '-') {						// '-'가 연속으로 나오는지 검사 - 두번째 문자가 '-'이면 중복
			check = -4;								// 오류번호 -> -4
			return check;
		}
	}
	
	*parent = new node(op_new, left_new, right_new);	// 노드 생성

	if (check == 0) {									// 숫자일 경우
		(*parent)->value = stoi(op_new);				// 해당 값 value변수에 저장
		return 1;										// 정상적인 종료 1리턴
	}


	check = maketree(left_new, &((*parent)->left_node));	// left 노드 생성
	if (check < 0)											// left 노드 정상 생성 여부 검사
		return check;
	cal.push((*parent)->left_node->value);					// left 노드 결과값 스택에 저장
	
	check = maketree(right_new, &((*parent)->right_node));	// right 노드 생성
	if (check < 0)											// right 노드 정상 생성 여부 검사
		return check;
	cal.push((*parent)->right_node->value);					// right 노드 결과값 스택에 저장
	

	if (op_new[0] == 'M'|| op_new[0] == 'm')				// operator 타입 검사
		oper_type = 1;										// minus -> 1
	else													
		oper_type = 2;										// if -> 2
	

	if (oper_type == 1) {	// minus
		(*parent)->value = cal.top();	//	right 노드의 value 스택에서 꺼내서 현재 노드 value값 갱신
		cal.pop();
		(*parent)->value -= cal.top();	//	left 노드의 value 스택에서 꺼내서 현재 노드 value값에서 뺌
		cal.pop();
		(*parent)->value *= -1;			//	value = right - left  ->  -value = left - right
	}
	else {					// if
		(*parent)->value = cal.top();	//	right 노드의 value 스택에서 꺼내서 현재 노드 value값 갱신
		cal.pop();
		if (cal.top() <= 0) {			//	left 노드의 value 검사
			(*parent)->value = 0;		//	left 노드의 value가 0이하이면 현재 노드 value 0으로 갱신
		}
		cal.pop();
	}

	return check;						//	오류여부 확인 check 변수 리턴
}

void start() {	// 게임시작 출력 함수
	cout << "=============================\n";
	cout << "1. File Load\n";
	cout << "2. Interactive Mode\n";
	cout << "3. Exit\n";
	cout << "=============================\n";
	cout << "메뉴를 선택하세요 >> ";
}
	
int main() {
	int menu=-1, result=0;	//	menu = 메뉴선택 변수, result = 오류검사 변수
	string filename;		//	입력 string
	node *head = NULL;		//	트리 head 노드 포인터
	
	while (1) {				//	게임시작
		start();			//	초기 출력
		while (menu < 1 || menu >3) {	//	메뉴 선택 -> 1,2,3을 제외한 입력이면 다시 입력받음
			
			cin >> menu;
			
			if (menu == 1) {			//	1번 -> 파일명 입력받음
				cout << "파일명을 입력하세요 >> ";
				cin >> filename;
			}
			else if (menu == 2) {		//	2번 -> 문장 입력받음
				cout << "문장을 입력하세요 >> \n";
				cout << "-----------------------------\n";
				cin.ignore();			//	개행 버퍼 제거
				getline(cin, filename);
				cout << "-----------------------------\n";
			}
			else if (menu == 3) {	//	3번 선택
				cout << "프로그램을 종료합니다.";
			}
			else{					//	잘못된 메뉴 선택
				cout << "잘못 입력하셨습니다. 다시 입력하세요 >> ";
			}
		}

		if (menu == 1) {	//파일 불러오기
			ifstream openfile(filename);	//	파일 읽기
			string buffer;					//	파일 내용 저장할 버퍼
			
			while (!openfile) {				//	파일이 없는 경우 재입력 받음
				cout << "파일이 존재하지 않습니다. 다시 입력하세요 >>";
				cin >> filename;
				openfile.open(filename, ios::in);
			}
			cout << "파일 내용은\n";
			cout << "-----------------------------\n";

			while (openfile.peek() != EOF) {		//	파일 출력 및 트리 생성
				getline(openfile, buffer);			//	1줄 읽음
				cout << buffer << "\n";				//	1줄 출력
				result = maketree(buffer, &head);	//	트리생성 및 연산
				
				if (result == -1) {					//	오류 검사
					q1.push(result);				//	-1 -> "("
				}
				else if (result == -2) {			//	-2 -> ")"
					q1.push(result);
				}
				else if (result == -3) {			//	-3 -> 실수, 잘못된 문자
					q1.push(result);
				}
				else if (result == -4) {			//	-4 -> "-" 중복
					q1.push(result);
				}
				else if (result == -5) {			//	-5 -> 연산자 오류
					q1.push(result);
				}
				else {								//	1 -> 정상
					q1.push(1);
					q2.push(head->value);			//	결과값 저장
				}
			}
			cout << "-----------------------------\n";
			cout << "입니다.\n\n";


			while (!q1.empty()) {					//	q1 큐의 값이 음수이면 해당 오류, 1이면 결과값 출력
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
		else if (menu == 2) {								//	문장 입력
			result = maketree(filename, &head);
			if (result == -1) {								//	1번 선택과 동일하게 오류 검사 및 오류 메세지, 결과값 출력
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
