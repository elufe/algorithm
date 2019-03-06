
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
	void f(int *p,int n);
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,input;
	stack st;
	int *p;
	cin >> n;
	p = new int[n];
	
	st.f(p,n);
}

void stack::f(int *p, int n) {
	int num = 0;
	
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		
		while (p[i] > this->top()) {
			this->push(++num);
		}
		
		if (p[i] == this->top()) {
			this->pop();
		}else {
		cout << "NO" << '\n';
		return;
	}
	}
	if (check == 0 && this->empty() == 0) {
		for (int i = 0; i < qsize; i++) {
			cout << q[i] << '\n';
		}
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
	q[qsize++] = '+';
}
void stack::pop() {
	node *a;
	if (tail != NULL) {
		a = tail;
//		cout << tail->a << endl;
		tail = tail->prev;
		delete a;
		if (length > 0)
			length--;
		else
			length = 0;
	}
	else
		check = 1;
	q[qsize++] = '-';
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
		return -1;
}
