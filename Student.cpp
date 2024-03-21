#include "Logger.h"
#include "Student.h"
#include <iostream>
using namespace std;

    /// <summary>
    /// Конструктор копирования класса Student.
    /// Создает копию студента на основе переданного объекта.
    /// </summary>
    /// <param name="original">Оригинальный студент, который будет скопирован.</param>
    

    /// <summary>
    ///  Конструктор по умолчанию класса Student.
    /// Инициализирует студента значениями по умолчанию.
    /// </summary>
    Student::Student() : Student("Benoeva", "Malika", "Khasanovna", "Filatovo 7", "0734054475") { Logger::GetInstance()->Write("Student has been created\n"); }

    /// <summary>
    /// Конструктор класса Student.
    /// Инициализирует студента с переданными значениями.
    /// </summary>
    /// <param name="surname">Фамилия студента.</param>
    /// <param name="name">Имя студента.</param>
    /// <param name="middlname">Отчество студента.</param>
    /// <param name="adress">Адрес студента.</param>
    /// <param name="phonenumber">Номер телефона студента.</param>
    Student::Student(string surname, string name, string middlname, string adress, string phonenumber)
    {
        count++;
        SetSurname(surname);
        SetName(name);
        SetMiddlName(middlname);
        SetAdress(adress);
        SetPhone(phonenumber);
    }
    
    Student::Student(string surname, string name, string middlname, string adress) :Student(surname, name, middlename, adress, "0674078044") { count++; }


    /// <summary>
    /// Деструктор класса Student.
    /// Освобождает память, занятую массивами оценок.
    /// </summary>
    Student::~Student()
    {
        count--;
        //if (grade_of_practic != nullptr)
        //    delete[] grade_of_practic;
        //if (grade_of_homework != nullptr)
        //    delete[] grade_of_homework;
        //if (grade_of_exam != nullptr)
         //   delete[] grade_of_exam;
    }

   
    /// <summary>
    /// Выводит информацию о студенте в консоль.
    /// </summary>
    void Student::PrintStudent() const
    {
        cout << "Surname: " << surname << "\n";
        cout << "Name: " << name << "\n";
        cout << "Midlname: " << middlename << "\n";
        cout << "Adress: " << adress << "\n";
        cout << "PhoneNumber: " << phonenumber << "\n";
        PrintExam();
        PrintPractic();
        PrintHomeWork();

    }

    unsigned int Student::GetCount()
    {
        return count;
    }

    void  Student::AverageGrade()
    {

        for (int i = 0; i < grade_of_exam.size(); i++)
        {
            averagegrade += grade_of_exam[i] / grade_of_exam.size();
        }
        cout << averagegrade << "\n";
    }



    /// <summary>
    /// Добавляет новую оценку за практику студенту.
    /// </summary>
    /// <param name="newcountry">Новая оценка за практику.</param>
    void Student::AddPractic(int newpractic)
    {
        grade_of_practic.push_back(newpractic);
    }


    /// <summary>
    /// Выводит оценки за практику студента в консоль.
    /// </summary>
    void Student::PrintPractic() const
    {
        cout << "Practic:  ";
        for (int i = 0; i < grade_of_practic.size(); i++)
        {
            cout << grade_of_practic[i] << ", ";
        }
        cout << "\n";
    }

    /// <summary>
    /// Получает оценку за практику студента по указанному индексу.
    /// </summary>
    /// <param name="index">Индекс оценки за практику</param>
    /// <returns>Оценка за практику по указанному индексу</returns>
    int Student::GePracticRatesCount(unsigned int index) const
    {
        return grade_of_practic.at(index);
    }


    /// <summary>
    /// Добавляет новую оценку за домашнюю работу студенту
    /// </summary>
    /// <param name="newcountry">Новая оценка за домашнюю работу</param>
    void Student::AddHomeWork(int new_homework)
    {
        grade_of_homework.push_back(new_homework);
    }

    /// <summary>
    /// Выводит оценки за домашнюю работу студента в консоль.
    /// </summary>
    void Student::PrintHomeWork() const
    {
        cout << "HomeWork:  ";
        for (int i = 0; i < grade_of_homework.size(); i++)
        {
            cout << grade_of_homework[i] << ", ";
        }
        cout << "\n";
    }

    /// <summary>
    /// Получает оценку за домашнюю работу студента по указанному индексу.
    /// </summary>
    /// <param name="index">Индекс оценки за домашнюю работу</param>
    /// <returns>Оценка за домашнюю работу по указанному индексу</returns>
    int Student::GetHomeWorkRatesCount(unsigned int index) const
    {
        return grade_of_homework.at(index);
    }

    /// <summary>
    /// Добавляет новую оценку за экзамен студенту
    /// </summary>
    /// <param name="newcountry">Новая оценка за экзамен</param>
    void Student::AddExam(int newexam)
    {
        grade_of_exam.push_back(newexam);
    }


    /// <summary>
    /// Выводит оценки за экзамен студента в консоль
    /// </summary>
    void Student::PrintExam() const
    {
        cout << "Exam:  ";
        for (int i = 0; i < grade_of_exam.size(); i++)
        {
            cout << grade_of_exam[i] << ",";
        }
        cout << "\n";
    }

    /// <summary>
    /// Получает оценку за экзамен студента по указанному индексу
    /// </summary>
    /// <param name="index">Индекс оценки за экзамен</param>
    /// <returns>Оценка за экзамен по указанному индексу</returns>
    int Student::GetExamRatesCount(unsigned int index) const
    {
        return grade_of_exam.at(index);
    }

    /// <summary>
    /// Устанавливает фамилию студента
    /// </summary>
    /// <param name="surname">Новая фамилия студента</param>
    void Student::SetSurname(string surname)
    {
        this->surname = surname;
    }

    /// <summary>
    /// Возвращает фамилию студента
    /// </summary>
    /// <returns>Фамилия студента</returns>
    string Student::GetSurname() const
    {
        return surname;
    }

    /// <summary>
    /// Устанавливает имя студента
    /// </summary>
    /// <param name="name">Новое имя студента</param>
    void Student::SetName(string name)
    {
        this->name = name;
    }

    /// <summary>
    /// Возвращает имя студента
    /// </summary>
    /// <returns>Имя студента</returns>
    string Student::GetName() const
    {
        return name;
    }

    /// <summary>
    /// Устанавливает отчество студента
    /// </summary>
    /// <param name="middlname">Новое отчество студента</param>
    void Student::SetMiddlName(string middlname)
    {
        this->middlename = middlname;
    }

    /// <summary>
    /// Возвращает отчество студента
    /// </summary>
    /// <returns>Отчество студента</returns>
    string Student::GetMiddlName() const
    {
        return middlename;
    }

    /// <summary>
    /// Устанавливает адрес студента
    /// </summary>
    /// <param name="adress">Новый адрес студента</param>
    void Student::SetAdress(string adress)
    {
        this->adress = adress;
    }

    /// <summary>
    /// Возвращает адрес студента
    /// </summary>
    /// <returns>Адрес студента</returns>
    string Student::GetAdress() const
    {
        return adress;
    }

    /// <summary>
    ///  Устанавливает номер телефона студента
    /// </summary>
    /// <param name="phonenumber">Новый номер телефона студента</param>
    void Student::SetPhone(string phonenumber)
    {
        this->phonenumber = phonenumber;
    }

    /// <summary>
    /// Возвращает номер телефона студента
    /// </summary>
    /// <returns>Номер телефона студента</returns>
    string Student::GetPhone() const
    {
        return phonenumber;
    }

    /// <summary>
    /// Метод для демонстрации работы с передачей студента по значению.
    /// </summary>
    /// <param name="s">Студент, который будет передан</param>
    void Student::GoToPeresdacha(Student s)
{
    cout << "hey hey peresdacha...\n";
}
    void Student::SetAverageGrade(int averagegrade)
    {
        this->averagegrade = averagegrade;
    }
    int Student::GetAverageGrade() const
    {
        return averagegrade;
    }

    unsigned int Student::count;