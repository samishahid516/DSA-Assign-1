
#include <vector>
#include <stdexcept>

template <typename T>

class Stack {
private:
	std::vector<T> elements;

public:
	void push(const T& element) {
		elements.push_back(element);
	}

	void pop() {
		if (!isEmpty()) {
			elements.pop_back();
		}
	}

	T top() const {
		if (!isEmpty()) {
			return elements.back();
		}
		throw std::out_of_range("Stack is empty");
	}

	bool isEmpty() const {
		return elements.empty();
	}
};

bool isValidExpression(const std::string& expression);
void readExpressionsFromFile(const std::string& filename, std::vector<std::string>& expressions);


