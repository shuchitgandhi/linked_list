//	Write code for creating a linked list, adding elements to t
//	he linked list
//	at the tail, searching for an element with a particular key an
//	d also
//	deleting an element with a particular key if it exists


#include<iostream>
using namespace std;
//============================================================================================================
//============================================================================================================
class Node{
		int key;
		Node* next;
		Node* prev;
	public:
		Node(int);
		int getKey();
		Node* getNext();
		Node* getPrev();
		void setNext(Node*);
		void setPrev(Node*);
};
class LinkedList{
			Node* front;
			Node* end;
		public:
			LinkedList();
			Node* createNewNode(int);
			void insertEnd(int);
			void deleteEle(int);
			bool search(int);
			void display();
};
//============================================================================================================
//============================================================================================================
int main()
{
	LinkedList L;
	int choice, x;
	bool flag = true, found;
	while(flag)
	{
		cout<<"\n1. Add to End";
		cout<<"\n2. Delete certain Element";
		cout<<"\n3. Search element";
		cout<<"\n4. Display List";
		cout<<"\n5. Exit";
		cout<<"\n===============================================================\nEnter your choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1: cout<<"\nEnter the key : ";
					cin>>x;
					L.insertEnd(x);
					break;
			case 2: cout<<"\nEnter the key : ";
					cin>>x;
					L.deleteEle(x);
					break;
			case 3: cout<<"\nEnter the key : ";
					cin>>x;
					found = L.search(x);
					if(found)
						cout<<"\nElement was found in the list..";
					else
						cout<<"\nElement was not found in the list..";
					break;
			case 4: L.display();
					break;
			default:flag = false; 
					 cout<<"Exiting..";
					 break;
		} 
	}
	L.display();
	return 0;
}
//============================================================================================================
//============================================================================================================
Node::Node(int x)
{
	key = x;
	next = NULL;
	prev = NULL;
}

int Node::getKey()
{
	return key;
}

Node* Node::getNext()
{	
	return next;
}

Node* Node::getPrev()
{
	return prev;
}

void Node::setNext(Node* x)
{
	next = x;
}

void Node::setPrev(Node* x)
{
	prev = x;
}
//============================================================================================================
//============================================================================================================
LinkedList::LinkedList()
{
	front = NULL;
	end = NULL;
	
}

Node* LinkedList::createNewNode(int x)
{
	Node* newNode = new Node(x);
	return newNode;	
}

void LinkedList::insertEnd(int x)
{
	Node* nNode = createNewNode(x);
	if(front==NULL)
	{
		front = nNode;
		end = nNode;
	}
	else
	{
		end->setNext(nNode);
		nNode->setPrev(end);
		end = nNode;
	}
}

void LinkedList::deleteEle(int x)
{
	Node* ptr = front;
	bool found = false;
	while(ptr!=NULL && !found)
	{
		if(x==ptr->getKey())
		{
			if(ptr==front)
			{
				if(ptr->getNext()==NULL)
				{
					front = NULL;
					end = NULL;
					delete ptr;
				}
				else
				{
					ptr->getNext()->setPrev(NULL);
					front = front->getNext();
					delete ptr;
				}
			}
			else if(ptr==end)
			{
				ptr->getPrev()->setNext(NULL);
				end = end->getPrev();
				delete ptr;
			}
			else
			{
				ptr->getPrev()->setNext(ptr->getNext());
				ptr->getNext()->setPrev(ptr->getPrev());
				delete ptr;
			}
			ptr = NULL;
			found = true;
		}
		else
		{
			ptr = ptr->getNext();
		}
	}
	if(!found)
		cout<<"Element could not be deleted..";
}

bool LinkedList::search(int x)
{
	bool found = false;
	Node* ptr = front;
	while(ptr!=NULL && !found)
	{
		if(x==ptr->getKey())
			found = true;
		else
			ptr = ptr->getNext();
	}
	if(found)
		return true;
	return false;
}

void LinkedList::display()
{
	Node* ptr = front;
	cout<<"\nThe list is : ";
	if(ptr==NULL)
		cout<<" empty\n";
	else
	{
		while(ptr!=NULL)
		{
			cout<<ptr->getKey()<<"->";
			ptr = ptr->getNext();
		}
		cout<<"null\n";
	}
}
//============================================================================================================
//============================================================================================================
