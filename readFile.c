#include<stdio.h>
#include <string.h>
#include <stdlib.h>

void readFile(char* fullPath, char* mode, char* buff) {
    
    FILE* fp;
    fp = NULL;

    fopen_s(&fp, fullPath, mode);
    if (fp == NULL) {
        printf("file open failed at readFile()\n");
        return;


    }
    else
    {
        char temp[100];
        while (fgets(temp,100,fp) != NULL)
        {
            strcat_s(buff, 100, temp);
        }
    }

    if (fclose(fp) != 0) {
        printf("file close readFile()");
        return;
    }
}