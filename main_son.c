#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

int main() {
	char path[50];
	char fName[20];
	char mode[4];
	char fullPath[100];

	path[0] = '\0';
	fullPath[0] = '\0';

	strcat_s(path,50,"d:/");

	printf(">File Name:");
	gets_s(fName, 20);

	strcat_s(fullPath, 100, path);
	strcat_s(fullPath, 100, fName);

	//printf(">Full_Path:%s\n", fullPath);

	//�޴�����

	char buff[100];
	int menu_slt = 0;
	while (1)
	{
		printf("[Menu]\n");
		printf("1>���� ����\n2>���� �б�\n0>����\n");
		printf("select:");
		scanf_s("%d", &menu_slt);

		switch (menu_slt)
		{
		case 1:
			printf("���� ���� ���(w/w+/a/a+)\n");
			gets_s(mode, 4);
			writeFile(fullPath, mode);
			break;
		case 2:
			buff[0] = '\0';
			printf("���� �б� ���(r/r+/)\n");
			gets_s(mode, 4);
			readFile(fullPath, mode,buff);
			puts(buff);

			printf("press Enter_Key to continue....");
			break;
		case 0:
			exit(1);
			break;
		default:
			printf("�߸��� �޴��Դϴ�.\n");

		}




	}







}