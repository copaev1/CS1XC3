/**
 * @file main.c
 * @author Lola Copaev
 * @version 0.1
 * @date 2022-04-12
 *
 * @copyright Copyright (c) 2022
 *
 */


/**
 * @brief Function stores all basic information about the students; full name, grades, and siblings.
 *
 */

 typedef struct _student
{
  char first_name[50];
  char last_name[50];
  char id[11];
  double *grades;
  int num_grades;
} Student;

void add_grade(Student *student, double grade);
double average(Student *student);
void print_student(Student *student);
Student* generate_random_student(int grades);
