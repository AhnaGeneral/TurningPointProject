#include <iostream>
#include <string>
#include <stack>
#include <map>
using namespace std;
stack<char> operatorStack;
map<char, int> priority; 

//void ReBracket()
//{
//	int RightBracket = 0;
//	int LeftBracket = 0;
//	
//	while (true)
//	{
//		stack<char> tempStack;
//		
//		if (operatorStack.empty() && !tempStack.empty())
//		{
//			operatorStack.push('(');
//			while (!tempStack.empty())
//			{
//				operatorStack.push(tempStack.top());
//				tempStack.pop();
//			}
//			break;
//		}
//
//		if (operatorStack.top() == ')')
//		{
//			RightBracket++;
//			tempStack.push(operatorStack.top());
//		}
//		else if (operatorStack.top() == '(')
//		{
//			LeftBracket++;
//			tempStack.push(operatorStack.top());
//		}
//		else if (RightBracket == LeftBracket)
//		{
//			if (isalpha(operatorStack.top()))
//			{
//				tempStack.push(operatorStack.top());
//				operatorStack.pop();
//				operatorStack.push('(');
//				operatorStack.push(tempStack.top());
//				break;
//			}
//		}
//		else
//		{
//			tempStack.push(operatorStack.top());
//		}
//		
//		operatorStack.pop();
//	}
//}
//
//
//int main(void)
//{
//	string Expression;
//	cin >> Expression; 
//
//	for (int i = 0; i < Expression.size(); ++i)
//	{
//		switch (Expression[i])
//		{
//		case '*':
//		case '/':
//		{
//			ReBracket();
//		}
//			break;
//		case '(':
//			break;
//		case ')':
//			break;
//		case '-':
//			break;
//		case '+':
//			break;
//		default:
//		{
//
//
//		}
//			break;
//		}
//		operatorStack.push(Expression[i]);
//	}

int main(void)
{
	string Expression;
	cin >> Expression;

	priority['('] = 0;  priority[')'] = 3;
	priority['*'] = priority['/'] = 1; 
	priority['+'] = priority['-'] = 2;

	for (int i = 0; i < Expression.size(); ++i)
	{
		if (isalpha(Expression[i]))
		{
			cout << Expression[i];
			//operatorStack.pop();
		}
		else if (priority.find(Expression[i]) != priority.end())
		{
			if (operatorStack.empty())
			{
				operatorStack.push(Expression[i]);
			}
			else
			{
				auto temp1 = priority.find(operatorStack.top()); // * 
				auto temp2 = priority.find(Expression[i]); // + 
				//if (temp2->second == 3)
				//{
				//	operatorStack.push(Expression[i]);
				//}
				if (temp1->second <= temp2->second)
				{
					while (!operatorStack.empty())
					{
						cout << operatorStack.top();
						operatorStack.pop();
					}
					if(Expression[i] != '(' && Expression[i] != ')')
					operatorStack.push(Expression[i]);
					//operatorStack.pop();
				}
				else
				{
					//if (temp2->second != 1)
					if (Expression[i] != '(' && Expression[i] != ')')
						operatorStack.push(Expression[i]);
				}
			}
			
		}

	}
		while (!operatorStack.empty())
		{
			//if( (priority.find(operatorStack.top()))->second  != 3)
			cout << operatorStack.top();
			operatorStack.pop();
		}
}