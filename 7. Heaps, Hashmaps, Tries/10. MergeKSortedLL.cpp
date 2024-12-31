#include <iostream>
#include<queue>
#include<vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

class compare{
    public:
    bool operator()(Node*a, Node* b){
        return a->data > b->data;
    }
};

Node* mergeKLists(vector<Node*> &listArray){
    priority_queue<Node*, vector<Node*>, compare> minHeap;

    int n = listArray.size();

    if(n == 0){
        return NULL;
    }

    // Step 1: Push the head of each list into the minHeap
    for(int i=0; i<n; i++){
        if(listArray[i] != NULL){
            minHeap.push(listArray[i]);
        }
    }

    Node* head = NULL;
    Node* tail = NULL;
    
    // Step 2: Extract nodes from the minHeap and build the merged list
    while(minHeap.size() > 0){
        Node* top = minHeap.top();
        minHeap.pop();

        if(top->next != NULL){
            minHeap.push(top->next);
        }

        if(head == NULL){
            head = top;
            tail = top;
        }else{
            tail->next = top;
            tail = top;
        }
    }
    return head;
}

// Function to print a linked list
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Function to create a new linked list from an array
Node* createList(const vector<int>& values) {
    if (values.empty()) return NULL;

    Node* head = new Node(values[0]);
    Node* current = head;

    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new Node(values[i]);
        current = current->next;
    }

    return head;
}

int main() {
    // Create sample linked lists
    vector<int> list1 = {1, 4, 5};
    vector<int> list2 = {1, 3, 4};
    vector<int> list3 = {2, 6};

    Node* l1 = createList(list1);
    Node* l2 = createList(list2);
    Node* l3 = createList(list3);

    // Add the lists to a vector
    vector<Node*> lists = {l1, l2, l3};

    // Merge k sorted linked lists
    Node* mergedHead = mergeKLists(lists);

    // Print the merged list
    cout << "Merged List: ";
    printList(mergedHead);

    return 0;
}