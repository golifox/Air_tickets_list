

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
		cout << "\n <1> Добавление ";
		cout << "\n <2> Посмотреть список ";
		cout << "\n <3> Поиск заявки по фамилии";
		cout << "\n <4> Отмена рейса";
		cout << "\n <5> Восстановление рейсов";
		cout << "\n <6> Помощь";
		cout << "\n <7> Выход";
		cout << "\n Введите пункт меню <> ";
		while (!(cin >> ch) || ch < 1 || ch > 7 || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << " Введите повторно пункт меню <> ";
		}
		switch (ch)
		{
		case 1:system("cls");
		{
			int mass;
			cout << "Сколько заявок добавить << ";

			while (!(cin >> mass) || mass < 1 || mass > 9999 || (cin.peek() != '\n'))
			{
				cout << "   Неверный ввод! Повторите: ";
				cin.clear();
				while (cin.get() != '\n');
			}


			for (int i = 0; i < mass; i++) {
				bool flag = false;
				cout << endl << "#" << i + 1;
				cout << (" Номер рейса: ");
				while (!(cin >> number) || number < 1 || number > 9999 || (*active).searchs(&actfirst, number) == 1 || (cin.peek() != '\n'))
				{
					cout << "   Неверный ввод! Повторите: ";
					cin.clear();
					while (cin.get() != '\n');
				}

				do
				{
					valid = false;
					cout << ("   Фамилия водителя: ");
					cin >> fio;
					if (isRusWord(fio)) valid = true;
				} while (valid != true);


				do
				{
					valid = false;
					cout << "   Введите пункт назначения(без пробелов): ";
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
				cout << "\n Введите сначала данные. Вернитесь обратно в меню. \n\n";
			}
			else
			{
				cout << "\n Вывести список : \n 1. Всех заявок \n 2. Активных рейсов \n 3. Отмененных рейсов \n Ваш выбор -";
				while (!(cin >> choice) || choice < 0 || choice > 3 || (cin.peek() != '\n'))
				{
					cin.clear();
					while (cin.get() != '\n');
				}
				if (choice == 1) {
					cout << "\n Активные рейсы: \n" << endl;
					(*active).print(&actfirst); cout << endl;
					cout << "\n Отмененные рейсы: \n" << endl;
					(*late).print(&latefirst); cout << endl;
				}
				else if (choice == 2) {
					cout << "\n Активные рейсы: " << endl;
					(*active).print(&actfirst); cout << endl;
				}
				else if (choice == 3) {
					cout << "\n Отмененные рейсы: " << endl;
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
				cout << "\n Введите сначала данные. Вернитесь обратно в меню. \n\n";
			}
			else
			{
				char* p = new char[15];
				valid = false;
				do
				{
					cout << " Введите фамилию для поиска - ";
					cin >> p;
					if (isRusWord(p)) valid = true;
				} while (valid != true);

				cout << " Вы ввели - " << p << endl;
				cout << "\nРезультаты поиска: \n Активные рейсы - " << endl;
				(*active).psk(&actfirst, true, p, NULL); // (первый элемент списка, номер для пермещения, проверка найден или нет)
				cout << "\n Отмененные рейсы - " << endl;
				(*late).psk(&latefirst, true, p, NULL); // (первый элемент списка, номер для пермещения, проверка найден или нет)
			}
			system("Pause");
			break;
		}
		case 4: {
			system("cls");
			if (condition == 0)
			{
				cout << "\n Введите сначала данные. Вернитесь обратно в меню. \n\n";
			}
			else
			{
				int pp;
				cout << "\n Введите номер отменяемого рейса? - ";

				while (!(cin >> pp) || pp < 1 || pp > 9999 || (cin.peek() != '\n'))
				{
					cout << " Неверный ввод! Повторите: ";
					cin.clear();
					while (cin.get() != '\n');
				}

				if ((*active).searchs(&actfirst, pp) == 0)
				{
					cout << " В активных рейсах заявки с номером " << pp << " не найдено!" << endl;
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
				cout << "\n Введите сначала данные. Вернитесь обратно в меню. \n\n";
			}
			else {
				cout << "\n Введите номер рейса, который нужно восстановить? ";

				while (!(cin >> pp) || pp < 1 || pp > 9999 || (cin.peek() != '\n'))
				{
					cout << "   Неверный ввод! Повторите: ";
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
			cout << "\nНажмите любую кнопку для выхода из программы . . . "; cin.get(); cin.get();
			exit(0);
		}
		}
	} while (ch != 8);
	return 0;
}