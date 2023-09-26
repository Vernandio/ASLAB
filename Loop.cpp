#include <stdio.h>

int main() {
	int a;
	
	scanf("%d", &a);
	getchar();
	
	printf("Segitiga 1\n");
	for(int i = 0; i < a; i++) {
		for(int j = i; j < a; j++) {
			printf("*");
		}	
		printf("\n");
	}
	printf("\n\n");
	
	printf("Segitiga 2\n");
	for(int i = a; i > 0; i--) {
		for(int j = a+1; j > i; j--){
			printf("*");
		}
		printf("\n");
	}
	printf("\n\n");
	
	printf("Segitiga 3\n");
	for(int i = 0; i < a; i++) {
		for(int j = i+1; j < a; j++) {
			printf(" ");
		}
		for(int j = a; j >= a-i; j--){
			printf("*");
		}
		printf("\n");
	}
	printf("\n\n");
	
	printf("Segitiga 4\n");
	for(int i = 0; i < a; i++) {
		for(int j = 0; j < i; j++){
			printf(" ");
		}
		for(int j = i; j < a; j++) {
			printf("*");
		}
		printf("\n");
	}
	printf("\n\n");
	
	printf("Segitiga 5\n");
	for(int i = 1; i <= a; i++) {
		for(int j = i; j < a; j++){
			printf(" ");
		}
		for(int j = 0; j < (i*2)-1; j++) {
			printf("*");
		}
		printf("\n");
	}
	printf("\n\n");
	
	printf("Segitiga 6\n");
	for(int i = 0; i < a; i++) {
		for(int j = 0; j < i; j++){
			printf(" ");
		}
		for(int j = i*2; j < a*2-1; j++){
			printf("*");
		}
		printf("\n");
	}
	printf("\n\n");
	
}
