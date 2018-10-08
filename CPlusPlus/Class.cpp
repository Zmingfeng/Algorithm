#include<iostream>
#include<string>
#include<vector>

using namespace std;
/*
class Screen
{
	friend class Window_mgr;
	public:
		typedef string::size_type pos;
	    Screen() = default; //默认构造函数
		Screen(pos ht,pos wd,char c):height(ht),width(wd),contents(ht * wd,c) {} //构造函数
	    char get() const {return contents[cursor];}  //隐式内联
		inline char get(pos r,pos c) const;        //显式内联
		Screen &set(char c);
		Screen &set(pos row,pos col,char c);
		Screen &move(pos r,pos c);                   //稍后内联
		Screen &display(ostream &os) {do_display(os); return *this;}
		const Screen &display(ostream &os) const {do_display(os); return *this;}
		~Screen(void) {};
	private:
		pos cursor = 0;
	    pos height = 0,width = 0;
		string contents;
		void do_display(ostream &os) const;
};

void Screen::do_display(ostream &os) const
{ 
  for (int r = 0;r < height;r++)
  {
    for(int c = 0;c < width;c++)
	{
	  os << contents[r * width + c];
	  os << ' ';
    }
	cout << endl;
  }
}

inline char Screen::get(pos r,pos c) const
{
	return this->contents[r * width + c];
}

inline Screen &Screen::move(pos r,pos c)
{
	this->cursor = r * this->width + c;
	return *this;
}

inline Screen &Screen::set(char c)
{
	this->contents[this->cursor] = c;
	return *this;
}

inline Screen &Screen::set(pos row,pos col,char c)
{
	this->contents[row * width + col] = c;
	return *this;
}

class Window_mgr
{
	public:
		using ScreenIndex = vector<Screen>::size_type;
	    void clear(ScreenIndex);
	private:
		vector<Screen> screens{Screen(24,80,' ')};
};

void Window_mgr::clear(ScreenIndex i)
{
	Screen &s = screens[i];
	s.contents = string(s.height * s.width,' ');
}

class Quote
{
	public:
		Quote() = default;
	    Quote(const std::string &book,double sales_price):
			             bookNo(book),price(sales_price){}
		std::string isbn() const {return bookNo;}
		virtual double net_price(std::size_t n) const;
		virtual ~Quote() = default;
	private:
		std::string bookNo;
	protected:
		double price = 0.0;
};

class Disc_quote : public Quote
{
	public:
		Disc_quote() = default;
		Disc_quote(const std::string &book,double price,std::size_t qty,double disc) : 
			                  Disc_quote(book,price),quantity(qty),discount(disc) {}
		double net_price(std::size_t) const = 0;
	protected:
		std::size_t quantity = 0;
		double discount = 0.0;
};

class Bulk_quote : public Disc_quote
{
	public:
		Bulk_quote() = default;
		Bulk_quote(const std::string &book, double price, std::size_t qty, double disc):
						      Disc_quote(book,price,qty,disc) {}
		double net_price(std::size_t n) const override;
};

double Quote::net_price(std::size_t n) const
{
	return n * price;
}

double Bulk_quote::net_price(std::size_t cnt) const
{
	if (cnt >= min_qty)
	{
		return cnt * (1 - discount) * price;
	}
	return cnt * price;
}

double print_total(ostream &os,const Quote &item,std::size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << "# sold: " << n << "total due: " << ret << endl;
	return ret;
}
*/
auto test = [] () -> int {
  cout << "This is a test lambda." << endl;
  return 0;
}();

int main(void)
{
  //Screen my_Screen(10,10,'-');
  //my_Screen.move(5,2).set('#').display(cout);
  return 0;
}