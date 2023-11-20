#include <iostream>
#include <fstream>
#include <string>

using namespace std;
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

void insertNode(Node*& head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void displayList(Node* head) {
    Node* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void removeNextElement(Node* node, int value) {
    if (node == nullptr || node->next == nullptr) {
        cout << "Cannot remove next element. Node or next node is null." << std::endl;
        return;
    }

    Node* nextNode = node->next;
    if (nextNode->data == value) {
        cout << "Next element has the specified value. Not removing." << std::endl;
        return;
    }

    node->next = nextNode->next;
    delete nextNode;
}

void deleteList(Node*& head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    ifstream file("test.txt");

    if (!file.is_open()) {
        cerr << "Failed to open the file." << endl;
        return 1;
    }

    Node* listHead = nullptr;
    int value;

    while (file >> value) {
        insertNode(listHead, value);
    }

    file.close();

    cout << "Original list: ";
    displayList(listHead);


    int valueToCheck;
    cout << "Enter a value to check for the next element: ";
    cin >> valueToCheck;

    Node* current = listHead;
    while (current) {
        if (current->data == valueToCheck) {
            removeNextElement(current, valueToCheck);
            break;
        }
        current = current->next;
    }

    cout << "List after checking and removing next element: ";
    displayList(listHead);

    deleteList(listHead);

    return 0;
}



