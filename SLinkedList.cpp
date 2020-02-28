#include<stdlib.h>
#include<stdio.h>
#include<iostream>

template< typename T >
class SLinkedList{
	private:
	
	class Node{
		public:
			
		T data;
		Node *next;
	};
	
	Node *head;
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
	
	SLinkedList(): head(NULL), length(0) {}
		
	Node *create(T n){
		Node *x = (Node *)malloc(sizeof(Node));
		x->data = n;
		x->next = NULL;
		return x;
	}

	void insertFirst(T n){
		Node *x = create(n);
		if(head!=NULL)
		    x->next = head;
		head = x;
		length++;
		//printf("\nInside iF: Head data: %d",head->data);
	}
	
	void deleteFirst(){
		if(head!=NULL && head->next!=NULL){
			Node *temp;
			temp=head->next;
			head->next=NULL;
			head=temp;
			length--;
		}
		else if(head!=NULL && head->next==NULL){
			head=NULL;
			length--;
		}
		else
			printf("\nEmpty List");
	}
	
	void deleteLast(){
		if(head!=NULL && head->next!=NULL){
			Node *travs=head;
			while(travs->next->next!=NULL)
	    		travs = travs->next;
	    	travs->next=NULL;
	    	length--;
		}
		else if(head!=NULL && head->next==NULL){
			head=NULL;
			length--;
		}
		else
			printf("\nEmpty List");
	}
	
	void insertLast(T n){
		Node *x = create(n);
		Node *travs = head;
		if(head!=NULL){
			while(travs->next!=NULL)
			    travs = travs->next;
				travs->next = create(n);
			}
		else
			head=x;
		length++;
	}
	
	void insertBefore_m(T m,T n){
		Node *x = create(n);
		Node *travs = head;
		if(head!=NULL && head->data!=m){
			while(travs->next->data!=m && travs!=NULL)
	    		travs = travs->next;
	    	if(travs!=NULL){
	    		x->next=travs->next;
				travs->next=x;	
				length++;
			}
			else
				std::cout<<"\n"<<m<<" not found in list";
		}
		else if(head->data==m)
			insertFirst(n);
		else
			printf("\nEmpty List");
	}
	
	void insertAfter_m(T m,T n){
		Node *x = create(n);
		Node *travs = head;
		if(head!=NULL){
			while(travs->data!=m && travs!=NULL)
	    		travs = travs->next;
	    	if(travs!=NULL){
	    		x->next=travs->next;
				travs->next=x;	
				length++;
			}
			else
				std::cout<<"\n"<<m<<" not found in list";
		}
		else
			printf("\nEmpty List");
	}
	
	void deleteBefore_m(T m){
		Node *travs = head,*prev=NULL;
		if(head!=NULL && head->next->data!=m && head->data!=m){
			while(travs->next->data!=m && travs!=NULL){
				prev=travs;
	    		travs = travs->next;
	    	}
	    	if(travs!=NULL){
	    		prev->next=travs->next;
	    		travs->next=NULL;
	    		length--;
			}
			else
				std::cout<<"\n"<<m<<" not found in list";
		}
		else if(head->next->data==m)
			deleteFirst();
	}
	
	void deleteAfter_m(T m){
		Node *travs = head,*after=travs->next;
		if(head!=NULL){
			while(travs->data!=m && after!=NULL){
				after=after->next;
	    		travs = travs->next;
	    	}
	    	if(after!=NULL){
	    		travs->next=after->next;
	    		after->next=NULL;
	    		length--;
			}
		}
		else
			printf("\nEmpty List");
	}

	void display(){
		Node *travs = head;
		printf("\n");
		while(travs!=NULL){
		    std::cout<<travs->data<<"\t";
		    travs = travs->next;
		}
	}
	
	void insert(T n){
		insertLast(n);
	}
	
	void remove(T n){
		Node *travs = head,*prev=NULL;
		if(head!=NULL && head->data!=n){
			while(travs->data!=n && travs!=NULL){
				prev=travs;
	    		travs = travs->next;
	    	}
	    	if(travs!=NULL){
	    		prev->next=travs->next;
	    		travs->next=NULL;
	    		length--;
			}
			else
				std::cout<<"\n"<<n<<" not found in list";
		}
		else if(head->data==n)
			deleteFirst();	
	}
	
	void removeAll(T n){
		Node *travs = head, *temp;
		while(travs!=NULL){
			temp = travs->next;
			if(travs->data==n)
				remove(n);
			travs = temp;
		}
	}
	
	int size() { return length; }
	
	void empty(){ head = NULL; length = 0; }
	
	void fill(int size, T n){
		for(int i=0;i<size;i++)	
			insert(n);
	}
	
	T at(int index){
		if(index<length && index>=0){
			Node *travs = head;
			for(int i=0;i<index;i++)
				travs=travs->next;
			return travs->data;
		}
		else{
			printf("\nInvalid Index\nReturning error value: -1");
			return -1;
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
		return indexOf(n)!=-1 ? 1 : 0;
	}
	
	void replace(T m,T n){
		if(indexOf(m)!=-1){
			Node *travs = head;
			while(travs->data!=m)
				travs=travs->next;
			travs->data = n;
		}
		else{
			std::cout<<"\n"<<m<<" not found in list";
		}
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
		Node *travs = head;
		while(travs!=NULL){
			travs->data = n;
			travs = travs->next;
		}
	}
	
	void replaceAt(int index,T n){
		if(index<length && index>=0){
			Node *travs = head;
			for(int i=0;i<index;i++)
				travs=travs->next;
			travs->data = n;
		}
		else{
			printf("\nInvalid Index");
		}
	}
	
	void insertAt(int index,T n){
		if(index<length && index>=0){
			insertBefore_m(at(index), n);
		}
		else{
			printf("\nInvalid Index");
		}
	}
	
	void deleteAt(int index){
		if(index==0) deleteFirst();
		else if(index==length-1) deleteLast();
		else if(index<length && index>0){
			deleteBefore_m(at(index+1));
		}
		else{
			printf("\nInvalid Index");
		}
	}
	
	void reverse(){
		Node *travs = head,*prev = NULL, *temp = NULL;
		while(travs!=NULL){
			temp=travs->next;
			travs->next=prev;
			prev=travs;
			travs=temp;
		}
		head=prev;
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
	SLinkedList<int> l;
	
	printf("\nInsert at First 5: ");
	l.insertFirst(5);
	l.display();
	
	printf("\nInsert at Last 10: ");
	l.insertLast(10);
	l.display();
	
	printf("\nInsert before 10, 3: ");
	l.insertBefore_m(10, 3);
	l.display();
	
	printf("\nDelete First: ");
	l.deleteFirst();
	l.display();
	
	printf("\nDelete Last: ");
	l.deleteLast();
	l.display();
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
	l.sort(1);
	l.display();
	if(l.contains(91))
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
	l.insertAfter_m('w','q');
	l.insertBefore_m('q','Q');
	l.display();
	l.deleteBefore_m('Q');
	l.display();
	l.deleteAfter_m('a');
	l.display();
	l.remove('Q');
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
	l.insertAfter_m(10,20);
	l.insertBefore_m(20,69);
	l.display();
	l.deleteBefore_m(3);
	l.display();
	l.deleteAfter_m(69);
	l.display();
	l.remove(69);
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
	l.insertBefore_m(20.45,69.96);
	l.display();
	l.deleteBefore_m(3.5);
	l.display();
	l.deleteAfter_m(69.96);
	l.display();
	l.remove(3.5);
	l.display();*/
	
    return 0;
}
