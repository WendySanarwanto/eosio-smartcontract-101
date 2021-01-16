#include <eosio/eosio.hpp>

using namespace eosio;

CONTRACT tictactoe : public contract {
  public:
    using contract::contract;

    ACTION welcome(name host, name opponent);
};
