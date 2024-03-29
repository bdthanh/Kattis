#include <iostream>
#include <forward_list>
using namespace std;

// https://visualgo.net/en/list?slide=3-1
struct Vertex { // we can use either C struct or C++/Python/Java class
  int item; // the data is stored here, an integer in this example
  Vertex* next; // this pointer tells us where is the next vertex
};

class SLL {
private:
  Vertex* head;
  Vertex* cursor;
  Vertex* tail;
public:
  SLL() {
    head = NULL;
    cursor = head;
  }

  /**int GetHead() {
    if (head == NULL) return -1; // avoid crashing when SLL is empty
    return head->item;
  }*/
  void MoveCursorToHead() {
    if (head == NULL) return;
    cursor = head;
  }
  void MoveCursorToTail() {
    cursor = tail;
  }
  bool CursorAtHead() {
    return cursor == head;
  }
  bool CursorAtTail() {
    return cursor == tail;
  }
  void InsertHead(char v) {
    Vertex* vtx = new Vertex(); // create new vertex vtx from item v
    vtx->item = v;
    vtx->next = head; // link this new vertex to the (old) head vertex
    head = vtx;
    tail = head;
  }
  void InsertAtHead(char v) {
    // https://visualgo.net/en/list?slide=3-8
    Vertex* vtx = new Vertex(); // create new vertex vtx from item v
    vtx->item = v;
    vtx->next = head; // link this new vertex to the (old) head vertex
    head = vtx; // the new vertex becomes the new head
  }
  void InsertInBetween(char v) {
    Vertex* vtx = new Vertex();
    Vertex* aft = cursor->next;
    vtx->item = v;
    vtx->next = aft;
    cursor->next = vtx;
    cursor = cursor->next;
  } 
  void InsertBeyondTail(char v) {
    Vertex* vtx = new Vertex(); // this is also a C++ code
    vtx->item = v; // create new vertex vtx from item v
    tail->next = vtx; // just link this, as tail is the i = (N-1)-th item
    tail = vtx; // now update the tail pointer
    current = tail;
  }
  void DeleteHead() {
    // https://visualgo.net/en/list?slide=3-15   
    if (head == NULL) return; // avoid crashing when SLL is empty
    Vertex* temp = head; // so we can delete it later
    head = head->next; // book keeping, update the head pointer
    delete temp; // whichVertex* vtx = new Vertex(); is the old head
  }
  void DeleteInBetween() {
    Vertex* pre = ; // traverse to (i-1)-th vertex, O(N)
    Vertex* del = pre->next, aft = del->next;
    pre->next = aft; // bypass del
    delete del;
  }

};

// live demo to extend this thing (which is actually a Stack) to a new class MyStack

int main() {
  SLL l;
  // experiment with this baseline code to familiarise yourself with the very basic idea of Linked List data structure
  l.InsertAtHead(5);
  l.InsertAtHead(2);
  l.InsertAtHead(7);
  cout << l.GetHead() << '\n'; // output 7 as the SLL is 7 (head)->2->5 now
  l.DeleteHead();
  cout << l.GetHead() << '\n'; // output 2 as the SLL is 2 (head)->5 now
  l.DeleteHead();
  cout << l.GetHead() << '\n'; // output 5 as the SLL is 5 (head)
  l.DeleteHead();
  cout << l.GetHead() << '\n'; // -1 (empty SLL), already safe-guarded, won't crash

  cout << "But why reinvent the wheel? Just use std::forward_list (SLL) or std::list (DLL)\n";

  forward_list<int> ll;
  ll.push_front(5);
  ll.push_front(2);
  ll.push_front(7);
  cout << *ll.begin() << '\n';
  ll.pop_front();
  cout << *ll.begin() << '\n';
  ll.pop_front();
  cout << *ll.begin() << '\n';
  ll.pop_front(); // empty after this
  if (!ll.empty())
    cout << *ll.begin() << '\n';
  else
    cout << "already empty, don't do anything\n";

  return 0;
}

