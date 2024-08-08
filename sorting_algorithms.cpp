/* Homework 6 Bonus, Drake Geeteh */

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

void display_menu() {
    cout << "M E N U" << endl;
    cout << "Input Data (0), Insertion Sort (1), Selection Sort (2)," << endl;
    cout << "Bubble Sort (3), Shell Sort (4), Exit Program (5)" << endl;
}

void insertion_sort(vector<int>& arr) {
    for (int i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selection_sort(vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; ++i) {
        int min_index = i;
        for (int j = i + 1; j < arr.size(); ++j) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        swap(arr[min_index], arr[i]);
    }
}

void bubble_sort(vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; ++i) {
        for (int j = 0; j < arr.size() - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void shell_sort(vector<int>& arr) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void print_array(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr;
    while (true) {
        display_menu();
        cout << "Choose? ";
        char choice;
        cin >> choice;

        if (choice == '0') {
            cin.ignore();
            string input;
            getline(cin, input);
            stringstream ss(input);
            int num;
            arr.clear();
            while (ss >> num) {
                arr.push_back(num);
            }
            print_array(arr);
        } else if (choice == '1') {
            insertion_sort(arr);
            print_array(arr);
        } else if (choice == '2') {
            selection_sort(arr);
            print_array(arr);
        } else if (choice == '3') {
            bubble_sort(arr);
            print_array(arr);
        } else if (choice == '4') {
            shell_sort(arr);
            print_array(arr);
        } else if (choice == '5') {
            cout << "Exiting program..." << endl;
            break;
        } else {
            cout << "Invalid choice. Please choose again." << endl;
        }
    }
    return 0;
}