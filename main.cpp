#include <iostream>
#include <string>

float f(float x){
    x=x+1.;
    std::cout << "inside f : x=" << x << " @x=" << &x <<  std::endl; 
    return x;    
}
void F(){
    float x=0.1;
    std::cout << "before f : x=" << x << " @x=" << &x << std::endl; 
    float y=f(x);
    std::cout << "after  f : x=" << x << " @x=" << &x << std::endl; 
    std::cout << "after  f : y=" << y << " @y=" << &y << std::endl; 
}

float* f_star(float* x){
    x[0]=x[0]+1.; //equiv. to (*x)=(*x)+1.; //equiv. to (*&*x)=(*&*x)+1.;
    std::cout << "inside f : x=" << x[0] << " @x=" << x <<  std::endl; 
    return x;
}
void F_star(){
    float x[1]; // equivalent to  float* x=(float*) malloc(sizeof(float));
    x[0]=0.1;
    std::cout << "before f : x=" << x[0] << " @x=" << x << std::endl; 
    float* y = f_star(x);
    std::cout << "after  f : x=" << x[0] << " @x=" << x << std::endl; 
    std::cout << "after  f : y=" << y[0] << " @y=" << y << std::endl; 
}

float f_ref(float& x){
    x=x+1.;
    std::cout << "inside f : x=" << x << " @x=" << &x <<  std::endl; 
    return x;    
}
void F_ref(){
    float x=0.1;
    std::cout << "before f : x=" << x << " @x=" << &x << std::endl; 
    float y=f_ref(x);
    std::cout << "after  f : x=" << x << " @x=" << &x << std::endl; 
    std::cout << "after  f : y=" << y << " @y=" << &y << std::endl; 
}

int main()
{
    std::cout << "parameter passing by value" << std::endl;
    F();
    std::cout << "parameter passing by pointer" << std::endl;
    F_star();
    std::cout << "parameter passing by reference" << std::endl;
    F_ref();
}
