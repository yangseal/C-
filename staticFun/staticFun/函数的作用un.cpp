#include<iostream>
using namespace std;

//����pcall���ֺ���ָ�������
typedef int(*pcall)(int, int);

//������������һ��pcall���͵ĺ�����Ϊ����
void func(pcall p, int x, int y)
{
	cout << "begin func:" << endl;
	cout << "result is :" << p(x, y) << endl;
	cout << "end func "   <<  endl;
}

//�ӷ�����
int AddFUnc(int x, int y)
{
	return x + y;
}

//��������
int SubFunc(int x, int y)
{
	return x - y;
}

int main()
{
	//������ָ����Ϊ�������ݸ�����
	//&���ſ���ʡ��
	func(&AddFUnc, 2, 1);
	func(&SubFunc, 2, 1);
	system("pause");
	return 0;
}