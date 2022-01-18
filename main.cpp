#include <iostream>

#include "tubes.h"

using namespace std;

int main()
{
    courseList L;
    adr_course C, F;
    adr_mhs M, prec, delData;
    string className, courseName, mhsName;
    string chooseOne, choose1;
    int chooseNumber;

    create_list(L);
    chooseOne = "y";
    while (chooseOne == "y" || chooseOne == "Y")
    {
        cout << endl;
        menu();
        cin >> chooseNumber;
        cout << endl;
        if (chooseNumber == 1)
        {
            cout << "====ADD NEW COURSE====" << endl;
            cout << "======Fill without space======" << endl;
            inputCourse(L);
            cout << endl;
        }
        else if (chooseNumber == 2)
        {
            cout << " ====ADD NEW MAHASISWA/I==== " << endl;
            cout << "======Fill without space======" << endl;
            inputMhs(L);
            cout << endl;
        }
        else if (chooseNumber == 3)
        {
            cout << "====DELETE COURSE====" << endl;
            cout << "======Fill without space======" << endl;
            cout << "Course name: ";
            cin >> courseName;
            cout << "Class of the course: ";
            cin >> className;
            delete_course(L, courseName, className);
            cout << endl;
        }
        else if (chooseNumber == 4)
        {
            cout << "====DELETE MAHASISWA/I ON ALL COURSE====" << endl;
            cout << "======Fill without space======" << endl;
            delete_mhs_on_all_course(L);
            cout << endl;
        }
        else if (chooseNumber == 5)
        {
            cout << "====DELETE COURSE REGISTRATION FROM CERTAIN MAHASISWA/I====" << endl;
            cout << "======Fill without space======" << endl;
            cout << "Mahasiswa/i name: ";
            cin >> mhsName;
            cout << "Course mahasiswa/I: ";
            cin >> courseName;
            cout << "Class of the course: ";
            cin >> className;
            delete_mahasiswa(L, courseName, className, mhsName);
            cout << endl;
        }
        else if (chooseNumber == 6)
        {
            cout << "====SHOW DATA MAHASISWA/I FROM CERTAIN COURSE AND CLASS====" << endl;
            show_mhs_based_mk(L);
            cout << endl;
        }
        else if (chooseNumber == 7)
        {
            cout << "====SHOW ALL COURSE AND MAHASISWA/I====" << endl;
            show_all(L);
            cout << endl;
        }
        else if (chooseNumber == 8)
        {
            cout << "====SHOW ALL COURSE AND MAHASISWA/I====" << endl;
            show_data_course(L);
            cout << endl;
        }
        else if (chooseNumber == 9)
        {
            cout << "====FIND CERTAIN COURSE THAT HAVE AVAILABLE KUOTA====" << endl;
            cout << "======Fill without space======" << endl;
            cout << "Course name: ";
            cin >> courseName;
            F = find_course_available(L, courseName);
            if (F != NULL)
            {
                cout << "Course name: " << info(F).courseName << endl;
                cout << "Class name: " << info(F).className << endl;
                cout << "Kuota: " << info(F).kuota << endl;
                cout << "Total: " << info(F).total << endl;
                cout << "INT/REG: " << info(F).mhsType << endl;
            }
            else
            {
                cout << "Kuota is full" << endl;
            }
        }
        else if (chooseNumber = 10)
        {
            cout << "====FIND MAHASISWA/I FROM CERTAIN COURSE====" << endl;
            cout << "======Fill without space======" << endl;
            cout << "Course mahasiswa/I: ";
            cin >> courseName;
            cout << "Class of the course: ";
            cin >> className;
            C = find_course(L, courseName, className);
            cout << "Mahasiswa/i name: ";
            cin >> mhsName;
            M = find_mahasiswa(L, C, mhsName);
            if (M != NULL)
            {
                cout << "Mahasiswa/i name: " << infoChild(M).mhsName << endl;
                cout << "NIM: " << infoChild(M).nim << endl;
            }
            else
            {
                cout << "Mahasiswa/i isn't taken this course" << endl;
            }
        }
        else
        {
            cout << "Options isn't available ";
            cout << endl;
            cout << endl;
        }
        cout << "BACK TO MENU ?(Y/T) : ";
        cin >> choose1;
        chooseOne = choose1;
    }
    cout << endl;
    cout << "THANK YOU!!!" << endl;
    cout << "KELOMPOK dudu gang : " << endl;
    cout << "1. Ditya Athallah (1301194095)" << endl;
    cout << "2. Muhammad Furqon Fahlevi (1301194214)" << endl;
}