#include <iostream>
using namespace std;
void is(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[minIndex])
            {
                minIndex = j;
            }
        }
        swap(a[i], a[minIndex]);
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