#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int** array;

void printA(int hang, int cot) {
	int a = 1;
	for (int i = 0; i < hang; i++) {
		for (int j = 0; j < cot; j++) {
			array[i][j] = 0;
		}
	}
	return;
}

void printB(int hang, int cot) {
	int a = 1;
	for (int i = 0; i < hang; i++) {
		for (int j = 0; j < cot; j++) {
		
			printf("array[% d][% d] = %d \n", i, j, array[i][j]);
		}
	}
	return;
}

int ngang(int hang, int cot, int o) {
	int cout = 1;
	for (int i = 0; i < hang ; i++) {
		for (int j = 0; j < cot - 1; j++) {
			if (array[i][j] == array[i][j + 1] && array[i][j] != 0) {
				cout++;
			}
			else {
				cout = 1;
			}
			if (cout == o) {
				printf("array[%d][%d] = %d\n", i, j+1, array[i][j]);
				return array[i][j+1];
			}
		}
		cout = 1;
	}
	return 0;
}

int doc(int hang, int cot, int o) {
	int cout = 1;
	for (int i = 0; i < cot  ; i++) {
		for (int j = 0; j < hang - 1; j++) {
			if (array[j][i] == array[j + 1][i] && array[j][i] != 0) {
				cout++;
			}
			else {
				cout = 1;
			}
			if (cout == o) {
				printf("array[%d][%d] = %d\n", j, i , array[j][i]);
				return array[j][i];
				}
		}
		cout = 1;
	}
	return 0;
}

int cheo_trai(int hang, int cot, int o) {
	int cout = 1;
	int t = 0;
	for (int i = 0; i < hang - 1; i++) {
		for (int j = 0; j < cot - 1; j++) {
			if (t + 1 <= hang - 1 && j + 1 <= cot - 1) {
				if (array[t][j] == array[t + 1][j + 1] && array[t][j] != 0)
				{
					cout++;
				}
			
			    else {
				cout = 1;
			}
				}
			if (cout == o)
			{
				return array[t][j];
			}
			t++;
		}
		t = i;
		cout = 1;
	}
	return 0;
}

int cheo_phai(int hang, int cot, int o) {
	int t = 0;
	int cout = 1;

	for (int i = 0; i < hang - 1; i++) {
		for (int j = cot - 1; j > 0; j--) {
		 if (t+1 <= hang -1 && j -1 >=0)
			if (array[t][j] == array[t+1][j-1] && array[t][j] != 0) {
				cout++;
			}
			else {
				cout = 1;
			}
		 if (cout == o) {
			 return array[t][j];
		 }
			t++;
		}
		t = i;
		cout = 1;
	}
	return 0;
}

void Chedo(int& hang, int& cot, int& o) {
	printf("Hang:");
	scanf("%d", &hang);
	printf("Cot:");
	scanf("%d", &cot);
	printf("O:");
	scanf("%d", &o);
	for (int i = 0; i < hang; i++) {
		for (int j = 0; j < cot; j++) {
			printf("(%d %d)", i, j);
		} printf("\n");
	}
	return;
}

void screen(int hang, int cot, int o) {
	for (int i = 0; i < hang; i++) {
		for (int j = 0; j < cot; j++) {
			if (array[i][j] == 120 || array[i][j] == 111) {
				printf("( %c )", array[i][j]);
			}

			else {
				printf("(%d %d)", i, j);
			}
		}
		printf("\n");
	}
}

int check(int hang, int cot, int o) {
	int row = hang;
	int col = cot;
	int win = o;
	int winner[4];


	winner[0] = ngang(row, col, win);
	winner[1] = doc(row, col, win);
	winner[2] = cheo_trai(row, col, win);
	winner[3] = cheo_phai(row, col, win);
	
	for (int i = 0; i < 4; i++) {
		if (winner[i] != 0) {
			return winner[i];
		}
	}


	return 0;


}

#define X 120
#define O 111


int main() {
	int hang = 0, cot = 0, o = 0;
	int winner = 0;
	Chedo(hang, cot, o);

	array = new int* [hang];
	for (int i = 0; i < hang; i++)
		array[i] = new int[cot];
	printA(hang, cot);

	int turn = X;
	while (winner == 0) {
		int x, y;
		if (turn == X) {
			printf("Nhap X:");
			scanf("%d %d", &x, &y);
			array[x][y] = X;
			turn = O;
		}

		else {
			printf("Nhap O:");
			scanf("%d %d", &x, &y);
			array[x][y] = O;
			turn = X;
		}
		system("cls");
		screen(hang, cot, o);
		winner = check(hang, cot, o);
	
	}
	printf("\n WINNER = %c \n", winner);
	printf("WINNER = %d", winner);
}