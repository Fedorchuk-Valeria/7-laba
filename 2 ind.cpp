/////2 индивидуальное, 11 вариант


#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int natural_shape;
    char number_2system[20];
    number_2system[19] = '\0';
    cout << "Enter a number in natural form:";
    cin >> natural_shape;
    int position = 0;
    int module = abs(natural_shape);
    while(module / 2 != 0)
    {
        position++;
        module = module / 2;
    }
    module = abs(natural_shape);
    int amount_of_numbers = position;
    while (module != 0)
    {
        number_2system[position] = (module % 2) + '0';
        position--;
        module = module / 2;
    }
    cout << endl;
    int number_of_zeros = 7 - (amount_of_numbers + 1);
    char straight_code[9];
    straight_code[8] = '\0';
    if (natural_shape > 0)
        {
            straight_code[0] = '0';
        } else
        {
            straight_code[0] = '1';
        }
    for (int i = 1; i < 8; i++)
    {
        if(i <= number_of_zeros)
        {
            straight_code[i] = '0';
        } else
        {
            straight_code[i] = number_2system[position+1];
            position++;
        }
    }
    cout << "Direct number code: ";
    for (int i = 0; i < 8; i++)
    {
        cout << straight_code[i];
    }
    cout << endl;
    cout << "Additional number code: ";
    if (natural_shape > 0)
    {
        for (int i = 0; i < 8; i++)
    {
        cout << straight_code[i];
    }
    } else
    {
        for (int i = 1; i < 8; i++)
        {
            if (straight_code[i] == '0')
            {
                straight_code[i] = '1';
            }
            else
            {
                straight_code[i] = '0';
            }
        }
        int i = 7;
        while (straight_code[i] != '0')
        {
             i--;
        }
        straight_code[i] = '1';
        for (int k = i + 1; k < 8; k++)
        {
             straight_code[k] = '0';
        }
        for (int l = 0; l < 8; l++)
        {
             cout << straight_code[l];
        }
    }
    return 0;
}
