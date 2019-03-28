//
// Code Contributor(s): Rajeev Ranjan
//

class Node {
  int data;
  Node next;
}

public class LinkedList {

  Node head;
  Node tail;

  LinkedList() {
      head = null;
      tail = null;
  }

  void headInsert(int data) {
      Node newNode = new Node();
      newNode.data = data;
      if(head == null && tail == null) {
          newNode.next = null;
          head = newNode;
          tail = newNode;
      }
      else {
          newNode.next = head;
          head = newNode;
      }
  }

  void tailInsert(int data) {
      Node newNode = new Node();
      newNode.data = data;
      if(head == null && tail == null) {
          newNode.next = null;
          head = newNode;
          tail = newNode;
      }
      else {
          newNode.next = null;
          tail.next = newNode;
          tail = newNode;
      }
  }

  void display() {
      Node temp = head;
      while(temp != null)
      {
          System.out.print(temp.data + " ");
          temp = temp.next;
      }
  }

  public static void main(String[] args) {
        LinkedList l = new LinkedList();
        l.headInsert(10);
        l.headInsert(9);
        l.headInsert(8);
        l.tailInsert(11);
        l.tailInsert(12);
        l.display();
  }
}
