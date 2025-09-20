#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_SUBJECT_LENGTH 50
#define DATABASE_FILE "database.txt"

typedef struct
{
    int id;
    char name[MAX_NAME_LENGTH];
    int age;

} Student;

#define MAX_SUBJECT_LENGTH 50

typedef struct
{
    int id;
    char name[MAX_SUBJECT_LENGTH];
    int credits;
    int student_id;
} Subject;

void addStudent();
void deleteStudent();
void edit_student_details();
void view_all_students();
void view_all_student_details();

void add_subject();
void delete_subject();
void edit_subject_details();

int main()
{
    int expression, flag = 0;
    while (flag != 1)
    {
        printf("Выберите действие для работы с базой данных\n");
        printf("1. Добавить студента\n");
        printf("2. Удалить студента\n");
        printf("3. Изменить данные студента\n");
        printf("4. Просмотреть всех студентов\n");
        printf("5. Добавить предмет\n");
        printf("6. Удалить предмет\n");
        printf("7. Изменить данные предмета\n");
        printf("8. Просмотреть все предметы\n");
        printf("9. Выход из программы\n");
        scanf("%d", &expression);
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
            view_all_students();
            break;
        case 5:
            add_subject();
            break;
        case 6:
            delete_subject();
            break;
        case 7:
            edit_subject_details();
            break;
        case 8:
            view_all_student_details();
            break;
        case 9:
            flag = 1;
            break;
        default:
            printf("программа сработала не корректно\nВведите число из списка\n");
            // flag = 1;
            break;
        }
    }
    return 0;
}
