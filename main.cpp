#include "library.h"
#include "highschool.cpp"
int main(){
    highschool *A = new highschool();
    string ID = "";
    string studyclass = "";
    string subject = "";
    string conduct = "";
    string rank = "";
    int option = A->option();
    while(1){
        switch(option){
            case 1:{
                int opt;
                int n;
                while(1){
                    cout <<"Each time you enter the number of additional students:";
                    cin >> n;
                    if(n > 0 && n < 500){
                        for(int i = 0;i < n;i++){
                            A->addstudent(A);
                        }
                        break;
                    } else {
                        cout << "\nNumber of highschool must be greater than 0 and less than 500\n";
                    }
                }
                
                while(1){
                    cout <<"\nEach time you choose next\n";
                    cout <<"1.Export timsheets of student information\n";
                    cout <<"2.Return to the original selection\n";
                    cout <<"Please enter the drug number of your choice:";
                    cin >> opt;
                    if(opt == 1){
                        A->printallinforofstudent(A);
                    } else if(opt == 2) {
                        option = A->option();
                        break;
                    } else {
                        cout <<"\nERROR!!Please re-enter correctly\n";
                    }
                }
                break;   
            }
    
            case 2:{
                int opt;
                ID ="";
                cout <<"\nEnter the student ID you need to addpoint: ";
                cin >> ID;
                A->addpointofstudent(A,ID);
                while(1){
                    cout <<"\nEach time you choose next\n";
                    cout <<"1.Additional point other student information\n";
                    cout <<"2.Return to the original selection\n";
                    cout <<"Please enter the drug number of your choice:";
                    cin >> opt;
                    if(opt == 1){
                        cout <<"\nEnter the student ID you need to addpoint: ";
                        cin >> ID;
                        A->addpointofstudent(A,ID);
                    } else if(opt == 2) {
                        option = A->option();
                        break;
                    } else {
                        cout <<"\nERROR!!Please re-enter correctly\n";
                    }
                }
                break; 
            }

            case 3:{
                ID = "";
                int opt;
                cout <<"\nEnter the student ID you need to write: ";
                cin >> ID;
                A->writenotes(A,ID);
                while(1){
                    cout <<"\nEach time you choose next\n";
                    cout <<"1.Find and write other student\n";
                    cout <<"2.Return to the original selection\n";
                    cout <<"Please enter the drug number of your choice:";
                    cin >> opt;
                    if(opt == 1){
                        cout <<"\nEnter the student ID you need to write: ";
                        cin >> ID;
                        A->writenotes(A,ID);
                    } else if(opt == 2) {
                        option = A->option();
                        break;
                    } else {
                        cout <<"\nERROR!!Please re-enter correctly\n";
                    }
                }
                break;
            }

            case 4:{
                ID = "";
                int opt;
                cout <<"\nEnter the student ID you need to find: ";
                cin >> ID;
                A->addconductofstudent(A,ID);
                while(1){
                    cout <<"\nEach time you choose next\n";
                    cout <<"1.Additional conduct other student\n";
                    cout <<"2.Return to the original selection\n";
                    cout <<"Please enter the drug number of your choice:";
                    cin >> opt;
                    if(opt == 1){
                        cout <<"\nEnter the student ID you need to addconduct: ";
                        cin >> ID;
                        A->addconductofstudent(A,ID);
                    } else if(opt == 2) {
                        option = A->option();
                        break;
                    } else {
                        cout <<"\nERROR!!Please re-enter correctly\n";
                    }
                }
                break;
            }

            case 5:{
                A->sortrankstudent(A);
                ID = "";
                int opt;
                cout <<"\nEnter the student ID you need to find: ";
                cin >> ID;
                A->findcheckrankstudent(A,ID);
                while(1){
                    cout <<"\nEach time you choose next\n";
                    cout <<"1.Find other student\n";
                    cout <<"2.Return to the original selection\n";
                    cout <<"Please enter the drug number of your choice:";
                    cin >> opt;
                    if(opt == 1){
                        cout <<"\nEnter the student ID you need to find: ";
                        cin >> ID;
                        A->findcheckrankstudent(A,ID);
                    } else if(opt == 2) {
                        option = A->option();
                        break;
                    } else {
                        cout <<"\nERROR!!Please re-enter correctly\n";
                    }
                }
                break;
            }
            
            case 6:{
                ID = "";
                int opt;
                cout <<"\nEnter the student ID you need to delete: ";
                cin >> ID;
                A->deletstudent(A,ID);
                while(1){
                    cout <<"\nEach time you choose next\n";
                    cout <<"1.Delete other student information\n";
                    cout <<"2.Return to the original selection\n";
                    cout <<"Please enter the drug number of your choice:";
                    cin >> opt;
                    if(opt == 1){
                        cout <<"\nEnter the student ID you need to delete: ";
                        cin >> ID;
                        A->deletstudent(A,ID);
                    } else if(opt == 2) {
                        option = A->option();
                        break;
                    } else {
                        cout <<"\nERROR!!Please re-enter correctly\n";
                    }
                }
                break;
            }
                
            case 7:{
                ID = "";
                int opt;
                cout <<"\nEnter the student ID you need to edit: ";
                cin >> ID;
                A->edtstudent(A,ID);
                while(1){
                    cout <<"\nEach time you choose next\n";
                    cout <<"1.Find and edit other student information\n";
                    cout <<"2.Return to the original selection\n";
                    cout <<"Please enter the drug number of your choice:";
                    cin >> opt;
                    if(opt == 1){
                        cout <<"\nEnter the student ID you need to edit: ";
                        cin >> ID;
                        A->edtstudent(A,ID);
                        A->sortrankstudent(A);
                    } else if(opt == 2) {
                        option = A->option();
                        break;
                    } else {
                        cout <<"\nERROR!!Please re-enter correctly\n";
                    }
                }
                break;
            }
                
            case 8:{
                ID = "";
                int opt;
                cout <<"\nEnter the student ID you need to find: ";
                cin >> ID;
                A->printonestudent(A,ID);
                while(1){
                    cout <<"\nEach time you choose next\n";
                    cout <<"1.Find other student information\n";
                    cout <<"2.Return to the original selection\n";
                    cout <<"Please enter the drug number of your choice:";
                    cin >> opt;
                    if(opt == 1){
                        cout <<"\nEnter the student ID you need to find: ";
                        cin >> ID;
                        A->printonestudent(A,ID);
                    } else if(opt == 2) {
                        option = A->option();
                        break;
                    } else {
                        cout <<"\nERROR!!Please re-enter correctly\n";
                    }
                }
                break;
            }

            case 9:{
                int opt;
                A->printsortfollowstudentgpa(A);
                while(1){
                    cout <<"\nReturn to the first choice?\n";
                    cout <<"1.Yes\n";
                    cout <<"2.No and exit\n";
                    cout <<"Please enter the drug number of your choice:";
                    cin >> opt;
                    if(opt == 1){
                        option = A->option();
                        break;
                    } else if(opt == 2) {
                        option = 0;
                        break;
                    } else {
                        cout <<"\nERROR!!Please re-enter correctly\n";
                    }
                }
                break; 
            }

            case 10:{
                studyclass = "";
                int opt;
                while(1){
                    cout<<"\n\t-------------CLASS-------------\n";
                    cout<<"L6 = class 6, L7 = class 7, L8 = class 8, L9 = class 9, L10 = class 10, L11 = class 11, L12 = class 12\n";
                    cout <<"\nEnter the student class you need to find: ";
                    cin >> studyclass;
                    if (studyclass == "L6"||studyclass == "L7"||studyclass == "L8"||studyclass == "L9"||studyclass == "L10"||studyclass == "L11"||studyclass == "L12"){
                        break;
                    } else {
                        cout  << "\nERROR! Please input again.\n";
                    }
                }
                A->findhigheststudentgpa(A,studyclass);
                while(1){
                    cout <<"\nEach time you choose next\n";
                    cout <<"1.Find other student\n";
                    cout <<"2.Return to the original selection\n";
                    cout <<"Please enter the drug number of your choice:";
                    cin >> opt;
                    if(opt == 1){
                        cout <<"\nEnter the student class you need to find: ";
                        cin >> studyclass;
                        A->findhigheststudentgpa(A,studyclass);
                    } else if(opt == 2) {
                        option = A->option();
                        break;
                    } else {
                        cout <<"\nERROR!!Please re-enter correctly\n";
                    }
                }
                break;
            }

            case 11:{
                studyclass = "";
                int opt;
                while(1){
                    cout<<"\n\t-------------CLASS-------------\n";
                    cout<<"L6 = class 6, L7 = class 7, L8 = class 8, L9 = class 9, L10 = class 10, L11 = class 11, L12 = class 12\n";
                    cout <<"\nEnter the student class you need to find: ";
                    cin >> studyclass;
                    if (studyclass == "L6"||studyclass == "L7"||studyclass == "L8"||studyclass == "L9"||studyclass == "L10"||studyclass == "L11"||studyclass == "L12"){
                        break;
                    } else {
                        cout  << "\nERROR! Please input again.\n";
                    }
                }
                A->findloweststudentgpa(A,studyclass);
                while(1){
                    cout <<"\nEach time you choose next\n";
                    cout <<"1.Find other student\n";
                    cout <<"2.Return to the original selection\n";
                    cout <<"Please enter the drug number of your choice:";
                    cin >> opt;
                    if(opt == 1){
                        cout <<"\nEnter the student class you need to find: ";
                        cin >> studyclass;
                        A->findloweststudentgpa(A,studyclass);
                    } else if(opt == 2) {
                        option = A->option();
                        break;
                    } else {
                        cout <<"\nERROR!!Please re-enter correctly\n";
                    }
                }
                break;
            }

            case 12:{
                studyclass = "";
                subject = "";
                int opt;
                while(1){
                    cout<<"\n\t-------------CLASS-------------\n";
                    cout<<"L6 = class 6, L7 = class 7, L8 = class 8, L9 = class 9, L10 = class 10, L11 = class 11, L12 = class 12\n";
                    cout <<"\nEnter the student class you need to find: ";
                    cin >> studyclass;
                    if (studyclass == "L6"||studyclass == "L7"||studyclass == "L8"||studyclass == "L9"||studyclass == "L10"||studyclass == "L11"||studyclass == "L12"){
                        break;
                    } else {
                        cout  << "\nERROR! Please input again.\n";
                    }
                }
                while(1){
                    cout<<"\n\t-------------SUBJECT-------------\n";
                    cout<<"geography, math, history, english, literary, physical, chemical, information, fitness, biological, civiceducation, defense, technology\n";
                    cout <<"\nEnter the student subject you need to find: ";
                    cin >> subject;
                    if (subject == "geography"||subject == "math"||subject == "history"||subject == "english"||subject == "literary"||subject == "physical"||subject == "chemical"||subject == "information"||subject == "fitness"||subject == "biological"||subject == "civiceducation"||subject == "defense"||subject == "technology"){
                        break;
                    } else {
                        cout  << "\nERROR! Please input again.\n";
                    }
                }
                A->findhigheststudentsubject(A,studyclass,subject);
                while(1){
                    cout <<"\nEach time you choose next\n";
                    cout <<"1.Find other student\n";
                    cout <<"2.Return to the original selection\n";
                    cout <<"Please enter the drug number of your choice:";
                    cin >> opt;
                    if(opt == 1){
                        cout<<"\n\t-------------CLASS-------------\n";
                        cout<<"L6 = class 6, L7 = class 7, L8 = class 8, L9 = class 9, L10 = class 10, L11 = class 11, L12 = class 12\n";
                        cout<<"\n\t-------------SUBJECT-------------\n";
                        cout<<"geography, math, history, english, literary, physical, chemical, information, fitness, biological, civiceducation, defense, technology\n";
                        cout <<"\nEnter the student class you need to find: ";
                        cin >> studyclass;
                        cout <<"\nEnter the student subject you need to find: ";
                        cin >> subject;
                        A->findhigheststudentsubject(A,studyclass,subject);
                    } else if(opt == 2) {
                        option = A->option();
                        break;
                    } else {
                        cout <<"\nERROR!!Please re-enter correctly\n";
                    }
                }
                break;
            }

            case 13:{
                studyclass = "";
                subject = "";
                int opt;
                while(1){
                    cout<<"\n\t-------------CLASS-------------\n";
                    cout<<"L6 = class 6, L7 = class 7, L8 = class 8, L9 = class 9, L10 = class 10, L11 = class 11, L12 = class 12\n";
                    cout <<"\nEnter the student class you need to find: ";
                    cin >> studyclass;
                    if (studyclass == "L6"||studyclass == "L7"||studyclass == "L8"||studyclass == "L9"||studyclass == "L10"||studyclass == "L11"||studyclass == "L12"){
                        break;
                    } else {
                        cout  << "\nERROR! Please input again.\n";
                    }
                }
                while(1){
                    cout<<"\n\t-------------SUBJECT-------------\n";
                    cout<<"geography, math, history, english, literary, physical, chemical, information, fitness, biological, civiceducation, defense, technology\n";
                    cout <<"\nEnter the student subject you need to find: ";
                    cin >> subject;
                    if (subject == "geography"||subject == "math"||subject == "history"||subject == "english"||subject == "literary"||subject == "physical"||subject == "chemical"||subject == "information"||subject == "fitness"||subject == "biological"||subject == "civiceducation"||subject == "defense"||subject == "technology"){
                        break;
                    } else {
                        cout  << "\nERROR! Please input again.\n";
                    }
                }
                A->findloweststudentsubject(A,studyclass,subject);
                while(1){
                    cout <<"\nEach time you choose next\n";
                    cout <<"1.Find other student\n";
                    cout <<"2.Return to the original selection\n";
                    cout <<"Please enter the drug number of your choice:";
                    cin >> opt;
                    if(opt == 1){
                        cout<<"\n\t-------------CLASS-------------\n";
                        cout<<"L6 = class 6, L7 = class 7, L8 = class 8, L9 = class 9, L10 = class 10, L11 = class 11, L12 = class 12\n";
                        cout<<"\n\t-------------SUBJECT-------------\n";
                        cout<<"geography, math, history, english, literary, physical, chemical, information, fitness, biological, civiceducation, defense, technology\n";
                        cout <<"\nEnter the student class you need to find: ";
                        cin >> studyclass;
                        cout <<"\nEnter the student subject you need to find: ";
                        cin >> subject;
                        A->findloweststudentsubject(A,studyclass,subject);
                    } else if(opt == 2) {
                        option = A->option();
                        break;
                    } else {
                        cout <<"\nERROR!!Please re-enter correctly\n";
                    }
                }
                break;
            }

            case 14:{
                studyclass = "";
                conduct = "";
                int opt;
                while(1){
                    cout<<"\n\t-------------CLASS-------------\n";
                    cout<<"L6 = class 6, L7 = class 7, L8 = class 8, L9 = class 9, L10 = class 10, L11 = class 11, L12 = class 12\n";
                    cout <<"\nEnter the student class you need to find: ";
                    cin >> studyclass;
                    if (studyclass == "L6"||studyclass == "L7"||studyclass == "L8"||studyclass == "L9"||studyclass == "L10"||studyclass == "L11"||studyclass == "L12"){
                        break;
                    } else {
                        cout  << "\nERROR! Please input again.\n";
                    }
                }
                while(1){
                    cout<<"\n\t-------------CONDUCT-------------\n";
                    cout<<"T(Very good), K(Good), TB(Average), Y(Weak)\n";
                    cout <<"\nEnter the student conduct you need to find: ";
                    cin >> conduct;
                    if (conduct == "T"||conduct == "K"||conduct == "TB"||conduct == "Y"){
                        break;
                    } else {
                        cout  << "\nERROR! Please input again.\n";
                    }
                }
                A->findconductstudentinclass(A,studyclass,conduct);
                while(1){
                    cout <<"\nEach time you choose next\n";
                    cout <<"1.Find other student\n";
                    cout <<"2.Return to the original selection\n";
                    cout <<"Please enter the drug number of your choice:";
                    cin >> opt;
                    if(opt == 1){
                        while(1){
                            cout<<"\n\t-------------CLASS-------------\n";
                            cout<<"L6 = class 6, L7 = class 7, L8 = class 8, L9 = class 9, L10 = class 10, L11 = class 11, L12 = class 12\n";
                            cout <<"\nEnter the student class you need to find: ";
                            cin >> studyclass;
                            if (studyclass == "L6"||studyclass == "L7"||studyclass == "L8"||studyclass == "L9"||studyclass == "L10"||studyclass == "L11"||studyclass == "L12"){
                                break;
                            } else {
                                cout  << "\nERROR! Please input again.\n";
                            }
                        }
                        while(1){
                            cout<<"\n\t-------------CONDUCT-------------\n";
                            cout<<"T(Very good), K(Good), TB(Average), Y(Weak)\n";
                            cout <<"\nEnter the student conduct you need to find: ";
                            cin >> conduct;
                            if (conduct == "T"||conduct == "K"||conduct == "TB"||conduct == "Y"){
                                break;
                            } else {
                                cout  << "\nERROR! Please input again.\n";
                            }
                        }
                        A->findconductstudentinclass(A,studyclass,conduct);
                    } else if(opt == 2) {
                        option = A->option();
                        break;
                    } else {
                        cout <<"\nERROR!!Please re-enter correctly\n";
                    }
                }
                break;
            }
            
            case 15:{
                studyclass = "";
                rank = "";
                int opt;
                while(1){
                    cout<<"\n\t-------------CLASS-------------\n";
                    cout<<"L6 = class 6, L7 = class 7, L8 = class 8, L9 = class 9, L10 = class 10, L11 = class 11, L12 = class 12\n";
                    cout <<"\nEnter the student class you need to find: ";
                    cin >> studyclass;
                    if (studyclass == "L6"||studyclass == "L7"||studyclass == "L8"||studyclass == "L9"||studyclass == "L10"||studyclass == "L11"||studyclass == "L12"){
                        break;
                    } else {
                        cout  << "\nERROR! Please input again.\n";
                    }
                }
                while(1){
                    cout<<"\n\t-------------RANK-------------\n";
                    cout<<"\tVery good, Good, Average, Weak, Poor\n";
                    cout <<"\nEnter the student rank you need to find: ";
                    cin.ignore();
                    getline(cin,rank);
                    if (strcmp(rank.c_str(),"Very good")==0||strcmp(rank.c_str(),"Good")==0||strcmp(rank.c_str(),"Average")==0||strcmp(rank.c_str(),"Weak")==0||strcmp(rank.c_str(),"Poor")==0){
                        break;
                    } else {
                        cout  << "\nERROR! Please input again.\n";
                    }
                }
                A->findrankstudentinclass(A,studyclass,rank);
                while(1){
                    cout <<"\nEach time you choose next\n";
                    cout <<"1.Find other student\n";
                    cout <<"2.Return to the original selection\n";
                    cout <<"Please enter the drug number of your choice:";
                    cin >> opt;
                    if(opt == 1){
                        while(1){
                            cout<<"\n\t-------------CLASS-------------\n";
                            cout<<"L6 = class 6, L7 = class 7, L8 = class 8, L9 = class 9, L10 = class 10, L11 = class 11, L12 = class 12\n";
                            cout <<"\nEnter the student class you need to find: ";
                            cin >> studyclass;
                            if (studyclass == "L6"||studyclass == "L7"||studyclass == "L8"||studyclass == "L9"||studyclass == "L10"||studyclass == "L11"||studyclass == "L12"){
                                break;
                            } else {
                                cout  << "\nERROR! Please input again.\n";
                            }
                        }
                        while(1){
                            cout<<"\n\t-------------RANK-------------\n";
                            cout<<"\tVery good, Good, Average, Weak, Poor\n";
                            cout <<"\nEnter the student rank you need to find: ";
                            cin.ignore();
                            getline(cin,rank);
                            if (strcmp(rank.c_str(),"Very good")==0||strcmp(rank.c_str(),"Good")==0||strcmp(rank.c_str(),"Average")==0||strcmp(rank.c_str(),"Weak")==0||strcmp(rank.c_str(),"Poor")==0){
                                break;
                            } else {
                                cout  << "\nERROR! Please input again.\n";
                            }
                        }
                        A->findrankstudentinclass(A,studyclass,rank);
                    } else if(opt == 2) {
                        option = A->option();
                        break;
                    } else {
                        cout <<"\nERROR!!Please re-enter correctly\n";
                    }
                }
                break;
            }

            case 16:{
                studyclass = "";
                int opt;
                while(1){
                    cout<<"\n\t-------------CLASS-------------\n";
                    cout<<"L6 = class 6, L7 = class 7, L8 = class 8, L9 = class 9, L10 = class 10, L11 = class 11, L12 = class 12\n";
                    cout <<"\nEnter the student class you need to find: ";
                    cin >> studyclass;
                    if (studyclass == "L6"||studyclass == "L7"||studyclass == "L8"||studyclass == "L9"||studyclass == "L10"||studyclass == "L11"||studyclass == "L12"){
                        break;
                    } else {
                        cout  << "\nERROR! Please input again.\n";
                    }
                }
                A->printtimesheetofclass(A,studyclass);
                while(1){
                    cout <<"\nEach time you choose next\n";
                    cout <<"1.Print other student class\n";
                    cout <<"2.Return to the original selection\n";
                    cout <<"Please enter the drug number of your choice:";
                    cin >> opt;
                    if(opt == 1){
                        while(1){
                            cout<<"\n\t-------------CLASS-------------\n";
                            cout<<"L6 = class 6, L7 = class 7, L8 = class 8, L9 = class 9, L10 = class 10, L11 = class 11, L12 = class 12\n";
                            cout <<"\nEnter the student class you need to find: ";
                            cin >> studyclass;
                            if (studyclass == "L6"||studyclass == "L7"||studyclass == "L8"||studyclass == "L9"||studyclass == "L10"||studyclass == "L11"||studyclass == "L12"){
                                break;
                            } else {
                                cout  << "\nERROR! Please input again.\n";
                            }
                        }
                        A->printtimesheetofclass(A,studyclass);
                    } else if(opt == 2) {
                        option = A->option();
                        break;
                    } else {
                        cout <<"\nERROR!!Please re-enter correctly\n";
                    }
                }
                break;
            }

            case 17:{
                int opt;
                A->printallstudent(A);
                while(1){
                    cout <<"\nReturn to the first choice?\n";
                    cout <<"1.Yes\n";
                    cout <<"2.No and exit\n";
                    cout <<"Please enter the drug number of your choice:";
                    cin >> opt;
                    if(opt == 1){
                        option = A->option();
                        break;
                    } else if(opt == 2) {
                        option = 0;
                        break;
                    } else {
                        cout <<"\nERROR!!Please re-enter correctly\n";
                    }
                }
                break;
            }

            case 18:{
                int opt;
                A->writeinforToFile(A,"infor.txt");
                while(1){
                    cout <<"\nReturn to the first choice?\n";
                    cout <<"1.Yes\n";
                    cout <<"2.No and exit\n";
                    cout <<"Please enter the drug number of your choice:";
                    cin >> opt;
                    if(opt == 1){
                        option = A->option();
                        break;
                    } else if(opt == 2) {
                        option = 0;
                        break;
                    } else {
                        cout <<"\nERROR!!Please re-enter correctly\n";
                    }
                }
                break;   
            }

            case 19:{
                int opt;
                A->writefullinforToFile(A,"fullinfor.txt");
                while(1){
                    cout <<"\nReturn to the first choice?\n";
                    cout <<"1.Yes\n";
                    cout <<"2.No and exit\n";
                    cout <<"Please enter the drug number of your choice:";
                    cin >> opt;
                    if(opt == 1){
                        option = A->option();
                        break;
                    } else if(opt == 2) {
                        option = 0;
                        break;
                    } else {
                        cout <<"\nERROR!!Please re-enter correctly\n";
                    }
                }
                break; 
            }

            case 0:{
                cout << "\nExit successfully!!!\n\n";
                return 0;
            }   
        }
    }
    return 0;
}