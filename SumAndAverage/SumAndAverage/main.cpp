#include <iostream>

using namespace std;

int main() {

    /*
    *
    *  ���ڸ� �Է¹ް� �հ� ����� ���ض�.
    *
    */

    string number = "";

    cout << "���ڸ� �Է��ϸ� �հ� ����� �����ݴϴ�!\n" << endl;
    cout << "�����̽��ٸ� ����Ͽ� �������� ���ڸ� ���� �� �ֽ��ϴ�." << endl;
    cout << "�ʹ� ũ�ų� ���� ���� Ȥ�� �Ҽ��� 6�ڸ��� �ʰ��� ���ڴ� �Է��� �ȵ� �� �ֽ��ϴ�." << endl;
    cout << "\n--------------------------------------------------------------------------------\n" << endl;

    while (true) {
        cout << "���ڸ� �Է����ּ���. Q)���� : ";

        cin >> number;

        if (number.compare("Q") == 0 || number.compare("q") == 0) {
            break;
        }

        cout << "\n" << endl;
    }

	return 0;
}