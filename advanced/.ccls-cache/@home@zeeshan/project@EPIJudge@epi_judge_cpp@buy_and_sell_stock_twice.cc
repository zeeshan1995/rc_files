#include <vector>

#include "test_framework/generic_test.h"
using std::vector;
double BuyAndSellStockTwice(const vector<double>& prices) {
  // TODO - you fill in here.
  std::vector<double>profit1{0};
  double buy_price = prices[0];
  for(int i=1; i<prices.size(); ++i)
  {
      profit1.push_back(std::max(profit1.back(), prices[i]-buy_price));
      buy_price = std::min(buy_price, prices[i]);
  }
  double sell_price = prices.back(), profit=profit1.back();
  for(int i=prices.size()-1; i>0; --i)
  {
      profit  = std::max(profit, profit1[i-1] + sell_price - prices[i]);
      sell_price = std::max(sell_price, prices[i]);
  }

  return profit;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"prices"};
  return GenericTestMain(args, "buy_and_sell_stock_twice.cc",
                         "buy_and_sell_stock_twice.tsv", &BuyAndSellStockTwice,
                         DefaultComparator{}, param_names);
}
