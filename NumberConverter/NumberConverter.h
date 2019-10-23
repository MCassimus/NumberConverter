// NumberConverter.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <string>
//#include <locale>

const std::string valueTable62 = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";


long long pow(int, int);
long long convertToDec(std::string, unsigned short);
std::string convertFromDec(long long, unsigned short);