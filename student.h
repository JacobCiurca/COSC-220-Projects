#ifndef STUDENT_H
#define STUDENT_H


class student
{
    string fname, lname;
    int ID, yInSchool;
    double GPA;

public:
    student(){}
    student(string first, string last, int ident, int years, double grade){
        fname = first;
        lname = last;
        ID = ident;
        yInSchool = years;
        GPA = grade;
    }
    string getFirst(){
        return fname;
    }
    string getLast(){
        return lname;
    }
    int getID(){
        return ID;
    }
    int getYears(){
        return yInSchool;
    }
    double getGPA(){
        return GPA;
    }
    void setFirst(string f){
        fname = f;
    }
    void setLast(string l){
        lname = l;
    }
    void setID(int i){
        ID = i;
    }
    void setYears(int y){
        yInSchool = y;
    }
    void setGPA(double g){
        GPA = g;
    }
   friend ostream& operator<<(ostream& str, student s){
        str << s.getFirst() << "\t" << s.getLast() << "\t" << s.getID() << "\t" << s.getYears() << "\t" << s.getGPA() << endl;
        return str;
    }
    friend istream& operator >> (istream& str, student& stud){
        string first, last;
        int i, y;
        double g;
        str >> first;
        str >> last;
        str >> i;
        str >> y;
        str >> g;
        stud.setFirst(first);
        stud.setLast(last);
        stud.setID(i);
        stud.setYears(y);
        stud.setGPA(g);
        return str;
    }
     bool operator == (student& rhs){
        if(ID == rhs.getID()){
            return true;
        }
        else{
            return false;
        }
     };
};

#endif // STUDENT_H
