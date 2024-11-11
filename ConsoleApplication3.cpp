#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student {
protected:
    string name;
    string surname;
    int age;
    string university;
    string group;
    int year;

public:
    Student(const string& name, const string& surname, int age, const string& university, const string& group, int year)
        : name(name), surname(surname), age(age), university(university), group(group), year(year) {}

    void displayInfo() const {
        cout << "Name: " << name << "\nSurname: " << surname << "\nAge: " << age
            << "\nUniversity: " << university << "\nGroup: " << group << "\nYear: " << year << endl;
    }
};

class Aspirant : public Student {
private:
    string researchTopic;

public:
    Aspirant(const string& name, const string& surname, int age, const string& university, const string& group, int year, const string& researchTopic)
        : Student(name, surname, age, university, group, year), researchTopic(researchTopic) {}

    void displayInfo() const {
        Student::displayInfo();
        cout << "Research Topic: " << researchTopic << endl;
    }
};

class Passport {
protected:
    string name;
    string surname;
    string ID;
    string birthDate;
    string birthPlace;
    string nationality;

public:
    Passport(const string& name, const string& surname, const string& ID, const string& birthDate, const string& birthPlace, const string& nationality)
        : name(name), surname(surname), ID(ID), birthDate(birthDate), birthPlace(birthPlace), nationality(nationality) {}

    void displayInfo() const {
        cout << "Name: " << name << "\nSurname: " << surname << "\nID: " << ID
            << "\nDate of Birth: " << birthDate << "\nPlace of Birth: " << birthPlace << "\nNationality: " << nationality << endl;
    }
};

class ForeignPassport : public Passport {
private:
    string foreignID;
    vector<string> visas;

public:
    ForeignPassport(const string& name, const string& surname, const string& ID, const string& birthDate, const string& birthPlace, const string& nationality, const string& foreignID)
        : Passport(name, surname, ID, birthDate, birthPlace, nationality), foreignID(foreignID) {}

    void addVisa(const string& visa) {
        visas.push_back(visa);
    }

    void displayInfo() const {
        Passport::displayInfo();
        cout << "Foreign Passport Number: " << foreignID << "\nVisas: ";
        for (const auto& visa : visas) {
            cout << visa << " ";
        }
        cout << endl;
    }
};

int main() {
    Aspirant aspirant("Maksim", "Pavlychuc", 16, "Bursa N10", "EM", 1, "Electro mechanic");
    aspirant.displayInfo();

    ForeignPassport foreignPassport("Andrii", "Bandera", "UA123456", "02112024", "Rivne", "Ukrainian", "GG83872");
    foreignPassport.addVisa("USA");
    foreignPassport.addVisa("Japan");
    foreignPassport.displayInfo();

    return 0;
}
