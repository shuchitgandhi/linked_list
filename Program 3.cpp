//	Write an efficient routine for reversing a sublist of elemen
//	ts represented in a linked list
//	i am implementing doubly link list
	
	#include<iostream>
	using namespace std;

	struct node
	{

		int key;
		node *next;
		node *previous;

	};

	node * l=NULL;

	void insert(int num)
	{

		node *ptr=new node;
		ptr->key=num;
		ptr->next=NULL;
		ptr->previous=NULL;

		if(l==NULL)
			l=ptr;
		else
		{

			node *temp;
			temp=l;

			while(temp->next!=NULL)
			{

				temp=temp->next;

			}
			
			temp->next=ptr;
			ptr->previous=temp;
	
		}

	}
	
	void swap(int pos1,int pos2)
	{
	
		node *l1=l;
		node *l2=l;
		node *p1=NULL;
		node *p2=NULL;
		node *temp=l;
		int counter=1;
	
		while(counter!=pos1-1)
		{
	
				temp=temp->next;
				counter++;
	
		}
	
		p1=temp->next;	
		p1->previous=NULL;
		temp->next=NULL;
		counter=1;
		temp=p1;
	
		while(counter!=pos2-pos1+1)
		{
	
			counter++;
			temp=temp->next;
	
		}
	
		p2=temp;
		l2=p2->next;
		l2->previous=NULL;
		p2->next=NULL;
		temp=p2;
		node *temp2;
	
		for(int i=1;i<=pos2-pos1+1;i++)
		{
	
			temp2=temp->previous;
			temp->previous=temp->next;
			temp->next=temp2;
			temp=temp->next;	
	
		}
		
	
		temp=l1;
	
		if(temp==NULL)
			l1=p2;
		else
		{	
	
			while(temp->next!=NULL)
			{
	
				temp=temp->next;
	
			}
	
			temp->next=p2;
	
		}
	
		temp=l1;
	
		if(temp==NULL)
			temp=p2;
		else
		{
	
			while(temp->next!=NULL)
			{
	
				temp=temp->next;
	
			}
	
				temp->next=l2;
	
		}
	
		l=l1;

	}

	void display()
	{

		node *temp=l;

		cout<<"\nList after applying the changes is --> \n\n";

		while(temp!=NULL)
		{

			cout<<temp->key<<"->";
			temp=temp->next;

		}
		cout<<"null\n";

	}

	int main()
	{

		int num;

		cout<<"\nHow many numbers you want to insert --> \n";
		cin>>num;

		int number;
		
		cout<<"\nEnter the numbers --> \n";
		
		for(int i=1;i<=num;i++)
		{
			
			cin>>number;

			insert(number);

		}

		int pos1,pos2;

		cout<<"\nEnter the positions --> \n";
		cin>>pos1;
		cin>>pos2;

		swap(pos1,pos2);
		display();

	}
