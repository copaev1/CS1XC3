/**
 * @file course.h
 * @author Lola Copaev
 * @brief This file consists of course struct and function declerations.
 */

#include "student.h"
#include <stdbool.h>

/**
 * @brief Course type stores array of characters, name, code, students, and total students (int).
 */
typedef struct _course
{
  char name[100];
  char code[10];
  Student *students;
  int total_students;
} Course;

void enroll_student(Course *course, Student *student);
void print_course(Course *course);
Student *top_student(Course* course);
Student *passing(Course* course, int *total_passing);
