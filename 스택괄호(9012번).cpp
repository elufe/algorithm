
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;
char *q = new char[200000];
int check;
int qsize;


class node {
	
public:
	int a;
	node* prev;
	node(int b) {
		this->a = b;
	}
};

class stack {
private:
	node* tail;
	int length;
public:
	stack() {
		length = 0;
		tail = NULL;
	}
	void push(int n);
	void pop();
	int size();
	int empty();
	int top();
	void f(char **p,int n);
//	void clear();
};

int main() {
	int n,input;
	stack st;
	char **p;
	cin >> n;
	p = new char*[n];
	
	st.f(p,n);
}

void stack::f(char **p, int n) {
	int num = 0;
	
	for (int i = 0; i < n; i++) {
		p[i] = new char[50];
		cin >> p[i];
		for (int j = 0; j < 50 && p[i][j] != '\0'; j++) {
			if (p[i][j] == '(') {
				this->push(1);
//				cout << "1" << endl;
			}
			else if(p[i][j]==')'&&this->top()){
				this->pop();
//				cout << "2"<<this->top() << endl;
			}
			else if(p[i][j] == ')'){
				cout << "NO" << '\n';
				break;
			}
			if (p[i][j + 1] == '\0'&&this->top()==0) {
//				cout << j << '\n';
				cout << "YES" << '\n';
				break;
			}
			else if (p[i][j + 1] == '\0') {
				cout << "NO" << '\n';

			}
		}
		this->tail = NULL;
	}
	
}


void stack::push(int n){
	node *a;
	a = new node(n);
	if (tail != NULL)
		a->prev = tail;
	else
		a->prev = NULL;
	tail = a;
	length++;
}
void stack::pop() {
	node *a;
	if (tail != NULL) {
		a = tail;
		tail = tail->prev;
		delete a;
		if (length > 0)
			length--;
		else
			length = 0;
	}
	else
		check = 1;

}
int stack::size() {
	return length;
}
int stack::empty() {
	if (length)
		return 1;
	else
		return 0;
}
int stack::top() {
	if (tail != NULL)
		return tail->a;
	else
		return 0;
}

