#include<stdlib.h>
#include<stdio.h>
#include<iostream>

template< typename T >
class CLinkedList{
	private:
	
	class Node{
		public:
		
		Node *prev;
		T data;
		Node *next;
	};
	
	Node *head;
	Node *tail;
	int length;
	
	void ascSort(){
		Node *travs = head;
		int i,j,ex;
		for(i=0;i<length;i++){
			ex=0;
			travs=head;
			for(j=0;j<length-1;j++){
				if(travs->data > travs->next->data){
					travs->data = travs->data + travs->next->data;
					travs->next->data = travs->data - travs->next->data;
					travs->data = travs->data - travs->next->data;
					ex++;
				}
				travs=travs->next;
			}
			if(ex==0) 
				break;
		}
	}
	
	void descSort(){
		Node *travs = head;
		int i,j,ex;
		for(i=0;i<length;i++){
			ex=0;
			travs=head;
			for(j=0;j<length-1;j++){
				if(travs->data < travs->next->data){
					travs->data = travs->data + travs->next->data;
					travs->next->data = travs->data - travs->next->data;
					travs->data = travs->data - travs->next->data;
					ex++;
				}
				travs=travs->next;
			}
			if(ex==0) 
				break;
		}
	}

	public:
	
	CLinkedList(): head(NULL), tail(NULL), length(0) {}
		
	Node *create(T n){
		Node *x = (Node *)malloc(sizeof(Node));
		x->data = n;
		x->prev = NULL;
		x->next = NULL;
		return x;
	}

	void insertFirst(T n){
		Node *x = create(n);
		if(head!=NULL){
			x->next = head;
			head->prev = x;
			head = x;	
		}
		else
			head = tail = x;
		tail->next = head;
		length++;
		//printf("\nInside iF: Head data: %d",head->data);
	}
	
	void deleteFirst(){
		if(head!=NULL && head->next!=NULL && head!=tail){
			Node *temp;
			tail->next = NULL;
			head->next->prev = NULL;
			temp = head->next;
			head->next = NULL;
			head = temp;
			tail->next = head;
			length--;
		}
		else if(head!=NULL && head==tail){
			tail->next = NULL;
			head = tail = NULL;
			length--;
		}
		else
			printf("\nEmpty List");
	}
	
	void deleteLast(){
		if(tail!=NULL && head->next!=NULL && head!=tail){
			Node *temp;
			tail->next = NULL;
			tail->prev->next = NULL;
			temp = tail->prev;
			tail->prev = NULL;
			tail = temp;
			tail->next = head;
			length--;
		}
		else if(tail!=NULL && head==tail){
			tail->next = NULL;
			head = tail = NULL;
			length--;
		}
		else
			printf("\nEmpty List");
	}
	
	void insertLast(T n){
		Node *x = create(n);
		if(head!=NULL){
			tail->next = x;
			x->prev = tail;
			tail = x;
		}
		else
			head = tail = x;
		tail->next = head;
		length++;
	}
	
	void insertBefore_m(T m,T n){
		if(contains(m))
			insertAt(indexOf(m), n);
	}
	
	void insertAfter_m(T m,T n){
		if(contains(m))
			insertAt(indexOf(m)+1, n);
	}
	
	void deleteBefore_m(T m){
		if(contains(m))
			deleteAt(indexOf(m)-1);
	}
	
	void deleteAfter_m(T m){
		if(contains(m))
			deleteAt(indexOf(m)+1);
	}

	void display(){
		if(length!=0){
			Node *travs = head->next;
			printf("\n");
			std::cout<<head->data<<"\t";
			while(travs!=head){
			    std::cout<<travs->data<<"\t";
			    travs = travs->next;
			}
		}
		else
			printf("\nEmpty list");
	}
	
	void insert(T n){
		insertLast(n);
	}
	
	void remove(T n){
		if(contains(n))
			deleteAt(indexOf(n));
	}
	
	void removeAll(T n){
		Node *travs = head->next;
		while(travs!=NULL){
			if(travs->data==n){
				deleteAt(indexOf(n));
			}
			travs = travs->next;
		}
		if(head->data==n) deleteFirst();
		if(tail->data==n) deleteLast();
	}
		
	int size() { return length; }
	
	void empty(){ head = tail = NULL; length = 0; }
	
	void fill(int size, T n){
		for(int i=0;i<size;i++)	
			insert(n);
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
		int index=1;
		Node *travs = head->next;
		if(head->data==n) return 0;
		while(travs!=head){
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
	
	void replace(T m,T n){
		if(contains(m))		
			replaceAt(indexOf(m), n);
		else
			std::cout<<"\n"<<m<<" not found in list";
	}
	
	void replaceAll(T m,T n){
		Node *travs = head;
		while(travs!=NULL){
			if(travs->data==m)
				travs->data = n;
			travs = travs->next;
		}
	}
	
	void replaceListWith(T n){
		Node *travs = head->next;
		head->data = n;
		while(travs!=head){
			travs->data = n;
			travs = travs->next;
		}
	}
	
	void replaceAt(int index,T n){
		if(index==0) head->data = n;
		else if(index==length-1) tail->data = n;
		else if(index<length-1 && index>0){
			Node *travs = head;
			for(int i=0;i<index;i++)
				travs = travs->next;
			travs->data = n;
		}
		else
			printf("\nInvalid Index");
	}
	
	void insertAt(int index,T n){
		if(index==0)
			insertFirst(n);
		else if(index==length)
			insertLast(n);
		else if(index<length && index>0){
			Node *travs = head;
			for(int i=0;i<index;i++)
				travs = travs->next;
			Node *x = create(n);
			x->next = travs;
			x->prev = travs->prev;
			travs->prev->next = travs->prev = x;
			tail->next = head;
			length++;
		}
		else
			printf("\nInvalid Index");
	}
	
	void deleteAt(int index){
		if(index==0)
			deleteFirst();	
		else if(index==length-1)
			deleteLast();
		else if(index<length-1 && index>0){
			Node *travs = head;
			for(int i=0;i<index;i++)
				travs = travs->next;
			travs->prev->next = travs->next;
	    	travs->next->prev = travs->prev;
	    	travs->next = travs->prev =NULL;
	    	//tail->next = head;
	    	length--;
		}
		else
			printf("\nInvalid Index");
	}
	
	void reverse(){
		Node *travs = head->next, *temp = NULL;
		temp = head->next;
		head->next = head->prev;
		head->prev = temp;
		while(travs!=head){
			temp = travs->next;
			travs->next = travs->prev;
			travs->prev = temp;
			travs = travs->prev;
		}
		temp = head;
		head = tail;
		tail = temp;
		tail->next = head;
	}
	
	void sort(int c=0){
		switch(c){
			case 0:
				ascSort();
				break;
			case 1:
				descSort();
				break;
			default:
				printf("\nInvalid Case\nTo sort in ascending order pass 0\nTo sort in descending order pass 1");
				break;
		}
	}
};

int main(){
	CLinkedList<int> l;
	
	/*l.insert(3);
	l.insert(3);
	l.fill(5,10);
	l.display();
	l.insert(-10);
	l.insert(60);
	l.insert(-2);
	l.insert(3);
	l.insert(0);
	l.insert(900);
	l.insert(3);
	l.insert(3);
	l.display();
	l.removeAll(3);
	l.display();
	l.replaceListWith(5);
	l.display();
	l.empty();
	l.display();
	l.fill(5,10);
	l.display();*/
		
	/*l.insertAt(-1,5);
	std::cout<<"\nSize: "<<l.size();
	for(int i=0;i<5;i++){
		l.insertAt(i,i+1);
		//l.display();
		std::cout<<"\nSize: "<<l.size()<<"\tIndex: "<<l.indexOf(i+1);
	}
	l.display();
	l.insertAt(4,6);
	l.display();
	l.insertAt(3,7);
	l.display();
	l.insertAt(10,-2);
	for(int i=0;i<l.size();i++){
		std::cout<<"\nAt "<<i<<": "<<l.at(i);
	}
	for(int i=0;i<5;i++){
		std::cout<<"\nSize: "<<l.size();
		l.deleteAt(i);
		l.display();
	}
	l.reverse();
	l.display();
	l.sort(1);
	l.display();
	l.remove(6);
	l.display();
	l.remove(7);
	l.display();
	l.remove(2);
	l.display();*/
		
	/*l.deleteFirst();
	l.deleteLast();
	l.insertLast(5);
	l.insertLast(4);
	l.insertLast(3);
	l.display();
	if(l.contains(4))
		printf("\nContains");
	else
		printf("\nNo");
	
	std::cout<<"\n"<<l.indexOf(5);
	std::cout<<"\n"<<l.indexOf(4);
	std::cout<<"\n"<<l.indexOf(3);
	std::cout<<"\n"<<l.indexOf(2);
	
	std::cout<<"\n"<<l.at(-1);
	std::cout<<"\n"<<l.at(0);
	std::cout<<"\n"<<l.at(1);
	std::cout<<"\n"<<l.at(2);
	std::cout<<"\n"<<l.at(3);
	l.deleteFirst();
	l.display();
	l.deleteFirst();
	l.display();
	l.deleteFirst();
	l.display();*/
	
	/*l.insert(1);
	l.insert(-12);
	l.insert(90);
	l.insert(5);
	l.insert(13);
	l.display();
	printf("\nIndex of 1: %d",l.indexOf(1));
	printf("\nIndex of 5: %d",l.indexOf(5));
	printf("\nIndex of 13: %d",l.indexOf(13));
	printf("\nAt 0: %d",l.at(0));
	printf("\nAt last: %d",l.at(l.size()-1));
	printf("\nAt 3: %d",l.at(3));
	l.replace(1,-23);
	l.replace(13,76);
	l.replace(5,55);
	l.display();
	l.replaceAt(0,4);
	l.replaceAt(l.size()-1,56);	
	l.replaceAt(2,85);
	l.display();
	l.insertAt(0,1);
	l.insertAt(l.size()-1,13);
	l.insertAt(2,90);
	l.display();
	l.deleteAt(0);
	l.deleteAt(l.size()-1);
	l.deleteAt(2);
	l.display();
	l.reverse();
	l.display();
	l.sort();
	l.display();
	if(l.contains(90))
		printf("\nContains");
	else
		printf("\nNot contains");*/
	
	//For char
	
	/*printf("\nInsert First:");
    l.insertFirst('a');
    l.insertLast('z');
    l.insertFirst('e');
    l.insertLast('x');
    l.display();
    printf("\nDelete First:");
    l.deleteFirst();
    l.display();
    printf("\nDelete Last:");
    l.deleteLast();
    l.display();
	l.insertBefore_m('a','w');
	l.insertAfter_m('a','q');
	l.insertBefore_m('q','Q');
	l.display();
	l.deleteBefore_m('Q');
	l.display();
	l.deleteAfter_m('a');
	l.display();
	l.remove('Q');
	l.display();
	l.insertAfter_m('z','L');
	l.display();
	l.insertBefore_m('z','o');
	l.display();
	l.insertBefore_m('w','g');
	l.display();
	l.insertAfter_m('w','X');
	l.display();*/
	
	// For int/double
	
	/*printf("\nInsert First:");
    l.insertFirst(5);
    l.insertLast(10);
    l.insertFirst(-2);
    l.insertLast(65);
    l.display();
    printf("\nDelete First:");
    l.deleteFirst();
    l.display();
    printf("\nDelete Last:");
    l.deleteLast();
    l.display();
	l.insertBefore_m(10,3);
	l.display();
	l.insertAfter_m(10,-20);
	l.display();
	l.insertBefore_m(5,3);
	l.display();
	l.insertAfter_m(5,20);
	l.display();
	l.insertBefore_m(-20,69);
	l.display();
	l.insertAfter_m(-20,-34);
	l.display();
	l.deleteBefore_m(3);
	l.display();
	l.deleteAfter_m(-34);
	l.display();
	l.deleteAfter_m(3);
	l.display();
	l.deleteBefore_m(-34);
	l.display();
	l.deleteAfter_m(69);
	l.display();
	l.remove(3);
	l.display();
	l.deleteAfter_m(3);
	l.display();*/
	
	//For float/double
	
	/*printf("\nInsert First:");
    l.insertFirst(5.3);
    l.insertLast(10.1);
    l.insertFirst(-2.2);
    l.insertLast(65.67);
    l.display();
    printf("\nDelete First:");
    l.deleteFirst();
    l.display();
    printf("\nDelete Last:");
    l.deleteLast();
    l.display();
	l.insertBefore_m(10.1,3.5);
	l.insertAfter_m(10.1,20.45);
	l.insertAfter_m(10.1,69.954);
	l.insertBefore_m(20.45,69.96);
	l.display();
	l.sort(1);
	l.display();
	l.deleteBefore_m(3.5);
	l.display();
	l.deleteAfter_m(69.96);
	l.display();
	l.remove(3.5);
	l.display();*/
    
	return 0;
}
