/**
 * @file main.c
 * @author Lola Copaev
 * @brief Main objective is to create a type Course, add students, and print information about that course. Using all the libraries
 * @version 0.1
 * @date 2022-04-12
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "time.h"
#include "course.h"

/**
 * @brief The main function created a class called MATH101. And manipulates accordingly to the data.
 * @brief prints the course contents.
 * @brief It also prints the top student, the number of passing students, and it lists all of the passing students.
 * 
 */
int main()
{
  srand((unsigned) time(NULL));

  Course *MATH101 = calloc(1, sizeof(Course));
  strcpy(MATH101->name, "Basics of Mathematics");
  strcpy(MATH101->code, "MATH 101");

  for (int i = 0; i < 20; i++)
    enroll_student(MATH101, generate_random_student(8));

  print_course(MATH101);

  Student *student;
  student = top_student(MATH101);
  printf("\n\nTop student: \n\n");
  print_student(student);

  int total_passing;
  Student *passing_students = passing(MATH101, &total_passing);
  printf("\nTotal passing: %d\n", total_passing);
  printf("\nPassing students:\n\n");
  for (int i = 0; i < total_passing; i++) print_student(&passing_students[i]);

  return 0;
}
