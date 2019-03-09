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
	Node * head;
	Node * tail;
	int length;
	
public:
	LinkedList () {
		head = NULL;
		tail = NULL;
		length = 0;
	}
	void insertFront(int data);
	void inserttail(int data);
	void insertPosition(int data, int position);
	void deleteHead();
	void deleteTail();
	void deletePosition(int position);
	void showList();
	int getLength();
};

void LinkedList::showList() {
	Node * curr = head;
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
	if (head == NULL) {
		Node * newNode = new Node;
		newNode->data = data;
		newNode->next = NULL;
		head = newNode;
		tail = newNode;
	}
	else {
		Node * newNode = new Node;
		newNode->data = data;
		newNode->next = head;
		head = newNode;
	}
	length++;
	showList();
}

void LinkedList::inserttail(int data) {
	if (tail == NULL) {
		Node * newNode = new Node;
		newNode->data = data;
		newNode->next = NULL;
		head = newNode;
		tail = newNode;
	}
	else {
		Node * newNode = new Node;
		newNode->data = data;
		newNode->next = NULL;
		tail->next = newNode;
		tail = newNode;
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
		inserttail(data);
	}
	else if (position > length){
		cout<<"Length of LinkedList is "<<getLength()<<" element cannot be inserted at "<<position<<endl;
	}
	else {
		Node * temp = head;
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

void LinkedList::deleteHead() {
	if (head == tail) {
		head = NULL;
		tail = NULL;
	}
	else {
		Node * temp = head;
		head = temp->next;
		delete temp;
	}
	length--;
}

void LinkedList::deleteTail() {

	if (head == tail) {
		head = NULL;
		tail = NULL;
	}
	else {
		Node * curr = head;
		while (curr->next != tail) {
			curr = curr->next;
		}

		tail = curr;
		Node * temp = curr->next;
		curr->next = NULL;
		delete temp;
	}
	length--;
}

void LinkedList::deletePosition(int position) {

	if (head == tail) {
		head = NULL;
		tail = NULL;
		length--;
	}
	else if (position == getLength()-1) {
		deleteTail();
	}
	else if (position == 0) {
		deleteHead();
	}
	else {
		Node * curr = new Node;
		Node * previous = new Node;
		curr = head;
		for (int i = 0; i<position; i++){
			previous = curr;
			curr = curr->next;
		}
		previous->next = curr->next;
		curr->next = NULL;
		delete curr;
		length--;
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
		cout<<"      6. For Head Deletion "<<endl;
		cout<<"      7. For Tail Deletion "<<endl;
		cout<<"      8. For Deletion at particular Position "<<endl;
		cin>>choice;
		if (choice == 1) {

			cout<<"Enter data : ";
			cin>>data;
			l.insertFront(data);
		}
		else if (choice == 2) {

			cout<<"Enter data : ";
			cin>>data;
			l.inserttail(data);
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
		else if (choice == 6) {
			if (l.getLength() != 0) {
				l.deleteHead();
				l.showList();
			} 
			else {
				cout<<"There are no element in LinkedList"<<endl;
			}
		}
		else if (choice == 7) {
			if (l.getLength() != 0) {
				l.deleteTail();
				l.showList();
			}
			else {
				cout<<"There are no element in LinkedList"<<endl;
			}
		}
		else if (choice == 8) {
			int position;
			cout<<"Enter position : "; 
			cin>>position;
			if (l.getLength() != 0) {
				l.deletePosition(position);
				l.showList();
			}
			else {
				cout<<"Node cannot be deleted"<<endl;
			}
		}
		else {
			break;
		}
	}
	
	return 0;
}
