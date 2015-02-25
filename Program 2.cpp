//	Write a routine for returning all elements with a particul
//	ar key value,
//	without deleting them from the list. The list of elements nee
//	ds to be
//	returned in the form of a duplicate linked list

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
			LinkedList search2(int);
			void display();
};
//============================================================================================================
//============================================================================================================
int main()
{
	LinkedList L1, L2;
	int choice, x;
	bool flag = true, found;
	while(flag)
	{
		cout<<"\n1. Add to End";
		cout<<"\n2. Delete certain Element";
		cout<<"\n3. Search element";
		cout<<"\n4. Display List";
		cout<<"\n5. Create new List consisting of search results";
		cout<<"\n6. Exit";
		cout<<"\n===============================================================\nEnter your choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1: cout<<"\nEnter the key : ";
					cin>>x;
					L1.insertEnd(x);
					break;
			case 2: cout<<"\nEnter the key : ";
					cin>>x;
					L1.deleteEle(x);
					break;
			case 3: cout<<"\nEnter the key : ";
					cin>>x;
					found = L1.search(x);
					if(found)
						cout<<"\nElement was found in the list..";
					else
						cout<<"\nElement was not found in the list..";
					break;
			case 4: L1.display();
					break;
			case 5: cout<<"Enter the key : ";
					cin>>x;
					L2 = L1.search2(x);
					L2.display();
					break;
			default:flag = false; 
					 cout<<"Exiting..";
					 break;
		} 
	}
	L1.display();
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

LinkedList LinkedList::search2(int key)
{
	LinkedList L;
	Node* ptr = front;
	while(ptr!=NULL)
	{
		if(key==ptr->getKey())
		{
			L.insertEnd(ptr->getKey());
		}
		ptr = ptr->getNext();
	}
	return L;
}
//============================================================================================================
//============================================================================================================
