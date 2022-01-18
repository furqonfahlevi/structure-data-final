#include "tubes.h"

// Parent
void create_list(courseList &List)
{
    first(List) = NULL;
}

void new_elm_course(info_course x, adr_course &C)
{
    C = new elm_course;
    info(C) = x;
    firstch(C) = NULL;
    next(C) = NULL;
}

void inputCourse(courseList &List)
{
    info_course course;
    adr_course C;

    course.total = 0;

    cout << "Course name: ";
    cin >> course.courseName;
    cout << "Class name: ";
    cin >> course.className;
    cout << "Kuota: ";
    cin >> course.kuota;
    cout << "Student type (INT/REG): ";
    cin >> course.mhsType;
    new_elm_course(course, C);
    insert_last_course(List, C);
}

void insert_last_course(courseList &List, adr_course C)
{
    if (first(List) == NULL)
    {
        first(List) = C;
        next(C) = first(List);
    }
    else
    {
        adr_course P = first(List);
        while (next(P) != first(List))
        {
            P = next(P);
        }
        next(P) = C;
        next(C) = first(List);
    }
}

void delete_first_course(courseList &List, adr_course &C)
{
    adr_course q;

    if (first(List) == NULL)
    {
        cout << "Course empty.";
    }
    else if (next(first(List)) == first(List))
    {
        C = first(List);
        first(List) == NULL;
    }
    else
    {
        C = first(List);
        q = next(first(List));
        while (next(q) != C)
        {
            q = next(q);
        }
        next(q) = first(List);
        next(C) = NULL;
    }
}

void delete_last_course(courseList &List, adr_course &C)
{
    if (first(List) == NULL)
    {
        cout << "Course empty.";
    }
    else if (next(first(List)) == first(List))
    {
        C = first(List);
        first(List) == NULL;
    }
    else
    {
        adr_course q = first(List);
        while (next(next(q)) != first(List))
        {
            q = next(q);
        }
        C = next(q);
        next(q) = first(List);
    }
}

void delete_after_course(courseList &List, adr_course Prec, adr_course &C)
{
    C = next(Prec);
    next(Prec) = next(C);
    next(C) = NULL;
}

adr_course find_course(courseList List, string courseName, string className)
{
    adr_course C;
    C = first(List);
    if (first(List) == NULL)
    {
        return NULL;
    }
    else
    {
        while (next(C) != first(List))
        {
            if (info(C).courseName == courseName && info(C).className == className)
            {
                return C;
            }
            C = next(C);
        }
        if (info(C).courseName == courseName && info(C).className == className)
        {
            return C;
        }
        else
        {
            return NULL;
        }
    }
}

void delete_course(courseList &List, string courseName, string className)
{
    adr_course C, q, delData;
    C = find_course(List, courseName, className);
    if (C == NULL)
    {
        cout << "No course.";
    }
    else
    {
        if (C == first(List))
        {
            delete_first_course(List, delData);
        }
        else if (next(C) == first(List))
        {
            delete_last_course(List, delData);
        }
        else
        {
            q = first(List);
            while (next(q) != C)
            {
                q = next(q);
            }
            delete_after_course(List, q, delData);
        }
    }
}

void show_data_course(courseList List)
{
    adr_course P = first(List);
    while (next(P) != first(List))
    {
        cout << "----- " << info(P).courseName << " COURSE -----" << endl;
        cout << "Course name: ";
        cout << info(P).courseName;
        cout << endl;
        cout << "Class name: ";
        cout << info(P).className;
        cout << endl;
        cout << "Kuota: ";
        cout << info(P).kuota;
        cout << endl;
        cout << "Total: ";
        cout << info(P).total;
        cout << endl;
        cout << "Student type (INT/REG): ";
        cout << info(P).mhsType;
        cout << endl;
        P = next(P);
        cout << endl;
    }
    cout << "----- " << info(P).courseName << " COURSE -----" << endl;
    cout << "Course name: ";
    cout << info(P).courseName;
    cout << endl;
    cout << "Class name: ";
    cout << info(P).className;
    cout << endl;
    cout << "Kuota: ";
    cout << info(P).kuota;
    cout << endl;
    cout << "Total: ";
    cout << info(P).total;
    cout << endl;
    cout << "Student type (INT/REG): ";
    cout << info(P).mhsType;
    cout << endl;
    P = next(P);
    cout << endl;
}

// Child
void new_elm_mhs(info_mhs x, adr_mhs &M)
{
    M = new elm_mhs;
    infoChild(M) = x;
    nextChild(M) = NULL;
    prevChild(M) = NULL;
}

void insert_last_mhs(courseList &List, adr_course C, adr_mhs M)
{
    if (info(C).kuota > info(C).total)
    {
        if (info(C).mhsType == infoChild(M).mhsType)
        {
            if (firstch(C) == NULL)
            {
                firstch(C) = M;
                lastch(C) = M;
                info(C).total = 1;
            }
            else
            {
                nextChild(lastch(C)) = M;
                prevChild(M) = lastch(C);
                lastch(C) = M;
                info(C).total += 1;
            }
        }
        else
        {
            cout << "----- Class not match -----" << endl;
        }
    }
    else
    {
        cout << "----- Kuota full -----" << endl;
    }
}

void inputMhs(courseList &List)
{
    info_mhs mhs;
    adr_mhs M;
    adr_course C;
    string courseName, className;

    cout << "Student name: ";
    cin >> mhs.mhsName;
    cout << "NIM: ";
    cin >> mhs.nim;
    cout << "Origin class: ";
    cin >> mhs.originClass;
    cout << "Student type (INT/REG): ";
    cin >> mhs.mhsType;
    new_elm_mhs(mhs, M);
    cout << endl;
    cout << "Course taken: ";
    cin >> courseName;
    cout << "Class that course taken: ";
    cin >> className;
    C = find_course(List, courseName, className);
    insert_last_mhs(List, C, M);
    cout << endl;
}

void show_data_mhs(adr_course C)
{
    adr_mhs M;
    M = firstch(C);
    if (firstch(C) == NULL)
    {
        cout << endl;
        cout << "Data mhs empty." << endl;
    }
    else
    {
        cout << endl;
        cout << "----- STUDENT FROM " << info(C).courseName << " COURSE -----" << endl;
        while (M != NULL)
        {
            cout << endl;
            cout << "Mahasiswa name: ";
            cout << infoChild(M).mhsName;
            cout << endl;
            cout << "NIM: ";
            cout << infoChild(M).nim;
            cout << endl;
            cout << "Origin class: ";
            cout << infoChild(M).originClass;
            cout << endl;
            cout << "Student type (INT/REG): ";
            cout << infoChild(M).mhsType;
            cout << endl;
            M = nextChild(M);
        }
    }
}

adr_mhs find_mahasiswa(courseList &List, adr_course C, string mhsName)
{
    adr_mhs M;
    M = firstch(C);
    if (C == NULL)
    {
        return NULL;
    }
    else
    {
        if (firstch(C) == NULL)
        {
            return NULL;
        }
        else
        {
            while (nextChild(M) != NULL)
            {
                if (infoChild(M).mhsName == mhsName)
                {
                    return M;
                }
                M = nextChild(M);
            }
            if (infoChild(M).mhsName == mhsName)
            {
                return M;
            }
            else
            {
                return NULL;
            }
        }
    }
}

void delete_first_mhs(adr_mhs &M, adr_course &C)
{
    if (firstch(C) == NULL)
    {
        cout << "Data mahasiswa is empty." << endl;
    }
    else if (nextChild(M) == NULL)
    {
        firstch(C) = NULL;
    }
    else
    {
        M = firstch(C);
        firstch(C) = nextChild(M);
        nextChild(M) = NULL;
        prevChild(firstch(C)) = NULL;
    }
}

void delete_after_mhs(adr_mhs &M, adr_mhs prec)
{
    nextChild(prec) = M;
    nextChild(prec) = nextChild(M);
    prevChild(nextChild(M)) = prec;
    nextChild(M) = NULL;
    prevChild(M) = NULL;
}

void delete_last_mhs(adr_mhs &M, adr_course C)
{
    adr_mhs q;
    if (firstch(C) == NULL)
    {
        cout << "Data mahasiswa is empty." << endl;
    }
    else
    {
        q = firstch(C);
        while (nextChild(q) != lastch(C))
        {
            q = nextChild(q);
        }
        M = lastch(C);
        lastch(C) = q;
        nextChild(q) = NULL;
        prevChild(M) = NULL;
    }
}

void delete_mahasiswa(courseList &List, string courseName, string className, string mhsName)
{
    adr_course C;
    adr_mhs M, prec;
    C = find_course(List, courseName, className);
    M = find_mahasiswa(List, C, mhsName);
    if (M == NULL)
    {
        cout << "Data mahasiswa isn't found." << endl;
    }
    else
    {
        info(C).total -= 1;
        if (M == firstch(C))
        {
            delete_first_mhs(M, C);
        }
        else if (M == lastch(C))
        {
            delete_last_mhs(M, C);
        }
        else
        {
            prec = firstch(C);
            while (nextChild(prec) != M)
            {
                prec = nextChild(prec);
            }
            delete_after_mhs(M, prec);
        }
    }
}

// Addition Procedure
void show_all(courseList List)
{
    adr_course P = first(List);
    while (next(P) != first(List))
    {
        cout << "----- " << info(P).courseName << " COURSE -----" << endl;
        cout << "Course name: ";
        cout << info(P).courseName;
        cout << endl;
        cout << "Class name: ";
        cout << info(P).className;
        cout << endl;
        cout << "Kuota: ";
        cout << info(P).kuota;
        cout << endl;
        cout << "Total: ";
        cout << info(P).total;
        cout << endl;
        cout << "Student type (INT/REG): ";
        cout << info(P).mhsType;
        cout << endl;
        show_data_mhs(P);
        cout << endl;
        P = next(P);
        cout << endl;
    }
    cout << "----- COURSE OF " << info(P).courseName << " -----" << endl;
    cout << "Course name: ";
    cout << info(P).courseName;
    cout << endl;
    cout << "Class name: ";
    cout << info(P).className;
    cout << endl;
    cout << "Kuota: ";
    cout << info(P).kuota;
    cout << endl;
    cout << "Total: ";
    cout << info(P).total;
    cout << endl;
    cout << "Student type (INT/REG): ";
    cout << info(P).mhsType;
    cout << endl;
    show_data_mhs(P);
    cout << endl;
}

void show_mhs_based_mk(courseList List)
{
    adr_course C;
    string className, courseName;

    cout << "Which course mahasiswa/i wants to find? ";
    cin >> courseName;
    cout << "Class of the mahasiswa/i's course? ";
    cin >> className;
    C = (find_course(List, courseName, className));
    cout << endl;

    if (C != NULL)
    {
        cout << "----- " << info(C).courseName << " COURSE -----" << endl;
        cout << "Course name: ";
        cout << info(C).courseName;
        cout << endl;
        cout << "Class name: ";
        cout << info(C).className;
        cout << endl;
        cout << "Kuota: ";
        cout << info(C).kuota;
        cout << endl;
        cout << "Total: ";
        cout << info(C).total;
        cout << endl;
        cout << "Student type (INT/REG): ";
        cout << info(C).mhsType;
        cout << endl;
        show_data_mhs(C);
        cout << endl;
    }
    else
    {
        cout << "----- Course not found -----" << endl;
    }
}

void delete_mhs_on_all_course(courseList List)
{
    adr_course C;
    adr_mhs M;
    string mhsName;

    cout << "Delete mahasiswa/i on all course: ";
    cin >> mhsName;
    cout << endl;
    C = first(List);
    M = find_mahasiswa(List, C, mhsName);
    if (M != NULL)
    {
        delete_mahasiswa(List, info(C).courseName, info(C).className, mhsName);
        show_data_mhs(C);
    }
    C = next(C);
    while (C != first(List))
    {
        M = find_mahasiswa(List, C, mhsName);
        if (M != NULL)
        {
            delete_mahasiswa(List, info(C).courseName, info(C).className, mhsName);
            show_data_mhs(C);
        }
        C = next(C);
    }
}

adr_course find_course_available(courseList List, string courseName)
{
    adr_course C = first(List);
    while (next(C) != first(List))
    {
        if (courseName == info(C).courseName && info(C).kuota > info(C).total)
        {
            return C;
        }
        C = next(C);
    }
    if (courseName == info(C).courseName && info(C).kuota > info(C).total)
    {
        return C;
    }
    else
    {
        return NULL;
    }
}

void menu()
{
    cout << "==========================================" << endl;
    cout << "Course registration for short semester" << endl;
    cout << "1. Add course" << endl;
    cout << "2. Add mahasiswa/i" << endl;
    cout << "3. Delete course" << endl;
    cout << "4. Delete mahasiswa/i on all course" << endl;
    cout << "5. Delete course registration from certain mahasiswa/i" << endl;
    cout << "6. Show data mahasiswa/i from certain course and class" << endl;
    cout << "7. Show all course and mahasiswa/i" << endl;
    cout << "8. Show course and total mahasiswa/i" << endl;
    cout << "9. Find certain course that have available kuota" << endl;
    cout << "10. Find mahasiswa/i from certain course" << endl;
    cout << "==========================================" << endl;
    cout << "Choose one: ";
}