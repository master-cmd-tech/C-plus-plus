#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

// Task 1
int min4(int a, int b, int c, int d) {
    return min({a,b,c,d});
}

// Task 2
double power2(double a, int n) {
    double result = pow(a, n);
    return result;
}

// Task 3
bool myXor2(bool x, bool y) {
    return (x || y) && !(x && y);
}

// Task 4
bool election(bool x, bool y, bool z) {
    return (x && y) || (y && z) || (x && z);
}

// Task 5
char getSign(int a, int b) {
    if (a < b) return '<';
    else if (a > b) return '>';
    else return '=';
}

// Task 6 
void comparePositiveArrays() {
    int N;
    cin >> N;

    int array1[100], array2[100];
    int count1 = 0, count2 = 0;

    for (int i = 0; i < N; i++) {
        cin >> array1[i];
        if (array1[i] > 0) count1++;
    }
    for (int i = 0; i < N; i++) {
        cin >> array2[i];
        if (array2[i] > 0) count2++;
    }

    if (count1 > count2)
        cout << "Number of positives in the first array is greater";
    else if (count1 < count2)
        cout << "Number of positives in the second array is greater";
    else
        cout << "Numbers are equal";
}

// Task 7 
void longestSeries() {
    int N, M;
    cin >> N >> M;

    int matrix[100][100];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matrix[i][j];
        }
    }

    int maxLength = 1;
    int bestRow = -1;

    for (int i = 0; i < N; i++) {
        int currentLength = 1;
        int rowMax = 1;
        for (int j = 1; j < M; j++) {
            if (matrix[i][j] == matrix[i][j - 1]) {
                currentLength++;
                rowMax = max(rowMax, currentLength);
            } else {
                currentLength = 1;
            }
        }
        if (rowMax > maxLength) {
            maxLength = rowMax;
            bestRow = i + 1; // +1 потому что строки считаются с 1
        }
    }

    if (maxLength > 1)
        cout << "Longest series is in the string " << bestRow;
    else
        cout << "No series of equal elements";
}

// Task 8
int countAccurance(char arr[], char ch) {
    int count = 0;
    for (int i = 0; arr[i] != '\0'; i++) {
        if (arr[i] == ch)
            count++;
    }
    return count;
}

void task8() {
    char ch1, ch2;
    cin >> ch1 >> ch2;
    char str1[21], str2[21];
    cin >> str1 >> str2;

    cout << countAccurance(str1, ch1) << " " << ch1 << " characters in " << str1 << endl;
    cout << countAccurance(str2, ch2) << " " << ch2 << " characters in " << str2 << endl;
}
// Task 9
void toUpperCase(char arr[]) {
    for (int i = 0; arr[i] != '\0'; i++) {
        if (arr[i] >= 'a' && arr[i] <= 'z')
            arr[i] = arr[i] - ('a' - 'A'); // разница между нижним и верхним регистром
    }
}

void task9() {
    char str[101];
    cin >> str;
    toUpperCase(str);
    cout << str << endl;
}
// Task 10 
void convertSequence(char arr[], char result[]) {
    int j = 0;
    for (int i = 0; arr[i] != '\0'; i++) {
        if (isalpha(arr[i])) {
            if (islower(arr[i]))
                result[j++] = toupper(arr[i]);
            else if (isupper(arr[i]))
                result[j++] = tolower(arr[i]);
        }
    }
    result[j] = '\0';
}

void task10() {
    char str[101];
    cin >> str;
    char converted[101];
    convertSequence(str, converted);
    cout << converted << endl;
}
// Task 11
int timeToSeconds(int h, int m, int s) {
    return h * 3600 + m * 60 + s;
}

void secondsToTime(int totalSeconds, int &h, int &m, int &s) {
    h = totalSeconds / 3600;
    totalSeconds %= 3600;
    m = totalSeconds / 60;
    s = totalSeconds % 60;
}

void task11() {
    int h1, m1, s1, h2, m2, s2;
    cin >> h1 >> m1 >> s1;
    cin >> h2 >> m2 >> s2;

    int t1 = timeToSeconds(h1, m1, s1);
    int t2 = timeToSeconds(h2, m2, s2);

    int diff = t2 - t1;

    int h, m, s;
    secondsToTime(diff, h, m, s);

    cout << (h < 10 ? "0" : "") << h << ":"
         << (m < 10 ? "0" : "") << m << ":"
         << (s < 10 ? "0" : "") << s << endl;
}
// Task 12
int binaryToDecimal(const char bin[]) {
    int result = 0;
    for (int i = 0; bin[i] != '\0'; i++) {
        result = result * 2 + (bin[i] - '0');
    }
    return result;
}

void task12() {
    int N;
    cin >> N;
    char bin[32];
    cin >> bin;
    cout << binaryToDecimal(bin) << endl;
}
//MAIN
int main() {
    int zxc;
    cin >> zxc;

    switch (zxc) {
        case 1: {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            cout << min4(a, b, c, d);
            break;
        }
        case 2: {
            double a;
            int n;
            cin >> a >> n;
            cout << power2(a, n);
            break;
        }
        case 3: {
            bool x, y;
            cin >> x >> y;
            cout << myXor2(x, y);
            break;
        }
        case 4: {
            bool x, y, z;
            cin >> x >> y >> z;
            cout << election(x, y, z);
            break;
        }
        case 5: {
            int a, b;
            cin >> a >> b;
            cout << getSign(a, b);
            break;
        }
        case 6: {
            comparePositiveArrays();
            break;
        }
        case 7: {
            longestSeries();
            break;
        }
        case 8: {
            task8();
            break;
        }
        case 9: {
            task9();
            break;
        }
        case 10: {
            task10();
            break;
        }
        case 11: {
            task11();
            break;
        }
        case 12: {
            task12();
            break;
        }
        
        default: {
            cout << "Invalid task number!";
            break;
        }
    }

    return 0;
}
