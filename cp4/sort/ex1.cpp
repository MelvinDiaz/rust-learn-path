#include <bits/stdc++.h>
using namespace std;

struct Person{
    string name;
    int age;
    string lastName;
};

bool compareByAge(const Person &a, const Person &b){
    return a.age < b.age;
}

int main(){

    vector<Person> people;
    int n;
    cout << "How many people are you going to enter: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        Person p;
        cout << "Enter the name of the person: ";
        cin >> p.name;
        cout << "Enter the last name of the person: ";
        cin >> p.lastName;
        cout << "Enter the age of the person: ";
        cin >> p.age;
        people.push_back(p);
    }

    cout << "People: " << endl;
    sort(people.begin(), people.end(), compareByAge);

    for(auto x: people)
        cout << x.name << " " << x.lastName << " " << x.age << endl;

    return 0;
}
