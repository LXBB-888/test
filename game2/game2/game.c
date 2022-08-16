

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
	printf("-----------ɨ����Ϸ------------\n");
	//��ӡ�к�
	for (j = 0; j <= col; j++)
	{
		printf("%d ", j);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);//��ӡ�к�
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
		if (mine[x][y] == '0')// '0'--�����׵����̳�ʼ�����ַ�0
		{
			mine[x][y] = '1';
			sum --;//����Ҫ�����׵ĸ�����
		}

	}
	
}

//��ʾ��ΧһȦ�׵ĸ���
int ShowMine(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1] +
		mine[x][y - 1]  + mine[x][y + 1] +
		mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] - 8 * '0'; //�ַ�ת��Ϊ����

}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < row * col - MINE)//�Ų������û�׵�λ����Ӯ
	{
		printf("������Ҫ�Ų�����꣺");
		scanf_s("%d%d", &x, &y);
		//�ж������Ƿ�Ϸ�
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("���ף���ը��\n");
				break;
			}
			else//'0'
			{

				int count= ShowMine(mine, x, y);
				show[x][y] = count + '0'; //�ַ�ת��Ϊ����
				DisplayBoard(show, row, col);//��ӡ����
				win++;
			}
		}
		else
		{
			printf("���겻�Ϸ�������������");
		}
		
	}
	if (win == row * col - MINE)
	{
		printf("��ϲ�㣬���׳ɹ�\n");
		DisplayBoard(mine, row, col);
	}

	

}