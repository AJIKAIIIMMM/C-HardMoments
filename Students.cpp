#include <iostream>
#include "Univer.pb.h"
#include <string>
#include <fstream>


class IRepository {
	virtual void Open() = 0; 
	virtual void Save() = 0; 
};

class IMethods {
	virtual double GetAverageScore(const univer::FullName& name) = 0;
	virtual std::string GetAllInfo(const univer::FullName& name) = 0;
	virtual std::string GetAllInfo() = 0;
};

template<class T>
class StudentsGroup : private IRepository, IMethods {
	T m_studgr;
public:
	StudentsGroup(univer::StudentsGroup& studgr) : m_studgr(studgr) {

	}
	virtual void Open() {
		std::ofstream out("./", std::ios_base::binary);
		m_studgr.SerializeToOstream(&out);
	};
	virtual void Save() {
		std::ifstream in("./", std::ios_base::binary);
	};
	virtual double GetAverageScore(const univer::FullName& name) {
		for (int i = 0; i < m_studgr.student[i].size(); i++) {
			if(m_studgr.student[i].full() == name)
			std::cout << name << "has average score: " << m_studgr.student().get_averagescore();
		}
	};
	virtual std::string GetAllInfo(const univer::FullName& name) {
		for (int i = 0; i < m_studgr.student[i].size(); i++) {
			if (m_studgr.student[i].full() == name)
				std::cout << name << "has average score: " << m_studgr.student().get_averagescore();
		}
	};
	virtual std::string GetAllInfo() {
		for (int i = 0; i < m_studgr.student[i].size(); i++) {
			if (m_studgr.student[i].full() == name)
				std::cout << name << m_studgr.student().get_averagescore();
		}
	};

	bool operator ==(const univer::FullName& name,const univer::StudentsGroup& m_studgr) {
		return m_studgr.student().full().firstname() == name.firstname() &&
			m_studgr.student().full().secondname() == name.secondname() &&
			m_studgr.student().full().middlename() == name.middlename();
	}
	bool operator <<(const univer::FullName& name) {
		return std::cout << name.firstname() << name.secondname() << name.middlename();
	}
};


int main(){
	univer::FullName full;
	full.set_firstname("Vasya");
	full.set_secondname("Stolyrov");
	full.set_middlename("Petrovich");
	univer::Student student;
	student.set_allocated_full(&full);
	for (int i = 0; i < 10; i++) {
		double a;
		std::cout << "Enter last scores for this term:";
		std::cin >> a;
		student.add_scores(a);
	}
	int counter = 0;
	double scores;
	for (int i = 0; i < 10; i++) {
		
		scores += student.scores[i];
		counter++;
	}
	student.set_averagescore(scores / counter);
	univer::StudentsGroup studgr;
	studgr.add_student(&student);
	
	
	return 0;
}
