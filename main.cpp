/* MOVIE TICKET BOOKING SYSTEM - DOUBLY CIRCULAR LINKED LISTS */

#include<iostream>
using namespace std;

typedef struct node
{
    char row_no;
    int seat_no, pin;
    char book;
    struct node *next, *prev;
}node;

class Screen
{
    public:
        node * head;
        Screen()
        {
            head = NULL;
        }
        void create();
        void display();
        void display1(node *[], int);
        void book_seat();
        void cancel();
};
void Screen::create()
{
    node *New, *current;
    int j=1;    // Row count
    volatile int k=2;
    char row ='A';

    do
    {
            int i=1;    // Seat count in each row
            do
            {
                    k = (k*k)/10 + 100 - k/2;
                    New = new node();
                    New->next = NULL;
                    New->prev = NULL;
                    New->row_no = row;
                    New->seat_no = i;
                    New->pin = k;
                    New->book = 'a';
                    if(head == NULL)  // First node
                    {
                        head = New;
                        New->next = head;
                        New->prev = head;
                    }
                    else
                    {
                        current = head;

                        while(current->next!=head)
                            current = current->next;

                        current->next=New;
                        New->prev=current;
                        New->next=head;
                        head->prev=New;
                    }
                    i++;
            }while(i<=7);
            j++;
            row++;
    }while(j<=10);
}

void Screen::display()
{
        node *current;
        current=head;
        cout<<"------------------------------------------------------------------\n";
        cout<<"|                             Premium                            |\n";
        while(current->next!=head)
        {
                if((current->prev)->row_no!=current->row_no)
                    cout<<"| ";
                cout<<current->row_no;
                cout<<current->seat_no;
                if(current->book=='a')
                    cout << " -> a  ";
                else
                    cout << " -> b  ";
                if((current->next)->row_no!=current->row_no)
                    cout<<"|\n";
                if(current->row_no=='C'&&current->seat_no==7)
                {
                    cout<<"------------------------------------------------------------------\n";
                    cout<<"|                            Executive                           |\n";
                }
                if(current->row_no=='H'&&current->seat_no==7)
                {
                    cout<<"------------------------------------------------------------------\n";
                    cout<<"|                             Club                               |\n";
                }
                current=current->next;
        }
        cout<<current->row_no;
        cout<<current->seat_no;
        if(current->book=='a')
                cout << " -> a  ";

        else
                cout << " -> b  ";
        cout << "|\n";
        cout << "\n==================================================================\n";
        cout << "                           ALL EYES HERE";
        cout << "\n==================================================================\n";
        cout << "------------------------------------------------------------------\n\n";
        cout << "PREMIUM-> Rs. 250          EXECUTIVE-> Rs. 190         CLUB-> Rs. 90\n";
}

void Screen::display1(node *tmp[20], int n)
{
        if(n != 1)
        {
                cout << "------------------------------------------------------------------\n";
                cout << "THANK YOU!\nYOU HAVE SUCCESSFULLY BOOKED THE SEATS\n";
                for(int i=1;i<n;i++)

                    cout << tmp[i]->row_no << tmp[i]->seat_no << "    PIN : " << tmp[i]->pin << endl;

                cout << "!!!!!!!!!!!!!!!!!!KEEP PIN SAFELY!!!!!!!!!!!!!!!!!!!\n";
                cout << "PINS ARE REQUIRED AT THE TIME OF CANCELLATION OF SEATS\n";
                cout << "------------------------------------------------------------------\n";
        }
}

void Screen::book_seat()
{
        node *current, *temp[20];
        int n, k;
        char row;
        int seat;
        char choice;
        do
        {
                k = 1;
                cout<<"\nHow many tickets do you want to buy? : ";
                cin>>n;

                cout<<"\nEnter Seat Number(s): \n";

                for(int i=1; i<=n; i++)
                {
                    cout << "NO " << i << " = ";
                    cin >> row >> seat;
                    current=head;
                    if(row>='A'&&row<='E')
                    {
                        while(current->next!=head)
                        {
                            if(current->row_no==row && current->seat_no==seat)
                            {
                                if(current->book=='a')
                                {
                                    current->book='b';
                                    temp[k]=current;
                                    k++;
                                }
                                else
                                {
                                    cout<<"INVALID CHOISE!\n";
                                    cout<<current->row_no<<current->seat_no<<" Seat is already reserved \n";

                                }
                            }
                            current=current->next;
                        }
                        if(current->row_no==row && current->seat_no==seat)
                        {
                            if(current->book=='a')
                            {
                                current->book='b';
                                temp[k]=current;
                                k++;
                            }
                            else
                            {
                                cout<<"INVALID CHOISE!\n";
                                cout<<current->row_no<<current->seat_no<<" Seat is already reserved\n";
                            }
                        }
                    }
                    else
                    {
                        while(current->prev!=head)
                        {
                            if(current->row_no==row && current->seat_no==seat)
                            {
                                if(current->book=='a')
                                {
                                    current->book='b';
                                    temp[k]=current;
                                    k++;
                                }
                                else
                                {
                                    cout<<"INVALID CHOISE!\n";
                                    cout<<current->row_no<<current->seat_no<<" Seat is already reserved \n";

                                }
                            }
                            current=current->prev;
                        }
                        if(current->row_no==row && current->seat_no==seat)
                        {
                            if(current->book=='a')
                            {
                                current->book='b';
                                temp[k]=current;
                                k++;
                            }
                            else
                            {
                                cout<<"INVALID CHOISE!\n";
                                cout<<current->row_no<<current->seat_no<<" Seat is already reserved\n";
                            }
                        }
                    }

                }

                display1(temp, k);
                cout<<"\n\nPRESS 1 To check Seat Status\n";
                cout<<"PRESS 2 To book other seat\n";
                cout<<"PRESS 3 To Exit BOOKING PORTAL\n";
                cout<<"\ninput: ";
                cin>>choice;
                if(choice==1)
                    display();
        }while(choice=='2');
}

void Screen::cancel()
{
    char row, ch;
    int seat;
    int pin;
    node *current;
    cout<<"SEAT CANCELLATION\n";
    do
    {
            ch='a';
            current=head;
            cout<<"SEAT NUMBER :";
            cin>>row>>seat;
            cout<<"PIN :";
            cin>>pin;
            if(row>='A'&&row<='E')
            {
                while(current->next!=head)
                {
                    if(current->row_no==row && current->seat_no==seat && current->pin==pin)
                    {
                        cout << "Are you sure you want to cancel? (y/n) ";
                        char c;
                        cin >> c;
                        if(c=='y'||c=='Y')
                        {
                            cout<<"SEAT CANCELLED SUCCESFULLY!\n";
                            current->book='a';
                        }
                    }
                    else if(current->row_no==row && current->seat_no==seat && current->pin!=pin)
                    {
                        cout<<"invalid SEAT NUMBER && PIN combination!!!!\n";
                    }
                    current=current->next;
                }
                if(current->row_no==row && current->seat_no==seat && current->pin==pin)
                {
                    cout << "Are you sure you want to cancel? (y/n) ";
                    char c;
                    cin>>c;
                    if(c=='y'||c=='Y')
                    {
                        cout<<"SEAT CANCELLED SUCCESFULLY!\n";
                        current->book='a';
                    }
                }
                else if(current->row_no==row && current->seat_no==seat && current->pin!=pin)
                {
                    cout<<"invalid SEAT NUMBER && PIN combination!!!!\n";
                }
            }
            else
            {
                while(current->next!=head)
                {
                    if(current->row_no==row && current->seat_no==seat && current->pin==pin)
                    {
                        cout << "Are you sure you want to cancel? (y/n) ";
                        char c;
                        cin >> c;
                        if(c=='y'||c=='Y')
                        {
                            cout<<"SEAT CANCELLED SUCCESFULLY!\n";
                            current->book='a';
                        }
                    }
                    else if(current->row_no==row && current->seat_no==seat && current->pin!=pin)
                    {
                        cout<<"invalid SEAT NUMBER && PIN combination!!!!\n";
                    }
                    current=current->next;
                }
                if(current->row_no==row && current->seat_no==seat && current->pin==pin)
                {
                    cout << "Are you sure you want to cancel? (y/n) ";
                    char c;
                    cin>>c;
                    if(c=='y'||c=='Y')
                    {
                        cout << "SEAT CANCELLED SUCCESFULLY!\n";
                        current->book='a';
                    }
                }
                else if(current->row_no==row && current->seat_no==seat && current->pin!=pin)
                {
                    cout<<"invalid SEAT NUMBER && PIN combination!!!!\n";
                }
            }
    cout<<"\n\nPRESS 1 To Check Seat Status\n";
    cout<<"PRESS 2 To Cancel More Tickets\n";
    cout<<"PRESS 3 To Exit CANCELLATION PORTAL\n";
    cout<<"\ninput: ";
    cin>>ch;
    if(ch==1)
            display();
    }while(ch=='2');
}


int main()
{
    Screen s1;
    int ch;
    char c;
    cout<<"\n\n\n";
    cout<<"              *****  WELCOME TO INOX  *****\n";
    cout<<"                ****** ARRANGEMENT ******\n\n";
    s1.create();
    s1.display();

    do
    {
        cout<<"\n\n\n";
        cout<<"PRESS 1-> BOOK TICKETS" << endl;
        cout<<"PRESS 2-> CANCEL TICKETS"<< endl;
        cout<<"PRESS 3-> EXIT" << endl;
        cout<<"\ninput: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                s1.book_seat();
                s1.display();
                break;
            case 2:
                s1.cancel();
                s1.display();
                break;
            case 3:
                cout << "THANKYOU" << endl;
                exit(0);
            default:
                cout << "Enter valid choice" << endl;
        }
        if(ch!=3)
        {
            cout<<"\n\nPRESS 1 To Main Menu\n";
            cout<<"PRESS 2 To Exit INOX PORTAL\n";
            cout<<"\ninput: ";
            cin>>c;
        }
    }while(c=='1');
    cout<<"\n\n\n";
    return 0;

}
