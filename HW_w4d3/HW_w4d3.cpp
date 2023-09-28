#include <iostream>
#include "List.h"
using namespace std;

int main()
{
    List<int> lists;
    lists.Add(5);
    lists.Add(6);
    lists.Add(7);
    lists.Print();
    lists.Extract();
    lists.Print();
}
