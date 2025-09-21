#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_SUBJECT_LENGTH 50
#define STUDENT_FILE "student.txt"

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

void addStudent()
{

    FILE *file = fopen(STUDENT_FILE, "a");

    fclose(file);
    FILE *file = fopen(STUDENT_FILE, "a");
    if (!file)
    {
        printf("Ошибка открытия файла!\n");
        return;
    }
    Student student;
    // student.id = max_id + 1;
    printf("Введите имя студента: ");
    scanf("%99s", student.name);
    printf("Введите возраст студента: ");
    scanf("%d", &student.age);
    fprintf(file, "%d %s %d\n", student.id, student.name, student.age);
    fclose(file);
    printf("Студент добавлен успешно! Его id: %d, его имя: %s, его возраст: %d\n",
           student.id, student.name, student.age);
}

void deleteStudent()
{
    printf("Удаление студента...\n");
}

void edit_student_details()
{
    printf("Редактирование данных студента...\n");
}

void view_all_students()
{
    printf("Просмотр всех студентов...\n");
}

void view_all_student_details()
{
    printf("Просмотр всех данных о студенте...\n");
}

void add_subject()
{
    printf("Добавление предмета...\n");
}

void delete_subject()
{
    printf("Удаление предмета...\n");
}

void edit_subject_details()
{
    printf("Редактирование данных предмета...\n");
}
