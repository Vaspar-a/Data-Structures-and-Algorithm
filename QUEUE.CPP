#include<stdio.h>
#include<iostream>

class Queue{
private: int a[100],f=0,r=-1;

public: void enqueue(int n){
a[++r] = n;
//if(r>=0) f = 0;
}

public: int dequeue(){
return a[f++];
}

public: void show(){
printf("\n[ ");
for(int i=f;i<=r;i++)
    printf("%d, ",a[i]);
printf("\b\b ]");
}

};


int main(){
Queue q;

printf("\nEnqueue: 5");
q.enqueue(5);
printf("\nEnqueue: 10");
q.enqueue(10);
printf("\nEnqueue: 7");
q.enqueue(7);
q.show();
printf("\nDequeue: %d",q.dequeue());
q.show();
printf("\nEnqueue: 7");
q.enqueue(7);
printf("\nEnqueue: 8");
q.enqueue(8);
q.show();
printf("\nEnqueue: -2");
q.enqueue(-2);
printf("\nEnqueue: 12");
q.enqueue(12);
q.show();

printf("\nDequeue: %d",q.dequeue());
q.show();

printf("\nDequeue: %d",q.dequeue());
q.show();

printf("\nEnqueue: 6");
q.enqueue(6);
q.show();

//cq.show();
}
