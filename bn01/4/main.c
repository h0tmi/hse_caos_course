void print_args();

void bar(int a);
void foo() {
    int v = 2123123;
    print_args();
    int n = 2123123;
}
int main() {
    int a = 2123123;
    bar(a);
}

void bar(int a) {
    foo();
}


