#include <stdio.h>

typedef struct {
    double a;
    double b;
} sample_s;

void printFormula( sample_s f ) {
    printf("%.3lf x + %.3lf\n", f.a, f.b);
}

sample_s addFormula (sample_s f1, sample_s f2) {
    sample_s f3;
    f3.a = f1.a + f2.a;
    f3.b = f1.b + f2.b;

    return f3;
}

void addFormulaPtr(sample_s *f1, sample_s *f2, sample_s *f3) {
    (*f3).a = (*f1).a + (*f2).a;
    (*f3).b = (*f1).b + (*f2).b;

    // f3->a = f1->a + f2->a;
    // f3->b = f1->b + f2->b;
}

int main ( void ) {

    // 1, 2どちらの初期化方法でも良い

    // 1
    // sample_s f = { 3.5, 2.0 };

    // 2
    // sample_s f;
    // f.a = 3.5;
    // f.b = 2.0;

    sample_s f1 = { 5.0, 1.0 };
    sample_s f2 = { 3.3, 1.5 };
    sample_s f3;

    f3 = addFormula(f1, f2);
    printFormula(f3);

    sample_s f4;

    addFormulaPtr(&f1, &f2, &f4);
    printFormula(f4);

    // addFormulaPtr(&f1, &f2, &f3);
    // printFormula(f3);

    return 0;
}
