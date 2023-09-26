#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

bool gameOver = false;
int x, y, fruitX, fruitY, tail, tailX, tailY;
int height = 25;
int width = 25;
int score = 0;

enum direction {stop = 0, left, right, up, down};
direction dir;

void start() {
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	tail = 0;
}

void map() {
	system("cls");
	
	for(int i = 0; i < width; i++) {
		printf("#");
	}
	printf("\n");
	
	for(int i = 0; i < height; i++) {
		for(int j = 0; j < width; j++) {
			if(j == 0 || j == width-1) {
				printf("#");
			}else if(i == fruitY && j == fruitX) {
				printf("F");
			}else if(i == y && j == x){
				printf("O");
			}else{
				printf(" ");
			}
		}
		printf("\n");
	}
	
	for(int i = 0; i < width; i++) {
		printf("#");
	}
	printf("\nScore : %d", score);
}

void input() {
	if(kbhit()) {
		char c = getch();
		switch(c){
			case 'a':
				dir = left;
				break;
			case 'w':
				dir = up;
				break;
			case 'd':
				dir = right;
				break;
			case 's':
				dir = down;
				break;
			case 'x':
				gameOver = true;
		}
	}
}

void move() {
	switch(dir){
		case left:
			x--;
			break;
		case up:
			y--;
			break;
		case right:
			x++;
			break;
		case down:
			y++;
			break;
		default:
			break;
	}
	if(x <= 0 || x >= width || y < 0 || y >= height){
		gameOver = true;
	}else if(x == fruitX && y == fruitY) {
		score += 10;
		fruitX = rand() % width;
		fruitY = rand() % height;
		tail++;
	}
}

int main() {
	start();
	while (!gameOver) {
		map();
		input();
		move();
		Sleep(80);
	}
	
}
