#include <iostream>
using namespace std;
struct node
{
    int data;
    node *prev;
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
        newnode->next = head;
        newnode->data = data;
    }
    else
    {
        while (p->next != head)
        {
            p = p->next;
        }
        node *newnode = new node();
        p->next = newnode;
        newnode->next = head;
        newnode->data = data;
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
        newnode->data = data;
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
        newnode->data = data;
        p->next = newnode;
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
        do
        {
            cout << p->data << "->";
            p = p->next;
        } while (p != head);

        cout << "\n";
    }
}

void rotate()
{
    node *p = head;
    int n, c = 0;
    cout << "Enter degree";
    cin >> n;
    while (p->next != head && c < n)
    {
        c++;
        p = p->next;
    }
    head = p;
}

int main()
{
    int choice, data;
    while (true)
    {
        cout << "\nCHOOSE OPERATION\n1.Insert\n2.Insert Before node\n3.Insert After\n4.Display\n5.Rotate\n11.Exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            insert(4);
            insert(9);
            insert(5);
            insert(1);
            insert(2);
            break;
        case 2:
            insertbef();
            break;
        case 3:
            insertaft();
            break;
        case 4:
            display();
            break;
        case 5:
            rotate();
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