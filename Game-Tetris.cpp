#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	//start di V1 H7 end di V1 H14
	//paling bawah itu V20
	char map [25][25] = {
		"######################",
		"#      [][][][]      #",
		"#                    #",
		"#                    #",
		"#                    #",
		"#                    #",
		"#                    #",
		"#                    #",
		"#                    #",
		"#                    #",
		"#                    #",
		"#                    #",
		"#                    #",
		"#                    #",
		"#                    #",
		"#                    #",
		"#                    #",
		"#                    #",
		"#                    #",
		"#                    #",
		"#                    #",
		"######################"
	};
	bool game = true;
	int score = 0;
	char input;
	int start = 7;
	int end = 14;
	int v = 1;
	
//	for (int i = 0; i < 100; i++) {
//		printf("%d\n", rand() % 10 + 1);
//	}
	
	do{
		printf("Score = %d\n", score);
		for(int i = 0; i < 22; i++) {
			printf("%s\n", map[i]);
		}
		
		printf("Move\n");
		printf("Left\t= a\n");
		printf("Right\t= d\n");
		printf("Drop\t= s\n");
		
		printf("\nInput : ");
		scanf("%c", &input);
		
		if(input == 'A' || input == 'a') {
			if(map[v][start-2] != '#'){
				start -= 2;
				map[v][start] = map[v][start+2];
				map[v][start+1] = map[v][start+3];
				
			}
			if(map[1][start-2] != '#' && map[1][start-1] != '#') {
				start -= 2;
				end -= 2;
				map[1][start] = map[1][end-1];
				map[1][start+1] = map[1][end];
				map[1][end+2] = ' ';
				map[1][end+1] = ' ';
			}
		}else if(input == 'D' || input == 'd') {
			if(map[1][end+2] != '#' && map[1][end+1] != '#') {
				start += 2;
				end += 2;
				map[1][end] = map[1][start+1];
				map[1][end-1] = map[1][start];
				map[1][start-2] = ' ';
				map[1][start-1] = ' ';
			}
		}else if(input == 'S' || input == 's') {
			if(map[v+1][start] != '#' && map[v+1][end] != '#') {
				v++;
				map[v][end] = map[v-1][end];
				map[v][start] = map[v-1][start];
				map[v-1][end] = ' ';
				map[v-1][start] = ' ';
			}else{
				v = 1;
			}
		}else{
			printf("\nTOLONG INPUT SESUAI MOVE!\n");
		}
	} while (game == true);
	
	return 0;
}
