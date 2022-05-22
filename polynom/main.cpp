#include <iostream>
#include <string.h>
#include "TPolynom.h"

using namespace std;

int main()
{
	TPolynom t1;
	t1.AddMonom(1, 1, 0, 0);

	TPolynom t2;
	t2.AddMonom(1, 0, 1, 1);
	t2.AddMonom(2, 0, 0, 1);

	TPolynom result;
	result = t1 * t2;

	TPolynom correct("x*y*z+2*x*z");
	cout << "result = " << result << "\n";
	cout << "correct = " << correct << "\n";

	//

	TPolynom t3;
	t3.AddMonom(1, 1, 0, 0);
	t3.AddMonom(1, 0, 0, 0);

	TPolynom t4;
	t4.AddMonom(-1, 1, 0, 0);
	t4.AddMonom(-1, 0, 0, 0);

	TPolynom sum;
	sum = t3 + t4;
	cout << "sum = " << sum << "\n\n";

	//

	while (true)
	{
		char key;
		string str;

		cout << "Polynom #1 = ";
		getline(cin, str);
		TPolynom p1(str);

		cout << "Polynom #2 = ";
		getline(cin, str);
		TPolynom p2(str);

		cout << "Operation: ";
		cin >> key;
		switch (key)
		{
		case '+':
			cout << "result = " << p1 + p2 << "\n\n";
			break;
		case '-':
			cout << "result = " << p1 - p2 << "\n\n";
			break;
		case '*':
			cout << "result = " << p1 * p2 << "\n\n";
			break;
		}
		cin.ignore(1);
	}

	return 0;
}