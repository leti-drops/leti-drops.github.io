#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SZ 501

struct stackel
{
	char br;
	struct stackel* prev;
};

void push(struct stackel** head, char br)
{
	struct stackel* next = malloc(sizeof(struct stackel));
	next->prev = *head;
	next->br = br;
	*head = next;
}
char pop(struct stackel** head)
{
	char val = (*head)->br;
	struct stackel* prev_head = *head;
	*head = (*head)->prev;
	free(prev_head);
	return val;
}
int isempty(struct stackel** head)
{
	return !*head;
}

int isbracket_open(char c){ return c == '(' || c == '[' || c == '{' || c == '<'; }
int isbracket_close(char c){ return c == ')' || c == ']' || c == '}' || c == '>'; }
int match_brackets_co(char c, char d)
{
	switch(c)
	{
		case ')': return d == '(';
		case ']': return d == '[';
		case '}': return d == '{';
		case '>': return d == '<';
	}
	return 1;
}

int main()
{
	char buf[BUF_SZ];
	fgets(buf, BUF_SZ, stdin);

	struct stackel* head = NULL;

	for(char* buf_it = buf; *buf_it; ++buf_it)
	{
		if(isbracket_open(*buf_it))
			push(&head, *buf_it);
		else if(isbracket_close(*buf_it))
		{
			if(isempty(&head)){
				printf("wrong");
				return 0;
			}
			char br = pop(&head);
			if(!match_brackets_co(*buf_it, br)){
				printf("wrong");
				return 0;
			}
		}
	}
	if(!isempty(&head)){
		printf("wrong");
	}
	else{
		printf("correct");
	}
	return 0;
}
