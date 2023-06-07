#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';


void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);

int main() {

	char winner = ' ';
	resetBoard();
	while (winner == ' ' && checkFreeSpaces() != 0)
	{
		printBoard();


		playerMove();
		winner = checkWinner();
		if (winner != ' ' || checkFreeSpaces() == 0) {
			break;
		}
		computerMove();
		winner = checkWinner();
		if (winner != ' ' || checkFreeSpaces() == 0) {
			break;
		}

	}
	printBoard();
	printWinner(winner);
	return 0;
}

void resetBoard() {		//보드
	for (int i = 0; i < 3;i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = ' ';
		}
	}
}
void printBoard() {			// 판 제작
	printf("| %c | %c | %c |", board[0][0], board[0][1], board[0][2]);
	printf("\n|---|---|---|\n");
	printf("| %c | %c | %c |", board[1][0], board[1][1], board[1][2]);
	printf("\n|---|---|---|\n");
	printf("| %c | %c | %c |", board[2][0], board[2][1], board[2][2]);
	printf("\n|---|---|---|\n");
	printf("\n");
}
int checkFreeSpaces() {		//빈 공간
	int freeSpaces = 9;
	for (int i = 0; i < 3;i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] != ' ') {
				freeSpaces--;
			}
		}
	}
	return freeSpaces;
}
void playerMove() {
	int x;
	int y;
	char input[10];

	do {
		printf("가로 입력하세요(1-3) : ");
		fgets(input, sizeof(input), stdin);
		x = atoi(input);

		printf("세로 입력하세요(1-3) : ");
		fgets(input, sizeof(input), stdin);
		y = atoi(input);

		x--;
		y--;

		if (x < 0 || x >= 3 || y < 0 || y >= 3) {
			printf("Invalid Move! 좌표 범위를 벗어났습니다.\n");
			continue;  // 입력 재시도
		}
		else if (board[x][y] != ' ') {
			printf("Invalid Move! 해당 위치는 이미 채워져 있습니다.\n");
			continue;  // 입력 재시도
		}
		else {
			board[x][y] = PLAYER;
			break;
		}
	} while (1);
}
void computerMove() {	//컴퓨터 랜덤 두기
	srand(time(0));
	int x;
	int y;

	if (checkFreeSpaces() > 0) {
		do {
			x = rand() % 3;
			y = rand() % 3;
		} while (board[x][y] != ' ');
	
		board[x][y] = COMPUTER;
	}
	else
	{
		printWinner(' ');
	}
}
char checkWinner() {		//한줄 승리 확인


	for (int i = 0; i < 3; i++) {	//가로 한줄 승리
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
			return board[i][0];
		}
	}
	for (int i = 0; i < 3; i++) {	//세로 한줄 승리
		if (board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
			return board[0][i];
		}
	}
									//대각선 한줄 승리
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
			return board[0][0];
	}
	if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
		return board[0][2];
	}
	return ' ';
	
}
void printWinner(char winner) {			//승패 확인
	if (winner == PLAYER) {
		printf("인간 승리!");
	}
	else if(winner == COMPUTER)
	{
		printf("컴퓨터 승리!");
	}
	else
	{
		printf("동점!");
	}
}
