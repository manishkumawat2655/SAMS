#include<bits//stdc++.h>
#include<unistd.h>
using namespace std;
class Person{
   public:
        string name;
        long int mobileNumber;
        string email;
        string address;
        string getName(){
            return this->name;
        }
        void setName(string s){
            this->name = s;
        }    
        long int getmobileNumber(){
            return this->mobileNumber;
        }
        void setmobileNumber(long int n){
            this->mobileNumber = n;
        }
        string getEmail(){
            return this->email;
        }
        void setEmail(string e){
            this->email = e;
        }
        string getAddress(){
            return this->address;
        }
        void setAddress(string a){
            this->address = a;
        }
};
class Show{
    private:
        string dateAndTime;
        string title;
        int audinarySeatAvailable;
        int balconySeatAvailable;
        int audinarySeatAvailableForVIP;
        int balconySeatAvailableForVIP;
        int sales;
        int priceAudinarySeat;
        int priceBalconySeat;
    public:
    string GetTitle(){
        return this->title;
    }
    void SetTitle(string tit){
        this->title = tit;
    }
    int getPriceAudinarySeat(){
        return this->priceAudinarySeat;
    }
    void setPriceAudinarySeat(int p){
        this->priceAudinarySeat= p;
    }
    int getPriceBalconySeat(){
        return this->priceBalconySeat;
    }
    void setPriceBalconySeat(int p){
        this->priceBalconySeat= p;
    }
        string getDateandTime(){
            return this->dateAndTime;
        }
        void setDateandTime(){
            time_t tm = time(0);
            this->dateAndTime = ctime(&tm);
        }
        int getAudinarySeatAvailable(){
            return this->audinarySeatAvailable;
        }
        void setAudinarySeatAvailable(int s){
            this->audinarySeatAvailable = s;
        }
        int getBalconySeatAvailable(){
            return this->balconySeatAvailable;
        }    
        void setBalconySeatAvailable(int s){
            this->balconySeatAvailable = s;
        }
        int getAudinarySeatForVIP(){
            return this->audinarySeatAvailableForVIP;
        }
        void setAudinarySeatForVip(int s){
            this->audinarySeatAvailableForVIP = s;
        }
        int getBalconySeatForVIP(){
            return this->balconySeatAvailableForVIP;
        }
        void setBalconySeatForVIP(int s){
            this->balconySeatAvailableForVIP = s;
        }
        int getSales(){
            return this->sales;
        }
        void setSales(int s){
            this->sales =s;
        }
};
class Transaction{
    private:
        string dateOfBooking;
        static long int id;
        int id_n;
        string ShowName;
        string BySalesPerson;
        int price;
    public:
        string getDateOfBooking(){
            return this->dateOfBooking;
        }
        void setDateOfBooking(){
            time_t tm = time(0);
            this->dateOfBooking = ctime(&tm);
        }
        long int getId(){
            return this->id_n;
        }    
        void setId(){
            this->id_n = id;
            id++;
        }  
        string getShowName(){
            return this->ShowName;
        }    
        void setShowName(string nm){
            this->ShowName = nm;
        }
        string getSalesPerson(){
            return this->BySalesPerson;
        }
        void setSalesPerson(string nm){
            this->BySalesPerson = nm;
        }
        int getPrice(){
            return this->price;
        }
        void setPrice(int p){   
             this->price = p;
        }
        void PrintTicket(){
            cout<<"Id                       : "<<getId()<<endl;
            cout<<"Show Name                : "<<getShowName()<<endl;
            cout<<"Booked by Sales Person   : "<<getSalesPerson()<<endl;
            cout<<"price Paid               : "<<getPrice()<<endl;
        }
};
long int Transaction::id = 1001;
class SalesPerson : public Person{
    private:
        long int id;
        string password;
        map<int,Transaction> trans;
    public:
        long int getId(){
            return this->id;
        }
        void SetId(long int id){
            this->id = id;
}
        string getUserName(){
            return this->name;
        }
        void setUserName(){
            string usname;
            cout<<"Enter new user name"<<endl;
            cin>>usname;
            this->name = usname;
        }
        string getPassWord(){
            return this->password;
        }
        void setPassword(){
            cout<<"Enter new Password"<<endl;
            string Pas;
            cin>>Pas;
            this->password = Pas;
        }
        int bookTicket(int a,Show &s){
            if(a == 0){
                int st = s.getAudinarySeatAvailable();
                if(st){
                    s.setAudinarySeatAvailable(st-1);
                    int sl = s.getSales();
                    s.setSales(sl+1);
                    Transaction t;
                    t.setId();
                    t.setSalesPerson(this->name);
                    t.setDateOfBooking();
                    t.setShowName(s.GetTitle());
                    t.setPrice(s.getPriceAudinarySeat());
                    trans[t.getId()] = t;
                    return t.getId();
                }
                else{
                    cout<<"Not Available"<<endl;
                    return 0;
                }
            }
            else{
                int st = s.getBalconySeatAvailable();
                cout<<st<<endl;
                if(st){
                    s.setBalconySeatAvailable(st-1);
                    int sl = s.getSales();
                    s.setSales(sl+1);
                     Transaction t;
                    t.setId();
                    t.setSalesPerson(this->name);
                    t.setDateOfBooking();
                    t.setShowName(s.GetTitle());
                    t.setPrice(s.getPriceBalconySeat());
                    trans[t.getId()] = t;
                    return t.getId();
                }
                else{
                    cout<<"Not Available"<<endl;
                    return 0;
                }
            }
            return 0;
        }

        void cancellation(int TransId,Show &s,int typeOfSeat){
            int st;
            if(typeOfSeat == 0){
                 st = s.getAudinarySeatAvailable();
                 s.setAudinarySeatAvailable(st+1);
                 int sales = s.getSales();
                 s.setSales(sales-1);
                 trans.erase(TransId);
            }
            else{
                st = s.getBalconySeatAvailable();
                 s.setBalconySeatAvailable(st+1);
                 int sales = s.getSales();
                 s.setSales(sales-1);
                 trans.erase(TransId);

            }
        }

        void TransactionDone(){
            for(auto d : trans){
                d.second.PrintTicket();
            }
        }
        void Ticket(int Trans_id){
            trans[Trans_id].PrintTicket();
        }
            
};
class ShowManager : public Person{
    private:
         map<long int,SalesPerson> SP;
         vector<Show> Sh;
         static long int id;
    public:
         void getSalesPersonsList(){
              for(auto data : SP){
                  cout<<"Name           : "<<data.second.name<<endl;
                  cout<<"Email          : "<<data.second.email<<endl;
                  cout<<"MobileNumber   : "<<data.second.mobileNumber<<endl;
                  cout<<"Address        : "<<data.second.address<<endl;
                  cout<<"Id             : "<<data.second.getId()<<endl;
              }
        }
        void getShowList(){
            for(auto data : Sh){
                cout<<endl;
                cout<<"Title                 : "<<data.GetTitle()<<endl;
                cout<<"Audinary Seats        : "<<data.getAudinarySeatAvailable()<<endl;
                cout<<"Balcony seats         : "<<data.getBalconySeatAvailable()<<endl;
                cout<<"Audinary VIP seats    : "<<data.getAudinarySeatForVIP()<<endl;
                cout<<"Balcony VIP seats     : "<<data.getBalconySeatForVIP()<<endl;
                cout<<"Audinary Seat Price   : "<<data.getPriceAudinarySeat()<<endl;
                cout<<"Balcony Seat Price    : "<<data.getPriceBalconySeat()<<endl;
            }
            cout<<endl;
        }
        void setSalesPerson(map<int,SalesPerson>&mp){
            string name,email,add;
            long int mobile;
            SalesPerson sp;
            cout<<"Enter name of Sales Person            : ";
            cin>>name;
            cout<<endl;
            cout<<"Enter email of Sales Person           : ";
            cin>>email;
            cout<<endl;
            cout<<"Enter Mobile Number of Sales Person   : ";
            cin>>mobile;
            cout<<endl;
            cout<<"Enter address of Sales Person         : ";
            cin>>add;
            cout<<endl;
            cout<<" SUCCESSFULLY ADDED "<<endl;
            sp.setName(name);
            sp.setAddress(add);
            sp.setEmail(email);
            sp.SetId(id);
            sp.setmobileNumber(mobile);
            SP[id] = sp;
            mp[id] = sp;
            id++; 
        }
       void RemoveSalesPerson(long int id){
             SP.erase(id);
       } 

       void setShowList(vector<Show>&v){
           string  title;
           int Aud, Bal, AudVIP, BalVIP,PriceAud,PriceBal;
           Show new_show;
           cout<<"Enter Title of The Show                      : ";
           cin>>title;
           cout<<endl;
           cout<<"Enter Number of Gernal Audinary Seats        : ";
           cin>>Aud;
           cout<<endl;
           cout<<"Enter Number of Gernal balcony Seats         : ";
           cin>>Bal;
           cout<<endl;
           cout<<"Enter Number of VIP Audinary Seats           : ";
           cin>>AudVIP;
           cout<<endl;
           cout<<"Enter Number of VIP Balcony Seats            : ";
           cin>>BalVIP;
           cout<<endl;
           cout<<"Enter Price for Audinary Seat for the show   : ";
           cin>>PriceAud;
           cout<<endl;
           cout<<"Enter Price for Balcony Seat for the show    : ";
           cin>>PriceBal;
           cout<<endl;
           cout<<" SUCCESSFULLY ADDED "<<endl;
           new_show.SetTitle(title);
           new_show.setAudinarySeatAvailable(Aud);
           new_show.setBalconySeatAvailable(Bal);
           new_show.setAudinarySeatForVip(AudVIP);
           new_show.setBalconySeatForVIP(BalVIP);
           new_show.setSales(0);
           new_show.setPriceAudinarySeat(PriceAud);
           new_show.setPriceBalconySeat(PriceBal);
           new_show.setDateandTime();
           Sh.push_back(new_show);
           v.push_back(new_show);
       }   
       void AllTransactions(){
           for(auto data : SP){
            data.second.TransactionDone();
           }
       }   
};

long int ShowManager::id = 7893;

class Data{
    public:
    int id;
    int T_Id;
    int ind;
    int st;
};
int main(){
    cout<<"*****************************************************************************"<<endl;
    cout<<"                   STUDENT AUDITORIUM MANAGEMENT SYSTEM                      "<<endl;
    cout<<"*****************************************************************************"<<endl<<endl;
    ShowManager s;
    map<int,SalesPerson> SPList;
    vector<Show> ShowList;
    map<string,Data> users;
    int a;
    while(true){
    cout<<"--------------------------------HOME PAGE--------------------------------------"<<endl<<endl;
    cout<<"Input As:"<<endl;
    cout<<1<<". Show Manager"<<endl;
    cout<<2<<". Sales Person"<<endl;
    cout<<3<<". Spectator"<<endl;
    cout<<4<<". exit"<<endl<<endl;
    
    cout<<"Enter your role (1/ 2/ 3/ 4): ";
    cin>>a;
    if(a == 4){
        cout<<endl<<"Quiting ..."<<endl; 
        usleep(500000);
    }
    else if(a > 4){
        cout<<endl<<"Enter your Choice again"<<endl;
        continue;
    }   
    else{
    cout<<endl<<"loading ..."<<endl; 
    usleep(500000);
    }
        if(a == 1){
            while(true){
            cout<<endl<<"--------------------SHOW MANAGER PORTAL------------------------------"<<endl<<endl;
             int b;
             cout<<1<<". Get Sales Person List"<<endl;
             cout<<2<<". Add new Sales Person"<<endl;
             cout<<3<<". Get Show List"<<endl;
             cout<<4<<". Add new Show"<<endl;
             cout<<5<<". All transactions Till Now"<<endl;
             cout<<6<<". Log Out"<<endl<<endl;
             cout<<"Enter your choice : ";
             cin>>b;
             cout<<endl;
             
                 if(b == 1){
                     s.getSalesPersonsList();
                 }
                 else if(b == 2){
                     s.setSalesPerson(SPList);
                 }
                 else if(b == 3){
                     s.getShowList();
                 }
                 else if(b == 4){
                     s.setShowList(ShowList);
                 }
                 else if(b == 5){
                     for(int i = 0;i<SPList.size();i++){
                         SPList[i].TransactionDone();
                     }    
                 }
                 else{
                    break;
                 }
             }
          }       
        else if(a == 2){
             cout<<endl<<"----------------------SALES PERSON PORTAL---------------------------"<<endl<<endl;
             int id;
             cout<<"Enter your id for login : ";
             cin>>id;
             cout<<endl;
             if(SPList.find(id) == SPList.end()){
                cout<<"Invalid id"<<endl;
             }
             else{
             cout<<"logging in ..."<<endl;
             usleep(500000); 
             while(true){
             int c;
             cout<<1<<". Set new User Name"<<endl;
             cout<<2<<". Set new Password"<<endl;
             cout<<3<<". Transactions done"<<endl;
             cout<<4<<". Log Out"<<endl<<endl;
             cout<<"Enter Your Choice : ";
             cin>>c;
             cout<<endl;
             if(c == 1){
              SPList[id].setUserName();
             }
             else if(c == 2){
             SPList[id].setPassword();
             }
             else if(c == 3){
             SPList[id].TransactionDone();
             }
             else{
             break;
             }
             } 
             }  
           }
        
         else if(a == 3){
            cout<<endl<<"------------------------SPECTATOR PORTAL-------------------------------"<<endl<<endl;
            cout<<"Enter Username : ";
            string userName;
            cin>>userName;
            cout<<endl;
            if(users.find(userName) == users.end()){
                Data dt;
                dt.T_Id = -1;
                users[userName] = dt;
            }
            cout<<"Enter Password : ";
            string Password;
            cin>>Password;
            cout<<endl;
            cout<<endl<<"logging in ..."<<endl;
            usleep(500000);  
            while(true){    
            int d;
            cout<<0<<". Show My bookings"<<endl;
            cout<<1<<". check shows"<<endl;
            cout<<2<<". book show"<<endl;
            cout<<3<<". cancell ticket"<<endl;
            cout<<4<<". Log out"<<endl<<endl;
            cout<<"Enter Your Choice : ";
            cin>>d;
            cout<<endl;
            if(d == 0){
                int tid = users[userName].T_Id;
                if(tid == -1){
                	cout<<"--------------------------------------------------------"<<endl;
                    	cout<<"|                You have No booking !!!                |"<<endl;
                    	cout<<"--------------------------------------------------------"<<endl<<endl;
                }
                else{
                int id  = users[userName].id;
                SalesPerson sw = SPList[id];
                int tid = users[userName].T_Id;
                sw.Ticket(tid);
                }
            }        
            else if(d == 1){
                 for(int i = 0;i<ShowList.size();i++){
                       Show so = ShowList[i];
                       string title = so.GetTitle();
                       string time = so.getDateandTime();
                       int Aud = so.getAudinarySeatAvailable();
                       int Bal = so.getBalconySeatAvailable();
                       int pa = so.getPriceAudinarySeat();;
                       int pb = so.getPriceBalconySeat();
                       cout<<endl;
                       cout<<"Show Number              : "<<i+1<<endl;
                       cout<<"itle                     : "<<title<<endl;
                       cout<<"Audinary Seats Available : "<<Aud<<endl;
                       cout<<"Balcony Seats Available  : "<<Bal<<endl; 
                       cout<<"Price Audinary Seat      : " <<pa<<endl;
                       cout<<"Price Balcony Seat       : "<<pb<<endl<<endl;
                   }
            }
            else if(d == 2){
            
            if(ShowList.size() == 0){
                cout<<"No Shows available"<<endl;
             }   
             else{
             cout<<"Choose Show from the list"<<endl;
                    int ind;
                    cin>>ind;
                    int sz = SPList.size();
                    int id = rand()%(sz)+7893;
                    int st;
                    cout<<0<<". Audinary"<<endl;
                    cout<<1<<". Balcony"<<endl;
                    cout<<"Choose seat type : ";
                    cin>>st;    
                    cout<<endl;
                    int T_Id = SPList[id].bookTicket(st,ShowList[ind-1]);
                    if(T_Id){
                        users[userName].T_Id = T_Id;
                        users[userName].id = id;
                        users[userName].st = st;
                        users[userName].ind = ind-1;
                        cout<<"Booking........."<<endl;
                        usleep(500000); 
                        cout<<"--------------------------------------------------------"<<endl;
                    	 cout<<"|         Congrats!!!! Booking Confirmed.               |"<<endl;
                    	 cout<<"--------------------------------------------------------"<<endl<<endl;
                        cout<<"Your Ticket"<<endl;
                        SPList[id].Ticket(T_Id);
                    }
                    else{
                        cout<<"Sorry !! the service you are looking for is not available currently."<<endl;
                    } 
            }
            }
            else if(d == 3){
                    int tid = users[userName].T_Id;
                    if(tid == -1){
                        cout<<"--------------------------------------------------------"<<endl;
                    	cout<<"|                You have No booking !!!                |"<<endl;
                    	cout<<"--------------------------------------------------------"<<endl<<endl;
                    }
                    else{    
                    Show sw = ShowList[users[userName].ind];
                    int idu = users[userName].id;
                    int stp = users[userName].st;
                    SPList[idu].cancellation(tid,sw,stp);
                    users[userName].T_Id = -1;
                    cout<<" Cancelling ......" <<endl;
                    usleep(500000); 
                    cout<<"Cancelled"<<endl;
                    cout<<"we will initiate the refund process within 24 hrs acoording to our refund policy."<<endl;
                    }
            }
            else{
            break;
            }
              }
                 
            }
            else{
            break;
            }   
        }

        return 0;
}