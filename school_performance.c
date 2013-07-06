#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 5

int main(int argc, char *argv[]) {

  int ammount_test, ammount_works, ammount_other, i, total_value, total_note = 0;
  int quantity_test, quantity_works, quantity_other_work;
  int *value_test, *value_works, *value_other;
  float *test_note, *works_note, *other_note;
  float average, *performance_test, *performance_work, *performance_other, total_performance_note;
  char choice_test[SIZE], choice_works[SIZE], other_work[SIZE];

  printf("Tests were done ? (answer yes or no) \n");
  scanf("%4s", choice_test);
  quantity_test = (unsigned)strlen(choice_test);

  if (strncmp (choice_test, "yes", quantity_test) == 0) {

    printf("How many tests were made? \n");
    scanf("%d", &ammount_test);
    test_note = malloc(ammount_test * sizeof(float));
    value_test = malloc(ammount_test * sizeof(int));
    performance_test = malloc(ammount_test * sizeof(float));

    for(i = 0; i < ammount_test; i++) {

      printf("\n\nValue of the %d° test : \n", i+1);
      scanf("%d", &value_test[i]);
      printf("Note %d° test : \n", i+1);
      scanf("%f", &test_note[i]);

    }

  }
  
  printf("\n\nWorks were made ? (answer yes or no) \n");
  scanf("%4s", choice_works);
  quantity_works = (unsigned)strlen(choice_works);

  if (strncmp (choice_works, "yes", quantity_works) == 0) {
    printf("How many works were made? \n");
    scanf("%d", &ammount_works);
    works_note = malloc(ammount_works * sizeof(float));
    value_works = malloc(ammount_works * sizeof(int));
    performance_work = malloc(ammount_works * sizeof(float));

    for(i = 0; i < ammount_works; i++) {
      
      printf("\n\nValue of the %d° work : \n", i+1);
      scanf("%d", &value_works[i]);
      printf("Note %d° work : \n", i+1);
      scanf("%f", &works_note[i]);

    }
    
  }
  
  printf("\n\nSome work was done more ? (answer yes or no) \n");
  scanf("%4s", other_work);
  quantity_other_work = (unsigned)strlen(other_work);

  if (strncmp (other_work, "yes", quantity_other_work) == 0) {
    
    printf("How many other works were made ? \n");
    scanf("%d", &ammount_other);
    other_note = malloc(ammount_other * sizeof(float));
    value_other = malloc(ammount_other * sizeof(int));
    performance_other = malloc(ammount_other * sizeof(float));

    for(i = 0; i < ammount_other; i++) {
    
      printf("\n\nValue of the %d° work : \n", i+1);
      scanf("%d", &value_other[i]);
      printf("Note %d° work : \n", i+1);
      scanf("%f", &other_note[i]);

    }

  }

  printf("\n\nTotal value of notes and works : \n");
  scanf("%d", &total_value);

  if (strncmp (choice_test, "yes", quantity_test) == 0) {
    for(i = 0; i < ammount_test; i++) {
      total_note += value_test[i];
      total_performance_note += test_note[i];
    }
  }

  if (strncmp (choice_works, "yes", quantity_works) == 0) {
    for(i = 0; i < ammount_works; i++) {
      total_note += value_works[i];
      total_performance_note += works_note[i];
    }
  }

  if (strncmp (other_work, "yes", quantity_other_work) == 0) {
    for(i = 0; i < ammount_other; i++) {
      total_note += value_other[i];
      total_performance_note += other_note[i];
    }
  }

  while (total_value < total_note) {
    printf("Invalid value! (total value less than the values reported notes!)\n\n");
    printf("Enter another value : \n");
    scanf("%d", &total_value);
  }

  printf("Minimum target to be achieved : \n");
  scanf("%f", &average);

  while (average > total_value) {
    printf("Invalid value! (the minimum value to be achieved can not be greater than the total!) \n");
    printf("Enter another value : \n");
    scanf("%f", &average);
  }

  if (strncmp (choice_test, "yes", quantity_test) == 0) {

    printf("\n\nTests performance : \n");

    for(i = 0; i < ammount_test; i++) {
      performance_test[i] = (test_note[i] * 100) / value_test[i] ;
      printf("%d° test : %0.2f / %d | Percentage : %0.1f\n", i+1, test_note[i], value_test[i], performance_test[i]);
    }

  }

  if (strncmp (choice_works, "yes", quantity_works) == 0) {

    printf("\nWorks performance : \n");

    for(i = 0; i < ammount_works; i++) {
      performance_work[i] = (works_note[i] * 100) / value_works[i] ;
      printf("%d° work : %0.2f / %d | Percentage : %0.1f\n", i+1, works_note[i], value_works[i], performance_work[i]);
    }

  } 

  if (strncmp (other_work, "yes", quantity_other_work) == 0) {

    printf("\nOther works performance : \n");

    for(i = 0; i < ammount_other; i++) {
      performance_other[i] = (other_note[i] * 100) / value_other[i] ;
      printf("%d° work : %0.2f / %d | Percentage : %0.1f\n", i+1, other_note[i], value_other[i],  performance_other[i]);
    }

  }

  printf("\nOverall performance : %0.2f / %d \n\n", total_performance_note, total_note);

  if (total_performance_note >= average) {
    printf("Final performance : OK!\n\n\n");
  }else{
    printf("Final performance : Disapproved!\n\n\n");
  }

  free(value_test);
  free(value_works);
  free(value_other);
  free(test_note);
  free(works_note);
  free(other_note);
  free(performance_test);
  free(performance_work);
  free(performance_other);

  return 0;

}
