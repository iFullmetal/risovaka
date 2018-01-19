#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <windows.h>
SHORT keyPressed(int key) {
	return GetAsyncKeyState(key);
}
int paint_x = 0;
int paint_y = 0;
int map[7][5];
void gotoxy(int x, int y)
{
	COORD p = { x,  y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

void paintMove(int x, int y) {


	paint_x += x;
	paint_y += y;

}
void mapInside() {
	for (int i = 0; i < 7; i++) {

		for (int j = 0; j < 5; j++) {
			
			if (i == paint_x && j == paint_y) {
				map[i][j] = 0;
			}
		}
	}

}
void markIt(int x, int y) {
	map[x][y] = 1;

}
void draw() {
	system("cls");
	for (int i = 0; i < 7; i++) {

		for (int j = 0; j < 5; j++) {
			if (map[i][j] == 0) {
				printf(" ");
			}

			if (i == paint_x && j == paint_y) {
				printf("O");
				if (keyPressed(VK_SPACE)) {
					markIt(i, j);
				}
				if (map[i][j] == 1) {
					printf("#");
				}
			}
		}
		printf("\n");
	}

}
void main() {
	
	

	while (1) {
		draw();
		if (keyPressed(VK_DOWN)) {
			paintMove(1, 0);
		}
		else if (keyPressed(VK_RIGHT)) {
			paintMove(0, 1);
		}
		else if (keyPressed(VK_LEFT)) {
			paintMove(0, -1);
		}
		else if (keyPressed(VK_UP)) {
			paintMove(-1, 0);
		}
		
	}



	system("pause");
}