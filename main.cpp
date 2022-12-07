
#include <iostream>

using namespace std;
//function for factorial
long long factorial(long long fact){
    int temp = fact;
    for(int i = temp-1; i > 1; i--){
        fact*=i;
    }
    return fact;
}
//function for the power
float pow(float base, int p){
    float temp = base;
    for(int i = 1; i < p; i++){
        base *= temp;
    }
    return base;
}
//function to calculate the sine
double sin(float&x){
    x *= (3.14159265359/180);
    double sinx(0);
    double sine = x;
    for(int i = 5; i <= 15; i+=4){
        sinx = ((pow(x,i)) / factorial(i));
        sine += sinx;
    }
    for(int i = 3; i <= 15; i+=4){
        sinx = -((pow(x,i)) / factorial(i));
        sine += sinx;
    }
    return sine;
}
double cos(float& x){
    double cosx(0);
    double cosn = 1;
    for(int i = 4; i <= 15; i+=4){
        cosx = ((pow(x,i)) / factorial(i));
        cosn += cosx;
    }
    for(int i = 2; i <= 15; i+=4){
        cosx = -((pow(x,i)) / factorial(i));
        cosn += cosx;
    }
    return cosn;
}
long double tan(float& x){
    long double Bernoulli[20];
    Bernoulli[0] = 1;
    Bernoulli[1] = -0.5;
    Bernoulli[2] = 1/6;
    Bernoulli[4] = -1/30;
    Bernoulli[6] = 1/42;
    Bernoulli[8] = -1/30;
    Bernoulli[10] = 5/66;
    Bernoulli[12] = 0.25311355311;
    Bernoulli[14] = 1.16666666667;
    Bernoulli[16] = 7.09215686275;
    Bernoulli[18] = 54.97117794486;
    Bernoulli[20] = 529.1242424242;

    long double tanx(0);
    long double tann = x;
    for(int i = 0; i <= 20; i+=2){
        tanx =  ((pow(x,i))*Bernoulli[i]*pow(2,i+1)*(pow(2,i+1)-1) / factorial(i+1));
        tann += tanx;
    }
    return tann;
}

int main(){
    float x;
    cout << "Please enter the angle in degrees:";
    cin >> x;
    float t = x;
    while(x>=360) x-=360;
    while(x<0) x+360;
    cout << "Sin(" << t << ") = " << sin(x) << endl;
    cout << "Cos(" << t << ") = " << cos(x) << endl;
    cout << "Tan(" << t << ") = " << tan(x) << endl;

    return 0;
}


