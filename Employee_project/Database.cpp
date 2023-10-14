module Database;
import Employee;
import<iostream>;
import<stdexcept>;
using namespace std;


namespace Records {
	
	Employee& Database::addEmployee(const std::string firstName, const std::string lastName) {
		Employee theEmployee(firstName, lastName);
		theEmployee.setEmployeeNumber(m_nextEmployeeNumber++);
		theEmployee.hire();
		m_employees.push_back(theEmployee);
		return m_employees.back();
	}

	Employee& Database::getEmployee(int employeeNumber) {
		for (auto& employee : m_employees) {
			if (employee.getEmployeeNumber() == employeeNumber) {
				return employee;
			}

		}
		return m_employees.back();
		//throw logic_erro("没有该员工。");
	}
	
	Employee& Database::getEmployee(const std::string firstName, const std::string lastName) {
		for (auto& employee : m_employees) {
			if (employee.getFirstName() == firstName && employee.getLastName() == lastName) {
				return employee;
			}
			

		}
		//throw logic_erro("没有该员工。");
		return m_employees.back();
			
	}

	void Database::displayAll()const {
		for (const auto& employee : m_employees) {
			employee.display();
		}
	}
	void Database::displayCurrent()const {
		for (const auto& employee : m_employees) {
			if (employee.isHired()) {
				employee.display();
			}
		}
	}
	void Database::displayFormer()const {
		for (const auto& employee : m_employees) {
			if (!employee.isHired()) {
				employee.display();
			}
		}
	}

}
