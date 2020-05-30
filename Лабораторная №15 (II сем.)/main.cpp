#include <iostream>
#include <memory>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::auto_ptr;
using std::unique_ptr;
using std::shared_ptr;
using std::weak_ptr;

struct Unit
{
	Unit(string name) { cout << "Unit()" << endl; };
	~Unit() { cout << "~Unit()" << endl; };
	/*shared_ptr<Unit> target;*/
	weak_ptr<Unit> target;
};

int main()
{
	{
		cout << "USING AUTO POINTER:\n";
		auto_ptr<Unit> warior1(new Unit("warior"));
		auto_ptr<Unit> warior2(warior1);
	}
	cout << endl;
	{
		cout << "USING UNIQUE POINTER:\n";
		unique_ptr<Unit> warior1 = std::make_unique<Unit>("warior");
		/*unique_ptr<int> warior2(warior1);*/
		unique_ptr<Unit> warior3;
		warior3 = std::move(warior1);
	}
	cout << endl;
	{
		cout << "USING SHARED POINTER:\n";
		shared_ptr<Unit> warior1 = std::make_shared<Unit>("warior");
		shared_ptr<Unit> warior2(warior1);
	}
	cout << endl;
	{
		cout << "USING WEAK POINTER:\n";
		shared_ptr<Unit> warior = std::make_shared<Unit>("warior");
		shared_ptr<Unit> archer = std::make_shared<Unit>("archer");
		cout << warior.use_count() << " : " << warior->target.use_count() << endl;
		cout << archer.use_count() << " : " << archer->target.use_count() << endl << endl;
		warior->target = archer;
		cout << warior.use_count() << " : " << warior->target.use_count() << endl;
		cout << archer.use_count() << " : " << archer->target.use_count() << endl << endl;
		archer->target = warior;
		cout << warior.use_count() << " : " << warior->target.use_count() << endl;
		cout << archer.use_count() << " : " << archer->target.use_count() << endl;
	}
	cout << endl;
	system("pause");
	return 0;
}