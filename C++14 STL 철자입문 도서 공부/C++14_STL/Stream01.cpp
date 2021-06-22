#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>
using std::string; 

int main()
{
	std::vector<string> words{ "Sunmee", "can" ,"successed" , "fighting" };
	
	// �Ϲ����� �ݺ��� ǥ����� ����� words �����̳ʿ� ����
	// �����ڿ��� ��� ��Ʈ���� �μ��� ȣ���ؼ� out_iter1 ��Ʈ�� �ݺ��ڸ� �����Ѵ�. 
	std::ostream_iterator<string> out_iter1 { std::cout }; //��±����� ���� �ݺ���
    // �ݺ��ڸ� �������ؼ� word�� ���� ���� out_iter1�� �� ������ ����� ������ �ڿ� �ݺ��ڸ� ������Ų��. 
	
	for (const auto& word : words)
	{
		*out_iter1++ = word; //�ܾ� ����
		*out_iter1++ = " ";  //�����ڸ� ����
	}
	*out_iter1++ = "\n";     // �� ���� ����
	// out_iter1 = '\n'; ������ ���� �ʴ´�. �ݺ��ڰ� ��Ʈ���� string��ü�� ������ ���ǵǾ� �����Ƿ� 
	// �ٸ� Ÿ���� �����ʹ� �� �� ����. operateor=()����� ���ڿ� �μ��� �޾Ƶ��̹Ƿ� �� ������ ������ ���� �ʴ´�. 
	// operator*(), ���� ����, ���� ���� �����ڴ� �ݺ��ڿ� ���� ������ ��ȯ�ϴ� ���� �����ϸ� �ƹ��͵� ���� �ʴ´�. 
	// ���� �̷��� ������ �ʿ����� �ʰ� �� ��° ������ ���忡��ó�� �̷��� ������ ��� ���� ����� �� �� �ִ�. 
	for (const auto& word : words)
	{
		(out_iter1 = word) = " "; //�ܾ�� ������ ����
	}
	out_iter1 = "\n"; 
	// copy()�� ����� words �����̳ʿ� ���� 
	std::ostream_iterator<string> out_iter2 {std::cout, " " }; 
	std::copy(std::begin(words), std::end(words), out_iter2);
	out_iter2 = "\n";
}
