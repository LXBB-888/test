
#include"game.h"

void menu()
{
	printf("*********************************\n");
	printf("********   ��������Ϸ    ********\n");
	printf("********     play:1      ********\n");
	printf("********     exit:0      ********\n");
	printf("*********************************\n");
}

void game()
{
	char board[ROW][COL];
	//��ʼ������
	InitBoard(board, ROW, COL);

	//��������
	DisplayBoard(board, ROW, COL);

	//��ʼ��Ϸ
	char ret = 0;//������Ϸ״̬
	while (1)
	{
		//�������
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret= IsWin(board, ROW, COL);
		if (ret != 'C')//û����Ϸ����
			break;
		//��������
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')//û����Ϸ����
			break;
	}
	if (ret == '*')
	{
		printf("���Ӯ��\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ��\n");
	}
	else
	{
		printf("ƽ��\n");
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
		printf("���������ѡ��->");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			//printf("��ʼ��Ϸ\n");
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	}while (input);
	return 0;
}