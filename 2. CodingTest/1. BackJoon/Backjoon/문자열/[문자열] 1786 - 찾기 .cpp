
// KMP �˰��� (k)------------------------------------------------------- 
// ���ڿ� ��Ī 
/* 
	�� (1)
	 1 2 3 4 5 6 7 8 9 ��
T:	[A B C D A B C D A B D E]
     | | | | | | X
P :	[A B C D A B D]
	 1 2 3 4 5 6 7

 - P: ����(����: m) T: �ؽ�Ʈ(����: n) 
 - ��� ��Ī�� Ȯ���Ѵٸ� (n - m + 1) x m 
 
 - �� (1)���� ���� ���� 
	1) i = 1....6�� ���� T[i] == P[i]

	2) P ���ο� �����ϴ� ���ڿ��� �ݺ��� �ָ�����. P���� 1, 2�� ���� A, B�� 5, 6�� ���ڷ� �ݺ��Ǿ� ��Ÿ����. 
	��, T�� 1�� ���ڿ��� �����ϴ� ��Ī�� 7�� ���ڿ����� ���������Ƿ� T�� 5, 6�� ���ڵ� A, B�̴�.

	3) T�� 1�� ���ڿ��� �����ϴ� ��Ī�� ������ ����, �� �������� ������ ��Ī�� T�� 5�� ���ڿ��� �����ϴ� ��Ī���� �� �� �ִ�!
	���Ҿ�, T�� 5��6�� ���ڴ� P�� 1��2�� ���ڿ� ������ �ʾƵ�, ���� ���ٴ� ���� �̹� �˰� �ִ�! �׷��Ƿ� ������ T�� 7�� ���ڿ�
	P�� 3�� ���ں��� ���� ������ �ȴ�.

	4) �Ϲ�ȭ T[i+j-1] != P[j]�� �߰� -> P[1....k] = P[j-k....j-1]�� �����ϴ� �ִ��� k�� ���� T[i+j-1] ���ڿ� P[k+1]

	5) k�� j�� ���� �Լ���� ���� 1 ~ m������ ���� ���� �ִ� k�� �̸� ����� ������ �� --> ��ó�� ���� 

	���λ�� ���̻簡 ��ġ�°�. ã�´�. 
	���λ�� ���̻縦 ���ϰ� �Ǹ� ���λ�� ���̻簡 ��ġ�ϴ� ��쿡 ���ؼ� ������ ������ �� �ִ�. 
*/ 

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

string sText, sPattern;
int numberTable[101] = {0,};
int k = 0; 
int loopCnt = 0; 
vector<int> Result; 

// ��ó�� �۾�. 
// ABCDABD -> A �־�� ������ 
void makeTable(string Pattern)
{
	int j = 0;
	for (int i = 1; i < Pattern.size(); ++i)
	{
		while (j > 0 && Pattern[i] != Pattern[j])
		{
			j = numberTable[j - 1];
		}

		if (Pattern[i] == Pattern[j])
		{
			numberTable[i] = ++j;
		}
	}
}

void KMP(string mainText, string pattern)
{
	int k = 0;
	for (int i = 0; i < mainText.size(); ++i)
	{
		while (k > 0 && mainText[i] != pattern[k])
		{
			k = numberTable[k - 1];
		}

		if (mainText[i] == pattern[k])
		{
			if (k == pattern.size() - 1)
			{
				Result.push_back(i - pattern.size() + 1);
				k = numberTable[k];
				//loopCnt++;
				//return;
			}
			else
			{
				k++;
			}
		}
	}
}


int main(void)
{
	char text[101], pattern[101];
	cin.getline(text, 100, '\n');
	cin.getline(pattern, 100, '\n');
	
	//string sText, sPattern;
	sText = text; 
	sPattern = pattern; 
	makeTable(sPattern);
	KMP(sText, sPattern);

	cout << Result.size() << '\n';
	for (auto a : Result)
	{
		cout << a + 1<< '\n';
	}
	return 0;
}