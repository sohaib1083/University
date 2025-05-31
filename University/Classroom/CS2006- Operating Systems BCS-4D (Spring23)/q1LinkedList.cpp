#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        next = NULL;
    }
};

class LRU {
private:
    Node* head;
    int count;
    int capacity;
    unordered_map<int, Node*> map;

public:
    int page_faults;
    LRU(int capacity) {
        head = new Node(-1);
        count = 0;
        this->capacity = capacity;
        page_faults=0;
    }

    void addNode(Node* node) {
        node->next = head->next;
        head->next = node;
    }

    void deleteNode(Node* prev) {
        Node* temp = prev->next;
        prev->next = temp->next;
        map.erase(temp->val);
        delete temp;
    }

    void update(int val) {
        if (map.find(val) != map.end()) { // milagya
            // delete the last node
            Node* prev = head;
            while (prev->next != NULL) {
                if (prev->next->val == val) {
                    break;
                }
                prev = prev->next;
            }
            Node* temp = map[val];
            prev->next = temp->next;

            // add the node at the beginning
            addNode(temp);
        }
        else {
            page_faults++;
            Node* temp = new Node(val);

            if (count == capacity) {
                // delete the last node
                Node* prev = head;
                while (prev->next->next != NULL) {
                    prev = prev->next;
                }
                deleteNode(prev);
                count--;
            }

            // add to the linked list
            addNode(temp);
            map[val] = temp;
            count++;
        }
    }

    void display() {
        Node* temp = head->next;
        while (temp != NULL) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LRU x(4); // frame size of 4
    vector <int> arr = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = 13;
    for (int i = 0; i < n; i++) {
        x.update(arr[i]);
        x.display();
    }

    cout<<"Number of page faults: "<<x.page_faults;
    return 0;
}
