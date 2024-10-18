   #include "library.h"

class highschool{
    private:
    class student{
        private:
            string name;
            string sex;
            string id;
            string studyclass;
            string rank;
            string note;
            string conduct;
            float mid;
            float last;
            float product;
            double geographypoint;
            double mathpoint;
            double historypoint;
            double englishpoint;
            double literarypoint;
            double physicalpoint;
            double chemicalpoint;
            double informationpoint;
            double fitnesspoint;
            double biologicalpoint;
            double civiceducationpoint;
            double defensepoint;
            double technologypoint;
            double gpa;
            student *next;
            friend class highschool;
        public:
            student(){
                this->name ="";
                this->sex ="";
                this->id ="";
                this->studyclass ="";
                this->rank ="";
                this->note ="";
                this->conduct = "";
                this->mid = 0;
                this->last = 0;
                this->product = 0;
                this->geographypoint = 0;
                this->mathpoint = 0;
                this->historypoint = 0;
                this->englishpoint = 0;
                this->literarypoint = 0;
                this->physicalpoint = 0;
                this->chemicalpoint = 0;
                this->informationpoint = 0;
                this->fitnesspoint = 0;
                this->biologicalpoint = 0;
                this->civiceducationpoint = 0;
                this->defensepoint = 0;
                this->technologypoint = 0;
                this->gpa = 0;
                next = NULL;
            }
    };
    private:
        int numberofstudent;
        student* head;
    public:
    highschool(){
        numberofstudent =0;
        head=NULL;
    }
    int option();
    void writeinforToFile(highschool *list, const string& fileName);
    void writefullinforToFile(highschool *list, const string& fileName);
    float checkinput(const string& message);
    student *findstudent(highschool *list, string ID);
    float calculate(float mid, float last, float product);
    void addstudent(highschool *list);
    void addpointofstudent(highschool *list, string ID);
    void writenotes(highschool *list, string ID);
    void addconductofstudent(highschool *list, string ID);
    void deletstudent(highschool *list,string ID);
    void edtstudent(highschool *list,string ID);
    void printonestudent(highschool *list,string ID);
    void printallinforofstudent(highschool *list);
    void printtimesheetofstudentgpa(highschool *list);
    void printallstudent(highschool *list);
    void printsortfollowstudentgpa(highschool *list);
    void swapstudent(student *pretmp, student *tmp);
    void sortrankstudent(highschool *list);
    void findcheckrankstudent(highschool *list, string ID);
    void findhigheststudentgpa(highschool *list, string studyclass);
    void findloweststudentgpa(highschool *list, string studyclass);
    void findhigheststudentsubject(highschool *list, string studyclass, string subject);
    void findloweststudentsubject(highschool *list, string studyclass, string subject);
    void findconductstudentinclass(highschool *list, string studyclass, string conduct);
    void findrankstudentinclass(highschool *list, string studyclass, string rank);
    void printtimesheetofclass(highschool *list, string studyclass);
};

int highschool:: option(){
    int option;
    while(1){
        cout<<"\n\t-------------OPTION-------------\n";
        cout<<"1.Add new student resume\n";
        cout<<"2.Add point of student\n";
        cout<<"3.Write notes about students\n";
        cout<<"4.Add conduct of student\n";
        cout<<"5.Sort student ratings and find reasons why students have loan ratings\n";
        cout<<"6.Delete student information\n";
        cout<<"7.Edit student information\n";
        cout<<"8.Find student information\n";
        cout<<"9.Sort and print the student list of each class increasing by GPA\n";
        cout<<"10.Find the student with the highest GPA in the class\n";
        cout<<"11.Find the student with the lowest GPA in the class\n";
        cout<<"12.Find the student with the highest point subject in the class\n";
        cout<<"13.Find the student with the lowest point subject in the class\n";
        cout<<"14.Find and export the list of students with the behavior you want to find\n";
        cout<<"15.Export a list of students with the rank you want to find\n";
        cout<<"16.Print a list of all students in a class\n"; 
        cout<<"17.Export a list of students by class for the entire school\n";
        cout<<"18.Export a list of student information for each class to the file\n";
        cout<<"19.Export information and transcripts of students from each class to the file\n";
        cout<<"0.Exit\n";
        cout<<"Please enter the drug number of your choice:";
        cin >> option;
        if(option == 1 || option == 2 || option == 3 || option == 4 || option == 5 || option == 6 || option == 7 || option == 8 || option == 9 || option == 10 || option == 11 || option == 12 || option == 13 || option == 14 || option == 15 || option == 16 || option == 17 || option == 18 || option == 19 || option == 0 ){
            break;
        } else {
            cout << "\nERROR!!Please re-enter correctly\n";
        }
    }
    return option;
}

void highschool:: writeinforToFile(highschool *list,const string& fileName) {

    ofstream file(fileName);
    if (!file.is_open()) {
        cout << "Error: Unable to open file.\n";
        return;
    }

    string classes[] = {"L6", "L7", "L8", "L9", "L10", "L11", "L12"};

    for (const string& studyClass : classes) {
        bool foundStudent = false;

        file << "\t\t------CLASS " << studyClass << "------\n";
        file <<"\nName:\t"<<"\tID:\t"<<"\tGPA:\n";

        for (student *tmp = list->head; tmp != NULL; tmp = tmp->next) {
            if (tmp->studyclass == studyClass) {
                file << tmp->name <<"\t\t"<<tmp->id<<"\t\t"<<tmp->gpa<<"\n";
                foundStudent = true;
            }
        }
        if (!foundStudent) {
            file << "\nNo student in the class " << studyClass << "!!\n";
        }
    }
    file.close();
    cout << "\nOutput file successfully!!\n";
} 

void highschool:: writefullinforToFile(highschool *list,const string& fileName) {

    ofstream file(fileName);
    if (!file.is_open()) {
        cout << "Error: Unable to open file.\n";
        return;
    }

    string classes[] = {"L6", "L7", "L8", "L9", "L10", "L11", "L12"};

    for (const string& studyClass : classes) {
        bool foundStudent = false;
        file << "\t\t------CLASS " << studyClass << "------\n";
        for (student *tmp = list->head; tmp != NULL; tmp = tmp->next) {
            if (tmp->studyclass == studyClass) {
                file <<"\nName: "<< tmp -> name << "\n";
                file <<"ID: "<< tmp -> id << "\n";
                file <<"Sex: "<< tmp -> sex <<"\n";
                file <<"Class: "<< tmp -> studyclass <<"\n";
                file <<"Point of geography : "<< tmp -> geographypoint <<"\n";
                file <<"Point of math : "<< tmp -> geographypoint <<"\n";
                file <<"Point of history : "<< tmp -> geographypoint <<"\n";
                file <<"Point of english : "<< tmp -> geographypoint <<"\n";
                file <<"Point of literary : "<< tmp -> geographypoint <<"\n";
                file <<"Point of physical : "<< tmp -> geographypoint <<"\n";
                file <<"Point of chemical: : "<< tmp -> geographypoint <<"\n";
                file <<"Point of information : "<< tmp -> geographypoint <<"\n";
                file <<"Point of fitness : "<< tmp -> geographypoint <<"\n";
                file <<"Point of biological : "<< tmp -> geographypoint <<"\n";
                file <<"Point of civiceducation : "<< tmp -> geographypoint <<"\n";
                file <<"Point of defense : "<< tmp -> geographypoint <<"\n";
                file <<"Point of technology : "<< tmp -> geographypoint <<"\n";
                file <<"GPA: "<< tmp -> gpa << "\n";
                file <<"Rank: "<< tmp -> rank << "\n";
                file <<"Conduct: "<< tmp->conduct << "\n";
                foundStudent = true;
            }
        }
        if (!foundStudent) {
            file << "\nNo student in the class " << studyClass << "!!\n";
        }
    }
    file.close();
    cout << "\nOutput file successfully!!\n";
}

float highschool::checkinput(const string& content) {
    string input;
    float value;
    while (1) {
        cout << content;
        cin >> input;
        istringstream iss(input);
        if (iss >> value && value >= 0 && value <= 10) {
            return value;
        } else {
            cout << "\nError!!Please enter a valid number between 0 and 10.\n\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

highschool::student* highschool::findstudent(highschool *list, string ID){
    student *tmp = list->head;
    while(tmp != NULL) {
        if(strcmp(ID.c_str(), tmp->id.c_str()) == 0 ){
            return tmp;
            break;
        } else{
            tmp = tmp->next;
        }
    }
    return NULL;
}

void highschool::findhigheststudentgpa(highschool *list, string studyclass){
    student *temp = head;
    float highpoint = 0;
    for(student *tmp = list->head; tmp != NULL; tmp=tmp->next){
        if(strcmp(tmp->studyclass.c_str(),studyclass.c_str()) == 0 && tmp->gpa > highpoint){
            highpoint = tmp->gpa;
            temp = tmp;
        }
    }
    cout <<"\nName: "<< temp -> name << "\n";
    cout <<"ID: "<< temp -> id << "\n";
    cout <<"Sex: "<< temp -> sex <<"\n";
    cout <<"Class: "<< temp -> studyclass <<"\n";
    cout <<"GPA: "<< temp -> gpa <<"\n";
}

void highschool::findloweststudentgpa(highschool *list, string studyclass){
    student *temp =  head;
    float  lowpoint = 10;
    for(student *tmp = list->head; tmp != NULL; tmp=tmp->next){
        if(strcmp(tmp->studyclass.c_str(),studyclass.c_str()) == 0 && tmp->gpa < lowpoint){
            lowpoint = tmp->gpa;
            temp = tmp;
        }
    }
    cout <<"\nName: "<< temp -> name << "\n";
    cout <<"ID: "<< temp -> id << "\n";
    cout <<"Sex: "<< temp -> sex <<"\n";
    cout <<"Class: "<< temp -> studyclass <<"\n";
    cout <<"GPA: "<< temp -> gpa <<"\n";
}

void highschool::findhigheststudentsubject(highschool *list, string studyclass, string subject){
    student *temp =  head;
    float highpoint = 0;
    for(student *tmp = list->head; tmp != NULL; tmp=tmp->next){
        if(strcmp(tmp->studyclass.c_str(),studyclass.c_str())==0){
            if(subject == "geography"){
                if(tmp->geographypoint > highpoint){
                    highpoint = tmp->geographypoint;
                    temp = tmp;
                }
            }
            if(subject == "math"){
                if(tmp->mathpoint > highpoint){
                    highpoint = tmp->mathpoint;
                    temp = tmp;
                }
            }
            if(subject == "history"){
                if(tmp->historypoint > highpoint){
                    highpoint = tmp->historypoint;
                    temp = tmp;
                }
            }
            if(subject == "english"){
                if(tmp->englishpoint > highpoint){
                    highpoint = tmp->englishpoint;
                    temp = tmp;
                }
            }
            if(subject == "literary"){
                if(tmp->literarypoint > highpoint){
                    highpoint = tmp->literarypoint;
                    temp = tmp;
                }
            }
            if(subject == "physical"){
                if(tmp->physicalpoint > highpoint){
                    highpoint = tmp->physicalpoint;
                    temp = tmp;
                }
            }
            if(subject == "chemical"){
                if(tmp->chemicalpoint > highpoint){
                    highpoint = tmp->chemicalpoint;
                    temp = tmp;
                }
            }
            if(subject == "information"){
                if(tmp->informationpoint > highpoint){
                    highpoint = tmp->informationpoint;
                    temp = tmp;
                }
            }
            if(subject == "fitness"){
                if(tmp->fitnesspoint > highpoint){
                    highpoint = tmp->fitnesspoint;
                    temp = tmp;
                }
            }
            if(subject == "biological"){
                if(tmp->biologicalpoint > highpoint){
                    highpoint = tmp->biologicalpoint;
                    temp = tmp;
                }
            }
            if(subject == "civiceducation"){
                if(tmp->civiceducationpoint > highpoint){
                    highpoint = tmp->civiceducationpoint;
                    temp = tmp;
                }
            }
            if(subject == "defense"){
                if(tmp->defensepoint > highpoint){
                    highpoint = tmp->defensepoint;
                    temp = tmp;
                }
            }
            if(subject == "technology"){
                if(tmp->technologypoint > highpoint){
                    highpoint = tmp->technologypoint;
                    temp = tmp;
                }
            }
        }
    }
    cout<<"\nThe student with the highest score in the subject is: \n";
    cout<<"The subject is: " << subject <<"\n";
    cout <<"Name: "<< temp -> name << "\n";
    cout <<"ID: "<< temp -> id << "\n";
    cout <<"Sex: "<< temp -> sex <<"\n";
    cout <<"Class: "<< temp -> studyclass <<"\n";
    cout <<"Point: "<< highpoint <<"\n";
}

void highschool::findloweststudentsubject(highschool *list, string studyclass, string subject){
    student *temp =  head;
    float lowpoint = 10;
    for(student *tmp = list->head; tmp != NULL; tmp=tmp->next){
        if(strcmp(tmp->studyclass.c_str(),studyclass.c_str())==0){
            if(subject == "geography"){
                if(tmp->geographypoint < lowpoint){
                    lowpoint = tmp->geographypoint;
                    temp = tmp;
                }
            }
            if(subject == "math"){
                if(tmp->mathpoint < lowpoint){
                    lowpoint = tmp->mathpoint;
                    temp = tmp;
                }
            }
            if(subject == "history"){
                if(tmp->historypoint < lowpoint){
                    lowpoint = tmp->historypoint;
                    temp = tmp;
                }
            }
            if(subject == "english"){
                if(tmp->englishpoint < lowpoint){
                    lowpoint = tmp->englishpoint;
                    temp = tmp;
                }
            }
            if(subject == "literary"){
                if(tmp->literarypoint < lowpoint){
                    lowpoint = tmp->literarypoint;
                    temp = tmp;
                }
            }
            if(subject == "physical"){
                if(tmp->physicalpoint < lowpoint){
                    lowpoint = tmp->physicalpoint;
                    temp = tmp;
                }
            }
            if(subject == "chemical"){
                if(tmp->chemicalpoint < lowpoint){
                    lowpoint = tmp->chemicalpoint;
                    temp = tmp;
                }
            }
            if(subject == "information"){
                if(tmp->informationpoint < lowpoint){
                    lowpoint = tmp->informationpoint;
                    temp = tmp;
                }
            }
            if(subject == "fitness"){
                if(tmp->fitnesspoint < lowpoint){
                    lowpoint = tmp->fitnesspoint;
                    temp = tmp;
                }
            }
            if(subject == "biological"){
                if(tmp->biologicalpoint < lowpoint){
                    lowpoint = tmp->biologicalpoint;
                    temp = tmp;
                }
            }
            if(subject == "civiceducation"){
                if(tmp->civiceducationpoint < lowpoint){
                    lowpoint = tmp->civiceducationpoint;
                    temp = tmp;
                }
            }
            if(subject == "defense"){
                if(tmp->defensepoint < lowpoint){
                    lowpoint = tmp->defensepoint;
                    temp = tmp;
                }
            }
            if(subject == "technology"){
                if(tmp->technologypoint < lowpoint){
                    lowpoint = tmp->technologypoint;
                    temp = tmp;
                }
            }
        }
    }
    cout<<"\nThe student with the lowest score in the subject is: \n";
    cout<<"The subject is: " << subject <<"\n";
    cout <<"Name: "<< temp -> name << "\n";
    cout <<"ID: "<< temp -> id << "\n";
    cout <<"Sex: "<< temp -> sex <<"\n";
    cout <<"Class: "<< temp -> studyclass <<"\n";
    cout <<"Point: "<< lowpoint <<"\n";
}

float highschool::calculate(float mid, float last, float product){
    float point = mid*0.3 + last*0.6 + product*0.1;
    return point;
}

void highschool::printonestudent(highschool *list,string ID){
    student *tmp = list->head;
    tmp = findstudent(list,ID);
    if (tmp == NULL){
        cout << "\nCouldn't find anyone with that ID number\n";
        return;
    } else {
        cout <<"\nName: "<< tmp -> name << "\n";
        cout <<"ID: "<< tmp -> id << "\n";
        cout <<"Sex: "<< tmp -> sex <<"\n";
        cout <<"Class: "<< tmp -> studyclass <<"\n";
        cout <<"GPA: "<< tmp -> gpa <<"\n";
        cout <<"Rank: "<< tmp -> rank << "\n";
        cout <<"Conduct: "<< tmp->conduct << "\n";
    }
}

void highschool::printallinforofstudent(highschool *list){
    student *tmp = list->head;
    if (tmp == NULL){
        cout << "\nThere is no listing on the highschool timesheet\n";
        return;
    }
    while(tmp != NULL){
        cout <<"\nName: "<< tmp -> name << "\n";
        cout <<"ID: "<< tmp -> id << "\n";
        cout <<"Sex: "<< tmp -> sex <<"\n";
        cout <<"Class: "<< tmp -> studyclass <<"\n";
        tmp = tmp->next;
    }
}

void highschool::printtimesheetofstudentgpa(highschool *list){

    string classes[] = {"L6", "L7", "L8", "L9", "L10", "L11", "L12"};

    for (const string& studyClass : classes) {
        bool foundStudent = false;

        cout << "\t\t------CLASS " << studyClass << "------\n";
        cout <<"\nName:\t"<<"\tID:\t"<<"\tGPA:\n";

        for (student *tmp = list->head; tmp != NULL; tmp = tmp->next) {
            if (tmp->studyclass == studyClass) {
                cout << tmp->name <<"\t\t"<<tmp->id<<"\t\t"<<tmp->gpa<<"\n";
                foundStudent = true;
            }
        }
        if (!foundStudent) {
            cout << "\nNo student in the class " << studyClass << "!!\n";
        }
    }
}

void highschool::printallstudent(highschool *list){

    string classes[] = {"L6", "L7", "L8", "L9", "L10", "L11", "L12"};

    for (const string& studyClass : classes) {
        bool foundStudent = false;

        cout << "\t\t------CLASS " << studyClass << "------\n";

        for (student *tmp = list->head; tmp != NULL; tmp = tmp->next) {
            if (tmp->studyclass == studyClass) {
                cout <<"\nName: "<< tmp -> name << "\n";
                cout <<"ID: "<< tmp -> id << "\n";
                cout <<"Sex: "<< tmp -> sex <<"\n";
                cout <<"Point of geography : "<< tmp -> geographypoint <<"\n";
                cout <<"Point of math : "<< tmp -> geographypoint <<"\n";
                cout <<"Point of history : "<< tmp -> geographypoint <<"\n";
                cout <<"Point of english : "<< tmp -> geographypoint <<"\n";
                cout <<"Point of literary : "<< tmp -> geographypoint <<"\n";
                cout <<"Point of physical : "<< tmp -> geographypoint <<"\n";
                cout <<"Point of chemical: : "<< tmp -> geographypoint <<"\n";
                cout <<"Point of information : "<< tmp -> geographypoint <<"\n";
                cout <<"Point of fitness : "<< tmp -> geographypoint <<"\n";
                cout <<"Point of biological : "<< tmp -> geographypoint <<"\n";
                cout <<"Point of civiceducation : "<< tmp -> geographypoint <<"\n";
                cout <<"Point of defense : "<< tmp -> geographypoint <<"\n";
                cout <<"Point of technology : "<< tmp -> geographypoint <<"\n";
                cout <<"GPA: "<< tmp -> gpa << "\n";
                cout <<"Rank: "<< tmp -> rank << "\n";
                cout <<"Conduct: "<< tmp->conduct << "\n";
                foundStudent = true;
            }
        }
        if (!foundStudent) {
            cout << "\nNo student in the class " << studyClass << "!!\n";
        }
    }
}

void highschool::findconductstudentinclass(highschool *list, string studyclass, string conduct){

    cout << "\n\t-----" << studyclass << "-----\n";
    cout<<"\nList of students whose behavior you want to find: \n";
    for(student *tmp = list->head; tmp != NULL; tmp=tmp->next){
        if(strcmp(tmp->studyclass.c_str(),studyclass.c_str())==0){
            if(conduct == "T"){
                cout<<"The conduct is: " << conduct <<"\n";
                cout <<"Name: "<< tmp -> name << "\n";
                cout <<"ID: "<< tmp -> id << "\n";
                cout <<"Sex: "<< tmp -> sex <<"\n";
            }

            if(conduct == "K"){
                cout<<"The conduct is: " << conduct <<"\n";
                cout <<"Name: "<< tmp -> name << "\n";
                cout <<"ID: "<< tmp -> id << "\n";
                cout <<"Sex: "<< tmp -> sex <<"\n";
            }
            if(conduct == "TB"){
                cout<<"The conduct is: " << conduct <<"\n";
                cout <<"Name: "<< tmp -> name << "\n";
                cout <<"ID: "<< tmp -> id << "\n";
                cout <<"Sex: "<< tmp -> sex <<"\n";
            }
            if(conduct == "Y"){
                cout<<"The conduct is: " << conduct <<"\n";
                cout <<"Name: "<< tmp -> name << "\n";
                cout <<"ID: "<< tmp -> id << "\n";
                cout <<"Sex: "<< tmp -> sex <<"\n";
            }
        }
    }
}

void highschool::findrankstudentinclass(highschool *list, string studyclass, string rank){
    sortrankstudent(list);
    cout << "\n\t-----" << studyclass << "-----\n";
    cout<<"\nList of students whose rank you want to find: \n";
    for(student *tmp = list->head; tmp != NULL; tmp=tmp->next){
        if(strcmp(tmp->studyclass.c_str(),studyclass.c_str())==0){
            if(rank == "Poor"){
                cout<<"The rank is: " << rank <<"\n";
                cout <<"Name: "<< tmp -> name << "\n";
                cout <<"ID: "<< tmp -> id << "\n";
                cout <<"Sex: "<< tmp -> sex <<"\n";
            }
            if(rank == "Weak"){
                cout<<"The rank is: " << rank <<"\n";
                cout <<"Name: "<< tmp -> name << "\n";
                cout <<"ID: "<< tmp -> id << "\n";
                cout <<"Sex: "<< tmp -> sex <<"\n";
            }
            if(rank == "Average"){
                cout<<"The rank is: " << rank <<"\n";
                cout <<"Name: "<< tmp -> name << "\n";
                cout <<"ID: "<< tmp -> id << "\n";
                cout <<"Sex: "<< tmp -> sex <<"\n";
            }
            if(rank == "Good"){
                cout<<"The rank is: " << rank <<"\n";
                cout <<"Name: "<< tmp -> name << "\n";
                cout <<"ID: "<< tmp -> id << "\n";
                cout <<"Sex: "<< tmp -> sex <<"\n";
            }
            if(rank == "Very good"){
                cout<<"The rank is: " << rank <<"\n";
                cout <<"Name: "<< tmp -> name << "\n";
                cout <<"ID: "<< tmp -> id << "\n";
                cout <<"Sex: "<< tmp -> sex <<"\n";
            }
        }
    }
}

void highschool ::addstudent (highschool *list){
    if(numberofstudent <= 500){
        if(list->head == NULL) {    
            student *tmp = new student();
            while(1){
                cout << "\nEnter a name of  the student: ";
                cin.ignore();
                getline(cin,tmp->name);
                if(tmp->name.length() > 20 || tmp->name == "")
                    cout << "\nName is wrong, please enter a name with less than 20 characters.\n";
                else{
                    break;
                }
            }
            while(1){
                cout <<"Enter about sex of the student:";
                cin >> tmp->sex;
                if(tmp->sex.length() != 1 || (tmp->sex != "M" && tmp->sex != "F"))
                    cout << "\nSex is wrong! Please enter only one character(M = Male, F = Female).\n";
                else{
                    break;
                }
            }
            while(1){
                cout << "Enter about level of the student:";
                cin >> tmp->studyclass;
                if((tmp->studyclass.length() != 2 && tmp->studyclass.length() != 3) || (tmp->studyclass != "L6"&&tmp->studyclass != "L7"&&tmp->studyclass != "L8"&&tmp->studyclass != "L9"&&tmp->studyclass != "L10"&&tmp->studyclass != "L11"&&tmp->studyclass != "L12"))
                    cout << "\nClass is wrong! Please enter only two character\n(L6 = class 6, L7 = class 7, L8 = class 8, L9 = class 9, L10 = class 10, L11 = class 11, L12 = class 12).\n";
                else{
                    break;
                }   
            }
            while(1){
                cout << "Enter ID of the student:";
                cin >> tmp->id;
                if(tmp->id.length() > 8)
                    cout << "\nID is too long, please enter a it with less than 8 characters.\n";
                else{
                    break;
                }
            }
            list->head = tmp;
        } else{ 
            student *tmp = list->head;
            while(tmp->next != NULL)
                tmp = tmp->next;
            student *tmpnext = new student();
            while(1){
                cout << "\nEnter a name of  the student: ";
                cin.ignore();
                getline(cin,tmpnext->name);
                if(tmpnext->name.length() > 20)
                    cout << "\nName is too long, please enter a name with less than 20 characters.\n";
                else{
                    break;
                }
            }
            while(1){
                cout <<"Enter about sex of the student:";
                cin >> tmpnext->sex;
                if(tmpnext->sex.length() != 1 || (tmpnext->sex != "M" && tmpnext->sex != "F"))
                    cout << "\nSex is wrong! Please enter only one character(M = Male, F = Female).\n";
                else{
                    break;
                }
            }
            while(1){
                cout << "Enter about level of the student:";
                cin >> tmpnext->studyclass;
                if((tmpnext->studyclass.length() != 2 && tmpnext->studyclass.length() != 3) || (tmpnext->studyclass != "L6"&&tmpnext->studyclass != "L7"&&tmpnext->studyclass != "L8"&&tmpnext->studyclass != "L9"&&tmpnext->studyclass != "L10"&&tmpnext->studyclass != "L11"&&tmpnext->studyclass != "L12"))
                    cout << "\nClass is wrong! Please enter only two character\n(L6 = class 6, L7 = class 7, L8 = class 8, L9 = class 9, L10 = class 10, L11 = class 11, L12 = class 12).\n";
                else{
                    break;
                }   
            }
            while(1){
                cout << "Enter ID of the student:";
                cin >> tmpnext->id;
                if(tmpnext->id.length() > 8)
                    cout << "\nID is too long, please enter a it with less than 8 characters.\n";
                else{
                    break;
                }
            }
            tmp->next = tmpnext;
        }
        numberofstudent++;
    }else{
        cout  << "\nThe number of students is over the limit\n";
        return; 
    } 
}

void highschool::addpointofstudent(highschool *list, string ID){
    if (numberofstudent > 500){
        cout << "\nThe highschool is full\n";
        return;
    }else{
        if(this->head != NULL){
            student *tmp = new student();
            tmp = findstudent(list,ID);
            if(tmp != NULL){
                tmp->mid = checkinput("\nEnter midterm exam(30%) point of geography(0->10):");
                tmp->last = checkinput("Enter finally exam(60%) point of geography(0->10):");
                tmp->product = checkinput("Enter product point(10%) of geography(0->10):");
                tmp->geographypoint = calculate(tmp->mid,tmp->last,tmp->product);
                cout << "So point of geography:" << tmp->geographypoint <<"\n"; 

                tmp->mid = checkinput("\nEnter midterm exam(30%) point of math(0->10):");
                tmp->last = checkinput("Enter finally exam(60%) point of math(0->10):");
                tmp->product = checkinput("Enter product point(10%) of math(0->10):");
                tmp->mathpoint = calculate(tmp->mid,tmp->last,tmp->product);
                cout << "So point of math:" << tmp->mathpoint <<"\n";  

                tmp->mid = checkinput("\nEnter midterm exam(30%) point of history(0->10):");
                tmp->last = checkinput("Enter finally exam(60%) point of history(0->10):");
                tmp->product = checkinput("Enter product point(10%) of history(0->10):");
                tmp->historypoint = calculate(tmp->mid,tmp->last,tmp->product);
                cout << "So point of history:" << tmp->historypoint <<"\n"; 

                tmp->mid = checkinput("\nEnter midterm exam(30%) point of english(0->10):");
                tmp->last = checkinput("Enter finally exam(60%) point of english(0->10):");
                tmp->product = checkinput("Enter product point(10%) of english(0->10):");
                tmp->englishpoint = calculate(tmp->mid,tmp->last,tmp->product);
                cout << "So point of english:" << tmp->englishpoint <<"\n"; 

                tmp->mid = checkinput("\nEnter midterm exam(30%) point of literary(0->10):");
                tmp->last = checkinput("Enter finally exam(60%) point of literary(0->10):");
                tmp->product = checkinput("Enter product point(10%) of literary(0->10):");
                tmp->literarypoint = calculate(tmp->mid,tmp->last,tmp->product);
                cout << "So point of literary:" << tmp->literarypoint <<"\n";  

                tmp->mid = checkinput("\nEnter midterm exam(30%) point of physical(0->10):");
                tmp->last = checkinput("Enter finally exam(60%) point of physical(0->10):");
                tmp->product = checkinput("Enter product point(10%) of physical(0->10):");
                tmp->physicalpoint = calculate(tmp->mid,tmp->last,tmp->product);
                cout << "So point of physical:" << tmp->physicalpoint <<"\n";

                tmp->mid = checkinput("\nEnter midterm exam(30%) point of chemical(0->10):");
                tmp->last = checkinput("Enter finally exam(60%) point of chemical(0->10):");
                tmp->product = checkinput("Enter product point(10%) of chemical(0->10):");
                tmp->chemicalpoint = calculate(tmp->mid,tmp->last,tmp->product);
                cout << "So point of chemical:" << tmp->chemicalpoint <<"\n"; 

                tmp->mid = checkinput("\nEnter midterm exam(30%) point of information(0->10):");
                tmp->last = checkinput("Enter finally exam(60%) point of information(0->10):");
                tmp->product = checkinput("Enter product point(10%) of information(0->10):");
                tmp->informationpoint = calculate(tmp->mid,tmp->last,tmp->product);
                cout << "So point of information:" << tmp->informationpoint <<"\n"; 

                tmp->mid = checkinput("\nEnter midterm exam(30%) point of fitness(0->10):");
                tmp->last = checkinput("Enter finally exam(60%) point of fitness(0->10):");
                tmp->product = checkinput("Enter product point(10%) of fitness(0->10):");
                tmp->fitnesspoint = calculate(tmp->mid,tmp->last,tmp->product);
                cout << "So point of fitness:" << tmp->fitnesspoint <<"\n"; 

                tmp->mid = checkinput("\nEnter midterm exam(30%) point of biological(0->10):");
                tmp->last = checkinput("Enter finally exam(60%) point of biological(0->10):");
                tmp->product = checkinput("Enter product point(10%) of biological(0->10):");
                tmp->biologicalpoint = calculate(tmp->mid,tmp->last,tmp->product);
                cout << "So point of biological:" << tmp->biologicalpoint <<"\n"; 

                tmp->mid = checkinput("\nEnter midterm exam(30%) point of civiceducation(0->10):");
                tmp->last = checkinput("Enter finally exam(60%) point of civiceducation(0->10):");
                tmp->product = checkinput("Enter product point(10%) of civiceducation(0->10):");
                tmp->civiceducationpoint = calculate(tmp->mid,tmp->last,tmp->product);
                cout << "So point of civiceducation:" << tmp->civiceducationpoint <<"\n"; 

                tmp->mid = checkinput("\nEnter midterm exam(30%) point of defense(0->10):");
                tmp->last = checkinput("Enter finally exam(60%) point of defense(0->10):");
                tmp->product = checkinput("Enter product point(10%) of defense(0->10):");
                tmp->defensepoint = calculate(tmp->mid,tmp->last,tmp->product);
                cout << "So point of defense:" << tmp->defensepoint <<"\n"; 

                tmp->mid = checkinput("\nEnter midterm exam(30%) point of technology(0->10):");
                tmp->last = checkinput("Enter finally exam(60%) point of technology(0->10):");
                tmp->product = checkinput("Enter product point(10%) of technology(0->10):");
                tmp->technologypoint = calculate(tmp->mid,tmp->last,tmp->product);
                cout << "So point of technology:" << tmp->technologypoint <<"\n";  
    
                tmp->gpa = (tmp->geographypoint + tmp->mathpoint + tmp->historypoint + tmp->englishpoint + tmp->literarypoint + tmp->physicalpoint + tmp->chemicalpoint + tmp->informationpoint + tmp->fitnesspoint + tmp->biologicalpoint + tmp->civiceducationpoint + tmp->defensepoint + tmp->technologypoint)/13 ;
                if(tmp->gpa > 0 || tmp->gpa < 10){
                    cout << "\nSo the student GPA will receive is:";
                    cout << tmp->gpa << "\n";
                } else {
                    cout << "\nError!";
                    cout << "\nSo the student GPA will receive is:";
                    cout << tmp->gpa << "\n";
                    cout <<"This is true must integer and less than 10\n";
                }
                
            } else {
                cout << "\nNo student in highschool such with ID found\n";
                cout << "\nPlease double check the ID you want to enter\n";
                return;
            }
        } else{
            cout << "\nThere are no have student in list\n";
        }
    }
    
}

void highschool::writenotes(highschool *list, string ID){
    if (numberofstudent > 500) {
        cout << "\nThe highschool is full\n";
        return;
    }
    student *tmp = findstudent(list, ID);
    if (tmp == NULL) {
        cout << "\nNo student in highschool found with the provided ID\n";
        cout << "\nPlease double check the ID you want to enter\n";
        return;
    }
    
    cout << "\nUnder is student information need to notes:\n";
    cout << "Name: " << tmp->name << "\n";
    cout << "ID: " << tmp->id << "\n";
    cout << "Sex: " << tmp->sex << "\n";
    cout << "Class: " << tmp->studyclass << "\n";

    ifstream inFile("notes.txt");
    string line, studentID, oldNotes;
    bool found = false;
    vector<string> fileContent;
    while (getline(inFile, line)) {
        size_t pos = line.find(": ");
        if (pos != string::npos) {
            studentID = line.substr(0, pos);
            if (studentID == ID) {
                oldNotes = line.substr(pos + 2);
                found = true;
            }
            fileContent.push_back(line);
        }
    }
    inFile.close();

    if (found) {
        cout << "\nOld notes found for student with ID " << ID << ": " << oldNotes << "\n";
    }
    string newNotes;
    cout << "\nWrite new notes about this student: ";
    cin.ignore();
    getline(cin, newNotes);

    ofstream outFile("notes.txt");
    if (!outFile.is_open()) {
        cout << "Error: Unable to open temporary file.\n";
        return;
    }

    bool updated = false;
    for (const auto& line : fileContent) {
        size_t pos = line.find(": ");
        if (pos != string::npos) {
            studentID = line.substr(0, pos);
            if (studentID == ID) {
                outFile << ID << ": " << oldNotes << ", " << newNotes << "\n";
                updated = true;
            } else {
                outFile << line << "\n";
            }
        }
    }

    if (!updated) {
        outFile << ID << ": " << newNotes << "\n";
    }

    outFile.close();
    cout << "Notes updated successfully.\n";
}

void highschool::addconductofstudent(highschool *list, string ID){
    if (numberofstudent > 500){
        cout << "\nThe highschool is full\n";
        return;
    }else{
        if(this->head != NULL){\
            ifstream inFile("notes.txt");
            string oldNotes;
            bool foundOldNotes = false;
            if (inFile.is_open()) {
                string line;
                while (getline(inFile, line)) {
                    size_t pos = line.find(": ");
                    if (pos != string::npos) {
                        string studentID = line.substr(0, pos);
                        if (studentID == ID) {
                            oldNotes = line.substr(pos + 2);
                            foundOldNotes = true;
                            break;
                        }
                    }
                }
                inFile.close();
            }
            student *tmp = new student();
            tmp = findstudent(list,ID);
            if(tmp != NULL){
                while(1){
                    if (foundOldNotes) {
                        tmp->note = oldNotes;
                    } else {
                        tmp->note ="There are no notes for this student!!\n";
                    }
                    cout << "\nUnder is student information need to conduct:\n";
                    cout << tmp->name << "\n";
                    cout << tmp->id << "\n";
                    cout << tmp->sex << "\n";
                    cout << tmp->studyclass << "\n";
                    cout << "\nBased on the student's notes, grade the student's behavior\n";
                    cout << "Notes about student: " <<tmp->note;
                    cout << "\nEnter about conduct of the student:";
                    cin >> tmp->conduct;
                    if((tmp->conduct.length() != 1 && tmp->conduct.length() != 2 )|| (tmp->conduct != "T"&&tmp->conduct != "K"&&tmp->conduct != "TB"&&tmp->conduct != "Y")){
                        cout << "\nConduct is wrong! Please enter only one character\n(T = Very good, K = Good, TB = Average, Y = Weak).\n";
                    } else {
                        break;
                    }
                }
            } else {
                cout << "\nNo student in highschool such with ID found\n";
                cout << "\nPlease double check the ID you want to enter\n";
                return;
            } 
        } else{
            cout << "\nThere are no have student in list\n";
        }
    }
}

void highschool::deletstudent(highschool *list, string ID){
    if(list->head == NULL){
        cout << "\nThere are no have student in list\n";
        return;
    } else {
        if(findstudent(list,ID) == NULL){
            cout <<"\nThis student is not found in the list\n";
            return;
        } else {
            student *delet = findstudent(list, ID);
            if(delet == list->head){
                list->head = delet->next;
            }else if(delet->next == NULL){
                student *predelet = list->head;
                while(predelet->next != delet){
                    predelet = predelet->next;
                }
                predelet->next = delet->next;
            } else {
                student *predelet = list->head;
                while(predelet->next != delet){
                    predelet = predelet->next;
                }
                predelet->next = delet->next;
                delet->next = NULL;
            }
            delete delet;
            numberofstudent--;
            cout << "\nDeleted successfully!\n";
        }
    }
        
}

void highschool::edtstudent(highschool *list,string ID){
    student* edt = findstudent(list,ID);
    if (edt==NULL){
        cout <<"\nThis student is not found in the list\n";
        return;
    } else {
        cout << "\nThis is not updated student information\n";
        printonestudent(list,ID);
        int opt;
        cout <<"Each time you choose next\n";
        cout <<"1.Update student resume\n";
        cout <<"2.Update student point table\n";
        cout <<"3.Update both of them\n";
        cout <<"0.Exit \n";
        cout <<"Please enter the drug number of your choice:";
        cin >> opt;

        if(opt == 1){

            while(1){
                cout << "Update a name of  the student: ";
                cin.ignore();
                getline(cin,edt->name);
                if(edt->name.length() > 20 || edt->name == "")
                    cout << "\nName is wrong, please Update a name with less than 20 characters.\n";
                else{
                    break;
                }
            }
            while(1){
                cout <<"Update about sex of the student:";
                cin >> edt->sex;
                if(edt->sex.length() != 1 || (edt->sex != "M" && edt->sex != "F"))
                    cout << "\nSex is wrong! Please Update only one character(M = Male, F = Female).\n";
                else{
                    break;
                }
            }
            while(1){
                cout << "Update about level of the student:";
                cin >> edt->studyclass;
                if((edt->studyclass.length() != 2 && edt->studyclass.length() != 3) || (edt->studyclass != "L6"&&edt->studyclass != "L7"&&edt->studyclass != "L8"&&edt->studyclass != "L9"&&edt->studyclass != "L10"&&edt->studyclass != "L11"&&edt->studyclass != "L12"))
                    cout << "\nClass is wrong! Please Update only two character\n(L6 = class 6, L7 = class 7, L8 = class 8, L9 = class 9, L10 = class 10, L11 = class 11, L12 = class 12).\n";
                else{
                    break;
                }   
            }
            while(1){
                cout << "Update ID of the student:";
                cin >> edt->id;
                if(edt->id.length() > 8)
                    cout << "\nID is too long, please Update a it with less than 8 characters.\n";
                else{
                    break;
                }
            }

        } else if(opt == 2){

            edt->mid = checkinput("\nUpdate midterm exam(30%) point of geography(0->10):");
            edt->last = checkinput("Update finally exam(60%) point of geography(0->10):");
            edt->product = checkinput("Update product point(10%) of geography(0->10):");
            edt->geographypoint = calculate(edt->mid,edt->last,edt->product);
            cout << "So point of geography:" << edt->geographypoint <<"\n"; 

            edt->mid = checkinput("\nUpdate midterm exam(30%) point of math(0->10):");
            edt->last = checkinput("Update finally exam(60%) point of math(0->10):");
            edt->product = checkinput("Update product point(10%) of math(0->10):");
            edt->mathpoint = calculate(edt->mid,edt->last,edt->product);
            cout << "So point of math:" << edt->mathpoint <<"\n";  

            edt->mid = checkinput("\nUpdate midterm exam(30%) point of history(0->10):");
            edt->last = checkinput("Update finally exam(60%) point of history(0->10):");
            edt->product = checkinput("Update product point(10%) of history(0->10):");
            edt->historypoint = calculate(edt->mid,edt->last,edt->product);
            cout << "So point of history:" << edt->historypoint <<"\n"; 

            edt->mid = checkinput("\nUpdate midterm exam(30%) point of english(0->10):");
            edt->last = checkinput("Update finally exam(60%) point of english(0->10):");
            edt->product = checkinput("Update product point(10%) of english(0->10):");
            edt->englishpoint = calculate(edt->mid,edt->last,edt->product);
            cout << "So point of english:" << edt->englishpoint <<"\n"; 

            edt->mid = checkinput("\nUpdate midterm exam(30%) point of literary(0->10):");
            edt->last = checkinput("Update finally exam(60%) point of literary(0->10):");
            edt->product = checkinput("Update product point(10%) of literary(0->10):");
            edt->literarypoint = calculate(edt->mid,edt->last,edt->product);
            cout << "So point of literary:" << edt->literarypoint <<"\n";  

            edt->mid = checkinput("\nUpdate midterm exam(30%) point of physical(0->10):");
            edt->last = checkinput("Update finally exam(60%) point of physical(0->10):");
            edt->product = checkinput("Update product point(10%) of physical(0->10):");
            edt->physicalpoint = calculate(edt->mid,edt->last,edt->product);
            cout << "So point of physical:" << edt->physicalpoint <<"\n";

            edt->mid = checkinput("\nUpdate midterm exam(30%) point of chemical(0->10):");
            edt->last = checkinput("Update finally exam(60%) point of chemical(0->10):");
            edt->product = checkinput("Update product point(10%) of chemical(0->10):");
            edt->chemicalpoint = calculate(edt->mid,edt->last,edt->product);
            cout << "So point of chemical:" << edt->chemicalpoint <<"\n"; 

            edt->mid = checkinput("\nUpdate midterm exam(30%) point of information(0->10):");
            edt->last = checkinput("Update finally exam(60%) point of information(0->10):");
            edt->product = checkinput("Update product point(10%) of information(0->10):");
            edt->informationpoint = calculate(edt->mid,edt->last,edt->product);
            cout << "So point of information:" << edt->informationpoint <<"\n"; 

            edt->mid = checkinput("\nUpdate midterm exam(30%) point of fitness(0->10):");
            edt->last = checkinput("Update finally exam(60%) point of fitness(0->10):");
            edt->product = checkinput("Update product point(10%) of fitness(0->10):");
            edt->fitnesspoint = calculate(edt->mid,edt->last,edt->product);
            cout << "So point of fitness:" << edt->fitnesspoint <<"\n"; 

            edt->mid = checkinput("\nUpdate midterm exam(30%) point of biological(0->10):");
            edt->last = checkinput("Update finally exam(60%) point of biological(0->10):");
            edt->product = checkinput("Update product point(10%) of biological(0->10):");
            edt->biologicalpoint = calculate(edt->mid,edt->last,edt->product);
            cout << "So point of biological:" << edt->biologicalpoint <<"\n"; 

            edt->mid = checkinput("\nUpdate midterm exam(30%) point of civiceducation(0->10):");
            edt->last = checkinput("Update finally exam(60%) point of civiceducation(0->10):");
            edt->product = checkinput("Update product point(10%) of civiceducation(0->10):");
            edt->civiceducationpoint = calculate(edt->mid,edt->last,edt->product);
            cout << "So point of civiceducation:" << edt->civiceducationpoint <<"\n"; 

            edt->mid = checkinput("\nUpdate midterm exam(30%) point of defense(0->10):");
            edt->last = checkinput("Update finally exam(60%) point of defense(0->10):");
            edt->product = checkinput("Update product point(10%) of defense(0->10):");
            edt->defensepoint = calculate(edt->mid,edt->last,edt->product);
            cout << "So point of defense:" << edt->defensepoint <<"\n"; 

            edt->mid = checkinput("\nUpdate midterm exam(30%) point of technology(0->10):");
            edt->last = checkinput("Update finally exam(60%) point of technology(0->10):");
            edt->product = checkinput("Update product point(10%) of technology(0->10):");
            edt->technologypoint = calculate(edt->mid,edt->last,edt->product);
            cout << "So point of technology:" << edt->technologypoint <<"\n";  

            edt->gpa = (edt->geographypoint + edt->mathpoint + edt->historypoint + edt->englishpoint + edt->literarypoint + edt->physicalpoint + edt->chemicalpoint + edt->informationpoint + edt->fitnesspoint + edt->biologicalpoint + edt->civiceducationpoint + edt->defensepoint + edt->technologypoint)/13 ;
            if(edt->gpa > 0 || edt->gpa < 10){
                cout << "\nSo the student GPA will receive is:";
                cout << edt->gpa << "\n";
            } else {
                cout << "\nError!";
                cout << "\nSo the student GPA will receive is:";
                cout << edt->gpa << "\n";
                cout <<"This is true must integer and less than 10\n";
            }

        }else if(opt == 3){

            while(1){
                cout << "Update a name of  the student: ";
                cin.ignore();
                getline(cin,edt->name);
                if(edt->name.length() > 20 || edt->name == "")
                    cout << "\nName is wrong, please Update a name with less than 20 characters.\n";
                else{
                    break;
                }
            }
            while(1){
                cout <<"Update about sex of the student:";
                cin >> edt->sex;
                if(edt->sex.length() != 1 || (edt->sex != "M" && edt->sex != "F"))
                    cout << "\nSex is wrong! Please Update only one character(M = Male, F = Female).\n";
                else{
                    break;
                }
            }
            while(1){
                cout << "Update about level of the student:";
                cin >> edt->studyclass;
                if((edt->studyclass.length() != 2 && edt->studyclass.length() != 3) || (edt->studyclass != "L6"&&edt->studyclass != "L7"&&edt->studyclass != "L8"&&edt->studyclass != "L9"&&edt->studyclass != "L10"&&edt->studyclass != "L11"&&edt->studyclass != "L12"))
                    cout << "\nClass is wrong! Please Update only two character\n(L6 = class 6, L7 = class 7, L8 = class 8, L9 = class 9, L10 = class 10, L11 = class 11, L12 = class 12).\n";
                else{
                    break;
                }   
            }
            while(1){
                cout << "Update ID of the student:";
                cin >> edt->id;
                if(edt->id.length() > 8)
                    cout << "\nID is too long, please Update a it with less than 8 characters.\n";
                else{
                    break;
                }
            }

            edt->mid = checkinput("\nUpdate midterm exam(30%) point of geography(0->10):");
            edt->last = checkinput("Update finally exam(60%) point of geography(0->10):");
            edt->product = checkinput("Update product point(10%) of geography(0->10):");
            edt->geographypoint = calculate(edt->mid,edt->last,edt->product);
            cout << "So point of geography:" << edt->geographypoint <<"\n"; 

            edt->mid = checkinput("\nUpdate midterm exam(30%) point of math(0->10):");
            edt->last = checkinput("Update finally exam(60%) point of math(0->10):");
            edt->product = checkinput("Update product point(10%) of math(0->10):");
            edt->mathpoint = calculate(edt->mid,edt->last,edt->product);
            cout << "So point of math:" << edt->mathpoint <<"\n";  

            edt->mid = checkinput("\nUpdate midterm exam(30%) point of history(0->10):");
            edt->last = checkinput("Update finally exam(60%) point of history(0->10):");
            edt->product = checkinput("Update product point(10%) of history(0->10):");
            edt->historypoint = calculate(edt->mid,edt->last,edt->product);
            cout << "So point of history:" << edt->historypoint <<"\n"; 

            edt->mid = checkinput("\nUpdate midterm exam(30%) point of english(0->10):");
            edt->last = checkinput("Update finally exam(60%) point of english(0->10):");
            edt->product = checkinput("Update product point(10%) of english(0->10):");
            edt->englishpoint = calculate(edt->mid,edt->last,edt->product);
            cout << "So point of english:" << edt->englishpoint <<"\n"; 

            edt->mid = checkinput("\nUpdate midterm exam(30%) point of literary(0->10):");
            edt->last = checkinput("Update finally exam(60%) point of literary(0->10):");
            edt->product = checkinput("Update product point(10%) of literary(0->10):");
            edt->literarypoint = calculate(edt->mid,edt->last,edt->product);
            cout << "So point of literary:" << edt->literarypoint <<"\n";  

            edt->mid = checkinput("\nUpdate midterm exam(30%) point of physical(0->10):");
            edt->last = checkinput("Update finally exam(60%) point of physical(0->10):");
            edt->product = checkinput("Update product point(10%) of physical(0->10):");
            edt->physicalpoint = calculate(edt->mid,edt->last,edt->product);
            cout << "So point of physical:" << edt->physicalpoint <<"\n";

            edt->mid = checkinput("\nUpdate midterm exam(30%) point of chemical(0->10):");
            edt->last = checkinput("Update finally exam(60%) point of chemical(0->10):");
            edt->product = checkinput("Update product point(10%) of chemical(0->10):");
            edt->chemicalpoint = calculate(edt->mid,edt->last,edt->product);
            cout << "So point of chemical:" << edt->chemicalpoint <<"\n"; 

            edt->mid = checkinput("\nUpdate midterm exam(30%) point of information(0->10):");
            edt->last = checkinput("Update finally exam(60%) point of information(0->10):");
            edt->product = checkinput("Update product point(10%) of information(0->10):");
            edt->informationpoint = calculate(edt->mid,edt->last,edt->product);
            cout << "So point of information:" << edt->informationpoint <<"\n"; 

            edt->mid = checkinput("\nUpdate midterm exam(30%) point of fitness(0->10):");
            edt->last = checkinput("Update finally exam(60%) point of fitness(0->10):");
            edt->product = checkinput("Update product point(10%) of fitness(0->10):");
            edt->fitnesspoint = calculate(edt->mid,edt->last,edt->product);
            cout << "So point of fitness:" << edt->fitnesspoint <<"\n"; 

            edt->mid = checkinput("\nUpdate midterm exam(30%) point of biological(0->10):");
            edt->last = checkinput("Update finally exam(60%) point of biological(0->10):");
            edt->product = checkinput("Update product point(10%) of biological(0->10):");
            edt->biologicalpoint = calculate(edt->mid,edt->last,edt->product);
            cout << "So point of biological:" << edt->biologicalpoint <<"\n"; 

            edt->mid = checkinput("\nUpdate midterm exam(30%) point of civiceducation(0->10):");
            edt->last = checkinput("Update finally exam(60%) point of civiceducation(0->10):");
            edt->product = checkinput("Update product point(10%) of civiceducation(0->10):");
            edt->civiceducationpoint = calculate(edt->mid,edt->last,edt->product);
            cout << "So point of civiceducation:" << edt->civiceducationpoint <<"\n"; 

            edt->mid = checkinput("\nUpdate midterm exam(30%) point of defense(0->10):");
            edt->last = checkinput("Update finally exam(60%) point of defense(0->10):");
            edt->product = checkinput("Update product point(10%) of defense(0->10):");
            edt->defensepoint = calculate(edt->mid,edt->last,edt->product);
            cout << "So point of defense:" << edt->defensepoint <<"\n"; 

            edt->mid = checkinput("\nUpdate midterm exam(30%) point of technology(0->10):");
            edt->last = checkinput("Update finally exam(60%) point of technology(0->10):");
            edt->product = checkinput("Update product point(10%) of technology(0->10):");
            edt->technologypoint = calculate(edt->mid,edt->last,edt->product);
            cout << "So point of technology:" << edt->technologypoint <<"\n";  

            edt->gpa = (edt->geographypoint + edt->mathpoint + edt->historypoint + edt->englishpoint + edt->literarypoint + edt->physicalpoint + edt->chemicalpoint + edt->informationpoint + edt->fitnesspoint + edt->biologicalpoint + edt->civiceducationpoint + edt->defensepoint + edt->technologypoint)/13 ;
            if(edt->gpa > 0 || edt->gpa < 10){
                cout << "\nSo the student GPA will receive is:";
                cout << edt->gpa << "\n";
            } else {
                cout << "\nError!";
                cout << "\nSo the student GPA will receive is:";
                cout << edt->gpa << "\n";
                cout <<"This is true must integer and less than 10\n";
            }

        } else if(opt == 0){

            return;

        } else {

            cout << "\nError!\n";
            return;
        }  
    }
}

void highschool::printsortfollowstudentgpa(highschool *list){
    for(student *pretmp = list->head; pretmp != NULL; pretmp=pretmp->next){
        for(student *tmp = pretmp->next; tmp != NULL; tmp = tmp->next){
            if(pretmp->gpa > tmp->gpa){
                swapstudent(pretmp,tmp);
            }
        }
    }
    printtimesheetofstudentgpa(list);
}

void highschool::swapstudent(student *pretmp, student *tmp){
    swap(pretmp->name,tmp->name);
    swap(pretmp->id, tmp->id);
    swap(pretmp->sex, tmp->sex);
    swap(pretmp->studyclass, tmp->studyclass);
    swap(pretmp->geographypoint, tmp->geographypoint);
    swap(pretmp->mathpoint, tmp->mathpoint);
    swap(pretmp->historypoint, tmp->historypoint);
    swap(pretmp->englishpoint, tmp->englishpoint);
    swap(pretmp->literarypoint, tmp->literarypoint);
    swap(pretmp->physicalpoint, tmp->physicalpoint);
    swap(pretmp->chemicalpoint, tmp->chemicalpoint);
    swap(pretmp->informationpoint, tmp->informationpoint);
    swap(pretmp->fitnesspoint, tmp->fitnesspoint);
    swap(pretmp->biologicalpoint, tmp->biologicalpoint);
    swap(pretmp->civiceducationpoint, tmp->chemicalpoint);
    swap(pretmp->defensepoint, tmp->defensepoint);
    swap(pretmp->technologypoint, tmp->technologypoint);
    swap(pretmp->gpa, tmp->gpa);
    swap(pretmp->rank, tmp->rank);
    swap(pretmp->conduct, tmp->conduct);
    swap(pretmp->note, tmp->note);
    swap(pretmp->mid, tmp->mid);
    swap(pretmp->last, tmp->last);
    swap(pretmp->product, tmp->product);
}

void highschool::sortrankstudent(highschool *list){
    student *tmp = list->head;
    if (tmp == NULL){
        cout << "\nThere is no listing on the highschool timesheet\n";
        return;
    }
    while(tmp != NULL){
        if(tmp->gpa > 0 || tmp->gpa < 10){
            if(tmp->geographypoint >= 0 && tmp->mathpoint >= 0 && tmp->historypoint >= 0 && tmp->englishpoint >= 0 && tmp->literarypoint >= 0 && tmp->physicalpoint >= 0 && tmp->chemicalpoint >= 0 && tmp->informationpoint >= 0 && tmp->fitnesspoint >= 0 && tmp->biologicalpoint >= 0 && tmp->civiceducationpoint >= 0 && tmp->defensepoint >= 0 && tmp->technologypoint >= 0){
                if(tmp->geographypoint < 3.5 || tmp->mathpoint < 3.5 || tmp->historypoint < 3.5 || tmp->englishpoint < 3.5 || tmp->literarypoint < 3.5 || tmp->physicalpoint < 3.5 || tmp->chemicalpoint < 3.5 || tmp->informationpoint < 3.5 || tmp->fitnesspoint < 3.5 || tmp->biologicalpoint < 3.5 || tmp->civiceducationpoint < 3.5 || tmp->defensepoint < 3.5 || tmp->technologypoint < 3.5){
                    if(tmp->gpa >= 0) {
                        tmp->rank ="Poor";
                    }
                }
            }
            if(tmp->geographypoint >= 0 && tmp->mathpoint >= 0 && tmp->historypoint >= 0 && tmp->englishpoint >= 0 && tmp->literarypoint >= 0 && tmp->physicalpoint >= 0 && tmp->chemicalpoint >= 0 && tmp->informationpoint >= 0 && tmp->fitnesspoint >= 0 && tmp->biologicalpoint >= 0 && tmp->civiceducationpoint >= 0 && tmp->defensepoint >= 0 && tmp->technologypoint >= 0){
                if(tmp->geographypoint < 5 || tmp->mathpoint < 5 || tmp->historypoint < 5 || tmp->englishpoint < 5 || tmp->literarypoint < 5 || tmp->physicalpoint < 5 || tmp->chemicalpoint < 5 || tmp->informationpoint < 5 || tmp->fitnesspoint < 5 || tmp->biologicalpoint < 5 || tmp->civiceducationpoint < 5 || tmp->defensepoint < 5 || tmp->technologypoint < 5){
                    if(tmp->gpa >= 3.5) {
                        tmp->rank ="Weak";
                    }
                }
            }
            if(tmp->geographypoint >= 5 && tmp->mathpoint >= 5 && tmp->historypoint >= 5 && tmp->englishpoint >= 5 && tmp->literarypoint >= 5 && tmp->physicalpoint >= 5 && tmp->chemicalpoint >= 5 && tmp->informationpoint >= 5 && tmp->fitnesspoint >= 5 && tmp->biologicalpoint >= 5 && tmp->civiceducationpoint >= 5 && tmp->defensepoint >= 5 && tmp->technologypoint >= 5){
                if(tmp->geographypoint < 6.5 || tmp->mathpoint < 6.5 || tmp->historypoint < 6.5 || tmp->englishpoint < 6.5 || tmp->literarypoint < 6.5 || tmp->physicalpoint < 6.5 || tmp->chemicalpoint < 6.5 || tmp->informationpoint < 6.5 || tmp->fitnesspoint < 6.5 || tmp->biologicalpoint < 6.5 || tmp->civiceducationpoint < 6.5 || tmp->defensepoint < 6.5 || tmp->technologypoint < 6.5){
                    if(tmp->gpa >= 5) {
                        if(tmp->conduct == "TB" || tmp->conduct == "T" || tmp->conduct == "K" ){
                            tmp->rank ="Average";
                        } else {
                            tmp->rank ="Weak";
                        }
                    }
                }
            }
            if(tmp->geographypoint >= 6.5 && tmp->mathpoint >= 6.5 && tmp->historypoint >= 6.5 && tmp->englishpoint >= 6.5 && tmp->literarypoint >= 6.5 && tmp->physicalpoint >= 6.5 && tmp->chemicalpoint >= 6.5 && tmp->informationpoint >= 6.5 && tmp->fitnesspoint >= 6.5 && tmp->biologicalpoint >= 6.5 && tmp->civiceducationpoint >= 6.5 && tmp->defensepoint >= 6.5 && tmp->technologypoint >= 6.5){
                if(tmp->geographypoint < 8 || tmp->mathpoint < 8 || tmp->historypoint < 8 || tmp->englishpoint < 8 || tmp->literarypoint < 8 || tmp->physicalpoint < 8 || tmp->chemicalpoint < 8 || tmp->informationpoint < 8 || tmp->fitnesspoint < 8 || tmp->biologicalpoint < 8 || tmp->civiceducationpoint < 8 || tmp->defensepoint < 8 || tmp->technologypoint < 8){
                    if(tmp->gpa >= 6.5) {
                        if(tmp->conduct == "K" || tmp->conduct == "T"){
                            tmp->rank ="Good";
                        } else if (tmp->conduct == "TB") {
                            tmp->rank ="Average";
                        } else {
                            tmp->rank ="Weak";
                        }
                    }
                }
            }
            if(tmp->geographypoint >= 8 && tmp->mathpoint >= 8 && tmp->historypoint >= 8 && tmp->englishpoint >= 8 && tmp->literarypoint >= 8 && tmp->physicalpoint >= 8 && tmp->chemicalpoint >= 8 && tmp->informationpoint >= 8 && tmp->fitnesspoint >= 8 && tmp->biologicalpoint >= 8 && tmp->civiceducationpoint >= 8 && tmp->defensepoint >= 8 && tmp->technologypoint >= 8){
                if(tmp->gpa >= 8 && tmp->gpa <= 10) {
                    if(tmp->conduct == "T"){
                        tmp->rank ="Very good";
                    } else if (tmp->conduct == "K") {
                        tmp->rank ="Good";
                    } else if (tmp->conduct == "TB") {
                        tmp->rank ="Average";
                    } else {
                        tmp->rank ="Weak";
                    }
                }
            }
        } else {
            cout <<"\nGPA must be greater than 0 and less than 10!!\n";
            return;
        }
        tmp=tmp->next;
    }
    cout << "\nThe students' rankings have been sorted\n";
}

void highschool::findcheckrankstudent(highschool *list, string ID){
    student *tmp = list->head;
    tmp = findstudent(list,ID);
    if (tmp == NULL){
        cout << "\nThere is no listing on the highschool timesheet\n";
        return;
    }
    if(tmp->rank == "Poor") {
        cout << "This student has ranked poorly.\n";
        cout << "Student GPA's:" << tmp->gpa << "\n"; 
        cout << "The under are scores for one or more subjects that did not qualify for a higher ranking:\n";
        if(tmp->geographypoint < 3.5){
            cout <<"Geographypoint:" <<  tmp->geographypoint << "\n";
        }
        if(tmp->mathpoint < 3,5){
            cout <<"Mathpoint:" <<  tmp->mathpoint << "\n";
        }
        if(tmp->historypoint < 3,5){
            cout <<"Historypoint:" <<  tmp->historypoint << "\n";
        }
        if(tmp->englishpoint < 3,5){
            cout <<"Englishpoint:" <<  tmp->englishpoint << "\n";
        }
        if(tmp->literarypoint < 3,5){
            cout <<"Literarypoint:" <<  tmp->literarypoint << "\n";
        }
        if(tmp->physicalpoint < 3,5){
            cout <<"Physicalpoint:" <<  tmp->physicalpoint << "\n";
        }
        if(tmp->chemicalpoint < 3,5){
            cout <<"Chemicalpoint:" <<  tmp->chemicalpoint << "\n";
        }
        if(tmp->informationpoint < 3,5){
            cout <<"Informationpoint:" <<  tmp->informationpoint << "\n";
        }
        if(tmp->fitnesspoint < 3,5){
            cout <<"Fitnesspoint:" <<  tmp->fitnesspoint << "\n";
        }
        if(tmp->biologicalpoint < 3,5){
            cout <<"Biologicalpoint:" <<  tmp->biologicalpoint << "\n";
        }
        if(tmp->civiceducationpoint < 3,5){
            cout <<"Civiceducationpoint:" <<  tmp->civiceducationpoint << "\n";
        }
        if(tmp->defensepoint < 3,5){
            cout <<"Defensepoint:" <<  tmp->defensepoint << "\n";
        }
        if(tmp->technologypoint < 3,5){
            cout <<"Technologypoint:" <<  tmp->technologypoint << "\n";
        }
    }
    if(tmp->rank == "Weak") {
        cout << "This student has ranked weakly.\n";
        cout << "Student GPA's:" << tmp->gpa << "\n"; 
        cout << "The under are scores for one or more subjects that did not qualify for a higher ranking:\n";
        if(tmp->conduct == "Y"){
            cout <<"Conduct: Weak!!\n";
        }
        if(tmp->geographypoint < 5){
            cout <<"Geographypoint:" <<  tmp->geographypoint << "\n";
        }
        if(tmp->mathpoint < 5){
            cout <<"Mathpoint:" <<  tmp->mathpoint << "\n";
        }
        if(tmp->historypoint < 5){
            cout <<"Historypoint:" <<  tmp->historypoint << "\n";
        }
        if(tmp->englishpoint < 5){
            cout <<"Englishpoint:" <<  tmp->englishpoint << "\n";
        }
        if(tmp->literarypoint < 5){
            cout <<"Literarypoint:" <<  tmp->literarypoint << "\n";
        }
        if(tmp->physicalpoint < 5){
            cout <<"Physicalpoint:" <<  tmp->physicalpoint << "\n";
        }
        if(tmp->chemicalpoint < 5){
            cout <<"Chemicalpoint:" <<  tmp->chemicalpoint << "\n";
        }
        if(tmp->informationpoint < 5){
            cout <<"Informationpoint:" <<  tmp->informationpoint << "\n";
        }
        if(tmp->fitnesspoint < 5){
            cout <<"Fitnesspoint:" <<  tmp->fitnesspoint << "\n";
        }
        if(tmp->biologicalpoint < 5){
            cout <<"Biologicalpoint:" <<  tmp->biologicalpoint << "\n";
        }
        if(tmp->civiceducationpoint < 5){
            cout <<"Civiceducationpoint:" <<  tmp->civiceducationpoint << "\n";
        }
        if(tmp->defensepoint < 5){
            cout <<"Defensepoint:" <<  tmp->defensepoint << "\n";
        }
        if(tmp->technologypoint < 5){
            cout <<"Technologypoint:" <<  tmp->technologypoint << "\n";
        }
    }

    if(tmp->rank == "Average") {
        cout << "\nThis student has ranked average.\n";
        cout << "Student GPA's:" << tmp->gpa << "\n"; 
        cout << "The under are scores for one or more subjects that did not qualify for a higher ranking:\n";
        if(tmp->conduct == "TB"){
            cout <<"Conduct: Average!!\n";
        }
        if(tmp->geographypoint < 6.5){
            cout <<"Geographypoint:" <<  tmp->geographypoint << "\n";
        }
        if(tmp->mathpoint < 6.5){
            cout <<"Mathpoint:" <<  tmp->mathpoint << "\n";
        }
        if(tmp->historypoint < 6.5){
            cout <<"Historypoint:" <<  tmp->historypoint << "\n";
        }
        if(tmp->englishpoint < 6.5){
            cout <<"Englishpoint:" <<  tmp->englishpoint << "\n";
        }
        if(tmp->literarypoint < 6.5){
            cout <<"Literarypoint:" <<  tmp->literarypoint << "\n";
        }
        if(tmp->physicalpoint < 6.5){
            cout <<"Physicalpoint:" <<  tmp->physicalpoint << "\n";
        }
        if(tmp->chemicalpoint < 6.5){
            cout <<"Chemicalpoint:" <<  tmp->chemicalpoint << "\n";
        }
        if(tmp->informationpoint < 6.5){
            cout <<"Informationpoint:" <<  tmp->informationpoint << "\n";
        }
        if(tmp->fitnesspoint < 6.5){
            cout <<"Fitnesspoint:" <<  tmp->fitnesspoint << "\n";
        }
        if(tmp->biologicalpoint < 6.5){
            cout <<"Biologicalpoint:" <<  tmp->biologicalpoint << "\n";
        }
        if(tmp->civiceducationpoint < 6.5){
            cout <<"Civiceducationpoint:" <<  tmp->civiceducationpoint << "\n";
        }
        if(tmp->defensepoint < 6.5){
            cout <<"Defensepoint:" <<  tmp->defensepoint << "\n";
        }
        if(tmp->technologypoint < 6.5){
            cout <<"Technologypoint:" <<  tmp->technologypoint << "\n";
        }
    }
    
    if(tmp->rank == "Good") {
        cout << "\nThis student has ranked good.\n";
        cout << "Student GPA's:" << tmp->gpa << "\n"; 
        cout << "The under are scores for one or more subjects that did not qualify for a higher ranking:\n";
        if(tmp->conduct == "K"){
            cout <<"Conduct: Good!!\n";
        }
        if(tmp->geographypoint < 8){
        cout <<"Geographypoint:" <<  tmp->geographypoint << "\n";
        }
        if(tmp->mathpoint < 8){
            cout <<"Mathpoint:" <<  tmp->mathpoint << "\n";
        }
        if(tmp->historypoint < 8){
            cout <<"Historypoint:" <<  tmp->historypoint << "\n";
        }
        if(tmp->englishpoint < 8){
            cout <<"Englishpoint:" <<  tmp->englishpoint << "\n";
        }
        if(tmp->literarypoint < 8){
            cout <<"Literarypoint:" <<  tmp->literarypoint << "\n";
        }
        if(tmp->physicalpoint < 8){
            cout <<"Physicalpoint:" <<  tmp->physicalpoint << "\n";
        }
        if(tmp->chemicalpoint < 8){
            cout <<"Chemicalpoint:" <<  tmp->chemicalpoint << "\n";
        }
        if(tmp->informationpoint < 8){
            cout <<"Informationpoint:" <<  tmp->informationpoint << "\n";
        }
        if(tmp->fitnesspoint < 8){
            cout <<"Fitnesspoint:" <<  tmp->fitnesspoint << "\n";
        }
        if(tmp->biologicalpoint < 8){
            cout <<"Biologicalpoint:" <<  tmp->biologicalpoint << "\n";
        }
        if(tmp->civiceducationpoint < 8){
            cout <<"Civiceducationpoint:" <<  tmp->civiceducationpoint << "\n";
        }
        if(tmp->defensepoint < 8){
            cout <<"Defensepoint:" <<  tmp->defensepoint << "\n";
        }
        if(tmp->technologypoint < 8){
            cout <<"Technologypoint:" <<  tmp->technologypoint << "\n";
        }
    }
    if(tmp->rank == "Very good") {
        cout << "\nThis student has ranked very good.\n";
        cout << "Student GPA's:" << tmp->gpa << "\n"; 
    }
} 

void highschool::printtimesheetofclass(highschool *list, string studyclass){
    student *tmp = list->head;
    while(tmp != NULL) {
        if(strcmp(studyclass.c_str(), tmp->studyclass.c_str()) == 0 ){
            cout <<"\nName: "<< tmp->name << "\n";
            cout <<"Sex: "<< tmp->sex << "\n";
            cout <<"ID: "<< tmp->id << "\n";
            cout <<"Class: "<< tmp->id << "\n";
            cout <<"GPA: "<< tmp->gpa << "\n";
            cout <<"Conduct: "<< tmp->conduct << "\n";
            break;
        } else{
            tmp = tmp->next;
        }
    }
}
