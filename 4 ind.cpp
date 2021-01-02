/////4 индивидуальное, 11 вариант

#include <iostream>

using namespace std;

void addition_func(char* number1, char* number2, char* addition);
void subtraction_func(char* number1, char* number2, char* subtraction);

int main()
{
    setlocale(LC_ALL, "Russian");

    char sign1;
    char sign2;
    char number1_14system[20];
    char number2_14system[20];
    char sum[20];
    sum [19] = '\0';
    char difference[20];
    difference [19] = '\0';

    cout << "Введите первое число в четырнадцатеричной системе счисления (c + или с -): ";
    cin >> sign1;
    gets(number1_14system);

    cout << "Введите второе число в четырнадцатеричной системе счисления (c + или с -): ";
    cin >> sign2;
    gets(number2_14system);

    int length1 = 0;
    while (number1_14system[length1])
    {
        length1++;
    }
    int length2 = 0;
    while (number2_14system[length2])
    {
        length2++;
    }
    int sum1 = 0;
    int sum2 = 0;
    for (int i = 0; i < length1; i++)
    {
        switch (number1_14system[i])
        {
            case 'A': sum1 += 10; break;
            case 'B': sum1 += 11; break;
            case 'C': sum1 += 12; break;
            case 'D': sum1 += 13; break;
            default: sum1 += (number1_14system[i] - '0');
        }
    }
    for (int i = 0; i < length2; i++)
    {
        switch (number2_14system[i])
        {
            case 'A': sum2 += 10; break;
            case 'B': sum2 += 11; break;
            case 'C': sum2 += 12; break;
            case 'D': sum2 += 13; break;
            default: sum2 += (number2_14system[i] - '0');
        }
    }


    cout << "Сумма = ";
    if (sign1 == '+' && sign2 == '+')
    {
       cout << '+';
       addition_func(number1_14system, number2_14system, sum);

    } else if (sign1 == '-' && sign2 == '-')
    {
        cout << '-';
        addition_func(number1_14system, number2_14system, sum);
    } else if (sign1 == '+' && sign2 == '-')
    {
        if (length1 > length2)
        {
            cout << '+';
            subtraction_func(number1_14system, number2_14system, difference);
        } else if (length1 = length2)
        {
            if (sum1 > sum2)
            {
                cout << '+';
                subtraction_func(number1_14system, number2_14system, difference);
            } else
            {
                cout << '-';
                subtraction_func(number2_14system, number1_14system, difference);
            }
        } else
        {
            cout << '-';
            subtraction_func(number2_14system, number1_14system, difference);
        }
    } else if (sign1 == '-' && sign2 == '+')
    {

        if (length1 > length2)
        {
            cout << '-';
            subtraction_func(number1_14system, number2_14system, difference);
        } else if (length1 = length2)
        {
           if (sum1 < sum2)
            {
                cout << '+';
                subtraction_func(number2_14system, number1_14system, difference);
            } else
            {
                cout << '-';
                subtraction_func(number1_14system, number2_14system, difference);
            }
        } else
        {
            cout << '+';
            subtraction_func(number2_14system, number1_14system, difference);
        }
    }


    cout << endl;

    cout << "Разность = ";
    if (sign1 == '+' && sign2 == '+')
    {
        if (length1 > length2)
        {
            cout << '+';
            subtraction_func(number1_14system, number2_14system, difference);
        } else if (length1 = length2)
        {
            if (sum1 > sum2)
            {
                cout << '+';
                subtraction_func(number1_14system, number2_14system, difference);
            } else
            {
                cout << '-';
                subtraction_func(number2_14system, number1_14system, difference);
            }
        } else
        {
            cout << '-';
            subtraction_func(number2_14system, number1_14system, difference);
        }
    } else if (sign1 == '-' && sign2 == '-')
    {
        cout << '-';
        addition_func(number1_14system, number2_14system, sum);

    } else if (sign1 == '+' && sign2 == '-')
    {
       cout << '+';
       addition_func(number1_14system, number2_14system, sum);

    } else if (sign1 == '-' && sign2 == '+')
    {
        cout << '-';
        addition_func(number1_14system, number2_14system, sum);
    }

}



void addition_func(char* number1, char* number2, char* addition)
{
    int m = 0;
    int length1 = 0;
    while (number1[length1])
    {
        length1++;
    }
    int length2 = 0;
    while (number2[length2])
    {
        length2++;
    }
    int l, n;
    if (length1 >= length2)
    {
        l = length1 - 1;
        n = l;
    } else
    {
        l = length2 - 1;
        n = l;
    }
    int i = length1 - 1;
    int k = length2 - 1;
    while (i >= 0 && k >= 0)
    {
        int a, a1, a2;
        switch (number1[i])
        {
            case 'A': a1 = 10; break;
            case 'B': a1 = 11; break;
            case 'C': a1 = 12; break;
            case 'D': a1 = 13; break;
            default: a1 = number1[i] - '0';
        }
        switch (number2[k])
        {
            case 'A': a2 = 10; break;
            case 'B': a2 = 11; break;
            case 'C': a2 = 12; break;
            case 'D': a2 = 13; break;
            default: a2 = number2[k] - '0';
        }
        a = a1 + a2;
        if (a >= 14)
        {
            switch (a - 14)
            {
                case 13: addition[l] = 'D'; break;
                case 12: addition[l] = 'C'; break;
                case 11: addition[l] = 'B'; break;
                case 10: addition[l] = 'A'; break;
                default: addition[l] = (a - 14 + m) + '0';
            }
            m = 1;
        } else if (a >= 10 && a < 14)
        {
            switch (a+m)
            {
                case 13: addition[l] = 'D'; break;
                case 12: addition[l] = 'C'; break;
                case 11: addition[l] = 'B'; break;
                case 10: addition[l] = 'A'; break;
            }
            m = 0;
        } else
        {
            addition[l] = (a + m) + '0';
            m = 0;
        }
        l--;
        i--;
        k--;
    }
    if (i > k)
    {
        while (i > -1)
        {
            addition[i] = ((number1[i] - '0') + m) + '0';
            m = 0;
            i--;
        }
    } else
    {
        while (k > -1)
        {
            addition[k] = ((number2[k] - '0') + m) + '0';
            m = 0;
            k--;
        }
    }
    for (int s = 0; s <= n; s++)
    {
        cout << addition[s];
    }
}

void subtraction_func(char* number1, char* number2, char* subtraction)
{
    int length1 = 0;
    int m = 0;
    while (number1[length1])
    {
        length1++;
    }
    int length2 = 0;
    while (number2[length2])
    {
        length2++;
    }
    int l, n;

    l = length1 - 1;
    n = l;
    int i = length1 - 1;
    int k = length2 - 1;
    while (i >= 0 && k >= 0)
    {
        int a, a1, a2;
        switch (number1[i])
        {
            case 'A': a1 = 10; break;
            case 'B': a1 = 11; break;
            case 'C': a1 = 12; break;
            case 'D': a1 = 13; break;
            default: a1 = number1[i] - '0';
        }
        switch (number2[k])
        {
            case 'A': a2 = 10; break;
            case 'B': a2 = 11; break;
            case 'C': a2 = 12; break;
            case 'D': a2 = 13; break;
            default: a2 = number2[k] - '0';
        }
        a = a1 - a2;
        if (a <= 0)
        {
            switch (a + 14 + m)
            {
                case 13: subtraction[l] = 'D'; break;
                case 12: subtraction[l] = 'C'; break;
                case 11: subtraction[l] = 'B'; break;
                case 10: subtraction[l] = 'A'; break;
                default: subtraction[l] = (a + 14 + m) + '0';
            }
            m = -1;
        } else if (a >= 10 && a < 14)
        {
            switch (a+m)
            {
                case 13: subtraction[l] = 'D'; break;
                case 12: subtraction[l] = 'C'; break;
                case 11: subtraction[l] = 'B'; break;
                case 10: subtraction[l] = 'A'; break;
            }
            m = 0;
        }
        else
        {
            subtraction[l] = (a + m) + '0';
            m = 0;
        }
        l--;
        i--;
        k--;
    }
    while (i > -1)
        {
            subtraction[i] = ((number1[i] - '0') + m) + '0';
            m = 0;
            i--;
        }
    for (int s = 0; s <= n; s++)
    {
        cout << subtraction[s];
    }
}

