//
//  main.cpp
//  Testproject
//
//  Created by Luis Perez on 17/10/21.
//

#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <vector>
using namespace std;
//structure//

struct Parents{
    string UserName;
    string Password;
    
};

vector<Parents>LoginParents(vector<Parents>& LoginInfo);

int main(){
    
    
   
    

}

vector<Parents>LoginParents(vector<Parents>& LoginInfo) {
    
    Parents p;
    char answer='y';
    fstream MyFlie1("ParentsLogin.csv",ios::app); //adding to existing file//
    while(tolower(answer)=='y'){
        cin.ignore();
        cout<<"Enter the Username"<<endl;
        getline(cin,p.UserName);
        cout<<"Enter Your Password"<<endl;
        getline(cin,p.Password);      /*Rule: minimum 8 characters atleast one upper case,
                                       one lower case, one special symbol and one number*/
    if(p.Password.size()>=8){
    int PasswordIndex, DigitFlag=0, LowerFlag=0, UpperFlag =0, SpecialCharacterFlag=0;
        for(PasswordIndex = 0; PasswordIndex < p.Password.size(); PasswordIndex++){
            if(isdigit(p.Password[PasswordIndex])){
                DigitFlag=1;
            }
            
            
        }
        if (DigitFlag==0)
            cout<<"Number is Missing"<<endl;
        
        //Checking if the Password contains a lower case//
        for(PasswordIndex = 0; PasswordIndex < p.Password.size(); PasswordIndex++){
            if(islower(p.Password[PasswordIndex])){
                LowerFlag=1;
            }
        }
        if(LowerFlag==0)
            cout<<"Lower Case is Missing"<<endl;
        
        
        for(PasswordIndex = 0; PasswordIndex < p.Password.size(); PasswordIndex++){
            if(isupper(p.Password[PasswordIndex])){
                UpperFlag=1;
            }
        }
        if(SpecialCharacterFlag==0)
            cout<<"Upper Case is Missing"<<endl;
        for(PasswordIndex = 0; PasswordIndex < p.Password.size(); PasswordIndex++){
            if(isupper(p.Password[PasswordIndex])){
                SpecialCharacterFlag=1;
            }
        }
        if(SpecialCharacterFlag==0)
            cout<<"Special Character is Missing"<<endl;
        
        if ((DigitFlag== 1) && (LowerFlag == 1) && (UpperFlag == 1) && (SpecialCharacterFlag == 1)) {
            cout<<"Valid Password"<<endl;
        }
        else {
            cout<< "The password must contain alteast a number, a special character, a lower case and an upper case. It is an invalid password "<<endl;
            
        }
    }
    else{
        cout<<"Password must contain 8 or more character"<<endl;
    }
        MyFlie1<< p.UserName <<"," <<p.Password<<","<<endl;
        
        MyFlie1.close();
    }
    return (LoginInfo);
}
