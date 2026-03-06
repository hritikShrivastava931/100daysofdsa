#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node
{
int data;
struct Node* next;
};

struct Node* top = NULL;

void push(int value)
{
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = value;
newNode->next = top;
top = newNode;
}

int pop()
{
if(top == NULL)
{
printf("Stack Underflow");
exit(1);
}
int value = top->data;
struct Node* temp = top;
top = top->next;
free(temp);
return value;
}

int evaluate(char* exp)
{
char* token = strtok(exp," ");
while(token != NULL)
{
if(isdigit(token[0]))
{
push(atoi(token));
}
else
{
int b = pop();
int a = pop();
int result;

if(token[0] == '+')
result = a + b;

else if(token[0] == '-')
result = a - b;

else if(token[0] == '*')
result = a * b;

else if(token[0] == '/')
result = a / b;

push(result);
}

token = strtok(NULL," ");
}

return pop();
}

int main()
{
char expression[100];

printf("Enter postfix expression: ");
gets(expression);

int result = evaluate(expression);

printf("Result: %d", result);

return 0;
}