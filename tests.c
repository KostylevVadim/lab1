#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "Lin.h"
#include "Linint.h"
#include "lindo.h"
//All for test
void Redy_test(){
    Lin* C=malloc(sizeof(Lin));
    Lin* M=malloc(sizeof(Lin));
    Lin* S=malloc(sizeof(Lin));
    Lin* H=malloc(sizeof(Lin));
    Lin* T=malloc(sizeof(Lin));
    Lin* S1=malloc(sizeof(Lin));
    Lin* F=malloc(sizeof(Lin));
    Lin* Z=malloc(sizeof(Lin));
    Lin* Mini=malloc(sizeof(Lin));
    Lin* Mind=malloc(sizeof(Lin));
    printf("\nFirst Integer Liniar form C\n");
    int* c=malloc(4* sizeof(int));
    c[0]=1;
    c[1]=2;
    c[2]=3;
    c[3]=4;
    C=GenerateLin(4, sizeof(int),c);
    Getinfint(C);
    double* m=malloc(4* sizeof(double));
    m[0]=1.0;
    m[1]=2.1;
    m[2]=3.2;
    m[3]=4.3;
    M=GenerateLin(4, sizeof(double),m);
    printf("\nFirst Double Liniar form M\n");
    Getinfdouble(M);
    int* h=malloc(4* sizeof(int));
    h[0]=5;
    h[1]=4;
    h[2]=3;
    h[3]=2;
    H=GenerateLin(4, sizeof(int),h);
    printf("\nSecond Integer Liniar form H\n");
    Getinfint(H);
    printf("\nSecond Double Liniar form T\n");
    double* t=malloc(4* sizeof(double));
    t[0]=1.0;
    t[1]=2.0;
    t[2]=3.3;
    t[3]=4.9;
    T=GenerateLin(4, sizeof(double),t);
    Getinfdouble(T);
    printf("\nSumm of C and H\n");
    S=Sumint(C,H);
    Getinfint(S);
    printf("\nSumm of T and M\n");
    S1=Sumdo(T,M);
    Getinfdouble(S1);
    Mini=Minint(C,H);
    Mind=Mindo(T,M);
    printf("\nMin of C and H\n");
    Getinfint(Mini);
    printf("\nMin of T and M\n");
    Getinfdouble(Mind);
    printf("\nMult C by 4\n");
    F=Multint(C,4);
    Getinfint(F);
    printf("\nMult T by 1.1\n");
    Z=Multdo(T,1.1);
    Getinfdouble(Z);

    printf("\nFirst val (by C(h)): ");
    Valint(C,h,4);
    printf("\nSecond val (by T(m)): ");
    Valdo(T,m,4);
    free(C);
    free(M);
    free(S);
    free(H);
    free(T);
    free(S1);
    free(F);
    free(Z);
    free(Mini);
    free(Mind);

}

void Random_values(){
    srand( time(0) );
    printf("enter your first Liniar form:\n1) What type do you whant? 0 for int, 1 for double (if you will enter wrong number program will use mod of your number)\n");
    printf("2) Enter length (please enter not so long, till 100)\n");
    Lin* a=malloc(sizeof(Lin));
    a=Creating_near_random();
    printf("enter your second Liniar form:\n1) What type do you whant? 0 for int, 1 for double (if you will enter wrong number program will use mod of your number)\n");
    printf("2) Enter length (please enter not so long, till 100)\n");
    Lin* b=malloc(sizeof(Lin));
    b=Creating_near_random();
    printf("\n");
    size_t x=rand()%8;
    switch (x) {
        //Сложение
        case 0:{
            printf("Program will try to sum forms, like they are integer\n");
            Getinfint(a);
            Getinfint(b);
            Lin* Sum=malloc(sizeof(Lin));
            Sum=Sumint(a,b);
            Getinfint(Sum);
            free(Sum);
            break;
        }
        case 1:{
            printf("Program will try to sum forms, like they are double\n");
            Lin* Sum=malloc(sizeof(Lin));
            Getinfdouble(a);
            Getinfdouble(b);
            Sum=Sumdo(a,b);
            Getinfdouble(Sum);
            free(Sum);
            break;
        }
            //Вычитание
        case 2:{
            printf("Program will try to minus forms, like they are integer\n");
            Getinfint(a);
            Getinfint(b);
            Lin* Min=malloc(sizeof(Lin));
            Min=Minint(a,b);
            Getinfint(Min);
            free(Min);
            break;

        }
        case 3:{
            printf("Program will try to minus forms, like they are double\n");
            Lin* Min=malloc(sizeof(Lin));
            Getinfdouble(a);
            Getinfdouble(b);
            Min=Sumdo(a,b);
            Getinfdouble(Min);
            free(Min);
            break;
        }
            //Умножение
        case 4:{
            printf("Program will try to multiply first form on a value\n");
            Lin* Mul=malloc(sizeof(Lin));
            size_t x=rand()%2;
            int a1;
            double a2;
            if(x==0){
                a1=rand()%100;
                Getinfint(a);
                Mul=Multint(a,a1);
                Getinfint(Mul);
                free(Mul);
            };
            if(x==1){
                a1=rand()%10000;
                a2=(a1+0.0)/10;
                Getinfdouble(a);
                Mul=Multdo(a,a2);
                Getinfdouble(Mul);
                free(Mul);
            };
            break;
        }
        case 5:{
            printf("Program will try to multiply second form on a value\n");
            Lin* Mul=malloc(sizeof(Lin));
            size_t x=rand()%2;
            int a1;
            double a2;
            if(x==0){
                a1=rand()%100;
                Mul=Multint(b,a1);
                Getinfint(Mul);
                free(Mul);
            };
            if(x==1){
                a1=rand()%10000;
                a2=(a1+0.0)/10;
                Mul=Multdo(b,a2);
                Getinfdouble(Mul);
                free(Mul);
            };
            break;
        }
            //Значение
        case 6:{
            size_t l=a->length;
            size_t k=a->elementSize;
            if (k== sizeof(int)){
                int* tmp=malloc(l*k);
                for (int i=0;i<l;++i){
                    tmp[i]=rand()%100;
                }
                printf("\nValue -> \n");
                Valint(a,tmp,l);
                printf("\nValue ->\n");
                free(tmp);
            }
            if (k== sizeof(double)){
                double* tmp=malloc(l*k);
                for (int i=0;i<l;++i){
                    tmp[i]=rand()%10000/1000;
                }
                printf("\nValue ->\n");
                Valdo(a,tmp,l);

                free(tmp);
            }
            break;
        }
        case 7:{
            size_t l=b->length;
            size_t k=b->elementSize;
            if (k== sizeof(int)){
                int* tmp=malloc(l*k);
                for (int i=0;i<l;++i){
                    tmp[i]=rand()%100;
                }

                printf("\nValue ->\n");
                Valint(b,tmp,l);
                free(tmp);
            }
            if (k== sizeof(double)){
                double* tmp=malloc(l*k);
                for (int i=0;i<l;++i){
                    tmp[i]=rand()%10000/1000;
                }
                Valdo(b,tmp,l);
                printf("\nValue ->\n");
                Valdo(b,tmp,l);
                free(tmp);
            }
            break;
        }
        default:{
            printf("NOTHING HAPPENED");
        }

    }
    printf("\nRANDOM TEST IS FINISHED\n");
}
void Enter_test(){
    Lin* a=NULL;
    Lin* b=NULL;
    int usrch=-1;
    printf("\n<Entering> test is started. Here you must enter data and choose your functions by yourself\n");
    while (usrch!=0){
        printf("0.Exit\n1.Enter a\n2.Enter b\n3.Print a information\n4.Print b information\n5.Sum a and b\n6.Min a an b\n7.Mult a\n8.Mult b\n9.Value using your numbers with a\n10.Value using your numbers with b\n");
        scanf("%d",&usrch);
        switch(usrch){
            case 1:{
                a=NULL;
                a=malloc(sizeof(Lin));
                printf("\n1.Enter a\n");
                a=Enterdata();
                break;
            }
            case 2:{
                b=NULL;
                b=malloc(sizeof(Lin));
                printf("\n2.Enter b\n");
                b=Enterdata();
                break;
            }
            case 3:{
                printf("\n3.Print a information\n");
                InformationGiver(a);
            }
            case 4:{
                printf("\n4.Print b information\n");
                InformationGiver(b);
                break;
            }
            case 5:{
                Lin* Sum=NULL;
                Sum=malloc(sizeof(Lin));
                /*InformationGiver(a);
                InformationGiver(b);*/
                printf("\n5.Sum a and b\n");
                if (a->elementSize==b->elementSize && a->elementSize == sizeof(int)){Sum=Sumint(a,b);};
                if (a->elementSize==b->elementSize && a->elementSize == sizeof(double)){Sum=Sumdo(a,b);};
                if (a->elementSize!=b->elementSize) {printf("Element sizes are not equal. Rewrite one of your forms");Sum=NULL;}
                InformationGiver(Sum);
                free(Sum);
                break;
            }
            case 6:{
                Lin* Min=NULL;
                Min=malloc(sizeof(Lin));
                printf("\n6.Min a an b\n");
                if (a->elementSize==b->elementSize && a->elementSize == sizeof(int)){Min=Minint(a,b);};
                if (a->elementSize==b->elementSize && a->elementSize == sizeof(double)){Min=Mindo(a,b);};
                if (a->elementSize!=b->elementSize) {printf("Element sizes are not equal. Rewrite one of your forms");Min=NULL;}
                InformationGiver(Min);
                free(Min);
                break;
            }
            case 7:{
                Lin* Mul=NULL;
                Mul=malloc(sizeof(Lin));
                printf("\n7.Mult a by number. Print your number.\n");
                if (a->elementSize == sizeof(int)){
                    printf("Print your integer\n");
                    int x;
                    scanf("%d",&x);
                    Mul=Multint(a,x);
                    InformationGiver(Mul);
                };
                if (a->elementSize == sizeof(double)){
                    printf("Print your double\n");
                    double x;
                    scanf("%lf",&x);
                    Mul=Multdo(a,x);
                    InformationGiver(Mul);
                };
                free(Mul);
                break;
            }
            case 8:{
                Lin* Mul=NULL;
                Mul=malloc(sizeof(Lin));
                printf("\n8.Mult b by number. Print your number.\n");
                if (b->elementSize == sizeof(int)){
                    printf("Print your integer\n");
                    int x;
                    scanf("%d",&x);
                    Mul=Multint(b,x);
                    InformationGiver(Mul);
                };
                if (b->elementSize == sizeof(double)){
                    printf("Print your double\n");
                    double x;
                    scanf("%lf",&x);
                    Mul=Multdo(b,x);
                    InformationGiver(Mul);
                };
                free(Mul);
                break;
            }
            case 9:{
                if(a->elementSize==sizeof(int)){
                    printf("\nEnter, how many numbers will you use?\n");
                    int x,y;
                    scanf("%d",&x);
                    int *usn=malloc(x* sizeof(int));
                    for (int i=0;i<x;++i) scanf("%d",&usn[i]);

                    printf("\nValue is %d\n");
                    Valint(a,usn,x);
                }
                if(a->elementSize==sizeof(double)){
                    printf("\nEnter, how many numbers will you use?\n");
                    int x;
                    scanf("%d",&x);
                    double *usn=malloc(x* sizeof(double));
                    for (int i=0;i<x;++i) scanf("%lf",&usn[i]);
                    printf("\nValue is \n");
                    Valdo(a,usn,x);
                }
                break;
            }
            case 10:{
                if(b->elementSize==sizeof(int)){
                    printf("\nEnter, how many numbers will you use?\n");
                    int x;
                    scanf("%d",&x);
                    int *usn=malloc(x* sizeof(int));
                    for (int i=0;i<x;++i) scanf("%d",&usn[i]);

                    printf("\nValue is \n");
                    Valint(b,usn,x);
                }
                if(b->elementSize==sizeof(double)){
                    printf("\nEnter, how many numbers will you use?\n");
                    int x;
                    scanf("%d",&x);
                    double *usn=malloc(x* sizeof(double));
                    for (int i=0;i<x;++i) scanf("%lf",&usn[i]);

                    printf("\nValue is \n");
                    Valdo(b,usn,x);

                }
                break;
            }
            default:{
                usrch=0;
                break;
            }
        };
    }
    printf("\nTest was finished\n");

}

//Main test
void Test(){
    int usrch = -1;

    while(usrch!=0){
        printf("Choose type of test:\n0)Stop testing\n1)Ready test \n2)Random values with random functions \n3)Enter your one values\n");
        scanf("%d",&usrch);
        switch (usrch) {
            case 1:{
                Redy_test();
                break;
            }
            case 2:{
                Random_values();
                break;
            }
            case 3:{
                Enter_test();
                break;
            }
            default:{
                usrch=0;
                break;
            }

        }
    }
}
