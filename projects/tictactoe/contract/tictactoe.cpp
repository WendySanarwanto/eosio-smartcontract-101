#include <tictactoe.hpp>

ACTION tictactoe::welcome( const name &host, const name &opponent ) {
  // welcome action can only be taken by contract account
  require_auth(get_self());

  // welcome action only prints a simple message
  print( "Welcome, challengers ", host, " and ", opponent, " !");
};

ACTION tictactoe::create( const name &challenger, const name &host ) {
  // Ensure the host is authorised.
  check(has_auth(host), "Host is not authorized.");
  
  // Ensure that both challenger and host are not the same player
  check( challenger != host, "Both challenger and host cannot be same player.");

  // Get a reference into the multi_index table that store a pair of challenger's & host's names
  games_table _games(get_self(), get_self().value);

  // Ensure that there are no any games played by challenger or host
  auto hostItr = _games.find(host.value);
  check( hostItr == _games.end(), "There is a game played by specified host." );  

  auto opponentIdx = _games.get_index<name("opponentid")>();
  auto challengerItr = opponentIdx.find(host.value);
  check( challengerItr == opponentIdx.end(), "There is a game played by specified host as challenger." );

  hostItr = _games.find(challenger.value);
  check( hostItr == _games.end(), "There is a game played by specified challenger as host." );   

  opponentIdx = _games.get_index<name("opponentid")>();
  challengerItr = opponentIdx.find(challenger.value);
  check( challengerItr == opponentIdx.end(), "There is a game played by specified challenger." );  
  
  // both challenger & host do not have any running game. Let's create a game for them.
  _games.emplace(get_self(), [&](game& new_game){
    new_game.host = host;
    new_game.opponent = challenger;
    // new_game.winner = game::WINNER_NONE;
    // new_game.turn = game::TURN_NONE;
  });
  print("A new game has been created for host: '", host, "' and challenger: '", challenger, "'");
}

ACTION tictactoe::close( const name &challenger, const name &host) {
  // Ensure the host is authorised.
  check(has_auth(host), "Host is not authorized.");

  // Get a reference into the multi_index table that store a pair of challenger's & host's names
  games_table _games(get_self(), get_self().value);

  // Find the record with matched name & host from the multi-index table
  // Find by host 1st
  auto hostItr = _games.find(host.value);  
  check(hostItr != _games.end(), "There is no game hosted by specified host.");

  auto opponentIdx = _games.get_index<name("opponentid")>();
  auto challengerItr = opponentIdx.begin();
  while(challengerItr != opponentIdx.end())  {
    if ( (challengerItr->opponent == challenger) && (challengerItr->host == host)) {
      print ("Found a game hosted by '", host, "' and played by '", challenger ,"'. Closing the game now.");      
      opponentIdx.erase(challengerItr);
      return;
    }
    ++challengerItr;
  }

  print ("There is no any game hosted by '", host, "' and played by '", challenger ,"'.");
}