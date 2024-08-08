// Homework 6, Drake Geeteh

#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>
#include <string>

using namespace std;

class Graph {
private:
    unordered_map<char, vector<char>> adjacency_list;

public:
    Graph(const unordered_map<char, vector<char>>& adj_list) : adjacency_list(adj_list) {}

    vector<char> depth_first_search(char start_node) {
        unordered_map<char, bool> visited;
        stack<char> stack;
        vector<char> dfs_traversal;

        stack.push(start_node);

        while (!stack.empty()) {
            char node = stack.top();
            stack.pop();

            if (!visited[node]) {
                dfs_traversal.push_back(node);
                visited[node] = true;

                for (char neighbor : adjacency_list[node]) {
                    if (!visited[neighbor]) {
                        stack.push(neighbor);
                    }
                }
            }
        }

        return dfs_traversal;
    }

    vector<char> minimum_path_search(char start_node, char end_node) {
        unordered_map<char, bool> visited;
        queue<pair<char, vector<char>>> q;

        q.push({start_node, {start_node}});

        while (!q.empty()) {
            char node = q.front().first;
            vector<char> path = q.front().second;
            q.pop();

            if (node == end_node) {
                return path;
            }

            if (!visited[node]) {
                visited[node] = true;

                for (char neighbor : adjacency_list[node]) {
                    if (!visited[neighbor]) {
                        vector<char> new_path = path;
                        new_path.push_back(neighbor);
                        q.push({neighbor, new_path});
                    }
                }
            }
        }

        return {};
    }
};

void print_menu() {
    cout << "M E N U" << endl;
    cout << "Depth-First Search (0), Minimum Path Search (1)" << endl;
    cout << "Exit Program (3)" << endl;
}

int main() {
    unordered_map<char, vector<char>> adjacency_list = {
        {'A', {'B', 'C', 'D'}},
        {'B', {'E'}},
        {'C', {'B', 'G'}},
        {'D', {'C', 'G'}},
        {'E', {'C', 'F'}},
        {'F', {'C', 'H'}},
        {'G', {'F', 'H', 'I'}},
        {'H', {'E', 'I'}},
        {'I', {'F'}}
    };

    Graph graph(adjacency_list);

    while (true) {
        print_menu();
        int choice;
        cout << "Choose? ";
        cin >> choice;

        if (choice == 0) {
            char start_node;
            cout << "Enter the starting node: ";
            cin >> start_node;

            vector<char> dfs_result = graph.depth_first_search(start_node);
            cout << "Depth-First Search:";
            for (char node : dfs_result) {
                cout << " " << node;
            }
            cout << endl;
        } else if (choice == 1) {
            char start_node, end_node;
            cout << "Enter the starting node: ";
            cin >> start_node;
            cout << "Enter the ending node: ";
            cin >> end_node;

            vector<char> min_path_result = graph.minimum_path_search(start_node, end_node);
            if (!min_path_result.empty()) {
                cout << "Minimum Path Search:";
                for (char node : min_path_result) {
                    cout << " " << node;
                }
                cout << endl;
            } else {
                cout << "Path does not exist." << endl;
            }
        } else if (choice == 3) {
            cout << "Exiting program" << endl;
            break;
        } else {
            cout << "Invalid choice. Please choose again." << endl;
        }
    }

    return 0;
}