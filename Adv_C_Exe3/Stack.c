#include <stdlib.h>
#include <stdio.h>
#include "Stack.h"

/***************** Stack ADT Implementation *****************/

void initStack(Stack* s)
{
	s->head = NULL;
}

void destroyStack(Stack* s)
{
	if (s->head->data) {
		return;
	}
	free(s->head->data);
	destroyStack(s->head->next);
}


void push(Stack* s, char data)
{
	charNode* newnode = (charNode*)malloc(sizeof(charNode));
	if (!newnode) {
		printf("memory allocation problem\n");
		return;
	}
	newnode->data = data;
	s->head = addToHead(s->head, newnode);
}

char pop(Stack* s)
{
	int res;
	res = s->head->data;
	removeItem(&(s->head));
	return (res);
}


int isEmptyStack(const Stack* s)
{
	if (s->head) {
		return 1;
	}
	return 0;
}

/*************** Functions using stacks - Implementation/definition **************************/


void flipBetweenHashes(const char* sentence)
{
	Stack* ptr_stk = NULL;
	ptr_stk = (Stack*)malloc(sizeof(Stack));
	charNode* tmp = NULL;
	int counter = 0;
	char* ptr_sentence = sentence;
	if (!ptr_stk) {
		printf("Memory allocation problem\n");
		exit(1);
	}
	if (!sentence) {
		return sentence;
	}
	
	while (*ptr_sentence != '\0') {
		if (*ptr_sentence == '#') {
			counter++;
		}
		ptr_sentence++;
	}
	if ((counter % 2) || !(counter)) {
		printf("Odd number of '#'\n");
		return;
	}
	while (sentence != '\0') {
		if (*sentence == '#') {
			sentence++;
			counter = 0;
			while (*sentence != '#') {
				push(ptr_stk, *sentence);
				sentence++;
				counter++;
			}
	        tmp = ptr_stk->head;
			for (int i = 0; i < counter; i++) {
				printf("%c", tmp->data);
				tmp = tmp->next;
			}
			while (ptr_stk->head->data) {
				pop(ptr_stk);
			}
		}
		else {
			printf("%c", *sentence);
		}
		sentence++;
	}
}


int isPalindrome(Stack* s)
{
	// add your code here
}

void rotateStack(Stack* s, int n)
{
	// add your code here
}

charNode *addToHead(charNode* head, charNode* toAdd) {
	toAdd->next = head;
	head = toAdd;
	return head;
}

void removeItem(charNode** head) {
	if (*head == NULL) {
		return; //If stack is empty
	}
	charNode* tmp = *head;
	*head = (*head)->next;
	free(tmp);
}