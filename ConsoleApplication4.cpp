#include<iostream>
#include<string>
using namespace std;
string strmax(string Ra, string Rb) {
    if (Ra.size() > Rb.size())
        return Ra;
    if (Ra.size() < Rb.size())
        return Rb;
    for (int i = Ra.size(); i > 0; i--) {
        if (Ra[i] - '0' > Rb[i] - '0')
            return Ra;
        if (Ra[i] - '0' < Rb[i] - '0')
            return Rb;
    }
    return Ra;
}
//большее число
int strlenmax(string a, string b) {
    int isnA = 0, isnB = 0;
    if (a[0] == '-')
        isnA = 1;
    if (b[0] == '-')
        isnB = 1;
    if (a.size() - isnA > b.size() - isnB)
        return a.size() - isnA;
    if (a.size() - isnA < b.size() - isnB)
        return b.size() - isnB;
    return a.size() - isnA;
}
//находит самое длинное число из 2х(функция проверена)
string rev(string str) {
    string str2;
    int n = 0;
    if (str[0] == '-')
        for (int i = str.size() - 1; i > 0; i--) {
            str2 = str2 + str[i];
        }
    else
        for (int i = str.size() - 1; i >= 0; i--) {
            str2 = str2 + str[i];
        }
    return str2;
}
//переворачивает число(проверено) 
string sum(string Ra, string Rb) {
    int n = 0;
    string c = "";
    while (Rb.size() < strlenmax(Ra, Rb))
        Rb += "0";
    while (Ra.size() < strlenmax(Ra, Rb))
        Ra += "0";

    for (int i = 0; i < strlenmax(Ra, Rb); i++) {
        c += (((Ra[i] - '0') + (Rb[i] - '0') + n) % 10 + '0');
        n = ((Ra[i] - '0') + (Rb[i] - '0') + n) / 10;
    }
    if (n != 0)
        c += n + '0';
    return rev(c);
}
//сумма
string sub(string Ra, string Rb) {
    if (Ra == Rb)
        return "0";
    int n = 0;
    string c = "";
    while (Rb.size() < strlenmax(Ra, Rb))
        Rb += "0";
    while (Ra.size() < strlenmax(Ra, Rb))
        Ra += "0";

    for (int i = 0; i < strlenmax(Ra, Rb); i++) {
        if ((Ra[i] - '0') - n >= Rb[i] - '0') {
            c += (((Ra[i] - '0') - (Rb[i] - '0') - n) + '0');
            n = 0;
        }
        else {
            c += ((10 - ((Rb[i] - '0') - (Ra[i] - '0') + n)) + '0');
            n = 1;
        }
    }
    c = rev(c);
    int i = 0;
    while (c[i] == '0') {
        i++;
    }
    string c2;
    for (int j = i; j < c.size(); j++)
        c2 += c[j];
    return c2;
}
//вычитание (из большего меньше)
string oper(string a, string b, int op) {//0 - слож. 1 - выч. 2 - умн. 3 - дел.
    int issub = 1;
    if (op == 1)
        issub = -1;
    int isnegA = 1, isnegB = 1;
    string str;
    if (a[0] == '-')
        isnegA = -1;
    if (b[0] == '-')
        isnegB = -1;
    a = rev(a);
    b = rev(b);
    if (isnegA == 1 && issub * isnegB == 1)
        return sum(a, b);
    if (isnegA == -1 && issub * isnegB == -1)
        return '-' + sum(a, b);
    if (strmax(a, b) == a) {
        if(isnegA == 1 && issub * isnegB == -1)
            return sub(a, b);
        else
            return '-' + sub(a, b);
    }
    if (strmax(a, b) == b) {
        if (isnegA == -1 && issub * isnegB == 1)
            return sub(b, a);
        else
            return '-' + sub(b, a);
    }
    return "0";
}
int main() {
    string a, b;
    int op;
    cout << "enter first number: ";
    cin >> a;
    cout << "enter second number: ";
    cin >> b;
    cout << "enter operation(0 - sum, 1 - sub): ";
    cin >> op;
    cout << oper(a, b, op) << endl;
    return 0;
}