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

	//메뉴구성

	char buff[100];
	int menu_slt = 0;
	while (1)
	{
		printf("[Menu]\n");
		printf("1>파일 쓰기\n2>파일 읽기\n0>종료\n");
		printf("select:");
		scanf_s("%d", &menu_slt);

		switch (menu_slt)
		{
		case 1:
			printf("파일 쓰기 모드(w/w+/a/a+)\n");
			gets_s(mode, 4);
			writeFile(fullPath, mode);
			break;
		case 2:
			buff[0] = '\0';
			printf("파일 읽기 모드(r/r+/)\n");
			gets_s(mode, 4);
			readFile(fullPath, mode,buff);
			puts(buff);

			printf("press Enter_Key to continue....");
			break;
		case 0:
			exit(1);
			break;
		default:
			printf("잘못된 메뉴입니다.\n");

		}




	}







}