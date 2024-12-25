#include <iostream>
#include <string>

using namespace std;

// 총합
double Sum(double* double_array, int size) {
    double sum = 0;

    for (int i = 0; i < size; i++) {
        sum += double_array[i];
    }

    return sum;
}

// 평균
double Avg(double* double_array, int size) {
    return Sum(double_array, size) / size;
}

int main() {

    /*
    *
    *  숫자를 입력받고 합과 평균을 구해라.
    *
    */

    string numbers = "";

    string number = "";

    int count = 0; // 숫자의 갯수

    cout << "숫자를 입력하면 합과 평균을 구해줍니다!\n" << endl;
    cout << "스페이스바를 사용하여 여러개의 숫자를 넣을 수 있습니다." << endl;
    cout << "너무 크거나 작은 숫자 혹은 소숫점 6자리를 초과한 숫자는 입력이 안될 수 있습니다." << endl;
    cout << "\n--------------------------------------------------------------------------------\n" << endl;

    while (true) {
        if (numbers.size() > 0) {
            cout << "입력된 숫자 : " << numbers << endl;
        }

        cout << "숫자를 입력해주세요. Q)종료 : ";

        cin >> number;

        // Q 입력 시 종료.
        if (number.compare("Q") == 0 || number.compare("q") == 0) {
            break;
        }

        try { // 들어온 값이 숫자가 아니거나 "11."이런 식으로 들어오면 예외처리.
            if (number.back() == '.' || number.compare((to_string(stod(number)).substr(0, number.size())))) {
                throw number;
            };

            count++;

            numbers = numbers + number + " ";
        }
        catch (...) {
            cout << " " << number << " 는 입력이 불가능합니다." << endl;
        }

        cout << "\n" << endl;
    }

    if (count == 0) {
        cout << "\n입력된 값이 없습니다." << endl;
        return 0;
    }

    // 들어온 숫자의 갯수만큼 배열크기 할당.
    double* number_array = new double[count];

    int index = 0;

    // 문자열에 들어있는 숫자들을 파싱해서 double 배열에 담기.
    for (int i = 0; i < count; i++) {
        index = numbers.find(" ");

        number_array[i] = stod(numbers.substr(0, index));

        numbers = numbers.substr(index + 1);
    }

    cout << "\n --- 종료 ---" << endl;

    cout << fixed;
    cout << "총합: " << Sum(number_array, count) << endl;
    cout << "평균: " << Avg(number_array, count) << endl;

    delete[] number_array;

	return 0;
}