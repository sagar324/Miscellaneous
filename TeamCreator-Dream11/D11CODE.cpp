#include <bits/stdc++.h>
//#include "def.h"
using namespace std;
#define STEXT freopen("INPUT.txt","r",stdin);freopen("OUTPUT.txt","w",stdout)
//typedefs and flash

class team{
public:    
    vector <int> tt1;
    vector <int> tt2;
    double netvalue=0;
};
class pl{
public:
    int type=0;
    double points=0;
    double avg = 0; 
    int inn=0;
};
pl temp;
map <string,pl> db;
#define inito(s,x,y,z,in) temp.type=x;temp.points=y;temp.avg=z;temp.inn=in;db[s]=temp;   

void read_record() {
    fstream fin;  
    fin.open("STATS.csv", ios::in);  
    int count = 0; 
    vector<string> row;
    vector <string> ar;
    set <string> playa; 
    string line, word;
    while (getline(fin,line)) {
         row.clear();
         if(count==0){
            count++;continue;
         } 
          stringstream s(line); 
        while (getline(s, word, ',')) { 
            row.push_back(word); 
        } 
            count++;
            //row[0] = redstring(row[0]);
            playa.insert(row[0]);
            inito(row[0],stoi(row[4]),stof(row[3]),stof(row[1]),stoi(row[2]));
    } 
    fin.close();
}
void stext(){
    #ifndef ONLINE_JUDGE
        STEXT;
    #endif
}
void makeCombiUtil(vector<vector<int> >& ans, 
    vector<int>& tmp, int n, int left, int k) 
{ 
    if (k == 0) { 
        ans.push_back(tmp); 
        return; 
    } 
    for (int i = left; i <= n; ++i) 
    { 
        tmp.push_back(i-1); 
        makeCombiUtil(ans, tmp, n, i + 1, k - 1); 
        tmp.pop_back(); 
    } 
} 
vector<vector<int> > makeCombi(int n, int k) 
{ 
    vector<vector<int> > ans; 
    vector<int> tmp; 
    makeCombiUtil(ans, tmp, n, 1, k); 
    return ans; 
} 
bool compare(team t1,team t2){
    return t1.netvalue>t2.netvalue;
}    
int halo=0;
vector <string> ttt1;
vector <string> ttt2;
int gflag=0;
void check_func(string playa){
    fstream fin;  
    fin.open("STATS.csv", ios::in);
    string line, word; 
    vector<string> row;
    int count = 0;
    int flag=0;
    while (getline(fin,line)) {
        row.clear();
        stringstream s(line); 
        while (getline(s, word, ',')) { 
            row.push_back(word); 
        } 
        if(row[0]==playa){
            flag=1;halo++;
        } 
    }   
    if(flag==0){
        if(gflag==0){
            cout<<"The following player/players were not found in the csv:"<<endl;
            gflag=1;
        }
        cout<<playa<<endl;;
    }
    fin.close(); 
}
void input_checker(){
    for(int i=0;i<22;i++){
        string s;
        if(i<11){
            s = ttt1[i];
        }
        else{
            s = ttt2[i-11];
        }
        cin>>s;
        check_func(s);
    }
}

void create(){
    read_record();
    pl prop;
    team prop2;
    vector <pl> dat1(11,prop);
    vector <pl> dat2(11,prop);
    
    for(int i=0;i<11;i++){
        string s;
        cin>>s;
        ttt1.push_back(s);
        dat1[i] = db[s];
    }
    for(int i=0;i<11;i++){
        string s;
        cin>>s;
        ttt2.push_back(s);
        dat2[i] = db[s];
    }
    input_checker();
    if(halo<22){
        return ;
    }
    int cnt=0;
    vector <team> answer(644688,prop2);
    vector <int> com = {4,5,6,7};
    for(int i=0;i<4;i++){
        vector <vector <int>> team1 = makeCombi(11, com[i]);
        vector <vector <int>> team2 = makeCombi(11, 11-com[i]);
        int size1,size2;
        size1 = team1.size();
        size2 = team2.size();
        //cout<<size1<<" "<<size2<<endl;
        for(int j=0;j<size1;j++){
            for(int k=0;k<size2;k++){
                int s1 = team1[j].size();
                int s2 = team2[k].size();
                //check1
                vector <double> collec(11,0);
                int iter=0;
                double sum=0;
                double net=0;
                int a=0,b=0,c=0,d=0;
                for(int itr = 0;itr<s1;itr++){
                    sum += dat1[team1[j][itr]].points;
                    net += dat1[team1[j][itr]].avg;
                    int tempo = dat1[team1[j][itr]].type;
                    if(tempo==0){
                        a++;
                    }
                    else if(tempo==1){
                        b++;
                    }
                    else if(tempo==2){
                        c++;
                    }
                    else{
                        d++;
                    }
                }
                for(int itr=0;itr<s2;itr++){
                    sum += dat2[team2[k][itr]].points;
                    net += dat2[team2[k][itr]].avg;
                    int tempo = dat2[team2[k][itr]].type;
                    if(tempo==0){
                        a++;
                    }
                    else if(tempo==1){
                        b++;
                    }
                    else if(tempo==2){
                        c++;
                    }
                    else{
                        d++;
                    } 
                }
                if(sum>100||a<1||a>4||b<3||b>6||c<1||c>4||d<3||d>6){
                    continue;
                }
                for(int itr=0;itr<s1;itr++){
                    collec[itr] = dat1[team1[j][itr]].avg;
                }
                for(int itr=0;itr<s2;itr++){
                    collec[s1+itr] = dat2[team2[k][itr]].avg;
                }
                sort(collec.begin(),collec.end());                
                answer[cnt].tt1 = team1[j];
                answer[cnt].tt2 = team2[k];
                answer[cnt].netvalue = net+(collec[9]/2)+collec[10];
                 
                cnt++;
            }
        }
        //sort answer vector.
    }
    double max1=0, max2=0, max3=0, max4=0, max5=0;
    int i1=0,i2=0,i3=0,i4=0,i5=0;
    for(int i=0;i<cnt;i++){
        if(max1<answer[i].netvalue){
            max1 = answer[i].netvalue;
            i1 = i;
        }
    }
    for(int i=0;i<cnt;i++){
        if(i==i1){
            continue;
        }
        if(max2<answer[i].netvalue){
            max2 = answer[i].netvalue;
            i2 = i;
        }
    }
    for(int i=0;i<cnt;i++){
        if(i==i1||i==i2){
            continue;
        }
        if(max3<answer[i].netvalue){
            max3 = answer[i].netvalue;
            i3 = i;
        }
    }
    for(int i=0;i<cnt;i++){
        if(i==i1||i==i2||i==i3){
            continue;
        }
        if(max4<answer[i].netvalue){
            max4 = answer[i].netvalue;
            i4 = i;
        }
    }
    for(int i=0;i<cnt;i++){
        if(i==i1||i==i2||i==i3||i==i4){
            continue;
        }
        if(max5<answer[i].netvalue){
            max5 = answer[i].netvalue;
            i5 = i;
        }
    }
    int tempindex[5] ;
    tempindex[0]=i1;
    tempindex[1]=i2;
    tempindex[2]=i3;
    tempindex[3]=i4;
    tempindex[4]=i5;
    cout<<"The best 5 teams are::"<<endl;
    cout<<endl;
    for(int iterator=0;iterator<5;iterator++){
        int index = tempindex[iterator];
        cout<<"Estimated points for team-"<<iterator+1<<" = "<<answer[index].netvalue<<endl;;
        vector <int> x = answer[index].tt1;
        vector <int> y = answer[index].tt2;
        double cap=0,vcap=0;
        string caps= "";
        string vcaps = "";
        for(int i=0;i<x.size();i++){
            if(cap<dat1[x[i]].avg){
                cap = dat1[x[i]].avg;
                caps = ttt1[x[i]];
            }
        }
        for(int i=0;i<y.size();i++){
            if(cap<dat2[y[i]].avg){
                cap = dat2[y[i]].avg;
                caps = ttt2[y[i]];
            }
        }   
        for(int i=0;i<x.size();i++){
            if(ttt1[x[i]]==caps){
                continue;
            }
            if(vcap<dat1[x[i]].avg){
                vcap = dat1[x[i]].avg;
                vcaps = ttt1[x[i]];
            }
       }
        for(int i=0;i<y.size();i++){
            if(ttt2[y[i]]==caps){
                continue;
            }
            if(vcap<dat2[y[i]].avg){
                vcap = dat2[y[i]].avg;
                vcaps = ttt2[y[i]];
            }
        }
        for(int i=0;i<x.size();i++){
            cout<<ttt1[x[i]];
            if(ttt1[x[i]]==caps){
                cout<<"(C)";
            }
            if(ttt1[x[i]]==vcaps){
                cout<<"(VC)";
            }
            cout<<" "<<endl;
        }
        for(int i=0;i<y.size();i++){
            cout<<ttt2[y[i]];
            if(ttt2[y[i]]==caps){
                cout<<"(C)";
            }
            if(ttt2[y[i]]==vcaps){
                cout<<"(VC)";
            }
            cout<<" "<<endl;
        }
        cout<<"-------------------------------------"<<endl;
    }    
    return;
}
void update_stat(string playa,float newpoints){
    fstream fin,fout;  
    fin.open("STATS.csv", ios::in);
    fout.open("STATS2.csv",ios::out);
    string line, word; 
    vector<string> row;
    int count = 0;
    while (getline(fin,line)) {
        row.clear();
        stringstream s(line); 
        while (getline(s, word, ',')) { 
            row.push_back(word); 
        } 
        if(row[0]!=playa){
            fout<<row[0]<<","<<row[1]<<","<<row[2]<<","<<row[3]<<","<<row[4]<<endl;
            count++;
        } 
        else{
            float inito = stof(row[1]);
            int ininito = stoi(row[2]);
            inito = (inito*ininito)+newpoints;
            ininito++;
            inito = inito/ininito;
            halo++;
            fout<<row[0]<<","<<inito<<","<<ininito<<","<<row[3]<<","<<row[4]<<endl;
        }
    }   
    remove("STATS.csv"); 
    rename("STATS2.csv", "STATS.csv"); 
    fin.close();
    fout.close();
}
void update(){
    vector <float> temppoints;
    for(int i=0;i<22;i++){
        string s;
        float newp;
        cin>>s>>newp;
        if(i<11){
            ttt1.push_back(s);
        }
        else{
            ttt2.push_back(s);
        }
        temppoints.push_back(newp);
    }
    input_checker();
    if(halo<22){
        return;
    }
    for(int i=0;i<22;i++){
        string s;
        float newp;
        newp = temppoints[i];
        if(i<11){
            s = ttt1[i];
        }
        else{
            s = ttt2[i-11];
        }
        update_stat(s,newp);
    }
    cout<<"Update Complete"<<endl;
    return;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    stext();
    string command;
    cin>>command;
    if(command=="create"){
        create();
    }
    else if(command=="update"){
        update();
    }
    else{
        cout<<"Invalid command in first line of Input"<<endl;
    }
    return 0;
}