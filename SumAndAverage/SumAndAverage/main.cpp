#include <iostream>
#include <string>

using namespace std;

// ����
double Sum(double* double_array, int size) {
    double sum = 0;

    for (int i = 0; i < size; i++) {
        sum += double_array[i];
    }

    return sum;
}

// ���
double Avg(double* double_array, int size) {
    return Sum(double_array, size) / size;
}

// ����
// isdesc == 1: ��������, isdesc == 2: ��������, �� ��: ����ó��
void MySort(double* double_array, int size, int isdesc) {

}

int main() {

    /*
    *
    *  �ʼ�. ���ڸ� �Է¹ް� �հ� ����� ���ض�.
    *
    *  ����. ���ı���
    * 
    */

    string numbers = "";

    string number = "";

    int count = 0; // ������ ����

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

        // Q �Է� �� ����.
        if (number.compare("Q") == 0 || number.compare("q") == 0) {
            break;
        }

        try { // ���� ���� ���ڰ� �ƴϰų� "11."�̷� ������ ������ ����ó��.
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

    // ���� ������ ������ŭ �迭ũ�� �Ҵ�.
    double* number_array = new double[count];

    int index = 0;

    // ���ڿ��� ����ִ� ���ڵ��� �Ľ��ؼ� double �迭�� ���.
    for (int i = 0; i < count; i++) {
        index = numbers.find(" ");

        number_array[i] = stod(numbers.substr(0, index));

        numbers = numbers.substr(index + 1);
    }

    cout << "\n --- ���� ---" << endl;

    cout << fixed;
    cout << "����: " << Sum(number_array, count) << endl;
    cout << "���: " << Avg(number_array, count) << endl;

    delete[] number_array;

	return 0;
}