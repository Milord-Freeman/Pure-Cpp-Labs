#include <iostream>
#include <clocale>

using namespace std;

int main()
{
    setlocale(0, "rus");
    int n; // Длина последовательности.
    cout << "Input N, please: " << endl; cin >> n;
    int P[100], C[100], PR[100]; // Вспомогательные множества.
    int num=0; // Количество перестановок.

    for (int i=0;i<n;i++)
    {
        P[i]=i+1; C[i]=0; PR[i]=1; // Заполнение вспомогательных множеств перед началом работы програмы.
    }

    //C[n]=0; // Для крайнего правого элемента обнуляем флаг "крайности", дабы алгоритм не завершился заранее.
    num++; // Новая перестановка.

    cout << num << ". "; for (int w=0; w<n; w++) { cout << P[w]; } cout << endl; // Выводим нынешнюю перестановку и переводим курсор на новую строку.

    int i=1;
    while (i<n)
    {
        i=1;
        int x=0;
        while (C[i]==n-i+1)
        {
            if (PR[i]) {PR[i]=0;} else {PR[i]=1;} // Реверс переменной PR, определяющей, будет ли транспозиция влево иль вправо. Иными словами, PR[i] = NOT PR[i];
            C[i]=1;
            if (PR[i]) {x++;}
            i++;
        };
        if (i<n)
        {   // Выполнение транспозиции.
            int k; // Вспомогательный буфер транспозиции.
            if (PR[i]) {k=C[i]+x;} else {k=n-i+1-C[i]+x;} // Определяем, двигаться ли влево иль вправо.
            int buf=P[k]; P[k]=P[k+1]; P[k+1]=buf;  // Транспозиция соседних элементов, то же самое, что и P[k]:=:P[k+1];
            // P[k]=P[k]+P[k+1]; P[k+1]=P[k]-P[k+1]; P[k]=P[k]-P[k+1]; // Транспозиция соседних элементов, то же самое, что и P[k]:=:P[k+1];
            num++; // Новая перестановка.
            cout << num << ". "; for (int w=0; w<n; w++) { cout << P[w]; } cout << endl; // Выводим нынешнюю перестановку и переводим курсор на новую строку.
            C[i]++;
        }
    }

    return 0;
}

