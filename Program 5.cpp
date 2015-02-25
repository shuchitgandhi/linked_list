//	Consider a list of records each of which have 5 different key fields from a totally ordered set. 
//  The search condition for a record is based on specific values of each of the five key fields. 
// 	Create a linked list of the largest set of data items all of which match at least three specific key
//	values. 
//  This needs to be done preserving the order of elements in the original list and also without destroying the original list


	#include<iostream>
	using namespace std;

	struct node
	{
		int m1;
		int m2;
		int m3;
		int m4;
		int m5;
		node *next;
		node *previous;
	};

	node *l=NULL;
	node *l2[100];
	node *l3=NULL;

	void insert(int a[])
	{

		node *ptr=new node;
		ptr->next=NULL;
		ptr->previous=NULL;
		ptr->m1=a[0];
		ptr->m2=a[1];
		ptr->m3=a[2];
		ptr->m4=a[3];
		ptr->m5=a[4];

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
	
	void create()
	{

		for(int i=0;i<100;i++)
		{

			l2[i]=NULL;

		}

		node *temp=l;
		node *main=l;

		int count=0;

		while(main!=NULL)
		{

			temp=main;

			int counter=1;

			while(temp!=NULL)
			{
	
				if(counter==1)
				{

					node *temp2=new node;
					temp2->m1=temp->m1;	
					temp2->m2=temp->m2;
					temp2->m3=temp->m3;
					temp2->m4=temp->m4;
					temp2->m5=temp->m5;
					temp2->next=NULL;
					temp2->previous=NULL;
					l2[count]=temp2;
					counter++;

				}
				else
				{

					int countertemp=0;

					if(l2[count]->m1==temp->m1)
						countertemp++;
					if(l2[count]->m2==temp->m2)
						countertemp++;
					if(l2[count]->m3==temp->m3)
						countertemp++;
					if(l2[count]->m4==temp->m4)
						countertemp++;
					if(l2[count]->m5==temp->m5)
						countertemp++;
					if(countertemp>=3)  //insert
					{

						node *temp2=new node;
						temp2->next=NULL;
						temp2->previous=NULL;
						temp2->m1=temp->m1;	
						temp2->m2=temp->m2;
						temp2->m3=temp->m3;
						temp2->m4=temp->m4;
						temp2->m5=temp->m5;
						node *p=l2[count];

						while(p->next!=NULL)
						{

							p=p->next;

						}

						p->next=temp2;
						temp2->previous=p;

					}

				}

				temp=temp->next;

			}					
			//delete unnecessary elements
			temp=l2[count];

			while(temp!=NULL)
			{

				node *temp2=temp->next;

				while(temp2!=NULL)
				{

					int countertemp=0;

					if(temp->m1==temp2->m1)
						countertemp++;
					if(temp->m2==temp2->m2)
						countertemp++;
					if(temp->m3==temp2->m3)
						countertemp++;
					if(temp->m4==temp2->m4)
						countertemp++;
					if(temp->m5==temp2->m5)
						countertemp++;
					if(countertemp<3)  //delete perform
					{

						(temp2->previous)->next=(temp2->next);

						if(temp2->next!=NULL)
							(temp2->next)->previous=temp2->previous;
						
					}

					temp2=temp2->next;

				}

				temp=temp->next;

			}

			count++;
			main=main->next;

		}

	}

	int number;
	int largest=0;

	void largestfind()
	{
		
		for(int i=0;i<number;i++)
		{

			int counter=0;

			node *temp=l2[i];

			while(temp!=NULL)
			{

				counter++;
				temp=temp->next;	

			}

			if(counter>largest)
				largest=counter;

		}

	}

	void display()
	{

		cout<<"New array list is as follows --> \n\n";

		for(int i=0;i<number;i++)
		{

			int counter=0;

			node *temp=l2[i];
			
			while(temp!=NULL)
			{

				counter++;
				temp=temp->next;	

			}

			if(counter==largest)  //display
			{

				temp=l2[i];
				cout<<i+1<<")"<<endl<<endl;
				while(temp!=NULL)
				{

					cout<<temp->m1;
					cout<<"->"<<temp->m2;
					cout<<"->"<<temp->m3;
					cout<<"->"<<temp->m4;
					cout<<"->"<<temp->m5<<"->null";

					temp=temp->next;

					cout<<endl;
					
				}

				cout<<"\n\n";

			}

		}

	}
	
	int main()
	{

		

		cout<<"\nEnter the number of nodes you want to insert in list -->\n";
		cin>>number;
		cout<<"\nEnter the elements of each node :-  \n";

		for(int i=1;i<=number;i++)
		{
			int a[5];

			cout<<"Elements of "<<i<<" node --> \n";
			cin>>a[0];
			cin>>a[1];
			cin>>a[2];
			cin>>a[3];
			cin>>a[4];

			insert(a);

		}

		create();
		largestfind();
		display();

	}
		
