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

class Bulk_quote : public Quote {
 public:
  Bulk_quote() = default;
  Bulk_quote(const std::string &, double, double, std::size_t);
  double net_price(std::size_t) const override;
 private:
  double discount = 0.0;
  std::size_t min_qty = 0;
};

Bulk_quote::Bulk_quote(const std::string &book, double sales_price, double disc, std::size_t qty) : Quote(book, sales_price), discount(disc), min_qty(qty) {}

double Bulk_quote::net_price(std::size_t n) const {
  if (n >= min_qty) {
    return n * price * (1 - discount);
  } else {
    return n * price;
  }
}

int main() {
  Quote q("english", 100);
  Bulk_quote bq("english", 100, 0.3, 20);
  print_total(std::cout, q, 10);
  print_total(std::cout, bq, 10);
  print_total(std::cout, q, 20);
  print_total(std::cout, bq, 20);
}