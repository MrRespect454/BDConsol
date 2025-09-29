#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_SUBJECT_LENGTH 50
#define STUDENT_FILE "student.txt"
#define RAND_MAX 2147483647

typedef struct
{
    int id;
    char name[MAX_NAME_LENGTH];
    int age;

} Student;

typedef struct
{
    int id;
    char name[MAX_SUBJECT_LENGTH];
    int credits;
    int student_id;
} Subject;

static unsigned long int next = 1;

int rand(void)
{
    next = next * 1103515245 + 12345;
    return (unsigned int)(next / 65536) % (RAND_MAX + 1);
}

void addStudent()
{
    Student student;
    int unique = 0;
    FILE *file;

    file = fopen(STUDENT_FILE, "r");
    if (file)
    {

        while (!unique)
        {
            student.id = rand();
            int existing_id;
            char name[100];
            int age;
            int found = 0;

            rewind(file);
            while (fscanf(file, "%d %99s %d", &existing_id, name, &age) != EOF)
            {
                if (existing_id == student.id)
                {
                    found = 1;
                    break;
                }
            }
            if (!found)
            {
                unique = 1;
            }
        }
        fclose(file);
    }
    else
    {
        while (student.id > 0)
        {
            student.id = rand();
        }
    }

    printf("Введите имя студента: ");
    scanf("%99s", student.name);

    printf("Введите возраст студента: ");
    scanf("%d", &student.age);

    file = fopen(STUDENT_FILE, "a");
    if (!file)
    {
        printf("Ошибка открытия файла для записи!\n");
        return;
    }

    fprintf(file, "%d %s %d\n", student.id, student.name, student.age);
    fclose(file);

    printf("Студент добавлен успешно! Его id: %d, его имя: %s, его возраст: %d\n", student.id, student.name, student.age);
}

void deleteStudent()
{
    printf("Удаление студента...\n");
}

void edit_student_details()
{
    printf("Редактирование данных студента...\n");
}

void allstudents()
{
    Student student;
    FILE *file;

    file = fopen(STUDENT_FILE, "r");
    if (!file)
    {
        printf("Ошибка открытия файла!\n");
        return;
    }

    if (file)
    {

        int existing_id;
        char name[100];
        int age;
        int found = 0;

        rewind(file);
        while (fscanf(file, "%d %99s %d", &existing_id, name, &age) != EOF)
        {
            printf("id Студента: %d, Имя студента: %s, Возраст студента: %d\n", existing_id, name, age);
        }
        fclose(file);
    }
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
