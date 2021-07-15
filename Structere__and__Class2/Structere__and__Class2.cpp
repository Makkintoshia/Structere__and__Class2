#include <string>
#include <iostream>

using namespace std;




class DateClass // члены класса являются закрытыми по умолчанию
{
    int m_day; // закрыто по умолчанию, доступ имеют только другие члены класса
    int m_month; // закрыто по умолчанию, доступ имеют только другие члены класса
    int m_year; // закрыто по умолчанию, доступ имеют только другие члены класса
   
public:
    Person(string n, int a)
    {
        name = n; age = a;
    }
    void setDate(int day, int month, int year) // открыто, доступ имеет любой объект
    {
        // Метод setDate() имеет доступ к закрытым членам класса, так как сам является членом класса
        m_day = day;
        m_month = month;
        m_year = year;
    }
    void display()
    {
        std::cout << "Name: " << name << "\tAge: " << age << std::endl;
    }
    void print() // открыто, доступ имеет любой объект
    {
        cout << m_day << "/" << m_month << "/" << m_year;
    }
protected:
    string name;
private:
    int age;
};

class Employee : public DateClass
{
public:
    Employee(std::string n, int a, std::string c) : Person(n, a)
    {
        company = c;
    }
    void showEmployeeName()
    {
        std::cout << "Employee Name: " << name << std::endl;
    }
private:
    std::string company;
};

int main()
{
    Employee bob("Bob", 31, "Microsoft");
    bob.showEmployeeName();

    DateClass date;
    date.setDate(12, 11, 2018); // ок, так как setDate() имеет спецификатор доступа public
    date.print(); // ок, так как print() имеет спецификатор доступа public

    return 0;
}
