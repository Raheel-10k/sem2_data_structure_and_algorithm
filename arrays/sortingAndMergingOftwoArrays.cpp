#include "iostream"
using namespace std;

void mergeAndSort() {
    int girls[5]={55,60,65,68,70};
    int boys[8]={51,53,66,80,90,92,95,99};

    int maxlength=(sizeof(girls)/sizeof(girls[0]))+(sizeof(boys)/sizeof(boys[0]));

    int classGrades[maxlength], boyp=0, girlp=0;

    for(int i=0; i<maxlength;i++) {
        if(boys[boyp]>girls[girlp]){
            classGrades[i]=girls[girlp];
            girlp++;
        }
        else if(boys[boyp]<girls[girlp]) {
            classGrades[i]=boys[girlp];
            boyp++;
        }
        else{
            classGrades[i]=girls[girlp];
            i++;
            classGrades[i]=boys[boyp];
        }
    }
}