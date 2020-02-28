#include<stdio.h>
#include<iostream>

class CircularQueue{
private: int a[5], f, r;

public: CircularQueue(): f(0), r(-1) {}

void enqueue(int n){
	//printf("\nr=%d\tf=%d",r,f);
	if (r == 4 && f != 0)	r = -1;
	else if (r == 4 && f == 0)	printf("\nQueue is full!");
	a[++r] = n;
}

int dequeue(){
	int n = a[f];
	
	if(f == 0 && r == -1){
		printf("\nQueue is empty!");
		n = -3245617;
	}	
	else if(f == r){
		f = 0;
		r = -1;
	}
	else if ( f == 4 ) f = 0;
	else f++;
	
	return n;
}

void show(){
	if(f == 0 && r == -1) printf("\nEmpty Queue");
	else{
		if(f <= r) {
			//printf("\nIn if of show()\tf = %d\tr = %d",f,r);
		    printf("\n[ ");
			for(int i=f;i<=r;i++)
			    printf("%d, ",a[i]);
			printf("\b\b ]");
		}
		else{
			//printf("\nIn else of show()\tf = %d\tr = %d",f,r);
		    printf("\n[ ");
			for(int i=f;i<=4;i++)
			    printf("%d, ",a[i]);
			for(int i=0;i<=r;i++)
			    printf("%d, ",a[i]);
			printf("\b\b ]");
		}
	}
}

};

int main(){
CircularQueue cq;
printf("\nEnqueue: 5");
cq.enqueue(5);
cq.show();
printf("\nEnqueue: 10");
cq.enqueue(10);
printf("\nEnqueue: 7");
cq.enqueue(7);
cq.show();
printf("\nDequeue: %d",cq.dequeue());
cq.show();
printf("\nEnqueue: 7");
cq.enqueue(7);
printf("\nEnqueue: 8");
cq.enqueue(8);
cq.show();
printf("\nEnqueue: -2");
cq.enqueue(-2);
cq.show();
printf("\nDequeue: %d",cq.dequeue());
cq.show();
printf("\nEnqueue: 12");
cq.enqueue(12);
cq.show();

printf("\nDequeue: %d",cq.dequeue());
cq.show();

printf("\nDequeue: %d",cq.dequeue());
cq.show();

printf("\nEnqueue: 6");
cq.enqueue(6);
cq.show();

//cq.show();
}
