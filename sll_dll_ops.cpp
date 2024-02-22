#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct SLLNode {
	char data;
	SLLNode* next;
	SLLNode(char value) : data(value), next(nullptr) {}
};

struct DLLNode {
	char data;
	DLLNode* next;
	DLLNode* prev;
	DLLNode(char value) : data(value), next(nullptr), prev(nullptr) {}
};


class SLinkedList {
	
	private:
		SLLNode* head;
		SLLNode* tail;
		
	public:
		SLinkedList() : head(nullptr), tail(nullptr) {}
		
		// Insert at head
		void insertAtHead(char value) {
			SLLNode* tmp = new SLLNode(value);
			tmp->next = head;
			head = tmp;
			if (!tail) {
				head = tail = tmp;
			}
		};
		
		// Insert at tail
		void insertAtTail(char value) {
			if (!tail) {
				head = tail = new SLLNode(value);
			}
			else {
				tail->next = new SLLNode(value);
				tail = tail->next;
			}
		};
		
		// Delete head
		int deleteHead() {
			if (!head) {
				cout << "List is empty!" << endl;
				return 0;
			}
			
			int el = head->data;
			SLLNode* tmp = head;
			if (head == tail) {
				head = tail = nullptr;
			}
			
			else head = head->next;
			delete tmp;
			return el;
		};
		
		// Delete tail
		int deleteTail() {
			if (!tail) {
				cout << "List is empty!" << endl;
				return 0;
			}
			int el = tail->data;
			if (head == tail) {
				delete head;
				head = tail = nullptr;
				
			}
			else {
				SLLNode* i;
				for (i = head; i->next != tail; i=i->next);
				delete tail;
				tail = i;
				tail->next = nullptr;
			}
			return el;
		};
		
		// Search and delete
		int searchDelete(char value) {
			SLLNode* current = head;
			SLLNode* prev = nullptr;
			int el = current->data;
			while (current && current->data != value) {
				prev = current;
				current = current->next;
			}
			if (!current) {
				cout << "There is no value '" << value << "' existing in the list." << endl;
			}
			else if (!prev) { // if the head is the target node
				deleteHead();
			}
			else {
				if (current == tail)  { // if the tail is the target node
					tail = prev; // because we are deleting the current and want to maintain our tail pointer. we could call deleteTail() here, but would have to traverse the entire list again.
				}
				int el = current->data;
				prev->next = current->next;
				delete current;
			}
			return el;
		};
		
		// Print SLL
		void printSLL() {
			SLLNode* temp = head;
			while (temp) {
				cout << temp->data << " ";
				temp = temp->next;
			}
			cout << endl;
		};

};

class DLinkedList {
	
	private:
		DLLNode* head;
		DLLNode* tail;
		
	public:
		DLinkedList() : head(nullptr), tail(nullptr) {}
		
		// Insert at head
		void insertAtHead(char value) {
			if (!head) {
				head = tail = new DLLNode(value);
			}
			else {
				DLLNode* tmp = new DLLNode(value);
				tmp->next = head;
				tmp->next->prev = tmp;
				head = tmp;
			}
		};
		
		// Insert at tail
		void insertAtTail(char value) {
			if (!tail) {
				head = tail = new DLLNode(value);
			}
			else {
				tail->next = new DLLNode(value);
				tail->next->prev = tail;
				tail = tail->next;
			}
		}
		
		// Delete head
		int deleteHead() {
			if (!head) {
				cout << "List is empty!" << endl;
				return 0;
			}
			int el = head->data;
			DLLNode* tmp = head;
			if (head == tail) {
				head = tail = nullptr;
			}
			else {
				head = head->next;
				head->prev = nullptr;
			}
			delete tmp;
			return el;
		}
		
		// Delete Tail
		int deleteTail() {
			if (!tail) {
				cout << "List is empty!" << endl;
				return 0;
			}
			int el = tail->data;
			if (head == tail) {
				delete head;
				head = tail = nullptr;
			}
			else {
				tail = tail->prev; // no need to traverse entire list in a dll
				delete tail->next;
				tail->next = nullptr;
			}
			return el;
		}
		
		// Search and delete
		void searchDelete(char value) {
			DLLNode* i;
			for (i = head; i && i->data != value; i=i->next);
			if (!i) {
				cout << "There is no value '" << value << "' existing in the list." << endl;
			}
			else if (!i->prev) {
				deleteHead();
			}
			else if (!i->next) {
				deleteTail();
			}
			else {
				i->prev->next = i->next;
				i->next->prev = i->prev;
				delete i;
			}
		}
		
		// Print dll
		void printDLL() {
			DLLNode* tmp = head;
			while (tmp) {
				cout << tmp->data << " ";
				tmp = tmp->next;
			}
			cout << endl;
		};
};


int main() {

	SLinkedList sll;
	DLinkedList dll;
	string choice;
	char value;
	
	do {
		
		cout << "\t\tM E N U" << endl;
		cout << "SLL: IH(0), IT(1), DH(2), DT(3), SD(4), PS(5)" << endl;
		cout << "DLL: IH(6), IT(7), DH(8), DT(9), SD(10), PD(11)" << endl;
		cout << "Exit Program (12)" << endl;
		cout << "\t\tChoose?" << endl;
		
		cin >> choice;
		
		// For singly linked list
		// IH(0) Insert Head
		if (choice == "0") {
			cout << "Enter value to insert at head: ";
            cin >> value;
            sll.insertAtHead(value);
		}
		
		// IT(1) Insert Tail
		else if (choice == "1") {
			cout << "Enter value to insert at tail: ";
			cin >> value;
			sll.insertAtTail(value);
		}
		
		// DH(2) Delete Head
		else if (choice == "2") {
			sll.deleteHead();
		}
		
		// DT(3) Delete Tail
		else if (choice == "3") {
			sll.deleteTail();
		}
		
		// SD(4) Search and Delete some Node
		else if (choice == "4") {
			cout << "Enter value to delete from list: ";
			cin >> value;
			sll.searchDelete(value);
		}
		
		// PS(5) Print SLL
		else if (choice == "5") {
			cout << "Singly Linked List: ";
            sll.printSLL();
		}
		
		// For doubly linked lists
		// IH(6) Insert Head 
		else if (choice == "6") {
			cout << "Enter value to insert at head: ";
			cin >> value;
			dll.insertAtHead(value);
		}
		
		// IT(7) Insert tail
		else if (choice == "7") {
			cout << "Enter value to insert at tail: ";
			cin >> value;
			dll.insertAtTail(value);
		}
		
		// DH(8) Delete head
		else if (choice == "8") {
			dll.deleteHead();
		}
		
		// DT(9) Delete tail
		else if (choice == "9") {
			dll.deleteTail();
		}
		
		// SD(10) Search and delete
		else if (choice == "10") {
			cout << "Enter value to delete from list: ";
			cin >> value;
			dll.searchDelete(value);
		}
		
		// PD(11) Print DLL
		else if (choice == "11") {
			cout << "Doubly Linked List: ";
			dll.printDLL();
		}
		
		// (12) Exit Program
		else if (choice == "12") {
			cout << "Exiting program..." << endl;
			exit(0);
		}
		
		// Miscellaneous input
		else {
			cout << "Invalid input: Please enter an integer 1-12 for corresponding menu functions." << endl;
		}
		
	} while(choice != "12");
	
	
	return 0;
}