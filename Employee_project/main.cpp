import<iostream>;
import<stdexcept>;
import<exception>;
import<string>;
import Database;
import Employee;

using namespace std;
using namespace Records;

int displayMenu();
void doHire(Database& db);
void doFire(Database& db);
void doPromote(Database& db);

int main() {
	Database employeeDB;
	bool done{ false };
	while (!done)
	{
		int selection{ displayMenu() };
		switch (selection)
		{
		case 0:
				done = true;
				break;
		case 1:
			doHire(employeeDB);
			break;
		case 2:
			doFire(employeeDB);
			break;
		case 3:
			doPromote(employeeDB);
			break;
		case 4:
			employeeDB.displayAll();
			break;
		case 5:
			employeeDB.displayCurrent();
			break;
		case 6:
			employeeDB.displayFormer();
			break;
		default:
			cerr << "未知命令。" << endl;
			break;
		}

	}
}
int displayMenu() {
	int selection;
	cout << endl;
	cout << "员工数据库" << endl;
	cout << "-----------------------------------" << endl;
	cout << "(1)雇佣一个新员工" << endl;
	cout << "(2)开除一个新员工" << endl;
	cout << "(3)为一名员工提薪" << endl;
	cout << "(4)列出所有的员工" << endl;
	cout << "(5）列出所有在职员工" << endl;
	cout << "(6)列出所有离职员工" << endl;
	cout << "(0)退出" << endl;
	cout << endl;
	cout << "-----------------------------------" << endl;
	cin >> selection;
	return selection;
}

void doHire(Database& db) {
	string firstName;
	string lastName;

	cout << "请输入姓：";
	cin >> firstName;

	cout << "请输入名字：";
	cin >> lastName;

	auto& employee(db.addEmployee(firstName, lastName));
	cout << format("雇佣员工{}{}的员工号是：{}", firstName, lastName, employee.getEmployeeNumber()) << endl;
}
void doFire(Database& db) {
	int employeeNumber;
	cout << "员工号是：";
	cin >> employeeNumber;
	try
	{
		auto& emp(db.getEmployee(employeeNumber));
		emp.fire();
		cout << format("员工{}被开除了。", employeeNumber);
	}
	catch (const std::logic_error& exception)
	{
		cerr << format("未能开除员工：{}", exception.what()) << endl;
	}
}

void doPromote(Database& db) {
	int employeeNumber;
	cout << "员工号是：";
	cin >> employeeNumber;

	int raiseAmount;
	cout << "加多少薪酬：";
	cin >> raiseAmount;

	try
	{
		auto& emp(db.getEmployee(employeeNumber));
		emp.promote(raiseAmount);
	}
	catch (const std::logic_error& exception)
	{
		cerr << format("未能给员工{}提薪。", exception.what()) << endl;
	}
}