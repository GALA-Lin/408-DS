#include <iostream>
/*
  逆置顺序表元素
*/
using namespace std;

#define Element_Type int
#define MAXSIZE 100

struct Linear_List
{
    Element_Type data[MAXSIZE];
    int length = 0;
};

void Reverse(Linear_List &L){
    Element_Type temp;
    for(int i = 0 ;i < L.length /2;i++){
        temp = L.data[i];
        L.data[i] = L.data[L.length - i - 1];
        L.data[L.length - i - 1] = temp;
    }
}

int main()
{
    Linear_List L;
    L.length = 5;
    L.data[0] = 3;
    L.data[1] = 5;
    L.data[2] = 7;
    L.data[3] = 9;
    L.data[4] = 11;
    cout << "Original List: ";
    for(int i = 0;i < L.length;i++){
        cout << L.data[i] << " ";
    }
    cout << endl;
    Reverse(L);
    cout << "Reversed List: ";
    for(int i = 0;i < L.length;i++){
        cout << L.data[i] << " ";
    }
    cout << endl;
    return 0;
}
