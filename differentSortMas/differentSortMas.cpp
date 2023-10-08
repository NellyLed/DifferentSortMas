#include <iostream>
#include <chrono>
using namespace std;

void FillArray(int* const mas, const int size) {
    for (int i = 0; i < size; i++) {
        mas[i] = rand() % 10 + 90;
    }
}

void FillAnon(int* const mas, const int size) {
    for (int i = 0; i < size; i++) {
        mas[i] = rand() % 91 + 299;
    }
}

void FillAn(int* const mas, const int size) {
    for (int i = 0; i < size; i++) {
        mas[i] = rand() % 300 + 589;
    }
}

void FillAno(int* const mas, const int size) {
    for (int i = 0; i < size; i++) {
        mas[i] = rand() % 590 + 800;
    }
}

void FillAnonmh(int* const mas, const int size) {
    for (int i = 0; i < size; i++) {
        mas[i] = rand() % 801 + 1001;
    }
}

void FillAnonlr(int* const mas, const int size) {
    for (int i = 0; i < size; i++) {
        mas[i] = rand() % 1002 + 1200;
    }
}

void InsertionSort(int* a, int size) {
    int key = 0;
    int i = 0;
    for (int j = 1; j < size; j++) {
        key = a[j];
        i = j - 1;
        while (i >= 0 && a[i] > key) {
            a[i + 1] = a[i];
            i = i - 1;
            a[i + 1] = key;
        }

    }
}

void Shell(int* b, int size) {
    int d = size;
    d = d / 2;
    while (d > 0) {
        for (int i = 0; i < size - d; i++) {
            int j = i;
            while (j >= 0 && b[j] > b[j + d]) {
                int count = b[j];
                b[j] = b[j + d];
                b[j + d] = count;
                j--;
            }
        }
        d = d / 2;
    }
}

void quickSort(int* c, int size) {
    int i = 0;
    int j = size - 1;
    int mid = c[size / 2];
    do
    {
        while (c[i] < mid)
        {
            i++;
        }
        while (c[j] > mid)
        {
            j--;
        }
        if (i <= j)
        {
            int tmp = c[i];
            c[i] = c[j];
            c[j] = tmp;
            i++;
            j--;
        }
    } while (i <= j);

    if (j > 0)
    {

        quickSort(c, j + 1);
    }
    if (i < size)
    {

        quickSort(&c[i], size - i);
    }
}

int main()
{
    setlocale(LC_ALL, "ru");
    float sr1 = 0;
    float sr2 = 0;
    float sr3 = 0;

    float do1 = 0;
    float do2 = 0;
    float do3 = 0;

    float po1 = 0;
    float po2 = 0;
    float po3 = 0;

    float jo1 = 0;
    float jo2 = 0;
    float jo3 = 0;
    float sum1 = 0;
    float sum2 = 0;
    float sum3 = 0;

    float rim1 = 0;
    float rim2 = 0;
    float rim3 = 0;

    int n;
    cout << "Введите количество исходных массивов=\t\t\t\t\t\t\t\t";
    cin >> n;

    int size;
    cout << "Введите размер первого массива=\t\t\t\t\t\t\t\t\t";
    cin >> size;

    int line;
    cout << "Введите размер второго массива=\t\t\t\t\t\t\t\t\t";
    cin >> line;

    int lon;
    cout << "Введите размер третьего массива=\t\t\t\t\t\t\t\t\t";
    cin >> lon;

    int per;
    cout << "Введите размер четвертого массива=\t\t\t\t\t\t\t\t\t";
    cin >> per;

    int sap;
    cout << "Введите размер пятого массива=\t\t\t\t\t\t\t\t\t";
    cin >> sap;

    int luk;
    cout << "Введите размер шестого массива=\t\t\t\t\t\t\t\t\t";
    cin >> luk;

    cout << "ПЕРВЫЙ МАССИВ" << endl;
    cout << "*********Сортировка вставками********" << endl;
    float max1 = 0.00;
    float min1 = 3600.00;
    int* one = new int[size];
    int* one1 = new int[size];
    FillArray(one, size);
    FillArray(one1, size);

    one = new int[size];
    for (int i = 0; i < size; i++) {
        one[i] = one1[i];
    }
    delete[] one1;
    for (size_t i = 1; i <= 10; i++)
    {
        auto start = chrono::high_resolution_clock::now();
        InsertionSort(one, size);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<float>duration = end - start;
        sr1 = sr1 + duration.count();
        if (i == 10)
        {
            do1 = sr1 / 10;
            cout << "Среднее время сортировки вставками первого массива=\t\t\t\t\t\t" << do1 << endl;
        }
        if (duration.count() > max1)
        {
            max1 = duration.count();
        }
        sum1 = max1;
        if (duration.count() < min1)
        {
            min1 = duration.count();
        }
        rim1 = min1;
    }
    po1 = po1 + do1;
    cout << "Максимальное время сортировки вставками первого массива=\t\t\t\t\t" << sum1 << endl;
    cout << "Минимальное время сортировки вставками первого массива=\t\t\t\t\t" << rim1 << endl;
    delete[] one;

    cout << "*********Сортировка Шелла********" << endl;
    float max2 = 0.00;
    float min2 = 3600.00;
    one = new int[size];
    int* one2 = new int[size];
    FillArray(one2, size);
    FillArray(one, size);
    for (int i = 0; i < size; i++)
    {
        one[i] = one2[i];
    }
    delete[] one2;
    for (size_t i = 1; i <= 10; i++)
    {
        auto start = chrono::high_resolution_clock::now();
        Shell(one, size);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<float>duration = end - start;
        sr2 = sr2 + duration.count();
        if (i == 10) {
            do2 = sr2 / 10;
            cout << "Среднее время сортировки Шелла первого массива=\t\t\t\t\t\t\t" << do2 << endl;
        }
        if (duration.count() > max2)
        {
            max2 = duration.count();
        }
        sum2 = max2;
        if (duration.count() < min2)
        {
            min2 = duration.count();
        }

        rim2 = min2;
    }
    po2 = po2 + do2;
    cout << "Максимальное время сортировки Шелла первого массива=\t\t\t\t\t\t" << sum2 << endl;
    cout << "Минимальное время сортировки Шелла первого массива=\t\t\t\t\t\t" << rim2 << endl;
    delete[] one;

    cout << "********Быстрая сортировка********" << endl;
    float max3 = 0.00;
    float min3 = 3600.00;
    one = new int[size];
    int* one3 = new int[size];
    FillArray(one3, size);
    FillArray(one, size);
    for (int i = 0; i < size; i++)
    {
        one[i] = one3[i];
    }
    delete[] one3;
    for (size_t i = 1; i <= 10; i++)
    {
        auto start = chrono::high_resolution_clock::now();
        quickSort(one, size);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<float>duration = end - start;
        sr3 = sr3 + duration.count();
        if (i == 10) {
            do3 = sr3 / 10;
            cout << "Среднее время быстрой сортировки первого массива=\t\t\t\t\t\t\t" << do3 << endl;
        }
        if (duration.count() > max3)
        {
            max3 = duration.count();
        }
        sum3 = max2;
        if (duration.count() < min3)
        {
            min3 = duration.count();
        }

        rim3 = min3;
    }
    po3 = po3 + do3;
    cout << "Максимальное время быстрой сортировки первого массива=\t\t\t\t\t\t" << sum3 << endl;
    cout << "Минимальное время быстрой сортировки первого массива=\t\t\t\t\t\t" << rim3 << endl;
    delete[] one;

    cout << "ВТОРОЙ МАССИВ" << endl;
    cout << "********Сортировка вставками********" << endl;
    float max4 = 0.00;
    float min4 = 3600.00;
    sr1 = 0;
    int* two = new int[line];
    int* two1 = new int[line];
    FillAnon(two, line);
    FillAnon(two1, line);
    delete[] two;
    two = new int[line];
    for (int i = 0; i < line; i++)
    {
        two[i] = two1[i];
    }
    delete[] two1;
    for (size_t i = 1; i <= 10; i++)
    {
        auto start = chrono::high_resolution_clock::now();
        InsertionSort(two, line);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<float>duration = end - start;
        sr1 = sr1 + duration.count();
        if (i == 10) {
            do1 = sr1 / 10;
            cout << "Среднее время сортировки вставками второго массива=\t\t\t\t\t\t" << do1 << endl;
        }
        if (duration.count() > max4)
        {
            max4 = duration.count();
        }
        if (sum1 < max4) {
            sum1 = max4;
        }
        if (duration.count() < min4)
        {
            min4 = duration.count();
        }
        if (rim1 > min4) {
            rim1 = min4;
        }
    }
    po1 = po1 + do1;
    cout << "Максимальное время сортировки вставками второго массива=\t\t\t\t\t" << sum1 << endl;
    cout << "Минимальное время сортировки вставками второго массива=\t\t\t\t\t\t" << rim1 << endl;

    delete[] two;
    cout << "********Сортировка Шелла********" << endl;
    float max5 = 0.00;
    float min5 = 3600.00;
    sr2 = 0;
    two = new int[line];
    int* two2 = new int[line];
    FillAnon(two, line);
    FillAnon(two2, line);
    for (int i = 0; i < line; i++)
    {
        two[i] = two2[i];
    }
    delete[] two2;
    for (size_t i = 1; i <= 10; i++)
    {
        auto start = chrono::high_resolution_clock::now();
        Shell(two, line);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<float>duration = end - start;
        sr2 = sr2 + duration.count();
        if (i == 10) {
            do2 = sr2 / 10;
            cout << "Среднее время сортировки Шелла второго массива=\t\t\t\t\t\t\t" << do2 << endl;
        }
        if (duration.count() > max5)
        {
            max5 = duration.count();
        }
        if (sum2 < max5)
        {
            sum2 = max5;
        }
        if (duration.count() < min5)
        {
            min5 = duration.count();
        }
        if (rim2 > min5)
        {
            rim2 = min5;
        }
    }
    po2 = po2 + do2;
    cout << "Максимальное время сортировки Шелла второго массива=\t\t\t\t\t" << sum2 << endl;
    cout << "Минимальное время сортировки Шелла второго массива=\t\t\t\t\t\t" << rim2 << endl;
    delete[] two;

    cout << "********Быстрая сортировка******** " << endl;
    float max6 = 0.00;
    float min6 = 3600.00;
    sr3 = 0;
    two = new int[line];
    int* two3 = new int[line];
    FillAnon(two, line);
    FillAnon(two3, line);
    for (int i = 0; i < line; i++)
    {
        two[i] = two3[i];
    }
    delete[] two3;
    for (size_t i = 1; i <= 10; i++)
    {
        auto start = chrono::high_resolution_clock::now();
        quickSort(two, line);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<float>duration = end - start;
        sr3 = sr3 + duration.count();
        if (i == 10) {
            do3 = sr3 / 10;
            cout << "Среднее время быстрой сортировки второго массива=\t\t\t\t\t\t\t" << do3 << endl;
        }
        if (duration.count() > max6)
        {
            max6 = duration.count();
        }
        if (sum3 < max6)
        {
            sum3 = max6;
        }
        if (duration.count() < min6)
        {
            min6 = duration.count();
        }
        if (rim3 > min6)
        {
            rim3 = min6;
        }
    }
    po3 = po3 + do3;
    cout << "Максимальное время быстрой сортировки второго массива=\t\t\t\t\t" << sum3 << endl;
    cout << "Минимальное время быстрой сортировки второго массива=\t\t\t\t\t\t" << rim3 << endl;
    delete[] two;

    cout << "ТРЕТИЙ МАССИВ" << endl;
    cout << "********Сортировка вставками********" << endl;
    float max7 = 0.00;
    float min7 = 3600.00;
    sr1 = 0;
    int* three = new int[lon];
    int* three1 = new int[lon];
    FillAn(three, lon);
    FillAn(three1, lon);
    delete[] three;
    three = new int[lon];
        for (int i = 0; i < lon; i++)
        {
            three[i] = three1[i];
        }
    delete[] three1;
    for (size_t i = 1; i <= 10; i++)
    {
        auto start = chrono::high_resolution_clock::now();
        InsertionSort(three, lon);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<float>duration = end - start;
        sr1 = sr1 + duration.count();
        if (i == 10) {
            do1 = sr1 / 10;
            cout << "Среднее время сортировки вставками третьего массива=\t\t\t\t\t\t\t" << do1 << endl;
        }
        if (duration.count() > max7)
        {
            max7 = duration.count();
        }
        if (sum1 < max7)
        {
            sum1 = max7;
        }
        if (duration.count() < min7)
        {
            min7 = duration.count();
        }
        if (rim1 > min7)
        {
            rim1 = min7;
        }
    }
    po1 = po1 + do1;
    cout << "Максимальное время сортировки вставками третьего массива=\t\t\t\t\t" << sum1 << endl;
    cout << "Минимальное время сортировки вставками третьего массива=\t\t\t\t\t\t" << rim1 << endl;
    delete[] three;

    cout << "********Сортировка Шелла********" << endl;
    float max8 = 0.00;
    float min8 = 3600.00;
    sr2 = 0;
    three = new int[lon];
    int* three2 = new int[lon];
    FillAn(three, lon);
    FillAn(three2, lon);
    for (int i = 0; i < lon; i++)
    {
        three[i] = three2[i];
    }
    delete[] three2;
    for (size_t i = 1; i <= 10; i++)
    {
        auto start = chrono::high_resolution_clock::now();
        Shell(three, lon);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<float>duration = end - start;
        sr2 = sr2 + duration.count();
        if (i == 10) {
            do2 = sr2 / 10;
            cout << "Среднее время сортировки Шелла третьего массива=\t\t\t\t\t\t\t" << do2 << endl;
        }
        if (duration.count() > max8)
        {
            max8 = duration.count();
        }
        if (sum2 < max8)
        {
            sum2 = max8;
        }
        if (duration.count() < min8)
        {
            min8 = duration.count();
        }
        if (rim2 > min8)
        {
            rim2 = min8;
        }
    }
    po2 = po2 + do2;
    cout << "Максимальное время сортировки Шелла третьего массива=\t\t\t\t\t" << sum2 << endl;
    cout << "Минимальное время сортировки Шелла третьего массива=\t\t\t\t\t\t" << rim2 << endl;
    delete[] three;

    cout << "********Быстрая сортировка********" << endl;
    float max9 = 0.00;
    float min9 = 3600.00;
    sr3 = 0;
    three = new int[lon];
    int* three3 = new int[lon];
    FillAn(three, lon);
    FillAn(three3, lon);
    for (int i = 0; i < lon; i++)
    {
        three[i] = three3[i];
    }
    delete[] three3;
    for (size_t i = 1; i <= 10; i++)
    {
        auto start = chrono::high_resolution_clock::now();
        quickSort(three, lon);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<float>duration = end - start;
        sr3 = sr3 + duration.count();
        if (i == 10) {
            do3 = sr3 / 10;
            cout << "Среднее время быстрой сортировки третьего массива=\t\t\t\t\t\t\t" << do3 << endl;
        }
        if (duration.count() > max9)
        {
            max9 = duration.count();
        }
        if (sum3 < max9)
        {
            sum3 = max9;
        }
        if (duration.count() < min9)
        {
            min9 = duration.count();
        }
        if (rim3 > min9)
        {
            rim3 = min9;
        }
    }
    po3 = po3 + do3;
    cout << "Максимальное время быстрой сортировки третьего массива=\t\t\t\t\t" << sum3 << endl;
    cout << "Минимальное время быстрой сортировки третьего массива=\t\t\t\t\t\t" << rim3 << endl;
    delete[] three;

    cout << "ЧЕТВЕРТЫЙ МАССИВ" << endl;
    cout << "********Сортировка вставками********" << endl;
    float max10 = 0.00;
    float min10 = 3600.00;
    sr1 = 0;
    int* four = new int[per];
    int* four1 = new int[per];
    FillAno(four, per);
    FillAno(four1, per);
    delete[] four;
    four = new int[per];
    for (int i = 0; i < per; i++)
    {
        four[i] = four1[i];
    }
    delete[] four1;
    for (size_t i = 1; i <= 10; i++)
    {
        auto start = chrono::high_resolution_clock::now();
        InsertionSort(four, per);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<float>duration = end - start;
        sr1 = sr1 + duration.count();
        if (i == 10) {
            do1 = sr1 / 10;
            cout << "Среднее время сортировки вставками четвертого массива=\t\t\t\t\t\t\t" << do1 << endl;
        }
        if (duration.count() > max10)
        {
            max10 = duration.count();
        }
        if (sum1 < max10)
        {
            sum1 = max10;
        }
        if (duration.count() < min10)
        {
            min10 = duration.count();
        }
        if (rim1 > min10)
        {
            rim1 = min10;
        }
    }
    po1 = po1 + do1;
    cout << "Максимальное время сортировки вставками четвертого массива=\t\t\t\t\t" << sum1 << endl;
    cout << "Минимальное время сортировки вставками четвертого массива=\t\t\t\t\t\t" << rim1 << endl;
    delete[] four;

    cout << "********Сортировка Шелла********" << endl;
    float max11 = 0.00;
    float min11 = 3600.00;
    sr2 = 0;
    four = new int[per];
    int* four2 = new int[per];
    FillAn(four, per);
    FillAn(four2, per);
    for (int i = 0; i < per; i++)
    {
        four[i] = four2[i];
    }
    delete[] four2;
    for (size_t i = 1; i <= 10; i++)
    {
        auto start = chrono::high_resolution_clock::now();
        Shell(four, per);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<float>duration = end - start;
        sr2 = sr2 + duration.count();
        if (i == 10) {
            do2 = sr2 / 10;
            cout << "Среднее время сортировки Шелла четвертого массива=\t\t\t\t\t\t\t" << do2 << endl;
        }
        if (duration.count() > max11)
        {
            max11 = duration.count();
        }
        if (sum2 < max11)
        {
            sum2 = max11;
        }
        if (duration.count() < min11)
        {
            min11 = duration.count();
        }
        if (rim2 > min11)
        {
            rim2 = min11;
        }
    }
    po2 = po2 + do2;
    cout << "Максимальное время сортировки Шелла четвертого массива=\t\t\t\t\t" << sum2 << endl;
    cout << "Минимальное время сортировки Шелла четвертого массива=\t\t\t\t\t\t" << rim2 << endl;
    delete[] four;

    cout << "********Быстрая сортировка********" << endl;
    float max12 = 0.00;
    float min12 = 3600.00;
    sr3 = 0;
    four = new int[per];
    int* four3 = new int[per];
    FillAn(three, per);
    FillAn(three3, per);
    for (int i = 0; i < per; i++)
    {
        three[i] = three3[i];
    }
    delete[] three3;
    for (size_t i = 1; i <= 10; i++)
    {
        auto start = chrono::high_resolution_clock::now();
        quickSort(three, per);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<float>duration = end - start;
        sr3 = sr3 + duration.count();
        if (i == 10) {
            do3 = sr3 / 10;
            cout << "Среднее время быстрой сортировки четвертого массива=\t\t\t\t\t\t\t" << do3 << endl;
        }
        if (duration.count() > max12)
        {
            max12 = duration.count();
        }
        if (sum3 < max12)
        {
            sum3 = max12;
        }
        if (duration.count() < min12)
        {
            min12 = duration.count();
        }
        if (rim3 > min12)
        {
            rim3 = min12;
        }
    }
    po3 = po3 + do3;
    cout << "Максимальное время быстрой сортировки четвертого массива=\t\t\t\t\t" << sum3 << endl;
    cout << "Минимальное время быстрой сортировки четвертого массива=\t\t\t\t\t\t" << rim3 << endl;
    delete[] four;

    cout << "ПЯТЫЙ МАССИВ" << endl;
    cout << "********Сортировка вставками********" << endl;
    float max13 = 0.00;
    float min13 = 3600.00;
    sr1 = 0;
    int* five = new int[sap];
    int* five1 = new int[sap];
    FillAnonmh(five, sap);
    FillAnonmh(five1, sap);
    delete[] five;
    five = new int[sap];
    for (int i = 0; i < sap; i++)
    {
        five[i] = five1[i];
    }
    delete[] five1;
    for (size_t i = 1; i <= 10; i++)
    {
        auto start = chrono::high_resolution_clock::now();
        InsertionSort(five, sap);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<float>duration = end - start;
        sr1 = sr1 + duration.count();
        if (i == 10) {
            do1 = sr1 / 10;
            cout << "Среднее время сортировки вставками пятого массива=\t\t\t\t\t\t\t" << do1 << endl;
        }
        if (duration.count() > max13)
        {
            max13 = duration.count();
        }
        if (sum1 < max13)
        {
            sum1 = max13;
        }
        if (duration.count() < min13)
        {
            min13 = duration.count();
        }
        if (rim1 > min13)
        {
            rim1 = min13;
        }
    }
    po1 = po1 + do1;
    cout << "Максимальное время сортировки вставками пятого массива=\t\t\t\t\t" << sum1 << endl;
    cout << "Минимальное время сортировки вставками пятого массива=\t\t\t\t\t\t" << rim1 << endl;
    delete[] five;

    cout << "********Сортировка Шелла********" << endl;
    float max14 = 0.00;
    float min14 = 3600.00;
    sr2 = 0;
    five = new int[sap];
    int* five2 = new int[sap];
    FillAnonmh(five, sap);
    FillAnonmh(five2, sap);
    for (int i = 0; i < sap; i++)
    {
        five[i] = five2[i];
    }
    delete[] five2;
    for (size_t i = 1; i <= 10; i++)
    {
        auto start = chrono::high_resolution_clock::now();
        Shell(five, sap);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<float>duration = end - start;
        sr2 = sr2 + duration.count();
        if (i == 10) {
            do2 = sr2 / 10;
            cout << "Среднее время сортировки Шелла пятого массива=\t\t\t\t\t\t\t" << do2 << endl;
        }
        if (duration.count() > max14)
        {
            max14 = duration.count();
        }
        if (sum2 < max14)
        {
            sum2 = max14;
        }
        if (duration.count() < min14)
        {
            min14 = duration.count();
        }
        if (rim2 > min14)
        {
            rim2 = min14;
        }
    }
    po2 = po2 + do2;
    cout << "Максимальное время сортировки Шелла пятого массива=\t\t\t\t\t" << sum2 << endl;
    cout << "Минимальное время сортировки Шелла пятого массива=\t\t\t\t\t\t" << rim2 << endl;
    delete[] five;

    cout << "********Быстрая сортировка********" << endl;
    float max15 = 0.00;
    float min15 = 3600.00;
    sr3 = 0;
    five = new int[sap];
    int* five3 = new int[sap];
    FillAnonmh(five, sap);
    FillAnonmh(five3, sap);
    for (int i = 0; i < sap; i++)
    {
        five[i] = five3[i];
    }
    delete[] five3;
    for (size_t i = 1; i <= 10; i++)
    {
        auto start = chrono::high_resolution_clock::now();
        quickSort(five, sap);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<float>duration = end - start;
        sr3 = sr3 + duration.count();
        if (i == 10) {
            do3 = sr3 / 10;
            cout << "Среднее время быстрой сортировки пятого массива=\t\t\t\t\t\t\t" << do3 << endl;
        }
        if (duration.count() > max15)
        {
            max15 = duration.count();
        }
        if (sum3 < max15)
        {
            sum3 = max15;
        }
        if (duration.count() < min15)
        {
            min15 = duration.count();
        }
        if (rim3 > min15)
        {
            rim3 = min15;
        }
    }
    po3 = po3 + do3;
    cout << "Максимальное время быстрой сортировки пятого массива=\t\t\t\t\t" << sum3 << endl;
    cout << "Минимальное время быстрой сортировки пятого массива=\t\t\t\t\t\t" << rim3 << endl;
    delete[] five;




    /////////////
    cout << "ШЕСТОЙ МАССИВ" << endl;
    cout << "********Сортировка вставками********" << endl;
    float max16 = 0.00;
    float min16 = 3600.00;
    sr1 = 0;
    int* six = new int[luk];
    int* six1 = new int[luk];
    FillAnonlr(six, luk);
    FillAnonlr(six1, luk);
    delete[] six;
    six = new int[luk];
    for (int i = 0; i < luk; i++)
    {
        six[i] = six1[i];
    }
    delete[] six1;
    for (size_t i = 1; i <= 10; i++)
    {
        auto start = chrono::high_resolution_clock::now();
        InsertionSort(six, luk);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<float>duration = end - start;
        sr1 = sr1 + duration.count();
        if (i == 10) {
            do1 = sr1 / 10;
            cout << "Среднее время сортировки вставками шестого массива=\t\t\t\t\t\t\t" << do1 << endl;
        }
        if (duration.count() > max16)
        {
            max16 = duration.count();
        }
        if (sum1 < max16)
        {
            sum1 = max16;
        }
        if (duration.count() < min16)
        {
            min16 = duration.count();
        }
        if (rim1 > min16)
        {
            rim1 = min16;
        }
    }
    po1 = po1 + do1;
    cout << "Максимальное время сортировки вставками шестого массива=\t\t\t\t\t" << sum1 << endl;
    cout << "Минимальное время сортировки вставками шестого массива=\t\t\t\t\t\t" << rim1 << endl;
    delete[] six;

    cout << "********Сортировка Шелла********" << endl;
    float max17 = 0.00;
    float min17 = 3600.00;
    sr2 = 0;
    six = new int[luk];
    int* six2 = new int[luk];
    FillAnonlr(six, luk);
    FillAnonlr(six2, luk);
    for (int i = 0; i < luk; i++)
    {
        six[i] = six2[i];
    }
    delete[] six2;
    for (size_t i = 1; i <= 10; i++)
    {
        auto start = chrono::high_resolution_clock::now();
        Shell(six, luk);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<float>duration = end - start;
        sr2 = sr2 + duration.count();
        if (i == 10) {
            do2 = sr2 / 10;
            cout << "Среднее время сортировки Шелла шестого массива=\t\t\t\t\t\t\t" << do2 << endl;
        }
        if (duration.count() > max17)
        {
            max17 = duration.count();
        }
        if (sum2 < max17)
        {
            sum2 = max17;
        }
        if (duration.count() < min17)
        {
            min17 = duration.count();
        }
        if (rim2 > min17)
        {
            rim2 = min17;
        }
    }
    po2 = po2 + do2;
    cout << "Максимальное время сортировки Шелла шестого массива=\t\t\t\t\t" << sum2 << endl;
    cout << "Минимальное время сортировки Шелла шестого массива=\t\t\t\t\t\t" << rim2 << endl;
    delete[] six;

    cout << "********Быстрая сортировка********" << endl;
    float max18 = 0.00;
    float min18 = 3600.00;
    sr3 = 0;
    six = new int[luk];
    int* six3 = new int[luk];
    FillAnonlr(six, luk);
    FillAnonlr(six3, luk);
    for (int i = 0; i < luk; i++)
    {
        six[i] = six3[i];
    }
    delete[] six3;
    for (size_t i = 1; i <= 10; i++)
    {
        auto start = chrono::high_resolution_clock::now();
        quickSort(six, luk);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<float>duration = end - start;
        sr3 = sr3 + duration.count();
        if (i == 10) {
            do3 = sr3 / 10;
            cout << "Среднее время быстрой сортировки шестого массива=\t\t\t\t\t\t\t" << do3 << endl;
        }
        if (duration.count() > max18)
        {
            max18 = duration.count();
        }
        if (sum3 < max18)
        {
            sum3 = max18;
        }
        if (duration.count() < min18)
        {
            min18 = duration.count();
        }
        if (rim3 > min18)
        {
            rim3 = min18;
        }
    }
    po3 = po3 + do3;
    cout << "Максимальное время быстрой сортировки шестого массива=\t\t\t\t\t" << sum3 << endl;
    cout << "Минимальное время быстрой сортировки шестого массива=\t\t\t\t\t\t" << rim3 << endl;
    delete[] six;

    cout << "ВРЕМЯ СОРТИРОВОК" << endl;
    cout << "********Время сортировки вставками********" << endl;
    cout << "Максимальное время обработки массивов сортировкой вставками=\t\t\t\t\t" << sum1 << endl;
    cout << "Минимальное время обработки массивов сортировкой вставками=\t\t\t\t\t" << rim1 << endl;
    jo1 = po1 / n;
    cout << "Среднее время обработки массивов сортировкой вставками=\t\t\t\t\t" << jo1 << endl;

    cout << "********Время сортировки Шелла********" << endl;
    cout << "Максимальное время обработки массивов сортировкой Шелла=\t\t\t\t\t" << sum2 << endl;
    cout << "Минимальное время обработки массивов сортировкой Шелла=\t\t\t\t\t" << rim2 << endl;
    jo2 = po2 / n;
    cout << "Среднее время обработки массивов сортировкой Шелла=\t\t\t\t\t" << jo2 << endl;

    cout << "********Время быстрой сортировки********" << endl;
    cout << "Максимальное время обработки массивов быстрой сортировкой,с опорным элементом-центральный=\t" << sum3 << endl;
    cout << "Минимальное время  обработки массивов быстрой сортировкой,с опорным элементом-центральный=\t" << rim3 << endl;
    jo3 = po3 / n;
    cout << "Среднее время обработки массивов  обработки массивов быстрой сортировки,с опорным элементом-центральный=\t\t" << jo3 << endl;
    system("pause");
    return 0;
}

