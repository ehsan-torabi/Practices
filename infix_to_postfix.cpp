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
	string statment;
	void handleOprator(char element, Stack<char> *stack)
	{
		if (element == ')')
		{
			char operand = element;

			while (operand != '(')
			{
				operand = stack->pop();
				if (operand != '(')
				{
					statment += operand;
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
				handleOprator(element, &stack);
			}
			else
			{
				statment += element;
			}
		}
	}

	string getPostFix()
	{
		return statment;
	}
};

float getValueFromArray(char varname, Variable *values, int size)
{
	char temp;
	for (int i = 0; i < size; i++)
	{
		char temp = values[i].name;
		if (varname == temp)
		{
			return values[i].value;
		}
	}
	throw logic_error("Oprand is not blanced!");
}

float getResult(int a, int b, char op)
{
	switch (op)
	{
	case '*':
		return a * b;

	case '/':
		return a / b;

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

void getVariableValue(string statment, Variable arr[])
{
	string oprands = "";
	for (char c : statment)
	{
		if (!isOperator(c))
		{
			oprands += c;
		}
	}
	for (int i = 0; i < oprands.size(); i++)
	{
		float op;
		cout << "Please enter value of " << oprands[i] << endl;
		cin >> op;
		arr[i].name = oprands[i];
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
	string infixStatment = getInfix(); // Geting infix statment from user
	int size = infixStatment.size();
	Variable variableValues[size];
	getVariableValue(infixStatment, variableValues); // Geting oprand values from user and store those in variableValues[] array
	PostFix pos(infixStatment);						 // Sending infix statment to Postfix class constructor for convert to postfix
	string postfixStatment = pos.getPostFix();
	float result = calculatePostfix(postfixStatment, variableValues, size); // Calculating result with postfix statment and oprand values
	cout << "Infix: " << infixStatment << " -- Postfix: " << postfixStatment << endl;
	cout << "Result -> " << result;

	return 0;
}
