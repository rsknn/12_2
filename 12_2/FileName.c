#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <time.h>
#include <locale.h>

int main() {
    setlocale(LC_CTYPE, "RUS");
    struct tm* mytime;
    time_t t;
    char str[100];
    int days_in_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    t = time(NULL);
    mytime = localtime(&t);
    printf("Московское время %02d:%02d:%02d \n", mytime->tm_hour, mytime->tm_min, mytime->tm_sec);
    int m = 11 - mytime->tm_mon;
    int k = days_in_month[mytime->tm_mon] - mytime->tm_mday;
    sprintf(str, "до Нового года осталось %d месяцев и %d дней", m, k);
    printf("%s\n", str);
    return 0;
}