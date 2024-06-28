#include "records.h"

//Student
Student::Student(int the_id, std::string the_name){
    id = the_id;
    name = the_name;
}

int Student::get_id() const{
    return this->id;
}

std::string Student::get_name() const{
    return this->name;
}

//Course
Course::Course(int the_id, std::string the_name, unsigned char the_credits){
    id = the_id;
    name = the_name;
    credits = the_credits;
}

int Course::get_id() const{
    return this->id;
}

std::string Course::get_name() const{
    return this->name;
}

int Course::get_credits() const{
    return this->credits;
}

//Grade
Grade::Grade(int sid, int cid, char grd){
    student_id = sid;
    course_id = cid;
    grade = grd;
}

int Grade::get_student_id() const{
    return this->student_id;
}

int Grade::get_course_id() const{
    return this->course_id;
}

char Grade::get_grade() const{
    return this->grade;
}
