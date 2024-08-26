
// KMP 알고리즘 (k)------------------------------------------------------- 
// 문자열 매칭 
/* 
	비교 (1)
	 1 2 3 4 5 6 7 8 9 …
T:	[A B C D A B C D A B D E]
     | | | | | | X
P :	[A B C D A B D]
	 1 2 3 4 5 6 7

 - P: 패턴(길이: m) T: 텍스트(길이: n) 
 - 모든 매칭을 확인한다면 (n - m + 1) x m 
 
 - 비교 (1)에서 얻은 정보 
	1) i = 1....6에 대해 T[i] == P[i]

	2) P 내부에 존재하는 문자열의 반복에 주목하자. P에서 1, 2번 문자 A, B는 5, 6번 문자로 반복되어 나타난다. 
	또, T의 1번 문자에서 시작하는 매칭이 7번 문자에서야 실패했으므로 T의 5, 6번 문자도 A, B이다.

	3) T의 1번 문자에서 시작하는 매칭이 실패한 이후, 그 다음으로 가능한 매칭은 T의 5번 문자에서 시작하는 매칭임을 알 수 있다!
	더불어, T의 5～6번 문자는 P의 1～2번 문자와 비교하지 않아도, 서로 같다는 것을 이미 알고 있다! 그러므로 이제는 T의 7번 문자와
	P의 3번 문자부터 비교해 나가면 된다.

	4) 일반화 T[i+j-1] != P[j]을 발견 -> P[1....k] = P[j-k....j-1]을 만족하는 최대의 k에 대해 T[i+j-1] 문자와 P[k+1]

	5) k를 j에 대한 함수라고 생각 1 ~ m까지의 값에 대해 최대 k를 미리 계산해 놓으면 편리 --> 전처리 과정 

	접두사와 접미사가 겹치는거. 찾는다. 
	접두사와 접미사를 구하게 되면 접두사와 접미사가 일치하는 경우에 한해서 점프를 수행할 수 있다. 
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

// 전처리 작업. 
// ABCDABD -> A 넣어보고 있으면 
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