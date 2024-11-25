#include <iostream>
#include <Windows.h>
#include <limits>
#include <iomanip>
#include <cstdlib>
#include <stdlib.h>
using namespace std;
const int N = 6;
void printArr(int arr[N][N]) {
    int n = sizeof(arr) / sizeof(*arr);
    int m = sizeof(*arr) / sizeof(**arr);
    int* end = *arr + n * n - 1;
    for (int* ptr = *arr; ptr <= end; ptr++) {
        cout << *ptr << "\t";
        if ((ptr - *arr) % m == 0)
            cout << "\n";
    }
}
void mainMenu() {
    system("cls");
    cout << "Выберите действие: " << endl;
    cout << "1. Заполнить матрицу спиралью" << endl;
    cout << "2. Заполнить матрицу змейкой" << endl;
    cout << "3. Переставить местами блоки матрицы" << endl;
    cout << "4. Сортировать элементы матрицы" << endl;
    cout << "5. Изменить элементы матрицы" << endl;
    cout << "6. Выход" << endl;
    cout << "Введите число, соответствующее нужному вам действию: ";
}
void choosingSortMenu() {
    system("cls");
    cout << "Выберите сортировку: " << endl;
    cout << "1. Bubble sort " << endl;
    cout << "2. Shaker sort" << endl;
    cout << "3. Comb sort" << endl;
    cout << "4. Insert sort" << endl;
    cout << "5. Quick sort" << endl;
    cout << "6. Выход" << endl;
    cout << "Введите число, соответствующее нужному вам действию: ";
}
void fillMatrixSpiral(int arr[N][N]) {
    HANDLE hStdout;
    COORD destCoord;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    int k = 0;
    int* p = arr[0];
    int* d = (p + N*N -1);
    do {
        for (int x = k; x < N - k; x++) {
            destCoord.X = x * 10;
            destCoord.Y = k * 4;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << *(p + k*4*N + x) << '\r';
            Sleep(100);
            cout.flush();
        }
        for (int y = k + 1; y < N - k; y++) {
            destCoord.X = (N - 1 - k) * 10;
            destCoord.Y = y * 4;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << *(p + k*4*N + y) << '\r';
            Sleep(100);
            cout.flush();
        }
        for (int x = N - 2 - k; x >= k; x--) {
            destCoord.X = x * 10;
            destCoord.Y = (N - 1 - k) * 4;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << *(p + N * N - 1 - (k * 4 * N + x)) << '\r';
            Sleep(100);
            cout.flush();
        }
        for (int y = N - 2 - k; y > k; y--) {
            destCoord.X = k * 10;
            destCoord.Y = y * 4;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << *(p + N * N - 1 - (k * 5 * N + y)) << '\r';
            Sleep(100);
            cout.flush();

        }
        k += 1;
    } while (!(k == N));
    destCoord.X = 0;
    destCoord.Y = 25;
    SetConsoleCursorPosition(hStdout, destCoord);
}
void fillMatrixWorm(int arr[N][N]) {
    HANDLE hStdout;
    COORD destCoord;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    int k = 0;
    int* p = arr[0];
    int* d = (p + N * N - 1);
    do {
        for (int i = 0; i < N; i++) {
            if (k % 2 == 0) {
                for (int y = N - 1; y > -1; y--) {
                    destCoord.X = (i) * 10;
                    destCoord.Y = y * 4;
                    SetConsoleCursorPosition(hStdout, destCoord);
                    cout << *(p + y + i) << '\r';
                    Sleep(100);
                    cout.flush();
                }
            }
            else {
                for (int y = 0; y < N; y++) {
                    destCoord.X = (i) * 10;
                    destCoord.Y = y * 4;
                    SetConsoleCursorPosition(hStdout, destCoord);
                    cout << *(d - (y + i + k*N)) << '\r';
                    Sleep(100);
                    cout.flush();
                }
            }
            k++;
        }
    } while (!(k == N));
    destCoord.X = 0;
    destCoord.Y = 25;
    SetConsoleCursorPosition(hStdout, destCoord);
}
void swapBlocks(int arr[N][N]) {
    int typeswap;
    int* p = arr[0];
    cout << "Choose type of swap(1,2,3,4)\n";
    cin >> typeswap;
    switch (typeswap) {
    case 1: {
        for (int i = 0; i < (N / 2); i++) {
            for (int g = 0; g < (N / 2); g++) {
                swap(*(p + i + g), *(p + N / 2 + g));
                swap(*(p + i + g + N / 2), *(p + i + N / 2 + g + N / 2));
                swap(*(p + i + N / 2 + g + N / 2), *(p + i + g));
                swap(*(p + i + g), *(p + N / 2 + i + g));
            }
        }
        break;
    }

    case 2: {
        /*for (int i = 0; i < (n / 2); i++) {
            for (int g = 0; g < (n / 2); g++) {
                swap(arra[i][g], arra[i + n / 2][g + n / 2]);
                swap(arra[i][g + n / 2], arra[i + n / 2][g]);
            }
        }*/
        break;
    }
    case 3: {

        /*for (int i = 0; i < (n / 2); i++) {
            for (int g = 0; g < (n / 2); g++) {
                swap(arra[i][g], arra[i + n / 2][g]);
                swap(arra[i][g + n / 2], arra[i + n / 2][g + n / 2]);
            }
        }*/
        break;
    }
    case 4: {
        /*for (int i = 0; i < (n / 2); i++) {
            for (int g = 0; g < (n / 2); g++) {
                swap(arra[i][g], arra[i][g + n / 2]);
                swap(arra[i + n / 2][g], arra[i + n / 2][g + n / 2]);
            }
        }*/
        break;

    }
    }
}
int checkInput(int floor = (numeric_limits<int>::min)(), int ceiling = (numeric_limits<int>::max)()) {
    int num;
    cin >> num;
    while (cin.fail() || cin.peek() != '\n' || num > ceiling || num < floor) {
        cin.clear();
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        cout << "Введите корректное значение: ";
        cin >> num;
    }
    return num;
}
void main() {
    setlocale(0, "");
    srand(time(NULL));
    int arr[N][N];
    for (int j = 0; j < N; j++)
        for (int i = 0; i < N; i++)   
            arr[i][j] = 1 + rand() % (N * N);
    cin.sync();
    int choice;
    do {
        mainMenu();
        choice = checkInput(1, 6);
        switch (choice) {
        case 1: {
            system("cls");
            fillMatrixSpiral(arr);    
            int n = sizeof(arr) / sizeof(*arr);
            int m = sizeof(*arr) / sizeof(**arr);
            int* end = *arr + n * n - 1;
            for (int* ptr = *arr; ptr <= end; ptr++) {
                cout << *ptr << "\t";
                if ((ptr - *arr) % m == 0)
                    cout << "\n";
            }
            break;
        }
        case 2: {
            system("cls");
            fillMatrixWorm(arr);
            int n = sizeof(arr) / sizeof(*arr);
            int m = sizeof(*arr) / sizeof(**arr);
            int* end = *arr + n * n - 1;
            for (int* ptr = *arr; ptr <= end; ptr++) {
                cout << *ptr << "\t";
                if ((ptr - *arr) % m == 0)
                    cout << "\n";
            }
            break;
        }
        case 3: {
            break;
        }
        case 4: {
            break;
        }
        case 5: {
            break;
        }
        }
        if (choice != 6)
            system("pause");
    } while (choice != 6);
}




