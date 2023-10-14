module Employee;
import<iostream>;
using namespace std;

namespace Records {

	Employee::Employee(const string& firstName, const string& lastName) :m_firstName{ firstName }, m_lastName{ lastName } {}

	void Employee::promote(int raiseAmount) {
		setSalary(getSalary() + raiseAmount);
	}

	void Employee::demote(int demeritAmount) {
		setSalary(getSalary() - demeritAmount);
	}

	void Employee::hire() { m_hired = true; };
	void Employee::fire() { m_hired = false; };

	void Employee::display()const {
		cout << "--------------------------------------------------" << endl;
		cout << format("员工：{}{}", getFirstName(), getLastName()) << endl;
		cout << (isHired() ? "在职员工" : "已离职员工") << endl;
		cout << format("员工号：{}", getEmployeeNumber());
		cout << format("工资：￥{}", getSalary());
		cout << endl;

	}

	void Employee::setFirstName(const string& firstname) {
		m_firstName = firstname;
	}
	const string& Employee::getFirstName() const {
		return m_firstName;
	}

	void Employee::setLastName(const string& lastname) {
		m_lastName = lastname;
	}
	const string& Employee::getLastName() const {
		return m_lastName;
	}

	void Employee::setEmployeeNumber(int employeeNumber) {
		m_employeeNumber = employeeNumber;
	}
	int Employee::getEmployeeNumber()const {
		return m_employeeNumber;
	}

	void Employee::setSalary(int newSalary) {
		m_salary = newSalary;
	}
	int Employee::getSalary()const {
		return m_salary;
	}
	bool Employee::isHired()const {
		return m_hired;
	}
}