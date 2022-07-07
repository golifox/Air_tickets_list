

#include "Header.h"

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "Russian");

	W* active, * late, * actfirst = 0, *latefirst = 0;
	active = new W;
	late = new W;


	int number;
	char* fio = new char[15];
	char* reis = new char[15];
	char* date = new char[10];

	bool valid = false;

	int ch = 0, condition = 0;
	do {
		system("cls");
		cout << "\n <1> ���������� ";
		cout << "\n <2> ���������� ������ ";
		cout << "\n <3> ����� ������ �� �������";
		cout << "\n <4> ������ �����";
		cout << "\n <5> �������������� ������";
		cout << "\n <6> ������";
		cout << "\n <7> �����";
		cout << "\n ������� ����� ���� <> ";
		while (!(cin >> ch) || ch < 1 || ch > 7 || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << " ������� �������� ����� ���� <> ";
		}
		switch (ch)
		{
		case 1:system("cls");
		{
			int mass;
			cout << "������� ������ �������� << ";

			while (!(cin >> mass) || mass < 1 || mass > 9999 || (cin.peek() != '\n'))
			{
				cout << "   �������� ����! ���������: ";
				cin.clear();
				while (cin.get() != '\n');
			}


			for (int i = 0; i < mass; i++) {
				bool flag = false;
				cout << endl << "#" << i + 1;
				cout << (" ����� �����: ");
				while (!(cin >> number) || number < 1 || number > 9999 || (*active).searchs(&actfirst, number) == 1 || (cin.peek() != '\n'))
				{
					cout << "   �������� ����! ���������: ";
					cin.clear();
					while (cin.get() != '\n');
				}

				do
				{
					valid = false;
					cout << ("   ������� ��������: ");
					cin >> fio;
					if (isRusWord(fio)) valid = true;
				} while (valid != true);


				do
				{
					valid = false;
					cout << "   ������� ����� ����������(��� ��������): ";
					cin >> reis;

					if (isRusWord(reis)) valid = true;
				} while (valid != true);

				date = dataform();

				(*active).new_node(&actfirst, number, fio, reis, date);
			}
			condition = 1;
		}
		break;

		case 2:system("cls");
		{
			int choice;
			if (condition == 0)
			{
				cout << "\n ������� ������� ������. ��������� ������� � ����. \n\n";
			}
			else
			{
				cout << "\n ������� ������ : \n 1. ���� ������ \n 2. �������� ������ \n 3. ���������� ������ \n ��� ����� -";
				while (!(cin >> choice) || choice < 0 || choice > 3 || (cin.peek() != '\n'))
				{
					cin.clear();
					while (cin.get() != '\n');
				}
				if (choice == 1) {
					cout << "\n �������� �����: \n" << endl;
					(*active).print(&actfirst); cout << endl;
					cout << "\n ���������� �����: \n" << endl;
					(*late).print(&latefirst); cout << endl;
				}
				else if (choice == 2) {
					cout << "\n �������� �����: " << endl;
					(*active).print(&actfirst); cout << endl;
				}
				else if (choice == 3) {
					cout << "\n ���������� �����: " << endl;
					(*late).print(&latefirst); cout << endl;
				}
			}
			system("Pause");
		}
		break;
		case 3:system("cls");
		{
			if (condition == 0)
			{
				cout << "\n ������� ������� ������. ��������� ������� � ����. \n\n";
			}
			else
			{
				char* p = new char[15];
				valid = false;
				do
				{
					cout << " ������� ������� ��� ������ - ";
					cin >> p;
					if (isRusWord(p)) valid = true;
				} while (valid != true);

				cout << " �� ����� - " << p << endl;
				cout << "\n���������� ������: \n �������� ����� - " << endl;
				(*active).psk(&actfirst, true, p, NULL); // (������ ������� ������, ����� ��� ����������, �������� ������ ��� ���)
				cout << "\n ���������� ����� - " << endl;
				(*late).psk(&latefirst, true, p, NULL); // (������ ������� ������, ����� ��� ����������, �������� ������ ��� ���)
			}
			system("Pause");
			break;
		}
		case 4: {
			system("cls");
			if (condition == 0)
			{
				cout << "\n ������� ������� ������. ��������� ������� � ����. \n\n";
			}
			else
			{
				int pp;
				cout << "\n ������� ����� ����������� �����? - ";

				while (!(cin >> pp) || pp < 1 || pp > 9999 || (cin.peek() != '\n'))
				{
					cout << " �������� ����! ���������: ";
					cin.clear();
					while (cin.get() != '\n');
				}

				if ((*active).searchs(&actfirst, pp) == 0)
				{
					cout << " � �������� ������ ������ � ������� " << pp << " �� �������!" << endl;
				}
				else
				{
					(*active).move(&actfirst, &late, &latefirst, pp);
	
				}
			}
			system("Pause");
			break;
		}
				

		case 5: system("cls");
		{
			int pp;
			if (condition == 0) {
				cout << "\n ������� ������� ������. ��������� ������� � ����. \n\n";
			}
			else {
				cout << "\n ������� ����� �����, ������� ����� ������������? ";

				while (!(cin >> pp) || pp < 1 || pp > 9999 || (cin.peek() != '\n'))
				{
					cout << "   �������� ����! ���������: ";
					cin.clear();
					while (cin.get() != '\n');
				}
			
				(*late).move(&latefirst, &active, &actfirst, pp);


			}
			system("pause");
		}
		break;
		case 6:system("cls");
		{
			information();
			system("Pause");
		}
		break;
		case 7:
		{
			cout << "\n������� ����� ������ ��� ������ �� ��������� . . . "; cin.get(); cin.get();
			exit(0);
		}
		}
	} while (ch != 8);
	return 0;
}