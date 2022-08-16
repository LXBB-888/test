

#include "game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i=0; i< rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}

	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("-----------扫雷游戏------------\n");
	//打印列号
	for (j = 0; j <= col; j++)
	{
		printf("%d ", j);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);//打印行号
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void SetMine(char mine[ROWS][COLS], int row, int col)
{
	int sum = MINE;
	while (sum)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] == '0')// '0'--布置雷的棋盘初始化是字符0
		{
			mine[x][y] = '1';
			sum --;//依次要减少雷的个数啊
		}

	}
	
}

//显示周围一圈雷的个数
int ShowMine(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1] +
		mine[x][y - 1]  + mine[x][y + 1] +
		mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] - 8 * '0'; //字符转换为数字

}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < row * col - MINE)//排查出所有没雷的位置算赢
	{
		printf("请输入要排查的坐标：");
		scanf_s("%d%d", &x, &y);
		//判断坐标是否合法
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("有雷，爆炸了\n");
				break;
			}
			else//'0'
			{

				int count= ShowMine(mine, x, y);
				show[x][y] = count + '0'; //字符转换为数字
				DisplayBoard(show, row, col);//打印棋盘
				win++;
			}
		}
		else
		{
			printf("坐标不合法，请重新输入");
		}
		
	}
	if (win == row * col - MINE)
	{
		printf("恭喜你，排雷成功\n");
		DisplayBoard(mine, row, col);
	}

	

}