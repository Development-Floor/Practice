#include <iostream>
#include <string>

using namespace std;

// ����
double Sum(double* number_array, int size) {
    double sum = 0;

    for (int i = 0; i < size; i++) {
        sum += number_array[i];
    }

    return sum;
}

// ���
double Avg(double* number_array, int size) {
    return Sum(number_array, size) / size;
}

// ����
// isdesc == 1: ��������, isdesc == 2: ��������, �� ��: ����ó��
void MySort(double* number_array, int size, int isdesc) {
    if (size <= 1 || isdesc != 1 && isdesc != 2) {
        return;
    }
    
    int max_index = 0;
    int min_index = 0;

    double change = 0;

    for (int i = 0; i < size / 2; i++) {
        max_index = i;
        min_index = i;

        // ���� �ݺ��� �ִ밪 �ּҰ� ���ϱ�
        for (int j = i + 1; j < size - i; j++) {
            if (number_array[j] > number_array[max_index]) {
                max_index = j;
            }

            if (number_array[j] < number_array[min_index]) {
                min_index = j;
            }
        }

        // ��������
        if (isdesc == 1) {
            change = number_array[i];
            number_array[i] = number_array[min_index];
            number_array[min_index] = change;

            // �ּҰ��� �ٲٰ� �ִ밪�� �ٲٱ� ����
            if (max_index == i) {
                max_index = min_index;
            }

            change = number_array[size - i - 1];
            number_array[size - i - 1] = number_array[max_index];
            number_array[max_index] = change;
        }
        
        // ��������
        else if (isdesc == 2) {
            change = number_array[size - i - 1];
            number_array[size - i - 1] = number_array[min_index];
            number_array[min_index] = change;

            // �ּҰ��� �ٲٰ� �ִ밪�� �ٲٱ� ����
            if (max_index == size - i - 1) {
                max_index = min_index;
            }

            change = number_array[i];
            number_array[i] = number_array[max_index];
            number_array[max_index] = change;
        }
    }
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

    cout << "����: " << Sum(number_array, count) << endl;
    cout << "���: " << Avg(number_array, count) << endl;

    /*
    * 
    * ���� ���
    * 
    */

    int check_desc = 1;

    cout << "\n-------------\n" << endl;

    for (int i = 0; i < count; i++) {
        cout << number_array[i] << " ";
    }

    cout << "\n" << endl;

    // �����Է½� ���ѷ���(����� �߸�...)
    while (true) {
        cout << "���ڵ��� �����ϼ���!" << endl;
        cout << "1) �������� 2) �������� : ";

        cin >> check_desc;

        if (check_desc == 1 || check_desc == 2) {
            break;
        }

        cout << "������ ���� 1 or 2�� ���ڸ� �Է����ּ���.\n" << endl;
    }

    // �����Լ� ���
    MySort(number_array, count, check_desc);

    cout << endl;

    for (int i = 0; i < count; i++) {
        cout << number_array[i] << " ";
    }

    cout << "\n" << endl;

    delete[] number_array;

	return 0;
}