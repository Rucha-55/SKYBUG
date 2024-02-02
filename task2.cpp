/*Develop a calculator program that performs basic arithmetic
operation such as addition , subtraction, multiplication, and division.
Allow the user to input two numbers and choose an operation to perform.*/
#include<iostream>
using namespace std;

class calculator{
    public:
    float add=0,sub=0,multi=0,div=0;

    public:
    void addition(float num1,float num2){
        add=num1+num2;
        cout<<num1<<" + "<<num2<<" = "<<add;
    }

    void substraction(float num1,float num2){
        sub=num1-num2;
        cout<<num1<<" - "<<num2<<" = "<<sub;
    }

    void multiplication(float num1,float num2){
        multi=num1*num2;
        cout<<num1<<" * "<<num2<<" = "<<multi;
    }

    void division(float num1,float num2){
        add=num1/num2;
        cout<<num1<<" / "<<num2<<" = "<<div;
    }
};

int main(){
    float num1,num2;
    int ch;
    calculator obj;
    do{
        cout<<"\nMenu:\n";
        cout<<"\n1.Addtion\n2.Subtraction\n3.Multiplication\n4.Division\nExit.";
        cin>>ch;
        cout<<"\nSelect the task that you have to perfrom:";
        switch(ch){
            case 1:
            cout<<"\nEnter the number 1:";
            cin>>num1;
            cout<<"\nEnter the number 2:";
            cin>>num2;
            obj.addition(num1,num2);
            break;

            case 2:
            cout<<"\nEnter the number 1:";
            cin>>num1;
            cout<<"\nEnter the number 2:";
            cin>>num2;
            obj.substraction(num1,num2);
            break;

            case 3:
            cout<<"\nEnter the number 1:";
            cin>>num1;
            cout<<"\nEnter the number 2:";
            cin>>num2;
            obj.multiplication(num1,num2);
            break;

            case 4:
            cout<<"\nEnter the number 1:";
            cin>>num1;
            cout<<"\nEnter the number 2:";
            cin>>num2;
            obj.division(num1,num2);
            break;

            case 5:
            cout<<"\nEnd operation.";
            exit(0);
            break;

            default:
            cout<<"\nPlease select the valid choice.";
        }
    }while(ch!=5);
    return 0;
}