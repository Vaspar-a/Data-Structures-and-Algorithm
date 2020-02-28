#include<stdio.h>
#include<iostream>

class Stack{
private: char a[100];
		 int top;

public:
	Stack(): top(-1){}

public: void push(int n){
if(top < 0) top = -1;
a[++top] = n;
}

public: char pop(){
return a[top--];
}

public: char peek(){
return a[top];
}

public: void show(){
/*int i=0;
while(a[i]!='\0'){
printf("%c",a[i]);
i++;
}
*/
printf("\n%s",a);
}

};

int f(char ch){
if(ch=='#') return 0;
else if(ch=='+' || ch=='-') return 1;
else if(ch=='*' || ch=='/') return 2;
else if(ch=='^') return 3;
else return 4;
}

int main(){
Stack s,out;
int i=0;
s.push('#');

char exp[100];

scanf("%s",exp);

//printf("%d",sizeof(exp));
//printf("%s", exp);
while(exp[i]!='\0'){
    while(f(exp[i])<f(s.peek())) out.push(s.pop());
    s.push(exp[i]);
    i++;
}

while(s.peek()!='#'){
    //printf("%c\n",s.pop());
    out.push(s.pop());
}
//out.pop();
out.show();

return 0;
}
