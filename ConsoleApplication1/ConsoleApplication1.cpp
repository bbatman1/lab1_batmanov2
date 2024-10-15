﻿#include <iostream>  
#include <fstream>  
#include <string> 

using namespace std;

struct tube {
    string Name = "";
    int KM = 0;
    int MM = 0;
    bool CHECK = true;

};

struct KS {
    string Name1 = "";
    int KC = 0;
    int KCV = 0;
    float EFFECT = 0;
};

int check(int max, int min) {
    int z;
    cin >> z;
    cin.ignore();
    while (true) {
        if (cin.fail()) {
            cout << "Ошибка. Введено не целое число или символ! Попробуйте ещё раз: ";
            cin.clear();
            while (cin.get() != '\n');
        }
        else if (z < min) {
            cout << "Ошибка. Введено отрицательное число или ноль! Попробуйте ещё раз: ";
        }
        else if (max != 0 && z > max) {
            cout << "Ошибка. Введено число больше максимального! Попробуйте ещё раз: ";
        }
        else {
            break;
        }
        cin >> z;
        cin.ignore();
    }
    return z;
}

float floatcheck(int max, float min) {
    float z;
    cin >> z;
    cin.ignore();
    while (true) {
        if (cin.fail()) {
            cout << "Ошибка. Введено не целое число или символ! Попробуйте ещё раз: ";
            cin.clear();
            while (cin.get() != '\n');
        }
        else if (z < min) {
            cout << "Ошибка. Введено отрицательное число или ноль! Попробуйте ещё раз: ";
        }
        else if (max != 0 && z > max) {
            cout << "Ошибка. Введено число больше максимального! Попробуйте ещё раз: ";
        }
        else {
            break;
        }
        cin >> z;
        cin.ignore();
    }
    return z;
}

int check(int max, int low) {
    int z;
    cin >> z;
    cin.ignore();
    while (true) {
        if (cin.fail()) {
            cout << "Ошибка. Введено не целое число или символ! Попробуйте ещё раз: ";
            cin.clear();
            while (cin.get() != '\n');
        }
        else if (z < low) {
            cout << "Ошибка. Введено отрицательное число или ноль! Попробуйте ещё раз: ";
        }
        else if (max != 0 && z > max) {
            cout << "Ошибка. Введено число больше максимального! Попробуйте ещё раз: ";
        }
        else {
            break;
        }
        cin >> z;
        cin.ignore();
    }
    return z;
}
float floatcheck(int max, float low) {
    float z;
    cin >> z;
    cin.ignore();
    while (true) {
        if (cin.fail()) {
            cout << "Ошибка. Введено не целое число или символ! Попробуйте ещё раз: ";
            cin.clear();
            while (cin.get() != '\n');
        }
        else if (z < low) {
            cout << "Ошибка. Введено отрицательное число или ноль! Попробуйте ещё раз: ";
        }
        else if (max != 0 && z > max) {
            cout << "Ошибка. Введено число больше максимального! Попробуйте ещё раз: ";
        }
        else {
            break;
        }
        cin >> z;
        cin.ignore();
    }
    return z;
}

tube tube_cin() {
    tube T;

    cout << "название трубы " << endl;
    cin >> T.Name;
    cout << "длина" << endl;
    cin >> T.KM;
    cout << "диаметр" << endl;
    cin >> T.MM;
    cout << "в ремонте ли?" << endl;
    cin >> T.CHECK;
    return T;
};
KS KS_cin() {
    KS K;

    cout << "название КС " << endl;
    cin >> K.Name1;
    cout << "количество цехов " << endl;
    cin >> K.KC;
    cout << "количество цехов в работе " << endl;
    cin >> K.KCV;
    cout << "эффективность " << endl;
    cin >> K.EFFECT;
    return K;
};

void show(tube T) {
    cout << "название трубы " << T.Name << endl;
    cout << "длина " << T.KM << endl;
    cout << "диаметр " << T.MM << endl;
    cout << "в ремонте ли? " << T.CHECK << endl;

};
void show_2(KS K) {
    cout << "название КС " << K.Name1 << endl;
    cout << "количество цехов " << K.KC << endl;
    cout << "количество цехов в работе " << K.KCV << endl;
    cout << "эффективность " << K.EFFECT << endl;
};

void edittubs(tube T) {
    if (T.CHECK == 0 or T.CHECK == false) {
        T.CHECK = true;
        cout << "Труба в рабочем состоянии" << endl;
        if (T.CHECK == 1 or T.CHECK == true) {
            T.CHECK = false;
            cout << "Труба в теперь в ремонте" << endl;
        }
    }
}



void editKS(KS K) {

    string boolean_const = "5";
    cout << "количество цехов" << K.KC << endl;
    cout << "количество цехов в работе" << K.KCV << endl;
    cout << "Введите 1 для запуска цеха и 0 для его остановки" << endl;
    cin >> boolean_const;
    if (K.KCV == 0 and boolean_const == "0") {
        cout << "Все цеха и так выключены" << endl;
        cout << "Включить цех? Введите 1,если да" << endl;
        cin >> boolean_const;
    }
    if (boolean_const != "0" and boolean_const != "1") {
        cout << "Вы ввели не 1 и 0. Введите 1 для запуска цеха и 0 для его остановки";
        cin >> boolean_const;
    }
    if (boolean_const == "0") {
        K.KCV = K.KCV - 1;
    }
    if (boolean_const == "1") {
        K.KCV = K.KCV + 1;
    }
    cout << "количество цехов в работе" << K.KCV << endl;
}

void save_to(tube T) {

    ofstream out;
    out.open("zapis_in_file.txt");
    if (out.is_open())
    {
        string Data = "";
        Data += "Tube" + '\n' + T.Name + '\n';
        Data = Data + to_string(T.KM) + '\n';
        Data = Data + to_string(T.MM) + '\n';
        Data = Data + to_string(T.CHECK) + '\n';

        out << Data << endl;
    }
    out.close();
}
void save_to2(KS K) {

    ofstream out;
    out.open("zapis_in_file.txt");
    if (out.is_open())
    {
        string Data = "";
        Data = "KS" + '\n' + K.Name1 + '\n';
        Data = Data + to_string(K.KC) + '\n';
        Data = Data + to_string(K.KCV) + '\n';
        Data = Data + to_string(K.EFFECT) + '\n';
        out << Data << std::endl;
    }
    out.close();
}
void loads_from_file(tube T) {
    string line;
    ifstream in("zapis_in_file.txt"); // 
    if (in.is_open())
    {
        while (getline(in, line))
        {
            if (line == "Tube") {
                getline(in, T.Name);
                getline(in, line);
                in >> T.KM;
                getline(in, line);
                in >> T.MM;
                getline(in, line);
                in >> T.CHECK;
                cout << T.Name << endl;
                cout << T.KM << endl;
            }
        }
    }
    in.close();
}
int menu() {
    tube T;
    KS K;
    while (true) {
        try
        {
            cout << "1. Добавить трубу" << endl;
            cout << "2. Добавить КС" << endl;
            cout << "3. Просмотр всех объектов" << endl;
            cout << "4. Редактировать трубу" << endl;
            cout << "5. Редактировать КС" << endl;
            cout << "6. Сохранить трубу " << endl;
            cout << "7. Сохранить КС " << endl;
            cout << "8. Загрузить трубу " << endl;
            cout << "9. Загрузить КС " << endl;
            cout << "0. Выход" << endl;
            int number;
            cin >> number;
            switch (number) {
            case 1:
                T = tube_cin();
                break;
            case 2: K = KS_cin();
                break;
            case 3:
                show(T);
                show_2(K);
                break;
            case 4: edittubs(T);
                break;
            case 5: editKS(K);
                break;
            case 6: save_to(T);
                break;
            case 7: save_to2(K);
                break;
            case 8: loads_from_file(T);
                break;
            case 9:
                break;
            case 0: return false;
            default: cout << "Данная команда отсутствует\n";


            }
        } 
        catch (...)
        {
            cout << "что то пошло не так" << endl;
        }

    }

}

int main() {
    setlocale(LC_ALL, "RU");
    menu();
    return 0;
}