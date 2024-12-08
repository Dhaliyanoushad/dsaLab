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

void avg()
{
    int count = 0;
    node *p = head;
    float avg = 0;
    while (p != nullptr)
    {
        avg = avg + p->data;
        count++;
        p = p->next;
    }
    cout << "Avg Element is " << avg / count;
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
        cout << "\nCHOOSE OPERATION\n1.Insert\n2.Avg\n3.Display\n4.Exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter Data";
            cin >> data;
            insert(data);
            break;
        case 2:
            avg();
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