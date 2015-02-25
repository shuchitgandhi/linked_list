//	Write an efficient routine for reversing a subsequence of a l
//	inked list
	
	#include<iostream>
	using namespace std;

	struct node
	{

		int key;
		node *next;

	};

	node *l=NULL;

	void insert(int num)
	{

		node *ptr=new node;
		ptr->key=num;
		ptr->next=NULL;

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

		}

	}
	
	void change(int a[],int num)
	{

		node *temp=l;
		int front=0;
		int rear=num-1;

		while(temp!=NULL)
		{

			if(a[front]==temp->key)
			{	

				temp->key=a[rear];
				rear--;
				front++;

			}
			temp=temp->next;

		}

	}

	void display()
	{

		node *temp;
		temp=l;

		cout<<"\nList after applying changes is --> \n\n";

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
		
		cout<<"\nEnter the elements--> \n";
		
		for(int i=1;i<=num;i++)
		{

			cin>>number;

			insert(number);

		}

		int a[100];
		int size;

		cout<<"\nEnter the number of elements of subsequence to reverse--> \n";
		cin>>size;
		cout<<"\nEnter the subsequence--> \n";

		for(int i=1;i<=size;i++)
		{

			cin>>a[i-1];

		}

		change(a,size);
		display();

	}
