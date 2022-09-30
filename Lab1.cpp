#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Var7 {
    string mark;
    string size;
    int cost = 0;
};

void print(Var7 &var){
    cout << var.mark << " ";
    cout << var.size << " ";
    cout << var.cost << " ";
}

void AVG(Var7 &s1, Var7 &s2, Var7 &s3, Var7 &s4) {
    double avg;
    avg = (s1.cost + s2.cost + s3.cost + s4.cost) / 4.0;
    cout << "Avg: " << avg << endl;
}

ofstream operator<<(ofstream &out, const Var7 &str){
    out << str.mark << " " << str.size << " " << str.cost << endl;
    return ofstream();
}

int main() {
    ifstream fin("D:\\in.txt");
    ofstream fout("D:\\out.txt");
    string b[4];
    int count = 0;
    Var7 a[4];
    while(getline(fin, b[count])) {
        ++count;
    }

    for (int i = 0; i < 4; ++i) {
        int Ok = 0;
        for (int j = 0; j < b[i].size(); ++j) {
            if (b[i][j] == ' ') {
                Ok++;
            }
            else {
                if (Ok == 0)
                    a[i].mark = a[i].mark + b[i][j];
                if (Ok == 1)
                    a[i].size = a[i].size + b[i][j];
                if (Ok == 2)
                    a[i].cost = a[i].cost * 10 + b[i][j] - '0';
            }
        }
    }
    cout << "______________________________________________________________" << endl;
    cout << "| Сhoose what line you want to change: 1) First line         |" << endl;
    cout << "|                                      2) Second line        |" << endl;
    cout << "|                                      3) Third line         |" << endl;
    cout << "|                                      4) Fourth line        |" << endl;
    cout << "|                                      0) Exit               |" << endl;
    cout << "|____________________________________________________________|" << endl;
    int str;
    cout << "Input number: ";
    cin >> str;
    switch (str) {
        case 0:
            break;
        case 1:
            cout << "_________________________________________________________" << endl;
            cout << "| Сhoose what you want to change: 1) Monitor brand      |" << endl;
            cout << "|                                 2) screen resolution  |" << endl;
            cout << "|                                 3) Cost               |" << endl;
            cout << "|_______________________________________________________|" << endl;
            int q;
            cout << "input number: ";
            cin >> q;
            if(q == 1){
                string brand;
                cout << "Input new brand: ";
                cin >> brand;
                a[0].mark = brand;
            }
            if(q == 2){
                string resolution;
                cout << "Input new resolution: ";
                cin >> resolution;
                a[0].size = resolution;
            }
            if(q == 3){
                int cost;
                cout << "Input new cost: ";
                cin >> cost;
                a[0].cost = cost;
            }
            break;
        case 2:
            cout << "_________________________________________________________" << endl;
            cout << "| Сhoose what you want to change: 1) Monitor brand      |" << endl;
            cout << "|                                 2) screen resolution  |" << endl;
            cout << "|                                 3) Cost               |" << endl;
            cout << "|_______________________________________________________|" << endl;
            int q2;
            cout << "input number: ";
            cin >> q2;
            if(q2 == 1){
                string brand2;
                cout << "Input new brand: ";
                cin >> brand2;
                a[1].mark = brand2;
            }
            if(q2 == 2){
                string resolution2;
                cout << "Input new resolution: ";
                cin >> resolution2;
                a[1].size = resolution2;
            }
            if(q2 == 3){
                int cost2;
                cout << "Input new cost: ";
                cin >> cost2;
                a[1].cost = cost2;
            }
            break;
        case 3:
            cout << "_________________________________________________________" << endl;
            cout << "| Сhoose what you want to change: 1) Monitor brand      |" << endl;
            cout << "|                                 2) screen resolution  |" << endl;
            cout << "|                                 3) Cost               |" << endl;
            cout << "|_______________________________________________________|" << endl;
            int q3;
            cout << "input number: ";
            cin >> q3;
            if(q3 == 1){
                string brand3;
                cout << "Input new brand: ";
                cin >> brand3;
                a[2].mark = brand3;
            }
            if(q3 == 2){
                string resolution3;
                cout << "Input new resolution: ";
                cin >> resolution3;
                a[2].size = resolution3;
            }
            if(q3 == 3){
                int cost3;
                cout << "Input new cost: ";
                cin >> cost3;
                a[2].cost = cost3;
            }
            break;
        case 4:
            cout << "_________________________________________________________" << endl;
            cout << "| Сhoose what you want to change: 1) Monitor brand      |" << endl;
            cout << "|                                 2) screen resolution  |" << endl;
            cout << "|                                 3) Cost               |" << endl;
            cout << "|_______________________________________________________|" << endl;
            int q4;
            cout << "input number: ";
            cin >> q4;
            if(q4 == 1){
                string brand4;
                cout << "Input new brand: ";
                cin >> brand4;
                a[3].mark = brand4;
            }
            if(q4 == 2){
                string resolution4;
                cout << "Input new resolution: ";
                cin >> resolution4;
                a[3].size = resolution4;
            }
            if(q4 == 3){
                int cost4;
                cout << "Input new cost: ";
                cin >> cost4;
                a[3].cost = cost4;
            }
            break;
    }

    for(const auto & i : a)
        fout << i;

    fin.close();
    fout.close();
}
