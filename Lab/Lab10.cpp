#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Student
{
    private:
        string m_name;
        int m_id;
        string m_depart;
        vector<string> m_subject;
        vector<char> m_grade;

    public:
        Student(): m_name("defualt"), m_id(0), m_depart("depart") {}
        Student(string name, int id, string depart): m_name(name), m_id(id), m_depart(depart) {}

        void setName(string name)
        {
            m_name = name;
        }

        void setID(int id)
        {
            m_id = id;
        }

        void setDpt(string depart)
        {
            m_depart = depart;
        }

        void addGrade(string subject, char grade)
        {
            m_subject.push_back(subject);
            m_grade.push_back(grade);
        }

        void printGrades()
        {
            for(int i = 0; i < m_subject.size(); i++)
                cout << m_subject[i] << " " << m_grade[i] << endl;
            cout << "GPA : " << getGPA();
        }

        float getGPA()
        {
            float sum = 0;
            for(const auto elem: m_grade)
            {
                switch (elem)
                {
                case 'A':
                    sum += 4;
                    break;
                case 'B':
                    sum += 3;
                    break;
                case 'C':
                    sum += 2;
                    break;
                case 'D':
                    sum += 1;
                    break;
                case 'F':
                    break;
                }

            }
            return sum / m_grade.size();
        }

        void getYear(int year)
        {
            int grade = year - m_id / 1000000 + 1;

            switch (grade)
            {
            case 1:
                cout << "Freshman(1학년)" << endl;
                break;
            case 2:
                cout << "Sophomore(2학년)" << endl;
                break;
            case 3:
                cout << "Junior(3학년)" << endl;
                break;
            case 4:
                cout << "Senior(4학년)" << endl;
                break;
            default:
                cout << "About to graduate(5학년)" << endl;
                break;
            }
            
        }

        void print()
        {
            cout << m_name << " " << m_id << " " << m_depart << endl;
        }
};

int main() {
	Student Harry("Harry", 2017310973, "CS");
	Harry.print();
	Harry.getYear(2019);
	Harry.addGrade("programming", 'A');
	Harry.addGrade("Basic Circuit", 'B');
	Harry.printGrades();
	cout << "\n\n";

	Student Ron;
	Ron.print();
	cout << "\n";
	Ron.setName("Ron");
	Ron.setID(2014103959);
	Ron.setDpt("EE");
	Ron.print();
	Ron.getYear(2019);
	Ron.addGrade("Computer Architecture", 'B');
	Ron.addGrade("Maching Learning", 'B');
	Ron.addGrade("Computer Vision", 'C');
	Ron.printGrades();
	cout << "\n\n";

	return 0;
}
