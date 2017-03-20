/*
@ProgramName: Infix and Postfix Calculator
@Author: Rojitha Goonesekere
@Description: modifies infix's to postfix and then calculate the postfix evaluation
@Course: 1063 Data Structures
@Semester: Spring 2017
@Date: 20 March 2017
*/

#include <iostream>
#include<fstream>
#include<string>
#include<math.h>
#include<iomanip>

using namespace std;

/**
* @ProgramName: Array Based Stack
* @Author: CS 1063 Course Members
* @Description:
*     This program uses an array to implement a basic stack.
* @Course: 1063 Data Structures
* @Semester: Spring 2017
* @Date: Mar 2017
*/

/**
* @FunctionName: Stack
* @Description:
*     Implementation of a char stack
*/
class Stack {
private:
	char *S;
	int top;
	int size;
public:
	/**
	* @FunctionName: Stack
	* @Description:
	*     Class constructor
	* @Params:
	*    int insize - initial stack size
	* @Returns:
	*    void
	*/
	Stack(int insize) {
		size = insize;
		top = -1;
		S = new char[size];
	}

	/**
	* @FunctionName: push
	* @Description:
	*     Adds a character to the stack
	* @Params:
	*    char c - character to add
	* @Returns:
	*    void
	*/
	void push(char c) {
		if (!full()) {
			S[++top] = c;
		}
		else {
			cout << "Stack Overflow!" << endl;
		}
	}

	/**
	* @FunctionName: pop
	* @Description:
	*     Returns a character from the top of the stack
	* @Params:
	*    None
	* @Returns:
	*    void
	*/
	char pop() {
		if (!empty())
			return S[top--];
		else
			return -1;
	}

	/**
	* @FunctionName: printStack
	* @Description:
	*     Prints stack to stdout for debugging purposes
	* @Params:
	*    None
	* @Returns:
	*    void
	*/
	void printStack() {
		for (int i = top; i >= 0; i--) {
			cout << S[i] << " ";
		}
		cout << endl;
	}

	/**
	* @FunctionName: empty
	* @Description:
	*     Checks to see if stack is empty.
	* @Params:
	*    None
	* @Returns:
	*    bool - true if empty / false otherwise
	*/
	bool empty() {
		return top == -1;
	}

	/**
	* @FunctionName: peek
	* @Description:
	*     Returns the top of the stack without popping it off
	* @Params:
	*    None
	* @Returns:
	*    void
	*/
	char peek() {
		if (!empty())
			return S[top];
		else
			return -1;
	}

	/**
	* @FunctionName: full
	* @Description:
	*     Checks if stack is full
	* @Params:
	*    None
	* @Returns:
	*    bool - true if full / false otherwise
	*/
	bool full() {
		return top == size - 1;
	}
};

/**
* @ProgramName: Array Based Queue
* @Author: CS 1063 Course Members
* @Description:
*     This program uses an array to implement a basic queue.
* @Course: 1063 Data Structures
* @Semester: Spring 2017
* @Date: Mar 2017
*/


/**
* @FunctionName: Queue
* @Description:
*     Implementation of a char queue
*/
class Queue {
private:
	int ArraySize;
	char *Q;
	int Front;
	int Rear;
	int NumItems;

public:
	/**
	* @FunctionName: Queue
	* @Description:
	*     Class constructor
	* @Params:
	*    int insize - initial queue size
	* @Returns:
	*    void
	*/
	Queue(int insize) {
		ArraySize = insize;
		Q = new char[ArraySize];
		Front = Rear = NumItems = 0;
	}

	/**
	* @FunctionName: push
	* @Description:
	*     Adds a character to the queue
	* @Params:
	*    char c - character to add
	* @Returns:
	*    void
	*/
	void Push(char c) {
		if (Full()) {
			cout << "Queue Full!" << endl;
			return;
		}
		Q[Rear] = c;
		Rear = (Rear + 1) % ArraySize;
		NumItems++;
		return;
	}

	/**
	* @FunctionName: pop
	* @Description:
	*     Returns a character from the top of the queue
	* @Params:
	*    None
	* @Returns:
	*    void
	*/
	char Pop() {
		if (Empty()) {
			cout << "Queue Empty!" << endl;
			return false;
		}
		int Temp = Q[Front];
		Front = (Front + 1) % ArraySize;
		NumItems--;
		return Temp;
	}

	/**
	* @FunctionName: printQueue
	* @Description:
	*     Prints queue to stdout for debugging purposes
	* @Params:
	*    None
	* @Returns:
	*    void
	*/
	void PrintQueue() {
		for (int i = Front, j = 0; j<NumItems; j++, i = (i + 1) % ArraySize) {
			cout << Q[i] << " ";
		}
		cout << endl;
	}

	/**
	* @FunctionName: empty
	* @Description:
	*     Checks to see if queue is empty.
	* @Params:
	*    None
	* @Returns:
	*    bool - true if empty / false otherwise
	*/
	bool Empty() {
		return (NumItems == 0);
	}

	/**
	* @FunctionName: full
	* @Description:
	*     Checks if queue is full
	* @Params:
	*    None
	* @Returns:
	*    bool - true if full / false otherwise
	*/
	bool Full() {
		return (NumItems == ArraySize);
	}
};

/*
* @FunctionName: precedenceCheck
* @Description:
*    Checks precedence in which operations will be performed
* @Params:
*    char c - checks the priority of the current operator
* @Returns:
*    int - The priority of the current operator
*/
int precedenceCheck(char ch) {
	int val;
	switch (ch) {
	case '+':
	case '-':
		val = 1;
		break;
	case '*':
	case '/':
	case '%':
		val = 2;
		break;
	case '^':
		val = 3;
		break;
	default:
		val = -1;
	}
	return val;
}

/*
* @FunctionName: isOperator
* @Description:
*     Checks if parameter is an operator
* @Params:
*    char c - Will be evaluated to see if it's an operator
* @Returns:
*    bool - true if the parameter is an operator, false otherwise
*/
bool isOperator(char c) {
	if (c == '+')
		return true;
	else if (c == '-')
		return true;
	else if (c == '*')
		return true;
	else if (c == '/')
		return true;
	else if (c == '^')
		return true;
	else if (c == '%')
		return true;
	else
		return false;
}


int main() {
	ifstream infile;
	infile.open("expression.txt");
	ofstream outfile;
	outfile.open("results.txt");
	srand(546365);
	string infix; //stores expression
	double x, y;//Holds values popped off the stack
	char ch;//Holds a character popped off from the queue
	double eval = 0;//The result of x and y are evaluated
	double result = 0; //Result of the infix & postfix evaluations
	int num2; //Number of expressions from input file
	infile >> num2;
	for (int i = 0; i < num2; i++) {
		infile >> infix;
		cout << infix << " = ";
		outfile << "Expression to be converted: " << infix << endl;
		Stack s1(infix.length());
		Queue q1(infix.length());
		infix += ')';
		s1.push('(');
		while (!s1.empty()) {
			for (int j = 0; j < infix.length(); j++) {
				if (infix[j] != ' ') {
					if (isdigit(infix[j])) {
						q1.Push(infix[j]);
					}
					else if (infix[j] == '(') {
						s1.push(infix[j]);
					}
					else if (precedenceCheck(infix[j]) != -1) {
						while (precedenceCheck(infix[j]) <= precedenceCheck(s1.peek())) {
							q1.Push(s1.pop());
						}
						s1.push(infix[j]);


					}
					else if (infix[j] == ')') {
						while (s1.peek() != '(') {
							q1.Push(s1.pop());
						}
						s1.pop();
					}

				}
			}
			outfile << " " << endl;
	
		}
		while (!q1.Empty()) {
			ch = q1.Pop();
			if (isdigit(ch)) {
				s1.push(ch - '0');
			}
			else if (isOperator(ch)) {
				x = s1.pop();
				y = s1.pop();
				if (ch == '+')
					eval = y + x;
				else if (ch == '-')
					eval = y - x;
				else if (ch == '*')
					eval = y * x;
				else if (ch == '/')
					eval = y / x;
				else if (ch == '%')
					eval = (int)y % (int)x;
				else if (ch == '^')
					eval = pow(y, x);
				s1.push(eval);
			}
		}
		result = s1.peek();
		cout << result << endl;
		outfile << "Answer to expression: " << result << endl << endl;
	}
	system("pause");
	return 0;
}
