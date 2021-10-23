#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include<math.h>
using namespace std;

void Fibonacci_A(int start, int next, size_t n_term, size_t Count){
    if(Count == n_term){
        return;
    }
    if(Count == 0){
        Count++;
        next = start;
        cout << next << " "; 
        Fibonacci_A(start+1, 0, n_term, Count);
    }
    else if(Count == 1){
        Count++;
        next = start;
        cout << next << " "; 
        Fibonacci_A(start, 1, n_term, Count);
    }
    else{
        Count++;
        int holder = next;
        next = start + next; 
        start = holder;
        cout << next << " "; 
        Fibonacci_A(start, next, n_term, Count);
    }
}

size_t User_P(){
    double p;
    cout << "Enter 'p'(Should be a postive integer and non-floating point)" << endl;
    cin >> p;

    while (p == 0 || p < 0 || abs(p -int(p) > 0))
    {
        cout << "INCORRECT NUMBER ENTERED. Please enter 'p'(Should be a postive integer and non-floating point)" << endl;
        cin >> p;
    }

    return p;
}

double Fib_eq1(int n){
    double x = sqrt(5);
    double y = x;
    x = pow(1 + x,n);
    y = pow(1 - y,n);

    x = x - y;
    y = pow(2,n);
    y = y * sqrt(5);
    x = x/y;

    return x;
}

double Fib_eq2(double Fp, int p, int n){
    double x = (1 + sqrt(5))/2;
    x = pow(x,n-p);

    return x * Fp;
    
}

double Fib_eq3(size_t n){
    double x = (1 + sqrt(5))/2;
    double y = Fib_eq1(n);
    return y * x;
}

void Fib_eq2_loop(int p, int n){
    for (int i = 0; i < n; i++)
    {
        if(i == 0 || i == 1){
            double a = i;
            cout << fixed << setprecision(5) << a << " ";
        }
        else{
            p = i - 1;
        double Fp = Fib_eq1(p);
        double x = (1 + sqrt(5))/2;
        int b = i - p;
        x = pow(x,b); 
        cout << fixed << setprecision(5) << x * Fp<< " ";
        }  
    }
}

void Fib_eq3_loop(int n){
    for (int i = 0; i < n; i++)
    {
        if(i == 0 || i == 1){
            double x = i;
            cout << fixed << setprecision(5) << x<< " ";
        }
        else{
            double x = (1 + sqrt(5))/2;
            double Fn = Fib_eq1(i);
            cout << fixed << setprecision(5) << Fn * x << " ";
        }
    }
}

int Value_Vector(vector<int> vect, int i, int j){
    int sum = 0;
    for (size_t a = i; a <= j; a++)
    {
        sum += vect[a];
    }
    return sum;
}

vector<int> Largest_Sum(vector<int> vect){
    int b = 0, e = 1;
    
    for (size_t i = 0; i < vect.size() - 1; i++)
    {
        for (size_t j = i + 1; j < vect.size(); j++)
        {
            if(Value_Vector(vect, i,j) > Value_Vector(vect,b,e)){
                b = i;
                e = j;
            }
        }
    }

    vector<int> vect1;
    vect1.push_back(b);
    vect1.push_back(e);
    return vect1;
}


int main(){
    
    Fibonacci_A(0, 0, 20, 0);

    cout << endl << endl;

    size_t p; 
    size_t n;
   
    p = User_P();
    cout << "Enter 'n'" << endl;
    cin >> n;
    cout << endl;
    cout << "Equation 2 Sequence:" << endl;
    
    Fib_eq2_loop(p,n);
    cout << endl << endl;
    cout << "Equation 3 Sequence:" << endl;
    Fib_eq3_loop(n);
    cout << endl << endl;

    p = User_P();
    cout << "Enter 'n'" << endl;
    cin >> n;

    cout << "\n Equation1: " << Fib_eq1(p) << "\n Equation 2: " << Fib_eq2(Fib_eq1(p),p,n) << endl; 
    cout <<" Equation 3: " << Fib_eq3(n) << endl << endl;

    cout << " n = 30, "<< Fib_eq3(30) << ", n = 31" << Fib_eq3(31) << endl;

    cout << "Mathematical estimate of the 31st and 32nd terms using equation 3 ";
    cout << Fib_eq3(31) << " " << Fib_eq3(32) << endl << endl;
    

    vector<int> V = {-3, -5, 5, -1, -3, 1, 5, -6}; 

    vector<int> vect = Largest_Sum(V);

    cout << "[";

    for (size_t i = vect[0]; i <= vect[1]; i++)
    {
        if(i == vect[1]){
            cout << V[i] << "]";
        }
        else{
            cout << V[i] << ", ";
        }
    }
    cout << endl;

    V = {10, 2, -5, 1, 9, 0, -4, 2, -2}; 

    vect = Largest_Sum(V);
    cout << "[";

    for (size_t i = vect[0]; i <= vect[1]; i++)
    {
        if(i == vect[1]){
            cout << V[i] << "]";
        }
        else{
            cout << V[i] << ", ";
        }
    }
    cout << endl;
    V = {-7, 1, 8, 2, -3, 1}; 

    vect = Largest_Sum(V);
    cout << "[";

    for (size_t i = vect[0]; i <= vect[1]; i++)
    {
        if(i == vect[1]){
            cout << V[i] << "]";
        }
        else{
            cout << V[i] << ", ";
        }
    }

    cout << endl;
    V = {9, 7, 2, 16, -22, 11}; 

    vect = Largest_Sum(V);
    cout << "[";

    for (size_t i = vect[0]; i <= vect[1]; i++)
    {
        if(i == vect[1]){
            cout << V[i] << "]";
        }
        else{
            cout << V[i] << ", ";
        }
    }

    cout << endl;
    V = {6,1, 9, -33, 7, 2, 9, 1, -3, 8, -2, 9, 12, -4}; 

    vect = Largest_Sum(V);
    cout << "[";

    for (size_t i = vect[0]; i <= vect[1]; i++)
    {
        if(i == vect[1]){
            cout << V[i] << "]";
        }
        else{
            cout << V[i] << ", ";
        }
    }
    
}
