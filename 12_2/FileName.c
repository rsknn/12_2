#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#define WIDTH 80
#define HEIGHT 10

int main() {
    setlocale(LC_CTYPE, "RUS");
    struct tm* mytime;
    time_t t;
    char str1[100];
    char str2[100];
    int days_in_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    t = time(NULL);
    mytime = localtime(&t);
    int m = 11 - mytime->tm_mon;
    int k = days_in_month[mytime->tm_mon] - mytime->tm_mday;
    sprintf(str1, " Московское время %02d:%02d:%02d ", mytime->tm_hour, mytime->tm_min, mytime->tm_sec);
    sprintf(str2, " до Нового года осталось %d месяцев и %d дней ", m, k);
    int len1 = (int)strlen(str1);
    int len2 = (int)strlen(str2);
    for (int row = 0; row < HEIGHT; row++) {
        if (row == 4) {
            int left = (WIDTH - len1) / 2;
            int right = WIDTH - len1 - left;
            for (int i = 0; i < left; i++) putchar('*');
            printf("%s", str1);
            for (int i = 0; i < right; i++) putchar('*');
            putchar('\n');
        }
        else if (row == 5) {
            int left = (WIDTH - len2) / 2;
            int right = WIDTH - len2 - left;
            for (int i = 0; i < left; i++) putchar('*');
            printf("%s", str2);
            for (int i = 0; i < right; i++) putchar('*');
            putchar('\n');
        }
        else {
            for (int i = 0; i < WIDTH; i++) putchar('*');
            putchar('\n');
        }
    }
    return 0;
}