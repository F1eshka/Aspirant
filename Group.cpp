#include "Group.h"
#include <set>
#include <algorithm>


Group::Group() 
{
    SetGroupName("P26");
    SetCourse(3);
    SetSpecialization("Programmer and software developer");
}

void Group::Print() const
{
    cout << groupName << "\n";
    for (int i = 0; i < size; i++)
    {
        students[i].AverageGrade();
        students[i].PrintStudent();
    }
}

void Group::NewStudent(const Student& newstudent)
{
    countstudents++;
    students.insert(newstudent);
}

void Group::ExcludedStudent(const Student& delete_student)
{
    size--;
    students.erase(delete_student);
}

void Group::LaggingStudent()
{
    if (countstudents == 0) {
        cout << "The group is done\n\n";
        return;
    }
    int minGradeIndex = 0;
    auto minGradeStudent = students.begin();

    for (const auto& current : students)
    {
        if (current.GetAverageGrade() < minGradeStudent->GetAverageGrade())
        {
            minGradeStudent = students.find(current);
        }
    }
    LaggingStudent(*minGradeStudent);
    cout << "The student with the lowest grade point average is expelled from the group.\n\n";
}
void Group::SetCountOfStudent(int size)
{
    this->size = size;
}

int Group::GetCountOfStudent() const
{
    return size;
}

    void Group::SetGroupName(const string& groupName) {
        this->groupName = groupName;
    }

    string Group::GetGroupName() const {
        return groupName;
    }

    void Group::SetSpecialization(const string& specialization) {
        this->specialization = specialization;
    }

    string Group::GetSpecialization() const {
        return specialization;
    }

    void Group::SetCourse(int course) {
        this->course = course;
    }

    int Group::GetCourse() const {
        return course;
    }

    void Group::PrintAllStudents() const {
        cout << GetGroupName() << "\n";

        for (int i = 0; i < size; ++i) {
            students[i]->PrintStudent();
        }
    }

    };