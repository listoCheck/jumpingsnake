#include <iostream>
#include <vector>
#include <cmath>
#include "windows.h"
using namespace std;
int c[20][45]{  };

int gonka() {
    for (int a = 0; a < 20; a++) {
        for (int b = 0; b < 45; b++) {
            if (c[a][b] == 0) {
                cout << "*" << ' ';
            }
            else {
                cout << "0" << ' ';
            }
        }
        cout << '\n';
    }
    for (int jk = 0; jk < 5; jk++) {
        cout << '\n';
    }
    return 0;
}


int zxc(int k, int l, int timer1) {
    int kit = 5 + k;
    int i = k, j = l;
    for (int u = 0; u < ceil(kit / 2) + 1; u++) {
        while (j < kit - u - 1) {
            c[i][j] = 1;
            ++j;
            gonka();
            Sleep(timer1);
        }
        while (i < kit - u - 1) {
            c[i][j] = 1;
            gonka();
            Sleep(timer1);
            ++i;
        }
        while (j > u + k) {
            c[i][j] = 1;
            gonka();
            --j;
            Sleep(timer1);
        }
        while (i > u + 1 + k) {
            c[i][j] = 1;
            gonka();
            --i;
            Sleep(timer1);
        }
    }
    c[k + 2][l + 2] = 1;
    gonka();
    i = k, j = l;
    for (int u = 0; u < ceil(kit / 2) + 1; u++) {
        while (j < kit - u - 1) {
            c[i][j] = 0;
            ++j;
            gonka();
            Sleep(timer1);
        }
        while (i < kit - u - 1) {
            c[i][j] = 0;
            gonka();
            Sleep(timer1);
            ++i;
        }
        while (j > u + k) {
            c[i][j] = 0;
            gonka();
            --j;
            Sleep(timer1);
        }
        while (i > u + 1 + k) {
            c[i][j] = 0;
            gonka();
            --i;
            Sleep(timer1);
        }
    }
    c[k + 2][l + 2] = 0;
    gonka();
    return 0;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int timer = 0;
    cout << "Задайте задержку для вывода поля в миллисекундах, лучше брать от 200 до 500!" << '\n' << "Задержка таймера:";
    cin >> timer;
    int timer1 = 0;
    cout << "Задайте задержку для вывода змейки в миллисекундах, лучше брать от 200 до 500!" << '\n' << "Задержка таймера:";
    cin >> timer1;
    int k = 0, l = 0;
    bool lk = true;
    int flag = 0;
    while (lk) {
        if (k < 15 and l < 40 and flag == 0) {
            c[k][l] = 1;
            zxc(k, l, timer1);
            c[k][l] = 0;
            k++, l++;
            Sleep(timer);
        }
        if (k == 15 and l < 40) {
            c[k][l] = 1;
            flag = 1;

        }
        if (flag == 1 and k > 0 and l < 40) {
            c[k][l] = 1;
            zxc(k, l, timer1);
            c[k][l] = 0;

            k--, l++;
            Sleep(timer);
        }
        if (flag == 1 and k == 0 and l < 40) {
            c[k][l] = 1;
            flag = 0;
            zxc(k, l, timer1);
            c[k][l] = 0;
        }
        if (l == 40) {
            while (l > 0) {
                if (flag == 1 and k > 0 and l > 0) {
                    c[k][l] = 1;
                    zxc(k, l, timer1);
                    c[k][l] = 0;
                    k--, l--;
                    Sleep(timer);
                }
                if (k == 0 and l > 0) {
                    flag = 0;
                    zxc(k, l, timer1);
                }
                if (k < 15 and l > 0 and flag == 0) {
                    c[k][l] = 1;
                    zxc(k, l, timer1);
                    c[k][l] = 0;
                    Sleep(timer);
                    k++, l--;
                }
                if (k == 15 and l > 0) {
                    flag = 1;
                    zxc(k, l, timer1);
                }
                if (k > 0 and l > 0 and flag == 1) {
                    c[k][l] = 1;
                    zxc(k, l, timer1);
                    c[k][l] = 0;
                    Sleep(timer);
                    k--, l--;
                }
            }
        }
    }
    return 0;
}