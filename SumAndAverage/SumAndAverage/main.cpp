#include <iostream>
#include <string>

using namespace std;

// 총합
double Sum(double* number_array, int size) {
    double sum = 0;

    for (int i = 0; i < size; i++) {
        sum += number_array[i];
    }

    return sum;
}

// 평균
double Avg(double* number_array, int size) {
    return Sum(number_array, size) / size;
}

// 정렬
// isdesc == 1: 오름차순, isdesc == 2: 내림차순, 그 외: 예외처리
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

        // 현재 반복의 최대값 최소값 구하기
        for (int j = i + 1; j < size - i; j++) {
            if (number_array[j] > number_array[max_index]) {
                max_index = j;
            }

            if (number_array[j] < number_array[min_index]) {
                min_index = j;
            }
        }

        // 오름차순
        if (isdesc == 1) {
            change = number_array[i];
            number_array[i] = number_array[min_index];
            number_array[min_index] = change;

            // 최소값을 바꾸고 최대값을 바꾸기 때문
            if (max_index == i) {
                max_index = min_index;
            }

            change = number_array[size - i - 1];
            number_array[size - i - 1] = number_array[max_index];
            number_array[max_index] = change;
        }
        
        // 내림차순
        else if (isdesc == 2) {
            change = number_array[size - i - 1];
            number_array[size - i - 1] = number_array[min_index];
            number_array[min_index] = change;

            // 최소값을 바꾸고 최대값을 바꾸기 때문
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
    *  필수. 숫자를 입력받고 합과 평균을 구해라.
    *
    *  도전. 정렬구현
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

    cout << "총합: " << Sum(number_array, count) << endl;
    cout << "평균: " << Avg(number_array, count) << endl;

    /*
    * 
    * 정렬 사용
    * 
    */

    int check_desc = 1;

    cout << "\n-------------\n" << endl;

    for (int i = 0; i < count; i++) {
        cout << number_array[i] << " ";
    }

    cout << "\n" << endl;

    // 문자입력시 무한루프(사용자 잘못...)
    while (true) {
        cout << "숫자들을 정렬하세요!" << endl;
        cout << "1) 오름차순 2) 내림차순 : ";

        cin >> check_desc;

        if (check_desc == 1 || check_desc == 2) {
            break;
        }

        cout << "정렬을 위해 1 or 2의 숫자만 입력해주세요.\n" << endl;
    }

    // 정렬함수 사용
    MySort(number_array, count, check_desc);

    cout << endl;

    for (int i = 0; i < count; i++) {
        cout << number_array[i] << " ";
    }

    cout << "\n" << endl;

    delete[] number_array;

	return 0;
}