#include <iostream>
#include <cstring>
using namespace std;

int main(void){

    char arr[10];
    cout << "문자 입력";
    cin >> arr;
    cout << "내용 : " << arr << std::endl;
    cout << strlen(arr) << endl;
    cout << arr[0] << endl;

    return 0;
}