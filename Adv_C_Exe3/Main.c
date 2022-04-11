#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include "Queue.h"

void main()
{
	Stack* s = NULL;
	const char check[27] = "Remem#reb# thi#carp s#tice";
	char sentence[5] = "noon";
	s = (Stack*)malloc(sizeof(Stack));
	if (!s) {
		printf("memory allocation problem\n");
		exit(1);
	}int i;
	push(s, '\0');
	for (i = 0; sentence[i] != '\0'; i++) {
		push(s, sentence[i]);
	}

	isPalindrome(s);
	flipBetweenHashes(check);


}