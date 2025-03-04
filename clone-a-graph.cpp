/*

Task : clone a graph

Logic : 
S0. Graph == NULL --> return nullptr;
S1. create clone map globally(purpose -> tracking cloned nodes across recursive calls if we create map ins side a funstion then it going to reset every f. time in every recursive call)
S2. take input node->check if already cloned or not(present in the map or not)->yes ? return cloned node : (make a new node with same val)->(add to map)(go through each node of the original node's neighbor and clone them)(add it into the map)
S3. return map;

simple right✅

*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

unordered_map<Node*, Node*> cloned;

Node* cloneGraph(Node* node) {
    if (!node) return nullptr;

    if (cloned.find(node) != cloned.end()) {
        return cloned[node];
    }

    Node* copy = new Node(node->val);
    cloned[node] = copy;

    for (Node* neighbor : node->neighbors) {
        copy->neighbors.push_back(cloneGraph(neighbor));
    }

    return copy;
}

void printGraph(Node* node, unordered_map<int, bool>& visited) {
    if (!node || visited[node->val]) return;
    
    visited[node->val] = true;
    cout << "Node " << node->val << " -> ";
    for (auto neighbor : node->neighbors) {
        cout << neighbor->val << " ";
    }
    cout << endl;

    for (auto neighbor : node->neighbors) {
        printGraph(neighbor, visited);
    }
}

int main() {
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    node1->neighbors = {node2, node4};
    node2->neighbors = {node1, node3};
    node3->neighbors = {node2, node4};
    node4->neighbors = {node1, node3};

    Node* clonedGraph = cloneGraph(node1);

    unordered_map<int, bool> visited;
    cout << "Original graph:\n";
    printGraph(node1, visited);

    visited.clear();
    cout << "\nCloned graph:\n";
    printGraph(clonedGraph, visited);

    return 0;
}






