#include <iostream>
#include "dnode.h"
#include "dlist.h"
#include "student.h"
#include <string>
#include <fstream>
using namespace std;

template <typename T>
void swapThem(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}
template <typename T>
    void LnameSort(dlist<T> list){
        dnode<T> *start;
        dnode<T> *ptr;
        bool swap;
        swap = false;
        start = list.begin();
        while(start->next != NULL){
                ptr = start->next;
                while(ptr->next != NULL){
            if((start->data).getLast() > (ptr->data).getLast()){
                swapThem(start->data, ptr->data);

            }
            ptr = ptr->next;
            }
            start = start->next;
        }
        swap = true;
        while(swap){
        cout << endl << "The students have been sorted by last name.\n";
        break;}
    }
    template <typename T>
    void view(dlist<T> list){
        cout << "|First| " << "|Last| " << "|ID| " << "|Years| " << "|GPA| " << endl;
        list.display();
    }
    template <typename T>
    void addStudent(dlist<T> list){
        student stud;
        cout << "Please enter the first name, last name, id number, years in school, and gpa.\n";
        cin >> stud;
        list.inser(stud);
    }
    template <typename T>
    void deleteStudent(dlist<T> list){
        cout << "Please enter the id of the student you would like to delete.\n";
        int i;
        cin >> i;
        student delS("", "", i, 0, 0);
        list.del(delS);
    }
    template <typename T>
    void searchStudent(dlist<T> list){
        cout << "Please enter the id of the student you would like to search for.\n";
        int i;
        cin >> i;
        student s("", "", i, 0, 0);
        list.searchList(s);
    }
int main()
{
    dlist <student> list;
    ofstream outputdata;
    ifstream inputData;
    inputData.open("StudentDatabase.txt");
    int StudentSize;
    student stud;
    inputData >> StudentSize;
    for(int i = 0; i < StudentSize; i++){
        inputData >> stud;
        list.inser(stud);
    }
    inputData.close();
    char input;
    while(input != 'Q'){
    cout << "==============================" << endl;
    cout << "Student Information Database Menu" << endl;
    cout << "==============================" << endl;
    cout << "V - View Student Information Database" << endl;
    cout << "F - Find Student Information by Student" << endl;
    cout << "S - Sort student" << endl;
    cout << "A - Add a student" << endl;
    cout << "D - Delete a student" << endl;
    cout << "Q - Quit the program" << endl;
    cout << "==============================" << endl;
    cin >> input;
    if(input == 'V'){
        view(list);
    }
    else if(input == 'F'){
            cout << "Vinny";
        searchStudent(list);
    }
    else if(input == 'S'){
        LnameSort(list);
    }
    else if(input == 'A'){
        cout << "Please enter a student to add.\n";
    }
    else if(input == 'D'){
        deleteStudent(list);
    }
    if(input == 'Q'){
        cout << "Thank you for using the Student Database. Have a nice Day!\n";
    }
    else{
        cout << "Incorrect choice! Please try again.\n";
    }
    }





    outputdata.open("StudentDatabase.txt");
    outputdata << list.getSize() << endl;
    dnode<student> *start;
    start = list.begin();
    for(int i = 0; i<list.getSize(); i++){
        outputdata << start->data;
        start = start->next;
    }


    return 0;
}
