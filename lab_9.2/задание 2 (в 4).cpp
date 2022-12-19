#include <iostream>
#include <locale.h>
#include <Windows.h>
#include<string.h>               
#include <cstdlib>
#include<fstream>


struct person {
    char surname[20];
    char name[20];
    char patronymic[20];
    char adres[20];
    char phonenumber[20];
    char age[20];
};


person OnePerson[30];
int ammount = 0;
struct person nothing;


int menu();
void addNew();
void search(person* OnePerson, int ammount);
void change(person* OnePerson, int ammount);
void sort(person* OnePerson, int ammount);
void output(person* OnePerson, int ammount);
void del(person* OnePerson, int ammount);
void saveInFile(person* OnePerson, int ammount);
void printFile(person* OnePerson, int ammount);
void readFile(person* OnePerson, int ammount);


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    menu();
    return 0;
}

int menu() {
    std::cout << "Меню:\n\n";
    std::cout << "1 - Добавить запись в массив.\n";
    std::cout << "2 - Сортировка.\n";
    std::cout << "3 - Поиск.\n";
    std::cout << "4 - Изменение структуры.\n";
    std::cout << "5 - Удаление структуры.\n";
    std::cout << "6 - Вывод.\n";
    std::cout << "7 - Запись структуры в файл.\n";
    std::cout << "8 - Чтение файла.\n";
    std::cout << "9 - Выход.\n";


    int choice = 0;
    bool IsCorrect;
    do {
        std::cout << "Ваш выбор: ";
        IsCorrect = true;
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cin.clear();
            while (std::cin.get() != '\n');
            IsCorrect = false;
            std::cout << "Неправильно выбранный тип данных (входящий параметр должен быть целым числом)\n\n";
        }
        if (IsCorrect && std::cin.get() != '\n') {
            std::cin.clear();
            while (std::cin.get() != '\n');

            std::cout << "Ошибка ввода, введите korrektnoe число\n\n";
            IsCorrect = false;
        }
        if (IsCorrect && (choice < 1 || choice>9)) {
            IsCorrect = false;
            std::cout << "Ошибка ввода, введите число от 0 до 9\n\n";
        }
    } while (!IsCorrect);


    switch (choice)
    {
    case 1: {
        addNew();
        break;
    }case 2: {
        sort(OnePerson, ammount);
        break;
    }case 3: {
        search(OnePerson, ammount);
        break;
    }case 4: {
        change(OnePerson, ammount);
        break;
    }case 5: {
        del(OnePerson, ammount);
        break;
    }case 6: {
        output(OnePerson, ammount);
        break;
    }case 7: {
        saveInFile(OnePerson, ammount);
        break;
    }case 8:{
        printFile(OnePerson, ammount);
    }case 9: {
        return 0;
    }
    }
}

void addNew() {
    if (ammount == 30)
    {
        std::cout << "Нет места для записеи\n";
    }
    else
    {
        int choice = 0;
        do {
            std::cout << "\nВведите фамилию: ";
            std::cin.getline(OnePerson[ammount].surname, 20);
            std::cout << "\nВведите имя: ";
            std::cin.getline(OnePerson[ammount].name, 20);
            std::cout << "\nВведите отчество: ";
            std::cin.getline(OnePerson[ammount].patronymic, 20);
            std::cout << "\nВведите адрес: ";
            std::cin.getline(OnePerson[ammount].adres, 20);
            std::cout << "\nВведите номер телефона: ";
            std::cin.getline(OnePerson[ammount].phonenumber, 20);
            std::cout << "\nВведите возраст: ";
            std::cin.getline(OnePerson[ammount].age, 20);
            std::cout << std::endl;
            ++ammount;
            std::cout << "Хотите продолжить добавлять элементы в массив?\n";
            std::cout << "1 - Да.\n";
            std::cout << "2 - Нет.\n\n";
            bool IsCorrect;
            do {
                std::cout << "Ваш выбор: ";
                IsCorrect = true;
                std::cin >> choice;
                if (std::cin.fail()) {
                    std::cin.clear();
                    while (std::cin.get() != '\n');
                    IsCorrect = false;
                    std::cout << "Неправильно выбранный тип данных (входящий параметр должен быть целым числом)\n\n";
                }
                if (IsCorrect && std::cin.get() != '\n') {
                    std::cin.clear();
                    while (std::cin.get() != '\n');

                    std::cout << "Ошибка ввода, введите korrektnoe число\n\n";
                    IsCorrect = false;
                }
                if (IsCorrect && (choice < 1 || choice>2)) {
                    IsCorrect = false;
                    std::cout << "Ошибка ввода, введите число 1 или 2\n\n";
                }
            } while (!IsCorrect);


            if (choice == 2) std::cout << "\nВы закончили добавлять элементы в массив.\n\n";
        } while (choice != 2);
    }


    menu();
}

void search(person* OnePerson, int ammount) {
    if (ammount == 0) {
        std::cout << "\nНет записей.\n\n";
    }
    else {
        int localChoice = 0;
        int choice = 0;
        do {
            std::cout << "\nВыберите параметр по которому хотите искать:\n\n";
            std::cout << "0 - Выйти из поиска.\n";
            std::cout << "1 - Фамилия.\n";
            std::cout << "2 - Имя.\n";
            std::cout << "3 - Отчество.\n";
            std::cout << "4 - Адрес.\n";
            std::cout << "5 - Номер телефона.\n";
            std::cout << "6 - Возраст.\n\n";
            bool IsCorrect;
            do {
                std::cout << "\nВаш выбор: ";
                IsCorrect = true;
                std::cin >> choice;
                if (std::cin.fail()) {
                    std::cin.clear();
                    while (std::cin.get() != '\n');
                    IsCorrect = false;
                    std::cout << "Неправильно выбранный тип данных (входящий параметр должен быть целым числом)\n\n";
                }
                if (IsCorrect && std::cin.get() != '\n') {
                    std::cin.clear();
                    while (std::cin.get() != '\n');

                    std::cout << "Ошибка ввода, введите korrektnoe число\n\n";
                    IsCorrect = false;
                }
                if (IsCorrect && (choice < 0 || choice>6)) {
                    IsCorrect = false;
                    std::cout << "Ошибка ввода, введите число от 0 до 6\n\n";
                }
            } while (!IsCorrect);


            bool search = false;
            switch (choice)
            {
            case 0: {
                std::cout << "\nВы вышли из поиска.\n\n";
                break;
            }
            case 1: {
                std::cout << "Введите фамилию: ";
                char strToSearch[20];
                std::cin.getline(strToSearch, 20);
                for (int i = 0; i < ammount; ++i) {
                    if (!strcmp(OnePerson[i].surname, strToSearch)) {
                        std::cout << "\nЗапись найдена!\n";
                        std::cout << "Номер записи: " << i + 1 << "\n";
                        search = true;
                        break;
                    }
                }
                break;
            }
            case 2: {
                std::cout << "Введите имя: ";
                char strToSearch[20];
                std::cin.getline(strToSearch, 20);
                for (int i = 0; i < ammount; ++i) {
                    if (!strcmp(OnePerson[i].name, strToSearch)) {
                        std::cout << "\nЗапись найдена!\n";
                        std::cout << "Номер записи: " << i + 1 << "\n";
                        search = true;
                        break;
                    }
                }
                break;
            }
            case 3: {
                std::cout << "Введите отчество: ";
                char strToSearch[20];
                std::cin.getline(strToSearch, 20);
                for (int i = 0; i < ammount; ++i) {
                    if (!strcmp(OnePerson[i].patronymic, strToSearch)) {
                        std::cout << "\nЗапись найдена!\n";
                        std::cout << "Номер записи: " << i + 1 << "\n";
                        search = true;
                        break;
                    }
                }
                break;
            }
            case 4: {
                std::cout << "Введите адрес: ";
                char strToSearch[20];
                std::cin.getline(strToSearch, 20);
                for (int i = 0; i < ammount; ++i) {
                    if (!strcmp(OnePerson[i].adres, strToSearch)) {
                        std::cout << "\nЗапись найдена!\n";
                        std::cout << "Номер записи: " << i + 1 << "\n";
                        search = true;
                        break;
                    }
                }
                break;
            }
            case 5: {
                std::cout << "Введите телефон: ";
                char strToSearch[20];
                std::cin.getline(strToSearch, 20);
                for (int i = 0; i < ammount; ++i) {
                    if (!strcmp(OnePerson[i].phonenumber, strToSearch)) {
                        std::cout << "\nЗапись найдена!\n";
                        std::cout << "Номер записи: " << i + 1 << "\n";
                        search = true;
                        break;
                    }
                }
                break;
            }
            case 6: {
                std::cout << "Введите возраст: ";
                char strToSearch[20];
                std::cin.getline(strToSearch, 20);
                for (int i = 0; i < ammount; ++i) {
                    if (!strcmp(OnePerson[i].age, strToSearch)) {
                        std::cout << "\nЗапись найдена!\n";
                        std::cout << "Номер записи: " << i + 1 << "\n";
                        search = true;
                        break;
                    }
                }
                break;
            }
            default:
                break;
            }
            if (!search) {
                std::cout << "\nЗаписи с таким параметром нет.";
            }
            std::cout << "\n\nВы хотите продолжить поиск?";
            std::cout << "\n1 - Да.";
            std::cout << "\n2- Нет.";
            bool localIsCorrect;
            do {
                std::cout << "\n\nВаш выбор: ";
                localIsCorrect = true;
                std::cin >> localChoice;
                if (std::cin.fail()) {
                    std::cin.clear();
                    while (std::cin.get() != '\n');
                    localIsCorrect = false;
                    std::cout << "Неправильно выбранный тип данных (входящий параметр должен быть целым числом)" << std::endl;
                }
                if (localIsCorrect && std::cin.get() != '\n') {
                    std::cin.clear();
                    while (std::cin.get() != '\n');

                    std::cout << "Ошибка ввода, введите korrektnoe число" << std::endl;
                    localIsCorrect = false;
                }
                if (localIsCorrect && (localChoice < 1 || localChoice>2)) {
                    localIsCorrect = false;
                    std::cout << "Ошибка ввода, введите число 1 или 2" << std::endl;
                }
            } while (!localIsCorrect);
            if (localChoice == 2)
            {
                std::cout << "\n\nВы успешно завершили поиск.\n\n";
            }
        } while (localChoice != 2 && choice != 0);
    }


    menu();
}

void change(person* OnePerson, int ammount) {
    if (ammount == 0)
    {
        std::cout << "\nНет записей";
    }
    else
    {
        int choice = 0, positionToChange = 0, repeat = 0;
        bool IsCorrect;
        do {
            std::cout << "Введите номер записи, которую хотите изменить: ";
            IsCorrect = true;
            std::cin >> choice;
            if (std::cin.fail()) {
                std::cin.clear();
                while (std::cin.get() != '\n');
                IsCorrect = false;
                std::cout << "Неправильно выбранный тип данных (входящий параметр должен быть целым числом)\n\n";
            }
            if (IsCorrect && std::cin.get() != '\n') {
                std::cin.clear();
                while (std::cin.get() != '\n');

                std::cout << "Ошибка ввода, введите korrektnoe число\n\n";
                IsCorrect = false;
            }
            if (IsCorrect && (choice < 0 || choice>ammount)) {
                IsCorrect = false;
                std::cout << "Ошибка ввода, введите число от 0 до " << ammount << "\n\n";
            }
        } while (!IsCorrect);


        do {
            std::cout << "\n1 - Изменить фамилию.\n";
            std::cout << "2 - Изменить имя.\n";
            std::cout << "3 - Изменить отчество.\n";
            std::cout << "4 - Изменить адрес.\n";
            std::cout << "5 - Изменить номер телефона.\n";
            std::cout << "6 - Изменить возраст.\n";
            std::cout << "0 - Выход.\n";
            do {
                std::cout << "Ваш выбор: ";
                IsCorrect = true;
                std::cin >> positionToChange;
                if (std::cin.fail()) {
                    std::cin.clear();
                    while (std::cin.get() != '\n');
                    IsCorrect = false;
                    std::cout << "Неправильно выбранный тип данных (входящий параметр должен быть целым числом)\n\n";
                }
                if (IsCorrect && std::cin.get() != '\n') {
                    std::cin.clear();
                    while (std::cin.get() != '\n');

                    std::cout << "Ошибка ввода, введите korrektnoe число\n\n";
                    IsCorrect = false;
                }
                if (IsCorrect && (positionToChange < 0 || positionToChange>6)) {
                    IsCorrect = false;
                    std::cout << "Ошибка ввода, введите число от 0 до 6\n\n";
                }
            } while (!IsCorrect);

            switch (positionToChange)
            {
            case 1: {
                std::cout << "\nВведдите новую фамилию:";
                std::cin.clear();
                std::cin.getline(OnePerson[choice - 1].surname, 100);
                break;
            }
            case 2: {
                std::cout << "\nВведдите новое имя:";
                std::cin.clear();
                std::cin.getline(OnePerson[choice - 1].name, 100);
                break;
            }
            case 3: {
                std::cout << "\nВведдите новое отчество:";
                std::cin.clear();
                std::cin.getline(OnePerson[choice - 1].patronymic, 100);
                break;
            }
            case 4: {
                std::cout << "\nВведдите новый адрес:";
                std::cin.clear();
                std::cin.getline(OnePerson[choice - 1].adres, 100);
                break;
            }
            case 5: {
                std::cout << "\nВведдите новый носер телефона:";
                std::cin.clear();
                std::cin.getline(OnePerson[choice - 1].phonenumber, 100);
                break;
            }
            case 6: {
                std::cout << "\nВведдите новый возраст:";
                std::cin.clear();
                std::cin.getline(OnePerson[choice - 1].age, 100);
                break;
            }
            default:
                std::cout << "\n\nНеверный ввод!\n\n";
                break;
            }

            std::cout << "\nХотите продолжить изменять записи?\n";
            std::cout << "1 - Да.";
            std::cout << "\n2 - Нет.\n\n";
            bool IsCorrect;
            do {
                std::cout << "Ваш выбор: ";
                IsCorrect = true;
                std::cin >> repeat;
                if (std::cin.fail()) {
                    std::cin.clear();
                    while (std::cin.get() != '\n');
                    IsCorrect = false;
                    std::cout << "Неправильно выбранный тип данных (входящий параметр должен быть целым числом)\n\n";
                }
                if (IsCorrect && std::cin.get() != '\n') {
                    std::cin.clear();
                    while (std::cin.get() != '\n');

                    std::cout << "Ошибка ввода, введите korrektnoe число\n\n";
                    IsCorrect = false;
                }
                if (IsCorrect && (repeat < 1 || repeat>2)) {
                    IsCorrect = false;
                    std::cout << "Ошибка ввода, введите число 1 или 2\n\n";
                }
            } while (!IsCorrect);

            if (repeat == 2) {
                std::cout << "Вы закончили изменять записи.";
            }
        } while (repeat != 2 && positionToChange != 0);
    }

    menu();
}

void sort(person* OnePerson, int ammount) {
    if (ammount == 0) {
        std::cout << "Нет записей.\n\n";
    }
    else
        if (ammount == 1) {
            std::cout << "Одна запись.\n\n";
        }
        else {
            int choice = 0;
            int localChoice = 0;
            do {
                std::cout << "\nПо какому параметру вы хотите провести сортировку?\n";
                std::cout << "1 - Фамилия.\n";
                std::cout << "2 - Имя.\n";
                std::cout << "3 - Отчество.\n";
                std::cout << "4 - Домашний адрес.\n";
                std::cout << "5 - Номер телефона.\n";
                std::cout << "6 - Возраст.\n";
                std::cout << "0 - Чтобы выйти из сортировки.\n";
                bool IsCorrect;
                do {
                    std::cout << "Ваш выбор: ";
                    IsCorrect = true;
                    std::cin >> localChoice;
                    if (std::cin.fail()) {
                        std::cin.clear();
                        while (std::cin.get() != '\n');
                        IsCorrect = false;
                        std::cout << "Неправильно выбранный тип данных (входящий параметр должен быть целым числом)\n\n";
                    }
                    if (IsCorrect && std::cin.get() != '\n') {
                        std::cin.clear();
                        while (std::cin.get() != '\n');

                        std::cout << "Ошибка ввода, введите korrektnoe число\n\n";
                        IsCorrect = false;
                    }
                    if (IsCorrect && (choice < 0 || choice>6)) {
                        IsCorrect = false;
                        std::cout << "Ошибка ввода, введите число от 0 до 6\n\n";
                    }
                } while (!IsCorrect);


                switch (localChoice) {
                case 0:
                    break;
                case 1: {
                    struct person vspom;
                    for (int i = 0; i < ammount - 1; ++i) {
                        for (int j = i + 1; j < ammount; ++j) {
                            if (strcmp(OnePerson[i].surname, OnePerson[j].surname) > 0) {
                                vspom = OnePerson[i];
                                OnePerson[i] = OnePerson[j];
                                OnePerson[j] = vspom;
                            }
                        }
                    }
                    break;
                }
                case 2: {
                    struct person vspom;
                    for (int i = 0; i < ammount - 1; ++i) {
                        for (int j = i + 1; j < ammount; ++j) {
                            if (strcmp(OnePerson[i].name, OnePerson[j].name) > 0) {
                                vspom = OnePerson[i];
                                OnePerson[i] = OnePerson[j];
                                OnePerson[j] = vspom;
                            }
                        }
                    }
                    break;
                }
                case 3: {
                    struct person vspom;
                    for (int i = 0; i < ammount - 1; ++i) {
                        for (int j = i + 1; j < ammount; ++j) {
                            if (strcmp(OnePerson[i].patronymic, OnePerson[j].patronymic) > 0) {
                                vspom = OnePerson[i];
                                OnePerson[i] = OnePerson[j];
                                OnePerson[j] = vspom;
                            }
                        }
                    }
                    break;
                }
                case 4: {
                    struct person vspom;
                    for (int i = 0; i < ammount - 1; ++i) {
                        for (int j = i + 1; j < ammount; ++j) {
                            if (strcmp(OnePerson[i].adres, OnePerson[j].adres) > 0) {
                                vspom = OnePerson[i];
                                OnePerson[i] = OnePerson[j];
                                OnePerson[j] = vspom;
                            }
                        }
                    }
                    break;
                }
                case 5: {
                    struct person vspom;
                    for (int i = 0; i < ammount - 1; ++i) {
                        for (int j = i + 1; j < ammount; ++j) {
                            if (strcmp(OnePerson[i].phonenumber, OnePerson[j].phonenumber) > 0) {
                                vspom = OnePerson[i];
                                OnePerson[i] = OnePerson[j];
                                OnePerson[j] = vspom;
                            }
                        }
                    }
                    break;
                }
                case 6: {
                    struct person vspom;
                    for (int i = 0; i < ammount - 1; ++i) {
                        for (int j = i + 1; j < ammount; ++j) {
                            if (strcmp(OnePerson[i].age, OnePerson[j].age) > 0) {
                                vspom = OnePerson[i];
                                OnePerson[i] = OnePerson[j];
                                OnePerson[j] = vspom;
                            }
                        }
                    }
                    break;
                }
                default:
                    std::cout << "Ошибка.\n";
                    break;
                }


                std::cout << "\nХотите продолжить сортировку?\n";
                std::cout << "1 - Да.\n";
                std::cout << "2 - Нет.\n";
                bool localIsCorrect;
                do {
                    std::cout << "Ваш выбор: ";
                    localIsCorrect = true;
                    std::cin >> choice;
                    if (std::cin.fail()) {
                        std::cin.clear();
                        while (std::cin.get() != '\n');
                        localIsCorrect = false;
                        std::cout << "Неправильно выбранный тип данных (входящий параметр должен быть целым числом)\n\n";
                    }
                    if (localIsCorrect && std::cin.get() != '\n') {
                        std::cin.clear();
                        while (std::cin.get() != '\n');

                        std::cout << "Ошибка ввода, введите korrektnoe число\n\n";
                        localIsCorrect = false;
                    }
                    if (localIsCorrect && (choice < 1 || choice>2)) {
                        localIsCorrect = false;
                        std::cout << "Ошибка ввода, введите число 1 или 2\n";
                    }
                } while (!localIsCorrect);
                if (choice == 2) {
                    std::cout << "\nВы вышли из сортировки\n";
                    menu();
                }
            } while (choice != 2 && localChoice != 0);
        }

    menu();
}

void output(person* OnePerson, int ammount) {
    system("cls");
    if (ammount == 0) {
        std::cout << "Нет записей" << std::endl;
    }
    else {
        for (int i = 0; i < ammount; i++) {
            std::cout << "Запись " << i + 1 << "\n";
            std::cout << OnePerson[i].surname << "\n";
            std::cout << OnePerson[i].name << "\n";
            std::cout << OnePerson[i].patronymic << "\n";
            std::cout << OnePerson[i].adres << "\n";
            std::cout << OnePerson[i].phonenumber << "\n";
            std::cout << OnePerson[i].age << "\n\n";
        }
    }


    menu();
}

void del(person* OnePerson, int ammount) {
    if (ammount == 0) {
        std::cout << "Нет записей\n";
    }
    else {
        int choice = 0;
        std::cout << "0 - Выход.\n";
        std::cout << "1 - Удалить одну запись.\n";
        std::cout << "2 - Удалить все записи.\n";
        bool IsCorrect;
        do {
            std::cout << "Ваш выбор: ";
            IsCorrect = true;
            std::cin >> choice;
            if (std::cin.fail()) {
                std::cin.clear();
                while (std::cin.get() != '\n');
                IsCorrect = false;
                std::cout << "Неправильно выбранный тип данных (входящий параметр должен быть целым числом)\n\n";
            }
            if (IsCorrect && std::cin.get() != '\n') {
                std::cin.clear();
                while (std::cin.get() != '\n');

                std::cout << "Ошибка ввода, введите korrektnoe число\n\n";
                IsCorrect = false;
            }
            if (IsCorrect && (choice < 0 || choice>2)) {
                IsCorrect = false;
                std::cout << "Ошибка ввода, введите число от 0 до 2\n\n";
            }
        } while (!IsCorrect);

        if (choice == 1) {
            int numberForDelete = 0;
            bool IsCorrect;
            do {
                std::cout << "Введите номер записи, которую хотите удалить: ";
                IsCorrect = true;
                std::cin >> numberForDelete;
                if (std::cin.fail()) {
                    std::cin.clear();
                    while (std::cin.get() != '\n');
                    IsCorrect = false;
                    std::cout << "Неправильно выбранный тип данных (входящий параметр должен быть целым числом)\n\n";
                }
                if (IsCorrect && std::cin.get() != '\n') {
                    std::cin.clear();
                    while (std::cin.get() != '\n');

                    std::cout << "Ошибка ввода, введите korrektnoe число\n\n";
                    IsCorrect = false;
                }
                if (IsCorrect && (numberForDelete < 1 || numberForDelete>ammount)) {
                    IsCorrect = false;
                    std::cout << "Ошибка ввода, введите число от 0 до " << ammount << "\n\n";
                }
            } while (!IsCorrect);

            for (int i = numberForDelete; i < ammount; i++) {
                OnePerson[i - 1] = OnePerson[i];
            }
            ammount--;
        }
        if (choice == 2) {
            for (int i = 0; i < ammount; ++i)
            {
                OnePerson[i] = nothing;
            }
            ammount = 0;
        }
    }
    menu();
}

void saveInFile(person * OnePerson, int ammount) {         
    if (ammount == 0) {
        std::cout << "Нет записей\n";
    }
    else {
        std::ofstream fout("person.dat");
        if (!fout.is_open()) {
            std::cout << "Файл не открыт!\n";
            return;
        }
        for (int i = 0; i < ammount; i++) {
            fout << "Запись " << i + 1 << "\n";
            fout << OnePerson[i].surname << "\n";
            fout << OnePerson[i].name << "\n";
            fout << OnePerson[i].patronymic << "\n";
            fout << OnePerson[i].adres << "\n";
            fout << OnePerson[i].phonenumber << "\n";
            fout << OnePerson[i].age << "\n";
        }
        fout.close();
        std::cout << "Действие успешно завершено\n";
        readFile(OnePerson, ammount);
    }

    menu();
}

void printFile(person* OnePerson, int ammount) {
    if (ammount == 0) {
        std::cout << "Нет записей\n";
    }
    else {
        system("cls");
        std::ifstream fin("person.dat");
        if (!fin.is_open()) {
            std::cout << "Файл не открыт!\n";
            return;
        }
        char buff[50];
        for (int i = 0; i < 7 * ammount; i++) {
            fin.getline(buff, 50);
            std::cout << buff << "\n";
        }
        fin.close();
    }

    menu();
}

void readFile(person* OnePerson, int ammount) {
    int choice = 0;
    do {
        std::cout << "\nХотите просмотреть содержимое файла?\n";
        std::cout << "1 - Да.";
        std::cout << "\n2 - Нет.\n\n";
        bool IsCorrect;
        do {
            std::cout << "Ваш выбор: ";
            IsCorrect = true;
            std::cin >> choice;
            if (std::cin.fail()) {
                std::cin.clear();
                while (std::cin.get() != '\n');
                IsCorrect = false;
                std::cout << "Неправильно выбранный тип данных (входящий параметр должен быть целым числом)\n\n";
            }
            if (IsCorrect && std::cin.get() != '\n') {
                std::cin.clear();
                while (std::cin.get() != '\n');

                std::cout << "Ошибка ввода, введите korrektnoe число\n\n";
                IsCorrect = false;
            }
            if (IsCorrect && (choice < 1 || choice>2)) {
                IsCorrect = false;
                std::cout << "Ошибка ввода, введите число 1 или 2\n\n";
            }
        } while (!IsCorrect);

        if (choice == 1) {
            printFile(OnePerson, ammount);
            return;
        }
    } while (choice != 2);
}