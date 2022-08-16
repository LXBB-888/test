
#include"game.h"

void menu()
{
	printf("*********************************\n");
	printf("********   三子棋游戏    ********\n");
	printf("********     play:1      ********\n");
	printf("********     exit:0      ********\n");
	printf("*********************************\n");
}

void game()
{
	char board[ROW][COL];
	//初始化棋盘
	InitBoard(board, ROW, COL);

	//绘制棋盘
	DisplayBoard(board, ROW, COL);

	//开始游戏
	char ret = 0;//接受游戏状态
	while (1)
	{
		//玩家下棋
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret= IsWin(board, ROW, COL);
		if (ret != 'C')//没有游戏结束
			break;
		//电脑下棋
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')//没有游戏结束
			break;
	}
	if (ret == '*')
	{
		printf("玩家赢了\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢了\n");
	}
	else
	{
		printf("平局\n");
	}
	DisplayBoard(board, ROW, COL);


}

int main()
{
	srand((unsigned int)time(NULL));

	int input = 0;
	do
	{	
		menu();
		printf("请做出你的选择->");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			//printf("开始游戏\n");
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	}while (input);
	return 0;
}