#pragma once
#include <string>
#include <iostream>
#include <ctime>
#include <fstream>
#include <windows.h>
#include <vector>


using namespace std;


class Student
{
        
        string surname;
        string name;
        string middlename;
        string adress;
        string phonenumber;
        int averagegrade;
        vector<int> grade_of_practic;
        vector<int> grade_of_homework;
        vector<int> grade_of_exam;
        static unsigned int count;

    public:
       

        Student(const Student& original);
        Student();
        Student(string surname, string name, string middlname, string adress, string phonenumber);
        Student(string surname, string name, string middlname, string adress){}
        ~Student();
        void PrintStudent() const;
        static unsigned int GetCount();
        void Time();
        void AverageGrade();
        void AddPractic(int newcountry);
        void PrintPractic() const;
        int  GePracticRatesCount(unsigned int index) const;
        void AddHomeWork(int newcountry);
        void PrintHomeWork() const;
        int  GetHomeWorkRatesCount(unsigned int index) const;
        void AddExam(int newcountry);
        void PrintExam() const;
        int  GetExamRatesCount(unsigned int index) const;
        void SetSurname(string surname);
        string GetSurname() const;
        void SetName(string name);
        string GetName() const;
        void SetMiddlName(string middlname);
        string GetMiddlName() const;
        void SetAdress(string adress);
        string GetAdress() const;
        void SetPhone(string phonenumber);
        string GetPhone() const;
        void GoToPeresdacha(Student s);
        void SetAverageGrade(int averagegrade);
        int  GetAverageGrade() const;

        bool operator<(const Student& other) const
        {
            return this->GetSurname() < other.GetSurname();
        }

        operator string()
        {
            return surname + "\n" + name + "\n" + middlename + "\n" + to_string(averagegrade) + "\n" + phonenumber;
        }
};

