/**
 * @file course.c
 * @author Lola Copaev
 * @date 04/12/2022
 * @brief commenting on C program that's using libraries to futher create courses for students
 *
 */


#include "course.h"
#include <stdlib.h>
#include <stdio.h>


/**
 * @brief Adds a new student to a specific course by appending them to the end of a list.
 *
 * @param course of type Course
 * @param student of type Student
 */
void enroll_student(Course *course, Student *student)
{
  course->total_students++;
  if (course->total_students == 1)
  {
    course->students = calloc(1, sizeof(Student));
  }
  else
  {
    course->students =
      realloc(course->students, course->total_students * sizeof(Student));
  }
  course->students[course->total_students - 1] = *student;
}

/**
 * @brief Prints information regarding a course: name, course code, total number of students enrolled in a course, and number of students enrolled in that specific course.
 *
 * @param course of type Course
 */
void print_course(Course* course)
{
  printf("Name: %s\n", course->name);
  printf("Code: %s\n", course->code);
  printf("Total students: %d\n\n", course->total_students);
  printf("****************************************\n\n");
  for (int i = 0; i < course->total_students; i++)
    print_student(&course->students[i]);
}
/**
 * @brief Looks for the student who achives the highest grade in the course, retutrns it, unless no one is registered in that course.
 *
 * @param course of type Course
 * @return Student* of type Student
 */
Student* top_student(Course* course)
{
  if (course->total_students == 0) return NULL;

  double student_average = 0;
  double max_average = average(&course->students[0]);
  Student *student = &course->students[0];

  for (int i = 1; i < course->total_students; i++)
  {
    student_average = average(&course->students[i]);
    if (student_average > max_average)
    {
      max_average = student_average;
      student = &course->students[i];
    }
  }

  return student;
}

/**
 * @brief Returns a students who are passing the course, and counts that amount.
 *
 * @param course
 * @param total_passing
 * @return passing
 */
Student *passing(Course* course, int *total_passing)
{
  int count = 0;
  Student *passing = NULL;

  for (int i = 0; i < course->total_students; i++)
    if (average(&course->students[i]) >= 50) count++;

  passing = calloc(count, sizeof(Student));

  int j = 0;
  for (int i = 0; i < course->total_students; i++)
  {
    if (average(&course->students[i]) >= 50)
    {
      passing[j] = course->students[i];
      j++;
    }
  }

  *total_passing = count;

  return passing;
}
