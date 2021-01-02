/////3 индивидуальное, 11 вариант

#include <iostream>
#include <math.h>

using namespace std;

void transfer(char* number_2system, int number);
void reverse_code(char* straight_code, char* number_2system, int natural_shape);
void sum (char* reversecode1, char* reversecode2, char* reversecode);

int main()
{
    int number1, number2;

    char number_2system1[20];
    number_2system1[19] = '\0';

    char number_2system2[20];
    number_2system2[19] = '\0';

    cout << "Enter number 1: ";
    cin >> number1;
    cout << endl;
    cout << "Enter number 2: ";
    cin >> number2;
    cout << endl;

    transfer(number_2system1, number1);
    transfer(number_2system2, number2);

    char reversecode1[9];
    reversecode1[8] = '\0';
    reverse_code(reversecode1, number_2system1, number1);
    cout << "Reverse code 1: ";
    puts (reversecode1);
    cout << endl;

    char reversecode2[9];
    reversecode2[8] = '\0';
    reverse_code(reversecode2, number_2system2, number2);
    cout << "Reverse code 2: ";
    puts (reversecode2);

    char reversecode [9];
    reversecode[8] = '\0';
    sum (reversecode1, reversecode2, reversecode);
    cout << endl;
    cout << "Sum = ";
    puts (reversecode);
    cout << endl;
    cout << "Answer: ";
    if (reversecode[0] == '0')
    {
        puts (reversecode);
    } else
    {
        for (int i = 1; i < 8; i++)
        {
            if (reversecode[i] == '0')
            {
                reversecode[i] = '1';
            }
            else
            {
                reversecode[i] = '0';
            }
        }
       puts (reversecode);
    }
    return 0;
}

void transfer(char* number_2system, int number)
{
    int position = 0;
    int module = abs(number);
    while(module / 2 != 0)
    {
        position++;
        module = module / 2;
    }
    module = abs(number);
    while (module != 0)
    {
        number_2system[position] = (module % 2) + '0';
        position--;
        module = module / 2;
    }
}

void reverse_code(char* straight_code, char* number_2system, int natural_shape)
{
    int position = 0;
    int module = abs(natural_shape);
    while(module / 2 != 0)
    {
        position++;
        module = module / 2;
    }
    int amount_of_numbers = position;
    int number_of_zeros = 7 - (amount_of_numbers + 1);
    if (natural_shape > 0)
        {
            straight_code[0] = '0';
        } else
        {
            straight_code[0] = '1';
        }
    position = 0;
    for (int i = 1; i < 8; i++)
    {
        if(i <= number_of_zeros)
        {
            straight_code[i] = '0';
        } else
        {
            straight_code[i] = number_2system[position];
            position++;
        }
    }
    if (natural_shape < 0)
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
    }
}


 void sum (char* reversecode1, char* reversecode2, char* reversecode)
 {

     for (int i = 7; i >= 0; i--)
     {
         int a = (reversecode1[i] - '0') + (reversecode2[i] - '0');
         if (a == 2)
         {
             reversecode[i] = '0';
             reversecode1[i-1] = ((reversecode1[i-1] - '0') + 1) + '0';
         } else if (a == 3)
         {
             reversecode[i] = '1';
             reversecode1[i-1] = ((reversecode1[i-1] - '0') + 1) + '0';
         } else
         {
             reversecode[i] = a + '0';
         }

         if (i == 0 && a == 2)
         {
             reversecode[i] = '0';
             reversecode[7] = '1';
         }
         if (i == 0 && a == 3)
         {
             reversecode[i] = '1';
             reversecode[7] = '1';
         }
     }
 }
