#include<iostream>
#include<conio.h>
#include<math.h>
#define N 10
#define GOLD_POINT 0.618
static int score[N] = { 0,0,0,0,0,0,0,0,0,0 };
static int player = 0;
using namespace std;

class Gold
{
private:
	int winer[N] = { 0 };
	double getfig[N] = { 0 };
	double dev[N] = { 0 };		  //dev[i]=getfig[i]-G
	double G = 0;			 //G=average*0.618
	double average = 0;
public:
	Gold() {};
	void Get_Figure();
	void Get_G(double getfig[]);
	void Winer(double);
	~Gold() {};
};
void Gold::Get_Figure()
{
	double figure;
	cout << "��������Ҹ���(���10��):";
	cin >> player;
	if (player > 10 || player <= 0)
	{
		cout << "��������" << endl;
		exit(0);
	}
	for (int i = 0; i < player; i++)
	{
		double j = 0;
		double k = 0;
		cout << "���" << (i + 1) << "λ�����������(0-100)�����س�������";
		while((figure = _getch())!=13)
		{
			//cout << (figure - 48) << endl;
			if(j==0)
			{
				j = figure - 48;
				cout << '*';
			}
			else
			{
				k = figure - 48;
				cout << '*';
			}
		}
		cout << endl;
		figure = j * 10 + k;
		//cout << figure;
		getfig[i] = figure;
		//cout << getfig[i] << endl;//���Դ���
	}
	Get_G(getfig);
}
void Gold::Get_G(double getfig[])
{
	double sum=0;
	for (int i = 0; i < player; i++)
	{
		sum += getfig[i];
	}
	average = sum / player;
	//cout << sum << endl;//���Դ���
	G = average*GOLD_POINT;
	//cout << G << endl;//���Դ���
	Winer(G);
}
void Gold::Winer(double G)
{
	int k = 0;
	double min = 0;
	for (int i = 0; i < player; i++)
	{
		dev[i] = fabs(getfig[i] - G);
		//cout << dev[i] << "  " << endl;//���Դ���
	}
	min = dev[0];
	for (int j = 0; j < player; j++)
	{
		if (min > dev[j])
		{
			min = dev[j];		//�ҵ���Сֵ
		}
	}
	//cout <<"��Сֵ��"<< min << endl;//���Դ���
	for (int j = 0; j < player; j++)
	{
		if (min == dev[j])
		{
			winer[k++] = j + 1;//��ʤ��Ϊ���˵����Ҳ�����ж�
			score[j] += 2;
		}
	}
	for(int i=0;i<player;i++)
	{ 
		if (winer[i] == 0)
			break;
		cout << winer[i] << "����һ�ʤ,���2��" << endl;
	}
}
void main()
{
	Gold gold;
	char i;
	do
	{
		gold.Get_Figure();
		cout << "�Ƿ������Ϸ�ǡ�y,��n" << endl;
		cin >> i;
		system("cls");
	} while (i == 'y' || i == 'Y');
	for (int j = 0; j < player; j++)
	{
		cout << (j + 1) << "����һ��" << score[j] << "��" << endl;
	}
}