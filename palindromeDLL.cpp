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

void palindundu()
{
    node *f = head;
    node *r = head;
    if (head == nullptr)
    {
        cout << "Empty List";
    }
    else
    {
        while (r->next != nullptr)
        {
            r = r->next;
        }
        int count = 0;
        while (r->prev != nullptr && f->next != nullptr)
        {
            if (f->data != r->data)
            {
                count = 1;
            }
            f = f->next;
            r = r->prev;
        }
        if (count == 1)
        {
            cout << "List Is not palindundu";
        }
        else
        {
            cout << "List Is Palindundu";
        }
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
        cout << "\nCHOOSE OPERATION\n1.Insert End\n2.Display Nere\n3.Display thirich\n4.Palindundu Check\n5.Exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter Data";
            cin >> data;
            insertend(data);
            break;
        case 2:
            display();
            break;
        case 3:
            displayRev();
            break;
        case 4:
            palindundu();
            break;
        case 5:
            return 0;
            break;
        default:
            break;
        }
    }

    return 0;
}