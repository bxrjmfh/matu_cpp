#include <iostream>
int power(int n){
    if (n==1){
        return 1;
    }
    else{
        int temp=n*power(n-1);
        if(temp>=n)
        {
            return temp;
        }
        else
        {
            return 0;
        }
    }
}
int main() {


        int n=0;
        scanf("%d",&n);
        if(!n>0){
            if(n==0){printf("%d!=%d",n,1); }
            else{return 0;}
        }
        else{
            int temp=power(n);
            if(n<13)
            {
                printf("%d!=%d",n,temp);
            }
            else if(n==13)
            {
                printf("%d!=%d",n,power(12));
            }
            else
            {
                return 0;
            }
        }


}
