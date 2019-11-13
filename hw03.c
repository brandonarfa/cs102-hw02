#include <stdio.h>
#include <stdlib.h>

typedef enum {
  NAME_ONLY = 0,
  MAJOR_AND_NAME = 1, 
  YEAR_AND_NAME = 2
} Mode;

typedef struct {
  char *first_name;
  char *last_name;
  char *major;
  int year;
  // TODO: add fields here for major and year
} Student;

void print_student(Mode m, Student s) {
  switch (m) {
    case NAME_ONLY:
      printf("%s %s\n", s.first_name, s.last_name);
        break;
    case MAJOR_AND_NAME:
      printf("%s %s %s\n", s.major, s.first_name, s.last_name);
        break;
    case YEAR_AND_NAME:
      printf("%d %s %s\n", s.year, s.first_name, s.last_name);
        break;
      
  // TODO: handle other cases
  }
}

/*
argv[1] will be the Mode integer.
argv[2]-argv[5] will be student info in the form [first_name, last_name, major, year].
argv[6]-argv[9], if present will be student info for a second student in the same form, and so on.
You will need to check argc to determine the number of students passed at runtime.
The fields are all strings (char[]), except year is a number (int)
*/
int main(int argc, char **argv) {
  
  Mode mode = (int)(atof(argv[1]));
  
  int student_amount = (argc-2)/4;
    
  Student students[student_amount];
  
  int i = 2;
  int student_count = -1;
  for(i;i<argc;i++){
    
    int v = (i-2)%4;
    
    if(v == 0){
      student_count++;
      students[student_count].first_name = argv[i];
    }
    else if(v == 1){
      students[student_count].last_name = argv[i];
    }
    else if(v == 2){
      students[student_count].major = argv[i];
    }
    else if(v == 3){
      students[student_count].year = (int)(atof(argv[i]));
    }
  }
  
  int j = 0;
  for(j;j<student_amount;j++){
    print_student(mode,students[j]);
  }

  return 0;
}
                  
