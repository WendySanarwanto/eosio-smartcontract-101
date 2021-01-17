#include <eosio/eosio.hpp>

using namespace eosio;

CONTRACT tictactoe : public contract {
  public:
    using contract::contract;

    TABLE game {
      name host;
      name opponent;

      auto primary_key() const { return host.value; };
    };

    typedef multi_index<name("games"), game> games_table;

    ACTION welcome(name host, name opponent);
    ACTION create( const name &challenger, name &host);
    ACTION close( const name &challenger, name &host);
};
