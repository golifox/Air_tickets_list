#include "Header.h"

constexpr bool IsRussianChar1251(const char c)
{
	return (c >= 'А' && c <= 'я') || c == 'ё' || c == 'Ё';
}

bool isRusWord(char *str){
	for (int i = 0; i < strlen(str); i++) {
		if (!IsRussianChar1251(str[i])) {
			return false;
		}
	}
	return true;
}

void W::move(W** AF, W** late, W** LF, int number)
{
	int k = 0;
	if (*AF == NULL) {
		cout << " Список пуст!" << endl;
	}
	else {
		char* fio, * reis, * date;
		fio = new char; reis = new char; date = new char;

		W* tmp = *AF;
		W* first = 0;

		if (number == (*AF)->number) {
			fio = (*AF)->fio;
			reis = (*AF)->reis;
			date = (*AF)->data;

			(*AF) = (*AF)->next;

			(**late).new_node(LF, number, fio, reis, date);

			tmp = tmp->next;
			cout << " Рейс успешно перемещен. . ."; _getch();
			k++;
		}
		else {
			if (tmp->next) {
				while (tmp->next && number == (*AF)->number) {
					first = tmp;
					tmp = tmp->next;

				}
			}
			if (tmp->next) {
				fio = (*AF)->fio;
				reis = (*AF)->reis;
				date = (*AF)->data;
				if (first) first->next = tmp->next;
				else first = tmp; first->next = tmp->next;

				(**late).new_node(LF, number, fio, reis, date);
				free(tmp);
				k++; cout << " Рейс успешно перемещен. . ."; _getch();
			}
			if (number == (*AF)->number) {
				fio = (*AF)->fio;
				reis = (*AF)->reis;
				date = (*AF)->data;

				first->next = 0;
				(**late).new_node(LF, number, fio, reis, date);
				free(tmp);
				k++; cout << " Рейс успешно перемещен. . ."; _getch();

			}
		}
		if (k == 0) {
			cout << "Совпадений нет!" << endl;
		}
	}
}

void W::new_node(W** LF, int num, char* fio, char* reis, char* data)
{
	W* tmp;
	W* tecush = *LF;
	W* first = 0;
	tmp = new W;

	while (tecush)
	{
		first = tecush;
		tecush = tecush->next;
	}

	(tmp)->number = num;
	strcpy_s((tmp)->fio, fio);
	strcpy_s((tmp)->reis, reis);
	strcpy((tmp)->data, data);

	(tmp)->next = NULL;
	if (first) {
		first->next = tmp;
	}
	else {
		*LF = tmp;
		(*LF)->next = NULL;
	}
}

void W::add(W** A, int number, char* fio, char* reis, char* data)
{
	W* actfirst;
	actfirst = new W;

	actfirst->number = number;
	strcpy_s(actfirst->fio, fio);
	strcpy_s(actfirst->reis, reis);
	strcpy(actfirst->data, data);
	actfirst->next = *A;
	*A = actfirst;
}

void W::del(W** A, char* l, char* sec)
{
	int u = 0;
	if (*A == NULL)
	{
		cout << "\n В списке нет ни одной записи.\n\n"; return;
	}
	if (*A)
	{
		W* old_item = *A;
		W* previous = 0;
		while (old_item != NULL)
		{
			if (sec == NULL)
			{ //если для удаления только один параметр
				if (strcmp(old_item->fio, l) == 0)
				{
					if (old_item == *A)
					{
						*A = (*A)->next;
						u++;
						old_item = (*A);
						continue;
					}
					if (old_item->next != NULL)
					{
						previous->next = old_item->next;
						u++;
						old_item = previous->next;
						continue;
					}
					if (old_item->next == NULL)
					{
						previous->next = NULL;
						u++;
						old_item = NULL;
						continue;
					}
				}
			}
			else { //если удаление по двум параметрам
				if (strcmp(old_item->fio, l) == 0 && strcmp(old_item->data, sec) == 0)
				{
					if (old_item == *A)
					{
						*A = (*A)->next;
						u++;
						old_item = (*A);
						continue;
					}
					if (old_item->next != NULL)
					{
						previous->next = old_item->next;
						u++;
						old_item = previous->next;
						continue;
					}
					if (old_item->next == NULL)
					{
						previous->next = NULL;
						u++;
						old_item = NULL;
						continue;
					}
				}
			}

			previous = old_item;
			old_item = old_item->next;
		}
		if (u == 0) cout << "\nТакой заявки нет\n\n";
		if (u > 0) cout << "\nИнформация удалена . . .\n\n";
	}
	else
	{
		cout << "\n В списке нет ни одной записи.\n\n";
	}
}

void W::print(W** s)
{
	W* tmp;
	tmp = *s;
	if (tmp == NULL)
	{
		cout << "\n Пусто!\n"; return;
	}
	cout.setf(ios::left);
	cout << setw(9) << "# Рейсa" << setw(15) << "Фамилия" << setw(17) << "Пункт назначения" << setw(11) << "Дата вылета" << endl;
	int i = 1;

	while (tmp != NULL)
	{

		cout << setw(2) << i << setw(7) << tmp->number << setw(15) << tmp->fio << setw(17) << tmp->reis << setw(11) << tmp->data << endl;
		tmp = tmp->next;
		i++;

	}
	cout << endl;
}

char* dataform() {
	char* data1 = new char[10];
	char* buffer = new char[17];
	const char* messageErr = "   Ошибка даты! Повторите ввод: ";

	int month, day, year;
	cout << "   Введите дату рейса (месяц): ";

	while (!(cin >> month) || month < 1 || month > 12 || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << messageErr;
	}

	cout << "   Введите дату рейса (день): ";
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
		while (!(cin >> day) || day < 1 || day > 31 || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << messageErr;
		}
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11) {
		while (!(cin >> day) || day < 1 || day > 30 || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << messageErr;
		}
	}
	else {
		while (!(cin >> day) || day < 1 || day > 28 || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << messageErr;
		}
	}

	cout << "   Введите дату рейса (год: 1900-2100) - ";
	while (!(cin >> year) || year < 1900 || month > 2100 || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << messageErr << "   Введите дату рейса (год) - ";
	}


	//красивый вывод даты, например если введено 7, отображаться будет 07
	if (day < 10) {
		strcpy(data1, "0");
		strcat(data1, _itoa(day, buffer, 10));
	}
	else {
		strcpy(data1, _itoa(day, buffer, 10));
	}
	strcat(data1, ".");

	if (month < 10) {
		strcat(data1, "0");
		strcat(data1, _itoa(month, buffer, 10));
	}
	else {
		strcat(data1, _itoa(month, buffer, 10));
	}
	strcat(data1, ".");

	strcat(data1, _itoa(year, buffer, 10));

	return data1;
}

int W::psk(W** s, bool flag, char* p, char* date) //flag true for output, date = NULL if just fio
{
	int count = 0, i = 1;
	W* t;
	t = *s;
	if (t == NULL)
	{
		cout << "Пусто!\n"; return count;
	}

	cout.setf(ios::left);
	cout << setw(9) << "# Рейсa" << setw(15) << "Фамилия" << setw(17) << "Пункт назначения" << setw(11) << "Дата вылета" << endl;
	while (t != NULL)
	{
		if (date != NULL) {
			if (strcmp(t->fio, p) == 0 && strcmp(t->data, date) == 0) {
				count++;

				if (flag == true) {
					cout << setw(2) << i << setw(7) << t->number << setw(15) << t->fio << setw(17) << t->reis << setw(11) << t->data << endl;
					i++;
				}
			}
			t = t->next;
		}
		else {
			if (strcmp(t->fio, p) == 0) {
				count++;

				if (flag == true) {
					cout << setw(2) << i << setw(7) << t->number << setw(15) << t->fio << setw(17) << t->reis << setw(11) << t->data << endl;
					i++;
				}
			}
			t = t->next;
		}

	}

	return count;
}

int W::searchs(W** s, int num) {
	int c=0;

	W* t = *s;
	if (t == NULL)
	{
		return 0;
	}

	while (t!= NULL) {
		if (t->number == num) {
			c++; 
		}
		t = t->next;
	}
	return c;
}

void information(){
	//инфОРМАЦИЯ

	cout << "инфОРМАЦИЯ " << endl;
}