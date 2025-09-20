#ifndef DATABASE_H
#define DATABASE_H

struct Employee
{
    int id;
    char first_name[50];
    char last_name[50];
    double salary;
};

typedef struct Employee Employee;

void db_init(Employee **db, int *capacity, int *size);
int db_add(Employee *db, int *size, int capacity, Employee new_employee);
int db_delete(Employee *db, int *size, int id);
void db_print(const Employee *db, int size);
Employee *db_find_by_id(const Employee *db, int size, int id);
Employee *db_find_by_name(const Employee *db, int size, const char *last_name);

int db_save_to_file(const Employee *db, int size, const char *filename);
int db_load_from_file(Employee **db, int *size, int *capacity, const char *filename);

#endif
