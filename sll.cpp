#include <iostream>
using namespace std;
struct node
{
    int data;
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
        newnode->data = data;
    }
    else
    {
        while (p->next != nullptr)
        {
            p = p->next;
        }
        node *newnode = new node();
        p->next = newnode;
        newnode->next = nullptr;
        newnode->data = data;
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
        newnode->data = data;
    }
    else
    {
        node *newnode = new node();
        newnode->next = head;
        newnode->data = data;
        head = newnode;
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
        head = head->next;
        delete temp;
    }
}
void insertbef(int value, int data)
{
    node *p = head;
    if (head == nullptr)
    {
        cout << "Empty List";
    }
    else
    {
        while (p->next->data != value)
        {
            p = p->next;
        }
        node *newnode = new node();
        newnode->next = p->next;
        newnode->data = data;
        p->next = newnode;
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
        node *temp = p->next->next;
        delete temp;
    }
}
void insertaft(int value, int data)
{
    node *p = head;
    if (head == nullptr)
    {
        cout << "Empty List";
    }
    else
    {
        while (p->data != value)
        {
            p = p->next;
        }
        node *newnode = new node();
        newnode->next = p->next;
        newnode->data = data;
        p->next = newnode;
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
        node *temp = p->next;
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

        while (p != nullptr)
        {
            cout << p->data << "->";
            p = p->next;
        }
        cout << "\n";
    }
}
int main()
{
    int choice, value, data;
    while (true)
    {
        cout << "\nCHOOSE OPERATION\n1.Insert Beginning\n2.Insert End\n3.Insert Before node\n4.Insert After\n5.Delete Beginning\n6.Delete End\n7.Delete before Node\n8.Delete After Node\n9.Display\n10.Exit\n";
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
            cout << "Enter Value to Insert Before and Data to insert";
            cin >> value >> data;
            insertbef(value, data);
            break;
        case 4:
            cout << "Enter Value to Insert After and Data to insert";
            cin >> value >> data;
            insertaft(value, data);
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
            return 0;
            break;
        default:
            break;
        }
    }

    return 0;
}