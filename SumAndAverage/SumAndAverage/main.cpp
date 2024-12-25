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
    *  ���ڸ� �Է¹ް� �հ� ����� ���ض�.
    *
    */

    string numbers = "";

    string number = "";

    int count = 0;

    cout << "���ڸ� �Է��ϸ� �հ� ����� �����ݴϴ�!\n" << endl;
    cout << "�����̽��ٸ� ����Ͽ� �������� ���ڸ� ���� �� �ֽ��ϴ�." << endl;
    cout << "�ʹ� ũ�ų� ���� ���� Ȥ�� �Ҽ��� 6�ڸ��� �ʰ��� ���ڴ� �Է��� �ȵ� �� �ֽ��ϴ�." << endl;
    cout << "\n--------------------------------------------------------------------------------\n" << endl;

    while (true) {
        if (numbers.size() > 0) {
            cout << "�Էµ� ���� : " << numbers << endl;
        }

        cout << "���ڸ� �Է����ּ���. Q)���� : ";

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
            cout << " " << number << " �� �Է��� �Ұ����մϴ�." << endl;
        }

        cout << "\n" << endl;
    }

    if (count == 0) {
        cout << "\n�Էµ� ���� �����ϴ�." << endl;
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