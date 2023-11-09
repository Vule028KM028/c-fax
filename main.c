//
//  main.c
//  C Skola
//
//  Created by Vukasin Lazarevic on 29.10.23..
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isnumber(int n){
    
    if(n >= '0' && n <= '9'){
        return 1;
    }
    return 0;
}

int main(void)
{
    char ch;
    char prev = ' ';
    int temp = 0;
    int najm = 0, najv = 0;
    int broj = 0;
    int velike = 0;
    int male = 0;
    prev = getchar();
    if (prev == '{') {
        velike = 1;
    }
    if (prev == '(') {
        male = 1;
    }
    while((ch = getchar()) != '\n') {
        

        
        if(velike==1){
            if(isnumber(ch)){
                temp = temp * 10 + (ch - '0');
            }else if((ch == ' ' || ch == '}')){
                
                if(temp>najv||najv==0){
                    najv = temp;
                }
                
                if(temp<najm|| najm == 0){
                    najm = temp;
                }
                
                temp = 0;
            }
        }

        
        if(male==1){
            if(isnumber(ch)){
                temp = temp * 10 + (ch - '0');
            }else if((ch == ' ' || ch == ')')){
                
                if(temp<najm||najm==0){
                    if(temp%2==0){
                        najm = temp;
                    }
                }
                
                temp = 0;
            }
        }
        

        if(ch=='{'){
            velike = 1;
        }else if(ch=='}'&&velike==1){
            
            broj = broj + (najv-najm);
            najv = 0;
            najm = 0;
            velike = 0;
        }
        
        if(ch=='('){
            male = 1;
        }else if(ch==')'&&male==1){
            
            broj = broj + najm;
            najm = 0;
            male = 0;
        }
        
        if(male == 0 && velike == 0){
            
            if(isnumber(ch)){
                temp = temp * 10 + (ch - '0');
            }else{
                broj = broj + temp;
                temp = 0;
            }
               
        }


        prev = ch;
    }

    if(temp!=0){
        broj = broj+ temp;
        temp = 0;
    }
    printf("%d\n",broj);
    return 0;
}
