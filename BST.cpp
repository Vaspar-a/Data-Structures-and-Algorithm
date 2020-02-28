#include<stdlib.h>
#include<stdio.h>
#include<iostream>

template< typename T >
class BST{
	private:
	
	class Node{
		public:
		
		Node *left;
		T data;
		Node *right;
	};
		
	Node *create(T n){
		Node *x = (Node *)malloc(sizeof(Node));
		x->data = n;
		x->left = NULL;
		x->right = NULL;
		return x;
	}
	
	Node *root;
	
	public:
		
	BST(): root(NULL) {}
	
	void insert(T n){	
		if(root == NULL)
			root = create(n);
		else{
			Node *travs = root;
			while(true){
				if(n <= travs->data && travs->left != NULL)
					travs = travs->left;
				else if(n > travs->data && travs->right != NULL)
					travs = travs->right;
				else if(n <= travs->data && travs->left == NULL){
					travs->left = create(n);
					break;
				}
				else if(n > travs->data && travs->right == NULL){
					travs->right = create(n);
					break;
				}
					
			}
			
		}
	}
	
	void remove(T n){
		if(root != NULL){
			Node *travs = root, *prev;
			while(travs->data != n){
				prev = travs;
				if(n < travs->data)	
					travs = travs->left;
				else if(n > travs->data)	
					travs = travs->right;
			}
			// If the node has 2 children
			if(travs->left != NULL && travs->right != NULL){
				Node *temp = travs;
				travs = travs->left;
				if(travs->right != NULL){
					while(travs->right != NULL){
						prev = travs;
						travs = travs->right; 
					}
					prev->right = travs->left;
					travs->left = NULL;
					
					temp->data = travs->data;	
				}
				else if(travs->right == NULL){
					temp->data = travs->data;
					temp->left = travs->left;
				}
				
			}
			// If the node has only a single child
			else if(travs->left != NULL && travs->right == NULL){
				if(prev->left == travs)
					prev->left = travs->left;
				else if(prev->right == travs)
					prev->right = travs->left;
				travs->left = NULL;
			}
			else if(travs->right != NULL && travs->left == NULL){
				if(prev->left == travs)
					prev->left = travs->right;
				else if(prev->right == travs)
					prev->right = travs->right;
				travs->right = NULL;
			}
			// If the node is leaf
			else if(travs->left == NULL && travs->right == NULL){
				if(prev->left == travs)
					prev->left = NULL;
				else if(prev->right == travs)
					prev->right = NULL;
			}
		}
	}
	
	Node *getRoot(){
		return root;
	}
	
	Node *get(T n){
		Node *travs = root;
		while(travs != NULL){
			if(n < travs->data)	
				travs = travs->left;
			else if(n > travs->data)	
				travs = travs->right;
			else if(n == travs->data)
				return travs;
		}
		std::cout<<"\nElement doesn't exists";
		return NULL;
	}
	
	T max(Node *travs){
		if(travs != NULL){
			if(travs->right != NULL){
				while(travs->right != NULL)	travs = travs->right;
				return travs->data;
			}
			return travs->data;
		}
		return INT_MIN;
	}
	
	T min(Node *travs){
		if(travs != NULL){
			if(travs->left != NULL){
				while(travs->left != NULL)	travs = travs->left;
				return travs->data;
			}
			return travs->data;
		}
		return INT_MAX;
	}
	
	void display(Node *travs, std::string order = "in"){
		if(travs != NULL){
			if(order == "in"){
				display(travs->left);
				std::cout << travs->data << "\t";
				display(travs->right);	
			}
			else if(order == "post"){
				display(travs->left,"post");
				display(travs->right,"post");
				std::cout << travs->data << "\t";	
			}
			else if(order == "pre"){
				std::cout << travs->data << "\t";	
				display(travs->left,"pre");
				display(travs->right,"pre");
			}
		}
	}
};

int main(){
	BST<int> tree;
	
	/*tree.insert(50);
	tree.insert(40);
	tree.insert(60);
	tree.insert(55);
	tree.insert(45);
	tree.insert(42);	
	tree.insert(48);
	
	std::cout<<"\nMax: "<<tree.max(tree.get(50));
	std::cout<<"\nMin: "<<tree.min(tree.get(50));
	
	tree.remove(42);
	
	printf("\nIn order: ");
	tree.display(tree.getRoot());
	printf("\nPre order: ");
	tree.display(tree.getRoot(),"pre");		
	printf("\nPost order: ");
	tree.display(tree.getRoot(),"post");*/
	
	long long int n;
	std::cout<<"\nEnter phone no: ";
	std::cin>>n;
	while(n>0){
		//printf("\nn = %ld", (int)n%10);
		tree.insert((int)n%10);
		n /= 10;
	}
	
	tree.display(tree.getRoot());
	printf("\nDisplay nodes after 3:\t");
	tree.display(tree.get(3));
	
	return 0;
}
