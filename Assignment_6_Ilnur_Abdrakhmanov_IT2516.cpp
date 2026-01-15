#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <string>
using namespace std;

// Task 1) Train Schedule Lookup
struct Train1 {
    int ID;
    char* destination;
    char* time;
};

void task1() {
    int n;
    cin >> n;
    Train1* tr = new Train1[n];
    for (int i = 0; i < n; i++) {
        int id;
        string dest, tim;
        cin >> id >> dest >> tim;
        tr[i].ID = id;
        tr[i].destination = new char[dest.size() + 1];
        tr[i].time = new char[tim.size() + 1];
        for (int j = 0; j < (int)dest.size(); j++) {
            tr[i].destination[j] = toupper(dest[j]);
        }
        tr[i].destination[dest.size()] = '\0';
        for (int j = 0; j < (int)tim.size(); j++) {
            tr[i].time[j] = tim[j];
        }
        tr[i].time[tim.size()] = '\0';
    }
    string q;
    cin >> q;
    for (int i = 0; i < (int)q.size(); i++) q[i] = toupper(q[i]);
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (strcmp(tr[i].destination, q.c_str()) == 0) {
            cout << tr[i].ID << "_" << tr[i].destination << "_" << tr[i].time;
            found = true;
            break;
        }
    }
    if (!found) cout << "Impossible";
    for (int i = 0; i < n; i++) {
        delete[] tr[i].destination;
        delete[] tr[i].time;
    }
    delete[] tr;
}

// Task 2) Top Student Finder
struct Student {
    int ID;
    char* surname;
    double grade;
};

void task2() {
    int n;
    cin >> n;
    Student* st = new Student[n];
    for (int i = 0; i < n; i++) {
        int id;
        string name;
        double g;
        cin >> id >> name >> g;
        st[i].ID = id;
        st[i].grade = g;
        st[i].surname = new char[name.size() + 1];
        for (int j = 0; j < (int)name.size(); j++) st[i].surname[j] = name[j];
        st[i].surname[name.size()] = '\0';
    }
    int best = 0;
    for (int i = 1; i < n; i++) {
        if (st[i].grade > st[best].grade) best = i;
        else if (st[i].grade == st[best].grade && st[i].ID < st[best].ID) best = i;
    }
    cout << st[best].ID << " " << st[best].surname << " " << st[best].grade;
    for (int i = 0; i < n; i++) delete[] st[i].surname;
    delete[] st;
}

// Task 3) Heaviest Luggage Finder
struct Luggage {
    char* description;
    int count;
    double weight;
};
struct Passenger {
    int luggageSize;
    char* name;
    Luggage* luggage;
};

void task3() {
    int N;
    cin >> N;
    Passenger* p = new Passenger[N];
    string temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        p[i].name = new char[temp.size() + 1];
        for (int j = 0; j < (int)temp.size(); j++) p[i].name[j] = temp[j];
        p[i].name[temp.size()] = '\0';
        int m;
        cin >> m;
        p[i].luggageSize = m;
        p[i].luggage = new Luggage[m];
        for (int j = 0; j < m; j++) {
            string desc;
            int cnt;
            double w;
            cin >> desc >> cnt >> w;
            p[i].luggage[j].description = new char[desc.size() + 1];
            for (int k = 0; k < (int)desc.size(); k++) p[i].luggage[j].description[k] = desc[k];
            p[i].luggage[j].description[desc.size()] = '\0';
            p[i].luggage[j].count = cnt;
            p[i].luggage[j].weight = w;
        }
    }
    double maxW = -1;
    int bestP = 0, bestL = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < p[i].luggageSize; j++) {
            if (p[i].luggage[j].weight > maxW) {
                maxW = p[i].luggage[j].weight;
                bestP = i;
                bestL = j;
            }
        }
    }
    cout << p[bestP].name << "\n" << p[bestP].luggage[bestL].description;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < p[i].luggageSize; j++) {
            delete[] p[i].luggage[j].description;
        }
        delete[] p[i].luggage;
        delete[] p[i].name;
    }
    delete[] p;
}

// Task 4) Train Sorting by Destination
struct Train4 {
    int ID;
    char* FromAddress;
    char* ToAddress;
    char* DepartureTime;
};

void task4() {
    int n;
    cin >> n;
    Train4* tr = new Train4[n];
    for (int i = 0; i < n; i++) {
        int id;
        string from, to, time;
        cin >> id >> from >> to >> time;
        tr[i].ID = id;
        tr[i].FromAddress = new char[from.size() + 1];
        tr[i].ToAddress = new char[to.size() + 1];
        tr[i].DepartureTime = new char[time.size() + 1];
        for (int j = 0; j < (int)from.size(); j++) tr[i].FromAddress[j] = toupper(from[j]);
        tr[i].FromAddress[from.size()] = '\0';
        for (int j = 0; j < (int)to.size(); j++) tr[i].ToAddress[j] = toupper(to[j]);
        tr[i].ToAddress[to.size()] = '\0';
        for (int j = 0; j < (int)time.size(); j++) tr[i].DepartureTime[j] = time[j];
        tr[i].DepartureTime[time.size()] = '\0';
    }
    sort(tr, tr + n, [](const Train4& a, const Train4& b) {
        return strcmp(a.ToAddress, b.ToAddress) < 0;
        });
    for (int i = 0; i < n; i++) {
        cout << tr[i].ID << " " << tr[i].FromAddress << " " << tr[i].ToAddress << " " << tr[i].DepartureTime << endl;
    }
    for (int i = 0; i < n; i++) {
        delete[] tr[i].FromAddress;
        delete[] tr[i].ToAddress;
        delete[] tr[i].DepartureTime;
    }
    delete[] tr;
}

// Task 5) Government Scholarship Distribution
struct Applicant {
    int ID;
    char* Name;
    char* Surname;
    int s1, s2, s3, sel;
    bool special;
    int total;
};

bool cmpApplicant(const Applicant& a, const Applicant& b) {
    if (a.total != b.total) return a.total > b.total;
    if (a.sel != b.sel) return a.sel > b.sel;
    return a.ID < b.ID;
}

void task5() {
    int N, M;
    cin >> N >> M;
    Applicant* a = new Applicant[N];
    for (int i = 0; i < N; i++) {
        int id;
        string name, surname, spec;
        int s1, s2, s3, sel;
        cin >> id >> name >> surname >> s1 >> s2 >> s3 >> sel >> spec;
        a[i].ID = id;
        a[i].s1 = s1;
        a[i].s2 = s2;
        a[i].s3 = s3;
        a[i].sel = sel;
        a[i].total = s1 + s2 + s3 + sel;
        a[i].Name = new char[name.size() + 1];
        for (int j = 0; j < (int)name.size(); j++) a[i].Name[j] = name[j];
        a[i].Name[name.size()] = '\0';
        a[i].Surname = new char[surname.size() + 1];
        for (int j = 0; j < (int)surname.size(); j++) a[i].Surname[j] = surname[j];
        a[i].Surname[surname.size()] = '\0';
        for (int j = 0; j < (int)spec.size(); j++) spec[j] = toupper(spec[j]);
        a[i].special = (spec == "YES" || spec == "TRUE");
    }
    int* specialIdx = new int[N];
    int* regularIdx = new int[N];
    int sc = 0, rc = 0;
    for (int i = 0; i < N; i++) {
        if (a[i].special) specialIdx[sc++] = i;
        else regularIdx[rc++] = i;
    }
    sort(specialIdx, specialIdx + sc, [&](int x, int y) {
        return cmpApplicant(a[x], a[y]);
        });
    sort(regularIdx, regularIdx + rc, [&](int x, int y) {
        return cmpApplicant(a[x], a[y]);
        });
    int* winners = new int[M];
    int wc = 0;
    for (int i = 0; i < sc && wc < M; i++) {
        winners[wc++] = specialIdx[i];
    }
    for (int i = 0; i < rc && wc < M; i++) {
        winners[wc++] = regularIdx[i];
    }
    sort(winners, winners + wc, [&](int x, int y) {
        return cmpApplicant(a[x], a[y]);
        });
    for (int i = 0; i < wc; i++) {
        int idx = winners[i];
        cout << a[idx].ID << " " << a[idx].Name << " " << a[idx].Surname << " " << a[idx].total << endl;
    }
    for (int i = 0; i < N; i++) {
        delete[] a[i].Name;
        delete[] a[i].Surname;
    }
    delete[] a;
    delete[] specialIdx;
    delete[] regularIdx;
    delete[] winners;
}

// Task 6) Find Keyword in Text
void task6() {
    string text, key;
    getline(cin, text);
    if (text.size() == 0) getline(cin, text);
    getline(cin, key);
    size_t pos = text.find(key);
    if (pos == string::npos) cout << -1;
    else cout << (int)pos;
}

// Task 7) Replace Characters with '*'
void task7() {
    string text, chars;
    getline(cin, text);
    if (text.size() == 0) getline(cin, text);
    getline(cin, chars);
    for (int i = 0; i < (int)text.size(); i++) {
        for (int j = 0; j < (int)chars.size(); j++) {
            if (text[i] == chars[j]) {
                text[i] = '*';
                break;
            }
        }
    }
    cout << text;
}

// Task 8) Reverse String
void task8() {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    cout << s;
}

// Task 9) String Transformation
bool isVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'o' || c == 'y' || c == 'e' || c == 'u' || c == 'i';
}

void task9() {
    string s;
    cin >> s;
    string res = "";
    for (int i = 0; i < (int)s.size(); i++) {
        char c = s[i];
        if (!isVowel(c)) {
            res.push_back('.');
            res.push_back(tolower(c));
        }
    }
    cout << res;
}

// Task 10) Check for Anagrams
void task10() {
    string a, b;
    cin >> a >> b;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (a == b) cout << "YES";
    else cout << "NO";
}

// Task 11) Concatenation with Reversed Parts
void task11() {
    string s;
    getline(cin, s);
    if (s.size() == 0) getline(cin, s);
    string st[205];
    int top = 0;
    st[0] = "";
    for (int i = 0; i < (int)s.size(); i++) {
        char c = s[i];
        if (c == '(') {
            top++;
            st[top] = "";
        }
        else if (c == ')') {
            reverse(st[top].begin(), st[top].end());
            st[top - 1] += st[top];
            top--;
        }
        else {
            st[top] += c;
        }
    }
    cout << st[0];
}

// Task 12) String Unpacking
void task12() {
    string s;
    cin >> s;
    string res = "";
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (isdigit(s[i])) {
            int num = 0;
            while (i < n && isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            if (i < n && isupper(s[i])) {
                for (int k = 0; k < num; k++) res.push_back(s[i]);
            }
        }
        else {
            res.push_back(s[i]);
        }
    }
    cout << res;
}

// Task 13) Lucky Ticket
int digitRootFromSum(int sum) {
    if (sum == 0) return 0;
    int r = sum % 9;
    if (r == 0) return 9;
    return r;
}

void task13() {
    string s;
    cin >> s;
    int n = s.size();
    int* pref = new int[n + 1];
    pref[0] = 0;
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + (s[i] - '0');
    }
    bool ok = false;
    for (int i = 1; i < n; i++) {
        int leftSum = pref[i];
        int rightSum = pref[n] - pref[i];
        int dr1 = digitRootFromSum(leftSum);
        int dr2 = digitRootFromSum(rightSum);
        if (dr1 == dr2) {
            ok = true;
            break;
        }
    }
    delete[] pref;
    if (ok) cout << "YES";
    else cout << "NO";
}

// MAIN
int main() {
    int t;
    cin >> t;
    switch (t) {
    case 1: task1(); break;
    case 2: task2(); break;
    case 3: task3(); break;
    case 4: task4(); break;
    case 5: task5(); break;
    case 6: task6(); break;
    case 7: task7(); break;
    case 8: task8(); break;
    case 9: task9(); break;
    case 10: task10(); break;
    case 11: task11(); break;
    case 12: task12(); break;
    case 13: task13(); break;
    default: cout << "Invalid task number!"; break;
    }
    return 0;
}
