#include <iostream>
#include <limits>
#include <string>
#include <cstdint>


int get_positive_integer (const std::wstring& prompt)
{
    int32_t number = 0;
    bool is_input_valid = false;

    while (!is_input_valid)
    {
        std::wcout << prompt;

        if (std::wcin >> number) {
            if (number > 0)
            {
                is_input_valid = true;
            }
            else
            {
                std::wcout << L"Ошибка: число должно быть положительным!\n"
                           << std::endl;
            }
        }
        else
        {
            std::wcout << L"Ошибка: введите корректное целое число!\n"
                       << std::endl;

            std::wcin.clear();
            std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    return number;
}


int main ()
{
    setlocale(LC_ALL, "");

    std::wcout << L"Программа для поиска большего числа из двух\n"
               << std::endl;

    int32_t num1 = get_positive_integer(L"Введите первое целое положительное число: ");
    int32_t num2 = get_positive_integer(L"Введите второе целое положительное число: ");

    std::wcout << L"\nРезультат:" << std::endl;
    std::wcout << L"Первое число: " << num1 << std::endl;
    std::wcout << L"Второе число: " << num2 << std::endl;

    if (num1 > num2)
    {
        std::wcout << L"Большее число: " << num1 << std::endl;
    }
    else if (num2 > num1)
    {
        std::wcout << L"Большее число: " << num2 << std::endl;
    }
    else
    {
        std::wcout << L"Числа равны: " << num1 << std::endl;
    }

    return 0;
}
