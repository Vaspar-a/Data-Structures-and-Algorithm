#include<stdio.h>
#include<stdlib.h>

int binarySearch(int *a,int k,int n){
	int h=0,t=n-1,m=(h+t)/2;
	if(k==*(a+h)) return h;
	else if(k==*(a+t)) return t;
	else{
		while(h<=t){
			if(*(a+m)==k) return m;
			else if(*(a+m)<k) h=m+1;
			else if(*(a+m)>k) t=m-1;
			m=(h+t)/2;
		}
	}
	return -1;
}

int linearSearch(int *a,int k,int n){
	int i;
	for(i=0;i<n;i++){
		if(*(a+i)==k)
			return i;
	}
	return -1;
}

int recBinarySearch(int *a,int k,int h=0,int t=5){
	int m=(h+t)/2;
	if(k==*(a+h)) return h;
	else if(k==*(a+t)) return t;
	else if(h<=t){
			if(*(a+m)==k) return m;
			else if(*(a+m)<k) recBinarySearch(a,k,m+1,t);
			else if(*(a+m)>k) recBinarySearch(a,k,h,m-1);
	}
	else return -1;
}

int recLinearSearch(int *a,int k,int n){
	if(k==*(a+n)) return n;
	else if(n>=0) return linearSearch(a,k,n-1);
	else return -1;
}

int main(){
	int i,n,k;
	printf("Enter size: ");
	scanf("%d",&n);
	int *p = (int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++){
		scanf("%d",(p+i));
	}
	printf("\nEnter key: ");
	scanf("%d",&k);
	printf("\nLinear Search: %d",linearSearch(p,k,n));
	printf("\nRec Linear Search: %d",recLinearSearch(p,k,n));
	
	printf("\nBinary Search: %d",binarySearch(p,k,n));
	printf("\nRec Binary Search: %d",recBinarySearch(p,k,0,n-1));
	
	return 0;	
}


