#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<locale.h>

int main()
{
    setlocale(0, "");
    FILE* f, * g;
    int ammount, a, k;
    if (!(f = fopen("f.txt", "w+t")))
    {
        std::cout << "ќшибка!\n";
        return 0;
    }
    if (!(g = fopen("g.txt", "w + t")))
    {
        std::cout << "ќшибка!\n";
        return 0;
    }
    std::cout<<"¬ведите количество чисел: "; 
    std::cin >> ammount;
    std::cout << "¬ведите к: ";
    std::cin >> k;
    std::cout << "¬ведите числа\n";
    for (int i = 0; i < ammount; i++)
    {
        scanf("%d", &a);
        fprintf(f, "%d ", a);
        if (a > k)
        {
            fprintf(g, "%d ", a);
        }
    }
    fclose(f); 
    fclose(g);
    return 0;
}