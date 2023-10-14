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
			cerr << "δ֪���" << endl;
			break;
		}

	}
}
int displayMenu() {
	int selection;
	cout << endl;
	cout << "Ա�����ݿ�" << endl;
	cout << "-----------------------------------" << endl;
	cout << "(1)��Ӷһ����Ա��" << endl;
	cout << "(2)����һ����Ա��" << endl;
	cout << "(3)Ϊһ��Ա����н" << endl;
	cout << "(4)�г����е�Ա��" << endl;
	cout << "(5���г�������ְԱ��" << endl;
	cout << "(6)�г�������ְԱ��" << endl;
	cout << "(0)�˳�" << endl;
	cout << endl;
	cout << "-----------------------------------" << endl;
	cin >> selection;
	return selection;
}

void doHire(Database& db) {
	string firstName;
	string lastName;

	cout << "�������գ�";
	cin >> firstName;

	cout << "���������֣�";
	cin >> lastName;

	auto& employee(db.addEmployee(firstName, lastName));
	cout << format("��ӶԱ��{}{}��Ա�����ǣ�{}", firstName, lastName, employee.getEmployeeNumber()) << endl;
}
void doFire(Database& db) {
	int employeeNumber;
	cout << "Ա�����ǣ�";
	cin >> employeeNumber;
	try
	{
		auto& emp(db.getEmployee(employeeNumber));
		emp.fire();
		cout << format("Ա��{}�������ˡ�", employeeNumber);
	}
	catch (const std::logic_error& exception)
	{
		cerr << format("δ�ܿ���Ա����{}", exception.what()) << endl;
	}
}

void doPromote(Database& db) {
	int employeeNumber;
	cout << "Ա�����ǣ�";
	cin >> employeeNumber;

	int raiseAmount;
	cout << "�Ӷ���н�꣺";
	cin >> raiseAmount;

	try
	{
		auto& emp(db.getEmployee(employeeNumber));
		emp.promote(raiseAmount);
	}
	catch (const std::logic_error& exception)
	{
		cerr << format("δ�ܸ�Ա��{}��н��", exception.what()) << endl;
	}
}