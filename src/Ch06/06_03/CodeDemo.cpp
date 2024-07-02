// Learning C++ 
// Challenge 06_03
// Upgrade to work with files, by Eduardo Corpeño 

#include <iostream>
#include <fstream>
#include <vector>
#include "records.h"

void initialize(StudentRecords&);

int main(){
    int id;
    StudentRecords SR;
    
    initialize(SR);

    std::cout << "Enter a student ID: " << std::flush;
    std::cin >> id;

    SR.report_card(id);
    
    std::cout << std::endl << std::endl;
    return (0);
}

void initialize(StudentRecords& srec){
    
    std::ifstream inFile;
    std::string buff;
    //read from students file
    inFile.open("students.txt");
    if(inFile.fail()){std::cerr<<"FAILED TO OPEN FILE"<<std::endl;}
    while(!inFile.eof()){
        std::string name;
        int id;
        getline(inFile, buff);
        id = stoi(buff);
        getline(inFile,buff);
        name = buff;
        srec.add_student(id,name);      
    }
    inFile.close();

    //read from courses file
    inFile.open("courses.txt");
    if(inFile.fail()){std::cerr<<"FAILED TO OPEN FILE"<<std::endl;}

    while(!inFile.eof()){
        int id;
        std::string name;
        unsigned char credits;
        getline(inFile, buff);
        id = stoi(buff);
        getline(inFile,buff);
        name = buff;
        getline(inFile,buff);
        credits = (unsigned char)stoi(buff);
        srec.add_course(id,name,credits);
    }
    
    inFile.close();

    //read from grades file
    inFile.open("grades.txt");
    if(inFile.fail()){std::cerr<<"FAILED TO OPEN FILE"<<std::endl;}

    while(!inFile.eof()){
        int sid;
        int cid;
        char grade;
        getline(inFile,buff);
        sid = stoi(buff);
        getline(inFile,buff);
        cid = stoi(buff);
        getline(inFile,buff);
        grade = buff[0];
        
        srec.add_grade(sid,cid,grade);
    }

    inFile.close();
}
