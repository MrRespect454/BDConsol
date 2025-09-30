#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "database.h"

int main()
{
    int expression, flag = 0;
    while (flag != 1)
    {
        printf("\n=== Система управления студентами и предметами ===\n");
        printf("1. Добавить студента\n");
        printf("2. Удалить студента\n");
        printf("3. Изменить данные студента\n");
        printf("4. Просмотреть всех студентов\n");
        printf("5. Добавить предмет\n");
        printf("6. Удалить предмет\n");
        printf("7. Просмотреть все предметы\n");
        printf("8. Выход из программы\n");
        printf("Выберите действие: ");

        if (scanf("%d", &expression) != 1)
        {
            printf("Ошибка ввода! Введите число.\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        switch (expression)
        {
        case 1:
            addStudent();
            break;
        case 2:
            deleteStudent();
            break;
        case 3:
            edit_student_details();
            break;
        case 4:
            allstudents();
            break;
        case 5:
            add_subject();
            break;
        case 6:
            delete_subject();
            break;
        case 7:
            allsubject();
            break;
        case 8:
            flag = 1;
            printf("Выход из программы...\n");
            break;
        default:
            printf("Неверный выбор! Введите число от 1 до 8.\n");
            break;
        }
    }
    return 0;
}
