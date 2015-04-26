// Copyright 2015 Vasilieva Maria, Rusyaev Sergey

#include "stdafx.h"
#include "struct.h"
#include <iostream>

//

//������ MUL_Z_Z  (�������� ����� ����� �� (-1)):
//��� integer ������������ ����� � ���� : sign(����) � module(���������� ��������)

int MUL_Z_Z (integer a) // ������� ������
{
	integer b; // ������������� ��������� ����������
	b.module = a.module; // ����������� ���������� ���������� �������� ������� ������������� �����
	//������������� ���������� ��������������� ���� ������� ������������� �����
	if (a.sign == 1)
	{
	b.sign = 0;
	}
	else
	b.sign = 1;
	return b; // ���������� �������� ���������� b
}


#ifndef MUL_Z_Z
#define MUL_Z_Z

#include "../../structs/struct.h"

ordinal MUL_Z_Z(integer a, integer b)
{
b.module = a.module;     // ����������� ���������� ���������� �������� ������� ������������� �����
	if (a.sign == 1) //������������� ���������� ��������������� ���� ������� ������������� �����
	{
	b.sign = 0;
	}
	else
	b.sign = 1;
	return b; // ���������� �������� ���������� b
}
