

#include "game.h"

void menu()
{
	printf("***********************\n");
	printf("******   1:piay  ******\n");
	printf("******   0:exit  ******\n");
	printf("***********************\n");
}

void game()
{
	//ɨ����Ϸ
	char mine[ROWS][COLS] = { 0 };//������
	char show[ROWS][COLS] = { 0 };//�Ų���

	//��ʼ������
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');

	//��ӡ����
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);

	//������
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);

	//ɨ��
	FindMine(mine, show, ROW, COL);


}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));

	do
	{
		menu();
		printf("��ѡ��:>");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			//printf("ɨ��\n");
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}

	} while (input);
		return 0;
}