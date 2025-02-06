#include <iostream>
#include "arrangement01.h"  // ��� ���� ����
#include <algorithm>
#include <vector>
#include <set>
using namespace std;


// ����01 �迭 �����ϱ�*
// ���� �迭 arr�� ������������ �����ؼ� ��ȯ�ϴ� solution() �Լ��� �ϼ��ϼ���.
vector<int> ex_01(vector<int> arr)
{
    sort(arr.begin(), arr.end());
    return arr;
}

// ����02 �迭 �����ϱ�**
// ���� �迭 lst�� �־����ϴ�. �迭�� �ߺ����� �����ϰ� �迭 �����͸� ������������ 
// �����ؼ� ��ȯ�ϴ� solution() �Լ��� �����ϼ���.
bool compare(int a, int b) {
    return a > b;
}

vector<int> ex_02(vector<int> lst)
{
    sort(lst.begin(), lst.end(), compare);
    lst.erase(unique(lst.begin(), lst.end()), lst.end());

    return lst;
}


// ���� 03 �� ���� �̾Ƽ� ���ϱ�*
// ��ũ: https://school.programmers.co.kr/learn/courses/30/lessons/68644?language=cpp
// ���� �迭 numbers�� �־����ϴ�. numbers���� ���� �ٸ� �ε����� �ִ� �� ����
// ���� �̾� ���ؼ� ���� �� �ִ� ��� ���� �迭�� ������������ ��� return �ϵ���
// solution �Լ��� �ϼ����ּ���.

// ���ѻ���
// 01. numbers�� ���̴� 2�̻� 100����
// 02. numbers�� ��� ���� 0 �̻� 100 ����

// ���� Ǯ��
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

// �ؼ��� Ǯ��
vector<int> ex03_commentary(vector<int> numbers)
{
    set<int> sum; //  �� ���� ���� ������ ������� ����

    for (int i = 0;i < numbers.size();++i)  //  �ݺ����� �����ϸ鼭 �� ���� ���� ����
        for (int j = i + 1; j < numbers.size();++j)
            sum.insert(numbers[i] + numbers[j]);

    vector<int> answer(sum.begin(), sum.end()); //  ��ȯŸ���� ���߱� ���� ���ͷ� ��ȯ
    return answer;
}

// ���� 04 ���ǰ��*


