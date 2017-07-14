// 12.34 and 12.35: friend func
#include <iostream>
#include <string>
using namespace std;

class Sales_item
{
private:
    string isbn;
    unsigned units_sold;
    double revenue;
public:
    //this class's friend
    friend Sales_item add(const Sales_item&, const Sales_item&);
    friend istream& read(std::istream&, Sales_item&);
    bool same_isbn(const Sales_item &rhs) const
    { return isbn == rhs.isbn; }
    // constructor
    Sales_item(const string &book = ""): isbn(book), units_sold(0), revenue(0.0) {}
    Sales_item(istream &is)
    {
        cin >> isbn >> units_sold >> revenue; 
    }
    void print()
    {
        cout << "isbn: " << isbn << ", units_sold: " << units_sold << ", revenue: " << revenue << endl;
    }
};

Sales_item add(const Sales_item &obj1, const Sales_item &obj2)
{
    if(!obj1.same_isbn(obj2)) return obj1;
    Sales_item temp;
    temp.isbn = obj1.isbn;
    temp.units_sold = obj1.units_sold + obj2.units_sold;
    temp.revenue = obj1.revenue + obj2.revenue;
    return temp;
}

istream& read(istream &is, Sales_item &obj)
{
    double price;
    is >> obj.isbn >> obj.units_sold >> price;
    if(is)
    {
        obj.revenue = obj.units_sold * price;
    }
    else
    { 
        obj = Sales_item(); // reset obj to default status
    }
    return is;
}

int main()
{
    Sales_item obj1, obj2;
    cout << "Input obj1's isbn, units_sold and price: " << endl;
    read(cin, obj1);
    cout << "Input obj2's isbn, units_sold and price: " << endl;
    read(cin, obj2);
    Sales_item obj3 = add(obj1, obj2);
    obj3.print();
    return 0;
}
