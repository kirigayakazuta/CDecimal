# CDecimal

В рамках данного проекта была реализована библиотека `decimal.h` на языке программирования `C` с использованием структурного подхода. Эта библиотека добовляет возможность работы с типом «decimal», который отсутствует в стандарте языка. Тем не менее, этот тип критически важен для расчетов, где недопустимы погрешности вычислений, свойственные типам с плавающей точкой. Для простой сборки проекта был создан `Makefile`. Также все функции были покрыты модульными тестами, написанными с использованием `check.h`.

## Содержание

1. [Установка](#установка)
2. [Структура decimal](#структура-decimal)
3. [Арифметические операторы](#арифметические-операторы)
4. [Операторы сравнение](#операторы-сравнение)
5. [Функции преобразования](#функции-преобразования)
6. [Другие функции](#другие-функции)

### Установка
Для установки проекта подребуются следующие утилиты:
- `gcc`
- `make`

Для компиляции библиотеки переходим в `src/` и запускаем сборку командой `make s21_decimal.a`. Чтобы использовать тесты выполняем `make test`. Также с помощью `make gcov_report` иожем получить отчет о покрытии кода тестами.ё

### Структура decimal  

```c
typedef struct {
  unsigned int bits[4];
} decimal;
```

Decimal число реализовано в виде четырехэлементного массива 32-разрядных целых беззнаковых чисел `unsigned bits[4]`.

`bits[0]`, `bits[1]`, и `bits[2]` содержат младшие, средние и старшие 32 бита 96-разрядного целого беззнакового числа соответственно (мантиса).

`bits[3]` содержит знак и коэффициент масштабирования (порядок), который показывает в каком месте должна стоять точка, разделяющая целую и дробную часть числа.

Например, число -123.456 = -1 * 123456 / 10^(28 - 25), где -1 - знак, 123456 - целое беззнаковое число, 25 - коэффициент масштабирования.

### Арифметические операторы

| Название оператора | Оператор  | Функция                                                                            | 
| ------ | ------ |------------------------------------------------------------------------------------|
| Сложение | + | int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result)         |
| Вычитание | - | int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result)         |
| Умножение | * | int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) | 
| Деление | / | int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) |

Функции возвращают код ошибки:  
- 0 - OK  
- 1 - число слишком велико или равно бесконечности
- 2 - число слишком мало или равно отрицательной бесконечности
- 3 - деление на 0

*Если число не вмещается в мантису, используется банковское округление*


### Операторы сравнение

| Название оператора | Оператор  | Функция | 
| ------ | ------ | ------ |
| Меньше  | < | int s21_is_less(s21_decimal, s21_decimal) |
| Меньше или равно | <= | int s21_is_less_or_equal(s21_decimal, s21_decimal) | 
| Больше | \> |  int s21_is_greater(s21_decimal, s21_decimal) |
| Больше или равно | \>= | int s21_is_greater_or_equal(s21_decimal, s21_decimal) | 
| Равно | == |  int s21_is_equal(s21_decimal, s21_decimal) |
| Не равно | != |  int s21_is_not_equal(s21_decimal, s21_decimal) |

Возвращаемое значение:
- 0 - FALSE
- 1 - TRUE

### Функции преобразования

| Преобразователь | Функция | 
| ------ | ------ |
| Из int | int s21_from_int_to_decimal(int src, s21_decimal *dst) |
| Из float  | int s21_from_float_to_decimal(float src, s21_decimal *dst) |
| В int  | int s21_from_decimal_to_int(s21_decimal src, int *dst) |
| В float  | int s21_from_decimal_to_float(s21_decimal src, float *dst) |

Возвращаемое значение - код ошибки:
 - 0 - OK
 - 1 - ошибка конвертации

### Другие функции

| Описание | Функция                                                  | 
| ------ |----------------------------------------------------------|
| Округляет указанное Decimal число до ближайшего целого числа в сторону отрицательной бесконечности. | int s21_floor(s21_decimal value, s21_decimal *result)    |	
| Округляет Decimal до ближайшего целого числа. | int s21_round(s21_decimal value, s21_decimal *result)    |
| Возвращает целые цифры указанного Decimal числа; любые дробные цифры отбрасываются, включая конечные нули. | int s21_truncate(s21_decimal value, s21_decimal *result) |
| Возвращает результат умножения указанного Decimal на -1. | int s21_negate(s21_decimal value, s21_decimal *result)   |

Возвращаемое значение - код ошибки:
 - 0 - OK
 - 1 - ошибка вычисления