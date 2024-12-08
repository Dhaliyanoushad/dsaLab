#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node *prev;
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

void dup()
{
    if (head == nullptr)
    {
        cout << "list is empty\n";
    }
    else
    {
        node *p1 = head;
        node *p2 = head;
        while (p1 != nullptr)
        {
            int c = 1;
            p2 = p1->next;
            while (p2 != nullptr)
            {
                if (p1->data == p2->data)
                {
                    c++;
                    node *temp = p2;
                    if (temp->next == nullptr)
                    {
                        temp->prev->next = nullptr;
                    }
                    else
                    {
                        if (temp->next != nullptr)
                            temp->next->prev = temp->prev;
                        if (temp->prev != nullptr)
                            temp->prev->next = temp->next;
                    }
                    delete temp;
                }
                p2 = p2->next;
            }
            if (c > 1)
            {
                cout << "ELement " << p1->data << "has occured in the list " << c << "times." << endl;
            }
            p1 = p1->next;
        }
    }
}

int main()
{
    int ch, data;
    do
    {
        cout << "menu\n";
        cout << "1.insert at end\n2.display\n3.find duplicates\n";
        cout << "enter choice\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            insertend(4);
            insertend(4);
            insertend(2);
            insertend(5);
            insertend(4);
            insertend(1);
            insertend(3);
            insertend(3);
            insertend(2);
            insertend(1);
            insertend(1);
            insertend(5);
            break;

        case 2:
            display();
            break;

        case 3:
            dup();
            break;

        default:
            cout << "invalid";
            break;
        }
    } while (ch != 0);
    return 0;
}