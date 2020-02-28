#include<stdlib.h>
#include<stdio.h>
#include<iostream>

template< typename T >
class MaxHeap{
	private:
	
	class Node{
		public:
		
		Node *prev;
		T data;
		Node *next;
	};
		
	Node *create(T n){
		Node *x = (Node *)malloc(sizeof(Node));
		x->data = n;
		x->prev = NULL;
		x->next = NULL;
		return x;
	}
			
	void heapify(){
		int index = (length - 1) / 2, leftChildIndex, rightChildIndex;
		Node *largestChild , *parent;
		bool flag;
		while(index >= 0){
			leftChildIndex = (2*index) + 1;
			rightChildIndex = (2*index) + 2;
			flag = true;
			
			if(rightChildIndex < length)
				largestChild = maxNode(getNode(leftChildIndex), getNode(rightChildIndex));	
			else if(leftChildIndex < length && rightChildIndex >= length)
				largestChild = getNode(leftChildIndex);	
			else flag = false;
							
			parent = getNode(index);
			
			if(flag && largestChild->data > parent->data){
				largestChild->data = largestChild->data + parent->data ;
				parent->data        = largestChild->data - parent->data ;
				largestChild->data = largestChild->data - parent->data ;
				index++;
				continue;
			}
			index--;
		}
	}
	
	Node *head;
	Node *tail;	
	int length;
	
	public:
		
	MaxHeap(): head(NULL), tail(NULL), length(0) {}
	
	void insert(T n){
		Node *x = create(n);
		if(head!=NULL){
			tail->next = x;
			x->prev = tail;
			tail = x;
		}
		else
			head = tail = x;
		length++;
		heapify();
	}
	
	Node *maxNode(Node *node1 = NULL, Node *node2 = NULL){
		return ((node1!=NULL && node2!=NULL) && (node1->data >= node2->data)) ? node1 : node2;
	}
	
	Node *minNode(Node *node1 = NULL, Node *node2 = NULL){
		return ((node1!=NULL && node2!=NULL) && (node1->data <= node2->data)) ? node1 : node2;
	}
	
	Node *getNode(int index){
		if(index==0) return head;
		else if(index==length-1) return tail;
		else if(index<length-1 && index>0){
			Node *travs = head;
			for(int i=0;i<index;i++)
				travs=travs->next;
			return travs;
		}
		else{
			printf("\nInvalid Index\nReturning NULL");
			return NULL;
		}
	}
	
	void removeRoot(){
		head->data = tail->data;
		deleteLast();		
	}
	
	void deleteLast(){
		if(tail!=NULL && head->next!=NULL){
			Node *temp;
			tail->prev->next = NULL;
			temp = tail->prev;
			tail->prev = NULL;
			tail = temp;
			length--;
			heapify();
		}
		else if(tail!=NULL && head->next==NULL){
			head = tail = NULL;
			length--;
		}
		else
			printf("\nEmpty List");
	}
	
	void remove(T n){
		if(contains(n)){
			Node *node = getNode(indexOf(n));
			node->data = tail->data;
			deleteLast();
		}
	}
	
	void display(){
		if(length!=0){
			Node *travs = head;
			printf("\n");
			while(travs!=NULL){
			    std::cout<<travs->data<<"\t";
			    travs = travs->next;
			}
		}
		else
			printf("\nEmpty Heap");
	}
	
	T at(int index){
		if(index==0) return head->data;
		else if(index==length-1) return tail->data;
		else if(index<length-1 && index>0){
			Node *travs = head;
			for(int i=0;i<index;i++)
				travs=travs->next;
			return travs->data;
		}
		else{
			printf("\nInvalid Index\nReturning error value: -1");
			return T(-1);
		}
	}
	
	int indexOf(T n){
		int index=0;
		Node *travs = head;
		while(travs!=NULL){
			if(travs->data==n)
				return index;
			travs=travs->next;
			index++;
		}
		
		return -1;
	}
	
	bool contains(T n){
		return indexOf(n)!=-1;
	}
};

int main(){
	MaxHeap<int> heap;
	
	heap.insert(1);
	heap.insert(12);
	heap.insert(9);
	heap.insert(5);
	heap.insert(6);
	heap.insert(10);
	heap.display();
	
	heap.remove(5);
	heap.display();
	/*heap.insert(10);
	heap.display();
	heap.insert(15);
	heap.display();*/
	
	return 0;
}
