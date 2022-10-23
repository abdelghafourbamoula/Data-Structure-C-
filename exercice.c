#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
	char *lastname;
	char *firstname;
} Student_t;

typedef struct link{
      Student_t  student;
      struct link * next;
} Link_t;

void read_file_content(Student_t * array, FILE * file) {
    int i=0;
    while(fscanf(file, "%s %s",  array[i].lastname, array[i].firstname) != EOF){    
        ++i;
  } 
}

Link_t * new_link(Student_t a_student) {
    Link_t* link = malloc(sizeof(Link_t));
    link->student = a_student;
    link->next = NULL;
    return link;
}

Link_t * chain(Link_t * beginning, Link_t * new_link){
    new_link->next = beginning;
    return new_link;
}

void display_linked_list(Link_t * beginning){
    while (beginning->next != NULL)
    {
        printf("%s %s\n", beginning->student.firstname, beginning->student.lastname);
        beginning = beginning->next;
    }
    
}

Link_t * search (Link_t * beginning, char * name_to_search) {
    while (beginning != NULL)
    {
        if ( strcmp(beginning->student.firstname, name_to_search) || strcmp(beginning->student.lastname, name_to_search))
        {
            return beginning;
        }
        beginning = beginning->next;        
    }
    return NULL;
}

int main(int argc, char const *argv[])
{
    Student_t students_array [60];
    FILE *file;
    file = fopen("students.txt", "r");

    read_file_content(students_array, file);

   Link_t* students_list = new_link(students_array[0]);

   for (int i = 0; i < 60; i++)
   {
    Link_t* student = new_link(students_array[i]);
    students_list = chain(students_list, student);
   }

   Link_t* s = search(students_list, "Ahmad");
   printf(" search Ahmad: %s %s\n", s->student.firstname, s->student.lastname);

   s = search(students_list, "jerry");
   printf(" search jerry: %s %s\n", s->student.firstname, s->student.lastname);

   printf("\n");
   display_linked_list(students_list);

    return 0;
}
