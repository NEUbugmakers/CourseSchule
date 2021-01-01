#include <iostream>
#include <string>
#include "Hungarian.h"
using namespace std;
int main(){
    AdjMatrix schedule;
    int m,n;//mÀÏÊ¦n¿Î³Ì
    cin>>m>>n;
    schedule.setnTeacher(m);
    schedule.setnCourse(n);
    string name;
    int count;
    for(int i=0;i<n;i++)
        schedule.setCourse(i,to_string(i));
    for(int i=0;i<m;i++){
        cin>>name;
        schedule.setTeacher(i,name);
        cin>>count;
        int t;
        for(int j=0;j<count;j++){
            cin>>t;
            schedule.setMap(i,t,1);
        }
    }
    int bo;
    Hungarian hun(schedule);
    bo = hun.multipleMatch();
    cout<<bo<<endl;
}