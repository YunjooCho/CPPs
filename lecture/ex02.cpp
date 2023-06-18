/* 구매금액의 1% 산출하기(포인트 적립) */

#include <iostream>

using namespace std;

int main(void)
{
    char info[30];
    cout << "성함과 전화번호 입력하세요" << endl;
    cin.getline(info, sizeof(info));
    cout << "구매금액을 입력하세요" << endl;
    int caltot, calpoint;
    cin >> caltot;
    calpoint = caltot * 0.01;
    cout << info << " 님 금회 발생 포인트 : " << calpoint << " 점 입니다." << endl;
    return (0);
}