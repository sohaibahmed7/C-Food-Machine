/*
    Name: Sohaib Ahmed
    Date: May 10th, 2021
    Purpose: School Food Machine School
*/

#include <iostream>
#include <iomanip>
using namespace std;

//Initializing 4 functions that my program call upon.
//Display: this function simply prints the menu.
void display();
//Choice: this function allows the user to pick which item they want from the menu and pay.
void choice(string &, char &, double &, double &, int);
//Repeat: this function asks if the user would like to order another item.
void repeat(string, char &, double &, double &, string, int);
//Terminate: if the user enters name as "Kent Armstrong", this function runs and offers to shutdown the system.
void terminate(char &);

//Initialize int 'n'. This counts the number of people that use the food machine in one session.
int n=0;

int main()
{
    //Initializing string 'name', which is the name the user enters at the beginning.
    string name;
    //Character 'item', which is the menu item the user selects.
    char item;
    //Double 'money', which is the amount of money the user deposits when purchasing an item.
    double money;
    //Double 'sum', which is the total cost of the user's order.
    double sum=0;

    //The program will run as long as 'n'<1000. Simply put, if 1000 students enter their names and order, the machine will stop.
    while(n<1000)
    {
        //Calls upon 'display' which presents the menu to the user.
        display();
        //Asks user for their name, if 'Sohaib Ahmed' is entered, 'terminate' is called upon which offers to shutdown the program.
        //Otherwise, 'choice' is called upon and the program continues.
        printf("Food Machine: Hi there! What is your name?\n");
        getline(cin,name);
        n++;
        if(name=="Sohaib Ahmed" || name=="sohaib ahmed" || name=="Sohaib ahmed")
        {
            terminate(item);
            exit(EXIT_FAILURE);
        }
        else
        {
            choice(name, item, money, sum, n);
        }
    }
    return 0;
}

void display()
{
    //Various print statements that simply display the menu.
    printf("----------------------------------------------\n");
    printf("|     Welcome to Sohaib Ahmed's Machine      |\n");
    printf("|--------------------------------------------|\n");
    printf("| Item \t\t\tPrice \t\tCode |\n");
    printf("|--------------------------------------------|\n");
    printf("| Rice Pilaf \t\t$5.00 \t\t R   |\n");
    printf("| Annas Potatoes \t$2.25 \t\t A   |\n");
    printf("| Tuna on Toast \t$7.00 \t\t T   |\n");
    printf("| Grilled Cheese \t$6.75 \t\t G   |\n");
    printf("| Veggie Samosa \t$1.00 \t\t S   |\n");
    printf("| Soft Drinks \t\t$1.25 \t\t D   |\n");
    printf("----------------------------------------------\n");
    cout<<endl;
}

void choice(string &a, char &b, double &c, double &d, int n)
{
    //Initializes string 'again' that is later used to ask if the user wants another item.
    string again;
    //Initializes double 'num' that asks the user for the quantity of the item they pick.
    double num;
    //Asks user to input which item they want.
    cout<<"Ok "<<a<<", what item would you like? (Enter your choice using the given codes above)."<<endl;
    cin>>b;

    //If the user enters a character that corresponds to an item, then the program asks for the quantity
    //and asks the user to deposit the appropriate amount of money. That amount is then added to the total.
    if(b=='r' || b=='R')
    {
        num=0.00;
        printf("How many of them do you want?\n");
        cin>>num;
        cout<<"Please Deposit $"<<std::setprecision(2)<<fixed<<5.00*num<<" to complete your purchase."<<endl;
        cout<<"$";
        cin>>c;
        //If the user enters more than the required amount, change is returned.
        //If the user enters less than the required amount, the user is asked to try again.
        if(c!=5*num || c!=5.0*num || c!=5.00*num)
        {
            if(c>5*num || c>5.0*num ||c>5.00*num)
            {
                cout<<"$"<<c-(5*num)<<" returned as change.\n";
                d+=5.00*num;
                repeat(a,b,c,d,again,n);
            }
            else
            {
                printf("Insufficient amount. Try again.\n");
                choice(a,b,c,d,n);
            }

        }
        else
        {
            d+=5.00*num;
            repeat(a,b,c,d,again,n);
        }
    }
    else if(b=='a' || b=='A')
    {
        num=0;
        printf("How many of them do you want?\n");
        cin>>num;
        cout<<"Please Deposit $"<<std::setprecision(2)<<fixed<<2.25*num<<" to complete your purchase."<<endl;
        cout<<"$";
        cin>>c;
        if(c!=2.25*num)
        {
            if(c>2.25)
            {
                cout<<"$"<<c-(2.25*num)<<" returned as change.\n";
                d+=2.25*num;
                repeat(a,b,c,d,again,n);
            }
            else
            {
                printf("Insufficient amount. Try again.\n");
                choice(a,b,c,d,n);
            }
        }
        else
        {
            d+=2.25*num;
            repeat(a,b,c,d,again,n);
        }
    }
    else if(b=='t' || b=='T')
    {
        num=0;
        printf("How many of them do you want?\n");
        cin>>num;
        cout<<"Please Deposit $"<<std::setprecision(2)<<fixed<<7.00*num<<" to complete your purchase."<<endl;
        cout<<"$";
        cin>>c;
        if(c!=7*num || c!=7.0*num || c!=7.00*num)
        {
            if(c>7*num || c>7.0*num ||c>7.00*num)
            {
                cout<<"$"<<c-(7*num)<<" returned as change.\n";
                d+=7.00*num;
                repeat(a,b,c,d,again,n);
            }
            else
            {
                printf("Insufficient amount. Try again.\n");
                choice(a,b,c,d,n);
            }
        }
        else
        {
            d+=7.00*num;
            repeat(a,b,c,d,again,n);
        }
    }
    else if(b=='g' || b=='G')
    {
        num=0;
        printf("How many of them do you want?\n");
        cin>>num;
        cout<<"Please Deposit $"<<std::setprecision(2)<<fixed<<6.75*num<<" to complete your purchase."<<endl;
        cout<<"$";
        cin>>c;
        if(c!=6.75*num)
        {
            if(c>6.75*num)
            {
                cout<<"$"<<c-(6.75*num)<<" returned as change.\n";
                d+=6.75*num;
                repeat(a,b,c,d,again,n);
            }
            else
            {
                printf("Insufficient amount. Try again.\n");
                choice(a,b,c,d,n);
            }
        }
        else
        {
            d+=6.75*num;
            repeat(a,b,c,d,again,n);
        }
    }
    else if(b=='s' || b=='S')
    {
        num=0;
        printf("How many of them do you want?\n");
        cin>>num;
        cout<<"Please Deposit $"<<std::setprecision(2)<<fixed<<1.00*num<<" to complete your purchase."<<endl;
        cout<<"$";
        cin>>c;
        if(c!=1*num || c!=1.0*num || c!=1.00*num)
        {
            if(c>1*num || c>1.0*num ||c>1.00*num)
            {
                cout<<"$"<<c-(1*num)<<" returned as change.\n";
                d+=1.00*num;
                repeat(a,b,c,d,again,n);
            }
            else
            {
                printf("Insufficient amount. Try again.\n");
                choice(a,b,c,d,n);
            }
        }
        else
        {
            d+=1.00*num;
            repeat(a,b,c,d,again,n);
        }
    }
    else if(b=='d' || b=='D')
    {
        num=0;
        printf("How many of them do you want?\n");
        cin>>num;
        cout<<"Please Deposit $"<<std::setprecision(2)<<fixed<<1.25*num<<" to complete your purchase."<<endl;
        cout<<"$";
        cin>>c;
        if(c!=1.25*num)
        {
            if(c>1.25*num)
            {
                cout<<"$"<<c-(1.25*num)<<" returned as change.\n";
                d+=1.25*num;
                repeat(a,b,c,d,again,n);
            }
            else
            {
                printf("Insufficient amount. Try again.\n");
                choice(a,b,c,d,n);
            }
        }
        else
        {
            d+=1.25*num;
            repeat(a,b,c,d,again,n);
        }
    }
    //If the user enters a character that does NOT correspond to an item, the machine resets and moves on to the next person.
    else
    {
        printf("That is not a proper choice, I'll assume you are not hungry.\n");
        printf("I will now help the next person.\n");
        system ("PAUSE");
        cin.ignore();
        cin.ignore();
        system ("CLS");
        main();
    }
}

void repeat(string a, char &b, double &c, double &d, string e, int n)
{
    printf("Would you like another item? (y/n)\n");
    cin>>e;
    //If the user decides to have another item, 'choice' is called upon and runs again, retaining the amount of money previously spent.
    if(e=="yes"||e=="Yes"||e=="YES"||e=="y"||e=="Y")
    {
        system ("PAUSE");
        system ("CLS");
        display();
        choice(a,b,c,d,n);
    }
    //If the user does not want to have another item, their total is calculated and then printed.
    //The machine then resets and asks for the next person to enter their name.
    else
    {
        cout<<"Thank you "<<a<<", your total is $"<<d<<", your order will be ready in a few minutes!\n";
        cout<<endl;
        printf("I will now help the next person.\n");
        system ("PAUSE");
        cin.ignore();
        system ("CLS");
        main();
    }
}

void terminate(char &b)
{
    //If the user inputs the correct code(k), the machine will shutdown.
    printf("Hello Mr.Ahmed, enter your code to terminate the system.\n");
    cin>>b;
    if(b=='k'||b=='K')
    {
        printf("Shutting system down.\n");
    }
    //Otherwise, it will simply reset and ask the user for their name once more.
    else
    {
        printf("Incorrect Code, process will not terminate.\n");
        system ("PAUSE");
        cin.ignore();
        system ("CLS");
        main();
    }
}
