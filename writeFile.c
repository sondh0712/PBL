#include <stdio.h>
#include <string.h>
#include <stdlib.h>



void writeFile(char* fullPath,char* mode) {

	FILE* fp;

	fp = NULL;

	fopen_s(&fp, fullPath, mode);


	if (fp == NULL) {
		printf("���Ͽ��� ����\n");
		return;
	}
	else {
		printf("input String:");
		char buff[100];
		get_s(buff, 100);
		fputs(buff, fp); //Ű���� �������
		fputc('\n', fp);// \n���
	}

	if (fclose(fp) != 0) {
		printf("file close failde at writeFile()\n");
		return;
	}
}