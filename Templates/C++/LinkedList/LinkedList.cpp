//
// Code Contributor(s) : Rajeev Ranjan
//

#include "iostream"

using namespace std;

class Node
{
public:
	int data;
	Node * next;
	
};

class LinkedList
{
private:
	Node * first;
	Node * last;
	int length;
	
public:
	LinkedList () {
		first = NULL;
		last = NULL;
		length = 0;
	}
	void insertFront(int data);
	void insertLast(int data);
	void insertPosition(int data, int position);
	void showList();
	int getLength();
};

void LinkedList::showList() {
	Node * curr = first;
	cout<<endl<<"Updated List"<<endl;
	while(curr!=NULL) {
		cout<<curr->data<<" ";
		curr = curr->next;
	}
	cout<<endl;
}

int LinkedList::getLength() {
	return length;
}


void LinkedList::insertFront(int data) {
	if (first == NULL) {
		Node * newNode = new Node;
		newNode->data = data;
		newNode->next = NULL;
		first = newNode;
		last = newNode;
	}
	else {
		Node * newNode = new Node;
		newNode->data = data;
		newNode->next = first;
		first = newNode;
	}
	length++;
	showList();
}

void LinkedList::insertLast(int data) {
	if (last == NULL) {
		Node * newNode = new Node;
		newNode->data = data;
		newNode->next = NULL;
		first = newNode;
		last = newNode;
	}
	else {
		Node * newNode = new Node;
		newNode->data = data;
		newNode->next = NULL;
		last->next = newNode;
		last = newNode;
	}
	length++;
	showList();
}

void LinkedList::insertPosition(int data, int position) {

	int counter = 1;

	if (position == 0) {
		insertFront(data);
	}
	else if (position == length) {
		insertLast(data);
	}
	else if (position > length){
		cout<<"Length of LinkedList is "<<getLength()<<" element cannot be inserted at "<<position<<endl;
	}
	else {
		Node * temp = first;
		while(temp != NULL && counter != position) {
			counter++;
			temp = temp->next;
		}
		Node * newNode = new Node;
		newNode->data = data;
		newNode->next = temp->next;
		temp->next = newNode;
		length++;
		showList();
	}	

}

int main(int argc, char const *argv[])
{
	int choice;
	LinkedList l;
	int data;
	while(true) {
		cout<<endl<<"--------Enter choice--------"<<endl;
		cout<<"      1. For Head Insertion "<<endl;
		cout<<"      2. For Tail Insertion "<<endl;
		cout<<"      3. For Insertion at particular Position "<<endl;
		cout<<"      4. See LinkedList "<<endl;
		cout<<"      5. See Length of LinkedList "<<endl;
		cin>>choice;
		if (choice == 1) {

			cout<<"Enter data : ";
			cin>>data;
			l.insertFront(data);
		}
		else if (choice == 2) {

			cout<<"Enter data : ";
			cin>>data;
			l.insertLast(data);
		}
		else if (choice == 3) {

			cout<<"Enter data : ";
			int position;
			cin>>data;

			cout<<"Enter position : ";
			cin>>position;

			l.insertPosition(data, position);
		}
		else if (choice == 4) {
			l.showList();
		}
		else if (choice == 5) {
			cout<<"Length : "<<l.getLength()<<endl;
		}
		else {
			break;
		}
	}
	
	return 0;
}
