#include <iostream>
#include <cmath>
#include <string>
#include "MyLib/stack.h"

using namespace std;

struct Variable
{
	char name;
	int value;
};

bool isOperator(char c)
{
	int ch = (int)c;
	switch (ch)
	{
	case '(':
	case ')':
	case '*':
	case '+':
	case '-':
	case '/':
	case '^':
		return true;
	default:
		return false;
	}
}

class PostFix
{
private:
	string statement;
	void handleOperators(char element, Stack<char> *stack)
	{
		if (element == ')')
		{
			char operand = element;

			while (operand != '(')
			{
				operand = stack->pop();
				if (operand != '(')
				{
					statement += operand;
				}
			}
		}
		else
		{
			stack->push(element);
		}
	}

public:
	PostFix(string infix)
	{
		Stack<char> stack(infix.size());
		for (char element : infix)
		{
			if (isOperator(element))
			{
				handleOperators(element, &stack);
			}
			else
			{
				statement += element;
			}
		}
	}

	string getPostFix()
	{
		return statement;
	}
};

float getValueFromArray(char varname, Variable *values, int size)
{
	char temp = 0;
	for (int i = 0; i < size; i++)
	{
		char temp = values[i].name;
		if (varname == temp)
		{
			return values[i].value;
		}
	}
	throw logic_error("Operands is not balanced");
}

float getResult(int a, int b, char op)
{
	switch (op)
	{
	case '*':
		return a * b;

	case '/':
		return (float)a / b;

	case '+':
		return a + b;

	case '-':
		return a - b;

	case '^':
		return pow(a, b);

	default:
		return 0;
		break;
	}
}

float calculatePostfix(string postfix, Variable values[], int size)
{
	Stack<float> stack(postfix.size());
	for (char c : postfix)
	{
		if (!isOperator(c))
		{
			stack.push(getValueFromArray(c, values, size));
		}
		else
		{
			stack.push(getResult(stack.pop(), stack.pop(), c));
		}
	}
	return stack.pop();
}

void getVariableValue(string statement, Variable arr[])
{
	string operands = "";
	for (char c : statement)
	{
		if (!isOperator(c))
		{
			operands += c;
		}
	}
	for (int i = 0; i < operands.size(); i++)
	{
		float op;
		cout << "Please enter vlaue of " << oprands[i] << endl;
		cin >> op;
		arr[i].name = operands[i];
		arr[i].value = op;
	}
}

string getInfix()
{
	string infix;
	cout << "Please enter infix phrase (with all parentheses): \n";
	cin >> infix;
	return infix;
}

int main()
{
	string infixStatement = getInfix(); // Getting infix statement from user
	const int size = infixStatement.size();
	Variable variableValues[size];
	getVariableValue(infixStatement, variableValues); // Getting operand values from user and store those in variableValues[] array
	PostFix pos(infixStatement);						 // Sending infix statement to Postfix class constructor for convert to postfix
	string postfixStatement = pos.getPostFix();
	float result = calculatePostfix(postfixStatement, variableValues, size); // Calculating result with postfix statement and operand values
	cout << "Infix: " << infixStatement << " -- Postfix: " << postfixStatement << endl;
	cout << "Result -> " << result;

	return 0;
}
