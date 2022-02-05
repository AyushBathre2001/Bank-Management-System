#include <bits/stdc++.h>
using namespace std;

class BMS
{
private:
    string name, age, gender, email, address, mob, adhar;
    string file, pin, cpin, account, key;
    string str;
    int unique, money = 0;

public:
    bool check()
    {
        cout << "\nEnter your email - ";
        getline(cin, email);
        cout << "\nEnter your pin - ";
        cin >> pin;
        key = email + pin;
        ifstream ch;
        ch.open("secure.txt");
        while (!ch.eof())
        {
            getline(ch, str);
            if (str == key)
            {

                return true;
                ch.close();
            }
        }
        return false;
        ch.close();
    }

    void transaction(string ac, string tr, string mon)
    {
        string account;
        account = ac + ".txt";
        time_t tmNow = time(0);
        char *dt = ctime(&tmNow);
        ofstream trans;
        trans.open(account, ios::app);
        trans << "TRANSACTION - " << tr << "\t" << mon << "/-\t" << dt;
        trans.close();
    }

    void create()
    {
        cout << "\n\t\t\tPLEASE ENTER THE DETAILS...." << endl;
        cout << "\nEnter your name -  ";
        getline(cin, name);
        cout << "\nEnter your age - ";
        cin >> age;
        cout << "\nEnter your gender(M/F) - ";
        cin >> gender;
        cout << "\nEnter your email - ";
        cin >> email;
        cin.ignore();
        cout << "\nEnter your address - ";
        getline(cin, address);
        cout << "\nEnter mobile no. - ";
        cin >> mob;
        cout << "\nEnter your Aadhar no. - ";
        cin >> adhar;
        cout << "\nEnter create a pin - ";
        cin >> pin;
        cout << "\nConfirm pin - ";
        cin >> cpin;
        if (pin != cpin)
        {
            cout << "\nWRONG PASSWORD!" << endl;
        }
        else
        {
            file = name + ".txt";
            key = email + pin;
            srand(time(0));
            unique = rand() % 9000 + 1000;
            account = "565623" + to_string(unique);
            ofstream out;
            out.open(file, ios::app);
            out << account << endl;
            out << money << endl;

            out.close();
            ofstream out2;
            out2.open("secure.txt", ios::app);
            out2 << key << endl;
            out2.close();

            cout << "\t|*--------------------------------------------------------------*|" << endl;
            cout << "\t\t\t\t-ACCOUNT_CREATED-\n"
                 << endl;
            cout << "\t\tACCOUNT NUMBER - " << account << endl;
            cout << "\t\tCURRENT BALANCE - " << money << endl;
            cout << "\t|*--------------------------------------------------------------*|" << endl;
        }
    }
    void deposit()
    {

        string ac, str2, money;
        int cr, newmon;
        cout << "\nEnter your name - ";
        getline(cin, name);
        cout << "\nEnter account number - ";
        cin >> ac;
        file = name + ".txt";
        ifstream ch2;
        ch2.open(file);
        ch2 >> str2;
        if (str2 == ac)
        {
            ch2 >> money;
            cout << "\nHow much money you want to deposit - ";
            cin >> cr;
            newmon = cr + stoi(money);
            ofstream out;
            out.open(file);
            out << ac << endl;
            out << to_string(newmon) << endl;
            out.close();
            cout << "\t------------------------------------------" << endl;
            cout << "\t\t|*TRANSACTION COMPLETE*|" << endl;
            cout << "\n\tCURRENT BALANCE - " << newmon << "/-" << endl;
            cout << "\t-----------------------------------------" << endl;
            transaction(ac, "credit", to_string(cr));
        }
        else
        {
            cout << "INVALID ACCOUNT NUMBER!" << endl;
            ch2.close();
        }
    }
    void show()
    {
        string ac, money;
        cout << "\nEnter your name - ";
        getline(cin, name);
        key = name + ".txt";
        ifstream sh;
        sh.open(key);
        if (sh)
        {
            sh >> ac;
            sh >> money;
            cout << "------------------------------------------" << endl;
            cout << "\tCURRENT BALANCE - " << money << "/-" << endl;
            cout << "------------------------------------------" << endl;
            sh.close();
        }
        else
        {
            cout << "\n\tFILE DOES NOT EXIST!!" << endl;
        }
    }

    void withdraw()
    {

        string ac, str2, money;
        int cr, newmon;
        cout << "\nEnter your name - ";
        getline(cin, name);
        cout << "\nEnter Account number - ";
        cin >> ac;
        file = name + ".txt";
        ifstream wd;
        wd.open(file);
        wd >> str;
        if (str == ac)
        {
            wd >> money;
            cout << "\nHow much money you want to withdraw - ";
            cin >> cr;
            newmon = stoi(money);
            if (cr > newmon)
            {
                cout << "\n\tINSUFFICIENT MONEY!!" << endl;
                exit(0);
            }

            newmon = newmon - cr;

            ofstream wd2;
            wd2.open(file);
            wd2 << ac << endl;
            wd2 << to_string(newmon) << endl;
            wd2.close();
            wd.close();
            cout << "\t------------------------------------------" << endl;
            cout << "\t\t|*TRANSACTION COMPLETE*|" << endl;
            cout << "\n\tCURRENT BALANCE - " << newmon << "/-" << endl;
            cout << "\t-----------------------------------------" << endl;
            transaction(ac, "Debit", to_string(cr));
        }
        else
        {
            cout << "INVALID ACCOUNT NUMBER!" << endl;
            wd.close();
        }
    }

    void transacHistory()
    {
        string ac;
        cout << "\nEnter Account number - ";
        cin >> ac;
        file = ac + ".txt";
        ifstream tr;
        tr.open(file);
        if (tr)
        {
            while (!tr.eof())
            {
                getline(tr, str);
                cout << str << endl;
            }
        }
        else
        {
            cout << "\nINVALID ACCOUNT NUMBER!" << endl;
        }
        tr.close();
    }
};

int main()
{
    BMS obj;
    int choice;
    bool cfm;
    cout << "\t\t\t|------------------------BANK-MANAGEMENT-SYSTEM------------------------|" << endl;
    cout << "\n\t\t\t1) Create Account" << endl;
    cout << "\n\t\t\t2) Deposit Money" << endl;
    cout << "\n\t\t\t3) Check Balance" << endl;
    cout << "\n\t\t\t4) Withdraw Money" << endl;
    cout << "\n\t\t\t5) Transaction History" << endl;
    cout << "\n\t\t\t|----------------------------------------------------------------------|" << endl;

    cout << "\t\tEnter your choice - ";
    cin >> choice;
    cin.ignore();

    switch (choice)
    {
    case 1:
        obj.create();
        break;
    case 2:
        obj.deposit();
        break;
    case 3:
        cfm = obj.check();
        if (cfm == true)
        {
            cin.ignore();
            obj.show();
        }
        else
        {
            cout << "INVALID IDENTITY!" << endl;
        }
        break;
    case 4:
        cfm = obj.check();
        if (cfm == true)
        {
            cin.ignore();
            obj.withdraw();
        }
        else
        {
            cout << "INVALID IDENTITY!" << endl;
        }
        break;
    case 5:
        cfm = obj.check();
        if (cfm == true)
        {
            cin.ignore();
            obj.transacHistory();
        }
        else
        {
            cout << "INVALID IDENTITY!" << endl;
        }

        break;

    default:
        cout << "INVALID CHOICE" << endl;
        break;
    }

    return 0;
}