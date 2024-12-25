#include <iostream>
#include <string>

using namespace std;

double Sum(double* double_array, int size) {
    double sum = 0;

    for (int i = 0; i < size; i++) {
        sum += double_array[i];
    }

    return sum;
}

int main() {

    /*
    *
    *  숫자를 입력받고 합과 평균을 구해라.
    *
    */

    string numbers = "";

    string number = "";

    int count = 0;

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

        if (number.compare("Q") == 0 || number.compare("q") == 0) {
            break;
        }

        try {
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

    double* number_array = new double[count];

    int index = 0;

    for (int i = 0; i < count; i++) {
        index = numbers.find(" ");

        number_array[i] = stod(numbers.substr(0, index));

        numbers = numbers.substr(index + 1);
    }

    delete[] number_array;

	return 0;
}