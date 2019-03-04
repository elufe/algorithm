#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

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
	void size();
	void empty();
	void top();
};

int main() {
	int n, input;
	cin >> n;
	char **a;
	stack st;
	a = new char*[n];
	for (int i = 0; i < n; i++) {
		a[i] = new char[10];
	}

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (strcmp(a[i], "push") == 0) {
			//			cout << "push111";
			cin >> input;
			//			cout << input <<"1111111"<< endl;
			st.push(input);
		}
		else if (strcmp(a[i], "pop") == 0) {
			st.pop();
		}
		else if (strcmp(a[i], "size") == 0) {
			st.size();
		}
		else if (strcmp(a[i], "empty") == 0) {
			st.empty();
		}
		else if (strcmp(a[i], "top") == 0) {
			st.top();
		}

	}
}


void stack::push(int n) {
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
		cout << tail->a << endl;
		tail = tail->prev;
		delete a;
		if (length > 0)
			length--;
		else
			length = 0;
	}
	else
		cout << "-1" << endl;

}
void stack::size() {
	cout << length << endl;
}
void stack::empty() {
	if (length)
		cout << "0" << endl;
	else
		cout << "1" << endl;
}
void stack::top() {
	if (tail != NULL)
		cout << tail->a << endl;
	else
		cout << "-1" << endl;
}