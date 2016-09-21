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
  Square(const vector<string>&);
  void output(ostream&) const;
  Square& operator=(const Square&);

  private:
  const double side;
};

struct Rectangle{
  Rectangle(const vector<string>&);
  void output(ostream&) const;
  Rectangle& operator=(const Rectangle&);

  private:
  const double length;
  const double width;
};

struct Circle{
  Circle(const vector<string>&);
  void output(ostream&) const;
  Circle& operator=(const Circle&);

  private:
  const double radius;
};

struct Triangle{
  Triangle(const vector<string>&);
  void output(ostream&) const;
  Triangle& operator=(const Triangle&);

  private:
  const double side;
};

struct Cube{
  Cube(const vector<string>&);
  void output(ostream&) const;
  Cube& operator=(const Cube&);

  private:
  const double side;
};

struct Box{
  Box(const vector<string>&);
  void output(ostream&) const;
  Box& operator=(const Box&);

  private:
  const double length;
  const double width;
  const double height;
};

struct Cylinder{
  Cylinder(const vector<string>&);
  void output(ostream&) const;
  Cylinder& operator=(const Cylinder&);

  private:
  const double radius;
  const double height;
};

struct Prism{
  Prism(const vector<string>&);
  void output(ostream&) const;
  Prism& operator=(const Prism&);

  private:
  const double side;
  const double height;
};

vector<string> parseString(string);
void checkShape(vector<string>&, vector<const void*>&, vector<string>&);
void calcShape(vector<string>&, vector<const void*>&, vector<string>&);
ostream& roundingTwo(ostream&);
ostream& roundingOff(ostream&);

const double PI = 3.14159;

int main(){
  cout << "Programmer: Dhanush Patel\n";
  cout << "Programmer's ID: 1553428\n";
  cout << "File: " << __FILE__ << endl;

  ifstream fin;
  fin.open("Shapes.input.txt");
  vector<const void*> shapesBag;
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

void calcShape(vector<string>& lineWords, vector<const void*>& shapesBag, vector<string>& shapesTypeBag){
  string shapeType = lineWords.at(0);

  if (shapeType == "SQUARE"){
    const Square* const s = new Square(lineWords);
    shapesBag.push_back(s);
    shapesTypeBag.push_back("SQUARE");
  }
  else if (shapeType=="RECTANGLE"){
    const Rectangle* const r = new Rectangle(lineWords);
    shapesBag.push_back(r);
    shapesTypeBag.push_back("RECTANGLE");
  }
  else if (shapeType == "CIRCLE"){
    const Circle* const c = new Circle(lineWords);
    shapesBag.push_back(c);
    shapesTypeBag.push_back("CIRCLE");
  }
  else if (shapeType == "TRIANGLE"){
    const Triangle* const t = new Triangle(lineWords);
    shapesBag.push_back(t);
    shapesTypeBag.push_back("TRIANGLE");
  }
  else if (shapeType == "CUBE"){
    const Cube* const c = new Cube(lineWords);
    shapesBag.push_back(c);
    shapesTypeBag.push_back("CUBE");
  }
  else if (shapeType == "BOX"){
    const Box* const b = new Box(lineWords);
    shapesBag.push_back(b);
    shapesTypeBag.push_back("BOX");
  }
  else if (shapeType == "CYLINDER"){
    const Cylinder* const c = new Cylinder(lineWords);
    shapesBag.push_back(c);
    shapesTypeBag.push_back("CYLINDER");
  }
  else if (shapeType == "PRISM"){
    const Prism* const p = new Prism(lineWords);
    shapesBag.push_back(p);
    shapesTypeBag.push_back("PRISM");
  }
  else {
    //end of file, do nothing
  }
}

void Square::output(ostream& os) const{
  const double area = side * side;
  const double perim = side * 4.0;
  os << "SQUARE side=" << side;
  os << roundingTwo << " area=" << area << " perimeter=" << perim << endl;
  os << roundingOff;
}

Square::Square(const vector<string>& lineWords)
: side(lineWords.size() >= 2 ? atof(lineWords.at(1).c_str()) : 0){
}

Square& Square::operator=(const Square& copyThis){
  Square& host = *this;
  if(this != &copyThis){
    const_cast<double&>(host.side) = copyThis.side;
  }
  return host;
}

void Rectangle::output(ostream& os) const{
  const double area = length * width;
  const double perim = (2.0 * length) + (2.0 * width);
  os << "RECTANGLE length=" << length << " width=" << width;
  os << roundingTwo << " area=" << area << " perimeter=" << perim << endl;
  os << roundingOff;
}

Rectangle::Rectangle(const vector<string>& lineWords)
: length(lineWords.size() >= 2 ? atof(lineWords.at(1).c_str()) : 0), width(lineWords.size() >= 3 ? atof(lineWords.at(2).c_str()) : 0){
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
  const double area = PI * radius * radius;
  const double perim = 2 * PI * radius;
  os << "CIRCLE radius=" << radius;
  os << roundingTwo << " area=" << area << " perimeter=" << perim << endl;
  os << roundingOff;
}

Circle::Circle(const vector<string>& lineWords)
: radius(lineWords.size() >= 2 ? atof(lineWords.at(1).c_str()) : 0){
}

Circle& Circle::operator=(const Circle& copyThis){
  Circle& host = *this;
  if(this != &copyThis){
    const_cast<double&>(host.radius) = copyThis.radius;
  }
  return host;
}

void Triangle::output(ostream& os) const{
  const double area = (pow(3.0, 0.5) / 4.0) * pow(side, 2.0);
  const double perim = side * 3.0;
  os << "TRIANGLE side=" << side;
  os << roundingTwo << " area=" << area << " perimeter=" << perim << endl;
  os << roundingOff;
}

Triangle::Triangle(const vector<string>& lineWords)
: side(lineWords.size() >= 2 ? atof(lineWords.at(1).c_str()) : 0){
}

Triangle& Triangle::operator=(const Triangle& copyThis){
  Triangle& host = *this;
  if(this != &copyThis){
    const_cast<double&>(host.side) = copyThis.side;
  }
  return host;
}

void Cube::output(ostream& os) const{
  const double surfaceArea = 6.0 * pow(side, 2.0);
  const double volume = pow(side, 3.0);
  os << "CUBE side=" << side;
  os << roundingTwo << " surface area=" << surfaceArea << " volume=" << volume << endl;
  os << roundingOff;
}

Cube::Cube(const vector<string>& lineWords)
: side(lineWords.size() >= 2 ? atof(lineWords.at(1).c_str()) : 0){
}

Cube& Cube::operator=(const Cube& copyThis){
  Cube& host = *this;
  if(this != &copyThis){
    const_cast<double&>(host.side) = copyThis.side;
  }
  return host;
}

void Box::output(ostream& os) const{
  const double surfaceArea = 2.0 * ((length * width) + (length * height) + (width * height));
  const double volume = length * width * height;
  os << "BOX length=" << length << " width=" << width << " height=" << height;
  os << roundingTwo << " surface area=" << surfaceArea << " volume=" << volume << endl;
  os << roundingOff;
}

Box::Box(const vector<string>& lineWords)
: length(lineWords.size() >= 2 ? atof(lineWords.at(1).c_str()) : 0), width(lineWords.size() >= 3 ? atof(lineWords.at(2).c_str()) : 0), height(lineWords.size() >= 4 ? atof(lineWords.at(3).c_str()) : 0){
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
  const double surfaceArea = (2.0 * (PI * pow(radius, 2.0))) + (2.0 * PI * radius * height);
  const double volume = PI * pow(radius, 2.0) * height;
  os << "CYLINDER radius=" << radius << " height=" << height;
  os << roundingTwo << " surface area=" << surfaceArea << " volume=" << volume << endl;
  os << roundingOff;
}

Cylinder::Cylinder(const vector<string>& lineWords)
: radius(lineWords.size() >= 2 ? atof(lineWords.at(1).c_str()) : 0), height(lineWords.size() >= 3 ? atof(lineWords.at(2).c_str()) : 0){
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
  const double surfaceArea = (2.0 * ((pow(3.0, 0.5) / 4.0) * pow(side, 2.0))) + (3.0 * (side * height));
  const double volume = ((pow(3.0, 0.5) / 4.0) * pow(side, 2.0)) * height;
  os << "PRISM side=" << side << " height=" << height;
  os << roundingTwo << " surface area=" << surfaceArea << " volume=" << volume << endl;
  os << roundingOff;
}

Prism::Prism(const vector<string>& lineWords)
: side(lineWords.size() >= 2 ? atof(lineWords.at(1).c_str()) : 0), height(lineWords.size() >= 3 ? atof(lineWords.at(2).c_str()) : 0){
}

Prism& Prism::operator=(const Prism& copyThis){
  Prism& host = *this;
  if(this != &copyThis){
    const_cast<double&>(host.side) = copyThis.side;
    const_cast<double&>(host.height) = copyThis.height;
  }
  return host;
}

void checkShape(vector<string>& lineWords, vector<const void*>& shapesBag, vector<string>& shapesTypeBag){
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
