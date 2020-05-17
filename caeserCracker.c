#include <stdio.h>

int check(char a){
    if(a=='a'|| a=='e' || a=='i' || a=='o' || a=='u' || a=='y'){
        return 1;
    }else{
        return 0;
    }
}

void incr(char str[]){
    for(int i=0; str[i]!='\0'; i++){
        if(str[i]==' '){
            continue;
        }
        if(str[i]=='z'){
            str[i]='a';
        }else{
            str[i]++;
        }
    }
}

int main(int arg, int *A){
    
    char str[100000];
    int count[26], ycount[26];
    scanf("%[^\n]", str);
    printf("\n");
    int n;
    for(n=0; str[n]!='\0'; n++);
    for(int j=0; j<26; j++){
        
        int max=0, vow=0, ok=0;
        incr(str);

        for(int i=0; str[i]!='\0'; i++){

            if(str[i]==' '){

                if(ok==0){
                    max=1000;
                    break;
                }else{
                    if(vow>=max){
                        max=vow;
                    }
                }
                ok=0;
                vow=0;
                continue;
            }

            if(check(str[i])){
                if(vow>=max){
                    max=vow;
                }
                ok=1;
                vow=0;
            }else{
                vow++;
            }
        }

        if(ok==0){
            max=1000;
        }

        if(vow>=max){
            max=vow;
        }

        count[j]=max;
        
        for(int i=0; str[i]!=0; i++){
            if(str[i]=='y'){
                ycount[j]++;
            }
            if(str[i]=='z' || str[i]=='v'){
                ycount[j]+=2;
            }
            if(i<n-1 && str[i+1]!=' ' && str[i]=='q' && str[i+1]!='u'){
                ycount[j]=1000;
            }else if(i<n-1 && str[i+1]!=' ' && str[i]=='q' && str[i+1]=='u'){
                ycount[j]=-100;
            }
            if(i<n-1 && str[i+1]!=' ' && str[i]=='x' && check(str[i+1])==0 ){
                ycount[j]=1000;
            }
            if(i<n-1 && (str[i]=='o' && str[i+1] == 'o')){
                ycount[j]-=5;
            }
            if(i<n-1 && (str[i]=='e' && str[i+1]=='e')){
                ycount[j]-=5;
            }
            if(i<n-1 && (str[i]=='s' && str[i+1]=='h')){
                ycount[j]-=5;
            }
            if(i<n-1 && (str[i]=='s' && str[i+1]=='c')){
                ycount[j]-=10;
            }
            if(i<n-1 && (str[i]=='s' && str[i+1]=='s')){
                ycount[j]-=10;
            }
            if(i<n-1 && (str[i]=='s' && str[i+1]=='t')){
                ycount[j]-=5;
            }
            if(i<n-1 && (str[i]=='i' && str[i+1]=='e')){
                ycount[j]-=5;
            }
            if(i<n-1 && (str[i]=='t' && str[i+1]=='h')){
                ycount[j]-=5;
            }
            if(i<n-1 && (str[i]=='o' && str[i+1]=='u')){
                ycount[j]-=5;
            }
            if(i<n-2 && (str[i]=='i' && str[i+1]=='o' && str[i+2]=='n')){
                ycount[j]-=100;
            }
            if(i<n-2 && (str[i]=='i' && str[i+1]=='n' && str[i+2]=='g')){
                ycount[j]-=100;
            }
        }

        if(arg>1)printf("%s = %d %d\n", str, count[j], ycount[j]);
    }

    int min=999, k;
    for(int i=0; i<26; i++){
        if(count[i]<min){
            min=count[i];
            k=i;
        }
        if(count[i]<=min+1){
            if(ycount[i]<ycount[k]){
                k=i;
            }
        }
    }

    printf("A few possible decryptions are:\n\n");

    for(int i=0; i<26; i++){
        incr(str);
        if(count[i]<=min+1 && ycount[i]<n*5){
            printf("%s\n", str);
        }
    }

    printf("\n\nA possible decryption is:\n\n");

    for(int i=0; i<=k; i++){
        incr(str);
    }

    printf("%s\n\n", str);
}
