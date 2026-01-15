#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
int main() {
//Task 1
    double x = 3 , y = 4 ,z;
    cout << "Input x y" << endl;
    cin >> x >> y;
    cout <<"Task-1: " << x+y << endl; 
// Task 2
    cout << "Input x y z" << endl;
    cin >> x >> y >> z;
    cout <<"Task-2: " << pow(x,2)+y-(int(z) / 2) << endl;
// Task 3
    cout << "Input x y z" << endl;
    cin >> x >> y >> z;
    if (x < y && y < z) {
    cout <<"Task-3: YES " << endl ;
    } else {
        cout <<"Task-3: NO " << endl ;
    }
// Task 4
    cout << "Input x y z" << endl;
    cin >> x >> y >> z;
    if (x <= y && y <= z) {
    cout <<"Task-4: " << 2*x << " "<< 2*y << " " << 2*z << endl ;
    } else {
        cout <<"Task-4: " << abs(x)<< " "<<abs(y)<< " "<<abs(z) << endl ;
    }
// Task 5
    cout << "Input x y z" << endl;
    cin >> x >> y >> z;
    cout <<"Task-5: " << min({x,y,z}) << " " << max({x,y,z}) << endl ;
// Task 6
    int years = 2012;
    cout << "Input year" << endl;
    cin >> years;
    if ((years % 400 == 0) || (years % 4 == 0 && years % 100 !=0)) {
        cout << "Task-6: 366" << endl ;
    } else {
        cout << "Task-6: 365" << endl ;
    }
// Task 7
    int xx, yy;
    cout << "Input x y " << endl;
    cin >> xx >> yy;
    if (xx % yy == 0) {
        cout << "Task-7: YES" << endl ;
    } else {
        cout << "Task-7: NO"  << endl ;}
// Task 8
    x = 3 , y = 4;
    cout << "Input x y" << endl;
    cin >> x >> y ;
    if (x < y) { cout << "Task-8: <" << endl ;}
    else if (x > y) { cout << "Task-8: >" << endl ;} 
    else if (x == y) { cout << "Task-8: =" << endl ;} 
// Task 9
    x = 3, y = 4, z = 5;
    cout << "Input x y z" << endl;
    cin >> x >> y >> z;
    if ((x + y > z) && (x + z > y) && (z + y > x)) {
        cout << "Task-9: YES" << endl ;
    } else {cout << "Task-9: NO" << endl ;}
// Task 10
    int day, month, year;
    cout << "Input day month year" << endl;
    cin >> day >> month >> year;
    day = 31 , month = 12 , year = 2022 ;
    int da[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month < 1 || month > 12) {
        cout << "Task-10: NO" << endl ;
        return 0;
    }
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        if (month == 2)
            da[1] = 29;
    }
    if (day >= 1 && day <= da[month - 1]) {
        cout << "Task-10: YES" << endl;
    } else {
        cout << "Task-10: NO" << endl;
    }
// Task 11
    x = 8 ; y = 5;
    char f = '-' ;
    cout << "Input x sign y" << endl;
    cin >> x >> f >> y;
    switch(f) {
        case '+':
            cout << "Task-11: " << x + y << endl;
            break;
        case '-':
            cout << "Task-11: " << x - y << endl;
            break;
        case '*':
            cout << "Task-11: " << x * y << endl;
            break;
        case '/':
            cout << "Task-11: " << x / y << endl;
            break;
    }
}