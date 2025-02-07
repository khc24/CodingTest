#include <iostream>
#include "stack01.h"  // 헤더 파일 포함
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;



// 문제08 괄호 짝 맞추기**
// 소괄호는 짝을 맞춘 열린 괄호 '('와 닫힌 괄호')'로 구성합니다. 문제에서는 열린 괄호나 닫힌 괄호가 마구 뒤섞인 문자열 s를 줍니다.
// 이때 소괄호가 정상으로 열고 닫혔는지 판별하는 solution() 함수를 구현하세요. 만약 소괄호가 정상적을 열고 닫혔다면 true를, 그렇지
// 않다면 false를 반환하면 됩니다.

// 제약 조건
// 열린 괄호는 자신과 가장 가까운 닫힌 괄호를 만나면 상쇄
// 모든 괄호가 상쇄되어 더 이상 아무 괄호도 없어야만 정상으로 열고 닫혔다고 할 수 있다.
// 더 상쇄할 괄호가 없을 때까지 상쇄를 반복

bool ex08(string s)
{
	stack<char> st;

	for (char c : s)
	{
		if (c == '(')
		{
			st.push('(');
		}
			
		else if (c == ')')
		{
			if (st.empty())
			{
				return false;
			}
			else
			{
				st.pop();
			}

			
		}
	}

	if (st.empty() == false)
	{
		return false;
	}

	return true;

	
}


// 문제 09 10진수를 2진수로 변환하기*
// 10진수 decimal을 입력받아 2진수로 변환해서 문자열 형태로 반환하는 solution() 함수를 구현하라.


string ex09(int decimal)
{
	stack<char> st;

	int temp_value = decimal;
	while (temp_value != 0)
	{
		st.push(to_string(temp_value % 2)[0]);
		temp_value = temp_value / 2;
	}

	string answer;

	while (!st.empty())
	{
		answer.push_back(st.top());
		st.pop();
	}

	return answer;

}

// 해설지 풀이
string ex09_commentay(int decimal) {
	//❶입력 값이  0인 경우 바로 처리
	if (decimal == 0) return "0";

	stack<int> stack;
	while (decimal > 0) {
		//❷ 2로 나눈 나머지를 스택에 삽입
		stack.push(decimal % 2);
		decimal /= 2;
	}

	string binary = "";
	while (!stack.empty()) {
		//❸ 스택에서 차례대로 top()에 해당되는 값을 binary에 추가
		binary += to_string(stack.top());
		stack.pop();
	}
	return binary;
}

// 문제 10 괄호 회전하기*
// 링크: https://school.programmers.co.kr/learn/courses/30/lessons/76502


// 직접 풀이 1차
// 실패: 출력 크기 초과
int ex10(string s)
{
    int answer = 0;

    if (s == "")
    {
        cout << "비어있음" << endl;
        return 0;
    }


    for (int i = 0; i < s.size();i++)
    {
        cout << i << endl;
        bool is_check = true;
        stack<char> st;
        for (int j = s.size() + i - 1; j >= i;j--)
        {
            cout << "i= " << i << " j=" << j << endl;
            if (s[j % s.size()] == '(')
            {
                if (st.empty())
                {
                    is_check = false;
                    break;
                }
                else
                {
                    if (st.top() == ')')
                    {
                        st.pop();
                    }
                    else
                    {
                        is_check = false;
                        break;
                    }
                }
            }
            else if (s[j % s.size()] == '{')
            {
                if (st.empty())
                {
                    is_check = false;
                    break;
                }
                else
                {
                    if (st.top() == '}')
                    {
                        st.pop();
                    }
                    else
                    {
                        is_check = false;
                        break;
                    }
                }
            }
            else if (s[j % s.size()] == '[')
            {
                if (st.empty())
                {
                    is_check = false;
                    break;
                }
                else
                {
                    if (st.top() == ']')
                    {
                        st.pop();
                    }
                    else
                    {
                        is_check = false;
                        break;
                    }
                }
            }
            else
            {
                st.push(s[j % s.size()]);
            }

        }



        if (is_check and st.empty())
        {

            answer += 1;
        }



    }




    return answer;
}


// 직접 풀이 2차 시도
// 성공
unordered_map<char, char> c_map = { {')', '('}, {'}', '{'}, {']', '['} };
bool check_validation(const string& str, int n)
{
    stack<char> st;
    int len = str.size();
    for (int i = 0 + n; i < len + n; i++)
    {
        char value = str[i % len];

        if (value == '(' || value == '{' || value == '[')
        {
            st.push(value);
        }
        else
        {
            if (st.empty() || st.top() != c_map[value])
            {
                return false;
            }
            else
            {
                st.pop();
            }
        }

    }

    return true;
}


int ex_10_2(string s) {
    int answer = 0;
    for (int i = 0; i < s.size(); i++)
    {
        bool is_check = check_validation(s, i);
        if (is_check)
        {
            answer += 1;
        }
    }
    return answer;
}


// 해설지 풀이
// ❶ 닫힌 괄호의 짝을 바로 확인할 수 있도록 맵 선언 
unordered_map<char, char> bracketPair = {
        {')', '('},
        {']', '['},
        {'}', '{'}
};

//❷현자 인자로 받은 문자열 기준 괄호짝이 맞는지 확인
bool isValid(string& s, int start) {
    stack<char> stk;
    unsigned int  sz = s.size();

    //❸ 문자열을 순회하면서
    for (int i = 0; i < sz; i++) {
        char ch = s[(start + i) % sz];
        //❹ ch가 닫힌 괄호 인경우
        if (bracketPair.count(ch)) {
            // ❺ 스택이 비었거나 top 원소가 ch와 짝이 맞는 열린괄호가 아닌 경우 false 반환
            if (stk.empty() || stk.top() != bracketPair[ch]) return false;
            //❻ ch와 짝이 맞는 열린괄호일경우 해당 열린괄호를 제거
            stk.pop();
        }
        else {
            //❼ 열린 괄호일경우 스택이 푸시
            stk.push(ch);
        }
    }
    //❽스택이 비었으면 true를 반환(비었다는것은 괄호 짝이 맞다는 것을 의미)
    return stk.empty();
}

int ex10_commentay(string s) {
    int answer = 0;
    int n = s.size();

    //❾ 문자열을 rotation하면서 괄호짝이 맞으면 answer를 1증가 시킴
    for (int i = 0; i < n; i++) {
        answer += isValid(s, i);
    }
    return answer;
}

// 문제 11 짝지어 제거하기*
// 링크: https://school.programmers.co.kr/learn/courses/30/lessons/12973

// 직접 풀이 1차
// 성공
int ex11(string s)
{
    int s_size = s.size();
    stack<char> st;
    for (int i = 0;i < s_size;i++)
    {
        if (st.empty())
        {
            st.push(s[i]);
        }
        else
        {
            if (s[i] == st.top())
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
    }
    int answer = st.empty();

    return answer;
}

// 해설지 풀이
int ex11_commnetay(string s)
{
    stack<char> st;

    for (int i = 0;i < s.length();i++) {
        //❶스택이 비었거나 현재문자와같은 문자가 아닌 경우 푸시
        if (st.empty() || st.top() != s[i]) st.push(s[i]);
        //❷ 현재문자와 스택의 가장 최근 문자가 같은 경우 팝
        else st.pop();
    }


    //❸ 현재 스택이 비었거나, 문자열의 짝이 맞다는 의미이므로 true반환, 아니면 false 반환
    return st.empty();
}

// 문제 12 주식 가격**
// 링크: https://school.programmers.co.kr/learn/courses/30/lessons/42584

// 직접 풀이 1차
// 성공 시간 복잡도 O(N^2)
vector<int> ex12_01(vector<int> prices) {
    vector<int> answer;
    int prices_size = prices.size();

    for (int i = 0;i < prices_size;i++)
    {
        // stack<int> st;
        int count = 0;

        for (int j = i + 1;j < prices_size;j++)
        {
            // cout << "prices[" << i << "] = " << prices[i] << " prices[" << j << "] = " << prices[j] << endl;
            if (prices[i] <= prices[j])
                count += 1;
            else
            {
                count += 1;
                break;
            }

        }

        answer.push_back(count);
    }

    return answer;
}

// 직접 풀이 2차
// 성공 시간 복잡도 O(N)
void test(stack<int> ss)
{
    while (!ss.empty())
    {
        cout << ss.top() << " ";
        ss.pop();
    }
    cout << endl;
}

vector<int> ex12_02(vector<int> prices) {
    int prices_size = prices.size();
    vector<int> answer(prices_size, 0);
    stack<int> st;
    for (int i = 0;i < prices_size;i++)
    {
        int temp_num = i;
        // cout << "i= " << i << " empty=" << st.empty() << endl;

        while (!st.empty() && (prices[st.top()] > prices[i]))
        {
            // cout << "감소: " << prices[st.top()] << " " << prices[i] << " " << endl;
            answer[st.top()] = i - st.top();
            st.pop();
        }

        st.push(i);
        // test(st);

    }

    while (!st.empty())
    {
        answer[st.top()] = prices_size - 1 - st.top();
        st.pop();
    }
    return answer;
}

// 해설지 풀이
vector<int> ex12_commentay(vector<int> prices) {
    //❶ 가격이 떨어지지 않은 기간을 저장한 벡터    
    vector<int> answer(prices.size());
    // 스택에는 prices의 인덱스가 들어감, 이전 가격과 현재 가격을 비교하기 위한 용도로 사용됨  
    stack<int> s;

    int priceNum = prices.size();

    for (int i = 0;i < priceNum;i++) {
        while (!s.empty() && prices[s.top()] > prices[i]) {
            //❷ 가격이 떨어졌으므로 이전 가격의 기간 계산 
            answer[s.top()] = i - s.top();
            s.pop();
        }
        s.push(i);
    }
    //❸ 스택에 남아있는 가격들은 가격이 떨어지지 않은 경우
    while (!s.empty()) {
        answer[s.top()] = priceNum - s.top() - 1;
        s.pop();
    }
    return answer;
}


// 문제 13 크레인 인형 뽑기 게임**
// 링크: https://school.programmers.co.kr/learn/courses/30/lessons/64061

// 직접풀이
// 성공
int  ex13(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int board_size = board.size();
    vector<stack<int>> board_st(board_size);
    stack<int> st;

    for (int k = board_size - 1;k >= 0; k--)
    {
        for (int l = 0;l < board_size; l++)
        {
            if (board[k][l] != 0)
                board_st[l].push(board[k][l]);
            // cout << "l = " << l << endl;
            // cout << "board[" << k << "][" << l << "] = " << board[k][l] << endl;
        }
    }

    // cout << "전체 확인" << endl;
    // for(int q = 0; q < board_size; q++)
    // {
    //     test(board_st[q]);
    // }

    for (int i = 0; i < moves.size(); i++)
    {
        // cout << "moves[" << i << "] = " << moves[i] << endl;
        if (!board_st[moves[i] - 1].empty())
        {
            if (st.empty())
            {
                // cout << "board_st[moves[i]-1].top() =" << board_st[moves[i]-1].top() << endl;
                st.push(board_st[moves[i] - 1].top());
                board_st[moves[i] - 1].pop();
            }
            else
            {
                // cout << "st.top()=" << st.top()<< " board_st[moves[i]-1].top()" << board_st[moves[i]-1].top() << endl;

                if (st.top() == board_st[moves[i] - 1].top())
                {
                    st.pop();
                    board_st[moves[i] - 1].pop();
                    answer += 2;
                    // cout << "점수!!" << endl;
                }
                else
                {
                    st.push(board_st[moves[i] - 1].top());
                    board_st[moves[i] - 1].pop();
                }
            }

        }

        //         test(st);
        //         cout << "전체 확인" << endl;
        //         for(int q = 0; q < board_size; q++)
        //         {
        //             test(board_st[q]);
        //         }
        //         cout << "-----------------------------" << endl;
    }

    return answer;
}

// 해설지 풀이
// stack<int> lanes[board[0].size()]; 런타임 값이므로 배열 크기로 사용할 수 없음.

//int ex13_commentay(vector<vector<int>> board, vector<int> moves) {
//    //❶ 보드판의 열의 크기만큼 스택을 생성 
//    stack<int> lanes[board[0].size()];
//    //❷ 보드의 가장 밑의 행부터 위로 올라가먼서 순회 
//    for (int i = board.size() - 1; i >= 0; --i) {
//        for (int j = 0; j < board[0].size(); ++j) {
//            //❸ 블럭이 있는 경우 해당 열에 해당되는 스택에 푸시 
//            if (board[i][j]) {
//                lanes[j].push(board[i][j]);
//            }
//        }
//    }
//
//    // 보드판에서 꺼낸 인형을 담을 bucket과 사라진 인형의 개수를 저장할 answer 선언
//    stack<int> bucket;
//    int answer = 0;
//
//    for (int m : moves) {
//        //❹ 해당 lane에 블럭이 있으면
//        if (lanes[m - 1].size()) {
//            int doll = lanes[m - 1].top();
//            lanes[m - 1].pop();
//            //❺ 버킷에 블럭이 있고, 가장 최근에 들어간 블럭과 현재 블럭이 같은지 확인
//            if (bucket.size() && bucket.top() == doll) {
//                bucket.pop();
//                answer += 2;
//            }
//            else {
//                bucket.push(doll);
//            }
//        }
//    }
//
//    return answer;
//}


// 문제 14 표 편집*****
// 링크: 

// 직접 풀이 1차
string ex14_01(int n, int k, vector<string> cmd) {

    vector<char> v(n, 'O');
    int cmd_size = cmd.size();
    stack<int> c_stack;

    for (int i = 0; i < cmd_size; i++)
    {
        switch (cmd[i][0])
        {
        case 'U':
        {
            string copy_str = cmd[i];
            copy_str.erase(copy_str.begin(), copy_str.begin() + 2);
            k -= stoi(copy_str);

        }break;
        case 'D':
        {

            string copy_str = cmd[i];
            copy_str.erase(copy_str.begin(), copy_str.begin() + 2);
            k += stoi(copy_str);

        }break;
        case 'C':
        {
            int temp_cnt = -1;
            for (int i = 0;i < n;i++)
            {
                if (v[i] == 'O')
                {
                    temp_cnt += 1;
                }

                if (temp_cnt == k)
                {
                    v[i] = 'X';
                    c_stack.push(i);


                }
            }
            if (temp_cnt == k)
            {
                k -= 1;
            }
        }break;
        case 'Z':
        {

            int temp_cnt = -1;
            for (int i = 0;i < n;i++)
            {
                if (v[i] == 'O')
                {
                    temp_cnt += 1;
                }
                if (temp_cnt == k)
                {
                    if (i > c_stack.top())
                    {
                        k += 1;
                        break;
                    }
                }

            }
            v[c_stack.top()] = 'O';
            c_stack.pop();

        }break;
        }

    }
    string answer = "";
    for (char c : v)
    {
        answer.push_back(c);
    }
    return answer;
}

// 직접 풀이 2차
// 성공
string ex14_02(int n, int k, vector<string> cmd) {
    // vector<int> all_size(n+2, 1);
    string answer(n, 'O');

    stack<int> delete_st;

    vector<int> left;
    vector<int> right;

    for (int j = 0; j < n; j++)
    {
        left.push_back(j - 1);
        right.push_back(j + 1);
    }





    for (int i = 0; i < cmd.size();i++)
    {
        switch (cmd[i][0]) {
        case 'U':
        {
            int count = stoi(cmd[i].substr(2));
            for (int w = 0;w < count;w++)
            {
                k = left[k];
            }

        }break;
        case 'D':
        {
            int count = stoi(cmd[i].substr(2));
            for (int w = 0;w < count;w++)
            {
                k = right[k];
            }

        }break;
        case 'C':
        {
            delete_st.push(k);
            answer[k] = 'X';
            if (left[k] != -1)
                right[left[k]] = right[k];
            if (right[k] != n)
                left[right[k]] = left[k];

            if (right[k] >= n)
            {
                k = left[k];

            }
            else
            {
                k = right[k];
            }



        }break;
        case 'Z':
        {
            int temp_num = delete_st.top();
            answer[temp_num] = 'O';
            right[left[temp_num]] = temp_num;
            left[right[temp_num]] = temp_num;

            delete_st.pop();


        }break;
        }
    }
    // string answer = answer;



    return answer;
}

// 해설지 풀이
string ex14_commentay(int n, int k, vector<string> cmd) {

    //❶삭제 된 행의 인덱스를 저장 
    stack<int> deleted;
    //❷ 각 행의 위아래에 있는 행의 인덱스를 저장 
    vector<int> up;
    vector<int> down;

    for (int i = 0; i < n + 2; i++) {
        up.push_back(i - 1);
        down.push_back(i + 1);
    }
    //❸ 임시공간을 고려한 현재위치 
    k++;

    //❹ 주어진 명령어를 순회  
    for (int i = 0; i < cmd.size(); i++) {
        //❺ 현재 위치를 삭제하고 그 다음 위치로 이동
        if (cmd[i][0] == 'C') {
            deleted.push(k);
            down[up[k]] = down[k];
            up[down[k]] = up[k];

            if (down[k] == n + 1) k = up[k];
            else k = down[k];
        }

        //❻ 가장 최근에 삭제한 행을 복원
        else if (cmd[i][0] == 'Z') {
            int r = deleted.top();
            down[up[r]] = r;
            up[down[r]] = r;
            deleted.pop();
        }

        //❼  현재 행을 주어진 값 만큼 위혹은 아래로 이동
        else {
            int sz = stoi(cmd[i].substr(2));

            if (cmd[i][0] == 'U') {
                for (int j = 0; j < sz; j++) {
                    k = up[k];
                }
            }

            else if (cmd[i][0] == 'D') {
                for (int j = 0; j < sz; j++) {
                    k = down[k];
                }
            }
        }

    }

    string answer;

    //❽ 삭제된 행의 위치에 “X”, 그렇지 않은 행의 위치에 “X” 로 표시한 문자열 반환
    answer.append(n, 'O');
    while (!deleted.empty()) {
        answer[deleted.top() - 1] = 'X';
        deleted.pop();
    }

    return answer;
}