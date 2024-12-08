#include <iostream>
using namespace std;
struct node
{
    int data;
    node *prev;
    node *next;
};
node *head = nullptr;

void insertend(int data)
{
    node *p = head;
    if (head == nullptr)
    {
        node *newnode = new node();
        head = newnode;
        newnode->next = nullptr;
        newnode->prev = nullptr;
        newnode->data = data;
    }
    else
    {
        while (p->next != nullptr)
        {
            p = p->next;
        }
        node *newnode = new node();
        newnode->next = nullptr;
        newnode->prev = p;
        p->next = newnode;
        newnode->data = data;
    }
}
void insertbeg(int data)
{
    node *p = head;
    if (head == nullptr)
    {
        node *newnode = new node();
        head = newnode;
        newnode->next = nullptr;
        newnode->prev = nullptr;
        newnode->data = data;
    }
    else
    {
        node *newnode = new node();
        newnode->next = p;
        newnode->prev = nullptr;
        newnode->data = data;
        p->prev = newnode;
        head = newnode;
    }
}
void insertbef()
{
    node *p = head;
    if (head == nullptr)
    {
        cout << "Empty List";
    }
    else
    {
        int value, data;
        cout << "Enter Value to Insert Before and Data to insert";
        cin >> value >> data;
        while (p->next->data != value)
        {
            p = p->next;
        }
        node *newnode = new node();
        newnode->next = p->next;
        newnode->prev = p;
        newnode->data = data;
        p->next->prev = newnode;
        p->next = newnode;
    }
}
void insertaft()
{
    node *p = head;
    if (head == nullptr)
    {
        cout << "Empty List";
    }
    else
    {
        int value, data;
        cout << "Enter Value to Insert After and Data to insert";
        cin >> value >> data;
        while (p->data != value)
        {
            p = p->next;
        }
        node *newnode = new node();
        newnode->next = p->next;
        newnode->prev = p;
        newnode->data = data;
        p->next->prev = newnode;
        p->next = newnode;
    }
}

void deleteend()
{
    node *p = head;
    if (head == nullptr)
    {
        cout << "List Khaali";
    }
    else
    {
        while (p->next->next != nullptr)
        {
            p = p->next;
        }
        p->next = nullptr;
        node *temp = p->next;
        delete temp;
    }
}

void deletebeg()
{
    node *p = head;
    if (head == nullptr)
    {
        cout << "List Khaali";
    }
    else
    {
        node *temp = head;
        head->next->prev = nullptr;
        head = head->next;
        delete temp;
    }
}

void deletebef()
{
    if (head == nullptr)
    {
        cout << "Empty List";
    }
    else
    {
        int value;
        cout << "Enter Value to Delete Before";
        cin >> value;
        node *p = head;
        while (p->next->next->data != value)
        {
            p = p->next;
        }
        p->next = p->next->next;
        p->next->next->prev = p;
        node *temp = p->next->next;
        delete temp;
    }
}

void deleteaft()
{
    if (head == nullptr)
    {
        cout << "Empty List";
    }
    else
    {
        node *p = head;
        int value;
        cout << "Enter Value to Delete After";
        cin >> value;
        while (p->data != value)
        {
            p = p->next;
        }
        p->next = p->next->next;
        p->next->next->prev = p;
        node *temp = p->next->next;
        delete temp;
    }
}
void display()
{
    node *p = head;
    if (head == nullptr)
    {
        cout << "Empty List";
    }
    else
    {

        while (p->next != nullptr)
        {
            cout << p->data << " <-> ";
            p = p->next;
        }
        cout << p->data << " <-> nullptr";

        cout << "\n";
    }
}
void displayRev()
{
    node *p = head;
    if (head == nullptr)
    {
        cout << "Empty List";
    }
    else
    {

        while (p->next != nullptr)
        {
            p = p->next;
        }
        while (p->prev != nullptr)
        {
            cout << p->data << " <-> ";
            p = p->prev;
        }
        cout << p->data << " <-> nullptr";
        cout << "\n";
    }
}
int main()
{
    int choice, data;
    while (true)
    {
        cout << "\nCHOOSE OPERATION\n1.Insert Beginning\n2.Insert End\n3.Insert Before node\n4.Insert After\n5.Delete Beginning\n6.Delete End\n7.Delete before Node\n8.Delete After Node\n9.Display Nere\n10.Display thirich\n11.Exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter Data";
            cin >> data;
            insertbeg(data);
            break;
        case 2:
            cout << "Enter Data";
            cin >> data;
            insertend(data);
            break;
        case 3:
            insertbef();
            break;
        case 4:
            insertaft();
            break;
        case 5:
            deletebeg();
            break;
        case 6:
            deleteend();
            break;
        case 7:
            deletebef();
            break;
        case 8:
            deleteaft();
            break;
        case 9:
            display();
            break;
        case 10:
            displayRev();
            break;
        case 11:
            return 0;
            break;
        default:
            break;
        }
    }

    return 0;
}