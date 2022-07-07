#pragma once

#ifndef HEADER_H
#define HEADER_H

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include "windows.h"
#include "conio.h"
#include <stdio.h>
#include <iomanip>
#include <cctype>
#include <string>

using namespace std;

class W
{
public:
	void new_node(W** LF, int, char*, char*, char*);
	void move(W**, W**, W**, int);
	void del(W**, char*, char*);
	void print(W**);
	void add(W**, int, char*, char*, char*);
	int psk(W**, bool, char*, char*);
	int searchs(W**, int);

private:
	int number;
	char fio[15]; char reis[15];
	char* data = new char[10];
	W* next;
};

constexpr bool IsRussianChar1251(const char c);
bool isRusWord(char* str);
char* dataform();

void information();

#endif