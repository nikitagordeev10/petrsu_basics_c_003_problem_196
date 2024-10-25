#include <stdio.h>
#include <limits.h>

/* Выводит все кандидаты в числа Лишрел из отрезка 1, 2, ..., N */
void show_lychrel_candidates(long last_number);

/* Проверяет, является ли заданное число кандидатом в числа Лишрел */
int is_lychrel_candidate(long number);

/* Вычисляет обращение числа */
long reverse(long n);


/* Основная функция */
int main()
{
    /* Получаем значение верхней границы последовательности N */
    long last_number;
    printf("Введите верхнюю границу отрезка поиска чисел Лишрел: ");
    scanf("%ld", &last_number);

    /* Выводим все кандидаты в числа Лишрел из отрезка 1, 2, ..., N */
    show_lychrel_candidates(last_number);

    return 0;
}


/* Выводит все кандидаты в числа Лишрел из отрезка 1, 2, ..., N */
void show_lychrel_candidates(long last_number)
{
    long number;

    /* Проверим каждое число в заданном отрезке: */
    for (number = 1; number <= last_number; number++) {
        /* Если оно является кандидатом в числа Лишрел, напечатаем его */
        if (is_lychrel_candidate(number)) {
            printf("%ld\n", number);
        }
    }
}


/* Проверяет, является ли число кандидатом в числа Лишрел */
int is_lychrel_candidate(long number)
{
    long n = number;
    long r = reverse(n);

    /* Повторяем ... */
    do {
        /* Если сумма числа и его обращения переполняет разрядную сетку, */
        if (n >= LONG_MAX - r) {
            /* то считаем число искомым кандидатом и завершаем проверку */
            return 1;
        }
        /* иначе вычисляем новое значение, складывая число с обращением */
        n = n + r;

        /* Вычисляем обращение суммы */
        r = reverse(n);

    /* ... пока число не совпадает с обращением */
    } while (n != r);

    /* Считаем, что проверяемое число - не число Лишрел и завершаем проверку */
    return 0;
}


/* Вычисляет обращение числа */
long reverse(long n)
{
    long r = 0;

    do {
        r = r * 10 + n % 10;
        n /= 10;
    } while (n > 0);

    return r;
}
