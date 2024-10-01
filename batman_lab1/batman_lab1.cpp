﻿#include <iostream>  
#include <fstream>  
#include <string> 

using namespace std;

struct tube {
    string Name = "";
    float KM = -1;
    int MM = -1;
    bool CHECK = true;

};

struct KS {
    string Name1 = "";
    int KC = -1;
    int KCV = -1;
    float EFFECT = -1;
};

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
    while (true) {
        if (K.KCV > K.KC) {
            cout << "Количество цехов в работе не может быть больше чем всего цехов" << endl;
            cin >> K.KCV;
        }
        else {
            break;
        }
    };
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

    string boolean_const = "";
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

void save_to(tube T,KS K) {

    ofstream out;
    out.open("zapis_in_file.txt");
    if (out.is_open())
    {
        string Data = "";
        Data = "Tube" + '\n' + T.Name + '\n';
        Data = Data + to_string(T.KM) + '\n';
        Data = Data + to_string(T.MM) + '\n';
        Data = Data + to_string(T.CHECK) + '\n';
        string Data2 = "";
        Data2 = "KS" + '\n' + K.Name1 + '\n';
        Data2 = Data2 + to_string(K.KC) + '\n';
        Data2 = Data2 + to_string(K.KCV) + '\n';
        Data2 = Data2 + to_string(K.EFFECT) + '\n';
        out << Data2 << std::endl;

        out << Data << endl;
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
void menu() {
    tube T;
    KS K;
    while (true) {
            cout << "1. Добавить трубу" << endl;
            cout << "2. Добавить КС" << endl;
            cout << "3. Просмотр всех объектов" << endl;
            cout << "4. Редактировать трубу" << endl;
            cout << "5. Редактировать КС" << endl;
            cout << "6. Сохранить данные " << endl;
            cout << "7. Загрузить данные " << endl;
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
            case 6: save_to(T,K);
                break;
                break;
            case 7: loads_from_file(T);
                break;
            case 0: 
                break;
            default: cout << "Данная команда отсутствует\n";


            }


    }

}

int main() {
    setlocale(LC_ALL, "RU");
    menu();
    return 0;
}
