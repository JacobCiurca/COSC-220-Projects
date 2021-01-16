//Jacob Ciurca
//Project 1 Shape fun
//Dr. Lu
//October 3rd, 2019


#include <iostream>
#include <string> 
#define SURFACE_LENGTH 20 
#define SURFACE_WIDTH 10 
#define X1 0 
#define X2 20 
#define Y1 0 
#define Y2 10 
using namespace std;

//Exception class
class OutOfSurfaceException
{   
public:
    const string what() { return "cannot be fit into the 20x10 surface"; }  
};

//Center class
class Center {
   public:
   Center(){
     x=0;
     y=0;
   }
      int x;
      int y;
      Center(int xx,int yy){
        x=xx;
        y=yy;
      }
};
// Base class
class Shape {
   public:
   Shape(){
     center=Center(0,0);
   }
   Shape(Center c){
     center=c;
   }
      void moveTo(Center c) {
         center=c;
      }
    void displayCenter()  
    {  
        std::cout << "Center("<<center.x<<", "<<center.y << ")"<<std::endl;   
    } 
    virtual void displayArea()=0;
    virtual void calculateArea() = 0;
    virtual bool isShapeFitted() = 0;
      
   protected:
      Center center;
};

// Derived class
class Rectangle: public Shape {
   public:
   Rectangle(){
    width=0;
    length=0;
   };
   Rectangle(Center c,float l,float w):Shape(c)
   {
     length=l;
     width=w;
   }
    void displayArea()  
    {  
        std::cout << "Area is "<<area<<std::endl;  
    }
    void calculateArea(){
      area=width*length;
    }
    bool isShapeFitted(){
      if ((length<=SURFACE_LENGTH && width<=SURFACE_WIDTH) || (length<=SURFACE_WIDTH && width<=SURFACE_LENGTH) ){  
        moveTo(center);
        return(true);  
      }   
    else
        return(false);
    }
    private:
      float width;
      float length;
      float area;
};

// Derived class
class Circle: public Shape {
   public:
   Circle(){
     radius=0;
   }
  Circle(Center c,float r):Shape(c){
    radius=r;
  }
    void displayArea()  
    {  
        std::cout << "Area is "<<area<<std::endl; 
    }
    void calculateArea(){
      area=3.14159*radius*radius;
    }
    bool isShapeFitted(){ 
    float R=radius*2;  
    
    if (R<=SURFACE_LENGTH && R<=SURFACE_WIDTH){  
        moveTo(center);
        return(true);  
      }      
    else
        return(false);
    }
    private:
    float area;
    float radius;
};

// Derived class
class Square: public Shape {
   public:
   Square(Center c,float s):Shape(c){
     side=s;
   }
   Square(){
     side=0;
   }

    void displayArea()  
    {  
        std::cout << "Area is "<<area<<std::endl;  
    }
    void calculateArea(){
      area=side*side;
    }
    bool isShapeFitted(){  
    if (side<=SURFACE_LENGTH && side<=SURFACE_WIDTH){  
        moveTo(center);
        return(true);  
      }     
    else
        return(false);
    }
    private:
    float area;
    float side;
};

int main(){           
string shapeTitle;
Shape *shape;
float cx=0,cy=0;
  cout<<"Welcome to Shape Fun"<<endl;
  cout<<"----------------------"<<endl;
  cout<<"Enter shape(circle,rectangle,square): ";
  getline (cin, shapeTitle); 
  if(shapeTitle.compare("circle")== 0){
      float radius;
      cout<<"Enter Radius: ";
      cin>>radius;
      cout<<"Enter Center(x,y): ";
      cin>>cx>>cy;
      Center center(cx,cy);
      Circle circle(center,radius);
      shape=&circle; 

  }else if(shapeTitle.compare("rectangle")== 0){
    float length=0,width=0;
      cout<<"Enter Length and Width: ";
      cin>>length>>width;
      cout<<"Enter Center(x,y): ";
      cin>>cx>>cy;
      Center center(cx,cy);
      Rectangle rectangle(center,length,width);
      shape=&rectangle; 
  }else if(shapeTitle.compare("square")== 0){
     float side=0;
     cout<<"Enter side: ";
      cin>>side;
      cout<<"Enter Center(x,y): ";
      cin>>cx>>cy;
      Center center(cx,cy);
      Square square(center,side);
      shape=&square; 
  }else{
    cout<<"you did not enter valid input, please try again!"<<endl;
    return 0;
  }
  try{
    if(!shape->isShapeFitted())
     throw OutOfSurfaceException();
    shape->calculateArea();
    shape->displayCenter();
    shape->displayArea();
  }catch(OutOfSurfaceException e){
    std::cerr << "Exception raised: " << e.what() << std::endl;
  }
  return 0;
}
