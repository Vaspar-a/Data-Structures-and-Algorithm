#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int *a,int n){
	int i,j,ex;
	for(i=0;i<n;i++){
		ex=0;
		for(j=0;j<n-1;j++){
			if(*(a+j) > *(a+j+1)){
				*(a+j) = *(a+j) + *(a+j+1);
				*(a+j+1) = *(a+j) - *(a+j+1);
				*(a+j) = *(a+j) - *(a+j+1);
				ex++;
			}
		}
		if(ex==0) 
			break;
	}
}

void selectionSort(int *a,int n){
	int i,j,min,index;
	for(i=0;i<n;i++){
		min=100000;
		for(j=i;j<n;j++){
			if(min>*(a+j)){
				min = *(a+j);
				index=j;
			}
		}
		if(*(a+i)>min){
			*(a+i)=*(a+i)+*(a+index);
			*(a+index)=*(a+i)-*(a+index);
			*(a+i)=*(a+i)-*(a+index);
		}
	}
}

void insertionSort(int *a,int n){
	int i,j,key;
	for(i=1;i<n;i++){
		key = *(a+i);
		j=i-1;
		
		while(j>=0 && *(a+j)>key){
			*(a+j+1) = *(a+j);
			j--;
		}
		
		*(a+j+1) = key;
	}
}

void quickSort(int *a,int first,int last){
	int i,j,pivot;
	if(first<last-1){
		pivot=first;
		i=first+1;
		j=last;
	
		while(i<j){
			while(*(a+i)<=*(a+pivot) && i<last) i++;
			while(*(a+j)>*(a+pivot)) j--;
			if(i<j){
				*(a+i)=*(a+i)+*(a+j);
				*(a+j)=*(a+i)-*(a+j);
				*(a+i)=*(a+i)-*(a+j);
			}
		}
		
		*(a+pivot)=*(a+pivot)+*(a+j);
		*(a+j)=*(a+pivot)-*(a+j);
		*(a+pivot)=*(a+pivot)-*(a+j);
		quickSort(a,first+1,j-1);
		quickSort(a,j+1,last);
	}
	/*int i,j,key;
	bool f=true;
	if(first<last){
		key=*(a+first);
		i=first;
		while(f){
			j=last-1;
			i=first+1;
			while(*(a+i)<=key && i<last) i++;
			while(*(a+j)>key && j>=0) j--;
		}
		if(i<j){
			*(a+i)=*(a+i)+*(a+j);
			*(a+j)=*(a+i)-*(a+j);
			*(a+i)=*(a+i)-*(a+j);
			f=true;
		}
		else f=false;
		quickSort(a,first,j-1);
		quickSort(a,i+1,last);
	}*/
}


int linearSearch(int *a,int k,int n){
	int i;
	for(i=0;i<n;i++){
		if(*(a+i)==k)
			return i;
	}
	return -1;
}

int recLinearSearch(int *a,int k,int n){
	if(k==*(a+n)) return n;
	else if(n>=0) return linearSearch(a,k,n-1);
	else return -1;
}

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

int main(){
	int i,n;
	printf("Enter size: ");
	scanf("%d",&n);
	int *p = (int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++){
		scanf("%d",(p+i));
	}
	//printf("\nLinear Search: %d",linearSearch(p,3,n));
	//printf("\nRec Linear Search: %d",recLinearSearch(p,3,n));
	//quickSort(p,0,n-1);
	bubbleSort(p,n);
	//selectionSort(p,n);
	//insertionSort(p,n);
	printf("\n[ ");
	for(i=0;i<n;i++){
		printf("%d, ",*(p+i));
	}
	printf("\b\b ]");
	
	//printf("\nBinary Search: %d",binarySearch(p,3,n));
	//printf("\nRec Binary Search: %d",recBinarySearch(p,3,0,n-1));
	return 0;	
}

