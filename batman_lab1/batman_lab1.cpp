#include <iostream>
#include <fstream>  
#include <string> 

using namespace std;

struct tube {
    string Name;
    float KM;
    int MM;
    bool CHECK;

};

struct KS {
    string Name1;
    int KC;
    int KCV;
    float EFFECT;
};

int check() {
    int num;
    while (true) {
        cin >> num;
        if (cin.fail() || num < 0 || cin.peek() != '\n') { // cin.fail() возвращает true, если нашлась ошибка при вводе; cin.peek() spaces
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //  Пропускает все оставшиеся символы в буфере ввода до символа новой строки
            cout << "Ошибка. Попробуйте снова: ";
        }
        else {
            return num;
        }
    }
}

float checkfloat() {
    float num;
    while (true) {
        cin >> num;
        if (cin.fail() || num <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка. Попробуйте снова: ";
        }
        else {
            return num;
        }
    }
}

tube tube_cin() {
    tube T;

    cout << "название трубы " << endl;
    getline(cin >> ws, T.Name);
    cout << "длина" << endl;
    T.KM = checkfloat();
    cout << "диаметр" << endl;
    T.MM = check();
    T.CHECK = true;
    return T;
}

KS KS_cin() {
    KS K;

    cout << "название КС " << endl;
    getline(cin >> ws, K.Name1);
    cout << "количество цехов " << endl;
    K.KC = check();
    cout << "количество цехов в работе " << endl;
    K.KCV = check();
    while (true) {
        if (K.KCV > K.KC) {
            cout << "Количество цехов в работе не может быть больше чем всего цехов" << endl;
            K.KCV = check();
        }
        else {
            break;
        }
    }
    cout << "эффективность " << endl;
    K.EFFECT = checkfloat();
    while (true) {
        if (K.EFFECT > 1) {
            cout << "Эффективность может быть от 0 до 1" << endl;
            K.EFFECT = checkfloat();
        }
        else {
            break;
        }

        return K;
    }
}

void show(const tube& T) {
    cout << "название трубы " << T.Name << endl;
    cout << "длина " << T.KM << endl;
    cout << "диаметр " << T.MM << endl;
    if (T.CHECK) {
        cout << "Труба в рабочем состоянии" << endl;
    }
    else {
        cout << "Труба не работает" << endl;
    }

}

void show_2(const KS& K) {
    cout << "название КС " << K.Name1 << endl;
    cout << "количество цехов " << K.KC << endl;
    cout << "количество цехов в работе " << K.KCV << endl;
    cout << "эффективность " << K.EFFECT << endl;
}

void view_all(const tube& T, const KS& K) {
    if (K.KC > 0 && T.MM > 0) {
        show(T);
        show_2(K);
    }
    else if (K.KC < 1 && T.MM > 0) {
        show(T);
        cout << "КС еще не была добавлена!" << endl;
    }
    else if (K.KC > 0 && T.MM < 1) {
        show_2(K);
        cout << "Труба еще не была добавлена!" << endl;
    }
    else {
        cout << "Вы еще не добавили ни одного объекта." << endl;
    }
}

void switch_status(tube& T) {
    T.CHECK = !T.CHECK;
    cout << "Статус изменен!" << endl;
}

void StartKC(KS& K) {
    cout << "Всего " << K.KC << " в работе " << K.KCV << endl;
    int count;
    int delta;
    delta = K.KC - K.KCV; // сколько ещё можно запустить

    if (delta == 0)
    {
        cout << "Все станции итак работают" << endl;
        return;
    }

    do {
        cout << " возможно запустить" << delta << "цехов: ";
        count = check();
    } while (count < 1 || count > delta);

    K.KCV += count;
    cout << count << "теперь работает столько станций" << K.KCV << endl;
}

void StopKC(KS& K) {
    cout << "Всего " << K.KC << " в работе " << K.KCV << endl;
    int count;

    if (K.KCV == 0)
    {
        cout << "Работающих станций нет" << endl;
        return;
    }
    do {
        cout << "Введите сколько станций сделать рабомичи ";
        count = check();
    } while (count < 1 || count > K.KCV);

    K.KCV -= count;
    cout << count << "теперь работают столько станций" << K.KCV << endl;
}

void save1(const tube& T, ofstream& out)
{
    out << "data Pipe:" << endl;
    out << T.Name << endl;
    out << T.KM << " " << T.MM << " " << T.CHECK << endl;
}

void save2(const KS& K, ofstream& out)
{
    out << "data Station:" << endl;
    out << K.Name1 << endl;
    out << K.KC << " " << K.KCV << " " << K.EFFECT << endl;
}

void saveall(const tube& T, const KS& K) {
    if (T.Name.empty() && K.Name1.empty()) { // empty return true, if stroka pustai
        cout << "Имен нет!" << endl;
        return;
    }
    ofstream out;
    out.open("zapis_in_file.txt");
    if (out.is_open())
    {
        if (!T.Name.empty()) {
            save1(T, out);
            cout << "Труба сохранена!" << endl;
        }
        if (!K.Name1.empty()) {
            save2(K, out);
            cout << "КС сохранена!" << endl;
        }

    }
    out.close();
}

void loads_from_file(tube& T, KS& K) {
    ifstream in("zapis_in_file.txt");
    if (in.is_open()) {
        string finde;
        while (getline(in, finde)) {
            if (finde == "data Pipe:") {
                getline(in, T.Name);
                in >> T.KM >> T.MM >> T.CHECK;
                in.ignore();
                cout << "Данные из файла о трубе записаны" << endl;
            }
            if (finde == "data CS:") {
                getline(in, K.Name1);
                in >> K.KC >> K.KCV >> K.EFFECT;
                in.ignore();
                cout << "Данные из файла о КС записаны" << endl;
            }
        }
        if (T.Name.empty()) {
            cout << "Нет данных о трубе" << endl;
        }
        if (K.Name1.empty()) {
            cout << "Нет данных о КС" << endl;
        }
    }
    in.close();
}
void menu() {
    tube T;
    KS K;
    bool T_exists = false; // default nothing no
    bool K_exists = false;

    while (true) {
        cout << "1. Добавить трубу" << endl;
        cout << "2. Добавить КС" << endl;
        cout << "3. Просмотр всех объектов" << endl;
        cout << "4. Редактировать трубу" << endl;
        cout << "5. Редактировать КС" << endl;
        cout << "6. Сохранить данные " << endl;
        cout << "7. Загрузить данные " << endl;
        cout << "8. Выход" << endl;

        int number;
        number = check();
        cout << "\n";

        switch (number) {
        case 1:
        {
            T = tube_cin();
            T_exists = true;
            break;
        }
        case 2:
        {
            K = KS_cin();
            K_exists = true;
            break;
        }
        case 3:
        {
            view_all(T, K);
            break;
        }
        case 4:
        {
            if (T_exists)
                switch_status(T);
            else
                cout << "Tube not.\n";
            break;
        }
        case 5:
        {
            if (K_exists) {
                cout << "1. Включить цех(и)\n2. Выключить цех(и)." << endl;
                int number_choose;
                cin >> number_choose;
                switch (number_choose) {
                case 1: StartKC(K);
                    break;
                case 2: StopKC(K);
                    break;
                default:
                    cout << "Введите 1 или 2!";
                    break;
                }
            }

            else
                cout << "KS not.\n";
            break;
        }
        case 6:
        {
            saveall(T, K);
            break;
        }
        case 7:
        {
            loads_from_file(T, K);
            if (T.KM < 0) {
                T_exists = false;
            }
            else T_exists = true;
            if (K.KC < 0) {
                K_exists = false;
            }
            else K_exists = true;
            break;
        }
        case 8:
            return;
        default:
        {
            cout << "Данная команда отсутствует\n";
            break;
        }


        }


    }

}

int main() {
    setlocale(LC_ALL, "RU");
    menu();
    return 0;
}