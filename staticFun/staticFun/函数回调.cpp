#include<iostream>
using namespace std;

class Baker
{
public:
	Baker();
	bool MakeCake();                     //������,��������˷���true�����򷵻�false
private:
	int m_iTime;                       //�������ʱ��
	static const int m_iMaxTime = 10; //����10��������
};

Baker::Baker():m_iTime(0){}

bool Baker::MakeCake()
{
	//����ÿ�ε��øú�����m_iTime+1
	m_iTime += 1;
	if (m_iTime == m_iMaxTime)
	{
		cout << "����������!" << endl;
		return true;
	}
	return false;
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
	while (1)
	{
		//�ͻ�������һʱ��֪��������û���ã��ͱ���ÿʱÿ�̲鿴��������
		if (baker.MakeCake())
		{
			GetMyCake();
			break;
		}
		else
			cout << "����û����" << endl;
	}
	system("pause");
	return 0;
}