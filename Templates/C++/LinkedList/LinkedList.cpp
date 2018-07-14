//
// Code Contributor(s) : Rajeev Ranjan
//

#include <iostream>

using namespace std;

class List;

class node
{
	public:
		int data;
		node * next;
};

class List
{
	node * head, *tail; 
	public:
		List(){ head = NULL; tail = NULL; }
		void headInsert(int data);
		void tailInsert(int data);
		void display();
		void delHead();
		void delTail();
		void delPos(int pos);
};

void List::headInsert(int data)
{
	node *newNode = new node;
	newNode->data = data; 
	if(head == NULL)
	{
		newNode->next = NULL;
		head = newNode;
		tail = newNode;
	}
	else
	{
		newNode->next = head;
		head = newNode;
	}
}

void List::tailInsert(int data)
{
	node * newNode = new node;
	newNode->data = data;
	if(tail == NULL)
	{
		newNode->next = NULL;
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->next = newNode;
		newNode->next = NULL;
		tail = newNode;
	}
}

void List::delHead()
{
	node *temp = head;
	if(head != NULL)
	{
		head = head->next;
		delete temp;
	}
}

void List::delTail()
{
	node *temp = tail;
	node *curr = head;
	if(tail != NULL)
	{
		while(curr->next != temp)
		{
			curr = curr->next;
		}
		tail = curr;
		tail->next  = NULL;
		delete temp;
	}
}

void List::delPos(int pos)
{
	node *temp = head;
	node *curr = NULL;
	int c = 1;

	if(pos == 1)
		delHead();
	else
	{
		while(temp != NULL && c != pos)
		{
			temp = temp->next;
			c++;
		}
		curr = temp;
		if(curr->next == NULL)
			delTail();
		else
		{
			temp = head;
			while(temp->next != curr)
			{
				temp = temp->next;
			}
			temp->next = curr->next;
			delete curr;
		}
	}		
}

void List::display()
{
	node *temp = head;
	while(temp != NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

int main()
{
	List l;
	l.headInsert(10);
	l.headInsert(9);
	l.headInsert(8);
	l.display();
	l.tailInsert(11);
	l.tailInsert(12);
	l.tailInsert(13);
	l.display();
	l.delHead();
	l.delTail();
	l.delPos(2);
	l.display();

	return 0;
}
