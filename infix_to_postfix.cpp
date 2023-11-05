#include <iostream>
#include <cmath>
#include <string>
#include "MyLib/stack.h"

using namespace std;

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

float getValueFromArray(char varname, string *values, int size)
{
	char temp;
	string value = "";
	for (int i = 0; i < size; i++)
	{
		string item = values[i];
		temp = item.at(0);
		if (varname == temp)
		{
			for (int j = 1; j < item.size(); j++)
			{
				value += item[j];
			}

			break;
		}
	}
	return stof(value);
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

float calculatePostfix(string postfix, string values[], int size)
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
	return stack.peek();
}

void getVariableValue(string statment, string arr[])
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
		string op;
		cout << "Please enter vlaue of " << oprands[i] << endl;
		cin >> op;
		arr[i] = oprands[i] + op;
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
	string variableValues[size];
	getVariableValue(infixStatment, variableValues); // Geting oprand values from user and store those in variableValues[] array
	PostFix pos(infixStatment);						 // Sending infix statment to Postfix class constructor for convert to postfix
	string postfixStatment = pos.getPostFix();
	float result = calculatePostfix(postfixStatment, variableValues, size); // Calculating result with postfix statment and oprand values
	cout << "Infix: " << infixStatment << " -- Postfix: " << postfixStatment << endl;
	cout << "Result -> " << result;

	return 0;
}
