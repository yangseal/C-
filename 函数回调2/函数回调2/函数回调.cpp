
#include <iostream>

using namespace std;

//����һ�ֻص�����
typedef void(*CallBackFunc)(void);

class Baker
{
private:
	int m_iTime;			  //�������ʱ��
	static const int m_iMaxTime = 10;//����10��������
	CallBackFunc m_pfCallBack;//�ص�����
public:
	//ע�᣺�����򵰸���˵���ϵ��ʽ
	void Invoke(CallBackFunc);
	//��绰֪ͨ�򵰸����
	void Notify();
	//�����⣬��������ˣ�ֱ��֪ͨ�ͻ�
	void MakeCake();
	//���캯��
	Baker();
};

Baker::Baker() : m_iTime(0){}

void Baker::MakeCake()
{
	while (m_iTime < m_iMaxTime)
	{
		//����ÿ�ε��øú�����m_iTime+1
		m_iTime += 1;
	}
	cout << "����������!" << endl;
	Notify();
}

void Baker::Invoke(CallBackFunc pfunc)
{
	//ע�����
	m_pfCallBack = pfunc;
	cout << "������������ϵ��ʽ!" << endl;
}

void Baker::Notify()
{
	if (m_pfCallBack)
		m_pfCallBack();
}


//�ͻ�����
void GetMyCake()
{
	cout << "����ȡ������!" << endl;
}

int main()
{
	//����һ�������
	Baker baker;
	//ע�᣺������ϵ��ʽ
	baker.Invoke(GetMyCake);
	//ע��֮�󣬿ͻ��Ͳ���Ҫʵʱ��ѯ��
	cout << "���˽��Ҿͺã���ȥ�����!" << endl;
	//������
	baker.MakeCake();

	system("pause");
	return 0;
}