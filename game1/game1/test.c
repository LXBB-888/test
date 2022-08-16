
#include"game.h"

void menu()
{
	printf("******************************\n");
	printf("******    1. play        *****\n");
	printf("******    0. exit        *****\n");
	printf("******************************\n");
}

void game()
{
	char board [ROW][COL];
	//初始化棋盘 - 初始化空格
	InitBoard(board, ROW, COL);

	//画出棋盘
	DisplayBoard(board, ROW, COL);
	char ret = 0;//接受游戏状态

	while (1)
	{
		//玩家下棋
		PlayMover(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断玩家是否赢得游戏
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;

		//电脑下棋
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		IsWin(board, ROW, COL);
		//判断电脑是否赢得游戏
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
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
		printf("请选择->");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏");
			break;
		default:
			printf("输入错误，请重新输入：");
			break;
		}

	} while (input);
	return 0;
}