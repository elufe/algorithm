#include<iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

class node {
public:
	int a;
	node *next;
	node(int a) {
		this->a = a;
		this->next = NULL;
	}
};

class q {
public:
	node *head, *tail;
	int length;
	q() {
		head = NULL;
		tail = NULL;
		length = 0;
	}
	
	void push(int num);
	void pop();
	void size();
	void empty();
	void front();
	void back();

};

int main() {
	int n, input;
	cin >> n;
	char **a;
	q qq;
	a = new char*[n];
	for (int i = 0; i < n; i++) {
		a[i] = new char[10];
	}

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if ((strcmp(a[i], "push") == 0)) {
			//			cout << "push111";
			cin >> input;
			//			cout << input <<"1111111"<< endl;
			qq.push(input);
		}
		else if ((strcmp(a[i], "pop") == 0)) {
			qq.pop();
		}
		else if ((strcmp(a[i], "size") == 0)) {
			qq.size();
		}
		else if ((strcmp(a[i], "empty") == 0)) {
			qq.empty();
		}
		else if ((strcmp(a[i], "front") == 0)){
			qq.front();
		}
		else if ((strcmp(a[i], "back") == 0)) {
			qq.back();
		}

	}
}

void q::push(int num) {
	node *a;
	a = new node(num);
	if (this->head == NULL && tail == NULL) {
		this->head = a;
		this->tail = a;
	}
	else {
		tail->next = a;
		tail = a;
	}
	this->length++;
}

void q::pop() {
	if (this->head == NULL) {
		cout << -1<<endl;
	}
	else {
		cout << this->head->a << endl;;
		node *p;
		if (this->head == this->tail) {
			tail=NULL;
		}
		p = this->head->next;
		delete this->head;
		this->head = p;
		this->length--;
	}
}

void q::size() {
	cout << this->length<<endl;
}

void q::empty() {
	if (this->length==0) {
		cout << 1 << endl;
	}
	else {
		cout << 0 << endl;
	}
}

void q::front() {
	if (this->head != NULL&&this->tail != NULL) {
		cout << this->head->a<<endl;
	}
	else {
		cout << -1<<endl;
	}
}

void q::back() {
	if (this->tail != NULL&&this->head!=NULL) {
		cout << this->tail->a<<endl;
	}
	else {
		cout << -1<<endl;
	}
}