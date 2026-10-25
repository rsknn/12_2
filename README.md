# Условие задачи

1. Написать программу, которая выводит на экран текущее время.
2. Добавить вывод дополнительной информации: **«до Нового года осталось m месяцев и k дней»**

# 1. Алгоритм и блок-схема

### Алгоритм

1. **Начало**.
2. **Объявление переменных:** указатель на структуру времени `struct tm *mytime`, переменная системного времени `time_t t`, буфер строки `char str[100]` и массив количества дней в месяцах `days_in_month`.
3. **Получение системного времени:** вызов `t = time(NULL)`.
4. **Преобразование в локальное время:** вызов `mytime = localtime(&t)`.
5. **Вывод текущего времени:** печать полей `mytime->tm_hour`, `mytime->tm_min`, `mytime->tm_sec` в формате `ЧЧ:ММ:СС`.
6. **Расчёт времени до Нового года:**
   * Оставшиеся месяцы: `m = 11 - mytime->tm_mon`.
   * Оставшиеся дни: `k = days_in_month[mytime->tm_mon] - mytime->tm_mday`.
7. **Формирование и вывод строки:** запись текста в массив `str` с помощью `sprintf()` и вывод строки на экран.
8. **Конец**.

### Блок-схема

<img width="392" height="757" alt="image" src="https://github.com/user-attachments/assets/912fa2f4-9828-4a3b-9f9c-92e994a2dde6" />

[Ссылка на изображение блок-схемы](https://clck.ru/3Wge4u)

# 2. Реализация программы

```c
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
```

# 3. Результат работы программы

```text
Московское время 00:37:22
до Нового года осталось 2 месяцев и 5 дней
```
# 4. Информация

Енгалычев Руслан бОТИ-261
