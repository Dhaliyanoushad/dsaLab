#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *head = nullptr;

void insert(int data)
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

void swap()
{
    node *p = head;
    if (head == nullptr || head->next == nullptr)
    {
        cout << "Khaali Or Kunj Listt";
    }
    else
    {
        int swap;
        cout << "Enter number to Swap From";
        cin >> swap;
        while (p->data != swap)
        {
            p = p->next;
        }
        node *key = p;
        p = head;
        while (p->next != nullptr)
        {
            p = p->next;
        }
        p->next = key;
        node *temp = key->next;
        key->next = head;
        head = temp;
        p = key;
        while (p->next->data != swap)
        {
            p = p->next;
        }
        p->next = nullptr;
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
            p = p->next;
            cout << p->data << "->";
        }
        cout << "\n";
    }
}
int main()
{
    int choice, value, data;
    while (true)
    {
        cout << "\nCHOOSE OPERATION\n1.Insert\n2.Swap\n3.Display\n4.Exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter Data";
            cin >> data;
            insert(data);
            break;
        case 2:
            swap();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
            break;
        default:
            break;
        }
    }

    return 0;
}