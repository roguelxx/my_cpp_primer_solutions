//
// Created by xxlin on 2021/9/8.
//


#include <string>
#include <iostream>

class Quote {
 public:
  Quote() = default;
  Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price) {}
  std::string isbn() const { return bookNo; }

  virtual double net_price(std::size_t n) const { return n * price; }
  virtual ~Quote() = default;
 private:
  std::string bookNo;
 protected:
  double price = 0.0;
};

double print_total(std::ostream &os, const Quote &item, size_t n) {
  double ret = item.net_price(n);
  os << "ISBN: " << item.isbn()
     << " # sold: " << n << " total due: " << ret << std::endl;
  return ret;
}

class Limited_Quote : public Quote {
 public:
  Limited_Quote() = default;
  Limited_Quote(const std::string &book, double sales_price, double disc, std::size_t qty) : Quote(book, sales_price),
                                                                                       limited_qty(qty),
                                                                                       discount(disc) {}

  double net_price(std::size_t) const override;
 private:
  std::size_t limited_qty = 0;
  double discount = 0.0;
};

double Limited_Quote::net_price(std::size_t n) const {
  if (n <= limited_qty) {
    return n * price * (1 - discount);
  } else {
    return limited_qty * price * (1 - discount) + (n - limited_qty) * price;
  }
}

int main() {
  Limited_Quote lq("english", 100, 0.3, 20);
  print_total(std::cout, lq, 20);
  print_total(std::cout, lq, 30);
}
