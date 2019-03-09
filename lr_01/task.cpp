#include<iostream>
using std::cin;
using std::cout;
using std::endl;

class Value
{
    public:
      
      Value();
      Value ( size_t rub , size_t cents );
      Value operator= ( const Value &b);      
      Value operator+ ( const Value &slog );
      void print();
     ~Value();  


    private:
     size_t _rub;
     size_t _cents;
};

     Value::Value()
     {
        _rub=0;
        _cents =0;

     }

     Value::~Value()
     {
      ;
     }

     Value Value::operator+ ( const Value &slog )
     {
         Value summ;
         summ._rub = _rub+ slog._rub;
         summ._cents= _cents+slog._cents;
          
          while (summ._cents>99)
          {
              summ._rub +=summ._cents/100; 
              summ._cents =(summ._cents%100);
           }
          return summ;

     }

     Value Value::operator= (const Value &b)
     {
         this->_rub = b._rub;
         this->_cents = b._cents;
         return *this;
     }

     Value::Value(size_t rub , size_t cents)
     {
         
         if(cents>99)
         {
           while(cents>99)
           {
              rub = rub + cents/100;
              cents = cents%100;
           }
          
         }
       this-> _cents=cents;
       this->_rub = rub;
     }

    void Value::print()
    {
        cout<<"rub: "<<_rub<<endl<<"cents: "<<_cents<<endl;
    }


int main()
{
    Value a (5,109);
    Value b (10,200);
    Value c ;
    c = a+b;
    c.print();
    return 0;
}
