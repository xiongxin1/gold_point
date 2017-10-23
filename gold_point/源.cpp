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
	cout << "请输入玩家个数(最多10人):";
	cin >> player;
	if (player > 10 || player <= 0)
	{
		cout << "输入有误！" << endl;
		exit(0);
	}
	for (int i = 0; i < player; i++)
	{
		double j = 0;
		double k = 0;
		cout << "请第" << (i + 1) << "位玩家输入数字(0-100)，按回车结束：";
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
		//cout << getfig[i] << endl;//测试代码
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
	//cout << sum << endl;//测试代码
	G = average*GOLD_POINT;
	//cout << G << endl;//测试代码
	Winer(G);
}
void Gold::Winer(double G)
{
	int k = 0;
	double min = 0;
	for (int i = 0; i < player; i++)
	{
		dev[i] = fabs(getfig[i] - G);
		//cout << dev[i] << "  " << endl;//测试代码
	}
	min = dev[0];
	for (int j = 0; j < player; j++)
	{
		if (min > dev[j])
		{
			min = dev[j];		//找到最小值
		}
	}
	//cout <<"最小值："<< min << endl;//测试代码
	for (int j = 0; j < player; j++)
	{
		if (min == dev[j])
		{
			winer[k++] = j + 1;//获胜者为多人的情况也可以判断
			score[j] += 2;
		}
	}
	for(int i=0;i<player;i++)
	{ 
		if (winer[i] == 0)
			break;
		cout << winer[i] << "号玩家获胜,获得2分" << endl;
	}
}
void main()
{
	Gold gold;
	char i;
	do
	{
		gold.Get_Figure();
		cout << "是否继续游戏是—y,否—n" << endl;
		cin >> i;
		system("cls");
	} while (i == 'y' || i == 'Y');
	for (int j = 0; j < player; j++)
	{
		cout << (j + 1) << "号玩家获得" << score[j] << "分" << endl;
	}
}