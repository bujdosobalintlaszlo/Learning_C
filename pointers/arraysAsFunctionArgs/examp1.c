void A(){
    print("Hello World!");
}

//function as pointer arg.
void B(void(*ptr)()){
    ptr(); //call-back the function that ptr points to
}

int main(){
    void (*p)() = A;
    B(p);
    return 0;
}