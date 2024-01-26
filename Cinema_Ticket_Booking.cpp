//Code
#include<iostream>
#include<string>
using namespace std;

class Node{
    public:
    string name;
    string seat;
    int id;
    Node* next;
    Node(int id=0,string seat="|___| "){
        this->id=id;
        next=NULL;
    }
};

void print(Node* &head,Node* &tail)
{   cout<<endl;
    Node* print=head;
    while(print!=NULL)
    {   
        if(print->id<10){
            cout<<" "<<print->id<<print->seat;
            print=print->next;
        }
        else{
            if(print->id==11 || print->id==21 || print->id==31 || print->id==41){
            cout<<endl;
            }
        cout<<print->id<<print->seat;
        print=print->next;
        }
    }
    cout<<"\n\n      SCREEN-> | _._._._._._._._._._._._._._._._._._._._._._._._ |";
    cout<<"\n-------------------------------------------------------------------------------\n";
    cout<<endl;
}

void booking(Node* &head,int pos){
    Node*book=head;
    if(pos>51){
        cout<<"\nSeat ID Invalid !\n";
        return;
    }
    for(int i=1;i<pos;i++){
        book=book->next;
    }
    if(book->seat=="|_B_| "){
        cout<<"\nSorry, This Seat Already Booked\nChoose Another\n";
        return;
    }
    else{
        book->seat="|_B_| ";
        cout<<"Enter Name : ";
        cin.ignore();
        getline(cin,book->name);
        cout<<"\nTicket Booked Successfully";
        cout<<endl;
    }    
}

void cancel(Node* &head,int pos){
    Node*book=head;
    for(int i=1;i<pos;i++){
        book=book->next;
    }
    if(book->seat=="|___| "){
        cout<<"\nThis Seat Not Booked yet\nEnter Correct ID\n";
        return;
    }
    else{
        book->seat="|___| ";
        cout<<"\nTicket Cancelled Successfully";
        cout<<endl;
    } 
}

//Manager:-
void remainingBooked(Node* &head,Node* &tail){
    Node* print=head;
    int remaining=0;
    while(print!=NULL)
    {   
        if(print->seat=="|___| "){
            remaining++;
        }
        print=print->next;
    }
    cout<<"Seat Booked : "<<50-remaining;
    cout<<"\nSeat Remaining : "<<remaining;
    cout<<endl;
}

void bookingname(Node* &head,int pos){
    Node*book=head;
    if(pos>51){
        cout<<"\nSeat ID Invalid !\n";
        return;
    }
    for(int i=1;i<pos;i++){
        book=book->next;
    }
    if(book->seat=="|___| "){
        cout<<"\nThis Seat Not Booked yet\n";
        return;
    }
    cout<<"Customer Info --> \nID : "<<book->id<<"\nName : "<<book->name;
    cout<<endl;
}

void creation(Node* &head,Node* &tail){
    int data=0;
    for(int i=1;i<=50;i++){
        Node *NEW=new Node();
        if(head==NULL){
            NEW->next=head;
            head=NEW;
            tail=NEW;
            tail->id=data;
            tail->seat="|___| ";
            data++;
        }
        tail->next=NEW;
        tail=NEW;
        tail->id=data;
        tail->seat="|___| ";
        data++;
    }
}

int main(){

    Node *head=NULL;
    Node *tail=NULL;
    int choice1,choice2,seatNumber;
    creation(head,tail);

    
        cout<<"\n|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|\n";
        cout<<"|                  ---->  CINEMA TICKET BOOKING SYSTEM  <----                 |\n";
        cout<<"|                             BY--> <codercastor/>                            |\n";
        cout<<"|_____________________________________________________________________________|\n";
        print(head,tail);

        bool step1=true;
        do{
            cout<<"\nSelect your Level :-\n1.Customer\n2.Manager\n3.Exit\nEnter Here -->";
            cin>>choice1;
            switch(choice1){
                case 1:
                {
                    bool a=true;
                    do{ 
                        cout<<"\n<------- MENU ------->\n";
                        cout<<"1.Check Status of Seats";
                            cout<<"\n2.Book Ticket";
                        cout<<"\n3.Cancel Ticket\n4.Back\nEnter Here -->";
                        cin>>choice2;
                        switch(choice2){
                            case 1:
                                print(head,tail);
                                break;

                            case 2:
                                cout<<"\nEnter Seat ID for Booking : ";
                                cin>>seatNumber;
                                booking(head,seatNumber);
                                break;
                    
                            case 3:
                                cout<<"Enter Seat ID for Ticket Cancellation : ";
                                cin>>seatNumber;
                                cancel(head,seatNumber);
                                break;

                            case 4:
                                a=false;
                                break;

                            default:
                                cout<<"\nEnter Correct Option Number\nchoice in Between 1-4 Shown Above\n";
                    }

                }while(a);
                break;
                }
                    
                case 2:
                {
                    bool b=true;
                    string userID;
                    string password;
                        cout<<"\nLogin Here --> \nEnter UserID : ";
                        cin>>userID;
                        cout<<"Enter Password : ";
                        cin>>password;
                        if(userID!="codercastor" || password!="1234"){
                            cout<<"\nLogIn Failed !\nEnter Correct ID & Password\n";
                            b=false;
                            exit;
                            break;
                        }
                    do{ 
                        cout<<"\n<------- MENU ------->\n";
                        cout<<"1.Check Status of Seats";
                        cout<<"\n2.Check Information About Customer";
                        cout<<"\n3.Remaining Seats and Booked Seats\n4.Cancel Ticket\n5.Back\nEnter Here -->";
                        cin>>choice2;
                        cout<<endl;
                        switch(choice2){
                            case 1:
                                print(head,tail);
                                break;

                            case 2:
                                cout<<"Enter Seat ID for Info : ";
                                cin>>seatNumber;
                                bookingname(head,seatNumber);
                                break;

                            case 3:
                            remainingBooked(head,tail);
                            break;
                    
                            case 4:
                                cout<<"Enter Seat ID for Ticket Cancellation : ";
                                cin>>seatNumber;
                                cancel(head,seatNumber);
                                break;

                            case 5:
                                b=false;
                                break;

                            default:
                                cout<<"\nEnter Correct Option Number\nchoice in Between 1-5 Shown Above\n";
                    }

                }while(b);
                break;
                }
                break;

                case 3:
                step1=false;
                exit;
                return 0;
                break;

                default:
                cout<<"\nInvalid Input\nChoose correct option Shown Above\n";
            }
        }while(step1);
        return 0;
}




