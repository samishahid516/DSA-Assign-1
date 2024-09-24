#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Stack.cpp"

using namespace std;

bool isValidExpression(const std::string& expression) 
{
    Stack<char> stack;  // Use char for the stack

    for (char ch : expression)
    {
        if (ch == '(' || ch == '{' || ch == '[') {
            stack.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (stack.IsEmpty()) return false;

            char top = stack.Top();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
            stack.pop();
        }
    }

    return stack.IsEmpty();
}

void readExpressionsFromFile(const std::string& filename, std::vector<std::string>& expressions)
{
    std::ifstream file(filename);
    std::string line;

    if (file.is_open()) 
    {
        while (getline(file, line))
        {
            expressions.push_back(line);
        }
        file.close();
    }
    else
    {
        cerr << "Unable to open file: " << filename << endl;
    }
}

int main() 
{
start:
    system("cls");
    vector<string> expressions;
    readExpressionsFromFile("expressions.txt", expressions);

    if (expressions.empty())
    {
        cout << "No expressions found in the file." << endl;
        return 1;
    }

    cout << "Available expressions:" << endl;
    for (size_t i = 0; i < expressions.size(); ++i) 
    {
        cout << i + 1 << ": " << expressions[i] << endl;
    }

    int choice;

    do {
        cout << "Enter the line number to check (1 to " << expressions.size() << "): ";
        cin >> choice;

        if (choice < 1 || choice > expressions.size()) {
            cout << "Invalid choice. Please try again:" << endl;
            choice = -1;
        }

    } while (choice < 1 || choice > expressions.size());

    string selectedExpression = expressions[choice - 1];

    if (isValidExpression(selectedExpression)) 
    {
        cout << "The expression \"" << selectedExpression << "\" is valid." << endl;
    }
    else {
        cout << "The expression \"" << selectedExpression << "\" is invalid." << endl;
    }

    system("pause");
    goto start;

    return 0;
}
