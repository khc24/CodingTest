#include <iostream>
#include "arrangement01.h"  // 헤더 파일 포함
#include <algorithm>
#include <vector>
#include <set>
#include <map>
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
// 링크: https://school.programmers.co.kr/learn/courses/30/lessons/42840?language=cpp
// 수포자는 수학을 포기한 사람의 준말입니다. 수포자 삼인방은 모의고사에 수학 문제를
// 전부 찍으려 합니다. 수포자는 1번 문제부터 마지막 문제까지 다음과 같이 찍습니다.
// 1번 수포자가 찍는 방식: 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, ...
// 2번 수포자가 찍는 방식: 2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5, ...
// 3번 수포자가 찍는 방식 : 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, ...
// 1번 문제부터 마지막 문제까지의 정답이 순서대로 들은 배열 answers가 주어졌을 때, 
// 가장 많은 문제를 맞힌 사람이 누구인지 배열에 담아 return 하도록 solution 함수를 작성해주세요.

// 01.시험은 최대 10,000 문제로 구성되어있습니다.
// 02.문제의 정답은 1, 2, 3, 4, 5중 하나입니다.
// 03.가장 높은 점수를 받은 사람이 여럿일 경우, return하는 값을 오름차순 정렬해주세요.

// 직접 풀이
vector<int> ex04(vector<int> answers) {
    vector<vector<int>> student(3);
    student[0] = { 1, 2, 3, 4, 5 };
    student[1] = { 2, 1, 2, 3, 2, 4, 2, 5 };
    student[2] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

    vector<int> count(3, 0);

    for (int i = 0; i < answers.size(); i++)
    {
        if (student[0][i % 5] == answers[i])
        {
            count[0] += 1;
        }
        if (student[1][i % 8] == answers[i])
        {
            count[1] += 1;
        }
        if (student[2][i % 10] == answers[i])
        {
            count[2] += 1;
        }
    }

    int max_count = *max_element(count.begin(), count.end());
    vector<int> answer;

    for (int j = 0; j < count.size(); j++)
    {
        if (count[j] == max_count)
            answer.push_back(j + 1);


    }


    return answer;
}

// 해설지 풀이

// ❶ 각 수포자가 찍는 패턴을 정의
vector<int> firstPattern = { 1,2,3,4,5 };
vector<int> secondPattern = { 2,1,2,3,2,4,2,5 };
vector<int> thirdPattern = { 3,3,1,1,2,2,4,4,5,5 };

vector<int> ex04_commentary(vector<int> answers) {
    // ❷ 최종적으로 가장 많이 문제를 맞힌 사람이 저장될 벡터
    vector<int> answer;

    // ❸ 각 수포자들의 패턴대로 답안을 작성할때 문제를 맞힌 갯수가 저장될 벡터
    vector<int> matchCnt(3);

    // ❹ 실제 정답과 각 수포자들의 패턴을 비교해서 맞춘 갯수
    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == firstPattern[i % firstPattern.size()]) matchCnt[0]++;
        if (answers[i] == secondPattern[i % secondPattern.size()]) matchCnt[1]++;
        if (answers[i] == thirdPattern[i % thirdPattern.size()]) matchCnt[2]++;
    }
    // ❺ 가장 많이 맞춘 수포자가 얻은 점수
    int max_score = *max_element(matchCnt.begin(), matchCnt.end());

    // ❻ 가장 많이 맞춘 수포자의 번호를 저장
    for (int i = 0; i < 3; i++) {
        if (matchCnt[i] == max_score) answer.push_back(i + 1);
    }

    return answer;
}


// 문제 05 행렬의 곱셈*
// 링크: https://school.programmers.co.kr/learn/courses/30/lessons/12949?language=cpp
// 2차원 행렬 arr1과 arr2를 입력받아, arr1에 arr2를 곱한 결과를 반환하는 함수, solution을 완성해주세요.
// 제한 조건
// 01.행렬 arr1, arr2의 행과 열의 길이는 2 이상 100 이하입니다.
// 02.행렬 arr1, arr2의 원소는 - 10 이상 20 이하인 자연수입니다.
// 03.곱할 수 있는 배열만 주어집니다.

// 직접 풀이
vector<vector<int>> ex05(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
    pair<int, int> arr1_point(arr1.size(), arr1[0].size());
    pair<int, int> arr2_point(arr2.size(), arr2[0].size());

    vector<vector<int>> answer;
    answer.assign(arr1_point.first, vector<int>(arr2_point.second, 0));
    

    for (int i = 0; i < arr1_point.first; i++)
    {
        for (int j = 0; j < arr1_point.second; j++)
        {
            for (int k = 0; k < arr2_point.second;k++)
            {
                answer[i][k] += arr1[i][j] * arr2[j][k];
            }
            
        }
    }

    return answer;
}


// 해설지 풀이
vector<vector<int> > ex05_commentary(vector<vector<int> >arr1, vector<vector<int> >arr2)
{
    // ❶ 최종 행렬곱의 결과를 저장할 벡터 선언
    vector<vector<int> >answer;

    // ❷ arr1과 arr2의 행렬곱을 수행했을때 최종적인 행렬의 크기만큼 공간을 할당
    answer.assign(arr1.size(), vector<int>(arr2[1].size(), 0));

    // ❸ arr1의 각 행과 arr2의 각 열에 대해 반복문 수행
    for (int i = 0;i < arr1.size(); i++)
        for (int j = 0;j < arr2[1].size(); j++)
            for (int k = 0;k < arr2.size(); k++)
                // ❹ 두 행렬을 곱을 수행 
                answer[i][j] += arr1[i][k] * arr2[k][j];

    return answer;
}


// 문제 06 실패율**
// 링크: https://school.programmers.co.kr/learn/courses/30/lessons/42889?language=cpp

// 스테이지에 머물고 있는 인원 파악
// 전체 인원 파악

bool compare_ex06(const pair<int, float>& a, const pair<int, float>& b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }
    return a.second > b.second;
}

vector<int> ex06(int N, vector<int> stages) {
    int all_gamer = stages.size();
    map<int, int> stay_gamer;
    map<int, float> fail_rate;
    for (int i = 0; i < all_gamer;i++)
    {
        stay_gamer[stages[i]]++;

    }

    for (int j = 1; j <= N; j++)
    {


        if (stay_gamer.count(j))
        {
            if (all_gamer != 0)
            {
                fail_rate[j] = float(stay_gamer[j]) / all_gamer;
                all_gamer -= stay_gamer[j];

            }
            else
            {
                fail_rate[j] = 0;

            }

        }
        else
        {
            fail_rate[j] = 0;

        }
    }
    vector<int> answer;
    vector<pair<int, float>> vec(fail_rate.begin(), fail_rate.end());
    sort(vec.begin(), vec.end(), compare_ex06);
    for (const pair<int, float>& p : vec)
    {
        answer.push_back(p.first);
    }

    return answer;
}


// 해설지 풀이
// ❶ 문제에서 요구하는 조건대로 실패율을 정렬하는 함수 
bool compare_ex06_commentay(pair<int, float>& a, pair<int, float>& b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {

    vector<int> answer; // ❷ answer는 최종 답 
    vector<float> challenger(N + 2, 0.0);  // ❸ challenger는 각 스테이지에 도달한 적이 있는 도전자의 수  
    vector<float> fail(N + 2, 0.0); // ❹ fail는 특정 스테이지에 실패한 도전자의 수

    // ❺ 각 스테이지의 인원을 기준으로 특정 스테이지에서 실패한 인원수와, 각 스테이지에 도전한 적이 있는 인원수를 구함 
    for (int i = 0; i < stages.size(); i++) {
        for (int j = 1; j <= stages[i]; j++)
            challenger[j]++;

        fail[stages[i]]++;
    }
    // ❻ failRatio는 실패율을 저장, first는 stage정보이고 second는 실패율 
    vector<pair<int, float>> failRatio(N);

    // ❼ 스테이지 정보 및 실패율을 저장  
    for (int i = 0; i < N; i++) {
        failRatio[i].first = i + 1;

        if (challenger[i + 1] == 0)
            failRatio[i].second = 0;
        else
            failRatio[i].second = fail[i + 1] / challenger[i + 1];
    }

    // ➑ 계산한 실패율을 문제에서 제시한 조건에 맞게 정렬
    sort(failRatio.begin(), failRatio.end(), compare_ex06_commentay);

    // ❾ 최종 답을 반환하기 위해 실패율을 저장
    for (int i = 0; i < N; i++) {
        answer.push_back(failRatio[i].first);
    }

    return answer;
}




    

// 문제 07 방문 길이**
// 링크: https://school.programmers.co.kr/learn/courses/30/lessons/49994?language=cpp

//직접 풀이
int ex07(string dirs) {
    int answer = 0;

    pair<int, int> pos = { 0 ,0 };
    set<vector<int>> road_info;

    for (char dir : dirs)
    {
        if (dir == 'U' and pos.second < 5)
        {

            road_info.insert(vector<int>{pos.first, pos.second + 1, pos.first, pos.second});
            pos.second += 1;
        }
        else if (dir == 'D' and pos.second > -5)
        {
            road_info.insert(vector<int>{pos.first, pos.second, pos.first, pos.second - 1});
            pos.second -= 1;
        }
        else if (dir == 'R' and pos.first < 5)
        {
            road_info.insert(vector<int>{pos.first + 1, pos.second, pos.first, pos.second});
            pos.first += 1;
        }
        else if (dir == 'L' and pos.first > -5)
        {
            road_info.insert(vector<int>{pos.first, pos.second, pos.first - 1, pos.second});
            pos.first -= 1;
        }


    }

    answer = road_info.size();

    return answer;
}


// 해설지 풀이
bool visited[11][11][4]; // ❶ 특정 좌표에서 특정 방향으로 이동한 적이 있는지 체크하는 배열

// ❷ 상하좌우로 좌표를 이동할 때 필요한 좌표의 오프셋 배열 
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

// ❸ 각 문자에 해당하는 오프셋 배열의 인덱스를 반환
int todir(char dir) {
    int ret;
    if (dir == 'U') ret = 0;
    else if (dir == 'R') ret = 1;
    else if (dir == 'D') ret = 2;
    else ret = 3;
    return ret;
}

// ❹ 특정좌표가 주어진 좌표평면을 벗어나는지 확인
bool isNotValid(int x, int y)
{
    return x < 0 || y < 0 || x > 10 || y > 10;
}
// ❺ 현재와 반대 방향의 오프셋 배열 인덱스 반환
int opposite_direction(int dir)
{
    return (dir + 2) % 4;
}

int ex07_commentry(string dirs)
{
    int answer = 0;
    int x = 5, y = 5; // ❻ 시작 좌표를 설정

    for (auto c : dirs) {
        // ❼ 반복문을 순회하며 nx, ny는  x, y가 dirs대로 움직였을 때 위치가 됨 
        int dir = todir(c);
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        // ❽ 좌표평면을 벗어난 경우 더 이상 이동하지 않음
        if (isNotValid(nx, ny)) {
            continue;
        }

        // ❾  다음 좌표가 아직 방문하지 않은 좌표인 경우
        if (visited[y][x][dir] == false) {
            // ❿ 방문이 중복 체크되지 않도록 해당 경로의 양방향을 방문 체크
            visited[y][x][dir] = true;
            visited[ny][nx][opposite_direction(dir)] = true;
            answer++;
        }
        // ⓫ 현재좌표를 이동한 좌표로 업데이트
        x = nx;
        y = ny;
    }
    return answer;
}

 