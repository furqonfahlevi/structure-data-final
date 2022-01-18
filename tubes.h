#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <iostream>
using namespace std;

#define info(P) (P)->info
#define infoChild(P) (P)->infoChild
#define next(P) (P)->next
#define nextChild(Q) (Q)->nextChild
#define prevChild(Q) (Q)->prevChild
#define first(L) (L).first
#define firstch(P) (P)->firstch
#define lastch(P) (P)->lastch

struct info_course
{
    string courseName, className, mhsType;
    int kuota, total;
};

struct info_mhs
{
    string mhsName, originClass, mhsType, nim;
};

typedef struct elm_mhs *adr_mhs;
struct elm_mhs
{
    info_mhs infoChild;
    adr_mhs nextChild, prevChild;
};

typedef struct elm_course *adr_course;
struct elm_course
{
    info_course info;
    adr_course next;
    adr_mhs firstch, lastch;
};

struct courseList
{
    adr_course first;
};

// Parent (Course)
void create_list(courseList &List);
void new_elm_course(info_course x, adr_course &C);
void inputCourse(courseList &List);
void insert_last_course(courseList &List, adr_course C);
void delete_first_course(courseList &List, adr_course &C);
void delete_last_course(courseList &List, adr_course &C);
void delete_after_course(courseList &List, adr_course Prec, adr_course &C);
void delete_course(courseList &List, string courseName, string className);
adr_course find_course(courseList List, string courseName, string className);
void show_data_course(courseList List);

// Child (Mahasiswa)
void new_elm_mhs(info_mhs x, adr_mhs &M);
void inputMhs(courseList &List);
void insert_last_mhs(courseList &List, adr_course C, adr_mhs M);
void show_data_mhs(adr_course C);
adr_mhs find_mahasiswa(courseList &List, adr_course C, string mhsName);
void delete_first_mhs(adr_mhs &M, adr_course &C);
void delete_after_mhs(adr_mhs &M, adr_mhs prec);
void delete_last_mhs(adr_mhs &M, adr_course C);
void delete_mahasiswa(courseList &List, string courseName, string className, string mhsName);

// Addition Procedure
void show_all(courseList List);
void show_mhs_based_mk(courseList List);
void delete_mhs_on_all_course(courseList List);
adr_course find_course_available(courseList List, string courseName);
void menu();
#endif // TUBES_H_INCLUDED
