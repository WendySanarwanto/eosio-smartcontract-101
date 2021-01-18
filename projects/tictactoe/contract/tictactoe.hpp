#include <eosio/eosio.hpp>

using namespace eosio;

CONTRACT tictactoe : public contract {
  public:
    using contract::contract;

    TABLE game {
      name host;
      name opponent;

      uint64_t primary_key() const { return host.value; };
      uint64_t by_secondary() const { return opponent.value; };
      EOSLIB_SERIALIZE(game, (host)(opponent))
    };  

    // typedef multi_index<name("games"), game> games_table;
    typedef multi_index<name("games"), game, 
                        indexed_by<name("secid"), const_mem_fun<game, uint64_t, &game::by_secondary>>> games_table;    

    ACTION welcome( const name &host, const name &opponent );
    ACTION create( const name &challenger, const name &host );
    ACTION close( const name &challenger, const name &host );
};
