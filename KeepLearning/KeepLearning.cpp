#include<exception>
#include<iostream>
#include<stdexcept>
#include<string>
#include<new>
#include<cstdlib>
#include<typeinfo>
using std::string;

using std::exception;

class throwException : public exception {
	terminate_handler set_terminate(terminate_handler f) noexcept;
	void terminate() noexcept;
};

template <typename T>
class UseTp {
	T user;
	string m_name;
	long id;
protected:
	bool Fill;
	enum { student, teacher };
public:
	UseTp(T& t, string name = nullptr, long id = 0) :user(t), m_name(name), Fill(false), id(id) {
		std::cout << "UseTp has been created!!!" << std::endl;
	}
	void showBuff(long val, string operation) const;
	friend void getName(UseTp<double>& t);
	friend int getName(UseTp<int>& t);
	~UseTp() {
		std::cout << "UseTp has been deleted!" << std::endl;
	}
};

class UseTp1 : public UseTp<double> {
	
};

class UseTp2 : public UseTp1 {

};

void UseTp<double>::showBuff(long val, string operation) const {

}

void UseTp<string>::showBuff(long val, string operation) const {

}

void UseTp<int>::showBuff(long val, string operation) const {

}

void getName(UseTp<double>& t) {
	std::cout << t.m_name << std::endl;
}

int getName(UseTp<int>& t) {
	return t.id;
}

int main(int argc, char* argv[], char* envp[]) {
	double m = 8.98;
	UseTp<double> ch(m, "hejuihui", 41823);
	return 0;
}

