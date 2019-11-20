#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    long double summ,res;
    long double k=0.00;
    long double xx=0.5;
     long  double a0,a,pch;

    a0=(0.3333333333333333333333333333)*xx*xx*xx;

//a0=pow(xx,3.0)/3.0;
cout<<"a0(k=0):"<<a0<<endl;


     pch=(0.125)*(4*xx-2*xx*pow((1-4*xx*xx),0.5)-asin(2*xx));


      summ=a0;
      res=abs(summ-pch);
      cout<<"sum:"<<summ<<" pch:"<<pch<<" res:"<<res<<endl;
      int i=1;


      while(res>pow(10,-10)){
           // k++;
              i++;


              a0=a0*((4*k+2)*(2*k+3)/((k+2)*(2*k+5)))*xx*xx;
              //a0=a0*((4*k+2)*(2*k+3)/((k+2)*(2*k+5)))*xx*xx;

              summ+=a0;
              res=abs(pch-summ);


              if(i==10000){
              cout << "k="<<k <<"; a0="<<a0<<"; res="<<res<<";   summ(now)="<<summ <<"; pch="<<pch<<endl;

              i=0;
              }
                k++;

}//k=380897 summ=0.0536505  res=1e-010-END!

       cout <<"END!"<< k <<" "<<summ<<"  "<<res<< endl;
        cout<<sizeof("1234")<<endl;





        return 0;
}

