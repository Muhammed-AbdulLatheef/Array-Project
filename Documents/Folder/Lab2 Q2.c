#include <stdio.h>
#include <string.h>

#define numOfSubjects 5
#define numOfStudent 30

// Function prototypes
void enrol();
void AggregateGrade(int studentCount);
void searchUpdate();
void printStudent(int i);
void updateStudent(int i);

typedef struct
{
    char firstName[10];
    char lastName[10];
    int StudentID;
    float subjectMarks[numOfSubjects];
    int aggregateMarks;
    char grade[11];

} Student;

Student students[numOfStudent];

int main(){
    enrol();
    return 0;

    
}
// Function to enter student marks.
void enrol(){
    int i = 0;
    int j = 0;
    for(i = 0; i < numOfStudent; i++){
        printf("Enter details for student %d\n",i );
        printf("Student ID : ");
        scanf("%d", &students[i].StudentID);
        printf("Last Name: ");
        scanf("%d", &students[i].lastName);
        printf("First Name: ");
        scanf("%d", &students[i].firstName);
        printf("Subjects: \n");
        char choice[4];
        for (j = 0; j < numOfSubjects; j++) {
            printf("Do you want to enter student's marks for Subject %d? (\"Yes\" or \"No\"):", j);
            scanf("%s", choice);
            if (strcmp(choice, "Yes") == 0) {
                printf("Enter marks for subject %d: ", j);
                scanf("%f", &students[i].subjectMarks[j]);
            }
            else if (strcmp(choice, "No") == 0) {
                students[i].subjectMarks[j] = -1;
            } else {
                printf("Invalid choice. Please enter \"Yes\" or \"No\".\n");
                j--;
            }
        }
        AggregateGrade(i);
    }
}

// Function to calculate aggregate marks and assign grades
void AggregateGrade(int studentCount) {
        int totalMarks = 0;
        for (int j = 0; j < numOfSubjects; j++) {
            totalMarks += students[studentCount].subjectMarks[j];
        }
        students[studentCount].aggregateMarks = totalMarks;
        if (totalMarks >= 85) {
            strcpy(students[studentCount].grade, "HD");
        } else if (totalMarks >= 75) {
            strcpy(students[studentCount].grade, "D");
        } else if (totalMarks >= 65) {
            strcpy(students[studentCount].grade, "C");
        } else if (totalMarks >= 50) {
            strcpy(students[studentCount].grade, "P");
        } else if (totalMarks < 50 && totalMarks >= 0) {
            strcpy(students[studentCount].grade, "F");
        } else{
            strcpy(students[studentCount].grade, "undefined");
        }
        
}

void searchUpdate(){
    char choice[4];
    printf("Do you want to search for a student by Last name or Student ID? (\"LastName\" or \"ID\"):");
    scanf("%s", choice);
    char LastName[10];
    int StudentID;
    if(strcasecmp(choice, "LastName") == 0){
        printf("Enter Last Name: ");
        scanf("%s", LastName);
    } else if(strcasecmp(choice, "ID") == 0){
        printf("Enter Student ID: ");
        scanf("%d", &StudentID);
    } else {
        printf("Invalid choice.\n");
        return;
    }
    for(int i = 0; i < numOfStudent; i++){
        if(strcasecmp(choice, "LastName") == 0 && strcmp(students[i].lastName, LastName) == 0){
            printf("Student found: %s %s\n", students[i].firstName, students[i].lastName);
            printStudent(i);
            printf("Do you want to update the student record? (\"Yes\" or \"No\"):");
        } else if(strcasecmp(choice, "ID") == 0 && students[i].StudentID == StudentID){
            printf("Student found: %s %s\n", students[i].firstName, students[i].lastName);
            printStudent(i);
            printf("Do you want to update the student record? (\"Yes\" or \"No\"):");
        }
    }
}

void printStudent(int i){
    printf("Student Details:\n");
    printf("-----------------\n");
    printf("Student ID: %d\n", students[i].StudentID);
    printf("Name: %s %s\n", students[i].firstName, students[i].lastName);
    printf("Aggregate Marks: %d\n", students[i].aggregateMarks);
    printf("Grade: %s\n", students[i].grade); 
    printf("Subject Marks:\n");
    for(int j = 0; j < numOfSubjects; j++){
        printf("Subject %d: %.2f\n", j + 1, students[i].subjectMarks[j]);
    }
    printf("-----------------\n");
}

void updateStudent(int i){
    printf("Updating details for student %s %s\n", students[i].firstName, students[i].lastName);
    printf("Enter the attribute you want to update (\"FirstName\", \"LastName\", \"StudentID\", \"SubjectMarks\"):");
    char attribute[15];
    scanf("%s", attribute);
    if(strcasecmp(attribute, "FirstName") == 0){
        printf("Enter new First Name: ");
        scanf("%s", students[i].firstName);
    } else if(strcasecmp(attribute, "LastName") == 0){
        printf("Enter new Last Name: ");
        scanf("%s", students[i].lastName);
    } else if(strcasecmp(attribute, "StudentID") == 0){
        printf("Enter new Student ID: ");
        scanf("%d", &students[i].StudentID);
    } else if(strcasecmp(attribute, "SubjectMarks") == 0){
        for(int j = 0; j < numOfSubjects; j++){
            printf("Enter new marks for subject %d: ", j);
            scanf("%f", &students[i].subjectMarks[j]);
        }
        AggregateGrade(i);
    }
    printf("Student record updated successfully.\n");
    printStudent(i);
}



