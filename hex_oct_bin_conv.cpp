/* Homework #3, Drake Geeteh */

#include <iostream>

using namespace std;

// Node for linked list
struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

// Stack implementation with linked list
class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow!" << endl;
            return -1;
        }
        int data = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

// Decimal to binary, octal, or hexadecimal
string decimalToBase(int decimal, int base) {
    Stack stack;

    while (decimal > 0) {
        int remainder = decimal % base;
        stack.push(remainder);
        decimal /= base;
    }

    string result = "";
    while (!stack.isEmpty()) {
        int digit = stack.pop();
        if (base == 16 && digit > 9) {
            result += 'A' + (digit - 10);
        } else {
            result += to_string(digit);
        }
    }

    return result;
}

void menu() {
    cout << "M E N U" << endl;
    cout << "Binary (0), Octal (1), Hexadecimal (2)" << endl;
    cout << "Exit Program (3)" << endl;
	cout << "Choose? ";
}

int main() {
    while (true) {
        menu();
        string choice;
		cin >> choice;
		
		if (choice == "3") {
			cout << "Exiting program." << endl;
			exit(1);
		} else if (choice == "2") {
			int decimalNumber;
			cout << "Enter the decimal number: ";
			cin >> decimalNumber;
            int base = 16;
			string result = decimalToBase(decimalNumber, base);
			cout << "Result: " << result << endl;
        } else if (choice == "1") {
			int decimalNumber;
			cout << "Enter the decimal number: ";
			cin >> decimalNumber;
            int base = 8;
			string result = decimalToBase(decimalNumber, base);
			cout << "Result: " << result << endl;
        } else if (choice == "0") {
			int decimalNumber;
			cout << "Enter the decimal number: ";
			cin >> decimalNumber;
            int base = 2;
			string result = decimalToBase(decimalNumber, base);
			cout << "Result: " << result << endl;
        } else {
			cout << "Invalid input. Please enter a number provided by the menu." << endl;
			continue;
		}
    }
    return 0;
}