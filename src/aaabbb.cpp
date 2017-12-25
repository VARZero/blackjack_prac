#include <stdio.h>
#include <stdlib.h>
#include <time.h>
class cards
{
//카드 관련 클래스
public:
	unsigned short card();
private:
	bool cardl[4][13];
}cs;
unsigned short cards::card()
{
	//카드 뽑기
	srand((unsigned)time(NULL));
	unsigned int t=rand()%4;
	unsigned int n=rand()%13;
	if (!cardl[t][n]==1)
	{
		cardl[t][n]=1;
		printf("%d %d %d\n",t+1,n+1,cardl[t][n]);
		return n+1;
	}
	else {return cards::card();}
}
void rule_game()
{
	//게임의 룰
	short a=0;
	printf("다시 뽑겠습니까?\n1을 입력해서 다시 뽑을 수 있습니다.\n");
	scanf("%d",$a);
	if (a==1)
	{
		//다시 뽑기
		user_sum+=cs.cards();
	}
	else
	{
		//끝내기

	}
}

int main()
{
	unsigned short user_sum=0; //유저 수의 합
	unsigned short com_sum=0; //컴퓨터 수의 합
	user_sum+=cs.card();
	rule_game();
	return 0;
}
