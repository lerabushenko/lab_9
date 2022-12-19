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
    std::cout << "����:\n\n";
    std::cout << "1 - �������� ������ � ������.\n";
    std::cout << "2 - ����������.\n";
    std::cout << "3 - �����.\n";
    std::cout << "4 - ��������� ���������.\n";
    std::cout << "5 - �������� ���������.\n";
    std::cout << "6 - �����.\n";
    std::cout << "7 - ������ ��������� � ����.\n";
    std::cout << "8 - ������ �����.\n";
    std::cout << "9 - �����.\n";


    int choice = 0;
    bool IsCorrect;
    do {
        std::cout << "��� �����: ";
        IsCorrect = true;
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cin.clear();
            while (std::cin.get() != '\n');
            IsCorrect = false;
            std::cout << "����������� ��������� ��� ������ (�������� �������� ������ ���� ����� ������)\n\n";
        }
        if (IsCorrect && std::cin.get() != '\n') {
            std::cin.clear();
            while (std::cin.get() != '\n');

            std::cout << "������ �����, ������� korrektnoe �����\n\n";
            IsCorrect = false;
        }
        if (IsCorrect && (choice < 1 || choice>9)) {
            IsCorrect = false;
            std::cout << "������ �����, ������� ����� �� 0 �� 9\n\n";
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
        std::cout << "��� ����� ��� �������\n";
    }
    else
    {
        int choice = 0;
        do {
            std::cout << "\n������� �������: ";
            std::cin.getline(OnePerson[ammount].surname, 20);
            std::cout << "\n������� ���: ";
            std::cin.getline(OnePerson[ammount].name, 20);
            std::cout << "\n������� ��������: ";
            std::cin.getline(OnePerson[ammount].patronymic, 20);
            std::cout << "\n������� �����: ";
            std::cin.getline(OnePerson[ammount].adres, 20);
            std::cout << "\n������� ����� ��������: ";
            std::cin.getline(OnePerson[ammount].phonenumber, 20);
            std::cout << "\n������� �������: ";
            std::cin.getline(OnePerson[ammount].age, 20);
            std::cout << std::endl;
            ++ammount;
            std::cout << "������ ���������� ��������� �������� � ������?\n";
            std::cout << "1 - ��.\n";
            std::cout << "2 - ���.\n\n";
            bool IsCorrect;
            do {
                std::cout << "��� �����: ";
                IsCorrect = true;
                std::cin >> choice;
                if (std::cin.fail()) {
                    std::cin.clear();
                    while (std::cin.get() != '\n');
                    IsCorrect = false;
                    std::cout << "����������� ��������� ��� ������ (�������� �������� ������ ���� ����� ������)\n\n";
                }
                if (IsCorrect && std::cin.get() != '\n') {
                    std::cin.clear();
                    while (std::cin.get() != '\n');

                    std::cout << "������ �����, ������� korrektnoe �����\n\n";
                    IsCorrect = false;
                }
                if (IsCorrect && (choice < 1 || choice>2)) {
                    IsCorrect = false;
                    std::cout << "������ �����, ������� ����� 1 ��� 2\n\n";
                }
            } while (!IsCorrect);


            if (choice == 2) std::cout << "\n�� ��������� ��������� �������� � ������.\n\n";
        } while (choice != 2);
    }


    menu();
}

void search(person* OnePerson, int ammount) {
    if (ammount == 0) {
        std::cout << "\n��� �������.\n\n";
    }
    else {
        int localChoice = 0;
        int choice = 0;
        do {
            std::cout << "\n�������� �������� �� �������� ������ ������:\n\n";
            std::cout << "0 - ����� �� ������.\n";
            std::cout << "1 - �������.\n";
            std::cout << "2 - ���.\n";
            std::cout << "3 - ��������.\n";
            std::cout << "4 - �����.\n";
            std::cout << "5 - ����� ��������.\n";
            std::cout << "6 - �������.\n\n";
            bool IsCorrect;
            do {
                std::cout << "\n��� �����: ";
                IsCorrect = true;
                std::cin >> choice;
                if (std::cin.fail()) {
                    std::cin.clear();
                    while (std::cin.get() != '\n');
                    IsCorrect = false;
                    std::cout << "����������� ��������� ��� ������ (�������� �������� ������ ���� ����� ������)\n\n";
                }
                if (IsCorrect && std::cin.get() != '\n') {
                    std::cin.clear();
                    while (std::cin.get() != '\n');

                    std::cout << "������ �����, ������� korrektnoe �����\n\n";
                    IsCorrect = false;
                }
                if (IsCorrect && (choice < 0 || choice>6)) {
                    IsCorrect = false;
                    std::cout << "������ �����, ������� ����� �� 0 �� 6\n\n";
                }
            } while (!IsCorrect);


            bool search = false;
            switch (choice)
            {
            case 0: {
                std::cout << "\n�� ����� �� ������.\n\n";
                break;
            }
            case 1: {
                std::cout << "������� �������: ";
                char strToSearch[20];
                std::cin.getline(strToSearch, 20);
                for (int i = 0; i < ammount; ++i) {
                    if (!strcmp(OnePerson[i].surname, strToSearch)) {
                        std::cout << "\n������ �������!\n";
                        std::cout << "����� ������: " << i + 1 << "\n";
                        search = true;
                        break;
                    }
                }
                break;
            }
            case 2: {
                std::cout << "������� ���: ";
                char strToSearch[20];
                std::cin.getline(strToSearch, 20);
                for (int i = 0; i < ammount; ++i) {
                    if (!strcmp(OnePerson[i].name, strToSearch)) {
                        std::cout << "\n������ �������!\n";
                        std::cout << "����� ������: " << i + 1 << "\n";
                        search = true;
                        break;
                    }
                }
                break;
            }
            case 3: {
                std::cout << "������� ��������: ";
                char strToSearch[20];
                std::cin.getline(strToSearch, 20);
                for (int i = 0; i < ammount; ++i) {
                    if (!strcmp(OnePerson[i].patronymic, strToSearch)) {
                        std::cout << "\n������ �������!\n";
                        std::cout << "����� ������: " << i + 1 << "\n";
                        search = true;
                        break;
                    }
                }
                break;
            }
            case 4: {
                std::cout << "������� �����: ";
                char strToSearch[20];
                std::cin.getline(strToSearch, 20);
                for (int i = 0; i < ammount; ++i) {
                    if (!strcmp(OnePerson[i].adres, strToSearch)) {
                        std::cout << "\n������ �������!\n";
                        std::cout << "����� ������: " << i + 1 << "\n";
                        search = true;
                        break;
                    }
                }
                break;
            }
            case 5: {
                std::cout << "������� �������: ";
                char strToSearch[20];
                std::cin.getline(strToSearch, 20);
                for (int i = 0; i < ammount; ++i) {
                    if (!strcmp(OnePerson[i].phonenumber, strToSearch)) {
                        std::cout << "\n������ �������!\n";
                        std::cout << "����� ������: " << i + 1 << "\n";
                        search = true;
                        break;
                    }
                }
                break;
            }
            case 6: {
                std::cout << "������� �������: ";
                char strToSearch[20];
                std::cin.getline(strToSearch, 20);
                for (int i = 0; i < ammount; ++i) {
                    if (!strcmp(OnePerson[i].age, strToSearch)) {
                        std::cout << "\n������ �������!\n";
                        std::cout << "����� ������: " << i + 1 << "\n";
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
                std::cout << "\n������ � ����� ���������� ���.";
            }
            std::cout << "\n\n�� ������ ���������� �����?";
            std::cout << "\n1 - ��.";
            std::cout << "\n2- ���.";
            bool localIsCorrect;
            do {
                std::cout << "\n\n��� �����: ";
                localIsCorrect = true;
                std::cin >> localChoice;
                if (std::cin.fail()) {
                    std::cin.clear();
                    while (std::cin.get() != '\n');
                    localIsCorrect = false;
                    std::cout << "����������� ��������� ��� ������ (�������� �������� ������ ���� ����� ������)" << std::endl;
                }
                if (localIsCorrect && std::cin.get() != '\n') {
                    std::cin.clear();
                    while (std::cin.get() != '\n');

                    std::cout << "������ �����, ������� korrektnoe �����" << std::endl;
                    localIsCorrect = false;
                }
                if (localIsCorrect && (localChoice < 1 || localChoice>2)) {
                    localIsCorrect = false;
                    std::cout << "������ �����, ������� ����� 1 ��� 2" << std::endl;
                }
            } while (!localIsCorrect);
            if (localChoice == 2)
            {
                std::cout << "\n\n�� ������� ��������� �����.\n\n";
            }
        } while (localChoice != 2 && choice != 0);
    }


    menu();
}

void change(person* OnePerson, int ammount) {
    if (ammount == 0)
    {
        std::cout << "\n��� �������";
    }
    else
    {
        int choice = 0, positionToChange = 0, repeat = 0;
        bool IsCorrect;
        do {
            std::cout << "������� ����� ������, ������� ������ ��������: ";
            IsCorrect = true;
            std::cin >> choice;
            if (std::cin.fail()) {
                std::cin.clear();
                while (std::cin.get() != '\n');
                IsCorrect = false;
                std::cout << "����������� ��������� ��� ������ (�������� �������� ������ ���� ����� ������)\n\n";
            }
            if (IsCorrect && std::cin.get() != '\n') {
                std::cin.clear();
                while (std::cin.get() != '\n');

                std::cout << "������ �����, ������� korrektnoe �����\n\n";
                IsCorrect = false;
            }
            if (IsCorrect && (choice < 0 || choice>ammount)) {
                IsCorrect = false;
                std::cout << "������ �����, ������� ����� �� 0 �� " << ammount << "\n\n";
            }
        } while (!IsCorrect);


        do {
            std::cout << "\n1 - �������� �������.\n";
            std::cout << "2 - �������� ���.\n";
            std::cout << "3 - �������� ��������.\n";
            std::cout << "4 - �������� �����.\n";
            std::cout << "5 - �������� ����� ��������.\n";
            std::cout << "6 - �������� �������.\n";
            std::cout << "0 - �����.\n";
            do {
                std::cout << "��� �����: ";
                IsCorrect = true;
                std::cin >> positionToChange;
                if (std::cin.fail()) {
                    std::cin.clear();
                    while (std::cin.get() != '\n');
                    IsCorrect = false;
                    std::cout << "����������� ��������� ��� ������ (�������� �������� ������ ���� ����� ������)\n\n";
                }
                if (IsCorrect && std::cin.get() != '\n') {
                    std::cin.clear();
                    while (std::cin.get() != '\n');

                    std::cout << "������ �����, ������� korrektnoe �����\n\n";
                    IsCorrect = false;
                }
                if (IsCorrect && (positionToChange < 0 || positionToChange>6)) {
                    IsCorrect = false;
                    std::cout << "������ �����, ������� ����� �� 0 �� 6\n\n";
                }
            } while (!IsCorrect);

            switch (positionToChange)
            {
            case 1: {
                std::cout << "\n�������� ����� �������:";
                std::cin.clear();
                std::cin.getline(OnePerson[choice - 1].surname, 100);
                break;
            }
            case 2: {
                std::cout << "\n�������� ����� ���:";
                std::cin.clear();
                std::cin.getline(OnePerson[choice - 1].name, 100);
                break;
            }
            case 3: {
                std::cout << "\n�������� ����� ��������:";
                std::cin.clear();
                std::cin.getline(OnePerson[choice - 1].patronymic, 100);
                break;
            }
            case 4: {
                std::cout << "\n�������� ����� �����:";
                std::cin.clear();
                std::cin.getline(OnePerson[choice - 1].adres, 100);
                break;
            }
            case 5: {
                std::cout << "\n�������� ����� ����� ��������:";
                std::cin.clear();
                std::cin.getline(OnePerson[choice - 1].phonenumber, 100);
                break;
            }
            case 6: {
                std::cout << "\n�������� ����� �������:";
                std::cin.clear();
                std::cin.getline(OnePerson[choice - 1].age, 100);
                break;
            }
            default:
                std::cout << "\n\n�������� ����!\n\n";
                break;
            }

            std::cout << "\n������ ���������� �������� ������?\n";
            std::cout << "1 - ��.";
            std::cout << "\n2 - ���.\n\n";
            bool IsCorrect;
            do {
                std::cout << "��� �����: ";
                IsCorrect = true;
                std::cin >> repeat;
                if (std::cin.fail()) {
                    std::cin.clear();
                    while (std::cin.get() != '\n');
                    IsCorrect = false;
                    std::cout << "����������� ��������� ��� ������ (�������� �������� ������ ���� ����� ������)\n\n";
                }
                if (IsCorrect && std::cin.get() != '\n') {
                    std::cin.clear();
                    while (std::cin.get() != '\n');

                    std::cout << "������ �����, ������� korrektnoe �����\n\n";
                    IsCorrect = false;
                }
                if (IsCorrect && (repeat < 1 || repeat>2)) {
                    IsCorrect = false;
                    std::cout << "������ �����, ������� ����� 1 ��� 2\n\n";
                }
            } while (!IsCorrect);

            if (repeat == 2) {
                std::cout << "�� ��������� �������� ������.";
            }
        } while (repeat != 2 && positionToChange != 0);
    }

    menu();
}

void sort(person* OnePerson, int ammount) {
    if (ammount == 0) {
        std::cout << "��� �������.\n\n";
    }
    else
        if (ammount == 1) {
            std::cout << "���� ������.\n\n";
        }
        else {
            int choice = 0;
            int localChoice = 0;
            do {
                std::cout << "\n�� ������ ��������� �� ������ �������� ����������?\n";
                std::cout << "1 - �������.\n";
                std::cout << "2 - ���.\n";
                std::cout << "3 - ��������.\n";
                std::cout << "4 - �������� �����.\n";
                std::cout << "5 - ����� ��������.\n";
                std::cout << "6 - �������.\n";
                std::cout << "0 - ����� ����� �� ����������.\n";
                bool IsCorrect;
                do {
                    std::cout << "��� �����: ";
                    IsCorrect = true;
                    std::cin >> localChoice;
                    if (std::cin.fail()) {
                        std::cin.clear();
                        while (std::cin.get() != '\n');
                        IsCorrect = false;
                        std::cout << "����������� ��������� ��� ������ (�������� �������� ������ ���� ����� ������)\n\n";
                    }
                    if (IsCorrect && std::cin.get() != '\n') {
                        std::cin.clear();
                        while (std::cin.get() != '\n');

                        std::cout << "������ �����, ������� korrektnoe �����\n\n";
                        IsCorrect = false;
                    }
                    if (IsCorrect && (choice < 0 || choice>6)) {
                        IsCorrect = false;
                        std::cout << "������ �����, ������� ����� �� 0 �� 6\n\n";
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
                    std::cout << "������.\n";
                    break;
                }


                std::cout << "\n������ ���������� ����������?\n";
                std::cout << "1 - ��.\n";
                std::cout << "2 - ���.\n";
                bool localIsCorrect;
                do {
                    std::cout << "��� �����: ";
                    localIsCorrect = true;
                    std::cin >> choice;
                    if (std::cin.fail()) {
                        std::cin.clear();
                        while (std::cin.get() != '\n');
                        localIsCorrect = false;
                        std::cout << "����������� ��������� ��� ������ (�������� �������� ������ ���� ����� ������)\n\n";
                    }
                    if (localIsCorrect && std::cin.get() != '\n') {
                        std::cin.clear();
                        while (std::cin.get() != '\n');

                        std::cout << "������ �����, ������� korrektnoe �����\n\n";
                        localIsCorrect = false;
                    }
                    if (localIsCorrect && (choice < 1 || choice>2)) {
                        localIsCorrect = false;
                        std::cout << "������ �����, ������� ����� 1 ��� 2\n";
                    }
                } while (!localIsCorrect);
                if (choice == 2) {
                    std::cout << "\n�� ����� �� ����������\n";
                    menu();
                }
            } while (choice != 2 && localChoice != 0);
        }

    menu();
}

void output(person* OnePerson, int ammount) {
    system("cls");
    if (ammount == 0) {
        std::cout << "��� �������" << std::endl;
    }
    else {
        for (int i = 0; i < ammount; i++) {
            std::cout << "������ " << i + 1 << "\n";
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
        std::cout << "��� �������\n";
    }
    else {
        int choice = 0;
        std::cout << "0 - �����.\n";
        std::cout << "1 - ������� ���� ������.\n";
        std::cout << "2 - ������� ��� ������.\n";
        bool IsCorrect;
        do {
            std::cout << "��� �����: ";
            IsCorrect = true;
            std::cin >> choice;
            if (std::cin.fail()) {
                std::cin.clear();
                while (std::cin.get() != '\n');
                IsCorrect = false;
                std::cout << "����������� ��������� ��� ������ (�������� �������� ������ ���� ����� ������)\n\n";
            }
            if (IsCorrect && std::cin.get() != '\n') {
                std::cin.clear();
                while (std::cin.get() != '\n');

                std::cout << "������ �����, ������� korrektnoe �����\n\n";
                IsCorrect = false;
            }
            if (IsCorrect && (choice < 0 || choice>2)) {
                IsCorrect = false;
                std::cout << "������ �����, ������� ����� �� 0 �� 2\n\n";
            }
        } while (!IsCorrect);

        if (choice == 1) {
            int numberForDelete = 0;
            bool IsCorrect;
            do {
                std::cout << "������� ����� ������, ������� ������ �������: ";
                IsCorrect = true;
                std::cin >> numberForDelete;
                if (std::cin.fail()) {
                    std::cin.clear();
                    while (std::cin.get() != '\n');
                    IsCorrect = false;
                    std::cout << "����������� ��������� ��� ������ (�������� �������� ������ ���� ����� ������)\n\n";
                }
                if (IsCorrect && std::cin.get() != '\n') {
                    std::cin.clear();
                    while (std::cin.get() != '\n');

                    std::cout << "������ �����, ������� korrektnoe �����\n\n";
                    IsCorrect = false;
                }
                if (IsCorrect && (numberForDelete < 1 || numberForDelete>ammount)) {
                    IsCorrect = false;
                    std::cout << "������ �����, ������� ����� �� 0 �� " << ammount << "\n\n";
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
        std::cout << "��� �������\n";
    }
    else {
        std::ofstream fout("person.dat");
        if (!fout.is_open()) {
            std::cout << "���� �� ������!\n";
            return;
        }
        for (int i = 0; i < ammount; i++) {
            fout << "������ " << i + 1 << "\n";
            fout << OnePerson[i].surname << "\n";
            fout << OnePerson[i].name << "\n";
            fout << OnePerson[i].patronymic << "\n";
            fout << OnePerson[i].adres << "\n";
            fout << OnePerson[i].phonenumber << "\n";
            fout << OnePerson[i].age << "\n";
        }
        fout.close();
        std::cout << "�������� ������� ���������\n";
        readFile(OnePerson, ammount);
    }

    menu();
}

void printFile(person* OnePerson, int ammount) {
    if (ammount == 0) {
        std::cout << "��� �������\n";
    }
    else {
        system("cls");
        std::ifstream fin("person.dat");
        if (!fin.is_open()) {
            std::cout << "���� �� ������!\n";
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
        std::cout << "\n������ ����������� ���������� �����?\n";
        std::cout << "1 - ��.";
        std::cout << "\n2 - ���.\n\n";
        bool IsCorrect;
        do {
            std::cout << "��� �����: ";
            IsCorrect = true;
            std::cin >> choice;
            if (std::cin.fail()) {
                std::cin.clear();
                while (std::cin.get() != '\n');
                IsCorrect = false;
                std::cout << "����������� ��������� ��� ������ (�������� �������� ������ ���� ����� ������)\n\n";
            }
            if (IsCorrect && std::cin.get() != '\n') {
                std::cin.clear();
                while (std::cin.get() != '\n');

                std::cout << "������ �����, ������� korrektnoe �����\n\n";
                IsCorrect = false;
            }
            if (IsCorrect && (choice < 1 || choice>2)) {
                IsCorrect = false;
                std::cout << "������ �����, ������� ����� 1 ��� 2\n\n";
            }
        } while (!IsCorrect);

        if (choice == 1) {
            printFile(OnePerson, ammount);
            return;
        }
    } while (choice != 2);
}