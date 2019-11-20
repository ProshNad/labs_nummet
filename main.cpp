#include <iostream>
#include <cmath>

using namespace std;

int main()
{
   ////лаба 5 по численным методам///решение1 = 1.11092, решение2(h)=1.11092
   ///                                                   решение2(h/2) =1.11167
   /// на сайте - 1.11072073453469 при h=0.000005 res = 1.11072

     long double h,res,a,b,x,f0,fn,fx,sum1,sum2;
     h=0.0005;
     res=0;
     a=0;
     b=1.57079632679;
     x=0;
     f0=1/(1+pow(cos(a),2));//f(x_0)
     fn=1/(1+pow(cos(b),2));//f(x_n)
     res=(f0+fn)/2;

     x=x+h;
     while(x<b){
         fx=1/(1+pow(cos(x),2));
         res=res+fx;
         x=x+h;
     }

     res=res*h;
     cout<<"Res1:"<<res<<endl;


     x=0;
     x=x+h;
     h=h/2;
     int i=1;
     sum1=0;
     sum2=0;
     while(x<b){
         if(i%2){
            // cout<<"here"<<i<<endl;
             fx=1/(1+pow(cos(x),2));
             sum1=sum1+fx;
         }else{
             fx=1/(1+pow(cos(x),2));
             sum2=sum2+fx;
         }
         i++;
         x=x+h;
     }
     res=(h/3)*(f0+fn+2*(sum2)+4*(sum1));
      cout<<"Res2:"<<res<<endl<<"i:"<<i<<" h:"<<h;///i=3142 при h=h;





    return 0;
}

