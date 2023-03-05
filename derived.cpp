#include <iostream>
#include <cstring>
using namespace std;
//人类 
class Person
{
public:
	Person(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}
	void info()
	{
		cout << "Person Name = " << this->m_name << " Age = " << this->m_age << endl;
	}
protected:
	string m_name;
	int m_age;
};
//学生类 
class Student : public Person
{
public:
	// using Person::Person;
	// Student(string name, int age, float score) {
	// 			Person::m_name = name;
	// 			Person::m_age = age;
	// 			m_score = score;
	// }
	Student(string name, int age, float score):Person(name, age), m_score(score)
	{
	}
	void info()
	{
		cout << "Student Name = " << this->m_name << " Age = " << this->m_age << " Score = " << this->m_score << endl;
	}
private:
	float m_score;
};
int main(void)
{
	cout << "(www.haicoder.net)\n" << endl;
	Student stu("HaiCoder", 109);
	Student stu1("HaiCoder", 109, 99.95);
	stu.info();
	stu1.info();
	return 0;
}