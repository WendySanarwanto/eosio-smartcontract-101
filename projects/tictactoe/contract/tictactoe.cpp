#include <tictactoe.hpp>

ACTION tictactoe::welcome(name host, name opponent) {
  // welcome action can only be taken by contract account
  require_auth(get_self());

  // welcome action only prints a simple message
  print( "Welcome, challengers ", host, " and ", opponent, " !");
};
