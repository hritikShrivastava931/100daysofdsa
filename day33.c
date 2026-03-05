#include<stdio.h>
#include<ctype.h>
#define MAX 100

char stack[MAX];
int top=-1;

void push(char x)
{
top++;
stack[top]=x;
}

char pop()
{
return stack[top--];
}

int precedence(char x)
{
if(x=='+'||x=='-')
return 1;
if(x=='*'||x=='/')
return 2;
if(x=='^')
return 3;
return 0;
}

int main()
{
char infix[MAX];
char postfix[MAX];
int i=0;
int k=0;

scanf("%s",infix);

while(infix[i]!='\0')
{
if(isalnum(infix[i]))
{
postfix[k]=infix[i];
k++;
}
else if(infix[i]=='(')
{
push(infix[i]);
}
else if(infix[i]==')')
{
while(stack[top]!='(')
{
postfix[k]=pop();
k++;
}
pop();
}
else
{
while(top!=-1 && precedence(stack[top])>=precedence(infix[i]))
{
postfix[k]=pop();
k++;
}
push(infix[i]);
}
i++;
}

while(top!=-1)
{
postfix[k]=pop();
k++;
}

postfix[k]='\0';

printf("%s",postfix);

return 0;
}