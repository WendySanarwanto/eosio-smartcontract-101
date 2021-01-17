#include <eosio/eosio.hpp>

using namespace eosio;
using namespace std;

CONTRACT toyhaus : public contract {
  public:
    using contract::contract;

    TABLE toy {
      uint64_t id;
      string toyname;
      string toydescrip;
      uint64_t quantity;
      name owner = name("toyboss");

      auto primary_key() const { return id; };
    };

    typedef multi_index<name("toyshelf"), toy> toyshelf_table;

    ACTION addtoy(uint64_t id, string toyname, string toydescrip, uint64_t quantity);

    ACTION removetoy(uint64_t id);
};
