// 24060 - 알고리즘 수업: 병합정렬 (재귀)
#include<iostream>
using namespace std; 
int Temp[500'000];
int A[500'000];
int K; 
int a = 0;
void merge_sort(int A[], int p, int r);
void merge(int A[], int p, int q, int r);

void merge_sort(int A[], int p, int r) 
{
	if (p < r)
	{
		int q = (p + r) / 2; 
		merge_sort(A, p, q); // 전반부 정렬
		merge_sort(A, q + 1, r); //후반부 정렬
		merge(A, p, q, r);
	}
}

//p = 1, q = 2, r = 3 
void merge(int A[], int p, int q, int r)
{
	int i = p; 
	int j = q + 1; 
	int t = 1; 

	while ((i <= q) && (j <= r))
	{
		if (A[i] <= A[j])
		{
			Temp[t++] = A[i++];
		}
		else
		{
			Temp[t++] = A[j++];
		}
	}

	while (i <= q) //왼쪽 배열 부분이 남은 경우
	{
		Temp[t++] = A[i++];
	}
	while (j <= r)
	{
		Temp[t++] = A[j++];
	}

	i = p; 
	t = 1;

	while (i <= r)
	{
		a++;
		A[i++] = Temp[t++];
		if (a == K)
		{
			cout << A[i-1];
		}
	}
}

int main() {

	int N; 
	cin >> N >> K; 

	for (int i = 1; i <= N; ++i)
	{
		cin >> A[i];
	}

	merge_sort(A, 1, N);

	if (a < K)
	{
		cout << -1;

	}
	return 0;
}