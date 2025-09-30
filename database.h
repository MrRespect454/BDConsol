#ifndef DATABASE_H
#define DATABASE_H

#define MAX_NAME_LENGTH 100
#define MAX_SUBJECT_LENGTH 50
#define STUDENT_FILE "student.txt"
#define SUBJECT_FILE "subject.txt"
#define TEMP_FILE "temporary.txt"
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

// Объявления функций
void addStudent();
void deleteStudent();
void edit_student_details();
void allstudents();
void add_subject();
void delete_subject();
void allsubject();

#endif
