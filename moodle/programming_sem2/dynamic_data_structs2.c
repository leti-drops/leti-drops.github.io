#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SZ 501

struct stack
{
	char* data;
	size_t data_sz;
};

void init(struct stack* st)
{
	st->data = NULL;
	st->data_sz = 0;
}
void push(struct stack* st, char br)
{
	st->data_sz++;
	st->data = realloc(st->data, st->data_sz * sizeof(char));
	st->data[st->data_sz-1] = br;
}
char pop(struct stack* st)
{
	char r = st->data[st->data_sz-1];
	st->data_sz--;
	st->data = realloc(st->data, st->data_sz * sizeof(char));
	return r;
}
int isempty(struct stack* st)
{
	return st->data_sz == 0;
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

	struct stack st;
	init(&st);

	for(char* buf_it = buf; *buf_it; ++buf_it)
	{
		if(isbracket_open(*buf_it))
			push(&st, *buf_it);
		else if(isbracket_close(*buf_it))
		{
			if(isempty(&st)){
				printf("wrong");
				return 0;
			}
			char br = pop(&st);
			if(!match_brackets_co(*buf_it, br)){
				printf("wrong");
				return 0;
			}
		}
	}
	if(!isempty(&st)){
		printf("wrong");
	}
	else{
		printf("correct");
	}
	return 0;
}
