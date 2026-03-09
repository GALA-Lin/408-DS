#include <iostream>
using namespace std;
/*
  删除x元素，a<=x<=b
*/
#define Element_Type int
#define MAXSIZE 100

struct Linear_List
{
    Element_Type data[MAXSIZE];
    int length = 0;
};

void delete_element(Linear_List &L, Element_Type a, Element_Type b)
{
    int i = 0;
    int n = L.length;
    while (i < n)
    {
        if (L.data[i] >= a && L.data[i] <= b)
        {
            L.data[i - 1] = L.data[i];
            i++;
            L.length--;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    Linear_List L;
    L.length = 5;
    L.data[0] = 1;
    L.data[1] = 2;
    L.data[2] = 3;
    L.data[3] = 4;
    L.data[4] = 5;
    cout << "Before delete: ";
    for (int i = 0; i < L.length; i++)
    {
        cout << L.data[i] << " ";
    }
    cout << endl;
    delete_element(L, 1, 5);
    cout << "After delete: ";
    if (L.length <=0)
    {
        cout << "Empty List" << endl;
        return 0;
    }
    for (int i = 0; i < L.length; i++)
    {
        cout << L.data[i] << " ";
    }
    cout << endl;
    return 0;
}