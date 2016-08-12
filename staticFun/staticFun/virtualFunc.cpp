#include<iostream>
using namespace std;

class Base
{
public:
	virtual void Print(int num)
	{
		cout << "base:" << num << endl;
	}

};

class Child:public Base
{
public:
		//���ǻ����Print����
	void  Print(int num)override
	{
		cout << "child:" << num << endl;
	}	 
};

//����һ����Ա����ָ��
typedef void (Base::*pFunc)(int);

int main()
{
	Base base;
	Child child;
	//������ָ�븳ֵ��ʱ�򣬱���������������ָ���������ֵ���˴�ΪBase��
	pFunc func = &(Base::Print);
	//ͨ��base������ú���ָ��
	(base.*func)(1);
	//ͨ��child������ú���ָ��
	(child.*func)(3);
	//�鿴����ָ��Ĵ�С
	cout << "sizeof Member Function :" << sizeof(func) << endl;
	system("pause");
	return 0;
}

/*
	������Ľ�������ǿ����������ʹ�ú���ָ���ʱ�����thisָ��Ķ��������������������ָ���ʱ��Ķ�������࣬����������Ǹ�д�˻���ĺ������ǿ��Ե�������ĺ����ģ�ע���Ǹ�д�����virtual���������ֻ�ǵ����ĸ�����û�ж�̬Ч���ģ�.�������������������ָ�룬����������ͨ����ָ��������һ��������thisָ����Ϊ����������β����ǿ�������Ϊ�����ָ�룬���Ǹ�ʵ�ε�ʱ�򣬿��Ը�����Ķ��󣬵�ȻҲ���Ը����������͸�������ͨ�������ݲ��������һ����Ȼ������������ݽ�ȥ�������virtual��������ô�Ϳ��Դ�����̬�����������ڸ�����ָ�븳ֵ��ʱ��ȴֻ��ʹ�û���ĺ�������Ϊ����û����������ĺ�����
	
*/