#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    string number_14system;
    string number_16system;
    int i = 0;
    int s, l;
    int number_10system = 0;
    cout << "Введите число в четырнадцатеричной системе счисления: ";
    getline(cin, number_14system);
    cout << endl;
    while (number_14system[i])
    {
        i++;
    }
    l = i;
    for (int k = 0; k<l;k++)
    {
        switch(number_14system[k])
        {
            case 'A': s = 10; break;
            case 'B': s = 11; break;
            case 'C': s = 12; break;
            case 'D': s = 13; break;
            default: s = number_14system[k] - '0';
        }
       number_10system += s * pow(14,i-1);
       i--;
    }
    int position = 0;
    int division = number_10system;
    while(division / 16 != 0)
    {
        position++;
        division = division / 16;
    }
    int number = position;
    while(number_10system != 0)
    {

       switch (number_10system % 16)
       {
           case 10: number_16system[position] = 'A'; break;
           case 11: number_16system[position] = 'B'; break;
           case 12: number_16system[position] = 'C'; break;
           case 13: number_16system[position] = 'D'; break;
           case 14: number_16system[position] = 'E'; break;
           case 15: number_16system[position] = 'F'; break;
           default: number_16system[position] = (number_10system % 16) + '0';
       }
       position--;
       number_10system = number_10system / 16;
    }
    cout << "Это число в шестнадцатеричной системе счисления: ";
    for (int k = 0; k <= number; k++)
    {
        cout << number_16system[k];
    }
    return 0;
}
