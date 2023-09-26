#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main() {
	char c;
	bool gameOver = false;
	
	while(!gameOver){
		if(kbhit()){
			c = getch();
			switch(c){
				case 'a':
					printf("Yang dipencet a\n");
					break;
				case 'w':
					printf("Yang dipencet w\n");
					break;
				case 'd':
					printf("Yang dipencet d\n");
					break;
				case 's':
					printf("Yang dipencet s\n");
					break;
				default:
					printf("EXIT");
					gameOver = true;
			}
		}
	}
}
