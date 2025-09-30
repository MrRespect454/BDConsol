#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "database.h"

static unsigned long int next = 1;

int custom_rand(void)
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
            student.id = custom_rand();
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
        student.id = custom_rand();
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

    printf("Студент добавлен успешно! Его id: %d, его имя: %s, его возраст: %d\n",
           student.id, student.name, student.age);
}

void deleteStudent()
{
    int delete_id;
    printf("Введите ID студента для удаления: ");
    scanf("%d", &delete_id);

    FILE *sfile = fopen(STUDENT_FILE, "r");
    if (!sfile)
    {
        printf("Ошибка открытия файла!\n");
        return;
    }

    FILE *tfile = fopen(TEMP_FILE, "w");
    if (!tfile)
    {
        printf("Ошибка создания временного файла!\n");
        fclose(sfile);
        return;
    }

    int existing_id;
    char name[100];
    int age;
    int found = 0;
    int records_kept = 0;

    while (fscanf(sfile, "%d %99s %d", &existing_id, name, &age) != EOF)
    {
        if (existing_id == delete_id)
        {
            printf("Удален студент: %s (ID: %d)\n", name, delete_id);
            found = 1;
        }
        else
        {
            fprintf(tfile, "%d %s %d\n", existing_id, name, age);
            records_kept++;
        }
    }

    fclose(sfile);
    fclose(tfile);

    if (found)
    {
        remove(STUDENT_FILE);
        rename(TEMP_FILE, STUDENT_FILE);
        printf("Удаление завершено. Осталось записей: %d\n", records_kept);
    }
    else
    {
        printf("Студент с ID %d не найден.\n", delete_id);
        remove(TEMP_FILE);
    }
}

void edit_student_details()
{
    int edit_id;
    printf("Введите ID студента для редактирования: ");
    scanf("%d", &edit_id);

    FILE *sfile = fopen(STUDENT_FILE, "r");
    if (!sfile)
    {
        printf("Ошибка открытия файла!\n");
        return;
    }

    FILE *tfile = fopen(TEMP_FILE, "w");
    if (!tfile)
    {
        printf("Ошибка создания временного файла!\n");
        fclose(sfile);
        return;
    }

    int existing_id;
    char name[100];
    int age;
    int found = 0;

    while (fscanf(sfile, "%d %99s %d", &existing_id, name, &age) != EOF)
    {
        if (existing_id == edit_id)
        {
            printf("Найден студент: %s (ID: %d, Возраст: %d)\n", name, existing_id, age);
            printf("Введите новое имя: ");
            char new_name[100];
            scanf("%99s", new_name);
            printf("Введите новый возраст: ");
            int new_age;
            scanf("%d", &new_age);
            fprintf(tfile, "%d %s %d\n", existing_id, new_name, new_age);
            printf("Данные студента обновлены!\n");
            found = 1;
        }
        else
        {
            fprintf(tfile, "%d %s %d\n", existing_id, name, age);
        }
    }

    fclose(sfile);
    fclose(tfile);

    if (found)
    {
        remove(STUDENT_FILE);
        rename(TEMP_FILE, STUDENT_FILE);
    }
    else
    {
        printf("Студент с ID %d не найден.\n", edit_id);
        remove(TEMP_FILE);
    }
}

void allstudents()
{
    FILE *file = fopen(STUDENT_FILE, "r");
    if (!file)
    {
        printf("Ошибка открытия файла или файл не существует!\n");
        return;
    }

    int existing_id;
    char name[100];
    int age;
    int count = 0;

    printf("\n=== Список всех студентов ===\n");
    while (fscanf(file, "%d %99s %d", &existing_id, name, &age) != EOF)
    {
        printf("ID: %d, Имя: %s, Возраст: %d\n", existing_id, name, age);
        count++;
    }

    if (count == 0)
    {
        printf("Студенты не найдены.\n");
    }
    else
    {
        printf("Всего студентов: %d\n", count);
    }

    fclose(file);
}

void add_subject()
{
    Subject subject;
    int unique = 0;
    FILE *file;

    file = fopen(SUBJECT_FILE, "r");
    if (file)
    {
        while (!unique)
        {
            subject.id = custom_rand();
            int existing_id;
            char name[100];
            int credits, student_id;
            int found = 0;

            rewind(file);
            while (fscanf(file, "%d %99s %d %d", &existing_id, name, &credits, &student_id) != EOF)
            {
                if (existing_id == subject.id)
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
        subject.id = custom_rand();
    }

    printf("Введите название предмета: ");
    scanf("%99s", subject.name);
    printf("Введите количество кредитов: ");
    scanf("%d", &subject.credits);
    printf("Введите ID студента: ");
    scanf("%d", &subject.student_id);

    file = fopen(SUBJECT_FILE, "a");
    if (!file)
    {
        printf("Ошибка открытия файла для записи!\n");
        return;
    }

    fprintf(file, "%d %s %d %d\n", subject.id, subject.name, subject.credits, subject.student_id);
    fclose(file);

    printf("Предмет добавлен. ID: %d, Название: %s, Кредиты: %d, ID студента: %d\n",
           subject.id, subject.name, subject.credits, subject.student_id);
}

void delete_subject()
{
    int delete_id;
    printf("Введите ID предмета для удаления: ");
    scanf("%d", &delete_id);

    FILE *sfile = fopen(SUBJECT_FILE, "r");
    if (!sfile)
    {
        printf("Ошибка открытия файла!\n");
        return;
    }

    FILE *tfile = fopen(TEMP_FILE, "w");
    if (!tfile)
    {
        printf("Ошибка создания временного файла!\n");
        fclose(sfile);
        return;
    }

    int existing_id, credits, student_id;
    char name[100];
    int found = 0;
    int records_kept = 0;

    while (fscanf(sfile, "%d %99s %d %d", &existing_id, name, &credits, &student_id) != EOF)
    {
        if (existing_id == delete_id)
        {
            printf("Удален предмет: %s (ID: %d)\n", name, delete_id);
            found = 1;
        }
        else
        {
            fprintf(tfile, "%d %s %d %d\n", existing_id, name, credits, student_id);
            records_kept++;
        }
    }

    fclose(sfile);
    fclose(tfile);

    if (found)
    {
        remove(SUBJECT_FILE);
        rename(TEMP_FILE, SUBJECT_FILE);
        printf("Удаление завершено. Осталось записей: %d\n", records_kept);
    }
    else
    {
        printf("Предмет с ID %d не найден.\n", delete_id);
        remove(TEMP_FILE);
    }
}

void allsubject()
{
    FILE *file = fopen(SUBJECT_FILE, "r");
    if (!file)
    {
        printf("Ошибка открытия файла или файл не существует!\n");
        return;
    }

    int existing_id, credits, student_id;
    char name[100];
    int count = 0;

    printf("\n=== Список всех предметов ===\n");
    while (fscanf(file, "%d %99s %d %d", &existing_id, name, &credits, &student_id) != EOF)
    {
        printf("ID: %d, Название: %s, Кредиты: %d, ID студента: %d\n",
               existing_id, name, credits, student_id);
        count++;
    }

    if (count == 0)
    {
        printf("Предметы не найдены.\n");
    }
    else
    {
        printf("Всего предметов: %d\n", count);
    }

    fclose(file);
}
