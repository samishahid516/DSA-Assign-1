#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Stack.h"

using namespace std;

bool isValidExpression(const string& expression) {
	Stack<char> stack;

	for (char ch : expression) {
		if (ch == '(' || ch == '{' || ch == '[') {
			stack.push(ch);
		}
		else if (ch == ')' || ch == '}' || ch == ']') {
			if (stack.isEmpty()) return false;

			char top = stack.top();
			if ((ch == ')' && top != '(') ||
				(ch == '}' && top != '{') ||
				(ch == ']' && top != '[')) {
				return false;
			}
			stack.pop();
		}
	}

	return stack.isEmpty();
}

void readExpressionsFromFile(const string& filename, vector<string>& expressions) {
	ifstream file(filename);
	string line;

	if (file.is_open()) {
		while (getline(file, line)) {
			expressions.push_back(line);
		}
		file.close();
	}
	else {
		cerr << "Unable to open file: " << filename << endl;
	}
}

int main() {
	vector<string> expressions;
	readExpressionsFromFile("expressions.txt", expressions);

	if (expressions.empty()) {
		cout << "No expressions found in the file." << endl;
		return 1;
	}

	cout << "Available expressions:" << endl;
	for (size_t i = 0; i < expressions.size(); ++i) {
		cout << i + 1 << ": " << expressions[i] << endl;
	}

	int choice;
	cout << "Enter the line number to check (1 to " << expressions.size() << "): ";
	cin >> choice;

	if (choice < 1 || choice > expressions.size()) {
		cout << "Invalid choice." << endl;
		return 1;
	}

	string selectedExpression = expressions[choice - 1];
	if (isValidExpression(selectedExpression)) {
		cout << "The expression \"" << selectedExpression << "\" is valid." << endl;
	}
	else {
		cout << "The expression \"" << selectedExpression << "\" is invalid." << endl;
	}

	return 0;
}