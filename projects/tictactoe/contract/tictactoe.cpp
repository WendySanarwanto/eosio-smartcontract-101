#include <tictactoe.hpp>

ACTION tictactoe::welcome(name host, name opponent) {
  // welcome action can only be taken by contract account
  require_auth(get_self());

  // welcome action only prints a simple message
  print( "Welcome, challengers ", host, " and ", opponent, " !");
};

ACTION tictactoe::create( const name &challenger, name &host) {
  // Ensure the host is authorised.
  check(has_auth(host), "Host is not authorized.");
  
  // Ensure that both challenger and host are not the same player
  check( challenger != host, "Both challenger and host cannot be same player.");

  // Get a reference into the multi_index table that store a pair of challenger's & host's names
  games_table _games(get_self(), get_self().value);

  // Ensure that there is no any game that exist between challenger & host, which means
  // Find by host 1st
  auto itr = _games.find(host.value);
  while (itr != _games.end()) {
    // Check if the opponent same as the challenger arg.
    check (itr->opponent != challenger, "Another game with identical challenger & host is already exist.");
    // move to next record
    ++itr;
  }
  
  // both challenger & host do not have any running game. Let's create a game for them.
  _games.emplace(get_self(), [&](game& new_game){
    new_game.host = host;
    new_game.opponent = challenger;
  });
  print("A new game has been created for host: '", host, "' and challenger: '", challenger, "'");
}

ACTION tictactoe::close( const name &challenger, name &host) {
  // Ensure the host is authorised.
  check(has_auth(host), "Host is not authorized.");

  // Get a reference into the multi_index table that store a pair of challenger's & host's names
  games_table _games(get_self(), get_self().value);

  // Find the record with matched name & host from the multi-index table
  // Find by host 1st
  auto itr = _games.find(host.value);  
  check(itr != _games.end(), "There is no game hosted by specified host.");

  while (itr != _games.end()) {
    // Check if the opponent same as the challenger arg.
    // If there's a matched record, remove the record. If not, print message which tells there are no game played by host & challenger.
    if (itr->opponent == challenger) {
      print ("Found a game hosted by '", host, "' and played by '", challenger ,"'. Closing the game now.");
      _games.erase(itr);
      return;
    }
    // move to next record
    ++itr;
  }
  print ("There is no any game hosted by '", host, "' and played by '", challenger ,"'.");
}