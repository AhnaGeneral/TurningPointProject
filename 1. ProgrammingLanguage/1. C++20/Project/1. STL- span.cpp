#include <iostream>
using namespace std;
#include <list>
#include <vector>
#include <span>
#include <algorithm>

void PrintArray(int* arr)
{

}

void PrintSpan(std::span<int> container)
{
	cout << "container size() = " << container.size() << endl; 
	for (int idx = 0; idx < container.size(); ++idx)
	{
		cout << container[idx] << endl;
	}

	
	for (auto& At : container)
	{
		cout << At << endl; 
	}
}
int main()
{
	//std::span = cŸ�� �迭, std::array, std::vector, std::string���� 
	//������ ��ü ������(contiguous sequence of objects)�� ����(refer)
	//cŸ�� �迭, std::array, std::vector, std::string ���� ���ڷ� �ѱ��� �ʰ�
	//std::span�̶� �ַ� �ѱ�ڴٶ���̾߱⤷

	//�� ���� ? 
	//�ϴ� ġ������ ������ �������� �迭�� ���� �������� Ȯ��
	int arr[] = { 1,2,3,4,5 }; 
	const int size = sizeof(arr); //20 
	const int len = sizeof(arr) / sizeof(int); //5

	PrintArray(arr); 
	// ����� �׳� ������ �ּҰ��̴� �ּҰ��� �Ѱ��ذŴ�. 
	// �迭�� ���� ������ �߰������� �ѱ��� �ʾ���. 
	// �׷��� �׻� �߰������� int len�� ���� �Ű������� �߰��ϸ� �߰����� ������ �Ѱ��. 


	//std::span 
	// static_extent = ������ Ÿ�ӿ� ũ�Ⱑ ������ //�迭, array
	// dynamic_extent = vector�� ���� �������� ũ�Ⱑ ���ϴ� 
	// ������ + ũ�� 
	vector<int> myVec {1, 2, 3, 4, 5}; 
	vector<int> myVec2 {6, 7, 8, 9, 10}; 
	std::span<int> dynamic_span(myVec2); 
	std::span<int, 5> static_span(myVec);

	PrintSpan(dynamic_span); 
	PrintSpan(static_span);

	dynamic_span = static_span; 
	static_span = dynamic_span; //error 
	//�������� ũ�⿡ �������� ũ�⸦ ����°� �Ұ�. 

	//������/����� �̿��Ͽ� span ����
	std::span<int> span1(myVec.data(), myVec.size()); 
	// �κ������� �߶� �����
	std::span<int> span2(span1.subspan(1, span1.size() - 2);

	std::transform(span1.begin(), span1.end(), span1.begin(), [](int i) {return i * i; });
	PrintSpan(span1); 

	//span�� �����ϴ°��� �ƴ� �����̹Ƿ� ���� �����Ͱ� ������ �ȴ�. 

}


//_EXPORT_STD template <class _Ty /*� Ÿ������*/, size_t _Extent /*��� ũ��*/ = dynamic_extent>
//class span : private _Span_extent_type<_Ty, _Extent>
//
//_EXPORT_STD inline constexpr size_t dynamic_extent = static_cast<size_t>(-1); //���Ѵ�� ū ���� ���� ����.