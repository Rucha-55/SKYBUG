#include<iostream>
#include<string>
using namespace std;

class node {
public:
    string task;
    bool is_complete;
    node* next;
};

class list_manager {
public:
    node* head;
    node* create_node();
    void insert_last();
    void display_list();
    void delete_pos();
    void mark_complete();

    list_manager() {
        head = NULL;
    }
};

node* list_manager::create_node() {
    node* temp;
    temp = new node;
    string add_task;
    cout << "\nEnter the task:";
    cin.ignore();  // Added to clear the input buffer
    getline(cin, add_task);
    if (temp == NULL) {
        cout << "\nMemory is not allocated";
        return NULL;
    }
    else {
        temp->task = add_task;
        temp->is_complete = false;  // Initialize as incomplete
        temp->next = NULL;
        return temp;
    }
}

void list_manager::insert_last() {
    node* temp, * s;
    temp = create_node();
    if (head == NULL) {
        head = temp;
        cout << "\nTask inserted at last.";
        return;
    }
    s = head;
    while (s->next != NULL) {
        s = s->next;
    }
    temp->next = NULL;
    s->next = temp;
    cout << "\nTask inserted at last";
}

void list_manager::display_list() {
    node* temp;
    if (head == NULL) {
        cout << "\nList is empty.";
        return;
    }
    temp = head;
    cout << "\nElements of the list are:\n";
    while (temp != NULL) {
        cout << temp->task << " - " << (temp->is_complete ? "Completed" : "Pending") << "\n";
        temp = temp->next;
    }
}

void list_manager::delete_pos() {
    int pos, counter = 0;
    if (head == NULL) {
        cout << "\nList is empty.";
        return;
    }
    cout << "\nEnter the position that you want to delete:";
    cin >> pos;
    node* s, * ptr;
    s = head;
    if (pos == 1) {
        head = s->next;
        delete s;
        cout << "\nElement Deleted.";
        return;
    }
    while (s != NULL) {
        s = s->next;
        counter++;
    }
    if (pos > 0 && pos <= counter) {
        s = head;
        for (int i = 1; i < pos; i++) {
            ptr = s;
            s = s->next;
        }
        ptr->next = s->next;
        delete s;
        cout << "\nElement Deleted at position " << pos;
    }
    else {
        cout << "\nPosition out of range.";
    }
}

void list_manager::mark_complete() {
    int pos, counter = 0;
    if (head == NULL) {
        cout << "\nList is empty.";
        return;
    }
    cout << "\nEnter the position of the task you want to mark as complete:";
    cin >> pos;
    node* s = head;
    while (s != NULL) {
        s = s->next;
        counter++;
    }
    if (pos > 0 && pos <= counter) {
        s = head;
        for (int i = 1; i < pos; i++) {
            s = s->next;
        }
        s->is_complete = true;
        cout << "\nTask marked as completed at position " << pos;
    }
    else {
        cout << "\nPosition out of range.";
    }
}

int main() {
    list_manager obj;
    int ch, menu;
    do {
        cout << "\nSelect the task that you have to perform:";
        cout << "\n1. Insert the data\n2. Display the data\n3. Mark task as completed\n4. Delete the data\n5. Exit\t";
        cin >> ch;
        switch (ch) {
        case 1:
            obj.insert_last();
            break;

        case 2:
            obj.display_list();
            break;

        case 3:
            obj.mark_complete();
            break;

        case 4:
            obj.delete_pos();
            break;

        case 5:
            cout << "\nThank you.....!";
            exit(0);
            break;

        default:
            cout << "\nPlease select a valid option...";
            break;
        }
        cout << "\nDo you want to continue?\n(1 for yes, 0 for no): ";
        cin >> menu;
    } while (menu != 0);
    return 0;
}
