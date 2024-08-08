/* Homework 4, Drake Geeteh */
#include <iostream>
#include <vector>

using namespace std;

void printMenu();
void discoverRoutes(int m, int n, int x, int y, vector<int>& path);
bool isValidMove(int m, int n, int x, int y);
void printPath(const vector<int>& path);

int main() {
    string choice;
    int m = -1;
    int n = -1;

    do {
        printMenu();
        cin >> choice;

        if (choice == "0") {
            cout << "Enter new horizontal axis size: ";
            cin >> m;
        } else if (choice == "1") {
            cout << "Enter new vertical axis size: ";
            cin >> n;
        } else if (choice == "2") {
            if (m > 0 && n > 0) {
                vector<int> path;
                discoverRoutes(m, n, 0, 0, path);
            } else {
                cout << "Please set horizontal and vertical axis sizes first. Enter integers > 0." << endl;
            }
        } else if (choice == "3") {
            cout << "Exiting program." << endl;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != "3");

    return 0;
}

void printMenu() {
    cout << "M E N U" << endl;
    cout << "Horizontal Axis (0), Vertical Axis (1), Start Discovery (2), Exit Program (3)" << endl;
    cout << "Choose? ";
}

void discoverRoutes(int m, int n, int x, int y, vector<int>& path) {
    path.push_back(x * n + y + 1);
	
	// base case
    if (x == m - 1 && y == n - 1) {
        printPath(path);
    }
	
	// down
    if (isValidMove(m, n, x + 1, y)) {
        discoverRoutes(m, n, x + 1, y, path);
    }
	
	// right
    if (isValidMove(m, n, x, y + 1)) {
        discoverRoutes(m, n, x, y + 1, path);
    }
	
	// down-right
    if (isValidMove(m, n, x + 1, y + 1)) { // down-right
        discoverRoutes(m, n, x + 1, y + 1, path);
    }

    path.pop_back();
}

bool isValidMove(int m, int n, int x, int y) {
    return x >= 0 && x < m && y >= 0 && y < n;
}

void printPath(const vector<int>& path) {
    for (int i = 0; i < path.size(); ++i) {
        cout << path[i];
        if (i != path.size() - 1) {
            cout << ", ";
        }
    }
    cout << endl;
}