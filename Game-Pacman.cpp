#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

bool gameOver = false;
int x, y, fruitX, fruitY, score, life;
int height = 9;
int width = 17;
char peta[9][18] =	 	{	"########=########",
							"#@# #!   !#!    #",
							"#    #   !##! ! #",
							"# ## !#  ##!  # #",
							"= !#      !# #! =", 
							"#  # !#!        #", 
							"# !    ! #! #   #", 
							"#   #!   !  !# !#",
							"########=########"};
enum direction{stop = 0, left, up, right, down};
direction dir;

void setup(){
	x = 1;
	y = 1;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
	life = 3;
}

void map(){
	system("cls");
	if(life < 1){
		gameOver = true;
	}
	for(int i = 0; i < height; i++){
		printf("%s\n", peta[i]);
	}
	printf("Life = %d\n", life);
	printf("Score = %d\n", score);
}

void input(){
	if(kbhit()){
		char c = getch();
		switch(c){
			case 'a':
				dir = left;
				break;
			case 'w':
				dir = up;	
				break;
			case 's':
				dir = down;
				break;
			case 'd':
				dir = right;
				break;
			default:
				gameOver = true;
				break;
		}	
	}
}

void move(){
	switch(dir){
		case left:
			x--;
			break;
		case right:
			x++;
			break;
		case up:
			y--;
			break;
		case down:
			y++;
			break;
		default:
			break;
	}
	if(peta[y][x] == '#'){
		switch(dir){
			case left:
				x++;
				break;
			case right:
				x--;
				break;
			case up:
				y++;
				break;
			case down:
				y--;
				break;
			default:
				break;
		}
	}else if(peta[y][x] == '='){
		switch(dir){
			case left:
				x+=15;
				peta[y][x] = '@';
				peta[y][1] = ' ';
				break;
			case right:
				x-=15;
				peta[y][x] = '@';
				peta[y][15] = ' ';
				break;
			case up:
				y+=7;
				peta[y][x] = '@';
				peta[1][x] = ' ';
				break;
			case down:
				y-=7;
				peta[y][x] = '@';
				peta[7][x] = ' ';
				break;
			default:
				break;
		}
	}else if(peta[y][x] == '!'){
		life--;
		switch(dir){
			case left:
				peta[y][x] = '@';
				peta[y][x+1] = ' ';
				break;
			case right:
				peta[y][x] = '@';
				peta[y][x-1] = ' ';
				break;
			case up:
				peta[y][x] = '@';
				peta[y+1][x] = ' ';
				break;
			case down:
				peta[y][x] = '@';
				peta[y-1][x] = ' ';
				break;
			default:
				break;
		}
	}else{
		switch(dir){
			case left:
				peta[y][x] = '@';
				peta[y][x+1] = ' ';
				break;
			case right:
				peta[y][x] = '@';
				peta[y][x-1] = ' ';
				break;
			case up:
				peta[y][x] = '@';
				peta[y+1][x] = ' ';
				break;
			case down:
				peta[y][x] = '@';
				peta[y-1][x] = ' ';
				break;
			default:
				break;
		}
	}
}


int main(){
	setup();
	while(!gameOver){
		map();
		input();
		move();
		Sleep(80);
	}
	
	return 0;
}
