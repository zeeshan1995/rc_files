#include <vector>

#include "test_framework/generic_test.h"
using std::vector;
double BuyAndSellStockOnce(const vector<double>& prices) {
  // TODO - you fill in here.
  double buy_price = prices[0], profit = 0;
  for(int i=1; i<prices.size(); ++i)
  {
      if(buy_price > prices[i])
          buy_price = prices[i];
      else
          profit = std::max(profit, prices[i] - buy_price);
  }
  return profit;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"prices"};
  return GenericTestMain(args, "buy_and_sell_stock.cc",
                         "buy_and_sell_stock.tsv", &BuyAndSellStockOnce,
                         DefaultComparator{}, param_names);
}
