//
// Created by xxlin on 2021/9/24.
//

class Quote {
 public:
  Quote() = default;
  Quote(const std::string &book, double pri)
      : bookNo(book), price(pri) {}

  virtual ~Quote() = default;
  std::string isbn() const { return bookNo; }
  virtual double net_price(std::size_t n) const { return n * price; }

 protected:
  double price = 0.0;

 private:
  std::string bookNo;
};

class Bulk_quote {
 public:
  Bulk_quote() = default;
  Bulk_quote(const std::string &book, double pri, std::size_t quan, double disc) : Quote(book, pri) {}
  double net_price(std::size_t n) const override;
};

double Bulk_quote::net_price(std::size_t n) const {
  if (n >= quantity)
    return n * price * (1 - discount);
  else
    return n * price;
}
