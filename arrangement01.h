#pragma once  // 헤더 중복 포함 방지
#include <vector>  // vector를 사용하려면 반드시 포함해야 함

void printHello();
int add(int a, int b);
std::vector<int> ex01(std::vector<int> v);
std::vector<int> ex03_commentary(std::vector<int> numbers);
std::vector<int> ex04(std::vector<int> answers);
std::vector<std::vector<int>> ex05(std::vector<std::vector<int>> arr1, std::vector<std::vector<int>> arr2);
std::vector<int> ex06(int N, std::vector<int> stages);