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

void bs()
{
    node *p1 = head;
    while (p1 != nullptr)
    {
        node *p2 = head;
        while (p2 != nullptr)
        {
            cout << p1->data << " " << p2->data << endl;
            if (p2->data > p2->next->data)
            {
                int temp = p2->data;
                p2->data = p2->next->data;
                p2->next->data = temp;
            }
            p2 = p2->next;
        }
        p1 = p1->next;
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
        cout << "\nCHOOSE OPERATION\n1.Insert\n2.Max\n3.Display\n4.Exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter Data";
            cin >> data;
            insert(data);
            break;
        case 2:
            bs();
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