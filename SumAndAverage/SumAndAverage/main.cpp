#include <iostream>

using namespace std;

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

        count++;

        numbers = numbers + number + " ";

        cout << "\n" << endl;
    }

	return 0;
}