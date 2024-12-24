import os


filess = []


for root, dirs, files in os.walk(r"C:\Users\HP\Downloads\Telegram Desktop"):
    for file in files:
        if file.endswith('Dado.txt'):
            print(file)
            filess.append(file)
class Counter:
    id = 0
    def __new__(cls, *args, **kwargs):
        cls.id = cls.id + 1
        return object.__new__(cls)

class Truba(Counter):
    
    def __init__(self, name, km, mm, works):
        self.id = self.id
        self.name = name
        self.km = km
        self.mm = mm
        self.works = works
        self.is_empty = None
    def __setattr__(self, key, value):
        if key == "name" and not(value):
            while not(value):
                value = input('Введите непустое название трубы: ')
        elif key == 'km':
            try:
                value = int(value)
                while value <= 0:
                    value = input('Введите целочисленное положительное значение для длины: ')
                    try:
                        value = int(value)
                        if value>0:
                            break
                    except:
                        continue
            except:
                while True:
                    value = input('Введите целочисленное положительное значение для длины: ')
                    try:
                        value = int(value)
                        break
                    except:
                        continue
        elif key == "mm":
            try:
                value = float(value)
                while value <= 0:
                    value = input('Введите целочисленное или с плавающей точкой положительное значение для диаметра: ')
                    try:
                        value = float(value)
                        if value>0:
                            break
                    except:
                        continue
            except:
                while True:
                    value = input('Введите целочисленное или с плавающей точкой положительное значение для диаметра: ')
                    try:
                        value = float(value)
                        break
                    except:
                        continue
        elif key == "works":
            while value != '0' and value != '1':
                value = input('Введите значение 0 или 1 в зависимости от того работает ли труба или нет: ')

        object.__setattr__(self,key,value)


class KS(Counter):
    
    def __init__(self, name, cexi, in_works, KPD):
        self.id = self.id
        self.name = name
        self.cexi = cexi
        self.in_works = in_works
        self.KPD = KPD
    def __setattr__(self, key, value):
        if key == "name" and not(value):
            while not(value):
                value = input('Введите непустое название КС: ')
        elif key == 'cexi':
            try:
                value = int(value)
                while value <= 0:
                    value = input('Введите целочисленное положительное значение для количества цехов: ')
                    try:
                        value = int(value)
                        if value>0:
                            break
                    except:
                        continue
            except:
                while True:
                    value = input('Введите целочисленное положительное значение для количества цехов: ')
                    try:
                        value = int(value)
                        break
                    except:
                        continue
        elif key == "in_works":
            try:
                value = int(value)
                while value < 0 or value>self.cexi:
                    value = input('Введите целочисленное положительное значение для количества работающих цехов(их должно быть меньше всего количества цехов): ')
                    try:
                        value = int(value)
                        if value>0 and value<=self.cexi:
                            break
                    except:
                        continue
            except:
                while True:
                    value = input('Введите целочисленное положительное значение для количества работающих цехов(их должно быть меньше всего количества цехов): ')
                    try:
                        value = int(value)
                        while value > self.cexi or value<0:
                            value = input('Количество работающих цехов должно быть меньше всего количества цехов: ')
                            try:
                                value = int(value)
                                if value > 0 and value <= self.cexi:
                                    break
                            except:
                                continue
                        break
                    except:
                        continue
        elif key == "KPD":
            try:
                value = float(value)
                while value>1 or value <= 0:
                    value = input('Введите кпд от 0 до 1: ')
                    try:
                        value = float(value)
                        if value > 0 and value <=1:
                            break
                    except:
                        continue
            except:
                while value>1 or value <= 0:
                    value = input('Введите кпд от 0 до 1: ')
                    try:
                        value = float(value)
                        if value > 0 and value <=1:
                            break
                    except:
                        continue
        object.__setattr__(self,key,value)

def add_t():
    return Truba(input('Введите название трубы '), input('Введите длину '), input("Введите диаметр "), input("Введите работает ли(0 или 1) "))

def add_k():
    return KS(input('Введите название КС '), input('Введите количество цехов '), input("Введите количество работающих цехов "), input("Введите кпд "))

def all_obj(truba, ks):
    string = ''
    for i in truba:
        string = string + 'Труба\n' + '\n'.join(list(map(str, list(i.__dict__.values()))))
    string_2 = ''
    for i in ks:
        string_2 = string_2 + '\n' + 'КС\n' + '\n'.join(list(map(str, list(i.__dict__.values()))))
    return string+string_2


def edit_t(truba):
    if truba:
        m = input("1.Редактировать все\n2.Редактировать по выбору\n")
        if m == "1":
            mn = input("1.Редактировать признак в ремонте ли\n2.Удалить все\n")
            if mn == "1":
                for i in truba:
                    if i.works == "0":
                        i.works = "1"
                    elif i.works == "1":
                        i.works = "0"
            elif mn == "2":
                truba = []
        elif m == "2":
            mnm = input("1.Редактировать признак в ремонте ли\n2.Удалить по выбору\n")
            if mnm == "1":
                t = ''
                for i in truba:
                    t = t + str(i.id) + "\n"
                mn = 1
                while mn != "0":
                    mn = input("Выбери 1 или несколько труб по ID(0 чтобы завершить) ")
                    for i in range(len(truba)):
                        if str(truba[i].id) == mn:
                            if truba[i].works == "0":
                                truba[i].works = "1"
                            elif truba[i].works == "1":
                                truba[i].works = "0"
                            break
            elif mnm == "2":
                t = ''
                for i in truba:
                    t = t + str(i.id)+"\n"
                mn = 1
                while mn!="0":
                    mn = input("Выбери 1 или несколько труб по ID(0 чтобы завершить) ")
                    for i in range(len(truba)):
                        if str(truba[i].id) == mn:
                            del truba[i]
                            break

    else:
        print("Нет трубы")
def launch(ks, how_much):
    ks.in_works = ks.in_works+how_much

def stop(ks, how_much):
    ks.in_works = ks.in_works - how_much


def edit_k(kss):
    if kss:
        much = input("1.Запустить цех(и)\n2.Остановить цех(и)\n")
        if much == "1":
            for ks in kss:
                th = input(f'Id = {ks.id}\nВведите количество цехов которые нужно запустить(возможно максимум {ks.cexi-ks.in_works}): ')
                try:
                    th = int(th)
                    while th<0 or th>ks.cexi-ks.in_works:
                        th = input(f'Введите количество цехов которые нужно запустить(возможно максимум {ks.cexi - ks.in_works}): ')
                        try:
                            th = int(th)
                            if th >= 0 and th <= ks.cexi-ks.in_works:
                                break
                        except:
                            continue
                    launch(ks, th)
                except:
                    th = input(f'Введите количество цехов которые нужно запустить(возможно максимум {ks.cexi - ks.in_works}): ')
                    try:
                        th = int(th)
                        while th < 0 or th > ks.cexi - ks.in_works:
                            th = input(
                                f'Введите количество цехов которые нужно запустить(возможно максимум {ks.cexi - ks.in_works}): ')
                            try:
                                th = int(th)
                                if th >= 0 and th <= ks.cexi - ks.in_works:
                                    break
                            except:
                                continue
                        launch(ks, th)
                    except:
                        th = int(th)
                        while th < 0 or th > ks.cexi - ks.in_works:
                            th = input(
                                f'Введите количество цехов которые нужно запустить(возможно максимум {ks.cexi - ks.in_works}): ')
                            try:
                                th = int(th)
                                if th >= 0 and th <= ks.cexi - ks.in_works:
                                    break
                            except:
                                continue
                        launch(ks, th)
        if much == "2":
            for ks in kss:
                th = input(f'Id = {ks.id}\nВведите количество цехов которые нужно остановить(возможно максимум {ks.in_works}): ')
                try:
                    th = int(th)
                    while th<0 or th>ks.in_works:
                        th = input(f'Введите количество цехов которые нужно остановить(возможно максимум {ks.in_works}): ')
                        try:
                            th = int(th)
                            if th >= 0 and th <= ks.in_works:
                                break
                        except:
                            continue
                    stop(ks, th)
                except:
                    th = input(f'Введите количество цехов которые нужно остановить(возможно максимум {ks.in_works}): ')
                    try:
                        th = int(th)
                        while th < 0 or th > ks.in_works:
                            th = input(
                                f'Введите количество цехов которые нужно остановить(возможно максимум {ks.in_works}): ')
                            try:
                                th = int(th)
                                if th >= 0 and th <= ks.in_works:
                                    break
                            except:
                                continue
                        stop(ks, th)
                    except:
                        th = int(th)
                        while th < 0 or th > ks.in_works:
                            th = input(
                                f'Введите количество цехов которые нужно остановить(возможно максимум {ks.in_works}): ')
                            try:
                                th = int(th)
                                if th >= 0 and th <=  ks.in_works:
                                    break
                            except:
                                continue
                        stop(ks, th)
    else:
        print('Нет КС')
def save(truba, ks):
    m = input("Введите название для файла: ")
    with open(m+"Dado.txt", 'w', encoding='UTF-8') as f:
        string = ''
        for i in truba:
            string = string + '\n' + 'Труба\n' + '\n'.join(list(map(str, list(i.__dict__.values()))))
        string_2 = ''
        for i in ks:
            string_2 = string_2 + '\n' + 'КС\n' + '\n'.join(list(map(str, list(i.__dict__.values()))))
        f.write(string + string_2)

def search(truba, ks):
    m = input("1.Труба\n2.КС\n")
    if m == "1":
        truba_search(truba)
    elif m == "2":
        ks_search(ks)

def ks_search(ks):
    m = input('1.По названию\n2.По проценту незадействованных цехов\n')
    if m == "1":
        nm = input('Введите название ')
        for i in ks:
            if nm in i.name:
                print(f"Name={i.name}\nId={i.id}\nCex={i.cexi}\nIn_works={i.in_works}\nKPD={i.KPD}")
                return
    elif m == '2':
        nm = input('Введите процент ')
        nm = float(nm)
        t = ''
        for i in ks:
            if nm == 100-int((i.in_works/i.cexi)*100):
                t += f"Name={i.name}\nId={i.id}\nCex={i.cexi}\nIn_works={i.in_works}\nKPD={i.KPD}\n\n"
        print(t)
        return

def truba_search(truba):
    m = input('1.По названию\n2.По признаку работает ли\n')
    if m == "1":
        nm = input('Введите название ')
        for i in truba:
            if nm+'\n' == i.name:
                print(f"Name={i.name}\nId={i.id}\nKM={i.km}\nMM={i.mm}\nWorks={i.works}")
                return
    elif m == '2':
        nm = input('Введите 0 или 1 ')
        t = ''
        for i in truba:
            if nm == i.works:
                t+=f"Name={i.name}\nId={i.id}\nKM={i.km}\nMM={i.mm}\nWorks={i.works}\n\n"
        print(t)
        return
def load():
    trubaa = []
    kss = []
    for j in filess:
        print(j)
        with open(j, encoding='UTF-8') as f:
            m = f.readlines()
        for i in range(len(m)-5):
            if 'Труба\n' == m[i]:
                trubaa.append(Truba(m[i+2], int(m[i+3]), float(m[i+4]), m[i+5][0]))
                trubaa[-1].id = int(m[i+1])
            elif 'КС\n' == m[i]:
                kss.append(KS(m[i+2], int(m[i+3]), int(m[i+4]), float(m[i+5])))
                kss[-1].id = int(m[i+1])

    return trubaa, kss

def join_KS(truba, ks):
    if ks and truba:
        m = input("Введите через пробел ID КС входа, ID КС выходы и ID свободной трубы: ")
        try:
            idis = list(map(int,m.split()))
            if len(idis)!=3:
                while len(idis)!=3:
                    m = input("Введите через пробел ID КС входа, ID КС выходы и ID свободной трубы: ")
                    idis = list(map(int,m.split()))

        except:
            while True:
                m = input("Введите через пробел ID КС входа, ID КС выходы и ID свободной трубы: ")
                try:
                    idis = list(map(int, m.split()))
                    if len(idis)!=3:
                        while len(idis)!=3:
                            m = input("Введите через пробел ID КС входа, ID КС выходы и ID свободной трубы: ")
                            idis = list(map(int,m.split()))
                    break
                except:
                    continue
        if idis[0] == idis[1]:
            print("Должны быть разные ID у КС")
            m = input("Введите через пробел ID КС входа, ID КС выходы и ID свободной трубы: ")
            try:
                idis = list(map(int,m.split()))
                if len(idis)!=3:
                    while len(idis)!=3:
                        m = input("Введите через пробел ID КС входа, ID КС выходы и ID свободной трубы: ")
                        idis = list(map(int,m.split()))

            except:
                while True:
                    m = input("Введите через пробел ID КС входа, ID КС выходы и ID свободной трубы: ")
                    try:
                        idis = list(map(int, m.split()))
                        if len(idis)!=3:
                            while len(idis)!=3:
                                m = input("Введите через пробел ID КС входа, ID КС выходы и ID свободной трубы: ")
                                idis = list(map(int,m.split()))
                        break
                    except:
                        continue
            flag = False
        flag1,flag2 = False,False
        for i in ks:
            if i.id == idis[0]:
                flag1 = True
            if i.id == idis[1]:
                flag2 = True
        if flag1 and flag2:
                
            for i in truba:
                if i.id == idis[-1]:
                    if i.is_empty is None:
                        i.is_empty = True
                        network[idis[0]] = [idis[1]]
                        network[idis[1]]=[]
                        flag = True
                        break
            if not(flag):
                print("Свободной трубы с таким id не существует")
                truba.append(add_t())
                truba[-1].is_empty = True
                network[idis[0]] = [idis[1]]
                network[idis[1]]=[]
        else:
            print("КС с такими ID не существует")
    else:
        print("Создайте хотя бы 1 трубу и 2 кс")
def topological_sort_dfs(graph):
    def dfs(vertex, visited, stack):
        visited.add(vertex)
        for neighbor in graph[vertex]:
            if neighbor not in visited:
                dfs(neighbor, visited, stack)
        stack.append(vertex)

    visited = set()
    stack = []
    for vertex in graph:
        if vertex not in visited:
            dfs(vertex, visited, stack)
    print(f"Отсортированный граф: {stack[::-1]}")
    return stack[::-1]  


truba = []
ks = []
network = {}

while True:
    to_do = input("1.Добавить трубу\n2.Добавить КС\n3.Просмотр всех объектов\n4.Редактировать трубу\n5.Редактировать КС\n6.Сохранить\n7.Загрузить\n8.Поиск\n9.Соединить КС трубой\n10.Сортировка\n0.Выход\n")
    if to_do == '0':
        break
    elif to_do not in list('0123456789')+['10']:
        continue
    elif to_do == "1":
        truba.append(add_t())

    elif to_do == "2":
        ks.append(add_k())
    elif to_do == "3":
        print(all_obj(truba, ks))
    elif to_do == '4':
        edit_t(truba)
    elif to_do == '5':
        edit_k(ks)
    elif to_do == '6':
        save(truba, ks)
    elif to_do == '7':
        truba, ks = load()
    elif to_do == '8':
        search(truba,ks)
    elif to_do == "9":
        join_KS(truba, ks)
    elif to_do == '10':
        topological_sort_dfs(network)