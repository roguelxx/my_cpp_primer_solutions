//
// Created by lxx on 2021/9/11.
//

#include <string>

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

class Disc_quote : public Quote {
 public:
  Disc_quote() = default;
  Disc_quote(const std::string &book, double pri, std::size_t quan, double disc) : Quote(book, pri),
                                                                                   quantity(quan),
                                                                                   discount(disc) {}
  double net_price(std::size_t n) const override = 0;
 protected:
  std::size_t quantity = 0;
  double discount = 0.0;
};

class Bulk_quote : public Disc_quote {
 public:
  Bulk_quote() = default;
  Bulk_quote(const std::string &book, double pri, std::size_t quan, double disc) : Disc_quote(book, pri, quan, disc) {}
  double net_price(std::size_t n) const override;
};

double Bulk_quote::net_price(std::size_t n) const {
  if (n >= quantity)
    return n * price * (1 - discount);
  else
    return n * price;
}

class Limited_quote : public Disc_quote {
 public:
  Limited_quote() = default;
  Limited_quote(const std::string &book, double pri, std::size_t quan, double disc) : Disc_quote(book,
                                                                                                 pri,
                                                                                                 quan,
                                                                                                 disc) {}
  double net_price(std::size_t n) const override {
    if (n <= quantity)
      return n * price * (1 - discount);
    else
      return (n - quantity) * price + quantity * price * (1 - discount);
  }
};