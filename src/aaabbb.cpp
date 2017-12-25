#include <stdlib.h>
#include <time.h>
#include <string>
#include <iostream>
using namespace std;
class ai
{
private:
	short per[6]={6,5,4,3,2,1};
	bool ch=0;
public:
	bool ai_l_c(short sum);
	bool chc()
	{
		return ch;
	}
};
bool ai::ai_l_c(short sum)
{
	if (sum>21)
	{
		ch=1;
		cout <<"컴퓨터는 버스트 되었습니다.\n";
		return 1;
	}
	sum-=21;sum*=-1;
	short pers=rand()%7;
	if (sum<5 and pers<=per[sum])
	{
		ch=1;
		cout <<"컴퓨터는 추가카드를 요청하지 않았습니다.\n";
		return 1;
	}
	return 0;
}
class cards
{
//카드 관련 클래스
public:
        unsigned short card(bool x);
private:
        bool cardl[4][13];
};
unsigned short cards::card(bool x)
{
        //카드 뽑기
        unsigned int t=rand()%4;
        unsigned int n=rand()%13;
        string tt;
        if (cardl[t][n]!=1)
        {
                cardl[t][n]=1;
                switch(t)
                {
                	case 0:tt="스페이드";break;
                	case 1:tt="클로버";break;
                	case 2:tt="하트";break;
                	case 3:tt="다이아몬드";break;
                }
                if (x==0)
                {
                	cout << tt << " " << n+1 << "\n" ;
                }
                return n+1;
        }
        else {return cards::card(x);}
}
short check(unsigned short sum1,unsigned short sum2)
{
	if (sum1<=21 and sum2<=21)
	{
		if (sum1!=sum2) {return sum1>sum2;}
		else {return 2;}
	}
	return 3;
}
void rule_game()
{
	cout <<"================================\n";
    //게임의 base
	ai cai;
	cards cs;
	unsigned short com_sum=0;
    unsigned short user_sum=0; //유저 수의 합
    int a=1;
    while(1)
    {
        if (a==1)
        {
            //다시 뽑기
        	user_sum+=cs.card(0);
        	if (user_sum>21)
        	{
        		cout << "당신은 버스트 되었습니다.\n";
        		cout <<"당신의 점수는: " << user_sum << " 컴퓨터의 점수는: " << com_sum << "\n당신은 패배하였습니다.\n";
        		break;
        	}
        	bool i=cai.ai_l_c(com_sum);
        	if (i!=1 or cai.chc()!=1)
        	{
        		com_sum+=cs.card(1);
        	}
        	cout << "다시 뽑겠습니까?\n1을 입력해서 다시 뽑을 수 있습니다.\n";
        	cin >>a;
        }
        else
        {
            //끝내기
        	cout <<"당신의 점수는: " << user_sum << " 컴퓨터의 점수는: " << com_sum << "\n";
        	switch(check(user_sum,com_sum))
        	{
        		case 0:
        		cout <<"당신은 패배하였습니다.\n";
        		break;
        		case 1:
        		cout <<"당신은 승리하였습니다.\n";
        		break;
        		case 2:
        		cout <<"무승부.\n";
        		break;
        		case 3:
        		cout <<"당신은 승리하였습니다.\n";
        		break;
        	}
        	break;
        }
    }
	cout <<"================================\n";
}
int main()
{
    srand((unsigned)time(NULL));
    short chg;
    while(1){rule_game();cout << "다시하시려면 1을 입력후 엔터를 눌러주세요."; cin >>chg; if (chg!=1) {break;}}
    return 0;
}
