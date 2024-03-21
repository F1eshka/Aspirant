#pragma once
#include "Student.h"
#include <set>


class Group {
    
private:
    unsigned short countstudents = 0;
    set<Student> students;
    unsigned short size = 0;
    string groupName;
    string specialization;
    unsigned short course = 0;

public:
    Group();

    Group(const Group& original);

    void Print() const;

    void NewStudent(const Student& newstudent);

    void ExcludedStudent(unsigned short index);

    void LaggingStudent();

    void SetCountOfStudent(int countstudent);

    int  GetCountOfStudent() const;

    void SetGroupName(string groupName);

    string GetGroupName() const;

    void SetSpecialization(string specialization);

    string GetSpecialization() const;

    void SetCourse(int course);

    int  GetCourse() const;

    


    Group& operator += (const Student& n)
    {
        NewStudent(n);
        return *this;
    }
    void PrintAllStudents() const;

    operator string()
    {
        return groupName + "\n" + specialization + "\n" + to_string(course) + "\n" + to_string(size);

    }
};