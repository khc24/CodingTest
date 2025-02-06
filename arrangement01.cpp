#include <iostream>
#include "arrangement01.h"  // 헤더 파일 포함
#include <algorithm>
#include <vector>
#include <set>
using namespace std;


// 문제01 배열 정렬하기*
// 정수 배열 arr을 오름차순으로 정렬해서 반환하는 solution() 함수를 완성하세요.
vector<int> ex_01(vector<int> arr)
{
    sort(arr.begin(), arr.end());
    return arr;
}

// 문제02 배열 제어하기**
// 정수 배열 lst가 주어집니다. 배열의 중복값을 제거하고 배열 데이터를 내림차순으로 
// 정렬해서 반환하는 solution() 함수를 구현하세요.
bool compare(int a, int b) {
    return a > b;
}

vector<int> ex_02(vector<int> lst)
{
    sort(lst.begin(), lst.end(), compare);
    lst.erase(unique(lst.begin(), lst.end()), lst.end());

    return lst;
}


// 문제 03 두 수를 뽑아서 더하기*
// 링크: https://school.programmers.co.kr/learn/courses/30/lessons/68644?language=cpp
// 정수 배열 numbers가 주어집니다. numbers에서 서로 다른 인덱스에 있는 두 개의
// 수를 뽑아 더해서 만들 수 있는 모든 수를 배열에 오름차순으로 담아 return 하도록
// solution 함수를 완성해주세요.

// 제한사항
// 01. numbers의 길이는 2이상 100이하
// 02. numbers의 모든 수는 0 이상 100 이하

// 직접 풀이
vector<int> ex03(vector<int> numbers)
{
    vector<int> answer;

    for (int i = 0;i < numbers.size() - 1; i++)
        for (int j = i + 1;j < numbers.size(); j++)
        {
            answer.push_back(numbers[i] + numbers[j]);
        }



    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());

    return answer;
}

// 해설지 풀이
vector<int> ex03_commentary(vector<int> numbers)
{
    set<int> sum; //  두 수의 합을 저장할 저장공간 선언

    for (int i = 0;i < numbers.size();++i)  //  반복문을 수행하면서 두 수의 합을 저장
        for (int j = i + 1; j < numbers.size();++j)
            sum.insert(numbers[i] + numbers[j]);

    vector<int> answer(sum.begin(), sum.end()); //  반환타입을 맞추기 위헤 벡터로 변환
    return answer;
}

// 문제 04 모의고사*


