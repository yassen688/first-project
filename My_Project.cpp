#include <iostream>
using namespace std;
class BankAccount {
private:
    string customer_Name ;
    int account_Number ;
    float bank_Balance;
public:

    BankAccount() {
        customer_Name = "unknown";
        account_Number=0;
        bank_Balance = 0.0;
    }

    void setcustomer_Name(string name ) {
        customer_Name=name ;

    }
    void setaccount_Number(int num) {
        account_Number=num;

    }

    void setbank_balance(float b) {
        if (b < 0) {
            cout << "The entry is incorrect, balance will be set to 0.\n";
            bank_Balance = 0.0;
        }
        else {
            bank_Balance = b;
        }
    }


        void displayInfo(){

                cout<<"yout acount name is : "<<customer_Name<<"\n";
            cout<<"yout acount number is : "<<account_Number<<"\n";
            cout<<"yout bank balance is : "<<bank_Balance<<"\n";
            cout<<"*********************************\n";
        }
            void deposit() {
                float amount ;
                cout<<"Please enter the deposit number : \n";
               cin >>amount;
                if (amount<0) {
                    cout << "The entry is incorrect, balance will be set to 0.\n";

                }
                else if (amount>=0) {
                    bank_Balance = amount+bank_Balance;
                    cout<<"The transaction was successful and the new balance : "<< bank_Balance<<endl;
                }
              cout<<"*********************************\n";
            }


                void withdraw() {
                float a;
                cout<<"Please enter the withdrawal number : \n";
                cin>>a;
                if (a<=bank_Balance) {
                    bank_Balance = bank_Balance-a;
                    cout<<"The withdrawal was successful and the withdrawn amount"<<a<< " \n"<< " bank balance are now " <<bank_Balance<<endl;
                }
                else if (a>bank_Balance) {
                    cout<<"Insufficient balance\n";
                }
              cout<<"*********************************\n";
            }


                int getAccountnumber() {
                return account_Number;
            }
};

int main () {
BankAccount account[100];
    int currentcount = 0;
    int choice=0;

    while (choice!=5) {
        cout<<"1.Add a new account\n"
              "2.Deposit\n"
              "3.Withdraw\n"
              "4.Account inquiry\n"
              "5.Exit\n"
        ;
        cin>>choice;
        switch (choice) {
            case 1: {
                string name;
                int ID;
                float balance;

                cout<<"Enter your Account name: \n";
                cin>>name;
                account[currentcount].setcustomer_Name(name);

                cout<<"Enter your Account Number : \n";
                cin>>ID;
                account[currentcount].setaccount_Number(ID);

                cout<<"Enter your bank balance \n";
                cin>>balance;
                account[currentcount].setbank_balance(balance);
                currentcount++;
                break;
            }


            case 2: {
                cout<<"enter your account number : \n";
                int searchID;
                cin>>searchID;
                bool isfound=false;
                for (int i =0; i<currentcount;i++) {
                    if (searchID==account[i].getAccountnumber()) {
                        account[i].deposit();
                        isfound = true;
                        break;
                    }
                }
                if (isfound==false) {
                    cout<<"This Account Not Found!!\n";
                }
          break;   }




            case 3: {
                    cout<<"enter your account number : \n";
                    int searchID;
                    cin>>searchID;
                    bool isfound=false;

                    for (int i =0; i<currentcount;i++) {
                        if (searchID==account[i].getAccountnumber()) {
                            account[i].withdraw();
                            isfound = true;
                            break;
                        }
                        }
                if (isfound==false) {
                    cout<<"This Account Not Found!!\n";
                    }
                }
                break;

            case 4:{
                cout<<"enter your account number : \n";
                int searchID;
                cin>>searchID;
                bool isfound=false;

                for (int i =0; i<currentcount;i++) {
                    if (searchID==account[i].getAccountnumber()) {
                        account[i].displayInfo();
                        isfound = true;
                        break;
                    }
                }
                if (isfound==false) {
                    cout<<"This Account Not Found!!\n";
                }
        }
        break;



            case 5: {
                cout<<"Thank you for using our bank! Goodbye \n";
            break;
            }
                default:
                cout<<"Invalid choice! Please try again\n";
                break;


        }
    }
}
