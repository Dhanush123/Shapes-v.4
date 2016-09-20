// Programmer: Dhanush Patel
// Programmer's ID: 1553428

#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

#include <cstdlib>
#include <cmath>

struct Square{
  const double side;
  Square(double);
  void output(ostream&) const;
  Square& operator=(const Square&);
};

struct Rectangle{
  const double length;
  double width;
  Rectangle(double, double);
  void output(ostream&) const;
  Rectangle& operator=(const Rectangle&);
};

struct Circle{
  const double radius;
  Circle(double);
  void output(ostream&) const;
  Circle& operator=(const Circle&);
};

struct Triangle{
  const double side;
  Triangle(double);
  void output(ostream&) const;
  Triangle& operator=(const Triangle&);
};

struct Cube{
  const double side;
  Cube(double);
  void output(ostream&) const;
  Cube& operator=(const Cube&);
};

struct Box{
  const double length;
  const double width;
  const double height;
  Box(double, double, double);
  void output(ostream&) const;
  Box& operator=(const Box&);
};

struct Cylinder{
  const double radius;
  const double height;
  Cylinder(double, double);
  void output(ostream&) const;
  Cylinder& operator=(const Cylinder&);
};

struct Prism{
  const double side;
  const double height;
  Prism(double, double);
  void output(ostream&) const;
  Prism& operator=(const Prism&);
};

vector<string> parseString(string);
void checkShape(vector<string>&, vector<void*>&, vector<string>&);
void calcShape(vector<string>&, vector<void*>&, vector<string>&);
ostream& roundingTwo(ostream&);
ostream& roundingOff(ostream&);

const double PI = 3.14159;

int main(){
  cout << "Programmer: Dhanush Patel\n";
  cout << "Programmer's ID: 1553428\n";
  cout << "File: " << __FILE__ << endl;

  ifstream fin;
  fin.open("Shapes.input.txt");
  vector<void*> shapesBag;
  vector<string> shapesTypeBag;

  while (fin.good()){
    string curLine;
    getline(fin, curLine);
    vector<string> lineElems = parseString(curLine);
    if(lineElems.size() != 0){
     checkShape(lineElems, shapesBag, shapesTypeBag);
    }
  }

  fin.close();

  for (int i = 0; i < shapesBag.size(); i++){
    for (int j = i + 1; j < shapesBag.size(); j++){
      if (shapesTypeBag[j] < shapesTypeBag[i]){
        swap(shapesBag[i], shapesBag[j]);
        swap(shapesTypeBag[i], shapesTypeBag[j]);
      }
    }
  }


  for (int i = 0; i < shapesBag.size(); i++){
    if (shapesTypeBag[i] == "SQUARE"){
      const Square* const ps = reinterpret_cast<const Square*>(shapesBag[i]);
      const Square& rs = *ps;
      rs.output(cout);
    }
    else if (shapesTypeBag[i] == "RECTANGLE"){
      const Rectangle* const ps = reinterpret_cast<const Rectangle*>(shapesBag[i]);
      const Rectangle& rs = *ps;
      rs.output(cout);
    }
    else if (shapesTypeBag[i] == "CIRCLE"){
      const Circle* const ps = reinterpret_cast<const Circle*>(shapesBag[i]);
      const Circle& rs = *ps;
      rs.output(cout);
    }
    else if (shapesTypeBag[i] == "TRIANGLE"){
      const Triangle* ps = reinterpret_cast<const Triangle*>(shapesBag[i]);
      const Triangle& rs = *ps;
      rs.output(cout);
    }
    else if (shapesTypeBag[i] == "CUBE"){
      const Cube* const ps = reinterpret_cast<const Cube*>(shapesBag[i]);
      const Cube& rs = *ps;
      rs.output(cout);
    }
    else if (shapesTypeBag[i] == "BOX"){
      const Box* const ps = reinterpret_cast<const Box*>(shapesBag[i]);
      const Box& rs = *ps;
      rs.output(cout);
    }
    else if (shapesTypeBag[i] == "CYLINDER"){
      const Cylinder* const ps = reinterpret_cast<const Cylinder*>(shapesBag[i]);
      const Cylinder& rs = *ps;
      rs.output(cout);
    }
    else if (shapesTypeBag[i] == "PRISM"){
      const Prism* const ps = reinterpret_cast<const Prism*>(shapesBag[i]);
      const Prism& rs = *ps;
      rs.output(cout);
    }
    else {
      //this shouldn't happen
    }
  }

  ofstream fout;
  fout.open("Shapes.output.txt");

  for (int i = 0; i < shapesBag.size(); i++){
    if (shapesTypeBag[i] == "SQUARE"){
       const Square* const ps = reinterpret_cast<const Square*>(shapesBag[i]);
       const Square& rs = *ps;
       rs.output(fout);
     }
     else if (shapesTypeBag[i] == "RECTANGLE"){
       const Rectangle*  const ps = reinterpret_cast<const Rectangle*>(shapesBag[i]);
       const Rectangle& rs = *ps;
       rs.output(fout);
     }
     else if (shapesTypeBag[i] == "CIRCLE"){
       const Circle* const ps = reinterpret_cast<const Circle*>(shapesBag[i]);
       const Circle& rs = *ps;
       rs.output(fout);
     }
     else if (shapesTypeBag[i] == "TRIANGLE"){
       const Triangle* const ps = reinterpret_cast<const Triangle*>(shapesBag[i]);
       const Triangle& rs = *ps;
       rs.output(fout);
     }
     else if (shapesTypeBag[i] == "CUBE"){
       const Cube* const ps = reinterpret_cast<const Cube*>(shapesBag[i]);
       const Cube& rs = *ps;
       rs.output(fout);
     }
     else if (shapesTypeBag[i] == "BOX"){
       const Box* const ps = reinterpret_cast<const Box*>(shapesBag[i]);
       const Box& rs = *ps;
       rs.output(fout);
     }
     else if (shapesTypeBag[i] == "CYLINDER"){
       const Cylinder* ps = reinterpret_cast<const Cylinder*>(shapesBag[i]);
       const Cylinder& rs = *ps;
       rs.output(fout);
     }
     else if (shapesTypeBag[i] == "PRISM"){
       const Prism* ps = reinterpret_cast<const Prism*>(shapesBag[i]);
       const Prism& rs = *ps;
       rs.output(fout);
     }
     else {
       //this shouldn't happen
     }
   }

  fout.close();

  for (int i = 0; i < shapesBag.size(); i++){
     if (shapesTypeBag[i] == "SQUARE"){
       const Square* const ps = reinterpret_cast<const Square*>(shapesBag[i]);
       delete ps;
     }
     else if (shapesTypeBag[i] == "RECTANGLE"){
       const Rectangle*  const ps = reinterpret_cast<const Rectangle*>(shapesBag[i]);
       delete ps;
     }
     else if (shapesTypeBag[i] == "CIRCLE"){
       const Circle* const ps = reinterpret_cast<const Circle*>(shapesBag[i]);
       delete ps;
     }
     else if (shapesTypeBag[i] == "TRIANGLE"){
       const Triangle* const ps = reinterpret_cast<const Triangle*>(shapesBag[i]);
       delete ps;
     }
     else if (shapesTypeBag[i] == "CUBE"){
       const Cube* ps = reinterpret_cast<const Cube*>(shapesBag[i]);
       delete ps;
     }
     else if (shapesTypeBag[i] == "BOX"){
       const Box* ps = reinterpret_cast<const Box*>(shapesBag[i]);
       delete ps;
     }
     else if (shapesTypeBag[i] == "CYLINDER"){
       const Cylinder* ps = reinterpret_cast<const Cylinder*>(shapesBag[i]);
       delete ps;
     }
     else if (shapesTypeBag[i] == "PRISM"){
       const Prism* ps = reinterpret_cast<const Prism*>(shapesBag[i]);
       delete ps;
     }
     else {
       //this shouldn't happen
     }
   }
}

void calcShape(vector<string>& lineWords, vector<void*>& shapesBag, vector<string>& shapesTypeBag){
  string shapeType = lineWords.at(0);

  if (shapeType == "SQUARE"){
    Square* s = new Square(lineWords.size() >= 2 ? atof(lineWords.at(1).c_str()) : 0);
    shapesBag.push_back(s);
    shapesTypeBag.push_back("SQUARE");
  }
  else if (shapeType=="RECTANGLE"){
    Rectangle* r = new Rectangle(lineWords.size() >= 2 ? atof(lineWords.at(1).c_str()) : 0, lineWords.size() >= 3 ? atof(lineWords.at(2).c_str()) : 0);
    shapesBag.push_back(r);
    shapesTypeBag.push_back("RECTANGLE");
  }
  else if (shapeType == "CIRCLE"){
    Circle* c = new Circle(lineWords.size() >= 2 ? atof(lineWords.at(1).c_str()) : 0);
    shapesBag.push_back(c);
    shapesTypeBag.push_back("CIRCLE");
  }
  else if (shapeType == "TRIANGLE"){
    Triangle* t = new Triangle(lineWords.size() >= 2 ? atof(lineWords.at(1).c_str()) : 0);
    shapesBag.push_back(t);
    shapesTypeBag.push_back("TRIANGLE");
  }
  else if (shapeType == "CUBE"){
    Cube* c = new Cube(lineWords.size() >= 2 ? atof(lineWords.at(1).c_str()) : 0);
    shapesBag.push_back(c);
    shapesTypeBag.push_back("CUBE");
  }
  else if (shapeType == "BOX"){
    Box* b = new Box(lineWords.size() >= 2 ? atof(lineWords.at(1).c_str()) : 0, lineWords.size() >= 3 ? atof(lineWords.at(2).c_str()) : 0, lineWords.size() >= 4 ? atof(lineWords.at(3).c_str()) : 0);
    shapesBag.push_back(b);
    shapesTypeBag.push_back("BOX");
  }
  else if (shapeType == "CYLINDER"){
    Cylinder* c = new Cylinder(lineWords.size() >= 2 ? atof(lineWords.at(1).c_str()) : 0, lineWords.size() >= 3 ? atof(lineWords.at(2).c_str()) : 0);
    shapesBag.push_back(c);
    shapesTypeBag.push_back("CYLINDER");
  }
  else if (shapeType == "PRISM"){
    Prism* p = new Prism(lineWords.size() >= 2 ? atof(lineWords.at(1).c_str()) : 0, lineWords.size() >= 3 ? atof(lineWords.at(2).c_str()) : 0);
    shapesBag.push_back(p);
    shapesTypeBag.push_back("PRISM");
  }
  else {
    //end of file, do nothing
  }
}

void Square::output(ostream& os) const{
  double area = side * side;
  double perim = side * 4.0;
  os << "SQUARE side=" << side;
  os << roundingTwo << " area=" << area << " perimeter=" << perim << endl;
  os << roundingOff;
}

Square::Square(double s)
: side(s){
}

Square& Square::operator=(const Square& copyThis){
  Square& host = *this;
  if(this != &copyThis){
    const_cast<double&>(host.side) = copyThis.side;
  }
  return host;
}

void Rectangle::output(ostream& os) const{
  double area = length * width;
  double perim = (2.0 * length) + (2.0 * width);
  os << "RECTANGLE length=" << length << " width=" << width;
  os << roundingTwo << " area=" << area << " perimeter=" << perim << endl;
  os << roundingOff;
}

Rectangle::Rectangle(double l, double w)
: length(l), width(w){
}

Rectangle& Rectangle::operator=(const Rectangle& copyThis){
  Rectangle& host = *this;
  if(this != &copyThis){
    const_cast<double&>(host.length) = copyThis.length;
    const_cast<double&>(host.width) = copyThis.width;
  }
  return host;
}

void Circle::output(ostream& os) const{
  double area = PI * radius * radius;
  double perim = 2 * PI * radius;
  os << "CIRCLE radius=" << radius;
  os << roundingTwo << " area=" << area << " perimeter=" << perim << endl;
  os << roundingOff;
}

Circle::Circle(double r)
: radius(r){
}

Circle& Circle::operator=(const Circle& copyThis){
  Circle& host = *this;
  if(this != &copyThis){
    const_cast<double&>(host.radius) = copyThis.radius;
  }
  return host;
}

void Triangle::output(ostream& os) const{
  double area = (pow(3.0, 0.5) / 4.0) * pow(side, 2.0);
  double perim = side * 3.0;
  os << "TRIANGLE side=" << side;
  os << roundingTwo << " area=" << area << " perimeter=" << perim << endl;
  os << roundingOff;
}

Triangle::Triangle(double s)
: side(s){
}

Triangle& Triangle::operator=(const Triangle& copyThis){
  Triangle& host = *this;
  if(this != &copyThis){
    const_cast<double&>(host.side) = copyThis.side;
  }
  return host;
}

void Cube::output(ostream& os) const{
  double surfaceArea = 6.0 * pow(side, 2.0);
  double volume = pow(side, 3.0);
  os << "CUBE side=" << side;
  os << roundingTwo << " surface area=" << surfaceArea << " volume=" << volume << endl;
  os << roundingOff;
}

Cube::Cube(double s)
: side(s){
}

Cube& Cube::operator=(const Cube& copyThis){
  Cube& host = *this;
  if(this != &copyThis){
    const_cast<double&>(host.side) = copyThis.side;
  }
  return host;
}

void Box::output(ostream& os) const{
  double surfaceArea = 2.0 * ((length * width) + (length * height) + (width * height));
  double volume = length * width * height;
  os << "BOX length=" << length << " width=" << width << " height=" << height;
  os << roundingTwo << " surface area=" << surfaceArea << " volume=" << volume << endl;
  os << roundingOff;
}

Box::Box(double l, double w, double h)
: length(l), width(w), height(h){
}

Box& Box::operator=(const Box& copyThis){
  Box& host = *this;
  if(this != &copyThis){
    const_cast<double&>(host.length) = copyThis.length;
    const_cast<double&>(host.width) = copyThis.width;
    const_cast<double&>(host.height) = copyThis.height;
  }
  return host;
}

void Cylinder::output(ostream& os) const{
  double surfaceArea = (2.0 * (PI * pow(radius, 2.0))) + (2.0 * PI * radius * height);
  double volume = PI * pow(radius, 2.0) * height;
  os << "CYLINDER radius=" << radius << " height=" << height;
  os << roundingTwo << " surface area=" << surfaceArea << " volume=" << volume << endl;
  os << roundingOff;
}

Cylinder::Cylinder(double r, double h)
: radius(r), height(h){
}

Cylinder& Cylinder::operator=(const Cylinder& copyThis){
  Cylinder& host = *this;
  if(this != &copyThis){
    const_cast<double&>(host.radius) = copyThis.radius;
    const_cast<double&>(host.height) = copyThis.height;
  }
  return host;
}

void Prism::output(ostream& os) const{
  double surfaceArea = (2.0 * ((pow(3.0, 0.5) / 4.0) * pow(side, 2.0))) + (3.0 * (side * height));
  double volume = ((pow(3.0, 0.5) / 4.0) * pow(side, 2.0)) * height;
  os << "PRISM side=" << side << " height=" << height;
  os << roundingTwo << " surface area=" << surfaceArea << " volume=" << volume << endl;
  os << roundingOff;
}

Prism::Prism(double s, double h)
: side(s), height(h){
}

Prism& Prism::operator=(const Prism& copyThis){
  Prism& host = *this;
  if(this != &copyThis){
    const_cast<double&>(host.side) = copyThis.side;
    const_cast<double&>(host.height) = copyThis.height;
  }
  return host;
}

void checkShape(vector<string>& lineWords, vector<void*>& shapesBag, vector<string>& shapesTypeBag){
  string validShapes[] = {"SQUARE", "RECTANGLE", "CIRCLE", "TRIANGLE", "CUBE", "BOX", "CYLINDER", "PRISM"};
  bool valShape = false;

  for(auto& i : validShapes){
    if(lineWords.at(0) == i){
      valShape = true;
    }
  }

  if(valShape == true){
    calcShape(lineWords, shapesBag, shapesTypeBag);
  }
  else{
    if(lineWords.at(0)!="EOF"){
      cout << lineWords.at(0) << " invalid shape" << endl;
    }
  }
}

ostream& roundingTwo(ostream& out){
  out.setf(ios::fixed);
  out.precision(2);
  return out;
}

ostream& roundingOff(ostream& out){
  out.unsetf(ios::fixed);
  out.precision(6);
  return out;
}

vector<string> parseString(string str){
  stringstream s(str);
  istream_iterator<string> begin(s), end;
  return vector<string>(begin, end);
}
