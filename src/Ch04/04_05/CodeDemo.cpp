// Learning C++ 
// Challenge 04_05
// Calculate a GPA, by Eduardo Corpeño 

#include <iostream>
#include <vector>
#include "records.h"

// #define DEBUGGING

int main(){
    float GPA = 0.0f;
    int id;
    
    std::vector<Student> students = {Student(1, "George P. Burdell"),
                                    Student(2, "Nancy Rhodes")};

    std::vector<Course> courses = {Course(1, "Algebra", 5),
                                Course(2, "Physics", 4),
                                Course(3, "English", 3),
                                Course(4, "Economics", 4)};

    std::vector<Grade> grades = {Grade(1, 1, 'B'), Grade(1, 2, 'A'), Grade(1, 3, 'C'),
                                Grade(2, 1, 'A'), Grade(2, 2, 'A'), Grade(2, 4, 'B')};

    std::cout << "Enter a student ID: " << std::flush;
    std::cin >> id;

    // Calculate the GPA for the selected student.
    // Write your code here
    float credits = 0.0f;
    for(int i = 0; i < grades.size(); i++){
        if(grades[i].get_student_id() == id){
            #ifdef DEBUGGING
            std::cout << "ID: " << grades[i].get_student_id() << std::endl;
            #endif
            switch(grades[i].get_grade()){
                case 'A':
                    GPA += 4.0*courses[grades[i].get_course_id()-1].get_credits(); break;
                case 'B':
                    GPA += 3.0*courses[grades[i].get_course_id()-1].get_credits(); break;
                case 'C':
                    GPA += 2.0*courses[grades[i].get_course_id()-1].get_credits(); break;
                case 'D':
                    GPA += 1.0*courses[grades[i].get_course_id()-1].get_credits(); break;
                case 'F':
                    GPA += 0.0; break;
                default:
                    GPA += 0.0; break;
            }
            credits += (float)courses[grades[i].get_course_id()-1].get_credits();
        }
    }
    #ifdef DEBUGGING
    std::cout <<"Total earned credits: " << GPA << std::endl;
    std::cout << "Total number of credits: " << credits << std::endl;
    #endif

    GPA /= credits;

    std::string student_str;
    student_str = students[id-1].get_name(); // Change this to the selected student's name

    std::cout << "The GPA for " << student_str << " is " << GPA << std::endl;
    
    std::cout << std::endl << std::endl;
    return (0);
}
