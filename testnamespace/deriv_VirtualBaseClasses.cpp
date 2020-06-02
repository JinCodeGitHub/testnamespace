#include <iostream>
using namespace std;

class Queue{};
class CashierQueue : virtual public Queue{};
class LunchQueue : virtual public Queue{};
class  LunchCashierQueue : public LunchQueue,public CashierQueue{};
