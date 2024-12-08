#include <iostream>
using namespace std;
void is(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
int main()
{
    int n, a[100];
    cout << "enter size";
    cin >> n;
    cout << "array elements";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    is(a, n);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}