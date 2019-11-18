#include <stdio.h>

// struct Person {
//     char name[20];
//     int sex;
//     int age;
//     double height;
//     double weight;
// };

// struct Person p; で定義できる


typedef struct Person {
    char name[20];
    int sex;
    int age;
    double height;
    double weight;
} person_s;
// person_s p; で定義できる

typedef struct {
    person_s boy;
    person_s girl;
    int month;
} couple_s;

typedef struct {
    double a;
    double b;
} sample_s;

int main(void) {

    // struct Person p;
    person_s p;

    person_s people[5] = {
        {"Bob",      'M', 19, 165.4, 72.5},
        {"Alice",    'F', 19, 161.7, 44.2},
        {"Tom",      'M', 20, 175.2, 66.3},
        {"Stefany",  'F', 18, 159.3, 48.5},
        {"Leonardo", 'M', 19, 172.8, 67.2}
    };

    couple_s cpl = {
        people[0],
        people[1],
        8
    };

    p.sex = 1;
    p.age = 10;
    p.height = 190;
    p.weight = 70;

    printf("%s %d %d %f %f\n", p.name, p.sex, p.age, p.height, p.weight);
    printf("%s %d %d %f %f\n", people[2].name, people[2].sex, people[2].age, people[2].height, people[2].weight);
    printf("%s %d %d %f %f\n", cpl.boy.name, cpl.boy.sex, cpl.boy.age, cpl.boy.height, cpl.boy.weight);
    printf("%s %d %d %f %f\n", cpl.girl.name, cpl.girl.sex, cpl.girl.age, cpl.girl.height, cpl.girl.weight);

    return 0;
}

