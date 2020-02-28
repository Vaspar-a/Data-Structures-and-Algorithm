#include<stdio.h>
#include<iostream>

class Stack{
private: int a[10],top;

public: 

Stack(): top(-1) {}

void push(int n){
	if(top >= -1 && top < 99) a[++top] = n;
	else if(top == 99) printf("\nStack Overflow");
}

int pop(){
	if(top >= 0) return a[top--];
	else{
		printf("\nStack Underflow");
		 return INT_MIN;
	}
}

void show(){
	printf("\n[ ");
	for(int i=0;i<=top;i++)
	    printf("%d, ",a[i]);
	printf("\b\b ]");
}

};

int main(){

Stack s1,s2,s3;

s1.push(3);
s1.push(2);
s1.push(1);

s1.show();

s3.push(s1.pop());
s2.push(s1.pop());
s2.push(s3.pop());

s3.push(s1.pop());

s1.push(s2.pop());
s3.push(s2.pop());
s3.push(s1.pop());

s3.show();
}
